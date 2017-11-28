#include <iostream>

using namespace std;

int main (){
	int arr[11][11], temp=0;
	arr[0][0]=3;
	temp = arr[0][0];
	for (int a=1; a<=9; a++){
		arr[a][0]=temp+2;
		for (int b=1; b<=a; b++){
			arr[a][b]= arr[a][0]+b;
		}
		temp+=2;
	}
	for (int c=0; c<=9; c++){
		for (int d=0; d<=c; d++){
			cout << arr[c][d] << " ";
		}
	cout << endl;
	}
}
