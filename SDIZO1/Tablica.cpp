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
}

void Tablica::push_front(int32_t value)
{
	if(size == 0)
	{
		head = new int32_t[0];
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
		head = new int32_t[0];
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
