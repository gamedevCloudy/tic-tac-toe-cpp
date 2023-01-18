#include<iostream>
#include<cstdlib>
#include"board.h"
using namespace std; 

class Player: virtual public Board
{
    public: int moves; 
            void PlayerMove()
            {
                int i,j=0; 
                cout<<"\nEnter row and column to place in: ";
                cin>>i>>j;
                if(board[i][j] !='-') PlayerMove();
                else Mark(i,j,player);
                moves+=1;
            }
};


class CPU: virtual public Board
{
    public: int moves; 

            void FindAndPlace(int i)
            {
                for(int k=0;k<3;k++)
                { 
                    if(board[i][k] =='-')
                        Mark(i,k,cpu); 
                }
            }
            bool Startegy1()
            {
                for(int i=0;i<3;i++)
                {   int count=0; 
                    for(int j=0;j<3;j++)
                    {
                        if(j==player)
                        {
                            count+=1; 
                        }
                        if (count==2)
                        { 
                            FindAndPlace(i);
                            WinCheck();
                            return true;
                        }
                    }
                }
                return false; 
            }
            bool Strategy2()
            {
                return false;
            }

            void PlaceAtRandom()
            {
                int r,c =1; 
                do{
                r= (rand()%3);
                c= (rand()%3);}
                while(board[r][c] != '-');
                Mark(r,c,cpu);
                WinCheck();
            }
            void CPUMove()
            {
                if(!Startegy1())
                {
                    if(!Strategy2())
                    {
                        PlaceAtRandom(); 
                    }
                }
            }
};