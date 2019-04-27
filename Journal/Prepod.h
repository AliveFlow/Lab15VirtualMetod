#pragma once
#include "People.h"

class Prepod :
	virtual public People  ////����������� ������������. ������������� ���������� �� ������
{

public:
	int age; //������� �������������
	int nomerlota;
	Prepod(); //�����������
	Prepod(string name) : People{ name } { age = 0; nomerlota = 0; }
	//����������� ��� �����
	Prepod(string name, int age, int nomerlota) : People{ name }, age{ age }, nomerlota{ nomerlota } {} //����������� ��� ����� � ��������
	~Prepod();  //����������
	void* getAsStudent() { return this; };
	string getName(); //������ �����
	void setName(string name); //������ �����
	int getAge(); //������ ��������
	void setAge(int age); //������ ��������
	void setLot(int nomerlota);
	void getLotDisp();
	void print(std::ostream &out); //������ � ����
	friend std::ostream& operator<< (std::ostream &out, Prepod &prepod); //���������� ������
};

