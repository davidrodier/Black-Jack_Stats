#include "BlackJack.h"

void main()
{
	srand(time(NULL));
	BlackJack Jeu;
	vector<int> Scores = { 0, 0 };
	vector<int> temp = { 0, 0 };

	for (int i = 40; i < 80; i++)
	{
		if (i == 50 || i == 65)
			i++;
		cout << i << endl;
		Jeu.Excel << "Partie d'AI " + Jeu.int_to_string(i) + "% contre l'AI 50%" << endl;
		Scores = { 0, 0 };
		for (int j = 0; j < 1000; j++)
		{
			temp = Jeu.Play(Joueur(i), Joueur(50));
			Scores.at(0) += temp.at(0);
			Scores.at(1) += temp.at(1);
		}
		Jeu.Excel << "P1(" + Jeu.int_to_string(i) + "), " + Jeu.int_to_string(Scores.at(0)) + ", " + Jeu.int_to_string(Scores.at(1)) + ",P2(50)" << endl;
		Jeu.Excel << "Partie d'AI " + Jeu.int_to_string(i) + "% contre l'AI 65%" << endl;
		Scores = { 0, 0 };
		for (int j = 0; j < 1000; j++)
		{
			temp = Jeu.Play(Joueur(i), Joueur(65));
			Scores.at(0) += temp.at(0);
			Scores.at(1) += temp.at(1);
		}
		Jeu.Excel << "P1(" + Jeu.int_to_string(i) + "), " + Jeu.int_to_string(Scores.at(0)) + ", " + Jeu.int_to_string(Scores.at(1)) + ",P2(65)" << endl;
		Jeu.Excel << "Partie d'AI " + Jeu.int_to_string(i) + "% contre l'AI 80%" << endl;
		Scores = { 0, 0 };
		for (int j = 0; j < 1000; j++)
		{
			temp = Jeu.Play(Joueur(i), Joueur(80));
			Scores.at(0) += temp.at(0);
			Scores.at(1) += temp.at(1);
		}
		Jeu.Excel << "P1(" + Jeu.int_to_string(i) + "), " + Jeu.int_to_string(Scores.at(0)) + ", " + Jeu.int_to_string(Scores.at(1)) + ",P2(80)" << endl;
	}

}