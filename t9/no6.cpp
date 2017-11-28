#include<iostream>
using namespace std;

int main (){
	int n, nTemp=0, cek=0;
	cout << "masukkan nilai n :";
	cin >> n;
	nTemp=n;
	for (int i=0; i<2*n-1; i++){
		cout << nTemp;
		for (int j=0; j<9; j++){
			cout << nTemp;
		}
		cout << endl;
		nTemp--;
		if (nTemp<2){
			break;
		}
	}
	for (int i=0; i<2*n-1; i++){
		cout << nTemp;
		for (int j=0; j<9; j++){
			cout << nTemp;
		}
		cout << endl;
		nTemp++;
		if (nTemp==n+1){
			break;
		}
	}
}
