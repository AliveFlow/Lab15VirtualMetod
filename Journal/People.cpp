#include "pch.h"
#include "People.h"
#include <time.h>

People::People() // �����������
{
}

string People::getName() //������ �����
{
	return name;
}

void People::setName(string name)  //������ �����
{
	this->name = name;
}

People::~People() //����������
{
}

