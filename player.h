#include<iostream>
#include<cstdlib>
#include"board.h"
using namespace std; 

class Player
{
    public: int moves; 
            Board b; 
            void Move()
            {
                int i,j=0; 
                cout<<"Enter row and column to place in: ";
                cin>>i>>j;
                if(b.board[i][j] !='-') Move();
                else b.Mark(i,j,b.player);
                moves+=1;
            }
};