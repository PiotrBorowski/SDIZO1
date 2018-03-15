#include "stdafx.h"
#include "Lista.h"
#include "IndexOutOfRangeException.h"
#include <exception>


Element* Lista::get_element(int index)
{
	if (index >= size || index < 0)
		throw IndexOutOfRangeException(); //TODO EXCEPTION

	Element* element;
	if(index <= size/2)
	{
		element = head;
		for (int i = 0; i != index; ++i)
			element = element->next;
	}
	else
	{
		element = tail;
		for (int i = size - 1; i != index; --i)
			element = element->prev;
	}

	return element;
}

Lista::Lista()
{
	size = 0;
}


Lista::~Lista()
{
	while (head) pop_front();
}

void Lista::push_front(int value)
{
	Element* temp = new Element(value, nullptr, head);
	head = temp;
	++size;
	if (temp->next != nullptr)
		(temp->next)->prev = temp;
	else
		tail = temp;
}

void Lista::push_back(int value)
{
	Element* temp = new Element(value, tail, nullptr);
	tail = temp;
	++size;
	if (temp->prev != nullptr)
		(temp->prev)->next = temp;
	else
		head = temp;
}


// wstawia nowy dodatkowy element w dane miejsce i przesuwa element ktory byl na tym miejscu o jedna pozycje dalej
void Lista::insert(int32_t value, int index)
{
	Element* temp = get_element(index);

	if (temp == nullptr)
		throw IndexOutOfRangeException(); //TODO EXCEPTION

	Element* newElem = new Element(value, temp->prev, temp);
	(newElem->prev)->next = newElem;
	temp->prev = newElem;

	++size;
}

void Lista::pop_front()
{
	if (size == 0)
		return; //TODO: EXCEPTION

	Element* element = head;

	if(size == 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		head = element->next;
		(element->next)->prev = nullptr;
		delete element;
	}

	--size;
}

void Lista::pop_back()
{
	if (size == 0)
		return; //TODO: EXCEPTION

	Element* element = tail;

	if(size == 1)
	{
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		tail = element->prev;
		(element->prev)->next = nullptr;
		delete element;
	}

	--size;
}


void Lista::pop(int index)
{
	if (index >= size || index < 0)
		throw IndexOutOfRangeException(); //TODO EXCEPTION

	Element* element = get_element(index);

	if (element->prev != nullptr)
		(element->prev)->next = element->next;
	else
		head = element->next;

	if (element->next != nullptr)
		(element->next)->prev = element->prev;
	else
		tail = element->prev;

	delete element;
	--size;
}

int Lista::find(int32_t value)
{
	Element* elem = head;

	for (int i = 0; i < size; ++i)
	{
		if (elem->data == value)
			return i;

		elem = elem->next;
	}
	return NULL;
}

int32_t Lista::get(int index)
{
	if (index >= size || index < 0)
		throw IndexOutOfRangeException();

	Element* elem = head;

	for (int i = 0; i < index; ++i)
	{
		elem = elem->next;
	}
	return elem->data;
}

void Lista::print(std::ostream& out)
{
	out << "\nElementy listy:\n";
	Element* elem = head;
	for (int i = 0; i < size; ++i)
	{
		out << elem->data;
		elem = elem->next;
		out << "\n";
	}
	out << "\n";

}

