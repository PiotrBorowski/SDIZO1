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
		table->swap(table->get(parent), index);
		table->swap(temp, parent);
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
		
		//naprawianie w dol
		//jezeli ktorys z synow jest wiekszy lub rowny value to zamieniamy miejscami wiekszego syna z rodzicem
		int32_t temp = table->get(index);
		table->swap(table->get(child), index);
		table->swap(temp, child);
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

	if(leftChild < size)
		if (table->get(leftChild) >= value)
			if (contains(value, leftChild))
				return true;

	if(rightChild < size)
		if (table->get(rightChild) >= value)
			if (contains(value, rightChild))
				return true;



	return false;

}

void Kopiec::print(std::ostream& out)
{

	int i = 2;
	int j;
	int l = 1;

	out << "\nKopiec:\n";
	if (size == 0) return;



	for (int k = 0; k < 8; ++k)
	{
		out << "\t";
	}
	out << table->get(0) << "\n";
	

	while(i < size)
	{
		j = i - 1;
		i *= 2;
	

		for (int k = 0; k < 8 - l; ++k)
		{
			out << "\t";
		}
		l *= 2;

		while( j < i - 1)
		{
			try
			{
				out << table->get(j) << "\t";
				++j;
			}
			catch (IndexOutOfRangeException)
			{
				return;
			}
				
		}
		out << "\n";

	}
}
