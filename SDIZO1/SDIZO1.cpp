// SDIZO1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Tablica.h"


using namespace std;
int main()
{
	Lista lista;
	Tablica tablica;

	try
	{
		lista.push_front(10);
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
		cout << tablica.find(11);
		getchar();
	}
	catch(IndexOutOfRangeException e)
	{
		cout << e;
		getchar();
	}
    return 0;
}

