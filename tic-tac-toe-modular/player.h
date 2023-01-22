#include<iostream>
#include<cstdlib>
#include"board.h"

using namespace std; 

class Player: virtual public Board
{
    public: 
            void PlayerMove()
            {
                int i,j=0; 
                cout<<"\nTurn: Player 1";
                cout<<"\nEnter row and column to place in: ";
                cin>>i>>j;
                if(board[i][j] !='-')
                {
                    cout<<"\nTRY AGAIN!";
                    PlayerMove();   
                } 
                else 
                {
                    Mark(i,j,player);
                }
                
            }
};

class Player2: virtual public Board
{
    public: 
            void PlayerMove2()
            {
                int i,j=0; 
                cout<<"\nTurn: Player 2";
                cout<<"\nEnter row and column to place in: ";
                cin>>i>>j;
                if(board[i][j] !='-') 
                {
                    cout<<"\nTRY AGAIN!";
                    PlayerMove2();
                }   
                else 
                {
                    Mark(i,j,cpu);
                }
                
            }
};


class CPU: virtual public Board
{
    public:
            void FindAndPlace(int i)
            {
                for(int k=0;k<3;k++)
                { 
                    if(board[i][k] =='-')
                    {    
                        Mark(i,k,cpu); 
                    }
                }
            }
            bool Startegy1()
            {
                cout<<"\nRow Block: \n";
                for(int i=0;i<3;i++)
                {   int count=0; 
                    for(int j=0;j<3;j++)
                    {
                        if(board[i][j]==cpu) return false;
                        if(board[i][j]==player)
                        {
                            count+=1; 
                        }
                        if (count==2)
                        { 

                            FindAndPlace(i);
                            return true;
                        }
                    }
                }
                return false; 
            }
            bool Strategy2()
            {
                cout<<"\nColumn Block: \n";
                for(int i=0; i<3;i++)
                {   
                    if(board[0][i]==board[1][i] and board[0][i]==player and board[2][i]=='-')
                    {
                        Mark(2,i,cpu);
                        return true;

                    }
                    else if(board[0][i]==board[2][i]  and board[0][i]==player and board[1][i]=='-')
                    {
                        Mark(1,i,cpu);
                        return true;
                    }
                    else if(board[1][i]==board[2][i]  and board[1][i]==player and board[0][i]=='-')
                    {
                        Mark(0,i,cpu);
                        return true;
                    }
                    else return false;
                }
                return false;
            }

            void PlaceAtRandom()
            {
                cout<<"\nRandom Block: \n";
                int r,c =1; 
                do{
                r= (rand()%3);
                c= (rand()%3);}
                while(board[r][c] != '-');
                Mark(r,c,cpu);
                
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