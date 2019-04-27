#include "pch.h"
#include "Prepod.h"
#include <iostream>

Prepod::Prepod() //конструктор
{
}


Prepod::~Prepod() //деструктор
{
}

string Prepod::getName()  //геттер имени
{
	return name;
}

void Prepod::setName(string name) //сеттер имени
{
	this->name = name;
}

int Prepod::getAge()  //геттер возраста
{
	return age;
}

void Prepod::getLotDisp()  //геттер лота
{
	printf("Успешно присвоен номер...\n");
}



void Prepod::setAge(int age) //сеттер возраста
{
	this->age = age;
}

void Prepod::setLot(int nomerlota) //сеттер лота
{
	this->nomerlota = nomerlota;
	
}

void Prepod::print(std::ostream & out)  //вывод инфы о преподе в файл
{
	if (out.rdbuf() == std::cout.rdbuf())
		out << "Преподаватель " << name << " возраст " << age << " Номер " << nomerlota << std::endl;
	else
		out << "-1" << std::endl << name << std::endl << age << std::endl << nomerlota << std::endl;// -1 - признак что записан препод
}

std::ostream & operator<<(std::ostream & out, Prepod & prepod) //перегрузка вывода
{
	prepod.print(out);
	return out;
}
