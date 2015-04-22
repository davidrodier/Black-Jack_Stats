#include "BlackJack.h"
#include<sstream>

string int_to_string(int i);

void main()
{
   BlackJack Jeu;
   
   for (int i = 40; i <= 80; i++)
   {
      *Jeu.Excel << "Partie d'ai " + int_to_string(i)+"% contre l'ai 50%" << endl;
      for (int j = 0; j < 1000; j++)
      {
         Jeu.Play(Joueur(i), Joueur(50));
      }
      *Jeu.Excel << "Partie d'ai " + int_to_string(i) + "% contre l'ai 65%" << endl;
      for (int j = 0; j < 1000; j++)
      {
         Jeu.Play(Joueur(i), Joueur(65));
      }
      *Jeu.Excel << "Partie d'ai " + int_to_string(i) + "% contre l'ai 80%" << endl;
      for (int j = 0; j < 1000; j++)
      {
         Jeu.Play(Joueur(i), Joueur(80));
      }
   }
   
}

string int_to_string(int i)
{
   ostringstream ss;
   ss << i;
   return ss.str();
}