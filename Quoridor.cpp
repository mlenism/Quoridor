// Quoridor
// Ultima modificación: 03/03/2019
// Ultimas Adiciones: - Ahora es posible desplazar y girar un bloque.
//                    - Se asignó una tecla para activar los movimientos del bloque.
//                    - Se generó un mensaje debajo del tablero que dice cuando se ha activado dicha tecla.

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
#define bV '\333' // Orientacion Vertical
#define bH '\334' // Orientacion Horizontal

// Teclas direccionales.
const char UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77;

// Teclas de salto diagonal.
const char L  = '1'; // Saltar diagonalmente a la izquierda del oponente.
const char R  = '3'; // Saltar diagonalmente a la derecha del oponente.

// Teclas de manipulación de bloques.
const char Blo = 'p'; // Activa los bloques.
const char Gir = 'o'; // Activa los bloques.

// Variables globales
char Jump = '\0';  // Determina si se puede hacer un salto diagonal y de qué tipo.
char tecla = '\0'; // Guarda el caracter ASCII de la tecla que presionemos.

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

// Posición de los jugadores.
struct Jugador
{
   char cod;
   int posX;
   int posY;
}
//            Cod    PosX   PosY
Jugador_1 = {  P1  ,  5  ,  9  }, // Pos incial del jugador de arriba.
Jugador_2 = {  P2  ,  5  ,  1  }; // Pos inicial del jugador de abajo.

// Posición de cada bloque.
struct Bloquear
{
   char Orientacion;
   int posX1;
   int posX2;
   int posX3;
   int posY1;
   int posY2;
   int posY3;
}
//        Orientacion   posX1   posX2   posX3   posY1   posY2   posY3
Bloque = {     bV     ,   3   ,   0   ,   0   ,   8   ,   0   ,   0  };

// Prototipos de Función
void Posicionar_jugadores();
void Posicionar_bloques();
void Orientar_bloques();
void Cambiar_Orientacion();
void Dibujar_matriz(int turno);
void Mostrar_el_turno(int turno);
void Limpiar_posiciones();
void Limpiar_bloques();
void Siguiente_turno(int& i);
void Leer_teclado(Jugador& Player, char& UNA_TECLA);
void Avance_Recto(Jugador& Player, Jugador& Oponente, int& Pos_Player, char Dir, int Borde, int& i);
void Avance_Diagonal(Jugador& Player, Jugador& Oponente, int& i);
void Mover_Jugadores(Jugador& Player, Jugador& Oponente, int& i);
void Mover_bloque(Jugador& Player, Jugador& Oponente, int& i);
void Pantalla_del_ganador();
char Determinar_diagonal(Jugador& Player, Jugador& Oponente);
bool Colindante(Jugador& Player, Jugador& Oponente, char Dir);
bool Sin_ganadores();
using namespace std;

