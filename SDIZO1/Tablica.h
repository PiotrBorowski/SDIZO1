#pragma once
#include <cstdint>

class Tablica
{
private:
	int32_t* head;
	int size;

public:
	Tablica();
	Tablica(int32_t*, int);
	~Tablica();

	void push_front(int32_t);
	void push_back(int32_t);
	void insert(int32_t, int);
	void pop_front();
	void pop_back();
	void pop(int);
	void print();

};

