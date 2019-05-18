#include <iostream>
#include <string>

using namespace std;

int jugar(int _vidas, string palabra, string instru, int tam)
{
	int puntuacion;
	string palabraD;
	int letrasRecolectadas = 0;
	bool encontro = false, gano = false;
	char letra;
	for (int i = 0; i < palabra.length(); i++)
		palabraD +="- ";

	while (_vidas > 0)
	{
		cout << "\n\n\n\t\t\t---> AHORCADO!!! <---";

		switch (_vidas)
		{
		case 5:
			cout << endl << "||";
			cout << endl << "||";
			cout << endl << "||";
			cout << endl << "||";
			cout << endl << "||";
			cout << endl << "||";
			break;

		case 4:
			cout << endl << "------------";
			cout << endl << "||";
			cout << endl << "||";
			cout << endl << "||";
			cout << endl << "||";
			cout << endl << "||";
			cout << endl << "||";
			break;

		case 3:
			cout << endl << "------------";
			cout << endl << "||         O";
			cout << endl << "||";
			cout << endl << "||";
			cout << endl << "||";
			cout << endl << "||";
			cout << endl << "||";
			break;

		case 2:
			cout << endl << "------------";
			cout << endl << "||         O";
			cout << endl << "||         |";
			cout << endl << "||         |";
			cout << endl << "||         |";
			cout << endl << "||";
			cout << endl << "||";
			break;

		case 1:
			cout << endl << "------------";
			cout << endl << "||         O";
			cout << endl << "||         |";
			cout << endl << "||         |";
			cout << endl << "||         |";
			cout << endl << "||        / \\";
			cout << endl << "||";
			break;

		default:
			break;
		}
		cout << endl << instru << endl;
		cout << palabraD;
		
		if (_vidas > 0)
		{
			cout << "\nIngrese una letra: ";
			cin >> letra;
		}

		if (_vidas > 0)
		{
			for (int i = 0; i < palabra.length(); i++)
			{
				if (letra == palabra[i])
				{
					
					palabraD[i + 1] = ' ';
					palabraD[i] = letra;
					encontro = true;
					puntuacion += 2;
					letrasRecolectadas++;
				}
			}
			if (encontro == false)
			{
				_vidas--;
			}
			encontro = false;
		}
		if (_vidas == 0)
		{
			cout << endl << "------------";
			cout << endl << "||         O";
			cout << endl << "||         |";
			cout << endl << "||       --|--";
			cout << endl << "||         |";
			cout << endl << "||        / \\";
			cout << endl << "||";
		}
		if (letrasRecolectadas == palabra.length())
		{
			gano = true;
			_vidas = 0;
		}
	}
	if (_vidas == 6)
	{
		puntuacion = 50;
	}

	return puntuacion;

}

int main()
{
	bool salir = false, eligioOpcion = false, comenzarPartida;
	char comenzar;
	int opcion = 0, opcionJugar = 0, vidas = 6, posi = 0, puntaje = 0;

	string peliculas[7];

	string deportes[7] = {"BARCELONA", "FRANCIA", "MIROSLAVKLOSE", "NATACION", "MICHAELPHELPS", "TAEKWONDO", "INGLATERRA"};
	string instruccionesDeportes[7] = {"Es considerado uno de los mejores equipos del mundo.", "Equipo nacional que gano el mundial del 2018.", "Maximo goleador de la historia de los mundiales.", "Es el deporte mas completo que existe.",
	"Jugador olimpico con mas medallas olimpicas de la historia.", "Arte marcial que se considera deporte olimpico.", "Pais nativo del deporte de futbol."};

	string palabra, instrucciones, nombre;

	string jugadores[10];
	for (int i = 0; i < 10; i++)
		jugadores[i] = "";

	int puntajes[10];
	for (int i = 0; i < 10; i++)
		puntajes[i] = 0;

	while (salir != true)
	{
		cout << "\n\n\t\t\t Bienvenido al juego ahorcado!!";
		cout << "\n1) Jugar";
		cout << "\n2) Ver reglas y tipos de juego";
		cout << "\n3) Ver puntajes de jugadores";
		cout << "\n4) Salir";
		cout << "\nIngrese una opcion: ";
		cin >> opcion;

		switch (opcion)
		{
		case 1:
			cout << "\n\n\t\t==> J U G A R <==";
			cout << "\nFavor ingresar la tematica del juego.";
			cout << "\n1) Peliculas";
			cout << "\n2) Deportes";
			cout << "\n3) Ciencias Sociales";
			cout << "\nIngrese una opcion: ";
			cin >> opcionJugar;

			switch (opcionJugar)
			{
			case 1:
				eligioOpcion = true;
				break;

			case 2:
				posi = (rand() % 6);
				palabra = deportes[posi];
				instrucciones = instruccionesDeportes[posi];
				eligioOpcion = true;

				cout << "Comenzar(S/N): ";
				cin >> comenzar;
				switch (comenzar)
				{
				case 'S':
					comenzarPartida = true;
					break;

				case 'N':
					comenzarPartida = false;
					break;

				default:
					comenzarPartida = false;
					break;
				}

				if (comenzarPartida == true)
				{
					puntaje = jugar(vidas, palabra, instrucciones, posi);
					if (puntaje > palabra.length()*2 || puntaje == 50)
					{
						cout << "HAS GANADO LA PARTIDA, LA PALABRA ES " + palabra;
					}
					else
					{
						cout << "Has perdido la partida :(";
					}
				}
				cout << "\nEjemplo: AAA, AJR, JED, OJM";
				cout << "\nIngrese su nombre en el formato mostrado: ";
				cin >> nombre;

				for (int i = 0; i < 10; i++)
				{
					if (jugadores[i] == "")
					{
						jugadores[i] = nombre;
						puntajes[i] = puntaje;
					}
				}
				
				break;

			case 3:
				eligioOpcion = true;
				break;

			default:
				cout << "Opcion ingresada no valida, regresando al menu principal...";
				break;
			}

		case 2:
			cout << "\n\n\t\t==> R E G L A S  Y  T I P O S  D E  J U E G O S <==";
			cout << "\nEste juego tiene como reglas las siguientes: ";
			cout << "\n\t1) Tienes 6 intentos los cuales se reducen si fallas adivinando alguna letra.";
			cout << "\n\t2) Si ganas la partida sin perder algun intento, ganas con 50 puntos(Puntuacion maxima).";
			cout << "\n\t3) Debes ingresar todas las letras en mayuscula.";

			cout << "\n\nEste juego tiene 3 temáticas: ";
			cout << "\n\ta. Peliculas";
			cout << "\n\tb. Deportes";
			cout << "\n\tc. Ciencias Sociales";
			break;

		case 3:
			cout << "\n\n\t\t==> P U N T A J E S  D E  J U G A D O R E S <==" << endl;

			cout << "JUGADORES \t\t\t PUNTAJES";
			for (int i = 0; i < 10; i++)
			{
				if (jugadores[i] != "")
				{
					cout << jugadores[i]+"\t\t\t"+to_string(puntajes[i]);
				}
			}
			break;

		case 4:
			salir = true;
			break;

		default:
			cout << "Opcion ingresada no valida, favor ingresar otra.";
			break;
		}
	}


}