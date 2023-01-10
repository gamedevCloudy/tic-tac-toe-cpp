#include<iostream>
#include<cstdlib>
#include"board.h"

using namespace std; 

class CPU
{
    public: int moves; 
            Board b;

            void FindAndPlace(int i)
            {
                for(int k=0;k<3;k++)
                { 
                    if(b.board[i][k] =='-')
                        b.Mark(i,k,b.cpu); 
                }
            }
            bool Startegy1()
            {
                for(int i=0;i<3;i++)
                {   int count=0; 
                    for(int j=0;j<3;j++)
                    {
                        if(j==b.player)
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
                return false;
            }

            void PlaceAtRandom()
            {
                int r,c =1; 
                do{
                r= (rand()%3);
                c= (rand()%3);}
                while(b.board[r][c] != '-');

                b.Mark(r,c,b.cpu);
            }
            void Move()
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