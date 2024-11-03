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
	int size; //����� �������
	static int count;//������� ��������

public:

	strings(const char* str_p, const int size_p); // ������� �����������, �o����� ������ � �������������� ��

	strings() : strings(nullptr, 80) {}; //�����������, ��������� ������, ������� 80

	strings(const int size_p) : strings(nullptr, size_p) {}; //�����������, ��������� ������ �������, ��������� �������������

	strings(const strings& str_p);//����������� �����������
	
	strings(strings&& str_p);//����������� ��������

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
		cout << "������ ������ " << size << "\n";
	}

	static int show_count() //���������� ���������� �������� ������
	{
		return count;
	}

	void set_str_adress(char* adress_str, const char* entered_string)//������ ��������� � ������ �� ��������� ���������
	{
		const char* ptr = "\0";//��������� ��������� �� \0
		char symbol = adress_str[strlen(entered_string)];//����������� ������ ��������� ����� ���������
		adress_str[strlen(entered_string)] = *(ptr);//������ ���������� �� ��������� 

		strcpy_s(adress_str, strlen(entered_string) + 1, entered_string);//���������� � ��������� 1 ��������� 2
		adress_str[strlen(adress_str)] = symbol;//������������ ����������� ������ �� ����� \0
	}

	//���������� ����������� ����������

	char operator[](int idx)const
	{
		assert(idx > 0 && idx < size && "\n������������ ������");//assert ���� ����������� ����������� ������������ ������, ���� �� ���������
		return str[idx];
	}

	char& operator[](int idx)
	{
		assert(idx > 0 && idx < size && "\n������������ ������");
		return str[idx];
	}

	char* operator[](const char* str_p)
	{
		char* idx{ strstr(str, str_p) };//������ ��������� � ������, ����������� ���������
		char* buf_str = new char[strlen(str_p) + 1];//��������� �������� ������
		if (idx != 0)
		{
			buf_str = idx;//� �������� ������ ���������� ��������� �� ���������
			return buf_str;//������������ �������� ������
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
			char* buf_str = new char[size];//��������� �������� ������, � ������� ���������� �������� �� str
			strcpy_s(buf_str, size, str);

			const char* ptr = "\0";//��������� ��������� �� \0

			*(strchr(buf_str, symbol)) = *(ptr);// �� ����� ����������� ������� � �������� �������� \0

			int index = strlen(buf_str);//������ ���������� �������� ������ � ���� ������ �������� �������

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

