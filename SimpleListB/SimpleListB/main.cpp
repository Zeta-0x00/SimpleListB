// SimpleListB.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "pch.h"
#include "SimpleList.h"
#include "SimpleListB.h"

int main()
{
	List<int> lm("Lista1");
	int x = 0;
	int &k = x;
	lm.push_front(30);
	lm.push_front(20);
	lm.push_front(10);
	lm.push_back(40);
	lm.insertarR(5, 0);
	lm.insertarR(8, 1);
	lm.insertarR(15, 5);
	lm.insertarR(50, 99);
	lm.insertarR(999, 1);
	lm.print();

	lm.pop(k);
	lm.pop_back(k);
	cout << x;
	lm.print();
	lm.get(5, k);
	cout << x;
	std::cout << "\n";
	List<string> la("Personas");
	la.push_back("ana");
	la.push_back("juan");
	la.print();
	std::cout << "\n";

	SimpleListB<int> lb("Pares");
	lb.push_front(62);
	lb.push_front(60);
	lb.push_front(58);
	lb.push_front(56);
	lb.push_front(54);
	lb.push_front(52);
	lb.push_front(50);
	lb.push_front(48);
	lb.push_front(46);
	lb.push_front(44);
	lb.push_front(42);
	lb.push_front(40);
	lb.push_front(38);
	lb.push_front(36);
	lb.push_front(34);
	lb.push_front(32);
	lb.push_front(30);
	lb.push_front(28);
	lb.push_front(26);
	lb.push_front(24);
	lb.push_front(22);
	lb.push_front(20);
	lb.push_front(18);
	lb.push_front(16);
	lb.push_front(14);
	lb.push_front(12);
	lb.push_front(10);
	lb.push_front(8);
	lb.push_front(6);
	lb.push_front(4);
	lb.push_front(2);
	lb.push_front(0);
	//int cont = 60;
	//while (cont > 0) {
		//lb.push_front(cont);
		//cont = cont - 2;
	//}
	/*lb.print();
	lb.insert(0, 3);*/
	lb.print();
	system("pause");

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
