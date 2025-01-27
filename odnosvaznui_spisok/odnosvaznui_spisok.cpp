
#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
public:
	List();
	~List();

	void pop_front();
	void clear();
	void push_back(T data);
	int GetSize() { return Size; }
	T& operator[](const int index);

	void push_front(T data);
	void pop_back();
	void insert(T data, int index);
	void removeAt(int index);

private:
	template<typename T>
	class Node
	{
	public:
		Node *pNext;
		T data;

		Node(T data=T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		};
	};
	int Size;
	Node<T> *head;
};

template<typename T>	//конструктор
List<T>::List()
{
	Size = 0;
	head = nullptr;
}

template<typename T>	//деструктор
List<T>::~List()
{
	clear();
}

template<typename T>	//удаление 1-го элемента
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	Size--;

}

template<typename T>	//очистка листа
void List<T>::clear()
{
	while (Size)
	{
		pop_front();
	}
}

template<typename T>	//добавление в конец
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data);
	}
	else 
	{
		Node<T> *current = this->head;

		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	Size++;
}

template<typename T>	//получение по индексу
T & List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T> *current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;

		}
		current = current->pNext;
		counter++;
	}

}

template<typename T>	//добавление в начало
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	Size++;
}

template<typename T>	//удаление конца
void List<T>::pop_back()
{
	removeAt(Size - 1);
}

template<typename T>	//добавление в середину
void List<T>::insert(T data, int index)
{
	if (index == 0)
	{
		push_front(data);
	}
	else
	{
		Node<T> *previous = this->head;

		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		previous->pNext = new Node<T>(data, previous->pNext);

		Size++;
	}
}

template<typename T>	//удаление из середины
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T> *toDelete = previous->pNext;

		previous->pNext = toDelete->pNext;

		delete toDelete;

		Size--;
	}
}




int main()
{
	setlocale(LC_ALL, "rus");

	List<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
	
	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

	cout << endl << "элементов в списке " << lst.GetSize() << endl << "выполняю метод clear" << endl << endl;

	lst.clear();

	cout << "элементов в списке " << lst.GetSize() << endl;
	/*int numbersCount;
	cin >> numbersCount;

	for (int  i = 0; i < numbersCount; i++)
	{
		lst.push_back(rand() % 10);
	}

	for (int i = 0; i < lst.GetSize(); i++)
	{
		cout << lst[i] << endl;
	}

//	cout << lst[2] << endl;
//	lst.GetSize();
	cin >> numbersCount;
	*/
	int i;
	cin >> i;
    return 0;
}

