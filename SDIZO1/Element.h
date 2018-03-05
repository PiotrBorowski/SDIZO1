#pragma once
#include <cstdint>

class Element
{
	friend class Lista;

private:
	Element* prev;
	Element* next;
	int32_t data;

public:
	Element();
	Element(int32_t, Element*, Element*);
	~Element();
};

