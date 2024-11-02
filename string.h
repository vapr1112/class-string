#pragma once

#include <iostream>
#define SIZE 400
#define SIZE_2 40

using namespace std;

class strings
{
private:
	char* str;
	int size; //длина массива
	static int count;//счетчик объектов

public:

	strings(const char* str_p, const int size_p); // главный конструктор, сoздает строку и инициализирует ее

	strings() : strings(nullptr, 80) {}; //конструктор, создающий строку, длинной 80

	strings(const int size_p) : strings(nullptr, size_p) {}; //конструктор, создающий строку длинной, указанной пользователем

	strings(const strings& str_p);//конструктор копирования
	
	strings(strings&& str_p);//конструктор переноса

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

