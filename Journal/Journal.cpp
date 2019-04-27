// Journal.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#pragma once
#include "pch.h"
#include <iostream>
#include <fstream>
#include <conio.h>
#include "LinkedList.h"
#include "Prepod.h"
#include "Student.h"
#include "Loter.h"
#include <time.h>



void loadPredmet(string filename, LinkedList<Predmet*> *p) { //загрузка из файла списка предметов
	ifstream in(filename);
	if (in) {
		while (!in.eof()) { // eof - выдаёт истину, если файл пуст, а если файл не пуст, то выдаётся ложь.
			string name;
			int id;
			in >> id; 
			in.get(); //ожидание
			if (getline(in, name)) //для ввода данных из потока (запись имени в переменную in)
				p->push(new Predmet(name, id)); //предварительно записываем имя и айди в in
		}
	}
}

void loadStudent(string filename, LinkedList<People*> *p, LinkedList<Predmet*> *predmet) {
	ifstream in(filename);
	if (in) {
		while (!in.eof()) { // eof - выдаёт истину, если файл пуст, а если файл не пуст, то выдаётся ложь.
			int who_is = 0;
			in >> who_is;
			in.get();
			string name;
			if (!getline(in, name)) return; //если не записать имя
			if (who_is == -2) {
				Student* student = new Student(name);
				int size;
				in >> size;
				for (int i = 1; i <= size; ++i) {
					int id_predmeta;
					int mark;
					in >> id_predmeta;
					in >> mark;
					Match *match = new Match();
					if(Node<Predmet*> *tmp = predmet->findNode(new Predmet("", id_predmeta)))
						match->predmet = tmp->data;
					else {
						cout << "Предмет не найден!" << endl;
						continue;
					}
					match->mark = mark;
					student->addMatch(match);
					in.get();
				}
				p->push(student);
			}
			else if (who_is == -1) {
				int age;
				int nomerlota;
				in >> age;
				in >> nomerlota;
				in.get();
				p->push(new Prepod(name, age, nomerlota));
			}
			else return;
		}
	}
}

void saveToFile(string filename, LinkedList<People*> *p) {
	ofstream out(filename);
	if (out) {
		for (int i = 1; i < p->getSize(); ++i) {
			Node<People*> *people = p->getNodeById(i);
			out << people->data->getName() << endl;
		}
	}
}

int main()
{

	class ALL : public Loter,  public Prepod
	{

	};
	

	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	LinkedList<People*> peoples;
	LinkedList<Predmet*> predmets;
	Student *st;
	Prepod *pr;
	int ans = 0;
	string name;


	while (true) {
		cout << "22 - загрузить список предметов из файла" << endl;
		cout << "1 - загрузить список предметов из файла" << endl;
		cout << "2 - загрузить список студентов/преподавателей из файла" << endl;
		cout << "3 - добавить студента в список" << endl;
		cout << "4 - добавить преподавателя в список" << endl;
		cout << "5 - добавить предмет в список" << endl;
		cout << "6 - проставить оценки студенту" << endl;
		cout << "7 - сохранить список студентов/преподавателей" << endl;
		cout << "8 - сохранить список предметов" << endl;
		cout << "9 - вывод список людей" << endl;
		cout << "10 - вывод список предметов" << endl;
		cout << "11 - удалить из списка" << endl;
		cout << "12 - изменить возраст преподавателя" << endl;
		cout << "13 - выход" << endl;
		cin >> ans;
		cin.get();
		if (ans == 1) {
			loadPredmet("sub.txt", &predmets);
		}

		else if (ans == 22) {
			ALL df;
			cout << "Введите имя преподавателя - ";
			getline(cin, name);
			if (Node<People*> *tmp = peoples.findNode(new Prepod(name))) {
				Prepod* prepod = (Prepod*)tmp->data->getAsStudent();
				cin.get(); //ожидание
				int xxx;
				xxx=df.Rand();
				prepod->setLot(xxx);
				df.getLotDisp();
			}
			
			
		}

		else if (ans == 2) {
	
			loadStudent("ppls.txt", &peoples, &predmets);
		}
		else if (ans == 3) {
			cout << "Введите имя студента - ";
			getline(cin, name);
			cout << endl;
			st = new Student(name);
			peoples.push(st);
		}
		else if (ans == 4) {
			cout << "Введите имя преподавателя - ";
			getline(cin, name);
			cout << endl;
			pr = new Prepod(name);
			peoples.push(pr);
		}
		else if (ans == 5) {
			cout << "Введите название предмета - ";
			getline(cin, name);
			cout << endl;
			predmets.push(new Predmet(name, predmets.getSize() + 1));
		}
		else if (ans == 6) {
			cout << "Введите имя студента в списке - ";
			//int id;
			//cin >> id;
			getline(cin, name);
			do {
				cout << endl << "Введите id предмета - ";
				int id_predmeta;
				cin >> id_predmeta;
				cout << endl;
				try {
					Predmet* pred;
					if(Node<People*> *tmp = peoples.findNode(new Student(name)))
						st = (Student*)tmp->data->getAsStudent();
					else {
						cout << "Нет такого студента" << endl;
						break;
					}
					if(Node<Predmet*>* tmp = predmets.findNode(new Predmet("", id_predmeta)))
						pred = tmp->data;
					else {
						cout << "Нет такого предмета" << endl;
						cout << "Нажмите Esc чтобы выйти";
						continue;
					}
					int mark;
					cout << "Введите оценку - ";
					cin >> mark;
					cout << endl;
					Match match;
					match.predmet = pred;
					if (st->getMatches()->findNode(&match)) //если предмет найден, изменяем оценку
						st->changeMatch(pred, mark);  //если такого нет, то добавляем
					else
						st->addMatch(pred, mark); //добавляем
				}
				catch (...) { cout << "Некорректные данные" << endl; }
				cout << "Нажмите Esc чтобы выйти";
			} while (_getch() != 27);
		}
		else if (ans == 7) {
			cout << "Введите имя файла - ";
			getline(cin, name);
			cout << endl;
			peoples.saveToFile(name);
		}
		else if (ans == 8) {
			cout << "Введите имя файла - ";
			getline(cin, name);
			cout << endl;
			predmets.saveToFile(name);
		}
		else if (ans == 9)
			peoples.display();
		else if (ans == 10)
			predmets.display();
		else if (ans == 11) {
			cout << "Введите имя человека - ";
			getline(cin, name);
			peoples.delNode(new People(name));
		}
		else if (ans == 12) {
			cout << "Введите имя преподавателя - ";
			getline(cin, name);
			if (Node<People*> *tmp = peoples.findNode(new Prepod(name))) {
				Prepod* prepod = (Prepod*)tmp->data->getAsStudent();
				cout << "Введите возраст - ";
				int age;
				cin >> age;
				cin.get(); //ожидание
				prepod->setAge(age);
			}
			
			else {
				cout << "Преподаватель не найден" << endl;
			}			
		}
		else if (ans == 13) return 0;
	}
	return 0;
}
