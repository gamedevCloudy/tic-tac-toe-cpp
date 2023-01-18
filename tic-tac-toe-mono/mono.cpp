#include<iostream>
#include<cstdlib>
using namespace std; 

char board[3][3];
class Board
{ 
    public:  
            char player,cpu; 

            Board()
            {
                cout<<"\nYour Mark: "; 
                cin>>player; 

                if(player=='X') cpu='O'; 
                else if(player=='O') cpu='X'; 
                else
                {
                    cout<<"TRY AGAIN!"; 
                    Board();
                } 

                for(int i =0; i<3;i++)
                    for(int j=0; j<3;j++)
                        board[i][j]='-';
      
            }

            

            void Mark(int row,int col, char id)
            {
                board[row][col]=id; 
            }

            void Display()
            {
                for(int i =0; i<3;i++)
                {
                    for (int j=0; j<3;j++)
                    {
                        cout<<board[i][j]<<"\t"; 
                    }
                    cout<<"\n"; 
                }
            }

            char Winner()
            {
                for(int i=0; i<3; i++)
                {
                    if( (board[i][0]==board[i][1]==board[i][2])& (board[i][2]=='X'| board[i][2]=='O')) return board[i][0];
                    else if( (board[0][i]==board[1][i]==board[2][i]) & (board[0][i]=='X' | board[0][i]=='O')) return board[0][i];
                }
                if((board[0][0]==board[1][1]==board[2][2]) & (board[0][0]=='X'| board[0][0]=='O')) return board[0][0];
                else if((board[0][2]==board[1][1]==board[2][0]) & (board[0][2]=='X' | board[0][2]=='O')) return board[0][2];

                return '-';
            }

            void WinCheck()
            {
                char w=Winner(); 

                if(w==player){
                    cout<<"\nPLAYER WINS"; 
                    exit(0);
                }
                else if(w==cpu)
                {
                    cout<<"\nCPU WINS!"; 
                    exit(0);
                }
            }



};

class Player
{
    public: int moves; 
            Board b; 
            void Move()
            {
                int i,j=0; 
                cout<<"Enter row and column to place in: ";
                cin>>i>>j;
                if(board[i][j] !='-') Move();
                else b.Mark(i,j,b.player);
                moves+=1;
            }
};

class CPU
{
    public: int moves; 
            Board b;

            void FindAndPlace(int i)
            {
                for(int k=0;k<3;k++)
                { 
                    if(board[i][k] =='-')
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
                while(board[r][c] != '-');

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

int main()
{
    Board b;
    Player player1; 
    CPU cpu1;
    
    while(true)
    {
        player1.Move();
        b.Display();
        b.WinCheck();
        cpu1.Move();
        b.WinCheck();
        b.Display();
    }
    return 0;
}
