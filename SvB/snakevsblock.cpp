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
int turun_parm = 0;
bool game_con = false, game_exit = false; // trigger kondisi game
int angka_btm[5]={0,0,5,0,0}; // isi map dibawah
int rand_batas = 20, batas_rand_plus = 10;
int score = 0;
int player = 5;

void acak_angka();
void print_map_btm();
void pindah_kar();
void print_map_top();
void turun();
void acak_tambah();

int rand_min_1, rand_min_2, rand_min_3, rand_min_4, rand_min_5, rand_plus_1, rand_plus_2, rand_plus_3;

int main(){
    int hitung_keluaran = 0;
    srand(time(NULL)); // Random generator
    while(game_con == false||game_exit == false){
        hitung_keluaran++;
        if(hitung_keluaran >= 5){
            acak_angka();
            turun();
            turun_parm++;
        }
        else{}
        print_map_top();
        print_map_btm();
        pindah_kar();
        //Sleep(250);
        system("cls");
        if (score == 100){
            rand_batas +=20;
        }
        else if(player == 0) {
            game_con = true;
        }
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
                if(angka_btm[hfa]<10){
                    cout << "  " << angka_btm[hfa];
                }
            }
            else{
                cout << "   "; // print map menjadi spasi jika ternyata isinya 0
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
            angka_btm[koor] = player;
            break;
        case 'd' :
            angka_btm[koor] = 0;
            koor += 1;
            if(koor == 5){
                koor-=1;
            }
            angka_btm[koor] = player;
            break;
        case 'A' :
            angka_btm[koor] = 0;
            koor -= 1;
            if(koor == 0){
                koor+=1;
            }
            angka_btm[koor] = player;
            break;
        case 'D' :
            angka_btm[koor] = 0;
            koor += 1;
            if(koor == 5){
                koor-=1;
            }
            angka_btm[koor] = player;
            break;
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
                if(angka_top[hitungX][hitungY] == 0){
                    cout << "   ";
                }
                else{
                    cout <<angka_top[hitungX][hitungY];
                }
                hitungY++;
            }
            else{
                cout << map_top[a][b] << "_";
            }
        }
        cout << endl;
        hitungY = 0;
        hitungX++;
    }
}

void acak_angka() // fungsi untuk mengacak angka
{
    rand_min_1 = (rand()%rand_batas)+1;
    rand_min_2 = (rand()%rand_batas)+1;
    rand_min_3 = (rand()%rand_batas)+1;
    rand_min_4 = (rand()%rand_batas)+1;
    rand_min_5 = (rand()%rand_batas)+1;
}

void turun(){
    angka_top[turun_parm][0] = rand_min_1;
    angka_top[turun_parm][1] = rand_min_2;
    angka_top[turun_parm][2] = rand_min_3;
    angka_top[turun_parm][3] = rand_min_4;
    angka_top[turun_parm][4] = rand_min_5;
    if(turun_parm==7){
        turun_parm = 0;
    }
}
