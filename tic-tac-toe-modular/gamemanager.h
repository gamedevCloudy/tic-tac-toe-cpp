#include<iostream>

#include"player.h"
using namespace std; 

class GameManager: public CPU,public Player
{
    public: GameManager()
            {
                cout<<"\n\nSTART GAME!!!";
            }
};