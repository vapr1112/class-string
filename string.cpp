#include "string.h"

int strings::count{ 0 };

strings::strings(const char* str_p, const int size_p) : str{ new char[size_p] }, size{ size_p }
{
	count++;
	if (str_p)
	{
		strcpy_s(str, strlen(str_p) + 1, str_p);
	}
}
//����������� �����������
strings::strings(const strings& str_p) : str{ new char[str_p.size] }, size{ str_p.size }
{
	count++;

	if (str_p.str)
	{
		strcpy_s(str, size, str_p.str);
	}
}

//����������� ��������
strings::strings(strings&& str_p) : str{ str_p.str }, size{ str_p.size }
{
	count++;
	str_p.str = nullptr;
	str_p.size = 0;
}

void strings:: set_size(const int size_p)
{
	size = size_p;

	delete[] str;
	str = new char[size];
}

void strings:: print() const
{
	puts(str);
	cout << "������ ������ " << size << "\n";
}

char strings:: operator[](const int idx)const
{
	//assert ���� ����������� ����������� ������������ ������, ���� �� ���������
	assert(idx > 0 && idx < size && "\n������������ ������");
	return str[idx];
}

char& strings:: operator[](const int idx)
{
	assert(idx > 0 && idx < size && "\n������������ ������");
	return str[idx];
}

char* strings:: operator[](const char* str_p)
{
	//������ ��������� � ������, ����������� ���������
	char* idx{ strstr(str, str_p) };
	//��������� �������� ������
	char* buf_str = new char[strlen(str_p) + 1];
	if (idx != 0)
	{
		//� �������� ������ ���������� ��������� �� ���������
		buf_str = idx;
		//������������ �������� ������
		return buf_str;
	}
}

const char* strings:: operator[](const char* str_p)const
{
	char* idx{ strstr(str, str_p) };
	char* buf_str = new char[strlen(str_p) + 1];
	if (idx != 0)
	{
		buf_str = idx;
		return buf_str;
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

void strings:: set_str_adress(char* adress_str, const char* entered_string)
{
	//��������� ��������� �� \0
	const char* ptr = "\0";
	char symbol = adress_str[strlen(entered_string)];//����������� ������ ��������� ����� ���������
	adress_str[strlen(entered_string)] = *(ptr);//������ ���������� �� ��������� 

	strcpy_s(adress_str, strlen(entered_string) + 1, entered_string);//���������� � ��������� 1 ��������� 2
	adress_str[strlen(adress_str)] = symbol;//������������ ����������� ������ �� ����� \0
}

int strings:: operator()(const char symbol)
{
	if (strchr(str, symbol) != 0)
	{
		//��������� �������� ������, � ������� ���������� �������� �� str
		char* buf_str = new char[size];
		strcpy_s(buf_str, size, str);

		//��������� ��������� �� \0
		const char* ptr = "\0";

		// �� ����� ����������� ������� � �������� �������� \0
		*(strchr(buf_str, symbol)) = *(ptr);

		//������ ���������� �������� ������ � ���� ������ �������� �������
		int index = strlen(buf_str);

		delete[] buf_str;

		return index;
	}

	return -1;
}