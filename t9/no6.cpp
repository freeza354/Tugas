#include<iostream>
using namespace std;

int fungsi(int x){
	int xTemp;
	xTemp=x;
for (int i=0; i<2*x-1; i++){
		cout << xTemp;
		for (int j=0; j<9; j++){
			cout << xTemp;
		}
		cout << endl;
		xTemp--;
		if (xTemp<2){
			break;
		}
	}
	for (int i=0; i<2*x-1; i++){
		cout << xTemp;
		for (int j=0; j<9; j++){
			cout << xTemp;
		}
		cout << endl;
		xTemp++;
		if (xTemp==x+1){
			break;
		}
	}

}

int main (){
	int n;
	cout << "masukkan nilai n :";
	cin >> n;
	fungsi(n);
}
