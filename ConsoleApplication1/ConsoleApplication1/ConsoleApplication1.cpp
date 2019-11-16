#include <iostream>
#include <ctime>

using namespace std;

void main()
{
	int n = 10, sum1 = 0, sum2 = 0;
	srand(time(NULL));
	int** arr = new int* [n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n * 2 - 1];
		for (int j = 0; j < n * 2 - 1; j++)
		{
			if (j >= n)
				arr[i][j] = arr[i][j - n];
			else
			{
				arr[i][j] = 1 + rand() % 5;
				cout << arr[i][j] << "\t";
			}
		}
		cout << endl << endl;
	}
	for (int rez = 1, i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			rez *= arr[j][j + i];
		sum1 += rez;
		rez = 1;
		for (int k = 0, j = n * 2 - 2; k < n; k++)
			rez *= arr[k][j - k - i];
		sum2 += rez;
		rez = 1;
	}
	cout << "Rezult = " << sum1 - sum2;
	delete[] arr;
}