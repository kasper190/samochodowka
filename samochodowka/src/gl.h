#ifndef __GL_H
#define __GL_H

#include "collision.h"

/** Glowa klasa odpowiedzialna za sterowanie aplikacja i rysowanie grafiki. Klasa jest 'wrapperem' dla funkcji wywolywanych 
bezposrednio przez API OpenGL'a. Jej zastosowanie ma na celu wykorzystanie mechanizmow obiektowych do programowania OpenGL'a
(natywnie API OpenGL'a wymaga programowania w ANSI C)). W klasie znajduje sie szereg funkcji wywolywanych przez maszyne 
stanu OpenGL'a. Przykladem moze byc funkcja display() wywolywana w momencie, gdy wymagane jest przerysowanie ekranu.
*/
class CGL {

public: 
	static const int TIMER = 40; /**< Ustawienie interwalu zegara przerysowania grafiki (czas w [ms]). Im krotszy czas tym czesciej przerysowywany bedzie ekran.*/
	//float EPSILION=0.0001;

private:
	int time_counter; /**< Licznik czasu rosnacy w kazdym wywolaniu timer'a. */
	int time_end; /**< Liczba sekund do zakonczenia gry. */
	int counter; /**< Liczba zderzen miedzy graczem i przeciwnikiem. */

	GLuint texture;
	GLuint texture1;/**< Indeks tekstury. */

	GLuint aseGeometry; /**< Uchwyt do obiektu ASE. */

	int board_width; /**< Szerokosc planszy. */
	int board_height; /**< Wysokosc planszy. */

	float playerMovementDirection; /**< Kierunek ruchu gracza (w deg). */
	float playerPosX; /**< Polozenie gracza (wspolrzedna X). */
	float playerPosY; /**< Polozenie gracza (wspolrzedna Y). */

	float camRotateX; /**< Kat obrotu kamery wokol osi OX. */
	float camRotateZ; /**< Kat obrotu kamery wokol osi OZ. */
	int xOld, yOld;

	CCollision collision; /**<  Obiekt wykrywajacy kolizje. */
	bool isCollision; /**< Flaga wystapienia kolizji. */

	float objPosX; /**< Pozycja przeciwnika (wspolrzedna X). */
	float objPosY; /**< Pozycja przeciwnika (wspolrzedna Y). */

public:
	
	float ruchx;
	float obrot;
	float ruch;
	float posX, posY, poX, poY;
	float moveX, moveY;
	bool IsMove;
	float deltaX;
	float posXTarget;
	float posYTarget;

	float dir;

    
    
	

	
	CGL() {
		dir=0;
		//

			moveX=0;
			moveY=0;
			posX=10;
			posY=0;
	
			
		//
		time_counter = 0;
		time_end = 50;
		counter = 0;

		texture = 0;
		texture1= 1;

		IsMove=false;
		posXTarget=-1;
		posXTarget=-1;
		
		

		ruchx=0;
		obrot=0;
		ruch=0;
		
		camRotateX = 0;
		camRotateZ = 0;
		xOld = -1;
		yOld = -1;

		board_width = 6.0f;
		board_height = 4.0f;

		playerPosX = 0.0f;
		playerPosY = 0.0f;
		playerMovementDirection = 90.0f;

		objPosX = 1.0f;
		objPosY = 1.0f;

		isCollision = false;
	}

	/** Inicjalizacja srodowiska graficznego: wczytanie tekstury, ustawienie kamery i swiatel, wczytanie obiektu ASE. Inicjalizacja
		odbywa sie tylko raz po uruchomieniu programu.
	*/
	void init( void );
	
	/** Glowna procedura rysowania grafiki. Wywolywana jest wtedy, gdy ekran wymaga przerysowania (np. obiekt zmienia swoje polozenie, okno bylo zasloniete przez inna aplikacje, itp.).  
	*/
	void display( void );
	
	/** Funkcja wywolywana w przypadku braku aktywnosci innych elementow programu (obecnie funkcja nie jest wykorzystywana). 
	*/
	void idle( void );
	
	/** Funkcja wywolywana cyklicznie co pewien interwal czasu (zobacz TIMER). Odbywa sie w niej zmiana polozenia gracza i przeciwnika oraz zwiekszany jest licznik czasu. 
	*/
	void timer( void );
	
	/** Funkcja obslugujaca klawiature. Zmiana kierunku ruchu gracza nastepuje po nacisnieciu klawiszy '[' oraz ']'. Klawisz 'Esc' przerywa gre.
	*/
	void keyboard( unsigned char key,int a,int b );
	
	/** Obsluga ruchy myszy. Zmiana polozenia kursora myszy z jednoczesnym wcisnieciem lewego przycisku myszy powoduje obrot planszy.
	*/
	void mouseMotion( int x, int y );
	
	/** Obsluga klawiszy myszy, funkcja wywolywana jest po nacisnieciu jednego z klawiszy myszy. Wspomaganie obracania planszy.
	*/
	void mousePress( int button, int state, int x, int y );

	/** Rysowanie gracza oraz definiowanie figury kolizyjnej dla gracza. W przypadku wystapienia kolizji gracza z przeciwnikiem, obiekt gracza (czajnik) zamieniany jest na kule.
	*/
	void draw_player( float x, float y );
	
	/** Rysowanie planszy. 
		@param board_width - szerokosc planszy
		@param board_height - wysokosc planszy
	*/
	void draw_board( float board_width, float board_height );
	
	/** Rysowanie przeciwnika. Obiekt przeciwnika wczytany byl z pliku ASE (patrz metoda init()). 
	*/
	void draw_enymy( float pos_x, float pos_y );
	
	/** Rysowanie figur kilizyjnych dla gracza i przeciwnika (funkcja pomocnicza, powinna byc wylaczona w koncowej wersji gry). 
	*/
	void draw_collisions_boxes( void );
	
	void prosta( int y, int x, float z );
	
	void lewo( int y, int x, float z );
	
	void prawo( int y, int x, float z );

};

extern CGL cgl;

#endif
