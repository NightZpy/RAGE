////////////////////////////////////////////////////////////
// Headers
////////////////////////////////////////////////////////////
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <RAGE/Core/Text.hpp>
#include <cassert>


namespace ra
{
////////////////////////////////////////////////////////////
Text::Text() :
m_string       (),
m_font         (NULL),
m_characterSize(30),
m_style        (Regular),
m_color        (255, 255, 255),
m_vertices     (sf::Quads),
m_bounds       ()
{

}


////////////////////////////////////////////////////////////
Text::Text(const sf::String& string, const sf::Font& font, unsigned int characterSize) :
m_string       (string),
m_font         (&font),
m_characterSize(characterSize),
m_style        (Regular),
m_color        (255, 255, 255),
m_vertices     (sf::Quads),
m_bounds       ()
{
    updateGeometry();
}


////////////////////////////////////////////////////////////
void Text::setString(const sf::String& string)
{
    m_string = string;
    updateGeometry();
}


////////////////////////////////////////////////////////////
void Text::setFont(const sf::Font& font)
{
    if (m_font != &font)
    {
        m_font = &font;
        updateGeometry();
    }
}


////////////////////////////////////////////////////////////
void Text::setCharacterSize(unsigned int size)
{
    if (m_characterSize != size)
    {
        m_characterSize = size;
        updateGeometry();
    }
}


////////////////////////////////////////////////////////////
void Text::setStyle(Uint32 style)
{
    if (m_style != style)
    {
        m_style = style;
        updateGeometry();
    }
}


////////////////////////////////////////////////////////////
void Text::setColor(const sf::Color& color)
{
    if (color != m_color)
    {
        m_color = color;
        for (unsigned int i = 0; i < m_vertices.getVertexCount(); ++i)
            m_vertices[i].color = m_color;
    }
}


////////////////////////////////////////////////////////////
const sf::String& Text::getString() const
{
    return m_string;
}


////////////////////////////////////////////////////////////
const sf::Font* Text::getFont() const
{
    return m_font;
}


////////////////////////////////////////////////////////////
unsigned int Text::getCharacterSize() const
{
    return m_characterSize;
}


////////////////////////////////////////////////////////////
Uint32 Text::getStyle() const
{
    return m_style;
}


////////////////////////////////////////////////////////////
const sf::Color& Text::getColor() const
{
    return m_color;
}


////////////////////////////////////////////////////////////
sf::Vector2f Text::findCharacterPos(std::size_t index) const
{
    // Make sure that we have a valid font
    if (!m_font)
        return sf::Vector2f();

    // Adjust the index if it's out of range
    if (index > m_string.getSize())
        index = m_string.getSize();

    // Precompute the variables needed by the algorithm
    bool  bold   = (m_style & Bold) != 0;
    float hspace = static_cast<float>(m_font->getGlyph(L' ', m_characterSize, bold).advance);
    float vspace = static_cast<float>(m_font->getLineSpacing(m_characterSize));

    // Compute the position
    sf::Vector2f position;
    Uint32 prevChar = 0;
    for (std::size_t i = 0; i < index; ++i)
    {
        Uint32 curChar = m_string[i];

        // Apply the kerning offset
        position.x += static_cast<float>(m_font->getKerning(prevChar, curChar, m_characterSize));
        prevChar = curChar;

        // Handle special characters
        switch (curChar)
        {
            case L' ' :  position.x += hspace;                 continue;
            case L'\t' : position.x += hspace * 4;             continue;
            case L'\n' : position.y += vspace; position.x = 0; continue;
            case L'\v' : position.y += vspace * 4;             continue;
        }

        // For regular characters, add the advance offset of the glyph
        position.x += static_cast<float>(m_font->getGlyph(curChar, m_characterSize, bold).advance);
    }

    // Transform the position to global coordinates
    position = getTransform().transformPoint(position);

    return position;
}


////////////////////////////////////////////////////////////
sf::FloatRect Text::getLocalBounds() const
{
    return m_bounds;
}


////////////////////////////////////////////////////////////
sf::FloatRect Text::getGlobalBounds() const
{
    return getTransform().transformRect(getLocalBounds());
}


////////////////////////////////////////////////////////////
void Text::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if (m_font)
    {
        states.transform *= getTransform();
        states.texture = &m_font->getTexture(m_characterSize);
        target.draw(m_vertices, states);
    }
}


