#pragma once
#include <string>
using namespace std;

class Predmet
{
private:
	int id; //уникальный номер предмета
	string name; //название предмета
public:
	Predmet() {}; //конструктор
	Predmet(string name, int id) : name{ name }, id { id } {}; //конструктор для имени и айди
	~Predmet() {}; //деструктор
	friend std::ostream& operator<< (std::ostream &out, Predmet &predmet) //перегрузка вывода
	{ out << predmet.id << " " << predmet.name << endl;
	return out;
	}
	string getName() { return name; } //геттер имени
	int getId() { return id; } //геттер айди
	void setName(string name) { this->name = name; } //сеттер имени
	bool operator==(Predmet other) { return id == other.id;	} //перегрузка ==
};
