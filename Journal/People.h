#pragma once
#include <string>
using namespace std;

class People 
{
protected:
	string name; // переменная имя человека 
public:
	People(); //контруктр
	People(string name) : name{ name } {} //конструктор для имени
	string getName();   //геттер имени
	void setName(string name); //сеттер имени
	virtual ~People();  //деструктор
	virtual void print(std::ostream&) {}; //виртуальный метод печати в файл
	virtual bool operator==(People &other) { return name == other.name; }; //перегрузка ==
	virtual void *getAsStudent() { return this; };  //возврат this
	friend std::ostream& operator<< (std::ostream &out, People &people) //перегрузка вывода
	{ people.print(out); return out; };  //вывод в файл аргумента
};

