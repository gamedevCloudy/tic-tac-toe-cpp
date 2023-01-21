#include<iostream>

#include"player.h"
using namespace std; 

class GameManager: public CPU,public Player
{
    public: GameManager()
            {
                if(mode==1)
                {
                    SinglePlayer();
                }
                else if(mode==2)
                {
                    TwoPlayer();
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

            }

};