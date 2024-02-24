#include<iostream>
#include<bits/stdc++.h>
#include<conio.h>
#include<stdlib.h>  
using namespace std;


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void generate_new_point(vector<int>& curr_pos, vector<int>& pts_loc){
    while(true){
        int point_loc_x = rand()%10;
        int point_loc_y = rand()%10;
        if(point_loc_x!=curr_pos[0] && point_loc_y!=curr_pos[1] && (point_loc_x >= 1 && point_loc_x <= 8) && (point_loc_y >= 1 && point_loc_y <= 8)){
            pts_loc[0] = point_loc_x;
            pts_loc[1] = point_loc_y;
            break;
        } 
    }
}

void show_board(char* board[][10], vector<int>& curr_pos, vector<int>& pts_loc, int& curr_point){ 
    cout << "\033[2J\033[1;1H";
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i==curr_pos[0] && j==curr_pos[1]){
                cout<<"G"<<" ";
            } else if(i==pts_loc[0] && j==pts_loc[1]){
                cout<<"$"<<" ";
            }
            else cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    if(pts_loc[0] == curr_pos[0] && pts_loc[1] == curr_pos[1]){
        curr_point++;
        generate_new_point(curr_pos,pts_loc);
    } 
    cout<<"Score : "<<curr_point<<endl;
    cout<<" >> Press (q) to exit << "<<endl;
}

int main(){
    char* board[10][10] = {{"*","*","*","*","*","*","*","*","*","*"},
        {"*"," "," "," "," "," "," "," "," ","*"},
        {"*"," "," "," "," "," "," "," "," ","*"},
        {"*"," "," "," "," "," "," "," "," ","*"},
        {"*"," "," "," "," "," "," "," "," ","*"},
        {"*"," "," "," "," "," "," "," "," ","*"},
        {"*"," "," "," "," "," "," "," "," ","*"},
        {"*"," "," "," "," "," "," "," "," ","*"},
        {"*"," "," "," "," "," "," "," "," ","*"},
        {"*","*","*","*","*","*","*","*","*","*"}
    };
    vector<int> curr_pos{1,1};
    vector<int> points_loc{0,0};
    int curr_score = 0;
    generate_new_point(curr_pos,points_loc);
    show_board(board,curr_pos,points_loc,curr_score);
    int c=0;
    while(true){
        show_board(board,curr_pos,points_loc,curr_score);
        switch((c=getch())) {
        case KEY_UP:
            if(curr_pos[1] > 1) curr_pos[1] --; //key up
            break;
        case KEY_DOWN:
            if(curr_pos[1] < 8) curr_pos[1] ++;   // key down
            break;
        case KEY_LEFT:
            if(curr_pos[0] > 1) curr_pos[0]--; // key left
            break;
        case KEY_RIGHT:
            if(curr_pos[0] < 8) curr_pos[0]++;
            break;
        case 113: exit(0);
        default:// not arrow
            break;
        }
    }
}