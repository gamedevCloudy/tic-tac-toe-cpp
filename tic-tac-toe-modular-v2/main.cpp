#include<iostream>
#include<cstdlib>

#include"gamemanager.h"



int main()
{
    GameManager gm;
    
    while(true)
    {
        gm.Display();
        gm.PlayerMove();
        gm.Display();
        gm.CPUMove();
    }
    return 0;
}
