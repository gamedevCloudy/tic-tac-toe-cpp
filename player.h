#include<iostream>
#include<cstdlib>
#include"board.h"
using namespace std; 

class Player: public Board
{
    public: int moves; 
            void PlayerMove()
            {
                int i,j=0; 
                cout<<"Enter row and column to place in: ";
                cin>>i>>j;
                if(board[i][j] !='-') PlayerMove();
                else Mark(i,j,player);
                moves+=1;
            }
};