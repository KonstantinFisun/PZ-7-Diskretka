#include <iostream>
#include <fstream>

using namespace std;

void swap(int *razP, int i, int j)
{
	int bufer = razP[i];
	razP[i] = razP[j];
	razP[j] = bufer;
}

bool nextCombobj(int *razP, int n, int k)
{
	int j;
	do  // повторяем пока не будет найдено следующее размещение
	{
		j = n - 1;
		while (j != -1 && razP[j] >= razP[j + 1]) j--;

		if (j == -1)
			return false; // больше размещений нет

		int k = n - 1;


		while (razP[j] >= razP[k]) k--;
		swap(razP, j, k);

		int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
		while (l < r)
			swap(razP, l++, r--);

	} while (j > k - 1);
	return true;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	int n=8, k=5;

	char *arr = new char[8] { '1', '2', '3', '4', '5', '6', '7', '8' };

	ofstream A("out.txt");
	int *razP = new int[k];

	int kol = 0;
		for (int i = 0; i < n; i++)
			razP[i] = i;

		for (int i = 0; i < k; i++)
			A << arr[razP[i]] << " ";
		A << endl;

		while (nextCombobj(razP, n, k))
		{
			for (int i = 0; i < k; i++){
				A << arr[razP[i]] << " ";
				kol++;
			}
			A << endl;
		}

	cout << "Все возможное размещения по k = 5 построены!";
	A << "Количество - " << kol << endl;
	cout << endl;
	A.close();
	system("pause");
}