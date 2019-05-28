// Quoridor
// Ultima modificaci�n: 08/03/2019
// Ultimas Adiciones: - Los bloques no se salen y hay un l�mite de bloques.

// Librerias Incluidas
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <conio.h>

// Constantes
#define alto 19  // Filas de la matriz.
#define ancho 19 // Columnas de la matriz.
#define bV '1'   // Bloque Vertical.
#define bH '2'   // Bloque Horizontal.

// Teclas direccionales.
const char UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77;

// Teclas de salto diagonal.
const char L  = '1'; // Saltar diagonalmente a la izquierda del oponente.
const char R  = '3'; // Saltar diagonalmente a la derecha del oponente.

// Teclas de manipulaci�n de bloques.
const char Blo = 'p'; // Activa los bloques.
const char Gir = 'o'; // Hace girar a un bloque.
const char Ent = 'l'; // Ancla un bloque.

// Caracteres
const char P1 = '\2';   // Player 1.
const char P2 = '\1';   // Pkayer 2.
const char b0 = '\0';   // Bloque Invisible.
const char bC = '\333'; // Bloque Caracter .
const char bS = '\260'; // Bloque Superpuesto.

// Variables globales
char Blok = '\0';
char tecla = '\0'; // Guarda el caracter ASCII de la tecla que presionemos.
char SaltoD = '\0';  // Determina si se puede hacer un salto diagonal y de qu� tipo.

//                                   (1)           (2)           (3)           (4)          (5)           (6)           (7)           (8)           (9)
// Matriz.                    0.     1.     2.     3.     4.     5.     6.     7.     8.    9.     10.    11.    12.    13.    14.    15.    16.    17.    18.
char matriz[alto][ancho] = {{'\332','\304','\302','\304','\302','\304','\302','\304','\302','\304','\302','\304','\302','\304','\302','\304','\302','\304','\277'},
/*              (1)  1.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},
/*                   2.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},
/*              (2)  3.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},
/*                   4.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},
/*              (3)  5.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},
/*                   6.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},
/*              (4)  7.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},
/*                   8.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},
/*              (5)  9.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},
/*                  10.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},
/*              (6) 11.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},
/*                  12.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},
/*              (7) 13.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},
/*                  14.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},
/*              (8) 15.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},
/*                  16.*/   {'\303','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\305','\304','\264'},
/*              (9) 17.*/   {'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263','\0'  ,'\263'},
/*                  18.*/   {'\300','\304','\301','\304','\301','\304','\301','\304','\301','\304','\301','\304','\301','\304','\301','\304','\301','\304','\331'}};

// Posici�n de los jugadores.
struct Jugador
{
   char cod;
   int posX;
   int posY;
   int Bloq;
}
//            Cod   PosX  PosY   Bloq
Jugador_1 = {  P1  ,  5  ,  9  ,  10  }, // Pos incial del jugador de arriba.
Jugador_2 = {  P2  ,  5  ,  1  ,  10  }; // Pos inicial del jugador de abajo.

// Posici�n de cada bloque.
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
Bloque = {     b0     ,   0   ,   0   ,   0   ,   9   ,   0   ,   0  };

// Prototipos de Funci�n
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
void Aparecer_bloque();
void Reiniciar_bloque();
void Caracter_bloque(char& a, char& b, char& c);
void Blo_Colindante(char Key);
void Borrar_remanente();
char Tipo_De_BloColindante(char Key);
char Determinar_diagonal(Jugador& Player, Jugador& Oponente);
bool Bloque_Superpuesto();
bool Ju_Colindante(Jugador& Player, Jugador& Oponente, char Dir);
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
      Siguiente_turno(i);     // Cambia las posiciones de las fichas con el teclado seg�n el turno.
   }

   Pantalla_del_ganador();
   return 0;
}

// Agrega los caracteres que representan a cada jugador en la matriz.
void Posicionar_jugadores()
{
   matriz[Jugador_1.posY * 2 - 1][Jugador_1.posX * 2 - 1] = P1;
   matriz[Jugador_2.posY * 2 - 1][Jugador_2.posX * 2 - 1] = P2;
}

