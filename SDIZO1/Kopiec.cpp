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
