#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");

	strings* mas_str = nullptr;

	enum menu { STR_1 = 1, STR_2, STR_3, SEE_COUNT, SEE_STR, INPUT };

	int user, size = 0;

	do
	{
		cout << "�������: \n1 ������� ������ �������� 80 ��������, \n2 ������� ������ ������������� ������� \n3 ������� ������ � ���������������� \n4 ���������� ���������� ����� \n5 ���������� ������\n6 ������ ��������� ������\n0 �����\n";

		cin >> user;

		switch (user)
		{
		case STR_1:
			mas_str = create_str_1(mas_str, size);
			break;
		case STR_2:
			mas_str = create_str_2(mas_str, size);
			break;
		case STR_3:
			mas_str = create_str_3(mas_str, size);
			break;
		case SEE_COUNT:
			cout << "\n��������� ����� " << mas_str->show_count() << "\n";//���������� ���������� ��������� ��������
			break;
		case SEE_STR:
			for (int i = 0; i < size; i++)
			{
				mas_str[i].print(); //���������� ������ � �� �������
			}
			break;
		case INPUT:
			char line[SIZE];
			int index;
			cout << "������� ������ ������ � �������� ���������� � ���\n";
			cin >> index;
			cin.ignore();

			gets_s(line);

			mas_str[index].set_str(line);
			break;
		default:
			break;
		}

	} while (user != 0);


	return 0;
}
