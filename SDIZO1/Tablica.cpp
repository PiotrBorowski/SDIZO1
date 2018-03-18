#include "stdafx.h"
#include "Tablica.h"


Tablica::Tablica()
{
}

Tablica::Tablica(int32_t* head, int32_t size)
{
	this->head = head;
	this->size = size;
}


Tablica::~Tablica()
{
	delete[] head;
}

void Tablica::push_front(int32_t value)
{
	if(size == 0)
	{
		head = new int32_t[1];
		*head = value;
		++size;
	}
	else
	{
		int32_t* temp = new int32_t[size + 1];
		*temp = value;
		memcpy(++temp, head, size * sizeof(int32_t));
		head = temp;
		++size;
	}
}

void Tablica::push_back(int32_t value)
{
	if(size == 0)
	{
		head = new int32_t[1];
		*head = value;
		++size;
	}
	else
	{
		int32_t* temp = new int32_t[size + 1];
		*(temp + size) = value;
		memcpy(temp, head, size * sizeof(int32_t));
		head = temp;
		++size;
	}
}

// wstawia nowy dodatkowy element w dane miejsce i przesuwa element ktory byl na tym miejscu o jedna pozycje dalej
void Tablica::insert(int32_t value, int index)
{
	if (index < 0 || index >= size)
		throw IndexOutOfRangeException();

	int32_t* temp = new int32_t[size + 1];
	memcpy(temp, head, index * sizeof(int32_t));
	*(temp + index) = value;
	memcpy(temp + index + 1, head + index, (size - index) * sizeof(int32_t));
	head = temp;
	++size;
}

void Tablica::pop_front()
{
	pop(0); //sprawdzic ilosc instrukcji
}

void Tablica::pop_back()
{
	pop(size - 1); //to samo co ^^^
}

//usuwa element o indeksie index
void Tablica::pop(int index)
{
	if (size == 0)
		return;
	if (index < 0 || index >= size)
		throw IndexOutOfRangeException();

	int32_t* temp = new int32_t[size - 1];
	memcpy(temp, head, index * sizeof(int32_t));
	memcpy(temp + index, head + index + 1, (--size - index) * sizeof(int32_t)); // kopiowanie i zmienejszanie size o 1
	head = temp;
}

void Tablica::swap(int32_t value, int index)
{
	if (index < 0 || index >= size)
		throw IndexOutOfRangeException();

	int32_t* elem = head;

	for (int i = 0; i < index; ++i)
	{
		++elem;
	}
	*elem = value;
}

int Tablica::find(int32_t value)
{
	for (int i = 0; i < size; ++i)
	{
		if (*(head + i) == value)
			return i;
	}
	return NULL;
}

int32_t Tablica::get(int index)
{
	if (index < 0 || index >=size)
		throw IndexOutOfRangeException();

	int32_t* elem = head;

	for (int i = 0; i < index ; ++i)
	{
		++elem;
	}
	return *elem;
}

void Tablica::print(std::ostream& out)
{
	out << "\nElementy tablicy:\n";
	for (int i = 0; i < size; ++i)
	{
		out << *(head + i);
		out << "\n";
	}
	out << "\n";
}
