#pragma once
#include <cstdint>
#include "Element.h"

class Lista
{
private:
	Element* head;
	Element* tail;
	int size;

	Element* find(int);

public:
	Lista();
	~Lista();

	void push_front(int);
	void push_back(int);
	void insert(int32_t, int);
	void pop_front();
	void pop_back();
	void pop(int);
	void print();
};

