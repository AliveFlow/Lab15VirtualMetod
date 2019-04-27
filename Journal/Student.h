#pragma once
#include "People.h"
#include "Predmet.h"
#include "LinkedList.h"

struct Match {
	Predmet* predmet; //указатель на предмет 
	short mark; //оценка
	bool operator==(Match other)
	{ return predmet == other.predmet; } //перегрузка==
};

class Student :
	virtual public People //наследник, виртуальный
{
private:
	int count; //кол-во экзаменов
	LinkedList<Match*> *matches; //указатель 
public:
	Student(); //конструктор
	Student(string name) : People{ name } 
	{ count = 0;  //кол-во = 0
	matches = new LinkedList<Match*>(); };//новый лист 
	int getCount(); //геттер 
	void setCount(int count); //сеттер
	void addMatch(Predmet* predmet, short mark); //добавить экзамен
	void addMatch(Match * match);  //добавить узел с предметом и оценкой
	void changeMatch(Predmet* predmet, short mark); //изменить предмет и оценку
	LinkedList<Match*> *getMatches() { return matches; } //геттер экзаменов
	void delMatch(Predmet* predmet); //удалить предмет
	void* getAsStudent() { return this; }; //вернуть this
	float getAvg(); //геттер среднего балла
	string getName(); //геттер имени
	friend std::ostream& operator<< (std::ostream &out, Student &student); //перегрузка вывода
	bool operator==(Student &other) { return name == other.name; } //перегрузка ==
	void print(std::ostream &out); //вывод в файл
	~Student(); //деструктор
};