// Agrega los caracteres que representan a cada jugador en la matriz.
void Posicionar_bloques()
{
   char _1, _2, _3;
   Orientar_bloques();
   Caracter_bloque(_1,_2,_3);
   matriz[Bloque.posY1][Bloque.posX1] = _1;
   matriz[Bloque.posY2][Bloque.posX2] = _2;
   matriz[Bloque.posY3][Bloque.posX3] = _3;
}

// Agrega espacios vacios en las posiciones de los jugadores.
void Limpiar_posiciones()
{
   matriz[Jugador_1.posY * 2 - 1][Jugador_1.posX * 2 - 1] = '\0';
   matriz[Jugador_2.posY * 2 - 1][Jugador_2.posX * 2 - 1] = '\0';
}

// Hace aparecer un bloque de la nada.
void Aparecer_bloque()
{
   SaltoD = '\0'; // Inhabilita el Salto diagonal desde que aparece el bloque.
   Bloque.Orientacion = bV;
   Blo_Colindante('d');
   Bloque.posX1 = 3;
   Bloque.posY1 = 8;
}

// Hace que Blok sea igual al tipo de remanete que Limpiar_bloques() debe borrar.
void Borrar_remanente()
{
   Bloque.posX1+=2;
   Orientar_bloques();
   Blo_Colindante('a');
   Bloque.posX1-=2;
}

// Desaparece el bloque que a�n no ha sido anclado en el tablero.
void Reiniciar_bloque()
{
   Bloque.Orientacion = b0;
   Bloque.posX1 = 1;
   Bloque.posY1 = 8;
}

// Sirve para girar un bloque seg�n su orientaci�n.
void Orientar_bloques()
{
   if(Bloque.Orientacion == bV || Bloque.Orientacion == b0) // Si la orientacion es vertical.
   {
      if(Bloque.posY1 % 2 == 0) // Si es impar...
      {
         Bloque.posX1--;
         Bloque.posY1--;
      }
      Bloque.posX2 = Bloque.posX1;
      Bloque.posX3 = Bloque.posX1;
      Bloque.posY2 = Bloque.posY1+1;
      Bloque.posY3 = Bloque.posY1+2;
   }
   else // Bloque.Orientacion == bH
   {
      if(Bloque.posY1 % 2 != 0) // Si es par...
      {
         Bloque.posX1++;
         Bloque.posY1++;
      }
      Bloque.posX2 = Bloque.posX1+1;
      Bloque.posX3 = Bloque.posX1+2;
      Bloque.posY2 = Bloque.posY1;
      Bloque.posY3 = Bloque.posY1;
   }
}

// Borra la remanente del bloque que estamos manipulando.
void Limpiar_bloques()
{
   char pared;
   if(Bloque.Orientacion == bV)
   {
      pared = '\263'; // Solo pinta paredes verticales.
   }
   else // Bloque.Orientacion == bH
   {
      pared = '\304'; // Solo pinta paredes horizontales.
   }
   switch(Blok)
   {
      case '1' : matriz[Bloque.posY1][Bloque.posX1] = pared;
                 matriz[Bloque.posY2][Bloque.posX2] = '\305';
                 matriz[Bloque.posY3][Bloque.posX3] = bC;
                 break;
      case '2' : matriz[Bloque.posY1][Bloque.posX1] = bC;
                 matriz[Bloque.posY2][Bloque.posX2] = bC;
                 matriz[Bloque.posY3][Bloque.posX3] = bC;
                 break;
      case '3' : matriz[Bloque.posY1][Bloque.posX1] = bC;
                 matriz[Bloque.posY2][Bloque.posX2] = '\305';
                 matriz[Bloque.posY3][Bloque.posX3] = pared;
                 break;
      case '4' : matriz[Bloque.posY1][Bloque.posX1] = pared;
                 matriz[Bloque.posY2][Bloque.posX2] = bC;
                 matriz[Bloque.posY3][Bloque.posX3] = pared;
                 break;
      case '5' : matriz[Bloque.posY1][Bloque.posX1] = bC;
                 matriz[Bloque.posY2][Bloque.posX2] = bC;
                 matriz[Bloque.posY3][Bloque.posX3] = pared;
                 break;
      case '6' : matriz[Bloque.posY1][Bloque.posX1] = pared;
                 matriz[Bloque.posY2][Bloque.posX2] = bC;
                 matriz[Bloque.posY3][Bloque.posX3] = bC;
                 break;
      case '7' : matriz[Bloque.posY1][Bloque.posX1] = bC;
                 matriz[Bloque.posY2][Bloque.posX2] = '\305';
                 matriz[Bloque.posY3][Bloque.posX3] = bC;
                 break;
      default  : matriz[Bloque.posY1][Bloque.posX1] = pared;
                 matriz[Bloque.posY2][Bloque.posX2] = '\305';
                 matriz[Bloque.posY3][Bloque.posX3] = pared;
                 break;
   }
}

