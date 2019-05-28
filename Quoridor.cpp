// Quoridor
// Ultima modificación: 01/03/2019
// Ultimas Adiciones: - Cada juagdor puede realizar un salto diagonal si el
//                      jugador oponente está en frente de él y tiene una pared detrás.
//                    - Las teclas que se habilitan para hacer el salto diagonal aparecen en pantalla.

// Librerias Incluidas
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <conio.h>

// Constantes
#define alto 21
#define ancho 21
#define P1 '\2'
#define P2 '\1'

// Teclas direccionales.
const char UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77;

// Teclas de salto diagonal.
const char L  = '1'; // Saltar diagonalmente a la izquierda del oponente.
const char R  = '3'; // Saltar diagonalmente a la derecha del oponente.

//                                         (1)           (2)           (3)           (4)          (5)           (6)           (7)           (8)           (9)           (10)
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
/*             (10) 20.*/   {'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'\0'  ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'/'   ,'\0'  }};

// Posición de los jugadores
struct Jugador
{
   char codigo;
   int posX;
   int posY;
}
//            Cód    PosX   PosY
Jugador_1 = {  P1  ,  5  ,  9  }, // Pos incial del jugador de arriba.
Jugador_2 = {  P2  ,  5  ,  1  }; // Pos inicial del jugador de abajo.

// Prototipos de Función
void Posicionar_jugadores();
void Dibujar_matriz(int turno, char Jump);
void Mostrar_el_turno(int turno, char Jump);
void Limpiar_posiciones();
void Siguiente_turno(int i, char& Jump);
void Leer_teclado(Jugador& Player, char& tecla);
void Avance_Recto(Jugador& Player, Jugador& Oponente, int& Pos_Player, char Dir, int Borde, char& Jump);
void Avance_Diagonal(Jugador& Player, Jugador& Oponente, int tecla, char& Jump);
void Mover_Jugadores(Jugador& Player, Jugador& Oponente, char& Jump);
void Pantalla_del_ganador();
char Determinar_diagonal(Jugador& Player, Jugador& Oponente);
bool Colindante(Jugador& Player, Jugador& Oponente, char Dir);
bool Sin_ganadores();

using namespace std;

int main()
{
   char Jump = '\0'; // Dice si se puede hacer un salto diagonal.

   for(int i=0; Sin_ganadores(); i++){ // El ciclo continua mientras no hayan ganadores.

      Posicionar_jugadores();  // Inserta las fichas en la matriz.
      system("cls");           // Limpia la pantalla.
      Dibujar_matriz(i,Jump);        // Dibuja la nueva matriz.
      Limpiar_posiciones();    // Las fichas desaparecen de la matriz.
      Siguiente_turno(i,Jump);      // Cambia las posiciones de las fichas con el teclado según el turno.
   }

   Pantalla_del_ganador();
   return 0;
}

// Agrega los caracteres que representan a cada jugador en la matriz.
void Posicionar_jugadores()
{
   matriz[Jugador_1.posY * 2][Jugador_1.posX * 2] = P1;
   matriz[Jugador_2.posY * 2][Jugador_2.posX * 2] = P2;
}

// Agrega espacios vacios en las posiciones de los jugadores.
void Limpiar_posiciones()
{
   matriz[Jugador_1.posY * 2][Jugador_1.posX * 2] = '\0';
   matriz[Jugador_2.posY * 2][Jugador_2.posX * 2] = '\0';
}

// Muestra la matriz en la consola.
void Dibujar_matriz(int turno, char Jump)
{
   for(int i=0; i<alto; i++) // i = posición y.
   {
      for(int j=0; j<ancho; j++) // j = posición x.
      {
         cout << matriz[i][j] ;
      }
      cout << '\n' ; // Imprime la siguiente fila un renglón abajo.
   }
   Mostrar_el_turno(turno, Jump); // El mensaje debajo de la matriz con el turno.
}

// Muestra a quién le sigue el turno y las teclas que debe usar debajo del tablero.
void Mostrar_el_turno(int turno, char Jump)
{
   if(turno % 2 == 0) // Si i es par...
   {
      if(Jump == '\0') // Si el salto diagonal NO está habilitado...
      {
         cout << "\n\nTurno de: " << Jugador_1.codigo << "\tTeclas:   w\n\t\t\ta s d\n";
      }
      else
      {
         switch(Jump)
         {
            case UP    : cout << "\n\nTurno de: " << Jugador_1.codigo << "\tTeclas: "<<L<<" w "<<R<<"\n\t\t\ta s d\n";            break;
            case DOWN  : cout << "\n\nTurno de: " << Jugador_1.codigo << "\tTeclas:   w\n\t\t\ta s d\n\t\t\t"<<L<<"   "<<R<<"\n"; break;
            case LEFT  : cout << "\n\nTurno de: " << Jugador_1.codigo << "\tTeclas: "<<L<<" w\n\t\t\ta s d\n\t\t\t"<<R<<"\n";     break;
            case RIGHT : cout << "\n\nTurno de: " << Jugador_1.codigo << "\tTeclas:   w 1\n\t\t\ta s d\n\t\t\t    "<<R<<"\n";     break;
            case L     : cout << "\n\nTurno de: " << Jugador_1.codigo << "\tTeclas: "<<L<<" w\n\t\t\ta s d\n";   break;
            case R     : cout << "\n\nTurno de: " << Jugador_1.codigo << "\tTeclas:   w "<<R<<"\n\t\t\ta s d\n"; break;
         }
      }
   }
   else
   {
      if(Jump == '\0') // Si el salto diagonal NO está habilitado...
      {
      cout << "\n\nTurno de: " << Jugador_2.codigo << "\tTeclas:    \30\n\t\t\t<- \31 ->\n";
      }
      else
      {
         switch(Jump)
         {
            case UP    : cout << "\n\nTurno de: " << Jugador_2.codigo << "\tTeclas:  "<<L<<" \30 "<<R<<"\n\t\t\t<- \31 ->\n";               break;
            case DOWN  : cout << "\n\nTurno de: " << Jugador_2.codigo << "\tTeclas:    \30\n\t\t\t<- \31 ->\n\t\t\t "<<L<<"   "<<R<<"\n";   break;
            case LEFT  : cout << "\n\nTurno de: " << Jugador_2.codigo << "\tTeclas:  "<<L<<" \30\n\t\t\t<- \31 ->\n\t\t\t "<<R<<"\n";       break;
            case RIGHT : cout << "\n\nTurno de: " << Jugador_2.codigo << "\tTeclas:    \30 "<<L<<"\n\t\t\t<- \31 ->\n\t\t\t     "<<R<<"\n"; break;
            case L     : cout << "\n\nTurno de: " << Jugador_2.codigo << "\tTeclas:  "<<L<<" \30\n\t\t\t<- \31 ->\n";   break;
            case R     : cout << "\n\nTurno de: " << Jugador_2.codigo << "\tTeclas:    \30 "<<R<<"\n\t\t\t<- \31 ->\n"; break;
         }
      }
   }
}

// El turno de los jugadores cambia basandose en si i es par.
void Siguiente_turno(int i, char& Jump)
{
   if(i % 2 == 0) // Si i es par...
   {
      Mover_Jugadores(Jugador_1, Jugador_2, Jump);
   }
   else
   {
      Mover_Jugadores(Jugador_2, Jugador_1, Jump);
   }
}

// Cambia los valores de las posiciones de los jugadores con el teclado
void Mover_Jugadores(Jugador& Player, Jugador& Oponente, char& Jump)
{
   char tecla;
   Leer_teclado(Player, tecla); // Lee lo que ingresaremos por el teclado.
   switch(tecla)
   {  //                                 Eje que cambia        Pared
      case 'w' : Avance_Recto(Player, Oponente, Player.posY , UP    ,  0, Jump) ; break; // Arriba

      case 's' : Avance_Recto(Player, Oponente, Player.posY , DOWN  , 10, Jump) ; break; // Abajo

      case 'a' : Avance_Recto(Player, Oponente, Player.posX , LEFT  ,  0, Jump) ; break; // Izquierda

      case 'd' : Avance_Recto(Player, Oponente, Player.posX , RIGHT , 10, Jump) ; break; // Derecha

      case  L  : if(Jump != '\0') // SI el salto diagonal NO está desabilitado...
                 {
                    Avance_Diagonal(Player, Oponente, tecla, Jump); // Avance diagonal a la izquierda.
                 }
                 else
                 {
                    Mover_Jugadores(Player, Oponente, Jump); // Tecla invalida, presione otra.
                 }
                 break;

      case  R  : if(Jump != '\0') // SI el salto diagonal NO está desabilitado...
                 {
                    Avance_Diagonal(Player, Oponente, tecla, Jump); // Avance diagonal a la derecha.
                 }
                 else
                 {
                    Mover_Jugadores(Player, Oponente, Jump); // Tecla invalida, presione otra.
                 }
                 break;

      default  : Mover_Jugadores(Player, Oponente, Jump); // Tecla invalida, presione otra.
   }
   Jump = Determinar_diagonal(Player,Oponente); // Determinar el tipo de anvace diagonal que puede hacer el siguiente
                                                // jugador o desabilitarle la posibilidad de hacerlo.
}

// Permite que los jugadores jueguen con diferentes comandos.
void Leer_teclado(Jugador& Player, char& tecla)
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
         case L     : break; // Aquí no reemplaza
         case R     : break; // ninguno.
         default    : tecla = '\0';
      }
   }
}

