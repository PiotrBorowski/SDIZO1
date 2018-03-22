// SDIZO1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Tablica.h"
#include "Kopiec.h"
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>

using namespace std;

typedef std::chrono::high_resolution_clock Clock;
chrono::time_point<chrono::steady_clock> t1, t2;

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
				table_test();
				break;
			case 3:
				heap_test();
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
			int32_t value;
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
				ofstream outputFile(outputFileName);
				ifstream inputFile(inputFileName);

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
			cout << "3. Dodaj w losowe miejsce\n";
			cout << "4. Usun z poczatku\n";
			cout << "5. Usun z konca\n";
			cout << "6. Usun z wybranego miejsca\n";
			cout << "7. Znajdz wartosc\n";
			cout << "8. Wyswietl\n";
			cout << "0. Wyjscie\n";

			cout << "\n---------------------------------------------------------------------------------------------";
			cout << "\nWybierz: ";
			cin >> choose;
			try {
				switch (choose)
				{
				case 1:
					for (int i = 0; i < loops; ++i)
					{
						inputFile >> value;
						//mierzenie czasu start
						t1 = Clock::now();
						list.push_front(value);
						t2 = Clock::now();
						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
						//outputFile << CZAS!
					}
					break;

				case 2:
					for (int i = 0; i < loops; ++i)
					{
						inputFile >> value;

						//mierzenie czasu start
						t1 = Clock::now();
						list.push_back(value);
						t2 = Clock::now();

						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 3:
					for (int i = 0; i < loops; ++i)
					{
						inputFile >> value;

						//mierzenie czasu start
						t1 = Clock::now();
						list.insert(value, rand() % (i + 1));
						t2 = Clock::now();
						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 4:
					for (int i = 0; i < loops; ++i)
					{
						//mierzenie czasu start
						t1 = Clock::now();
						list.pop_front();
						t2 = Clock::now();

						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 5:
					for (int i = 0; i < loops; ++i)
					{

						//mierzenie czasu start
						t1 = Clock::now();
						list.pop_back();
						t2 = Clock::now();

						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 6:
					for (int i = 0; i < loops; ++i)
					{

						//mierzenie czasu start
						t1 = Clock::now();
						list.pop(rand() % (loops - i));
						t2 = Clock::now();
						// usuwanie z miejsca losowego miejsca
						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 7:
					for (int i = 0; i < loops; ++i)
					{

						//mierzenie czasu start
						t1 = Clock::now();
						list.find(rand() % INT32_MAX);
						t2 = Clock::now();
						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 8:
					list.print(cout);
					break;
				}
			}
				catch(IndexOutOfRangeException)
				{
					cout << "wykroczono poza zakres";
				}

			outputFile.flush();
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
			cout << "0. Wyjscie\n";

			cout << "\n---------------------------------------------------------------------------------------------";
			cout << "\nWybierz: ";
			cin >> choose;

			try {
				switch (choose)
				{
				case 1:
					cout << "\nPodaj wartosc do dodania na poczatek: ";
					cin >> value;
					t1 = Clock::now();
					list.push_front(value);
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 2:
					cout << "\nPodaj wartosc do dodania na koniec: ";
					cin >> value;
					t1 = Clock::now();
					list.push_back(value);
					t2 = Clock::now();

					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 3:
					cout << "\nPodaj wartosc do dodania w danym miejscu: ";
					cin >> value;
					cout << "\nPodaj indeks w ktorym ma zostac umieszczona wartosc: ";
					cin >> index;
					t1 = Clock::now();
					list.insert(value, index);
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 4:
					cout << "\nUsuwanie elementu z poczatku";
					t1 = Clock::now();
					list.pop_front();
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 5:
					cout << "\nUsuwanie elementu z konca";
					t1 = Clock::now();
					list.pop_back();
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 6:
					cout << "\nPodaj indeks ktory ma zostac usuniety: ";
					cin >> index;
					t1 = Clock::now();
					list.pop(index);
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 7:
					cout << "\nPodaj wartosc do znalezienia: ";
					cin >> value;
					t1 = Clock::now();
					list.find(value);
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 8:
					list.print(cout);
					break;
				}
			}
			catch (IndexOutOfRangeException)
			{
				cout << "wykroczono poza zakres";
			}
		}
		while (choose != 0);
	}
}

void table_test()
{
	int choose;
	std::cout << "\n---------------------------------------------------------------------------------------------";
	std::cout << "\nTablica:\n";
	std::cout << "1. Testy z pliku\n";
	std::cout << "2. Testy reczne\n";
	std::cout << "\n---------------------------------------------------------------------------------------------";

	do
	{
		cout << "\nWybierz: ";
		cin >> choose;
	} while (choose != 1 && choose != 2);

	if (choose == 1)
	{

		string inputFileName;
		string outputFileName;
		int32_t value;
		Tablica table;

		cout <<
			"\n---------------------------------------------------------------------------------------------";
		cout << "\nTablica (testy z pliku):\n";
		cout << "\n---------------------------------------------------------------------------------------------";
		cout << "\nPodaj plik wejsciowy:";
		cin >> inputFileName;
		cout << "\nPodaj plik wyjsciowy:";
		cin >> outputFileName;





		do {
			ofstream outputFile(outputFileName);
			ifstream inputFile(inputFileName);

			if (inputFile.good())
				cout << "\nOtwarto plik wejsciowy\n";

			if (outputFile.good())
				cout << "\nOtwarto plik wyjsciowy\n";

			inputFile >> loops; // ilosc liczb w pliku


			cout <<
				"\n---------------------------------------------------------------------------------------------";
			cout << "\n/Tablica (test na pliku: " << inputFileName << " )\n";
			cout << "1. Dodaj na poczatek\n";
			cout << "2. Dodaj na koniec\n";
			cout << "3. Dodaj w wybrane miejsce\n";
			cout << "4. Usun z poczatku\n";
			cout << "5. Usun z konca\n";
			cout << "6. Usun z wybranego miejsca\n";
			cout << "7. Znajdz wartosc\n";
			cout << "8. Wyswietl\n";
			cout << "0. Wyjscie\n";

			cout << "\n---------------------------------------------------------------------------------------------";
			cout << "\nWybierz: ";
			cin >> choose;
			try {
				switch (choose)
				{
				case 1:
					for (int i = 0; i < loops; ++i)
					{
						inputFile >> value;
						//mierzenie czasu start
						t1 = Clock::now();
						table.push_front(value);
						t2 = Clock::now();
						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
						//outputFile << CZAS!
					}
					break;

				case 2:
					for (int i = 0; i < loops; ++i)
					{
						inputFile >> value;

						//mierzenie czasu start
						t1 = Clock::now();
						table.push_back(value);
						t2 = Clock::now();

						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 3:
					for (int i = 0; i < loops; ++i)
					{
						inputFile >> value;

						//mierzenie czasu start
						t1 = Clock::now();
						table.insert(value, rand() % (i + 1));
						t2 = Clock::now();
						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 4:
					for (int i = 0; i < loops; ++i)
					{
						//mierzenie czasu start
						t1 = Clock::now();
						table.pop_front();
						t2 = Clock::now();

						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 5:
					for (int i = 0; i < loops; ++i)
					{

						//mierzenie czasu start
						t1 = Clock::now();
						table.pop_back();
						t2 = Clock::now();

						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 6:
					for (int i = 0; i < loops; ++i)
					{

						//mierzenie czasu start
						t1 = Clock::now();
						table.pop(rand() % (loops - i));
						t2 = Clock::now();
						// usuwanie z miejsca losowego miejsca
						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 7:
					for (int i = 0; i < loops; ++i)
					{

						//mierzenie czasu start
						t1 = Clock::now();
						table.find(rand() % INT32_MAX);
						t2 = Clock::now();
						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 8:
					table.print(cout);
					break;
				}
			}
			catch (IndexOutOfRangeException)
			{
				cout << "wykroczono poza zakres";
			}
			outputFile.flush();
			inputFile.close();
			outputFile.close();

		} while (choose != 0);
	}
	else if (choose == 2)
	{
		Tablica table;
		int32_t value;
		int index;

		do
		{
			cout <<
				"\t\tMENU\n---------------------------------------------------------------------------------------------";
			cout << "\ntTablica (testy reczne):\n";
			cout << "1. Dodaj na poczatek\n";
			cout << "2. Dodaj na koniec\n";
			cout << "3. Dodaj w wybrane miejsce\n";
			cout << "4. Usun z poczatku\n";
			cout << "5. Usun z konca\n";
			cout << "6. Usun z wybranego miejsca\n";
			cout << "7. Znajdz wartosc\n";
			cout << "8. Wyswietl\n";
			cout << "0. Wyjscie\n";

			cout << "\n---------------------------------------------------------------------------------------------";
			cout << "\nWybierz: ";
			cin >> choose;

			try {
				switch (choose)
				{
				case 1:
					cout << "\nPodaj wartosc do dodania na poczatek: ";
					cin >> value;
					t1 = Clock::now();
					table.push_front(value);
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 2:
					cout << "\nPodaj wartosc do dodania na koniec: ";
					cin >> value;
					t1 = Clock::now();
					table.push_back(value);
					t2 = Clock::now();

					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 3:
					cout << "\nPodaj wartosc do dodania w danym miejscu: ";
					cin >> value;
					cout << "\nPodaj indeks w ktorym ma zostac umieszczona wartosc: ";
					cin >> index;
					t1 = Clock::now();
					table.insert(value, index);
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 4:
					cout << "\nUsuwanie elementu z poczatku";
					t1 = Clock::now();
					table.pop_front();
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 5:
					cout << "\nUsuwanie elementu z konca";
					t1 = Clock::now();
					table.pop_back();
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 6:
					cout << "\nPodaj indeks ktory ma zostac usuniety: ";
					cin >> index;
					t1 = Clock::now();
					table.pop(index);
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 7:
					cout << "\nPodaj wartosc do znalezienia: ";
					cin >> value;
					t1 = Clock::now();
					table.find(value);
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 8:
					table.print(cout);
					break;
				}
			}
			catch (IndexOutOfRangeException)
			{
				cout << "wykroczono poza zakres";
			}
		} while (choose != 0);
	}

}

void heap_test()
{

	int choose;
	std::cout << "\n---------------------------------------------------------------------------------------------";
	std::cout << "\nKopiec:\n";
	std::cout << "1. Testy z pliku\n";
	std::cout << "2. Testy reczne\n";
	std::cout << "\n---------------------------------------------------------------------------------------------";

	do
	{
		cout << "\nWybierz: ";
		cin >> choose;
	} while (choose != 1 && choose != 2);

	if (choose == 1)
	{

		string inputFileName;
		string outputFileName;
		int32_t value;
		Kopiec heap;

		cout <<
			"\n---------------------------------------------------------------------------------------------";
		cout << "\nKopiec (testy z pliku):\n";
		cout << "\n---------------------------------------------------------------------------------------------";
		cout << "\nPodaj plik wejsciowy:";
		cin >> inputFileName;
		cout << "\nPodaj plik wyjsciowy:";
		cin >> outputFileName;





		do {
			ofstream outputFile(outputFileName);
			ifstream inputFile(inputFileName);

			if (inputFile.good())
				cout << "\nOtwarto plik wejsciowy\n";

			if (outputFile.good())
				cout << "\nOtwarto plik wyjsciowy\n";

			inputFile >> loops; // ilosc liczb w pliku


			cout <<
				"\n---------------------------------------------------------------------------------------------";
			cout << "\nKopiec (test na pliku: " << inputFileName << " )\n";
			cout << "1. Dodaj\n";
			cout << "2. Usun\n";
			cout << "3. Sprawdz czy zawiera wartosc\n";
			cout << "4. Wyswietl\n";
			cout << "0. Wyjscie\n";

			cout << "\n---------------------------------------------------------------------------------------------";
			cout << "\nWybierz: ";
			cin >> choose;
			try {
				switch (choose)
				{
				case 1:
					for (int i = 0; i < loops; ++i)
					{
						inputFile >> value;
						//mierzenie czasu start
						t1 = Clock::now();
						heap.push(value);
						t2 = Clock::now();
						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
						//outputFile << CZAS!
					}
					break;


				case 2:
					for (int i = 0; i < loops; ++i)
					{
						//mierzenie czasu start
						t1 = Clock::now();
						heap.pop();
						t2 = Clock::now();

						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;


				case 3:
					for (int i = 0; i < loops; ++i)
					{

						//mierzenie czasu start
						t1 = Clock::now();
						heap.contains(rand() % INT32_MAX);
						t2 = Clock::now();
						//mierzenie czasu stop
						cout << "CZAS(ms): ";
						cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					}
					break;

				case 4:
					heap.print(cout);
					break;
				}
			}
			catch (IndexOutOfRangeException)
			{
				cout << "wykroczono poza zakres";
			}
			outputFile.flush();
			inputFile.close();
			outputFile.close();

		} while (choose != 0);
	}
	else if (choose == 2)
	{
		Kopiec heap;
		int32_t value;
		int index;

		do
		{
			cout <<
				"\t\tMENU\n---------------------------------------------------------------------------------------------";
			cout << "\nKopiec (testy reczne):\n";
			cout << "1. Dodaj\n";
			cout << "2. Usun\n";
			cout << "3. Sprawdz czy zawiera wartosc\n";
			cout << "4. Wyswietl\n";
			cout << "0. Wyjscie\n";

			cout << "\n---------------------------------------------------------------------------------------------";
			cout << "\nWybierz: ";
			cin >> choose;

			try {
				switch (choose)
				{
				case 1:
					cout << "\nPodaj wartosc do dodania na poczatek: ";
					cin >> value;
					t1 = Clock::now();
					heap.push(value);
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 2:
					cout << "\nUsuwanie elementu z poczatku";
					t1 = Clock::now();
					heap.pop();
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;

				case 3:
					cout << "\nPodaj wartosc do znalezienia: ";
					cin >> value;
					t1 = Clock::now();
					heap.contains(value);
					t2 = Clock::now();
					//mierzenie czasu stop
					cout << "CZAS(ms): ";
					cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count() << endl;
					break;
				case 4:
					heap.print(cout);
					break;
				}
			}
			catch (IndexOutOfRangeException)
			{
				cout << "wykroczono poza zakres";
			}
		} while (choose != 0);
	}
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