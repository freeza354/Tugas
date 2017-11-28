#include <iostream>

using namespace std;

int main (){
	for (int a=0; a<=9; a++){
		for (int b=0; b<=a; b++){
			cout << (a+1)*(b+1)<< " ";
		}
		cout << endl;
	}
}
