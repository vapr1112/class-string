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

	// ������� �����������, �o����� ������ � �������������� ��
	strings(const char* str_p, const int size_p); 
	//�����������, ��������� ������, ������� 80
	strings() : strings(nullptr, 80) {}; 
	//�����������, ��������� ������ �������, ��������� �������������
	strings(const int size_p) : strings(nullptr, size_p) {}; 
	//����������� �����������
	strings(const strings& str_p);
	//����������� ��������
	strings(strings&& str_p);
	explicit strings(const char* str_p) : strings(nullptr, strlen(str_p) + 1) {}

	void set_str(const char* str_p);
	void set_size(const int size_p);
	const char* get_str() const {return str}
	int get_size() const {return size;}
	void print() const;
	//���������� ���������� �������� ������
	static int show_count() {return count;}
	//������ ��������� � ������ �� ��������� ���������
	void set_str_adress(char* adress_str, const char* entered_string);
	//���������� ����������� ����������
	char operator[](const int idx)const;
	char& operator[](const int idx);
	char* operator[](const char* str_p);

	const char* operator[](const char* str_p)const;

	int operator()(const char symbol);

	operator int() const {return strlen(str) + 1;}

	~strings()
	{
		delete[] str;
		count--;
	}
};

