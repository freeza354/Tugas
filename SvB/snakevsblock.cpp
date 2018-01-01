#include <iostream>
#include <windows.h>
#include <conio.h>
#include <cstdlib>
#include <ctime>

using namespace std;

char map_top[8][11]= {'#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '_','_','_','_','_','_','_','_','_','_','_'}; // bentuk map diatas
char map_btm[]= {'#',' ','|',' ','|',' ','|',' ','|',' ','#'}; // bentuk map dibawah
char pindah;
int angka_top[7][5]={0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0,
                     0, 0, 0, 0, 0}; // isi map diatas
int koor = 2; // inisialisasi kooardinat awal pemain
bool game_con = false, game_exit = false; // trigger kondisi game
int angka_btm[5]={0,0,5,0,0}; // isi map dibawah

void acak_angka();
void print_map_btm();
void pindah_kar();
void print_map_top();
void turun();

int main(){
    int koorX;
    srand(time(NULL)); // Random generator
    while(game_con == false||game_exit == false){
        acak_angka();
        print_map_top();
        print_map_btm();
        pindah_kar();
        //Sleep(250);
        system("cls");
        turun();
    }

}

void print_map_btm(){
    cout << endl;
    int hfa = 0; // Hitungan untuk angka
    for (int i=0; i<=10; i++) // hitungan untuk Map
        {
        if(i%2==0){
        cout << map_btm[i];
        }
        else{
            if(angka_btm[hfa]!=0){
            cout << angka_btm[hfa]; // print map isinya jika ternyata tidak 0
            }
            else{
                cout << " "; // print map menjadi spasi jika ternyata isinya 0
            }
            hfa++;
        }
    }
}

void pindah_kar() // fungsi untuk memindahkan angka dibawah
    {
    cout << endl << "Gunakan A dan D untuk pindah!" << endl;
    pindah=getch();
    switch (pindah){
        case 'a' :
            angka_btm[koor] = 0;
            koor -= 1;
            if(koor == -1){
                koor+=1;
            }
            angka_btm[koor] = 5;
            break;
        case 'd' :
            angka_btm[koor] = 0;
            koor += 1;
            if(koor == 5){
                koor-=1;
            }
            angka_btm[koor] = 5;
            break;
        case 'A' :
            angka_btm[koor] = 0;
            koor -= 1;
            if(koor == 0){
                koor+=1;
            }
            angka_btm[koor] = 5;
            break;
        case 'D' :
            angka_btm[koor] = 0;
            koor += 1;
            if(koor == 5){
                koor-=1;
            }
            angka_btm[koor] = 5;
            break;
        case 27 :
            game_exit = true;
        default :
            cout << "Invalid Input!" << endl;
    }
}

void print_map_top() // fungsi untuk menge-print map atas
    {
    int hitungX = 0, hitungY = 0; // hitungan untuk angka
    for (int a=0; a<8; a++) // hitungan untuk bilangan koordinat x
        {
        for (int b=0; b<=10; b++) // hitungan untuk bilangan koordinat y
            {
            if(b%2==0&&a!=7){
                cout << map_top[a][b];
            }
            else if(b%2!=0&&a!=7){
                if(angka_top[hitungX][hitungY]==0){
                    cout << " ";
                }
                else{
                    cout << angka_top[hitungX][hitungY];
                }
                hitungY++;
/*                angka_top[hitungX+1][hitungY+1] = angka_top[hitungX][hitungY]; // menurunkan angka yg ada diatasnya
                angka_top[hitungX+2][hitungY+2] = angka_top[hitungX+1][hitungY+1];
                angka_top[hitungX+3][hitungY+3] = angka_top[hitungX+2][hitungY+2];
                angka_top[hitungX+4][hitungY+4] = angka_top[hitungX+3][hitungY+3];
                angka_top[hitungX+5][hitungY+5] = angka_top[hitungX+4][hitungY+4];
                angka_top[hitungX+6][hitungY+6] = angka_top[hitungX+5][hitungY+5];
                angka_top[hitungX+7][hitungY+7] = angka_top[hitungX+6][hitungY+6];
                angka_top[hitungX][hitungY]=0; */  //mengganti angka diatasnya menjadi 0;
            }
            else{
                cout << map_top[a][b] << "_";
            }
        }
        cout << endl;
        hitungX++;
    }
}

void acak_angka() // fungsi untuk mengacak angka
{
    int acakX, hasil_angka;
    acakX = (rand()%6); // mengacak tempat keluar
    hasil_angka = (rand()%9)+1; // mengacak angka yang dikeluarkan
    angka_top[0][acakX] = hasil_angka;
}

void turun(){
    for (int x=0; x<=7; x++){
        for (int y=0; y<=5; y++){
            angka_top[x][y]=angka_top[x+1][y+1];
            angka_top[x][y]= 0;
        }
}

}
