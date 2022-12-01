#include "func.hpp"
#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "");
	int n;
	std::cout << "������� ����� N - ������� ���������� �������: ";
	std::cin >> n;
	int** A = new int* [n];
	for (int i = 0; i < n; i++)
		A[i] = new int [n];
		
	
	std::cout << "������� ������� ������� " << n << " :" << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			std::cin >> A[i][j];
	}
	
	std::cout << "�������� �������: " << std::endl;
	showMatrix(&A, n);
	
	std::cout << "���� ������� ������ � ���� �� 1 ������� ������ � ������ ��������� � ��� = 0, �� � ���������� �������" << std::endl << "��������������� ������� �� �������� �� ������������� ����� (����� �������)" << std::endl;
	
	bool found = false;
	for (int i = 0; i < n; i++)
	{
		int summ = 0;
		bool flag = false;
		for (int j = 0; j < n; j++)
		{
			summ+=A[i][j];
			if (checkProst(A[i][j]))
				flag = true;
		}
		if (flag && summ == 0)
			{
				changeMatrix(&A, n);
				found = true;

			}
	}
	if (found) std::cout << "��������� ������ ��������� (������� ������ ������������): " << std::endl;
	else std::cout << "��������� ������ ��������� (������� ������ ���. ������� �� ����������): " << std::endl;
	
	//����� ���������� �������
	showMatrix(&A, n);
	
	for (int i = 0; i < 9; i ++)
		delete [] A[i];
	delete [] A;
	return 0;
}