////////////////////////////////////////////////////////////
void Text::updateGeometry()
{
    // Clear the previous geometry
    m_vertices.clear();
    m_bounds = sf::FloatRect();

    // No font: nothing to draw
    if (!m_font)
        return;

    // No text: nothing to draw
    if (m_string.isEmpty())
        return;

    // Compute values related to the text style
    bool  bold               = (m_style & Bold) != 0;
    bool  underlined         = (m_style & Underlined) != 0;
    float italic             = (m_style & Italic) ? 0.208f : 0.f; // 12 degrees
    float underlineOffset    = m_characterSize * 0.1f;
    float underlineThickness = m_characterSize * (bold ? 0.1f : 0.07f);

    // Precompute the variables needed by the algorithm
    float hspace = static_cast<float>(m_font->getGlyph(L' ', m_characterSize, bold).advance);
    float vspace = static_cast<float>(m_font->getLineSpacing(m_characterSize));
    float x      = 0.f;
    float y      = static_cast<float>(m_characterSize);

    // Create one quad for each character
    Uint32 prevChar = 0;
    for (std::size_t i = 0; i < m_string.getSize(); ++i)
    {
        Uint32 curChar = m_string[i];

        // Apply the kerning offset
        x += static_cast<float>(m_font->getKerning(prevChar, curChar, m_characterSize));
        prevChar = curChar;

        // If we're using the underlined style and there's a new line, draw a line
        if (underlined && (curChar == L'\n'))
        {
            float top = y + underlineOffset;
            float bottom = top + underlineThickness;

            m_vertices.append(sf::Vertex(sf::Vector2f(0, top),    m_color, sf::Vector2f(1, 1)));
            m_vertices.append(sf::Vertex(sf::Vector2f(x, top),    m_color, sf::Vector2f(1, 1)));
            m_vertices.append(sf::Vertex(sf::Vector2f(x, bottom), m_color, sf::Vector2f(1, 1)));
            m_vertices.append(sf::Vertex(sf::Vector2f(0, bottom), m_color, sf::Vector2f(1, 1)));
        }

        // Handle special characters
        switch (curChar)
        {
            case L' ' :  x += hspace;        continue;
            case L'\t' : x += hspace * 4;    continue;
            case L'\n' : y += vspace; x = 0; continue;
            case L'\v' : y += vspace * 4;    continue;
        }

        // Extract the current glyph's description
        const sf::Glyph& glyph = m_font->getGlyph(curChar, m_characterSize, bold);

        int left   = glyph.bounds.left;
        int top    = glyph.bounds.top;
        int right  = glyph.bounds.left + glyph.bounds.width;
        int bottom = glyph.bounds.top  + glyph.bounds.height;

        float u1 = static_cast<float>(glyph.textureRect.left);
        float v1 = static_cast<float>(glyph.textureRect.top);
        float u2 = static_cast<float>(glyph.textureRect.left + glyph.textureRect.width);
        float v2 = static_cast<float>(glyph.textureRect.top  + glyph.textureRect.height);

        // Add a quad for the current character
        m_vertices.append(sf::Vertex(sf::Vector2f(x + left  - italic * top,    y + top),    m_color, sf::Vector2f(u1, v1)));
        m_vertices.append(sf::Vertex(sf::Vector2f(x + right - italic * top,    y + top),    m_color, sf::Vector2f(u2, v1)));
        m_vertices.append(sf::Vertex(sf::Vector2f(x + right - italic * bottom, y + bottom), m_color, sf::Vector2f(u2, v2)));
        m_vertices.append(sf::Vertex(sf::Vector2f(x + left  - italic * bottom, y + bottom), m_color, sf::Vector2f(u1, v2)));

        // Advance to the next character
        x += glyph.advance;
    }

    // If we're using the underlined style, add the last line
    if (underlined)
    {
        float top = y + underlineOffset;
        float bottom = top + underlineThickness;

        m_vertices.append(sf::Vertex(sf::Vector2f(0, top),    m_color, sf::Vector2f(1, 1)));
        m_vertices.append(sf::Vertex(sf::Vector2f(x, top),    m_color, sf::Vector2f(1, 1)));
        m_vertices.append(sf::Vertex(sf::Vector2f(x, bottom), m_color, sf::Vector2f(1, 1)));
        m_vertices.append(sf::Vertex(sf::Vector2f(0, bottom), m_color, sf::Vector2f(1, 1)));
    }

    // Recompute the bounding rectangle
    m_bounds = m_vertices.getBounds();
}

} // namespace ra