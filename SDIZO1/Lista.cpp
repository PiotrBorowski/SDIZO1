#include "stdafx.h"
#include "Lista.h"


Element* Lista::find(int index)
{
	if (index >= size || index < 0)
		return nullptr;

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
		return; //TODO EXCEPTION

	Element* newElem = new Element(value, temp->prev, temp);
	(newElem->prev)->next = newElem;
	temp->prev = newElem;

	++size;
}

int32_t Lista::pop_front()
{
	return pop(0);
}

int32_t Lista::pop_back()
{	
	return pop(size - 1);
}

int32_t Lista::pop(int index)
{
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
	return val;
}
