#include "string.h"

int strings::count{ 0 };

strings::strings(const char* str_p, int size_p) : str{ new char[size_p] }, size{ size_p }
{
	count++;
	if (str_p)
	{
		strcpy_s(str, strlen(str_p) + 1, str_p);
	}
}

void strings:: set_str(const char* str_p)
{
	int size_p = strlen(str_p) + 1;

	delete[] str;

	str = new char[size_p];

	strcpy_s(str, size_p, str_p);
	size = size_p;
}

