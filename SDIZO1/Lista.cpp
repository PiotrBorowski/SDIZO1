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
	
}
