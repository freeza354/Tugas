#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

char map_top[9][11]= {'#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '#',' ','|',' ','|',' ','|',' ','|',' ','#',
                      '_','_','_','_','_','_','_','_','_','_','_'};
char map_btm[]= {'#',' ','|',' ','|',' ','|',' ','|',' ','#'};
char pindah;
int koor = 2;
bool game_con = false;
int angka_btm[5]={0,0,5,0,0};

void print_map_btm();
void pindah_kar();
void print_map_top();

int main(){

    while(game_con == false){
        print_map_top();
        print_map_btm();
        pindah_kar();
        //Sleep(250);
        system("cls");
    }

}

void print_map_btm(){
    cout << endl;
    int hfa = 0;
    for (int i=0; i<=10; i++){
        if(i%2==0){
        cout << map_btm[i];
        }
        else{
            if(angka_btm[hfa]!=0){
            cout << angka_btm[hfa];
            }
            else{
                cout << " ";
            }
            hfa++;
        }
    }
}

void pindah_kar(){
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
        default :
            cout << "Invalid Input!" << endl;
    }
}

void print_map_top(){
    for (int a=0; a<=8; a++){
        for (int b=0; b<=10; b++){
            cout << map_top[a][b];
        }
        if(a!=8){
        cout << endl;
        }
    }
}
