#include<iostream>

#include"player.h"
using namespace std; 

class GameManager: public CPU,public Player, public Player2
{
    public: GameManager()
            {
                if(mode==1)
                {
                    SinglePlayer();
                    PlayerVsCpu();
                }
                else if(mode==2)
                {
                    TwoPlayer();
                    PlayerVsPlayer();
                }
            }

    private: 
            void SinglePlayer()
            {
                cout<<"\n\nSTART GAME!!!";

               
                cout<<"\nYour Mark: "; 
                cin>>player; 

                if(player=='X') cpu='O'; 
                else if(player=='O') cpu='X'; 
                else
                {
                    cout<<"\nTRY AGAIN!"; 
                    
                    SinglePlayer();
                } 

                
            }
            void TwoPlayer()
            {
                cout<<"\n\nSTART GAME!!!";

               
                cout<<"Player 1 Mark: "; 
                cin>>player; 

                if(player=='X') cpu='O'; 
                else if(player=='O') cpu='X'; 
                else
                {
                    cout<<"\nTRY AGAIN!"; 
                    
                    TwoPlayer();
                } 

            }
            void CheckReset()
            {
                if(reset==true)
                {
                    reset=false;
                    if(mode==1)
                    {
                        PlayerVsCpu();
                    }
                    else if(mode==2)
                    {
                        PlayerVsPlayer();
                    }
                }
            }
            void  PlayerVsCpu()
            {
                while(true)
                {
                    PlayerMove();
                    
                    CPUMove();
                }
            }
            void PlayerVsPlayer()
            {
                while(true)
                {
                    PlayerMove();
                    PlayerMove2();    
                }
            }

};