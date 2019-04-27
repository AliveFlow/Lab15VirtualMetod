#pragma once
#include <iostream>
#include <fstream>
#include <string> 

template<typename T>
struct Node //СТРУКТУРА УЗЛА
{
	T data; //данные обобщенного типа
	Node* next; //указатель на следующий элемент списка
	bool operator==(Node<T> other) { return data == other.data; } //перегрузка ==
};

template<typename T>
class LinkedList //СПИСОК
{
private:

	Node<T>* head; //указатель на первый головной элемент
	Node<T>* tail; //указатель на хвост(последний)
	int size; //кол-во узлов

public:
	LinkedList() : head{ nullptr }, tail{ nullptr }, size{ 0 } //конструктор обнуления
	{
	}
	~LinkedList() { //деструктор
		Node<T>* currentNode = head; //текущий узел = головной

		while (currentNode) //пока есть
		{
			Node<T>* nextNode = currentNode->next; //следующий = текущий следующий
			delete currentNode; //удалит текущий
			currentNode = nextNode; //присвоит ему следующий
		}
		delete currentNode; //удаление узла
	}
	Node<T>* createNode(T data); //создать узел
	void display(); //вывод на дисплей

	void saveToFile(std::string filename); //сохранить в файл
	void push(T data); //подвинуть вперед
	Node<T> *findNode(T data); //найти узел по полезным данным
	Node<T> *getNodeById(int id); //геттер по айди 
	int getSize(); //геттер размера
	void delNode(Node<T>* node); //удалить узел по указателю
	void delNode(T data); //удалить узел по дате
};

template<typename T>
Node<T>* LinkedList<T>::createNode(T data) //создать узел
{
	Node<T>* newNode = new Node<T>; //указатель = новый список(пуст)
	newNode->data = data; //поместить дату аргумент в узел
	newNode->next = nullptr; //следующий нулл

	return newNode; //возвратить
}

template<typename T>
void LinkedList<T>::display() //вывод на экран
{
	Node<T>* currentNode = head; //текущий - головной
	std::cout << "+++++Вывод списка++++++" << std::endl;
	while (currentNode) //пока текущий(существует)
	{
		std::cout << *currentNode->data; //вывести дату узла
		currentNode = currentNode->next; //теперь идем на следующий
	}
	std::cout << "+++++++++++++++++++++++" << std::endl;
	system("pause");
}


template<typename T>
inline void LinkedList<T>::saveToFile(std::string filename) //сохранить в файл
{
	Node<T>* currentNode = head; //текущий узел - головной
	std::ofstream out(filename); //поток вывода
	if (out) { //выводимо
		while (currentNode) //пока существует
		{
			out << *currentNode->data; //вывести дату узла
			currentNode = currentNode->next; //на следующий
		}
		out.close(); //закрыть файловый поток
	}
}

template<typename T>
void LinkedList<T>::push(T data) //толкнуть от себя в конец
{
	Node<T> *newNode = createNode(data); //создать узел

	if (size == 0) //если нет
	{
		head = newNode; 
		tail = newNode;
	}
	else //иначе
	{
		tail->next = newNode; //следующий после конечного - новый (вместо нулл заменяем на узел)
		tail = newNode;  //теперь newNode конец
	}

	++size; //счетчик кол-ва 
}

template<typename T>
Node<T>* LinkedList<T>::findNode(T data) //найти узел
{
	Node<T>* currentNode = head; //текущий - головной

	while (currentNode) //пока текущий есть
	{
		if (*(currentNode->data) == *data) //если указатель даты текущего равен дате введенной
			return currentNode; //возвратить текущий узел
		currentNode = currentNode->next; //иначе идти дальше
	}
	return nullptr; //возврат нулевого указателя
}

template<typename T>
Node<T>* LinkedList<T>::getNodeById(int id) //найти узел по айди 
{ 
	if (id > size) return nullptr; //если ложный ввод то возвратить нуллптр
	Node<T>* currentNode = head; //текущий - головной

	while (id++ < size) //пока введенный идентификатор меньше размера 
		currentNode = currentNode->next; //далее
	return currentNode; //возврат текущего найденного
}

template<typename T>
int LinkedList<T>::getSize() //геттер размера
{
	return size;
}

template<typename T>
void LinkedList<T>::delNode(Node<T>* node) //удалить узел по указателю
{
	if (node == nullptr) return; //если пуст
	if (node == head) { //если он головной 
		head = head->next; //Присвоить головному следующий после него; удалить узел 
		delete node;
		--size;  //уменьшить размер на -1
		
	}

	Node<T>* currentNode = head; //текущий - головной
	if (head == nullptr) return;
	while (currentNode->next) { //пока далее идет 
		
		if (currentNode->next == node) { //если следующий == узлу введенному
			currentNode->next = node->next; //сдвигаем 
			delete node; //удаляем
			--size; //-1 узел
			return;
		}
		currentNode = currentNode->next; //далее по узлам
	}
	
}

template<typename T>
inline void LinkedList<T>::delNode(T data) //удалить узел по дате
{
	delNode(findNode(data));   //удалить (найти по дате)
} 
