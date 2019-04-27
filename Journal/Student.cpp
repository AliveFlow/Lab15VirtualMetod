#include "pch.h"
#include "Student.h"


Student::Student() //конструктор
{
	count = 0;  //обнуление количества экзов
	matches = new LinkedList<Match*>(); //новый лист экзаменов
}

int Student::getCount()  //геттер
{
	return count;
}

void Student::setCount(int count) //сеттер
{
	this->count = count;
}

void Student::addMatch(Predmet * predmet, short mark) //добавить предмет с оценкой
{
	Match *match = new Match(); //указатель равный новому списку
	match->mark = mark;  //элемент оценки деткущего указателя = введенной оценке
	match->predmet = predmet; //аналогично с предметом
	matches->push(match); //вызвать пуш для объекта указателя
	count = matches->getSize(); //считать количество узлов и записать в переменную, то есть узнать кол-во предметов
}

void Student::addMatch(Match * match) { 
	matches->push(match); //добавить узел в список
	count = matches->getSize();  //вызвать метод getSize объекта matches
}

void Student::changeMatch(Predmet * predmet, short mark)
{
	Match* tmp = new Match(); //указатель присвоен новому списку
	tmp->predmet = predmet; //объект predmet указателя tmp присвоен введенному
	Match* match = matches->findNode(tmp)->data; //указатель = вызвать метод поиска узла по переменной и получить полезные данные
	match->mark = mark;
}

void Student::delMatch(Predmet * predmet) //удалить узел с предметом
{
	Match* tmp = new Match(); //указатель = новый список
	tmp->predmet = predmet; //из tmp считать предмет и перезаписать на введенный (аргумент метода)
	matches->delNode(matches->findNode(tmp)); //вызвать метод удаления узла (найти узел по данным) далее  удалить
	count = matches->getSize(); //обновить инфу о кол-ве
}

float Student::getAvg() //получить средний балл
{
	if (matches->getSize() == 0) return 0; //если узлов нет и список пуст
	float avg = 0; //то ср балл 0
	for (int i = 1; i <= matches->getSize(); i++) //иначе идем по циклу до кол-ва узлов
		avg += matches->getNodeById(i)->data->mark; //счетчик (метод получения узла по номеру-полезная дата-оценка)
	return avg / matches->getSize(); //возвращаем (оценки / кол-во предметов)
}

string Student::getName() //геттер имени
{
	return name;
}


void Student::print(std::ostream & out) //запись в файл
{
	if (out.rdbuf() == std::cout.rdbuf()) { //rdbuf() просто возвращает указатель на базовый объект basic_streambuf для данного объекта [io]stream
		out << "Студент " << name << "  Средний балл - " << getAvg() << endl; //вывод инфы о студенте 
		Match* match; //объявили указатель 
		for (int i = 1; i <= count; ++i) { //цикл до кол-ва узлов
			match = matches->getNodeById(i)->data; //получаем полезную дату методом поиска по идентификатору узала и запишем в переменную указатель
			out << "       " << match->predmet->getName() << " " << match->mark << endl; //выводим предмет имя и оценку из переменной указателя
		}
	}
	else {  //иначе 
		out << "-2" << endl; // признак того, что записан студент
		out << name << endl; //вывод имени
		out << count << endl; //вывод кол-ва экзов
		Match* match; //объявили указатель
		for (int i = 1; i <= count; ++i) { //цикл до кол-ва предметов
			match = matches->getNodeById(i)->data; //записали в указатель дату узла
			out << match->predmet->getId() << " " << match->mark << endl; //вывели айди предмета и оценку
		}
	}
}

Student::~Student()  //деструктор удаляет узлы (экзы)
{
	delete matches;
}

std::ostream & operator<<(std::ostream & out, Student & student) //перегрузка оператора вывода
{
	student.print(out); 
	return out;
}