// Elije el caracter del que est�n hechos los bloques.
void Caracter_bloque(char& a, char& b, char& c)
{
   if(Bloque.Orientacion == bV || Bloque.Orientacion == bH)
   {
      switch(Blok) // Dibuja el bloque seg�n su tipo de superposicion.
      {
         case '1' : a = bC; // No Superpuesto.
                    b = bC; // No Superpuesto.
                    c = bS; // Superpuesto.
                    break;
         case '2' : a = bS; // Superpuesto.
                    b = bS; // Superpuesto.
                    c = bS; // Superpuesto.
                    break;
         case '3' : a = bS; // Superpuesto.
                    b = bC; // No Superpuesto.
                    c = bC; // No Superpuesto.
                    break;
         case '4' : a = bC;
                    b = bS;
                    c = bC;
                    break;
         case '5' : a = bS;
                    b = bS;
                    c = bC;
                    break;
         case '6' : a = bC;
                    b = bS;
                    c = bS;
                    break;
         case '7' : a = bS;
                    b = bC;
                    c = bS;
                    break;
         default  : a = bC;
                    b = bC;
                    c = bC;
                    break;
      }
   }
   else // El bloque queda escondido en una esquina del tablero.
   {
      a = '\263'; // Pared vertical.
      b = '\303'; // Pared en cruz.
      c = '\263'; // Pared vertical.
   }
}

// Muestra la matriz en la consola.
void Dibujar_matriz(int turno)
{
   cout << "/(" << Jugador_2.Bloq << ")\n" ;
   for(int i=0; i<alto; i++) // i = posici�n y.
   {
      for(int j=0; j<ancho; j++) // j = posici�n x.
      {
         cout << matriz[i][j] ;
      }
      cout << '\n' ; // Imprime la siguiente fila un rengl�n abajo.
   }
   cout << "\t      /(" << Jugador_1.Bloq << ")\n" ;
   Mostrar_el_turno(turno); // El mensaje debajo de la matriz con el turno.
}

