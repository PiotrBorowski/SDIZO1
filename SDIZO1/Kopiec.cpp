#include "stdafx.h"
#include "Kopiec.h"


Kopiec::Kopiec()
{
	table = new Tablica();
	size = 0;
}


Kopiec::~Kopiec()
{
	delete table;
}

void Kopiec::push(int32_t value)
{
	int index = size; //ostatni element nowej dluzszej tablicy
	++size;
	int parent = (index - 1) / 2;
	table->push_back(value);

	//naprawianie w góre
	while(index > 0 && table->get(parent) < value)
	{
		int32_t temp = table->get(index);
		table->insert(table->get(parent), index);
		table->insert(temp, parent);
		index = parent;
		parent = (index - 1) / 2;
	}
}

void Kopiec::pop()
{
	if (size == 0) return;
	--size;
	int32_t value = table->get(size); //ostatni element starej tablicy
	int index = 0;
	int child = 1; // lewy syn

	while(child < size)
	{
		if (child + 1 < size && table->get(child + 1) > table->get(child))
			++child;
		if(value > table->get(child)) break;
		
		//jezeli ktorys z synow jest wiekszy lub rowny value to zamieniamy miejscami wiekszego syna z rodzicem
		int32_t temp = table->get(index);
		table->insert(table->get(child), index);
		table->insert(temp, child);
		index = child;
		child = 2 * child + 1; //nastepny lewy syn
	}
}

bool Kopiec::contains(int32_t value, int index)
{
	if (index < 0 || index >= size)
		return false;

	if (table->get(index) == value)
		return true;
	
	int leftChild = 2 * index + 1;
	int rightChild = leftChild+1;

	if (table->get(leftChild) >= value) 
		if(contains(value, leftChild) == true)
			return true;
	
	if (table->get(rightChild) >= value)
		if (contains(value, rightChild) == true)
			return true;

	return false;


}
