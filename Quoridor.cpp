// Quoridor
// Ultima modificación: 26/02/2019
// Ultimas Adiciones: - Los jugadores ya no se superponen

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
Jugador_2 = {  P2  ,  10  ,  02  }; // Pos inicial del jugador de abajo.

// Prototipos de Función
void Posicionar_jugadores();
void Dibujar_matriz(int turno);
void Mostrar_el_turno(int turno);
void Limpiar_posiciones();
void Siguiente_turno(int i);
void leer_teclado(Jugador& Player, char& tecla);
void Avanzar(Jugador& Player, Jugador& Oponente, int& Pos_Player, char Dir, int Borde);
void Mover_Jugadores(Jugador& Player, Jugador& Oponente);
void Pantalla_del_ganador();
bool Jugador_colindante(Jugador& Player, Jugador& Oponente, char Dir);
bool Sin_ganadores();

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
      Mover_Jugadores(Jugador_1, Jugador_2);
   }
   else
   {
      Mover_Jugadores(Jugador_2, Jugador_1);
   }
}

// Cambia los valores de las posiciones de los jugadores con el teclado
void Mover_Jugadores(Jugador& Player, Jugador& Oponente)
{
   char tecla;
   leer_teclado(Player, tecla); // Lee lo que ingresaremos por el teclado.
   switch(tecla)
   {  //                                 Eje que cambia        Pared
      case 'w' : Avanzar(Player, Oponente, Player.posY , UP    ,  0) ; break; // Arriba
      case 's' : Avanzar(Player, Oponente, Player.posY , DOWN  , 20) ; break; // Abajo
      case 'a' : Avanzar(Player, Oponente, Player.posX , LEFT  ,  0) ; break; // Izquierda
      case 'd' : Avanzar(Player, Oponente, Player.posX , RIGHT , 20) ; break; // Derecha
      default  : Mover_Jugadores(Player, Oponente) ;
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

// Mueve al jugador según su cercanía a una pared o a otro jugador.
void Avanzar(Jugador& Player, Jugador& Oponente, int& Pos_Player, char Dir, int Borde)
{
   int Un_Paso, Dos_Pasos;
   if(Dir == DOWN || Dir == RIGHT)
   {
      Un_Paso   = Pos_Player + 2;
      Dos_Pasos = Pos_Player + 4;
   }
   else
   {
      Un_Paso   = Pos_Player - 2;
      Dos_Pasos = Pos_Player - 4;
   }

   if(Un_Paso != Borde) // ¿No hay pared al lado?
   {
      if(Jugador_colindante(Player, Oponente, Dir)) // ¿Hay jugadores juntos?
      {
         if(Dos_Pasos == Borde) // ¿Al lado del jugador colindante hay una pared?
         {
            Mover_Jugadores(Player, Oponente); // Tecla invalida, presione otra.
         }
         else
         {
            Pos_Player = Dos_Pasos; // Dar un salto de dos pasos.
         }
      }
      else
      {
         Pos_Player = Un_Paso; // Dar un salto de un paso.
      }
   }
   else
   {
      Mover_Jugadores(Player, Oponente); // Tecla invalida, presione otra.
   }
}

// True si hay jugadores juntos.
bool Jugador_colindante(Jugador& Player, Jugador& Oponente, char Dir)
{
   switch(Dir)
   {  // Player y Oponente se sobreponen si...
      case UP    : return Player.posX == Oponente.posX && Player.posY-2 == Oponente.posY;
      case DOWN  : return Player.posX == Oponente.posX && Player.posY+2 == Oponente.posY;
      case LEFT  : return Player.posY == Oponente.posY && Player.posX-2 == Oponente.posX;
      case RIGHT : return Player.posY == Oponente.posY && Player.posX+2 == Oponente.posX;
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
