#include "stdafx.h"
#include "Element.h"


Element::Element()
{
}

Element::Element(int32_t value, Element* prev, Element* next)
{
	this->prev = prev;
	this->next = next;
	this->data = value;
}


Element::~Element()
{
}
