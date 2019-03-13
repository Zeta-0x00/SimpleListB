#pragma once
#ifndef SimpleListB_h
#define SimpleListB_h
#include<iostream>
using namespace std;

template<class T, int N = 10>
class SimpleListB
{
	struct Nodo
	{
		//region Properties
		bool Full;	//Indicator if the array is fully
		T element[N];	//Array to N elements
		struct Nodo* Next; //Pointer to next node
		//end region
		//region Contructors
		Nodo() : Full{ false }, Next{ nullptr }{}
		Nodo(struct Nodo* X) : Full { false }, Next{ X }{}
		//end region
	};
	typedef struct Nodo* Link;
	//region Properties
	Link Head;
	int Size;
	int Tam;
	string ListName;
	//end region
public:
	//region Declarations
	SimpleListB(string);
	~SimpleListB();
	int length() { return this->Size; }
	void push_front(T x);
	void push_back(T x);
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
SimpleListB<T, N>::SimpleListB(string n)
{
	this->Head = NULL;
	this->ListName = n;
	this->Size = 0;
}

template<class T, int N>
SimpleListB<T, N>::~SimpleListB()
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
void SimpleListB<T, N>::push_front(T x)
{
	Link p = Head;
	if (!Head) {
		Head = new Nodo();p = Head;
	}
	if(Tam==N) {
		Head = new Nodo(p);
		p->Full = true;
		Size++;
		Tam = 0;
	}
	if (Tam==0){
	for (int i = 0; i < N; i++) { p->element[i] = NULL; }
	}cout << Head->element[0] << endl;
	if (Head->element[0] != NULL) {
		int i = N- 1;
		while (i > -1) {
			Head->element[i] = Head->element[i-1];
			i--;
		}
	}Tam++;
	Head->element[0] = x;
}
template<class T, int N>
void SimpleListB<T, N>::push_back(T x)
{
	Link p=Head;
	if (!Head) { Head = new Nodo(); p = Head; }
	while (p->Next != nullptr)
		p = p->Next;
	if (Tam < N) {
		if (Tam == 0) {
			for (int i = 0; i < N; i++) { p->element[i] = NULL; }
		}
		p->element[Tam] = x;
		Tam++;
	}
	if (Tam == N){
		p->Full = true;
		Size++;
		Tam = 0;
		p->Next = new Nodo();
		p = p->Next;
	}
	cout << Size<<Tam << "/" << x << "\n";
}
template<class T, int N>
void SimpleListB<T, N>::insert(T x, int pos)
{
	if (!Head) {
		Head = new Nodo();
		for (int i = 0; i < N; i++) { Head->element[i] = NULL; }
	}
	if (pos < N) {
		for (int i = N-1; i>pos; i--) { Head->element[i] = Head->element[i - 1]; }
		Head->element[pos] = x;
		Tam++;
	}
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
	cout << ListName << " = [";
	if (Head) {
		Link p = Head;
		while (p) {
		int i = 0;
		cout << "[";
		cout << p->element[i];
		while (i<N-1){
			cout << ", " << p->element[i+1];
			i++;
		}
		p = p->Next;
		cout << "]";
		}
	}
	cout << "]\n";
}
//end region
#endif // !SimpleListB