#include "stdafx.h"
#include "IndexOutOfRangeException.h"


IndexOutOfRangeException::IndexOutOfRangeException()
{
}


IndexOutOfRangeException::~IndexOutOfRangeException()
{
}

std::ostream& operator<<(std::ostream& output, IndexOutOfRangeException ex)
{
	output << "\nIndexOutOfRangeException\n";
	return output;
}
