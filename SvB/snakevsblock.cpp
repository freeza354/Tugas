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
int angka_btm[5]={0,0,100,0,0}; // isi map dibawah
int pemain = 100;
int batas_rand_min = 20;
int batas_rand_plus = 10;
int board_j_size = 5;
int board_i_size = 7;
int score = 0;

void hitung_score();
void acak();
void tambah();
void print_map_btm();
void pindah_kar();
void print_map_top();
void turun();
void cek_game();

int rand_min_1, rand_min_2, rand_min_3, rand_min_4, rand_min_5, rand_plus_1, rand_plus_2, rand_plus_3;

int main(){
    int hitungan=1;
    srand(time(NULL)); // Random generator
    while(game_con == false){
        //acak();
        if (hitungan%2==0){
            tambah();
        }
        else if(hitungan%2!=0){
            acak();
        }
        print_map_top();
        print_map_btm();
        pindah_kar();
        //Sleep(250);
        system("cls");
        turun();
        hitung_score();
        cek_game();
        hitungan++;
        if(score>=250&&batas_rand_min==20){
            batas_rand_min += 20;
            batas_rand_plus += 10;
        }
        else if(score>=500&&batas_rand_min==40){
            batas_rand_min += 20;
            batas_rand_plus += 10;
        }
        else if(score>=1000&&batas_rand_min==60){
            batas_rand_min += 20;
            batas_rand_plus += 10;
        }
    }
    cout << "Skor anda :" << score;
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
            if(angka_btm[hfa]!=0&&angka_btm[hfa]>=100){
                cout << angka_btm[hfa]; // print map isinya jika ternyata tidak 0
            }
            else if(angka_btm[hfa]!=0&&angka_btm[hfa]>=10){
                cout << " " << angka_btm[hfa];
            }
            else if(angka_btm[hfa]!=0&&angka_btm[hfa]<10){
                cout << "  " << angka_btm[hfa];
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
    cout << endl << "Skor anda saat ini :" << score;
    pindah=getch();
    switch (pindah){
        case 'a' :
            angka_btm[koor] = 0;
            koor -= 1;
            if(koor == -1){
                koor+=1;
            }
            angka_btm[koor] = pemain;
            break;
        case 'd' :
            angka_btm[koor] = 0;
            koor += 1;
            if(koor == 5){
                koor-=1;
            }
            angka_btm[koor] = pemain;
            break;
        case 'A' :
            angka_btm[koor] = 0;
            koor -= 1;
            if(koor == 0){
                koor+=1;
            }
            angka_btm[koor] = pemain;
            break;
        case 'D' :
            angka_btm[koor] = 0;
            koor += 1;
            if(koor == 5){
                koor-=1;
            }
            angka_btm[koor] = pemain;
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
                if(angka_top[hitungX][hitungY]==0){
                    cout << "   ";
                }
                else if(angka_top[hitungX][hitungY]>=100){
                    if(angka_top[hitungX][hitungY]>batas_rand_plus){
                        cout << angka_top[hitungX][hitungY];
                    }
                    else{
                        cout << "+" << angka_top;
                    }
                }
                else if(angka_top[hitungX][hitungY]>=10){
                    if(angka_top[hitungX][hitungY]>batas_rand_plus){
                        cout << " " << angka_top[hitungX][hitungY];
                    }
                    else {
                        cout << "+" << angka_top[hitungX][hitungY];
                    }
                }
                else{
                    if(angka_top[hitungX][hitungY]>batas_rand_plus){
                        cout << "  " << angka_top[hitungX][hitungY];
                    }
                    else {
                        cout << " +" << angka_top[hitungX][hitungY];
                    }
                }
                hitungY++;
            }
        }
        cout << endl;
        hitungY = 0;
        hitungX++;
    }
}

void acak()
{
    for(int i=0; i< board_j_size; i++)
    {
        angka_top[0][i] = (rand()%batas_rand_min)+11;
    }
}

void tambah(){
    int kotak_acak;
    kotak_acak = (rand()%4);
    angka_top[0][kotak_acak] = (rand()%batas_rand_plus+1);
}

void turun()
{
    int temp[board_j_size];
    int temp2[board_j_size];
    for(int w=0; w<board_i_size; w++)
    {
        for(int j=0; j<board_j_size; j++)
        {
            if(w > 0)
            {
                if(w==1)
                {
                    temp[j] =  angka_top[w][j];
                    angka_top[w][j] = angka_top[w-1][j];
                }
                else
                {
                    temp2[j] =  angka_top[w][j];
                    angka_top[w][j] = temp[j];
                    temp[j] = temp2[j];
                }
            }
        }
    }
}

void hitung_score(){
    for (int garis=0; garis<=4; garis++)
        if (angka_top[6][garis] != 0 && angka_btm [garis] != 0){
            if(angka_top[6][garis]>batas_rand_plus){
                pemain -= angka_top[6][garis];
                score += angka_top[6][garis];
            }
            else {
                pemain += angka_top[6][garis];
            }
        }
        else {

        }
}

void cek_game(){
    if(pemain<=0){
        game_con=true;
    }
}
