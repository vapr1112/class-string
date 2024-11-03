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

	void set_str_adress(char* adress_str, const char* entered_string)//меняет подстроку в строке на указанную подстроку
	{
		const char* ptr = "\0";//создается указатель на \0
		char symbol = adress_str[strlen(entered_string)];//сохраняется символ следующий после подстроки
		adress_str[strlen(entered_string)] = *(ptr);//строка обрезается до подстроки 

		strcpy_s(adress_str, strlen(entered_string) + 1, entered_string);//копируется в подстроку 1 подстрока 2
		adress_str[strlen(adress_str)] = symbol;//возвращается сохраненный символ на место \0
	}

	//перегрузка специальных операторов

	char operator[](int idx)const
	{
		assert(idx > 0 && idx < size && "\nнедопустимый индекс");//assert дает возможность отслеживать недопустимый индекс, взят из методички
		return str[idx];
	}

	char& operator[](int idx)
	{
		assert(idx > 0 && idx < size && "\nнедопустимый индекс");
		return str[idx];
	}

	char* operator[](const char* str_p)
	{
		char* idx{ strstr(str, str_p) };//ищется подстрока в строке, сохраняется указатель
		char* buf_str = new char[strlen(str_p) + 1];//создается буферная строка
		if (idx != 0)
		{
			buf_str = idx;//в буферную строку копируется указатель на подстроку
			return buf_str;//возвращается буферная строка
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
			char* buf_str = new char[size];//создается буферная строка, в которую копируется значение из str
			strcpy_s(buf_str, size, str);

			const char* ptr = "\0";//создается указатель на \0

			*(strchr(buf_str, symbol)) = *(ptr);// на месте переданного символа в буферной ставится \0

			int index = strlen(buf_str);//размер полученной буферной строки и есть индекс искомого символа

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

