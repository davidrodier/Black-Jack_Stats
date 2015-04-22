#include "BlackJack.h"


BlackJack::BlackJack()
{
	ResetGame();
	Excel.open("Parties.csv");
}

BlackJack::~BlackJack()
{
	delete JoueurQuiJoue;
	Excel.close();
}

void BlackJack::Piger(Joueur & P)
{
	if (*Packet.begin() == 1)
	if (P.Score <= 11)
		P.Score += 10;
	else
		P.Score += 1;
	else
		P.Score += *Packet.begin();


	Packet.erase(Packet.begin());
}

float BlackJack::FaireMoyenne(Joueur & J)
{
	float NbPoints = 0;

	for (int i = 0; i < Packet.size(); i++)
	{
		if (Packet.at(i) == 1)
		{
			if (J.Score <= 11)
				NbPoints += 10;
			else
				NbPoints += 1;
		}
		NbPoints += (float)Packet.at(i);
	}

	return (float)NbPoints / (float)Packet.size();
}

void BlackJack::ResetGame()
{
	Packet.clear();
	Score.clear();
	Score = { 0, 0 };

	for (int i = 1, j = 1; i <= 13 && j <= 4; i++)
	{
		
		if (Packet.size() == 0)
			Packet.insert(Packet.begin(), i);
		else if (i<=10)
			Packet.insert(Packet.begin() + rand() % Packet.size() + 1, i);
		else
			Packet.insert(Packet.begin() + rand() % Packet.size() + 1, 10);

		if (i == 13)
		{
			i = 0;
			j++;
		}
	}
}

vector<int> BlackJack::Play(Joueur & P1, Joueur & P2)
{
	ResetGame();
	bool Playing = true;
	JoueurQuiJoue = &P2;

	while (Playing)
	{
		if (JoueurQuiJoue->Diff == P1.Diff)
		{
			JoueurQuiJoue = &P2;
		}
		else
		{
			JoueurQuiJoue = &P1;
		}

		if (JoueurQuiJoue->Playing)
		{
			if (JoueurQuiJoue->Score < 10)
			{
				Piger(*JoueurQuiJoue);
			}
			else
			{
				if (JoueurQuiJoue->Diff == 50)
				{
					if ((float)JoueurQuiJoue->Score + FaireMoyenne(*JoueurQuiJoue) > 21)
					{
						JoueurQuiJoue->Playing = false;
					}
					else
					{
						Piger(*JoueurQuiJoue);
					}
				}
				else
				{
					if ((float)JoueurQuiJoue->Score + FaireMoyenne(*JoueurQuiJoue) * 2 * ((float)JoueurQuiJoue->Diff / 100) > 21)
					{
						JoueurQuiJoue->Playing = false;
					}
					else
					{
						Piger(*JoueurQuiJoue);
					}
				}
			}
		}

		if (JoueurQuiJoue->Score >= 21)
		{
			JoueurQuiJoue->Playing = false;
		}

		Playing = (P1.Playing || P2.Playing);
	}

	PrintGame(P1, P2);

	return Score;
}

void BlackJack::PrintGame(Joueur & P1, Joueur & P2)
{
	if (P1.Score > P2.Score && P1.Score <= 21)
	{
		Score.at(0)++;
		//Excel << "P1(" + int_to_string(P1.Score) + "), 1, P2(" + int_to_string(P2.Score) + "), 0" << endl;
	}
	else if (P1.Score > P2.Score && P1.Score > 21 && P2.Score <= 21)
	{
		Score.at(1)++;
		//Excel << "P1(" + int_to_string(P1.Score) + "), 0, P2(" + int_to_string(P2.Score) + "), 1" << endl;
	}
	else if (P1.Score < P2.Score && P2.Score <= 21)
	{
		Score.at(1)++;
		//Excel << "P1(" + int_to_string(P1.Score) + "), 0, P2(" + int_to_string(P2.Score) + "), 1" << endl;
	}
	else if (P1.Score < P2.Score && P1.Score <= 21 && P2.Score > 21)
	{
		Score.at(0)++;
		//Excel << "P1(" + int_to_string(P1.Score) + "), 1, P2(" + int_to_string(P2.Score) + "), 0" << endl;
	}
	else if (P1.Score > 21 && P2.Score > 21)
	{
		Score.at(1)++;
		//Excel << "P1(" + int_to_string(P1.Score) + "), 0, P2(" + int_to_string(P2.Score) + "), 0" << endl;
	}
	else if (P1.Score == P2.Score)
	{
		Score.at(0)++;
		//Excel << "P1(" + int_to_string(P1.Score) + "), 1, P2(" + int_to_string(P2.Score) + "), 1" << endl;
	}

}

string BlackJack::int_to_string(int i)
{
	ostringstream ss;
	ss << i;
	return ss.str();
}