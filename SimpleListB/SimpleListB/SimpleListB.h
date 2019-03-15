#pragma once
#ifndef SimpleListB_h
#define SimpleListB_h
#include<iostream>
using namespace std;

template<typename T, int N = 10>
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
		Nodo() : Full{ false }, Next{ nullptr }, element{NULL}{}
		Nodo(struct Nodo* X) : Full { false }, Next{ X }, element{ NULL }{}
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
template<typename T, int N>
SimpleListB<T, N>::SimpleListB(string n)
{	/*
	* Constructor
	* Initialize the properties
	*/
	this->Head = NULL;
	this->ListName = n;
	this->Size = 0;
}

template<typename T, int N>
SimpleListB<T, N>::~SimpleListB()
{
	/*
	* Destructor
	* it free Heap memory
	*/
	Link p;
	while (Head)
	{
		p = Head->Next;
		delete Head;
		Head = p;
	}
}
template<typename T, int N>
 void SimpleListB<T, N>::push_front(T x)
{
	Link p = Head;
	if (!Head) {
		Head = new Nodo();
		Head->element[0] = x;
	}
	else {
		if (Size % N != 0) {
			T aux = x;
			while (p) {
				if (p->Full) { aux = p->element[N - 1]; }
				int i = N - 1;
				while (i > -1) {
					p->element[i] = p->element[i - 1];
					i--;
				}
				p->element[0] = x;
				x = aux;
				p = p->Next;
			}
		}
		if (Size%N == 0) {
			Head = new Nodo(Head);
			Head->element[0] = x;
			p = Head;
			while (p->Next) {
				for (int i = 1; i < N; i++)p->element[i] = p->Next->element[i - 1];
				p->Next->element[0] = p->Next->element[N - 1];
				for (int i = 1; i < N; i++)p->Next->element[i] = NULL;
				p = p->Next;
			}
			Head->Full = true;
		}
	}

	this->Size++;
}
template<typename T, int N>
 void SimpleListB<T, N>::push_back(T x)
{
	Link p=Head;
	if (!Head) { Head = new Nodo(); p = Head; Size++;  Head->element[0] = x;
	}
	else {
		while (p->Next != nullptr)
			p = p->Next;
		if (Size%N != 0) {
			p->element[Size%N] = x;
		}
		if (Size%N == 1) {
			p->Full = true;
			p->Next = new Nodo();
			p = p->Next;
			p->element[0] = x;
		}
		this->Size++;
	}
}
template<typename T, int N>
 void SimpleListB<T, N>::insert(T x, int pos)
{
	if (!Head) {
		Head = new Nodo();
		for (int i = 0; i < N; i++) { Head->element[i] = NULL; }
	}
	else if (pos < N) {
		for (int i = N-1; i>pos; i--) { Head->element[i] = Head->element[i - 1]; }
		Head->element[pos] = x;
		this->Size++;
	}
}
template<typename T, int N>
 bool SimpleListB<T, N>::remove(int pos, T& x)
{
	if (!Head)
		return false;
	else if (pos > -1 && pos < Size)
	{
		int bloc = pos / N;
		int location = (pos % N) - 1;
		Link p = Head;
		for (int i = 0; i < bloc; i++)
		{
			p = p->Next;
		}
		x = p[location];
		p->element[location] = -1;
		this->Size--;
		return true;
	}
}
template<typename T, int N>
 bool SimpleListB<T, N>::pop(T& x)
{
	
	if (!Head) {
		return false;
	}
	else {
		Link p = Head;
		if (Size % N != 0) {
			T aux;
			x = p->element[0];
			while (p) {
				if (p->Full) { aux = p->element[N - 1]; }
				int i = N - 1;
				while (i > -1) {
					p->element[i] = p->element[i - 1];
					i--;
				}
				p->element[0] = aux;
				p = p->Next;
			}
		}
		this->Size--;
		return true;
	}

}
template<typename T, int N>
 bool SimpleListB<T, N>::pop_back(T& x)
{
	if(!Head)
		return false;
	else
	{
		int bloc = Size / N;
		int pos = (Size % N) - 1;
		Link p = Head;
		while (p->Next)
		{
			p = p->Next;
		}
		x = p->element[pos];
		p->element[pos] = -1;
		this->Size--;
		return true;
	}
}
template<typename T, int N>
 bool  SimpleListB<T, N>::get(int pos, T& x)
{
	if (!Head)
		return false;
	else if (pos > -1 && pos < Size)
	{
		int bloc = pos / N;
		int location = (pos % N) - 1;
		Link p = &*Head;
		for (int i = 0; i < bloc; i++)
		{
			p = p->Next;
		}
		x = p->element[location];
	}
	return true;
}
template<typename T, int N>
 bool SimpleListB<T, N>::get_front(T& x)
{
	if(!Head)
		return false;
	else
	{
		x = Head->element[0];
		return true;
	}
}
template<typename T, int N>
 bool SimpleListB<T, N>::get_back(T& x)
{
	if (!Head)
		return false;
	else
	{
		int bloc = Size / N;
		int pos = (Size % N) - 1;
		Link p = Head;
		while (p->Next)
		{
			p = p->Next;
		}
		x = p->element[pos];
		return true;
	}
}
template<typename T, int N>
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