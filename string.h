#pragma once

#include <iostream>
#include <cassert>
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

	// главный конструктор, сoздает строку и инициализирует ее
	strings(const char* str_p, const int size_p); 

	//конструктор, создающий строку, длинной 80
	strings() : strings(nullptr, 80) {}; 

	//конструктор, создающий строку длинной, указанной пользователем
	strings(const int size_p) : strings(nullptr, size_p) {}; 

	//конструктор копирования
	strings(const strings& str_p);
	
	//конструктор переноса
	strings(strings&& str_p);

	explicit strings(const char* str_p) : strings(nullptr, strlen(str_p) + 1) {}

	void set_str(const char* str_p);

	void set_size(const int size_p)
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

	//возвращает количество обЬектов класса
	static int show_count() 
	{
		return count;
	}

	//меняет подстроку в строке на указанную подстроку
	void set_str_adress(char* adress_str, const char* entered_string);

	//перегрузка специальных операторов

	char operator[](const int idx)const
	{
		//assert дает возможность отслеживать недопустимый индекс, взят из методички
		assert(idx > 0 && idx < size && "\nнедопустимый индекс");
		return str[idx];
	}

	char& operator[](const int idx)
	{
		assert(idx > 0 && idx < size && "\nнедопустимый индекс");
		return str[idx];
	}

	char* operator[](const char* str_p)
	{
		//ищется подстрока в строке, сохраняется указатель
		char* idx{ strstr(str, str_p) };
		//создается буферная строка
		char* buf_str = new char[strlen(str_p) + 1];
		if (idx != 0)
		{
			//в буферную строку копируется указатель на подстроку
			buf_str = idx;
			//возвращается буферная строка
			return buf_str;
		}
	}

	const char* operator[](const char* str_p)const
	{
		char* idx{ strstr(str, str_p) };
		char* buf_str = new char[strlen(str_p) + 1];
		if (idx != 0)
		{
			buf_str = idx;
			return buf_str;
		}
	}

	int operator()(const char symbol) 
	{
		if (strchr(str, symbol) != 0)
		{
			//создается буферная строка, в которую копируется значение из str
			char* buf_str = new char[size];
			strcpy_s(buf_str, size, str);

			//создается указатель на \0
			const char* ptr = "\0";

			// на месте переданного символа в буферной ставится \0
			*(strchr(buf_str, symbol)) = *(ptr);

			//размер полученной буферной строки и есть индекс искомого символа
			int index = strlen(buf_str);

			delete[] buf_str;

			return index;
		}

		return -1;
	}

	operator int() const
	{
		return strlen(str) + 1;
	}

	~strings()
	{
		delete[] str;
		count--;
	}
};

