#include<iostream>

using namespace std;

void print( const char x[] );

void inputValidate(int &n, const char x[]);

int validate(const char x[]);

int main(void){

    char p1[30], p2[30];
    bool isEnded = false;
    int pos, val = -1;
    int count  = 0;
    char game[9] = {'1', '2', '3',
                    '4', '5', '6',
                    '7', '8', '9'};



    cout << "TIC TAC TOE\n\n";
    cout << "Enter the name of first player: ";
    cin >> p1;
    cout << "Enter the name of second player: ";
    cin >> p2;
    
    print(game);
    while (!isEnded){
       

        cout << p1 << " Enter : ";
        inputValidate(pos, game);
        game[pos - 1] = 'x';
        print(game);
        
        val = validate(game);
        if (val == 1){
            cout << p1 << " Wins" << endl;
            isEnded = true;
            break;
        } else if(val == 2){
            cout << p2 << " Wins" << endl;
            isEnded = true;
        }

        cout << p2 << " Enter : ";
        inputValidate(pos, game);
        game[pos - 1] = 'o';
        print(game);

        val = validate(game);
        if (val == 1){
            cout << p1 << " Wins" << endl;
            isEnded = true;
        } else if(val == 2){
            cout << p2 << " Wins" << endl;
            isEnded = true;
        }
        count++;
        if (count >= 4){
            isEnded = true;
        }

    }


    return 0;
}

void inputValidate(int &n, const char x[]){
    int isvalid = 1;
    while (isvalid){

        cin >> n;

        if (n <= 9 && n > 0){
            if (x[n-1] == 'x' || x[n-1] == 'o'){
                cout << "Already Occupied, Enter again: ";
            } else {
                
                isvalid = 0;
            }
        } else {
            cout << "Invalid!, Enter again: ";
        }
    }

}


void print( const char x[]){
    for (int i = 0; i < 9; i+=3){
        cout << x[i] << " | " << x[i + 1] << " | " << x[i + 2] << endl;
    }
}


int validate(const char x[]){
    int value = -1;
    if ((x[0] ==x[1] && x[1] == x[2] ) || (x[3] == x[4] && x[4] == x[5]) || (x[6] == x[7] && x[7] == x[8]) ||
        (x[0] == x[3] && x[3] == x[6]) || (x[1] == x[4] && x[4] == x[7]) || (x[2] == x[5] && x[5] == x[8]  ||
         x[0] == x[4] && x[4] == x[8]) || (x[2] == x[4] && x[4] == x[6])){
             if (x[0] == 'x'){
                value = 1;
             } else {
                value = 2;
             }
    } else {
        value = -1;
    }

    return value;
}