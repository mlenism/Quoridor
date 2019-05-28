// Quoridor
// Ultima modificación: 25/02/2019
// Ultimas Adiciones: - Habilitadas la flechas direccionales.
//                    - Cada jugador tiene unas teclas de movimiento asignadas.
//                    - Los turnos ya no se pierden si presiona una tecla equivocada.
//                    - El jugador puede visualizar su turno.

// Librerias Incluidas
#include <iostream>
#include <cstdlib>
#include <conio.h>

// Constantes
#define alto 21
#define ancho 21
#define P1 '\2'
#define P2 '\1'

// Teclas direccionales.
const char UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77;

//                                         (1)           (2)           (3)           (4)          (5)           (6)           (7)           (8)           (9)
// Matriz.                    0.     1.     2.     3.     4.     5.     6.     7.     8.    9.     10.    11.    12.    13.    14.    15.    16.    17.    18.    19.    20.
char matriz[alto][ancho] = {{'\0'  ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  },
/*                   1.*/   {'\0'  ,'\332','\304','\302','\304','\302','\304','\302','\304','\302','\304','\302','\304','\302','\304','\302','\304','\302','\304','\277','\0'  },
/*              (1)  2.*/   {'\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  },
/*                   3.*/   {'\0'  ,'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264','\0'  },
/*              (2)  4.*/   {'\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  },
/*                   5.*/   {'\0'  ,'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264','\0'  },
/*              (3)  6.*/   {'\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  },
/*                   7.*/   {'\0'  ,'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264','\0'  },
/*              (4)  8.*/   {'\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  },
/*                   9.*/   {'\0'  ,'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264','\0'  },
/*              (5) 10.*/   {'\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  },
/*                  11.*/   {'\0'  ,'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264','\0'  },
/*              (6) 12.*/   {'\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  },
/*                  13.*/   {'\0'  ,'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264','\0'  },
/*              (7) 14.*/   {'\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  },
/*                  15.*/   {'\0'  ,'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264','\0'  },
/*              (8) 16.*/   {'\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  },
/*                  17.*/   {'\0'  ,'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264','\0'  },
/*              (9) 18.*/   {'\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  },
/*                  19.*/   {'\0'  ,'\300','\304','\301','\304','\301','\304','\301','\304','\301','\304','\301','\304','\301','\304','\301','\304','\301','\304','\331','\0'  },
/*                  20.*/   {'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'\0'  }};

// Posición de los jugadores
struct Jugador
{
   char codigo;
   int posX;
   int posY;
}
//            Cód    PosX   PosY
Jugador_1 = {  P1  ,  10  ,  18  }, // Pos incial del jugador de arriba.
Jugador_2 = {  P2  ,  10  ,  2   }; // Pos inicial del jugador de abajo.

// Prototipos de Función
void Posicionar_jugadores();
void Dibujar_matriz(int turno);
void Mostrar_el_turno(int turno);
void Limpiar_posiciones();
void Siguiente_turno(int i);
void leer_teclado(Jugador& Player, char& tecla);
void Mover_Jugadores(Jugador& Player);
bool Sin_ganadores();
void Pantalla_del_ganador();

using namespace std;

int main()
{
   for(int i=0; Sin_ganadores(); i++){ // El ciclo continua mientras no hayan ganadores.

      Posicionar_jugadores();  // Inserta las fichas en la matriz.
      system("cls");           // Limpia la pantalla.
      Dibujar_matriz(i);        // Dibuja la nueva matriz.
      Limpiar_posiciones();    // Las fichas desaparecen de la matriz.
      Siguiente_turno(i);      // Cambia las posiciones de las fichas con el teclado según el turno.
   }

   Pantalla_del_ganador();
   return 0;
}

// Agrega los caracteres que representan a cada jugador en la matriz.
void Posicionar_jugadores()
{
   matriz[Jugador_1.posY][Jugador_1.posX] = P1;
   matriz[Jugador_2.posY][Jugador_2.posX] = P2;
}

// Agrega espacios vacios en las posiciones de los jugadores.
void Limpiar_posiciones()
{
   matriz[Jugador_1.posY][Jugador_1.posX] = '\0';
   matriz[Jugador_2.posY][Jugador_2.posX] = '\0';
}

// Muestra la matriz en la consola.
void Dibujar_matriz(int turno)
{
   for(int i=0; i<alto; i++) // i = posición y.
   {
      for(int j=0; j<ancho; j++) // j = posición x.
      {
         cout << matriz[i][j] ;
      }
      cout << '\n' ; // Imprime la siguiente fila un renglón abajo.
   }
   Mostrar_el_turno(turno); // El mensaje debajo de la matriz con el turno.
}

// Muestra a quién le sigue el turno y las teclas que debe usar.
void Mostrar_el_turno(int turno)
{
   if(turno % 2 == 0) // Si i es par...
   {
      cout << "\n\nTurno de: " << Jugador_1.codigo << "\tTeclas:   w\n\t\t\ta s d\n";
   }
   else
   {
      cout << "\n\nTurno de: " << Jugador_2.codigo << "\tTeclas:    \30\n\t\t\t<- \31 ->\n";
   }
}

// El turno de los jugadores cambia basandose en si i es par.
void Siguiente_turno(int i)
{
   if(i % 2 == 0) // Si i es par...
   {
      Mover_Jugadores(Jugador_1);
   }
   else
   {
      Mover_Jugadores(Jugador_2);
   }
}

// Cambia los valores de las posiciones de los jugadores con las teclas: w a s d
void Mover_Jugadores(Jugador& Player)
{
   char tecla;
   leer_teclado(Player, tecla); // Lee lo que ingresaremos por el teclado.
   switch(tecla)
   {             // Si el jugador está en un borde, no avanza.
      case 'w' : if(Player.posY-2 != 0 ) {Player.posY -= 2;} else Mover_Jugadores(Player) ; break; // Arriba
      case 's' : if(Player.posY+2 != 20) {Player.posY += 2;} else Mover_Jugadores(Player) ; break; // Abajo
      case 'a' : if(Player.posX-2 != 0 ) {Player.posX -= 2;} else Mover_Jugadores(Player) ; break; // Izquierda
      case 'd' : if(Player.posX+2 != 20) {Player.posX += 2;} else Mover_Jugadores(Player) ; break; // Derecha
      default  : Mover_Jugadores(Player) ;
   }
}

// Permite que los jugadores jueguen con diferentes comandos.
void leer_teclado(Jugador& Player, char& tecla)
{
   tecla = getch(); // Primer lectura.

   if(tecla == 'à') // Si detecta una tecla especial hace una segunda lectura.
   {
      tecla = getch();
   }
   if(Player.codigo == Jugador_2.codigo)
   {
      switch(tecla) // Reemplaza el caracter especial por uno de los que el programa puede leer.
      {
         case UP    : tecla = 'w'; break;
         case DOWN  : tecla = 's'; break;
         case LEFT  : tecla = 'a'; break;
         case RIGHT : tecla = 'd'; break;
         default    : tecla = '0';
      }
   }
}

// Verifica si aún no hay ganadores
bool Sin_ganadores()
{
   if((Jugador_1.posY == 2) || (Jugador_2.posY == 18)) // Los numeros son las posiciones en las
   {                                                   // que cada jugador gana.
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