// Muestra a qui�n le sigue el turno y las teclas que debe usar debajo del tablero.
void Mostrar_el_turno(int turno)
{
   if(turno % 2 == 0) // Si i es par...
   {
      if(SaltoD == '\0') // Si el salto diagonal NO est� habilitado...
      {
         cout << "\n\nTurno de: " << P1 << "\tTeclas:   w\n\t\t\ta s d\n";
      }
      else
      {
         switch(SaltoD)
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
      if(SaltoD == '\0') // Si el salto diagonal NO est� habilitado...
      {
      cout << "\n\nTurno de: " << P2 << "\tTeclas:    \30\n\t\t\t<- \31 ->\n";
      }
      else
      {
         switch(SaltoD)
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
      if(Blok == '\0')
      {
         cout << "\nPresione " << Gir << " para girar el bloque."
                 "\nPresione " << Ent << " para anclar el bloque."
                 "\nPresione " << Blo << " para mover su ficha.\n";
      }
      else
      {
         cout << "\nPresione " << Gir << " para girar el bloque."
                 "\nPresione " << Blo << " para mover su ficha.\n";
      }
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
      return Mover_bloque(Player, Oponente, i);
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

         case Blo : if(Player.Bloq > 0)
                    {
                       i--;
                       return Aparecer_bloque();
                    }
                    else
                    {
                       tecla = '\0';
                       return Mover_Jugadores(Player, Oponente, i);
                    }

         case  L  : if(SaltoD != '\0') // SI el salto diagonal NO est� desabilitado...
                    {
                       Avance_Diagonal(Player, Oponente, i); // Avance diagonal a la izquierda.
                    }
                    else
                    {
                       return Mover_Jugadores(Player, Oponente, i); // Tecla invalida, presione otra.
                    }
                    break;

         case  R  : if(SaltoD != '\0') // SI el salto diagonal NO est� desabilitado...
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
      SaltoD = Determinar_diagonal(Player,Oponente); // Determinar el tipo de anvace diagonal que puede hacer el siguiente
                                                   // jugador o desabilitarle la posibilidad de hacerlo.
   }
}

// Permite que los jugadores jueguen con diferentes comandos.
void Leer_teclado(Jugador& Player, char& UNA_TECLA)
{
   UNA_TECLA = getch(); // Primer lectura.

   if(UNA_TECLA == '�') // Si detecta una tecla especial hace una segunda lectura.
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
         case L     : break; // Aqu�
         case R     : break; // no
         case Blo   : break; // reemplaza
         case Gir   : break; // ninguno.
         case Ent   : break; //
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

   if(Key == Blo) // Si presion� Blo de nuevo para desactivar los bloques sin perder turno...
   {
      Limpiar_bloques();
      Reiniciar_bloque();
      tecla = '\0'; // La condici�n if(tecla == Blo) en Mover_Jugadores dejar� de cumplirse.
      i--; // El turno no se pierde.
      SaltoD = Determinar_diagonal(Oponente,Player); // Si el actual jugador estaba en una posici�n que
                                                     // le permit�a hacer un salto diagonal, a�n podr� hacerlo.
   }
   else
   {
      if(Key == Ent)
      {
         if(!Bloque_Superpuesto()) // Mientras el bloque no est� superpuesto...
         {
            Player.Bloq--;
            tecla = '\0'; // La condici�n if(tecla == Blo) en Mover_Jugadores dejar� de cumplirse.
            Reiniciar_bloque();
            SaltoD = Determinar_diagonal(Player,Oponente); // Si el otro jugador estaba en una posici�n que
         }                                                 // le permit�a hacer un salto diagonal, a�n podr� hacerlo.
         else
         {
            return Mover_bloque(Player, Oponente, i);
         }
      }
      else
      {
         {
            // Se borran los bloques de la matriz.
            if(Key == Gir) //  Si Key es igual a la tecla que gira el bloque...
            {
               if(Bloque.Orientacion == bV && Bloque.posX1 == 16 // Si es un bloque vertival en la columna 17
                  ||
                  Bloque.Orientacion == bH && Bloque.posX1 == 1) // o horizontal en la columna 2...
               {
                  return Mover_bloque(Player, Oponente, i);      // No puede girar el bloque.
               }
               else // De lo contrario s� puede girarlo.
               {
                  Limpiar_bloques();
                  Cambiar_Orientacion();
                  Borrar_remanente();
               }
            }
            else
            {
               Limpiar_bloques();
               switch(Key) // Desplazar bloque.
               {
                  case 'w' : if(Bloque.posY1 - 2 < 1) // Si presionar w generar�a que el bloque se salga de la matriz...
                             {
                                return Mover_bloque(Player, Oponente, i); // El movimiento deber�a ser invalido y presionar de nuevo.
                             }
                             else // Si no es as� la posici�n del bloque deber�a cambiar.
                             {
                                Blo_Colindante(Key);
                                Bloque.posY1 -= 2; break;
                             }
                  case 's' : if(Bloque.posY1 + 2 > 16)
                             {
                                return Mover_bloque(Player, Oponente, i);
                             }
                             else
                             {
                                Blo_Colindante(Key);
                                Bloque.posY1 += 2; break;
                             }
                  case 'a' : if(Bloque.posX1 - 2 < 1)
                             {
                                return Mover_bloque(Player, Oponente, i);
                             }
                             else
                             {
                                Blo_Colindante(Key);
                                Bloque.posX1 -= 2; break;
                             }
                  case 'd' : if(Bloque.posX1 + 2 > 16)
                             {
                                return Mover_bloque(Player, Oponente, i);
                             }
                             else
                             {
                                Blo_Colindante(Key);
                                Bloque.posX1 += 2; break;
                             }
                  default  : return Mover_bloque(Player, Oponente, i);
               }
            }
            i--; // El jugador no perder� el turno cuando la matriz se vuelva a pintar.
         }
      }
   }
}

// Retorna el tipo de bloque colindante a otro bloque.
char Tipo_De_BloColindante(char Key)
{
   int _1, _2, _3, _4, _5, _6, pared;
   if(Bloque.Orientacion == bV)
   {
      pared = '\263';
   }
   else // Bloque.Orientacion == bH
   {
      pared = '\304';
   }
   if(Key == 'w' || Key == 's')
   {
      if(Key == 'w')
      {
         _1 = Bloque.posY1-2;
         _2 = Bloque.posY2-2;
         _3 = Bloque.posY3-2;
         _4 = Bloque.posX1;
         _5 = Bloque.posX2;
         _6 = Bloque.posX3;
      }
      else // Key == s
      {
         _1 = Bloque.posY1+2;
         _2 = Bloque.posY2+2;
         _3 = Bloque.posY3+2;
         _4 = Bloque.posX1;
         _5 = Bloque.posX2;
         _6 = Bloque.posX3;
      }
   }
   else // key == 'a' || key == 'd'
   {
      if(Key == 'a')
      {
         _1 = Bloque.posY1;
         _2 = Bloque.posY2;
         _3 = Bloque.posY3;
         _4 = Bloque.posX1-2;
         _5 = Bloque.posX2-2;
         _6 = Bloque.posX3-2;
      }
      else // Key == d
      {
         _1 = Bloque.posY1;
         _2 = Bloque.posY2;
         _3 = Bloque.posY3;
         _4 = Bloque.posX1+2;
         _5 = Bloque.posX2+2;
         _6 = Bloque.posX3+2;
      }
   }
   if(matriz[_1][_4] == pared
      &&
      matriz[_2][_5] == '\305'
      &&
      matriz[_3][_6] == bC)
   {
      return '1'; // borrar, borrar, bloque
   }
   else
   {
      if(matriz[_1][_4] == bC
         &&
         matriz[_2][_5] == bC
         &&
         matriz[_3][_6] == bC)
      {
         return '2'; // no borrar nada
      }
      else
      {
         if(matriz[_1][_4] == bC
            &&
            matriz[_2][_5] == '\305'
            &&
            matriz[_3][_6] == pared)
         {
            return '3'; // bloque, borrar, borrar
         }
         else
         {
            if(matriz[_1][_4] == pared
               &&
               matriz[_2][_5] == bC
               &&
               matriz[_3][_6] == pared)
            {
               return '4'; // borrar, bloque, borrar
            }
            else // bV , '\305' , bV
            {
               if(matriz[_1][_4] == bC
                  &&
                  matriz[_2][_5] == bC
                  &&
                  matriz[_3][_6] == pared)
               {
                  return '5'; // bloque, bloque, borrar
               }
               else
               {
                  if(matriz[_1][_4] == pared
                     &&
                     matriz[_2][_5] == bC
                     &&
                     matriz[_3][_6] == bC)
                  {
                     return '6'; // blorrar, bloque, bloque
                  }
                  else // pared, pared, pared.
                  {
                     if(matriz[_1][_4] == bC
                        &&
                        matriz[_2][_5] == '\305'
                        &&
                        matriz[_3][_6] == bC)
                     {
                        return '7'; // bloque, borrar, bloque
                     }
                     else
                     {
                        return '\0'; // Borrar todo el bloque
                     }
                  }
               }
            }
         }
      }
   }
}

// Asigna a Blok el tipo de bloque colindante a otro bloque.
void Blo_Colindante(char Key)
{
   switch(Key)
   {  // Player y Oponente se sobreponen si...
      case 'w'  : Blok = Tipo_De_BloColindante(Key);
                  break;

      case 's'  : Blok = Tipo_De_BloColindante(Key);
                  break;

      case 'a'  : Blok = Tipo_De_BloColindante(Key);
                  break;

      case 'd'  : Blok = Tipo_De_BloColindante(Key);
                  break;
   }
}

bool Bloque_Superpuesto()
{
   if(matriz[Bloque.posY1][Bloque.posX1] != bC
      ||
      matriz[Bloque.posY2][Bloque.posX2] != bC
      ||
      matriz[Bloque.posY3][Bloque.posX3] != bC)
   {
      return true;
   }
   else
   {
      return false;
   }
}

// Mueve al jugador seg�n su cercan�a a una pared o a otro jugador.
void Avance_Recto(Jugador& Player, Jugador& Oponente, int& Pos_Player, char Dir, int Borde, int& i)
{
   // Esta parte ayuda a hacer el c�digo polimorfico.
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

   if(Un_Paso != Borde) // �NO hay ninguna pared al frente?
   {
      if(Ju_Colindante(Player, Oponente, Dir)) // �Hay jugadores juntos?
      {
         if(Dos_Pasos == Borde) // �Al frente del jugador colindante hay una pared?
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

// Mueve al jugador seg�n el tipo de avance diagonal que puede hacer.
void Avance_Diagonal(Jugador& Player, Jugador& Oponente, int& i)
{
   if(SaltoD == UP || SaltoD == DOWN)
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
      if(SaltoD == LEFT || SaltoD == RIGHT)
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
         if(SaltoD == R)
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
         else // Si SaltoD == L
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
   if(Player.posY == 1) // Si el jugador est� en la fila 1...
   {
      if(Ju_Colindante(Player, Oponente, DOWN)) // Si hay un jugador colindante abajo...
      {
         if(Player.posX-1 == 0) // Si est� en la esquina superior izquierda...
         {
            return R; // Puede subir a la derecha del oponente.
         }
         if(Player.posX+1 == 10) // Si est� en la esquina superior derecha...
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
   if(Player.posY == 9) // Si el jugador est� en la fila 9...
   {
      if(Ju_Colindante(Player, Oponente, UP)) // Si hay un jugador colindante arriba...
      {
         if(Player.posX-1 == 0) // Si est� en la esquina inferior izquierda...
         {
            return R; // Puede bajar a la derecha del oponente.
         }
         if(Player.posX+1 == 10) // Si est� en la esquina inferior derecha...
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
   if(Player.posX == 1) // Si el jugador est� en la columna 1...
   {
      if(Ju_Colindante(Player, Oponente, RIGHT)) // Si hay un jugador colindante a la derecha...
      {
         return LEFT; // Puede ir a la parte superior o inferior del oponente, a la izquierda de la pantalla.
      }
      return '\0'; // NO puede hacer salto diagonal.
   }
   if(Player.posX == 9)
   {
      if(Ju_Colindante(Player, Oponente, LEFT))
      {
         return RIGHT; // Puede ir a la parte superior o inferior del oponente, a la derecha de la pantalla.
      }
   }
   return '\0'; // NO puede hacer salto diagonal.
}

// True si hay jugadores juntos.
bool Ju_Colindante(Jugador& Player, Jugador& Oponente, char Dir)
{
   switch(Dir)
   {  // Player y Oponente se sobreponen si...
      case UP    : return Player.posX == Oponente.posX && Player.posY-1 == Oponente.posY;

      case DOWN  : return Player.posX == Oponente.posX && Player.posY+1 == Oponente.posY;

      case LEFT  : return Player.posY == Oponente.posY && Player.posX-1 == Oponente.posX;
   }
 /* Case RIGHT */  return Player.posY == Oponente.posY && Player.posX+1 == Oponente.posX;
}

// Verifica si a�n no hay ganadores
bool Sin_ganadores()
{
   if((Jugador_1.posY == 1) || (Jugador_2.posY == 9)) // Los numeros son las posiciones en las
   {                                                   // que cada jugador gana.
      return false;
   }
   return true;
}

// Muestra qui�n gan� el juego
void Pantalla_del_ganador()
{
   char ganador;
   if(Jugador_1.posY == 1)
   {
      ganador = P1;
   }
   else
   {
      ganador = P2;
   }
   system("cls");
   cout << "\n\n\n\n\n\n\n\n\n\tFin del juego\n\nGanador: " << ganador << endl;
   getch();
}
