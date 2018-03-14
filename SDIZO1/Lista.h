#pragma once
#include <cstdint>
#include "Element.h"
#include <ostream>

class Lista
{
private:
	Element* head;
	Element* tail;
	int size;

	Element* get_element(int);

public:
	Lista();
	~Lista();

	void push_front(int);
	void push_back(int);
	void insert(int32_t, int);
	void pop_front();
	void pop_back();
	void pop(int);
	int find(int32_t);
	int32_t get(int);
	void print(std::ostream&);
	
};

