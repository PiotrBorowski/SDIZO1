#pragma once
#include "Tablica.h"

class Kopiec
{
private:
	Tablica* table;
	int size;
	

public:
	Kopiec();
	~Kopiec();

	void push(int32_t);
	void pop();
	bool contains(int32_t);
	void print(std::ostream&);

};

