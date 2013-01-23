#ifndef   RAGE_CORE_STRING_UTIL_HPP
#define   RAGE_CORE_STRING_UTIL_HPP

#include <string>
#include <RAGE/Core/Export.hpp>
#include <RAGE/Core/Core_types.hpp>
#include <SFML/Graphics.hpp>

namespace ra
{

///////////////////////////////////////////////////////////////////////////
// String Manipulation Methods
///////////////////////////////////////////////////////////////////////////
/**
* ConvertBool will convert the boolean value provided into a string.
* @param[in] theBoolean to convert to a string.
* @return the resulting string after converting theBoolean
*/
std::string RAGE_CORE_API ConvertBool(const bool theBoolean);

/**
* ConvertColor will convert theColor value provided into a string.
* @param[in] theVector to convert to a string.
* @return the resulting string after converting theVector
*/
std::string RAGE_CORE_API ConvertColor(const sf::Color theVector);

/**
* ConvertDouble will convert the double value provided into a string.
* @param[in] theFloat to convert to a string.
* @return the resulting string after converting theFloat
*/
std::string RAGE_CORE_API ConvertDouble(const double theFloat);

/**
* ConvertFloat will convert the float value provided into a string.
* @param[in] theFloat to convert to a string.
* @return the resulting string after converting theFloat
*/
std::string RAGE_CORE_API ConvertFloat(const float theFloat);

/**
* ConvertInt8 will convert the 8 bit signed integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string RAGE_CORE_API ConvertInt8(const Int8 theNumber);

/**
* ConvertInt16 will convert the 16 bit signed integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string RAGE_CORE_API ConvertInt16(const Int16 theNumber);

/**
* ConvertInt32 will convert the 32 bit signed integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string RAGE_CORE_API ConvertInt32(const Int32 theNumber);

/**
* ConvertInt64 will convert the 64 bit signed integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string RAGE_CORE_API ConvertInt64(const Int64 theNumber);

/**
* ConvertIntRect will convert the sf::IntRect value provided into a string.
* @param[in] theRect to convert to a string.
* @return the resulting string after converting theRect
*/
std::string RAGE_CORE_API ConvertIntRect(const sf::IntRect theRect);

/**
* ConvertUint8 will convert the 8 bit unsigned integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string RAGE_CORE_API ConvertUint8(const Uint8 theNumber);

/**
* ConvertUint16 will convert the 16 bit unsigned integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string RAGE_CORE_API ConvertUint16(const Uint16 theNumber);

/**
* ConvertUint32 will convert the 32 bit unsigned integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string RAGE_CORE_API ConvertUint32(const Uint32 theNumber);

/**
* ConvertUint64 will convert the 64 bit unsigned integer provided into a
* string.
* @param[in] theNumber to convert to a string.
* @return the resulting string after converting theNumber
*/
std::string RAGE_CORE_API ConvertUint64(const Uint64 theNumber);

/**
* ConvertVector2f will convert theVector value provided into a string.
* @param[in] theVector to convert to a string.
* @return the resulting string after converting theVector
*/
std::string RAGE_CORE_API ConvertVector2f(const sf::Vector2f theVector);

/**
* ConvertVector2i will convert theVector value provided into a string.
* @param[in] theVector to convert to a string.
* @return the resulting string after converting theVector
*/
std::string RAGE_CORE_API ConvertVector2i(const sf::Vector2i theVector);

/**
* ConvertVector2u will convert theVector value provided into a string.
* @param[in] theVector to convert to a string.
* @return the resulting string after converting theVector
*/
std::string RAGE_CORE_API ConvertVector2u(const sf::Vector2u theVector);

/**
* ConvertVector3f will convert theVector value provided into a string.
* @param[in] theVector to convert to a string.
* @return the resulting string after converting theVector
*/
std::string RAGE_CORE_API ConvertVector3f(const sf::Vector3f theVector);

/**
* ConvertVector3i will convert theVector value provided into a string.
* @param[in] theVector to convert to a string.
* @return the resulting string after converting theVector
*/
std::string RAGE_CORE_API ConvertVector3i(const sf::Vector3i theVector);

///////////////////////////////////////////////////////////////////////////
// String Parse Methods
///////////////////////////////////////////////////////////////////////////
/**
* ParseBool will parse theValue string to obtain the boolean value to
* return.  If the value is not one of the following (0,1,true,false,on,
* off) then theDefault will be returned instead.
* @param[in] theValue to parse for (0,1,true,false,on,off)
* @param[in] theDefault value to return if not one of the above
* @return the boolean value obtained
*/
bool RAGE_CORE_API ParseBool(std::string theValue, const bool theDefault);

/**
* ParseColor will parse theValue string to obtain the R,G,B,A color values
* to produce an sf::Color object for the GetColor method above.
* @param[in] theValue to parse for R,G,B,A color values
* @param[in] theDefault color to use if the parser fails
* @return the color object created with the values obtained
*/
sf::Color RAGE_CORE_API ParseColor(const std::string theValue, const sf::Color theDefault);

/**
* ParseDouble will parse theValue string to obtain the double value to
* return or return theDefault instead.
* @param[in] theValue to parse for the float value
* @param[in] theDefault float value to use if the parser fails
* @return the float value obtained or theDefault if not parsed
*/
double RAGE_CORE_API ParseDouble(const std::string theValue, const double theDefault);

/**
* ParseFloat will parse theValue string to obtain the float value to
* return or return theDefault instead.
* @param[in] theValue to parse for the float value
* @param[in] theDefault float value to use if the parser fails
* @return the float value obtained or theDefault if not parsed
*/
float RAGE_CORE_API ParseFloat(const std::string theValue, const float theDefault);

/**
* ParseInt8 will parse theValue string to obtain a signed 8 bit value.
* If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the signed 8 bit value
* @param[in] theDefault signed 8 bit value to use if the parser fails
* @return the signed 8 bit value obtained
*/
Int8 RAGE_CORE_API ParseInt8(const std::string theValue, const Int8 theDefault);

/**
* ParseInt16 will parse theValue string to obtain a signed 16 bit value.
* If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the signed 16 bit value
* @param[in] theDefault signed 16 bit value to use if the parser fails
* @return the signed 16 bit value obtained
*/
Int16 RAGE_CORE_API ParseInt16(const std::string theValue, const Int16 theDefault);

/**
* ParseInt32 will parse theValue string to obtain a signed 32 bit value.
* If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the signed 32 bit value
* @param[in] theDefault signed 32 bit value to use if the parser fails
* @return the signed 32 bit value obtained
*/
Int32 RAGE_CORE_API ParseInt32(const std::string theValue, const Int32 theDefault);

/**
* ParseInt64 will parse theValue string to obtain a signed 64 bit value.
* If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the signed 64 bit value
* @param[in] theDefault signed 64 bit value to use if the parser fails
* @return the signed 64 bit value obtained
*/
Int64 RAGE_CORE_API ParseInt64(const std::string theValue, const Int64 theDefault);

/**
* ParseIntRect will parse theValue string to obtain a sf::IntRect value.
* If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the sf::IntRect value
* @param[in] theDefault sf::IntRect value to use if the parser fails
* @return the sf::IntRect value obtained
*/
sf::IntRect RAGE_CORE_API ParseIntRect(const std::string theValue, const sf::IntRect theDefault);

/**
* ParseUint8 will parse theValue string to obtain a signed 8 bit value.
* If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the signed 8 bit value
* @param[in] theDefault signed 8 bit value to use if the parser fails
* @return the signed 8 bit value obtained
*/
Uint8 RAGE_CORE_API ParseUint8(const std::string theValue, const Uint8 theDefault);

/**
* ParseUint16 will parse theValue string to obtain an unsigned 16 bit
* value.  If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the unsigned 16 bit value
* @param[in] theDefault unsigned 16 bit value to use if the parser fails
* @return the unsigned 16 bit value obtained
*/
Uint16 RAGE_CORE_API ParseUint16(const std::string theValue, const Uint16 theDefault);

/**
* ParseUint32 will parse theValue string to obtain an unsigned 32 bit
* value.  If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the unsigned 32 bit value
* @param[in] theDefault unsigned 32 bit value to use if the parser fails
* @return the unsigned 32 bit value obtained
*/
Uint32 RAGE_CORE_API ParseUint32(const std::string theValue, const Uint32 theDefault);

/**
* ParseUint64 will parse theValue string to obtain an unsigned 64 bit
* value.  If the parser fails, then it will return theDefault instead.
* @param[in] theValue to parse for the unsigned 64 bit value
* @param[in] theDefault unsigned 64 bit value to use if the parser fails
* @return the unsigned 64 bit value obtained
*/
Uint64 RAGE_CORE_API ParseUint64(const std::string theValue, const Uint64 theDefault);

/**
* ParseVector2f will parse theValue string to obtain the X,Y vector values
* to produce an sf::Vector2f object.
* @param[in] theValue to parse for X,Y vector values
* @param[in] theDefault color to use if the parser fails
* @return the color object created with the values obtained
*/
sf::Vector2f RAGE_CORE_API ParseVector2f(const std::string theValue, const sf::Vector2f theDefault);

/**
* ParseVector2i will parse theValue string to obtain the X,Y vector values
* to produce an sf::Vector2i object.
* @param[in] theValue to parse for X,Y vector values
* @param[in] theDefault color to use if the parser fails
* @return the color object created with the values obtained
*/
sf::Vector2i RAGE_CORE_API ParseVector2i(const std::string theValue, const sf::Vector2i theDefault);

/**
* ParseVector2u will parse theValue string to obtain the X,Y vector values
* to produce an sf::Vector2u object.
* @param[in] theValue to parse for X,Y vector values
* @param[in] theDefault color to use if the parser fails
* @return the color object created with the values obtained
*/
sf::Vector2u RAGE_CORE_API ParseVector2u(const std::string theValue, const sf::Vector2u theDefault);

/**
* ParseVector3f will parse theValue string to obtain the X,Y,Z vector values
* to produce an sf::Vector3f object.
* @param[in] theValue to parse for X,Y,Z vector values
* @param[in] theDefault color to use if the parser fails
* @return the color object created with the values obtained
*/
sf::Vector3f RAGE_CORE_API ParseVector3f(const std::string theValue, const sf::Vector3f theDefault);

/**
* ParseVector3i will parse theValue string to obtain the X,Y,Z vector values
* to produce an sf::Vector3i object.
* @param[in] theValue to parse for X,Y,Z vector values
* @param[in] theDefault color to use if the parser fails
* @return the color object created with the values obtained
*/
sf::Vector3i RAGE_CORE_API ParseVector3i(const std::string theValue, const sf::Vector3i theDefault);

} // namespace ra

#endif // RAGE_CORE_STRING_UTIL_HPP