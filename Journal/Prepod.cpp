#include "pch.h"
#include "Prepod.h"
#include <iostream>

Prepod::Prepod() //�����������
{
}


Prepod::~Prepod() //����������
{
}

string Prepod::getName()  //������ �����
{
	return name;
}

void Prepod::setName(string name) //������ �����
{
	this->name = name;
}

int Prepod::getAge()  //������ ��������
{
	return age;
}

void Prepod::getLotDisp()  //������ ����
{
	printf("������� �������� �����...\n");
}



void Prepod::setAge(int age) //������ ��������
{
	this->age = age;
}

void Prepod::setLot(int nomerlota) //������ ����
{
	this->nomerlota = nomerlota;
	
}

void Prepod::print(std::ostream & out)  //����� ���� � ������� � ����
{
	if (out.rdbuf() == std::cout.rdbuf())
		out << "������������� " << name << " ������� " << age << " ����� " << nomerlota << std::endl;
	else
		out << "-1" << std::endl << name << std::endl << age << std::endl << nomerlota << std::endl;// -1 - ������� ��� ������� ������
}

std::ostream & operator<<(std::ostream & out, Prepod & prepod) //���������� ������
{
	prepod.print(out);
	return out;
}
