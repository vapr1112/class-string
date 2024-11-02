#pragma once

#include <iostream>
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

	~strings()
	{
		delete[] str;
		count--;
	}
};

