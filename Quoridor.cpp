// Quoridor
// Ultima modificación: 24/02/2019
// Ultimas Adiciones: - Las fichas ya no se salen del tablero.
//                    - Se puede mover a ambas fichas por turnos.
//                    - Cuando una ficha llega al otro lado el juego termina.
//                    - Se introdujo una pantalla de fin del juego.
//                    - Los ceros en la parte superior e inferior del tablero fueron reemplazados por: /

// Librerias Incluidas
#include <iostream>
#include <cstdlib>
#include <conio.h>

// Constantes
#define alto 21
#define ancho 19

// Teclas direccionales. ¡Por el momento no es conveniente usarlas!
// const char UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77;

//                                   (1)           (2)           (3)           (4)          (5)           (6)           (7)           (8)           (9)
// Matriz.                    0.     1.     2.     3.     4.     5.     6.     7.     8.    9.     10.    11.    12.    13.    14.    15.    16.    17.    18.
char matriz[alto][ancho] = {{'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  },
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
/*                  20.*/   {'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   }};

// Posición de los jugadores
struct Jugador
{
   int posX;
   int posY;
}
//           PosX   PosY
Jugador_1 = {  9  ,  2  }, // Pos incial del jugador de arriba.
Jugador_2 = {  9  ,  18 }; // Pos inicial del jugador de abajo.

// Prototipos de Función
void Posicionar_jugadores();
void Dibujar_matriz();
void Limpiar_posiciones();
void Siguiente_turno(int i);
void Mover_Jugadores(Jugador& Player);
bool Sin_ganadores();
void Pantalla_del_ganador();

using namespace std;

int main()
{
   for(int i=0; Sin_ganadores(); i++){ // Es un ciclo continua mientras no hayan ganadores.

      Posicionar_jugadores();  // Inserta las fichas en la matriz.
      system("cls");           // Limpia la pantalla.
      Dibujar_matriz();        // Dibuja la nueva matriz.
      Limpiar_posiciones();    // Las fichas desaparecen de la matriz.
      Siguiente_turno(i);      // Cambia las posiciones de las fichas con el teclado según el turno.
   }

   Pantalla_del_ganador();
   return 0;
}

// Agrega los caracteres que representan a cada jugador en la matriz.
void Posicionar_jugadores()
{
   matriz[Jugador_1.posY][Jugador_1.posX] = '\1';
   matriz[Jugador_2.posY][Jugador_2.posX] = '\2';
}

// Agrega espacios vacios en las posiciones de los jugadores.
void Limpiar_posiciones()
{
   matriz[Jugador_1.posY][Jugador_1.posX] = '\0';
   matriz[Jugador_2.posY][Jugador_2.posX] = '\0';
}

// Muestra la matriz en la consola.
void Dibujar_matriz()
{
   for(int i=0; i<alto; i++) // i = posición y.
   {
      for(int j=0; j<ancho; j++) // j = posición x.
      {
         cout << matriz[i][j] ;
      }
      cout << '\n' ; // Imprime la siguiente fila un renglón abajo.
   }
   cout << "\n\n"
           "Teclas de movimiento:   w\n"
           "                      a s d\n";
}

// El turno de los jugadores cambia basandose en si i es par.
void Siguiente_turno(int i)
{
   if(i % 2 == 0)
   {
      Mover_Jugadores(Jugador_1);
   }
   else
   {
      Mover_Jugadores(Jugador_2);
   }
}

// Cambia los valores de las posiciones de los jugadores con las teclas:   w
//                                                                       a s d
void Mover_Jugadores(Jugador& Player)
{
   char tecla;
   tecla = getch(); // Lo que ingresaremos por el teclado.
   switch(tecla)
   {             // Si el jugador está en un borde, no avanza.
      case 'w' : if(Player.posY-2 != 0 ) {Player.posY -= 2;} ; break ; // Arriba
      case 's' : if(Player.posY+2 != 20) {Player.posY += 2;} ; break ; // Abajo
      case 'a' : if(Player.posX-1 != 0 ) {Player.posX -= 2;} ; break ; // Izquierda
      case 'd' : if(Player.posX+1 != 18) {Player.posX += 2;} ; break ; // Derecha
   }
}

// Verifica si aún no hay ganadores
bool Sin_ganadores()
{
   if((Jugador_1.posY == 18) || (Jugador_2.posY == 2)) // Los numeros son las posiciones en las
   {                                                   // esos jugadores ganan.
      return false;
   }
   return true;
}

// Muestra quién ganó el juego
void Pantalla_del_ganador()
{
   string ganador= "<jugador>";
   system("cls");
   cout << "\n\n\n\n\n\n\n\n\n\tFin del juego\n\nGanador: " << ganador << endl;
   getch();
}
