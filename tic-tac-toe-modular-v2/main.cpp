#include<iostream>
#include<cstdlib>

#include"gamemanager.h"


int main()
{
    GameManager gm;
    
    while(true)
    {
        gm.PlayerMove();
        
        gm.CPUMove();
    }
    return 0;
}
