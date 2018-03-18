// SDIZO1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Tablica.h"
#include "Kopiec.h"
#include <string>

using namespace std;
void printMenu();

void list_test();

string inputFile;
string outputFile;

int main()
{
	Lista lista;
	Tablica tablica;
	Kopiec kopiec;
	
	int choose;
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

	/*	kopiec.push(10);
		kopiec.push(11);
		kopiec.push(1);
		kopiec.push(2);
		kopiec.push(20);
		kopiec.print(cout);
		kopiec.push(1);
		kopiec.print(cout);

		cout << "\n";
		cout << kopiec.contains(19);*/
		
		do
		{
			printMenu();
			cout << "\nWybierz: ";
			cin >> choose;

			switch (choose)
			{
				case 1:
					list_test();
					break;
				case 2:
					
					break;
				case 3:
					break;
				default:
					cout << "\nPodaj poprawna cyfre: ";
					cin >> choose;
			}
		} while (choose != 0);

	}
	catch(IndexOutOfRangeException e)
	{
		cout << e;
		getchar();
	}

    return 0;
}

void printMenu()
{
	std::cout << "\t\tMENU\n---------------------------------------------------------------------------------------------";
	std::cout << "\nStrutkura:\n";
	std::cout << "1. Lista dwukierunkowa\n";
	std::cout << "2. Tablica\n";
	std::cout << "3. Kopiec\n";
	std::cout << "\n---------------------------------------------------------------------------------------------";
}

void list_test()
{
	int choose;
	std::cout << "\t\tMENU\n---------------------------------------------------------------------------------------------";
	std::cout << "\nLista dwukierunkowa:\n";
	std::cout << "1. Testy z pliku\n";
	std::cout << "2. Testy reczne\n";
	std::cout << "\n---------------------------------------------------------------------------------------------";

	do
	{
		cout << "\nWybierz: ";
		cin >> choose;
	} while (choose == 1 || choose == 2);

	if(choose == 1)
	{
		std::cout << "\t\tMENU\n---------------------------------------------------------------------------------------------";
		std::cout << "\nLista dwukierunkowa(testy z pliku):\n";
		std::cout << "\n---------------------------------------------------------------------------------------------";
		std::cout << "\nPodaj plik wejsciowy:";
		cin >> inputFile;
		std::cout << "\nPodaj plik wejsciowy:";
		cin >> outputFile;

		switch(choose)
		{
			//TODO
		}
	}
	else if(choose == 2)
	{
		std::cout << "\t\tMENU\n---------------------------------------------------------------------------------------------";
		std::cout << "\nLista dwukiernkowa (testy reczne):\n";
		std::cout << "1. Dodaj na poczatek\n";
		std::cout << "2. Dodaj na koniec\n";
		std::cout << "3. Dodaj w wybrane miejsce\n";
		std::cout << "4. Usun z poczatku\n";
		std::cout << "5. Usun z konca\n";
		std::cout << "6. Usun z wybranego miejsca\n";
		std::cout << "7. Znajdz wartosc\n";
		std::cout << "8. Wyswietl\n";

		std::cout << "\n---------------------------------------------------------------------------------------------";
		cout << "\nWybierz: ";
		cin >> choose;

		switch (choose)
		{
			//TODO
		}
	}
}

