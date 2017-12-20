
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
using namespace std;

// MADE BY ARYA & FAIZ, plz enjoy

//======== INISIALISASI VARIABEL ==============================================


char maps[9][9] = {

	' ','|',' ','|',' ','|',' ','|',' ',

	'-','|','-','|','-','|','-','|','-',

	' ','|',' ','|',' ','|',' ','|',' ',

	'-','|','-','|','-','|','-','|','-',

	' ','|',' ','|',' ','|',' ','|',' ',

	'-','|','-','|','-','|','-','|','-',

	' ','|',' ','|',' ','|',' ','|',' ',

	'-','|','-','|','-','|','-','|','-',

	' ','|',' ','|',' ','|',' ','|',' '

};

bool win;
bool playerturn = true;
int baris, row, column;
int checkWin();

//=============================================================================

//Fungsi ini memprint seluruh isi array maps
void print(){
	system("CLS");
	for(int a=0; a<9; a++){
		for(int b=0; b<9; b++){
			cout << maps[a][b];
		}
		cout << endl;
	}
	//cout << endl;
	cout << "========="<<endl;
	cout << "1|2|3|4|5";
}

//Fungsi ini menentukan bidak yang digunakan berdasarkan giliran player dengan boolean "playerturn"
char player(){
	if(playerturn){
		return 'O';
	}
	else{
		return 'X';
	}
}

//Fungsi ini mengecek apa petak dibawah di baris yang di input, kosong. jika ya, maka ganti dengan bidak player
int insert(int barisKeBerapa){
	int check = -2;
	//cout << maps[check][barisKeBerapa];
	while(maps[check+2][barisKeBerapa]==' '){
		maps[check+2][barisKeBerapa] = player();
		maps[check][barisKeBerapa] = ' ';
		check = check + 2;
		print();
	}
}


int main(){
    int trigger= 0;

	do{
		//system("CLS");
		print();
		cout << endl << endl << "Sekarang giliran: " << player() << endl << "Ingin menaruh di baris ke berapa? ";
		cin >> baris;
		switch(baris){
			case 1:
				insert(0);
				break;
			case 2:
				insert(2);
				break;
			case 3:
				insert(4);
				break;
			case 4:
				insert(6);
				break;
			case 5:
				insert(8);
				break;
			default:
				cout << endl << "ERROR, bukan angka baris";
				//sleep(1);
				break;
		}
		playerturn = !playerturn;
        //win(0);
        trigger = checkWin();
        if (trigger != 0){
            break;
        }

	}while(win == false);
	print();
	if (trigger == 1){
        cout << "O Win!";
	}
	else if (trigger == 2){
        cout << "X Win!";
	}
}

int checkWin(){
    if (maps[0][0]=='O'&&maps[0][2]=='0'&&maps[0][4]=='O'&&maps[0][6]=='0'){
        return 1;
    }
    else {
        return 2;
    }
}
