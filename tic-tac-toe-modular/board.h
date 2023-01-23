#include<iostream>
#include<cstdlib>


using namespace std; 


class Board
{ 
    private:int moveCount;
            int playerScore;
            int cpuScore;

    
    public: char board[3][3]; 
            char player,cpu; 
            int mode;
            bool reset;

            Board()
            {
                Start();
                CreateBoard();
            }
            

            void Mark(int row,int col, char id)
            {
                board[row][col]=id; 
                UpdateMoveCount();
                Display();
                WinCheck();
            }

    private:
            
            void Start()
            {
                moveCount=0;
                reset=false;

                cout<<"\n-----------------------------------------------------";
                cout<<"\nTIC TAC TOE\n";
                cout<<"\n-----------------------------------------------------";

                cout<<"\nModes: "; 
                cout<<"\n1. Vs. CPU \n2. Vs. Player";
                SelectMode();
            }

            void SelectMode()
            {
                cout<<"\nSELECT MODE: ";
                cin>>mode;
                if(mode!=1)
                    if(mode !=2)
                    {
                        cout<<"\nTRY AGAIN!";
                        SelectMode();
                    }
            }

            void CreateBoard()
            {
                for(int i =0; i<3;i++)
                    for(int j=0; j<3;j++)
                        board[i][j]='-';
            }
            int GetMoveCount()
            {
                return moveCount;
            }

            void UpdateMoveCount()
            {
                moveCount++;
            }

            void SetMoveCount(int count)
            {
                moveCount= count;
            }

            void Display()
            {
                cout<<"\n -------------------------------------------------"; 

                for(int i =0; i<3;i++)
                {
                    cout<<"\n";
                    for (int j=0; j<3;j++)
                    {
                        cout<<board[i][j]<<"\t"; 
                    }
                    cout<<"\n"; 
                }
                cout<<"\n -------------------------------------------------"; 
                
            }

            
            void ResetMenu()
            {
                char opt;

                cout<<"\nPlay Again?"; 
                cout<<"\nY/N: "; 
                cin>>opt;
                if(opt!='Y')
                    exit(0);
                else
                {
                    
                    CreateBoard();
                    Display();
                    reset=true;
                    SetMoveCount(0);
                }
            }
            char Winner()
            {
                for(int i=0; i<3; i++)
                {
                    if( (board[i][0]==board[i][1] && board[i][0]==board[i][2]))
                        return board[i][0];
                    if( (board[0][i]==board[1][i] && board[0][i]==board[2][i])) 
                        return board[0][i];
                }
                if((board[0][0]==board[1][1] && board[0][0]==board[2][2])) 
                    return board[0][0];
                else if(board[0][2]==board[1][1] && board[0][2]==board[2][0])
                    return board[0][2];
                else return '-';
            }

            void WinCheck()
            {
                char w=Winner(); 
                int mCt= GetMoveCount();
                //cout<<"\nwincheck: "<<w<<"\t"<<GetMoveCount(); 
                if(mCt>5)
                {
                    if(w==player)
                    {
                        playerScore+=1;
                        cout<<"\nPLAYER WINS"; 
                        ResetMenu();
                    }
                    else if(w==cpu)
                    {
                        if(mode==1)
                        {
                            cpuScore+=1;
                            cout<<"\nCPU WINS!"; 
                            ResetMenu();
                        }
                        else if(mode==2)
                        {
                            cpuScore+=1;
                            cout<<"\nPlayer 2 WINS!"; 
                            ResetMenu();
                        }
                        
                    }
                }
                
                if(mCt==9)
                {
                    cout<<"\n\nTIE!";
                    ResetMenu();
                }
            }
       
};

