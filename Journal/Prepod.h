#pragma once
#include "People.h"

class Prepod :
	virtual public People  ////виртуальное наследование. Разновидность композиции по ссылке
{

public:
	int age; //возраст преподавателя
	int nomerlota;
	Prepod(); //конструктор
	Prepod(string name) : People{ name } { age = 0; nomerlota = 0; }
	//конструктор для имени
	Prepod(string name, int age, int nomerlota) : People{ name }, age{ age }, nomerlota{ nomerlota } {} //конструктор для имени и возраста
	~Prepod();  //деструктор
	void* getAsStudent() { return this; };
	string getName(); //геттре имени
	void setName(string name); //сеттер имени
	int getAge(); //геттер возраста
	void setAge(int age); //сеттер возраста
	void setLot(int nomerlota);
	void getLotDisp();
	void print(std::ostream &out); //печать в файл
	friend std::ostream& operator<< (std::ostream &out, Prepod &prepod); //перегрузка вывода
};

