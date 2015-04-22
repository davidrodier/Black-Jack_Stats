#ifndef _JOUEUR_H
#define _JOUEUR_H

class Joueur
{
public:
   Joueur(int C_diff)
   {
      Score = 0;
      Diff = C_diff;
      Playing = true;
   }
   Joueur()
   {
      Score = 0;
      Diff = 0;
      Playing = false;
   }

   int Score;
   int Diff;
   bool Playing;
private:
};

#endif