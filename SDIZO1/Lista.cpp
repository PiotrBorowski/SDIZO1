#include "stdafx.h"
#include "Lista.h"
#include "IndexOutOfRangeException.h"
#include <exception>


Element* Lista::find(int index)
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

void Lista::insert(int32_t value, int index)
{
	Element* temp = find(index);

	if (temp == nullptr)
		throw IndexOutOfRangeException(); //TODO EXCEPTION

	Element* newElem = new Element(value, temp->prev, temp);
	(newElem->prev)->next = newElem;
	temp->prev = newElem;

	++size;
}

int32_t Lista::pop_front()
{
	if (size == 0)
		return NULL; //TODO: EXCEPTION

	Element* element = head;
	int32_t val = element->data;

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
	return val;

}

int32_t Lista::pop_back()
{
	if (size == 0)
		return NULL; //TODO: EXCEPTION

	Element* element = tail;
	int32_t val = element->data;

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
	return val;
}


int32_t Lista::pop(int index)
{
	if (index >= size || index < 0)
		throw IndexOutOfRangeException(); //TODO EXCEPTION

	Element* element = find(index);
	int32_t val = element->data;

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
	return val;
}
