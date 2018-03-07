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
	int32_t pop_front();
	int32_t pop_back();
	int32_t pop(int);
};

