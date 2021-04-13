#include <iostream>
#include <string>
using namespace std;
string field [3] [3];
int mapping [9];
int x = 0;
int y = 0;
bool flag = false;
int finish_cond = -1;


void marking_x (int i, int j){
    if (field[i][j] == "[ ]") {
        field [i][j] = "[x]";
        mapping[(3*i)+j] = 1;
        flag = true;
    } 
    else {
        cout << "It is not possible position" << endl;
        flag = false;
    }
}

void marking_o (int i, int j){
    if (field[i][j] == "[ ]") {
        field [i][j] = "[O]";
        mapping[(3*i)+j] = 0;
        flag = true;
    } else {
        cout << "It is not possible position" << endl;
        flag = false;
    }
}

void initial_field(){
    for (int i = 0; i< 3; i++){
        for (int j = 0; j< 3; j++){
            field [i][j] = "[ ]";
            mapping[i+(3*j)] = -1;
        }
    }
}

void print_field(){
    for (int i = 0; i< 3; i++){
        for (int j =0; j < 3; j++){
            cout << field[i][j];
            cout << mapping[3*i+j];
        }
        cout << endl;
    }
}

void user_input(){
    do{
        cout << "Put the coordinate of i :: ";
    cin >> x;
    if (x < 0 || x > 3){
        cout << "wrong integer" << endl;
        continue;
    } 
    cout << "Put the coordinate of j :: ";
    cin >> y;
    if (y < 0 || y > 3){
        cout << "wrong integer" << endl;
    }
    } while ((x <0 || x > 2) || ( y < 0 || y > 2));

}

int game_result(){
    if(mapping[0] == 1 && mapping[1] == 1 && mapping[2] == 1)return 1;
    else if(mapping[0] == 0 && mapping[1] == 0 && mapping[2] == 0) return 2;
    
    if(mapping[0] == 1 && mapping[4] == 1 && mapping[8] == 1) return 1;
    else if(mapping[0] == 0 && mapping[4] == 0 && mapping[8] == 0) return 2;
    
    if(mapping[0] == 1 && mapping[3] == 1 && mapping[6] == 1) return 1;
    else if(mapping[0] == 0 && mapping[3] == 0 && mapping[6] == 0) return 2;
    
    if(mapping[1] == 1 && mapping[4] == 1 && mapping[7] == 1) return 1;
    else if(mapping[1] == 0 && mapping[4] == 0 && mapping[7] == 0) return 2;
    
    if(mapping[2] == 1 && mapping[4] == 1 && mapping[6] == 1) return 1;
    else if(mapping[2] == 0 && mapping[4] == 0 && mapping[6] == 0) return 2;
    
    if(mapping[2] == 1 && mapping[5] == 1 && mapping[8] == 1) return 1;
    else if(mapping[2] == 0 && mapping[5] == 0 && mapping[8] == 0) return 2;
    
    if(mapping[3] == 1 && mapping[4] == 1 && mapping[5] == 1) return 1;
    else if(mapping[3] == 0 && mapping[4] == 0 && mapping[5] == 0) return 2;
    
    if(mapping[6] == 1 && mapping[7] == 1 && mapping[8] == 1) return 1;
    else if(mapping[6] == 0 && mapping[7] == 0 && mapping[8] == 0) return 2;
    
    for(int i =0; i<9 ; i++){
        if(mapping[i] == -1){
            return -1;
        }
    }
    return 0;
}
void result(){
    if(finish_cond == 0){
        cout<<"TIE!"<<endl;
    }
    else if(finish_cond == 1){
        cout<<"Player 1 WIN!"<<endl;
    }
    else{
        cout<<"Player 2 WIN!"<<endl;
    }
}

void reline(){
    printf("\x1b[2J");
    printf("\x1b[d");
}

int main() {
    cout<<"WELCOME TO TICTACTO GAME!"<<endl;
    initial_field();
    print_field();
    
    while (finish_cond == -1){
        while (flag == false){
            cout << "Player 1's turn: " << endl;
            user_input();
            marking_x(x, y);
            finish_cond = game_result();
        }
        flag = false;
        
        reline();
        print_field();
        
        if(finish_cond != -1) {
            result();
            break;
        }
        
        while (flag == false){
            cout << "Player 2's turn: " << endl;
             user_input();
             marking_o(x, y);
             finish_cond = game_result();
        }
        flag = false;
        
        reline();
        print_field();
        
        if(finish_cond != -1){ 
            result();
            break;
        }
    } 
    return 0;
}
