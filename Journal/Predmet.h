#pragma once
#include <string>
using namespace std;

class Predmet
{
private:
	int id; //���������� ����� ��������
	string name; //�������� ��������
public:
	Predmet() {}; //�����������
	Predmet(string name, int id) : name{ name }, id { id } {}; //����������� ��� ����� � ����
	~Predmet() {}; //����������
	friend std::ostream& operator<< (std::ostream &out, Predmet &predmet) //���������� ������
	{ out << predmet.id << " " << predmet.name << endl;
	return out;
	}
	string getName() { return name; } //������ �����
	int getId() { return id; } //������ ����
	void setName(string name) { this->name = name; } //������ �����
	bool operator==(Predmet other) { return id == other.id;	} //���������� ==
};
