#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include "MSTextController.h"
#include <iostream>
using namespace std;
MSTextController::MSTextController(MinesweeperBoard & board, MSBoardTextView & view):board(board),view(view){}
void MSTextController::play()
{
    //podczas, gdy gra ja wlaczcona
    while(board.getGameState()==RUNNING)
    {
        view.display();
        int wybor,x,y;
        cout<<endl;
        cout<<"[1] ODKRYWAJ POLE"<<endl;
        cout<<"[2] STAWIAJ FLAGE"<<endl;
        cout<<"OPCJA: ";
        cin>>wybor;
                                                    if (wybor == 1)
        {
            cout<<"Wpisz X: ";
            cin>>x;
            cout<<"Wpisz Y: ";
            cin>>y;
            board.Reveal(x,y);
        }
                                                    if (wybor == 2)
        {
            cout<<"Wpisz X: ";
            cin>>x;
            cout<<"Wpisz Y: ";
            cin>>y;
            board.toggleFlag(x,y);
        }
    }
    view.display();
    cout<<endl;
    if(board.getGameState()==FINISHED_LOSS)
                                            cout<<"P R Z E G R A L E S";
    else
                                            cout<<"W Y G R A L E S";
}

