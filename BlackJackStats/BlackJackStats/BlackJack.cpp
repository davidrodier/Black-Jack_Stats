#include "BlackJack.h"

#include <ctime>

BlackJack::BlackJack()
{
	srand(time(NULL));

	for (int i = 0, j = 1; i <= 13, j != 4; i++, j++)
	{
		Packet.insert(rand() % Packet.size(), i);
	}
}