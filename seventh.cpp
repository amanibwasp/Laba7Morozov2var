#include "func.hpp"
#include <iostream>
#include <cmath>

int main()
{
	setlocale(LC_ALL, "");
	int n;
	std::cout << "Введите число N - порядок квадратной матрицы: ";
	std::cin >> n;
	int** A = new int* [n];
	for (int i = 0; i < n; i++)
		A[i] = new int [n];
		
	
	std::cout << "Введите матрицу порядка " << n << " :" << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			std::cin >> A[i][j];
	}
	
	std::cout << "Введённая матрица: " << std::endl;
	showMatrix(&A, n);
	
	std::cout << "Если найдётся строка с хотя бы 1 простым числом и суммой элементов в ней = 0, то в результате получим" << std::endl << "отсортированную матрицу по столбцам по невозрастанию нормы (суммы модулей)" << std::endl;
	
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
	if (found) std::cout << "Результат работы программы (искомая строка присутствует): " << std::endl;
	else std::cout << "Результат работы программы (искомой строки нет. Матрица не изменилась): " << std::endl;
	
	//вывод полученной матрицы
	showMatrix(&A, n);
	
	for (int i = 0; i < 9; i ++)
		delete [] A[i];
	delete [] A;
	return 0;
}
