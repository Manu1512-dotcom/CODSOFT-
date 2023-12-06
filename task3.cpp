#include<iostream>
using namespace std;

char board[3][3];
int flag[3][3];

char check();

char check()
{
    char winflag='n';
    if(board[0][0]==board[0][1] && board[0][0]==board[0][2])
            {
                winflag = board[0][0];
            }
            else if(board[0][0]==board[1][0] && board[0][0]==board[2][0])
            {
                winflag = board[0][0];    
            }
            else if(board[0][1]==board[1][1] && board[0][1]==board[2][1])
            {
                winflag = board[0][1];
            }
            else if(board[0][2]==board[1][2] && board[0][2]==board[2][2])
            {
                winflag = board[0][2];
            }
            else if(board[1][0]==board[1][1] && board[1][0]==board[1][2])
            {
                winflag=board[1][0];
            }
            else if(board[2][0]==board[2][1] && board[2][0]==board[2][2])
            {
                winflag = board[2][0];
            }
            else if(board[0][0]==board[1][1] && board[0][0]==board[2][2])
            {
                winflag = board[0][0];
            }
            else if(board[0][2]==board[1][1] && board[0][2]==board[2][0])
            {
                winflag = board[0][2];
            }        
    return winflag;
}

int main()
{
    cout<<"\t\t\t**************************************************************************\n\n\t\t\t\t\t\t\tTIC TAC TOC\n\n\t\t\t**************************************************************************\n\n";

   int choice;
   do
   {
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                board[i][j]='*';
                flag[i][j]=0;
            }
        }
        cout<<"grid status:\n\n";
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                cout<<board[i][j]<<"\t";
            }
            cout<<endl<<endl;
        }
        cout<<"_______Press ENTER to start game______\n\n"<<endl;
        cin.ignore();
        int turn=1;
        while(turn<=9)
        {
            int x,y;
            if(turn%2==0)
            {
                cout<<"PLAYER 2's TURN :-"<<endl;
            }
            else if(turn%2!=0)
            {
                cout<<"PLAYER 1's TURN :-"<<endl;
            }
            cout<<"enter the row number : ";
            cin>>x;
            cout<<"enter the column number : ";
            cin>>y;
            if(x<=3 && y<=3 && x>0 && y>0 && flag[x-1][y-1]==0)
            {
                if(turn%2==0)
                {
                    board[x-1][y-1]='O';
                    flag[x-1][y-1]=1;
                }
                else if(turn%2!=0)
                {
                    board[x-1][y-1]='X';
                    flag[x-1][y-1]=1;
                }
                turn++;
                cout<<"\n\ngrid status:\n\n";
                for(int i=0;i<3;i++)
                {
                    for(int j=0;j<3;j++)
                    {
                        cout<<board[i][j]<<"\t";
                    }
                    cout<<endl<<endl;
                }

                char winner=check();
                
                if(winner=='X')
                {
                    cout<<"player 1 won"<<endl<<endl<<endl;
                    break;

                }
                else if(winner=='O')
                {
                    cout<<"player 2 won"<<endl<<endl<<endl;
                    break;
                }
                else if(winner=='n' && turn>9)
                {
                    cout<<"\t\tGAME OVER"<<endl<<endl<<endl;
                }
            }
            else
            {
                cout<<"\n\n\t\tENTER VALID POSITION\n\n";
            }
        }
        cout<<"Press 1 to play more or 0 to exit"<<endl;
        cin>>choice;
   }while(choice==1);

    return 0;
}