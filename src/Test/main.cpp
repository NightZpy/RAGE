#include <iostream> // Quitar
#include <RAGE/Core.hpp>
#include "SceneMain.hpp"

int main(int argc, char **argv)
{
	// Creamos un c�digo de error
	int anExitCode = ra::StatusNoError;

	// Creamos la aplicaci�n
	ra::App *anApp = ra::App::Instance();

	// Registramos la ruta del ejecutable
	anApp->RegisterExecutableDir(argc, argv);

	// Establecemos la escena inicial
	anApp->SetFirstScene(new SceneMain("Main"));

	// Ponemos en marcha la aplicaci�n
	anExitCode = anApp->Run();

	// Eliminamos la aplicaci�n
	anApp->Release();
	// Anulamos el puntero
	anApp = 0;

	return anExitCode;
}