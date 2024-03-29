#pragma once
#ifndef SimpleList_h
#define SimpleList_h

#include <iostream>
#include <string>

using std::string;
using std::cout;

template <typename T>
class List {
private:
	struct Nodo {
		T elemento;
		struct Nodo * siguiente;
		Nodo(T x) :elemento{ x }, siguiente{ 0 } {}
		Nodo(T x, struct Nodo* sig) :elemento{ x }, siguiente{ sig } {}
	};

	typedef struct Nodo * link;

	link primero;        // Puntero al primer elemento de la lista
	int tam;            // Cantidad de elementos de la lista
	string nombreLista;    // Nombre de la lista

						   // M�todo de clase
	static void insertR(link &p, T x, int pos);

public:

	List(string nombre);
	int len();
	void push_front(T x);
	void push_back(T x);
	void insertar(T x, int pos);
	void insertarR(T x, int pos);
	bool remove(int pos, T& x);
	bool pop(T& x);
	bool pop_back(T& x);
	bool get(int pos, T& element);
	bool get_front(T& element);
	bool get_back(T& element);
	void print();
	~List();

};

template<typename T>
void List<T>::insertR(link & p, T x, int pos) {
	if (p == NULL)
		p = new Nodo(x);
	else {
		if (pos == 0)
			p = new Nodo(x, p);
		else
			insertR(p->siguiente, x, pos - 1);
	}
}

template<typename T>
List<T>::List(string nombre) {
	nombreLista = nombre;
	primero = NULL;
	tam = 0;
}

template <typename T>
void List<T>::push_front(T x) {
	primero = new Nodo(x, primero);
	tam++;
}

template<typename T>
void List<T>::push_back(T x) {
	if (!primero)
		primero = new Nodo(x, primero);
	else {
		link p;
		for (p = primero; p->siguiente; p = p->siguiente) {}
		p->siguiente = new Nodo(x);
	}
	tam++;
}

template<typename T>
void List<T>::insertar(T x, int pos) {
	if (!primero) {
		primero = new Nodo(x);
	}
	else {
		if (pos == 0)
			primero = new Nodo(x, primero);
		else {
			link p = primero;
			while (p->siguiente && pos > 1) {
				p = p->siguiente;
				pos--;
			}
			p->siguiente = new Nodo(x, p->siguiente);
		}
	}
	tam++;
}

template<typename T>
void List<T>::insertarR(T x, int pos) {
	insertR(primero, x, pos);
	tam++;
}

template<typename T>
bool List<T>::remove(int pos, T & x)
{
	link p = primero;
	link v = NULL;
	if (p == NULL || pos < 0 || pos >= tam)
		return false;
	else {
		while (pos != 0 && p->siguiente) {
			p = p->siguiente;
			if (pos == 1) v = p;
			pos--;
		}
		v->siguiente = p->siguiente;
		x = p->elemento;
		delete p;
		return true;
	}
	return false;
}

template<typename T>
bool List<T>::pop(T & x)
{
	link p = primero;
	if (!p)
		return false;
	else {
		x = p->elemento;
		primero = p->siguiente;
		delete p;
		return true;
	}
}

template<typename T>
bool List<T>::pop_back(T & x)
{
	link p = primero;
	link c = p;
	if (!p)
		return false;
	else {
		while (p->siguiente) {
			c = p;
			p = p->siguiente;
		}
		c->siguiente = p->siguiente;
		x = p->elemento;
		delete p;
		return true;
	}
}

template<typename T>
bool List<T>::get(int pos, T & element)
{
	link p = primero;
	if (p == NULL || pos < 0 || pos >= tam)
		return false;
	else {
		while (pos != 0 && p->siguiente) {
			p = p->siguiente;
			pos--;
		}
		element = p->elemento;
		return true;
	}
	return false;
}

template<typename T>
bool List<T>::get_front(T & element)
{
	if (!primero)
		return false;
	else
	{
		element = primero;
		return true;
	}
}

template<typename T>
bool List<T>::get_back(T & element)
{
	if (!primero)
		return false;
	else
	{
		link p = primero;
		while (p->siguiente)
		{
			p = p->siguiente;
		}
		element = p;
		return true;
	}
}

template<typename T>
void List<T>::print() {
	cout << nombreLista << " = [";
	if (primero) {
		link p = primero;
		cout << p->elemento;
		p = p->siguiente;
		while (p) {
			cout << ", " << p->elemento;
			p = p->siguiente;
		}
	}
	cout << "]";
}

template<typename T>
int List<T>::len() {
	return tam;
}

template<typename T>
List<T>::~List() {
	link p;
	while (primero) {
		// Borrra todos los elementos en la
		// lista.
		p = primero->siguiente;
		delete primero;
		primero = p;
	}
}
#endif // !SimpleList_h