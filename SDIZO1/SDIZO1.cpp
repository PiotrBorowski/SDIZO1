// SDIZO1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Tablica.h"
#include "Kopiec.h"
#include <string>
#include <fstream>
#include <ctime>

using namespace std;
void printMenu();

void list_test();
void table_test();
void heap_test();
void generate_file();




int loops;

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
			case 4:
				generate_file();
				break;
			}
		}
		while (choose != 0);
	}
	catch (IndexOutOfRangeException e)
	{
		cout << e;
		getchar();
	}

	return 0;
}

void printMenu()
{
	std::cout << "\n---------------------------------------------------------------------------------------------";
	std::cout << "\nStrutkura:\n";
	std::cout << "1. Lista dwukierunkowa\n";
	std::cout << "2. Tablica\n";
	std::cout << "3. Kopiec\n";
	std::cout << "4. Utworz plik z danymi\n";
	std::cout << "0. Wyjscie\n";
	std::cout << "\n---------------------------------------------------------------------------------------------";
}


void list_test()
{
	int choose;
	std::cout << "\n---------------------------------------------------------------------------------------------";
	std::cout << "\nLista dwukierunkowa:\n";
	std::cout << "1. Testy z pliku\n";
	std::cout << "2. Testy reczne\n";
	std::cout << "\n---------------------------------------------------------------------------------------------";

	do
	{
		cout << "\nWybierz: ";
		cin >> choose;
	}
	while (choose != 1 && choose != 2);

	if (choose == 1)
	{
		
			string inputFileName;
			string outputFileName;
			ifstream inputFile;
			ofstream outputFile;
			int32_t data;
			Lista list;

			cout <<
				"\n---------------------------------------------------------------------------------------------";
			cout << "\nLista dwukierunkowa(testy z pliku):\n";
			cout << "\n---------------------------------------------------------------------------------------------";
			cout << "\nPodaj plik wejsciowy:";
			cin >> inputFileName;
			cout << "\nPodaj plik wyjsciowy:";
			cin >> outputFileName;


		


			do {
				inputFile.open(inputFileName);
				outputFile.open(outputFileName);

				if (inputFile.good())
					cout << "\nOtwarto plik wejsciowy\n";

				if (outputFile.good())
					cout << "\nOtwarto plik wyjsciowy\n";

				inputFile >> loops; // ilosc liczb w pliku


			cout <<
				"\n---------------------------------------------------------------------------------------------";
			cout << "\nLista dwukiernkowa (test na pliku: " << inputFileName << " )\n";
			cout << "1. Dodaj na poczatek\n";
			cout << "2. Dodaj na koniec\n";
			cout << "3. Dodaj w wybrane miejsce\n";
			cout << "4. Usun z poczatku\n";
			cout << "5. Usun z konca\n";
			cout << "6. Usun z wybranego miejsca\n";
			cout << "7. Znajdz wartosc\n";
			cout << "8. Wyswietl\n";

			cout << "\n---------------------------------------------------------------------------------------------";
			cout << "\nWybierz: ";
			cin >> choose;

			switch (choose)
			{
			case 1:
				for(int i = 0; i < loops; ++i)
				{
					inputFile >> data;

					//mierzenie czasu start
					list.push_front(data);
					//mierzenie czasu stop
					//outputFile << CZAS!
				}
				break;

			case 2:
				for (int i = 0; i < loops; ++i)
				{
					inputFile >> data;

					//mierzenie czasu start
					list.push_back(data);
					//mierzenie czasu stop
					//outputFile << CZAS!
				}
				break;

			case 3:
				for (int i = 0; i < loops; ++i)
				{
					inputFile >> data;

					//mierzenie czasu start
					list.insert(data, rand() % loops);
					//mierzenie czasu stop
					//outputFile << CZAS!
				}
				break;

			case 4:
				for (int i = 0; i < loops; ++i)
				{
					//mierzenie czasu start
					list.pop_front();
					//mierzenie czasu stop
					//outputFile << CZAS!
				}
				break;

			case 5:
				for (int i = 0; i < loops; ++i)
				{

					//mierzenie czasu start
					list.pop_back();
					//mierzenie czasu stop
					//outputFile << CZAS!
				}
				break;

			case 6:
				for (int i = 0; i < loops; ++i)
				{

					//mierzenie czasu start
					list.pop(rand() % (loops - i) ); // usuwanie z miejsca losowego miejsca
					//mierzenie czasu stop
					//outputFile << CZAS!
				}
				break;
			
			case 7:
				for (int i = 0; i < loops; ++i)
				{
		
					//mierzenie czasu start
					list.find(rand() % INT32_MAX);
					//mierzenie czasu stop
					//outputFile << CZAS!
				}
				break;

			case 8:
				list.print(cout);
				break;
			}

			inputFile.close();
			outputFile.close();
		} while (choose != 0);
	}
	else if (choose == 2)
	{
		Lista list;
		int32_t value;
		int index;

		do
		{
			cout <<
				"\t\tMENU\n---------------------------------------------------------------------------------------------";
			cout << "\nLista dwukiernkowa (testy reczne):\n";
			cout << "1. Dodaj na poczatek\n";
			cout << "2. Dodaj na koniec\n";
			cout << "3. Dodaj w wybrane miejsce\n";
			cout << "4. Usun z poczatku\n";
			cout << "5. Usun z konca\n";
			cout << "6. Usun z wybranego miejsca\n";
			cout << "7. Znajdz wartosc\n";
			cout << "8. Wyswietl\n";
		
			cout << "\n---------------------------------------------------------------------------------------------";
			cout << "\nWybierz: ";
			cin >> choose;

	
		
			//TODO: MIERZENIE CZASU
			switch (choose)
			{
			case 1:
				cout << "\nPodaj wartosc do dodania na poczatek: ";
				cin >> value;
				list.push_front(value);
				break;
			case 2:
				cout << "\nPodaj wartosc do dodania na koniec: ";
				cin >> value;
				list.push_back(value);
				break;
			case 3:
				cout << "\nPodaj wartosc do dodania w danym miejscu: ";
				cin >> value;
				cout << "\nPodaj indeks w ktorym ma zostac umieszczona wartosc: ";
				cin >> index;
				list.insert(value, index);
				break;
			case 4:
				cout << "\nUsuwanie elementu z poczatku";
				list.pop_front();
				break;
			case 5:
				cout << "\nUsuwanie elementu z konca";
				list.pop_back();
				break;
			case 6:
				cout << "\nPodaj indeks ktory ma zostac usuniety: ";
				cin >> index;
				list.pop(index);
				break;
			case 7:
				cout << "\nPodaj wartosc do znalezienia: ";
				cin >> value;
				list.find(value);
				break;
			case 8:
				list.print(cout);
				break;
			}
		}
		while (choose != 0);
	}
}

void table_test()
{
	

}

void heap_test()
{
	
}

void generate_file()
{
	string outputFileName;
	ofstream outputFile;
	int count;
	int32_t number;

	cout << "\nPodaj nazwe pliku: ";
	cin >> outputFileName;
	cout << "\nPodaj ilosc liczb do wylosowania: ";
	cin >> count;

	outputFile.open(outputFileName);

	srand(time(NULL));

	outputFile << count << endl;
	for (int i = 0; i < count; ++i)
	{
		number = rand();
		outputFile << number << endl;
	}
	outputFile.close();
}