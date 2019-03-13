#pragma once
#ifndef SimpleListB_h
#define SimpleListB_h
#include<iostream>
using namespace std;

template<class T, int N = 10>
class SimpleListB
{private:
	struct Nodo
	{
		//region Properties
		bool Full;	//Indicator if the array is fully
		T element[N];	//Array to N elements
		struct Nodo* Next; //Pointer to next node
		//end region
		//region Contructors
		Nodo() :Full{ false }, Next{ nullptr }{}
		Nodo(struct Nodo* X)Full { false }, Next{ X }{}
		//end region
	};
	typedef struct Nodo* Link;
	//region Properties
	Link Head;
	int Size;
	string ListName;
	//end region
public:
	//region Declarations
	SimpleListB(string);
	~SimpleListB();
	int length() { return this->Size; }
	void push_front(T x);
	void psuh_back(T x);
	void insert(T x, int pos);
	bool remove(int pos, T& x);
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& x);
	bool get_front(T& x);
	bool get_back(T& x);
	void print();
	//end region
};

//region Definitions
template<class T, int N>
SimpleListB<T,N>::SimpleListB(string n)
{
	this->Head = NULL;
	this->ListName = n;
	this->Size = 0;
}

template<class T, int N>
SimpleListB<T,N>::~SimpleListB()
{
	Link p;
	while (Head)
	{
		p = Head->Next;
		delete Head;
		Head = p;
	}
}
template<class T, int N>
void SimpleListB<T,N>:: push_front(T x)
{

}
template<class T, int N>
void SimpleListB<T, N>::psuh_back(T x)
{

}
template<class T, int N>
void SimpleListB<T, N>::insert(T x, int pos)
{

}
template<class T, int N>
bool SimpleListB<T, N>::remove(int pos, T& x)
{
	return false;
}
template<class T, int N>
bool SimpleListB<T, N>::pop(T& x)
{
	return false;
}
template<class T, int N>
bool SimpleListB<T, N>::pop_back(T& x)
{
	return false;
}
template<class T, int N>
bool  SimpleListB<T, N>::get(int pos, T& x)
{
	return false;
}
template<class T, int N>
bool SimpleListB<T, N>::get_front(T& x)
{
	return false;
}
template<class T, int N>
bool SimpleListB<T, N>::get_back(T& x)
{
	return false;
}
template<class T, int N>
void SimpleListB<T, N>::print()
{

}
//end region
#endif // !SimpleListB