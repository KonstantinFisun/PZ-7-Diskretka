#include<iostream>
#include<fstream>
#include<ctime>
#include<set>
using namespace std;


bool Podschet(int *razP, int N, int n, int k1, int k2){
	int Kol[10];
	int seen[12];
	for (int i = 0; i < n; i++) {
		Kol[i] = 0;
		seen[i] = 0;
	}

	for (int i = 0; i < N; i++){
		if (seen[i] == 0){
			int count = 0;
			for (int j = i; j < N; j++){
				if (razP[j] == razP[i]){
					count++;
					seen[j] = 1;
				}
			}
			Kol[i] = count;
		}
	}


	int kol_k1 = 0;
	int kol_k2 = 0;

	for (int i = 0; i < n; i++){
		if (Kol[i] == k1){
			kol_k1++;
			Kol[i] = 0;
		}
	}
		if (kol_k1 != 1) return false;
		else{
			for (int i = 0; i < n; i++){
				if (Kol[i] == k2){
					kol_k2++;
					Kol[i] = 0;
				}
			}
				if (kol_k2 != 1) return false;
		}



		return true;
	}


bool nextCombobj(int *razP, int k, int n){ //все возможные слова

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

	int N=7, k1=3,k2=2;
	

	int *razP = new int[N];
	for (int i = 0; i < N; i++){
		razP[i] = 0;
	}
	ofstream A("A.txt");

	int kol = 0;
	while (nextCombobj(razP, N, n)){
		if (Podschet(razP, N, n, k1,k2)) {
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