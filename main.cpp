#include<iostream>
#include<cstdlib>

#include"board.h"
#include"cpu.h"
#include"player.h"

using namespace std; 

int main()
{
    Board b;
    Player player1; 
    CPU cpu1;
    player1.b = b; 
    cpu1.b=b;
    b.Display();
    player1.Move();
    player1.b.Display();
    cpu1.Move();
    cpu1.b.Display();
    return 0;
}
