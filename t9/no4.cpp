#include<iostream>
using namespace std;

int fungsi(int x){
	for (x=0; x<=4; x++){
		for (int b=0; b<=4; b++){
			cout << (x+1)+(b+1) << " ";
		}
		cout << endl;
	}
}
int main ()
{
	fungsi(0);
}