// Mueve al jugador según su cercanía a una pared o a otro jugador.
void Avance_Recto(Jugador& Player, Jugador& Oponente, int& Pos_Player, char Dir, int Borde, char& Jump)
{
   // Esta parte ayuda a hacer el código polimorfico.
   int Un_Paso, Dos_Pasos;
   if(Dir == DOWN || Dir == RIGHT)
   {
      Un_Paso   = Pos_Player + 1;
      Dos_Pasos = Pos_Player + 2;
   }
   else
   {
      Un_Paso   = Pos_Player - 1;
      Dos_Pasos = Pos_Player - 2;
   }

   if(Un_Paso != Borde) // ¿NO hay ninguna pared al frente?
   {
      if(Colindante(Player, Oponente, Dir)) // ¿Hay jugadores juntos?
      {
         if(Dos_Pasos == Borde) // ¿Al frente del jugador colindante hay una pared?
         {
            Mover_Jugadores(Player, Oponente, Jump); // Tecla invalida, presione otra.
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
      Mover_Jugadores(Player, Oponente, Jump); // Tecla invalida, presione otra.
   }
}

// Mueve al jugador según el tipo de avance diagonal que puede hacer.
void Avance_Diagonal(Jugador& Player, Jugador& Oponente, int tecla, char& Jump)
{
   if(Jump == UP || Jump == DOWN)
   {
      if(tecla == L) // Ir al lado izquierdo del oponente.
      {
         Player.posX = Oponente.posX - 1;
         Player.posY = Oponente.posY;
      }
      else // (tecla == R) Ir al lado derecho del oponente.
      {
         Player.posX = Oponente.posX + 1;
         Player.posY = Oponente.posY;
      }
   }
   else
   {
      if(Jump == LEFT || Jump == RIGHT)
      {
         if(tecla == L) // Ir al lado superior del oponente.
         {
            Player.posX = Oponente.posX;
            Player.posY = Oponente.posY - 1;
         }
         else // (tecla == R) Ir al lado inferior del oponente.
         {
            Player.posX = Oponente.posX;
            Player.posY = Oponente.posY + 1;
         }
      }
      else
      {
         if(Jump == R)
         {
            if(tecla == R) // Ir al lado derecho del oponente.
            {
               Player.posX = Oponente.posX + 1;
               Player.posY = Oponente.posY;
            }
            else // (tecla == L) Tecla invalida. Presionar otra.
            {
               Mover_Jugadores(Player, Oponente, Jump);
            }
         }
         else // Si Jump == L
         {
            if(tecla == L) // Ir al lado izquierdo del oponente.
            {
               Player.posX = Oponente.posX - 1;
               Player.posY = Oponente.posY;
            }
            else // (tecla == R) Tecla invalida. Presionar otra.
            {
               Mover_Jugadores(Player, Oponente, Jump);
            }
         }
      }
   }
}

// Determina el tipo de anvace diagonal que puede hacer el siguiente
// jugador o le desabilita la posibilidad de hacerlo.
char Determinar_diagonal(Jugador& Player, Jugador& Oponente)
{
   if(Player.posY == 1) // Si el jugador está en la fila 1...
   {
      if(Colindante(Player, Oponente, DOWN)) // Si hay un jugador colindante abajo...
      {
         if(Player.posX-1 == 0) // Si está en la esquina superior izquierda...
         {
            return R; // Puede subir a la derecha del oponente.
         }
         if(Player.posX+1 == 10) // Si está en la esquina superior derecha...
         {
            return L; // Puede subir a la izquierda del oponente.
         }
         else
         {
            return UP; // Puede subir a la izquierda o derecha del oponente.
         }
      }
      return '\0'; // NO puede hacer salto diagonal.
   }
   if(Player.posY == 9) // Si el jugador está en la fila 9...
   {
      if(Colindante(Player, Oponente, UP)) // Si hay un jugador colindante arriba...
      {
         if(Player.posX-1 == 0) // Si está en la esquina inferior izquierda...
         {
            return R; // Puede bajar a la derecha del oponente.
         }
         if(Player.posX+1 == 10) // Si está en la esquina inferior derecha...
         {
            return L; // Puede bajar a la izquierda del oponente.
         }
         else
         {
            return DOWN; // Puede bajar a la izquierda o derecha del oponente.
         }
      }
      return '\0'; // NO puede hacer salto diagonal.
   }
   if(Player.posX == 1) // Si el jugador está en la columna 1...
   {
      if(Colindante(Player, Oponente, RIGHT)) // Si hay un jugador colindante a la derecha...
      {
         return LEFT; // Puede ir a la parte superior o inferior del oponente, a la izquierda de la pantalla.
      }
      return '\0'; // NO puede hacer salto diagonal.
   }
   if(Player.posX == 9)
   {
      if(Colindante(Player, Oponente, LEFT))
      {
         return RIGHT; // Puede ir a la parte superior o inferior del oponente, a la derecha de la pantalla.
      }
   }
   return '\0'; // NO puede hacer salto diagonal.
}

// True si hay jugadores juntos.
bool Colindante(Jugador& Player, Jugador& Oponente, char Dir)
{
   switch(Dir)
   {  // Player y Oponente se sobreponen si...
      case UP    : return Player.posX == Oponente.posX && Player.posY-1 == Oponente.posY;
      case DOWN  : return Player.posX == Oponente.posX && Player.posY+1 == Oponente.posY;
      case LEFT  : return Player.posY == Oponente.posY && Player.posX-1 == Oponente.posX;
      case RIGHT : return Player.posY == Oponente.posY && Player.posX+1 == Oponente.posX;
   }
}

// Verifica si aún no hay ganadores
bool Sin_ganadores()
{
   if((Jugador_1.posY == 1) || (Jugador_2.posY == 9)) // Los numeros son las posiciones en las
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
