#include "func.hpp"
#include <iostream>
void showMatrix(int***A, int n)
{
	//вывод матрицы
	int** B = *A;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << B[i][j] << ' ';
		}
	
		std::cout << std::endl;
	}
}

bool checkProst(int number)
{
	//проверка на простоту числа
	if (number <= 1) return false;
	for (int i = 2; i <= sqrt(number); i++)
	{
		if (number % i == 0)
			return false;
	}
	return true;
}
void changeMatrix(int*** A, int n)
{

	int** B = *A;
	//подсчёт норм в каждом столбце и занесение в массив norms
	int* norms = new int[n];
	for (int i = 0; i < n; i++)
	{
		norms[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			norms[j] += abs(B[i][j]);
	}
	//сортировка элементов массива norms одновременно со столбцами матрицы по невозрастанию
	for (int k = 0; k < n - 1; k++)
		for (int m = 0; m < n - 1 - k; m++)
		{
			if (norms[m] < norms[m + 1])
			{
				std::swap(norms[m], norms[m + 1]);
				for (int i = 0; i < n; i++)
				{
					std::swap(B[i][m], B[i][m + 1]);
				}
			}
		}
}
