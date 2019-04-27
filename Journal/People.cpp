#include "pch.h"
#include "People.h"
#include <time.h>

People::People() // конструктор
{
}

string People::getName() //геттер имени
{
	return name;
}

void People::setName(string name)  //сеттер имени
{
	this->name = name;
}

People::~People() //деструктор
{
}

