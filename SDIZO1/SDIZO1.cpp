// SDIZO1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;
int main()
{
	Lista lista;
	try
	{
		//lista.push_front(10);
		//lista.push_back(2);
		//lista.push_front(11);
		lista.push_back(11);
		cout << lista.pop_front();
		lista.insert(32, 100);
		cout << lista.pop(10);
		getchar();
	}
	catch(IndexOutOfRangeException e)
	{
		cout << e;
		getchar();
	}
    return 0;
}

