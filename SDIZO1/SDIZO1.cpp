// SDIZO1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Tablica.h"
#include "Kopiec.h"


using namespace std;
int main()
{
	Lista lista;
	Tablica tablica;
	Kopiec kopiec;

	try
	{
		/*lista.push_front(10);
		lista.push_back(13);
		lista.print(cout);
		cout << lista.find(10) << endl;
		cout << lista.find(13) << endl;

		tablica.push_front(10);
		tablica.pop_back();
		tablica.push_back(11);
		tablica.print(cout);
		tablica.insert(13, 1);
		tablica.print(cout);
		cout << tablica.find(11);*/

		kopiec.push(10);
		kopiec.push(11);
		kopiec.push(1);
		kopiec.push(2);
		kopiec.push(20);
		kopiec.print(cout);
		kopiec.push(1);
		kopiec.print(cout);

		cout << "\n";
		cout << kopiec.contains(19);


		getchar();
	}
	catch(IndexOutOfRangeException e)
	{
		cout << e;
		getchar();
	}
    return 0;
}

