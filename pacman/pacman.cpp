#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

char player = 'O';
char movement;
char maps[7][7] = {
    '#','#','#','#','#','#','#',
    '#',' ',' ',' ',' ',' ','#',
    '#',' ','u',' ','u',' ','#',
    '#',' ',' ',' ',' ',' ','#',
    '#',' ','u',' ','u',' ','#',
    '#',' ',' ',' ',' ',' ','#',
    '#','#','#','#','#','#','#',
};
void printMap();
struct earth{
    bool dinding;
    bool pellet;
    bool player;
    bool enemy;
};

int main(){
    int a = 3, b = 3;
    maps[a][b] = player;
    printMap();
    for (int z=3; z>=2; z++) {
        cout << "mau bergerak ke mana?" << endl << "a = left, w : up, d : right, s : down" << endl;
        cin >> movement;
        switch(movement){
            case 'a':
                if(b == 1 ||
                    (b == 2)&&(a == 2) ||
                   (b == 4)&&(a == 2) ||
                   (b == 4)&&(a == 4) ||
                   (b == 2)&&(a == 4) ){
                    break;
                }
                maps[a][b-1] = player;
                maps[a][b] = ' ';
                b--;
                break;

            case 'w':
                if(a == 1 ||
                    (b == 2)&&(a == 2) ||
                   (b == 4)&&(a == 2) ||
                   (b == 4)&&(a == 4) ||
                   (b == 2)&&(a == 4) ){
                    break;
                }
                maps[a-1][b] = player;
                maps[a][b] = ' ';
                a--;
                break;

            case 's':
                if(a == 5 ||
                   (b == 2)&&(a == 2) ||
                   (b == 4)&&(a == 2) ||
                   (b == 4)&&(a == 4) ||
                   (b == 2)&&(a == 4) ){
                    break;
                }
                maps[a+1][b] = player;
                maps[a][b] = ' ';
                a++;
                break;

            case 'd':
                if(b == 5 ||
                   (b == 2)&&(a == 2) ||
                   (b == 4)&&(a == 2) ||
                   (b == 4)&&(a == 4) ||
                   (b == 2)&&(a == 4) ){
                    break;
                }
                maps[a][b+1] = player;
                maps[a][b] = ' ';
                b++;
                break;

        }
        system("CLS");
        printMap();
        cout << a << " " << b;
    }
}


void printMap(){
    for (int a=0; a <=6; a++){
        for (int b=0; b <=6; b++){
            cout << maps[a][b];
        }
        cout << endl;
    }
    /*cout << "#######" << endl;
    cout << "#     #" << endl;
    cout << "# # # #" << endl;
    cout << "#     #" << endl;
    cout << "# # # #" << endl;
    cout << "#     #" << endl;
    cout << "#######" << endl;*/
}

/*int movement(){
    char pilihjalur;
    cin >> pilihjalur;
}*/
