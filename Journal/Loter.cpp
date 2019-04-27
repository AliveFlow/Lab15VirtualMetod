#include "pch.h"
#include "Loter.h"
#include <iostream>
#include <time.h>


int Loter::Rand()  //лотерейное число
{
	srand(time(NULL));
	int x = rand() % 500 + 1;
	printf("You lottery number - %d\n", x);
	return x;
}