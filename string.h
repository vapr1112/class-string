#pragma once

#include <iostream>

using namespace std;

#define SIZE 2000

class strings
{
private:
	char* str;
	int size; //длина массива
	static int count;

public:

	strings(const char* str_p, int size_p); // главный конструктор, сщздает строку и инициализирует ее


	strings() : strings(nullptr, 80) {}; //конструктор, создающий строку, длинной 80

	strings(int size_p) : strings(nullptr, size_p) {}; //конструктор, создающий строку длинной, указанной пользователем
	
	void set_str(const char* str_p);

	void set_size(int size_p)
	{
		size = size_p;

		delete[] str;
		str = new char[size];
	}

	const char* get_str() const
	{
		return str;
	}

	int get_size() const
	{
		return size;
	}

	void print() const
	{
		puts(str);
		cout << "размер строки " << size << "\n";
	}

	static int show_count() //возвращает количество обЬектов класса
	{
		return count;
	}

	~strings()
	{
		delete[] str;
		count--;
	}
};

