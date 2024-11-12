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