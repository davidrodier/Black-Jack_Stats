#ifndef _BLACK_JACK_H
#define _BLACK_JACK_H

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include "Joueur.h"

using namespace std;

class BlackJack
{
public:
	vector<int> Packet;
   Joueur* JoueurQuiJoue;
   ofstream* Excel;

	BlackJack();
   ~BlackJack();
   void Piger(Joueur & P);
   float FaireMoyenne(Joueur & J);
   void Play(Joueur & P1, Joueur & P2);
   void PrintGame(Joueur & P1, Joueur & P2);
private:
};

#endif