int main()
{
   for(int i=0; Sin_ganadores(); i++){ // El ciclo continua mientras no hayan ganadores.

      Posicionar_jugadores(); // Inserta las fichas de los jugadores en la matriz.
      Posicionar_bloques();   // Inserta los bloques en la matriz.
      system("cls");          // Limpia la pantalla.
      Dibujar_matriz(i);      // Dibuja la nueva matriz.
      Limpiar_posiciones();   // Las fichas de los jugadores desaparecen de la matriz.
      Siguiente_turno(i);     // Cambia las posiciones de las fichas con el teclado según el turno.
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

// Agrega los caracteres que representan a cada jugador en la matriz.
void Posicionar_bloques()
{
   Orientar_bloques();
   matriz[Bloque.posY1][Bloque.posX1] = bV;
   matriz[Bloque.posY2][Bloque.posX2] = bV;
   matriz[Bloque.posY3][Bloque.posX3] = bV;
}

// Agrega espacios vacios en las posiciones de los jugadores.
void Limpiar_posiciones()
{
   matriz[Jugador_1.posY * 2][Jugador_1.posX * 2] = '\0';
   matriz[Jugador_2.posY * 2][Jugador_2.posX * 2] = '\0';
}

void Limpiar_bloques()
{
   if(Bloque.Orientacion == bV)
   {
      matriz[Bloque.posY1][Bloque.posX1] = '\263';
      matriz[Bloque.posY2][Bloque.posX2] = '\305';
      matriz[Bloque.posY3][Bloque.posX3] = '\263';
   }
   else // Bloque.Orientacion == bH
   {
      matriz[Bloque.posY1][Bloque.posX1] = '\304';
      matriz[Bloque.posY2][Bloque.posX2] = '\305';
      matriz[Bloque.posY3][Bloque.posX3] = '\304';
   }
}

// Sirve para girar los bloques de acuerdo a su orientación.
void Orientar_bloques()
{
   if(Bloque.Orientacion == bV) // Si la orientacion es vertical.
   {
      if(Bloque.posY1 % 2 != 0) // Si es impar...
      {
         Bloque.posX1--;
         Bloque.posY1++;
      }
      Bloque.posX2 = Bloque.posX1;
      Bloque.posX3 = Bloque.posX1;
      Bloque.posY2 = Bloque.posY1+1;
      Bloque.posY3 = Bloque.posY1+2;
   }
   else // Si es horinzontal.
   {
      if(Bloque.posY1 % 2 == 0) // Si es par...
      {
         Bloque.posX1++;
         Bloque.posY1--;
      }
      Bloque.posX2 = Bloque.posX1+1;
      Bloque.posX3 = Bloque.posX1+2;
      Bloque.posY2 = Bloque.posY1;
      Bloque.posY3 = Bloque.posY1;
   }
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

// Muestra a quién le sigue el turno y las teclas que debe usar debajo del tablero.
void Mostrar_el_turno(int turno)
{
   if(turno % 2 == 0) // Si i es par...
   {
      if(Jump == '\0') // Si el salto diagonal NO está habilitado...
      {
         cout << "\n\nTurno de: " << P1 << "\tTeclas:   w\n\t\t\ta s d\n";
      }
      else
      {
         switch(Jump)
         {
            case UP    : cout << "\n\nTurno de: " << P1 << "\tTeclas: "<<L<<" w "<<R<<"\n\t\t\ta s d\n";            break;
            case DOWN  : cout << "\n\nTurno de: " << P1 << "\tTeclas:   w\n\t\t\ta s d\n\t\t\t"<<L<<"   "<<R<<"\n"; break;
            case LEFT  : cout << "\n\nTurno de: " << P1 << "\tTeclas: "<<L<<" w\n\t\t\ta s d\n\t\t\t"<<R<<"\n";     break;
            case RIGHT : cout << "\n\nTurno de: " << P1 << "\tTeclas:   w 1\n\t\t\ta s d\n\t\t\t    "<<R<<"\n";     break;
            case L     : cout << "\n\nTurno de: " << P1 << "\tTeclas: "<<L<<" w\n\t\t\ta s d\n";   break;
            case R     : cout << "\n\nTurno de: " << P1 << "\tTeclas:   w "<<R<<"\n\t\t\ta s d\n"; break;
         }
      }
   }
   else
   {
      if(Jump == '\0') // Si el salto diagonal NO está habilitado...
      {
      cout << "\n\nTurno de: " << P2 << "\tTeclas:    \30\n\t\t\t<- \31 ->\n";
      }
      else
      {
         switch(Jump)
         {
            case UP    : cout << "\n\nTurno de: " << P2 << "\tTeclas:  "<<L<<" \30 "<<R<<"\n\t\t\t<- \31 ->\n";               break;
            case DOWN  : cout << "\n\nTurno de: " << P2 << "\tTeclas:    \30\n\t\t\t<- \31 ->\n\t\t\t "<<L<<"   "<<R<<"\n";   break;
            case LEFT  : cout << "\n\nTurno de: " << P2 << "\tTeclas:  "<<L<<" \30\n\t\t\t<- \31 ->\n\t\t\t "<<R<<"\n";       break;
            case RIGHT : cout << "\n\nTurno de: " << P2 << "\tTeclas:    \30 "<<L<<"\n\t\t\t<- \31 ->\n\t\t\t     "<<R<<"\n"; break;
            case L     : cout << "\n\nTurno de: " << P2 << "\tTeclas:  "<<L<<" \30\n\t\t\t<- \31 ->\n";   break;
            case R     : cout << "\n\nTurno de: " << P2 << "\tTeclas:    \30 "<<R<<"\n\t\t\t<- \31 ->\n"; break;
         }
      }
   }
   if(tecla != Blo) // Si no se ha presionado la tecla que activa los bloques...
   {
      cout << "\nPresione " << Blo << " para mover un bloque.\n";
   }
   else
   {
      cout << "\nPresione " << Gir << " para girar el bloque.\nPresione " << Blo << " para mover su ficha.\n";
   }
}

// El turno de los jugadores cambia basandose en si i es par.
void Siguiente_turno(int& i)
{
   if(i % 2 == 0) // Si i es par...
   {
      return Mover_Jugadores(Jugador_1, Jugador_2, i);
   }
   else
   {
      return Mover_Jugadores(Jugador_2, Jugador_1, i);
   }
}

// Cambia los valores de las posiciones de los jugadores con el teclado
void Mover_Jugadores(Jugador& Player, Jugador& Oponente, int& i)
{
   if(tecla == Blo)
   {
      Mover_bloque(Player, Oponente, i);
   }
   else
   {
      Leer_teclado(Player, tecla); // Lee lo que ingresaremos por el teclado.
      switch(tecla)
      {  //                                      Eje que cambia        Pared
         case 'w' : Avance_Recto(Player, Oponente, Player.posY , UP    ,  0 , i) ; break; // Arriba

         case 's' : Avance_Recto(Player, Oponente, Player.posY , DOWN  , 10 , i) ; break; // Abajo

         case 'a' : Avance_Recto(Player, Oponente, Player.posX , LEFT  ,  0 , i) ; break; // Izquierda

         case 'd' : Avance_Recto(Player, Oponente, Player.posX , RIGHT , 10 , i) ; break; // Derecha

         case Blo : i-- ; break;

         case  L  : if(Jump != '\0') // SI el salto diagonal NO está desabilitado...
                    {
                       Avance_Diagonal(Player, Oponente, i); // Avance diagonal a la izquierda.
                    }
                    else
                    {
                       return Mover_Jugadores(Player, Oponente, i); // Tecla invalida, presione otra.
                    }
                    break;

         case  R  : if(Jump != '\0') // SI el salto diagonal NO está desabilitado...
                    {
                       Avance_Diagonal(Player, Oponente, i); // Avance diagonal a la derecha.
                    }
                    else
                    {
                       return Mover_Jugadores(Player, Oponente, i); // Tecla invalida, presione otra.
                    }
                    break;

         default  : return Mover_Jugadores(Player, Oponente, i); // Tecla invalida, presione otra.
      }
      Jump = Determinar_diagonal(Player,Oponente); // Determinar el tipo de anvace diagonal que puede hacer el siguiente
                                                   // jugador o desabilitarle la posibilidad de hacerlo.
   }
}

// Permite que los jugadores jueguen con diferentes comandos.
void Leer_teclado(Jugador& Player, char& UNA_TECLA)
{
   UNA_TECLA = getch(); // Primer lectura.

   if(UNA_TECLA == 'à') // Si detecta una tecla especial hace una segunda lectura.
   {
      UNA_TECLA = getch();
   }
   if(Player.cod == Jugador_2.cod)
   {
      switch(UNA_TECLA) // Reemplaza el caracter especial por uno de los que el programa puede leer.
      {
         case UP    : UNA_TECLA = 'w'; break;
         case DOWN  : UNA_TECLA = 's'; break;
         case LEFT  : UNA_TECLA = 'a'; break;
         case RIGHT : UNA_TECLA = 'd'; break;
         case L     : break; // Aquí
         case R     : break; // no
         case Blo   : break; // reemplaza
         case Gir   : break; // ninguno.
         default    : UNA_TECLA = '\0';
      }
   }
}

// Cambia la orientacion de un bloque.
void Cambiar_Orientacion()
{
   if(Bloque.Orientacion == bV)
   {
      Bloque.Orientacion = bH;
   }
   else // Bloque.Orientacion == bH
   {
      Bloque.Orientacion = bV;
   }
}

// Desplaza un bloque o lo gira de acuedo a las teclas que se presionen.
void Mover_bloque(Jugador& Player, Jugador& Oponente, int& i)
{
   char Key;
   Leer_teclado(Player, Key);

   if(Key != Blo) // Si Key es diferente de la tecla que activa los bloques...
   {
      Limpiar_bloques(); // Se borran los bloques de la matriz.

      if(Key == Gir) //  Si Key es igual a la tecla que gira el bloque...
      {
         Cambiar_Orientacion();
      }
      else
      {
         switch(Key) // Desplazar bloque.
         {
            case 'w' : Bloque.posY1 -= 2; break;
            case 's' : Bloque.posY1 += 2; break;
            case 'a' : Bloque.posX1 -= 2; break;
            case 'd' : Bloque.posX1 += 2; break;
            default  : return Mover_bloque(Player, Oponente, i);
         }
      }
      i--; // Aseguramos que el jugador no perderá el turno cuando la matriz se vuelva a pintar.
   }
   else // Si Key es igual a la tecla que activa los bloques...
   {    // Significa que la presionó de nuevo porque quiere desactivar los bloques.
      tecla = '\0'; // Esto hace que la condición if(tecla == Blo) en Mover_Jugadores deje de cumplirse.
      return Mover_Jugadores(Player, Oponente, i);
   }
}

// Mueve al jugador según su cercanía a una pared o a otro jugador.
void Avance_Recto(Jugador& Player, Jugador& Oponente, int& Pos_Player, char Dir, int Borde, int& i)
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
            return Mover_Jugadores(Player, Oponente, i); // Tecla invalida, presione otra.
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
      return Mover_Jugadores(Player, Oponente, i); // Tecla invalida, presione otra.
   }
}

// Mueve al jugador según el tipo de avance diagonal que puede hacer.
void Avance_Diagonal(Jugador& Player, Jugador& Oponente, int& i)
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
               return Mover_Jugadores(Player, Oponente, i);
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
               return Mover_Jugadores(Player, Oponente, i);
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
