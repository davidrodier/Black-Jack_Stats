#ifndef _BLACK_JACK_H
#define _BLACK_JACK_H

#include<iostream>
#include<vector>
#include<fstream>
#include<string>
#include<conio.h>
#include <ctime>
#include <time.h>
#include<sstream>
#include "Joueur.h"

using namespace std;

class BlackJack
{
public:
	vector<int> Packet;
	vector<int> Score;
	Joueur* JoueurQuiJoue;
	ofstream Excel;

	BlackJack();
	~BlackJack();
	string int_to_string(int i);
	void Piger(Joueur & P);
	float FaireMoyenne(Joueur & J);
	vector<int> Play(Joueur & P1, Joueur & P2);
	void ResetGame();
	void PrintGame(Joueur & P1, Joueur & P2);
private:
};

#endif