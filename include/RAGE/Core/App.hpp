#ifndef RAGE_CORE_APP_HPP
#define RAGE_CORE_APP_HPP

#include <string>
#include <fstream>
#include <SFML/Graphics.hpp>
#include <RAGE/Core/Export.hpp>
#include <RAGE/Config.hpp>
#include <RAGE/Core/Core_types.hpp>

namespace ra
{

class RAGE_CORE_API App
{
	static App* ms_instance;

public:
	// Constantes
	///////////////////////////////////////////////////////////////////////////
	static const unsigned int DEFAULT_VIDEO_WIDTH = 640;
	static const unsigned int DEFAULT_VIDEO_HEIGHT = 480;
	static const unsigned int DEFAULT_VIDEO_BPP = 32;

	// Variables
	///////////////////////////////////////////////////////////////////////////
	/// Log del Engine
	std::ofstream log;
	/// Ventana de la aplicaci�n
	sf::RenderWindow window;

	/**
	 * Devuelve un puntero a la instancia �nica de la clase si existe,
	 * si no, la crea y duevuelve el puntero.
	 * 
	 * @return Puntero a la instancia �nica de App
	 */
	static App* Instance();
	 
	/**
	 * Elimina la instancia �nica de la aplicaci�n.
	 */
	static void Release();

	/**
	 * Establece la ruta del ejecutable de la aplicaci�n
	 * 
	 * @param argc N�mero de par�metros
	 * @param argv[] Lista de par�metros
	 */
	void RegisterExecutableDir(int argc, char** argv);

	/**
	 * Devuelve la ruta del ejecutable de la aplicaci�n
	 *
	 * @return string con la ruta de la aplicaci�n
	 */
	std::string GetExecutableDir() const;

	/**
	 * Devuelve verdadero si la aplicaci�n se est� ejecutando
	 *
	 * @return true si la apicaci�n se est� ejecutando
	 */
	bool IsRunning(void) const;

	/**
	 * Detiene la aplicacion con el c�digo de salida indicado
	 *
	 * @param the_exit_code C�digo de salida de la aplicaci�n
	 */
	void Quit(int the_exit_code);

	std::string GetTitle() const;

	void SetTitle(const std::string theTitle);

	void SetFirstScene(ra::Scene* theScene);

	/**
	 * Ejecuta la aplicaci�n, pone en marcha el GameLoop
	 *
	 * @return Devuelve el c�digo de salida de la aplicaci�n
	*/
	int Run();

protected:
	void CreateWindow();

	void Init();

	void GameLoop();

	void Cleanup();
		 
private:
	// Variables
	///////////////////////////////////////////////////////////////////////////
	/// Almacena la ruta del ejecutable
	std::string m_executableDir;
	/// Comprueba si est� activa o no la Aplicaci�n
	bool m_running;
	/// C�digo de salida de la aplicaci�n
	int m_exitCode;
	/// Nombre de la aplicaci�n
	std::string m_title;
	/// Bandera para el estilo de la ventana
	ra::Uint32 m_windowStyle;
	/// Opciones de video de la ventana
	sf::VideoMode m_videoMode;
	/// Puntero al AssetManager
	ra::AssetManager *m_assetManager;
	// Puntero al SceneManager
	ra::SceneManager *m_sceneManager;
	// Puntero a la escena inicial
	ra::Scene* m_initialScene;

	/**
	 * Constructor de la Aplicaci�n su �nica funci�n es crear el archivo log
	 */
	App();

	/**
	 * Destructor de la aplicaci�n. Cierra el archivo de log.
	 */
	virtual ~App();

	/**
	 * App copy constructor is private because we do not allow copies of
	 * our Singleton class
	*/
	App(const App&);               // Intentionally undefined

	/**
	 * Our assignment operator is private because we do not allow copies
	 * of our Singleton class
	 */
	App& operator=(const App&);    // Intentionally undefined


}; // class App

} // namespace ra

#endif // RAGE_CORE_APP_HPP