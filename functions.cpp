#include "Header.h"

strings* create_str_1(strings* mas_str, int& size)//������� ��������� � ������ �������� ������ ������� 80
{
	strings* new_mas_str = new strings[++size];
	for (int i = 0; i < size - 1; i++)
	{
		new_mas_str[i].set_str(mas_str[i].get_str());
		new_mas_str[i].set_size(mas_str[i].get_size());
	}

	delete[] mas_str;

	return new_mas_str;
}

strings* create_str_2(strings* mas_str, int& size)//������� ��������� � ������ ������ �������, ��������� �������������
{
	strings* new_mas_str = new strings[++size];

	int size_str;

	for (int i = 0; i < size - 1; i++)
	{
		new_mas_str[i].set_str(mas_str[i].get_str());
		new_mas_str[i].set_size(mas_str[i].get_size());
	}

	cout << "\n������� ������ ������\n";

	cin >> size_str;

	new_mas_str[size - 1].set_size(size_str);

	delete[] mas_str;

	return new_mas_str;
}

strings* create_str_3(strings* mas_str, int& size)//������� ��������� � ������ ������ � �������������� �� ���������, �������� �������������
{
	strings* new_mas_str = new strings[++size];

	char line[SIZE] = "\0";

	for (int i = 0; i < size - 1; i++)
	{
		new_mas_str[i].set_str(mas_str[i].get_str());
		new_mas_str[i].set_size(mas_str[i].get_size());
	}

	delete[] mas_str;

	cout << "\n������� ������\n";
	cin.ignore();
	gets_s(line);

	new_mas_str[size - 1].set_str(line);

	return new_mas_str;
}