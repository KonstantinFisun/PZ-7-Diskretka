#include<iostream>
#include<fstream>
#include<ctime>
#include<set>
using namespace std;



bool nextCombobj(int *razP, int k,int n){

	int j = k - 1;
	while (j >= 0 && razP[j] == n - 1) j--;

	if (j == -1) return false;

	razP[j]++;


	for (int i = j + 1; i < k; i++){
		razP[i] = 0;
	}

	return true;

}


void main(){
	setlocale(LC_ALL, "RUSSIAN");
	int start = clock();
	const int n = 8;
	char *arr = new char[n] { '1', '2', '3', '4', '5', '6', '7', '8' };

	int N = 6, k = 3;


	int *razP = new int[N];
	for (int i = 0; i < N; i++){
		razP[i] = 0;
	}
	ofstream A("A.txt");

	int kol = 0;
	while (nextCombobj(razP, N, n)){
		int sim = 0;
		for (int g = 0; g < N; g++){
			if (razP[g] == 1) sim++;
		}
		if (sim == 3){
			for (int i = 0; i < N; i++){
				A << arr[razP[i]];
			}
			A << endl;
			kol++;
		}
	}
	cout << kol << " - Количество" << endl;
	int end = clock();

	int t = (end - start) / CLOCKS_PER_SEC;

	cout << "Время работы: " << t << " секунд " << endl;
	system("pause");
}