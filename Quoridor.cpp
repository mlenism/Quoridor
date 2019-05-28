// Quoridor
// Ultima modificaci�n: 24/02/2019

// Librerias Incluidas
#include <iostream>
#include <cstdlib>
#include <conio.h>

// Constantes
#define alto 21
#define ancho 19

// Teclas direccionales. �Por el momento no es conveniente usarlas!
// const char UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77;

// Posici�n de los jugadores
struct Jugador
{
   int posX;
   int posY;
}
//           PosX   PosY
Jugador_1 = {  9  ,  2  }, // Pos incial del jugador de arriba.
Jugador_2 = {  9  ,  18 }; // Pos inicial del jugador de abajo.

//                                   (1)           (2)           (3)           (4)          (5)           (6)           (7)           (8)           (9)
// Matriz.                    0.     1.     2.     3.     4.     5.     6.     7.     8.    9.     10.    11.    12.    13.    14.    15.    16.    17.    18.
char matriz[alto][ancho] = {{'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   },

/*                   1.*/   {'\332','\304','\302','\304','\302','\304','\302','\304','\302','\304','\302','\304','\302','\304','\302','\304','\302','\304','\277'},

/*              (1)  2.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},

/*                   3.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},

/*              (2)  4.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},

/*                   5.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},

/*              (3)  6.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},

/*                   7.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},

/*              (4)  8.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},

/*                   9.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},

/*              (5) 10.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},

/*                  11.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},

/*              (6) 12.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},

/*                  13.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},

/*              (7) 14.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},

/*                  15.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},

/*              (8) 16.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},

/*                  17.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},

/*              (9) 18.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},

/*                  19.*/   {'\300','\304','\301','\304','\301','\304','\301','\304','\301','\304','\301','\304','\301','\304','\301','\304','\301','\304','\331'},

/*                  20.*/   {'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   ,'0'   }};

// Prototipos de Funci�n
void Posicionar_jugadores();
void Dibujar_matriz();
void Mover_Jugadores();

using namespace std;

int main()
{
   for(int i=0; i==i; i++){ // Es un ciclo infinito mientras tanto.

      Posicionar_jugadores();  // Agrega unos en las nueas posiciones de los jugadores.
      system("cls"); // Limpia la pantalla
      Dibujar_matriz(); // Dibuja la nueva matriz
      matriz[Jugador_1.posY][Jugador_1.posX] = '\0';  // Las posiciones de los jugadores son borradas de la matriz.
      Mover_Jugadores(); // Cambia las posiciones con el teclado.
   }
   return 0;
}


// Por el momento solo mueve la ficha de arriba.
void Mover_Jugadores()
{
   char tecla; // Lo que ingresaremos por el teclado.
   tecla = getch();
   switch(tecla)
   {
      case 'w' : (Jugador_1.posY -= 2) ; break ; // Arriba
      case 's' : (Jugador_1.posY += 2) ; break ; // Abajo
      case 'a' : (Jugador_1.posX -= 2) ; break ; // Izquierda
      case 'd' : (Jugador_1.posX += 2) ; break ; // Derecha
   }
}

// Declara la posici�n de los jugadores.
void Posicionar_jugadores()
{
   matriz[Jugador_1.posY][Jugador_1.posX] = '\1';
   matriz[Jugador_2.posY][Jugador_2.posX] = '\2';
}

// Muestra la matriz en la consola.
void Dibujar_matriz()
{
   for(int i=0; i<alto; i++) // i = posici�n y.
   {
      for(int j=0; j<ancho; j++) // j = posici�n x.
      {
         cout << matriz[i][j] ;
      }
      cout << '\n' ; // Imprime la siguiente fila un rengl�n abajo.
   }
}
