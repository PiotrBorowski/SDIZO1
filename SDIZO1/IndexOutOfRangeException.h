#pragma once
#include <ostream>

class IndexOutOfRangeException
{
public:
	IndexOutOfRangeException();
	~IndexOutOfRangeException();
	friend std::ostream& operator<<(std::ostream& output, IndexOutOfRangeException ex);
};