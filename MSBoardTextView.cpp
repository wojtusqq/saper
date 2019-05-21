#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
#include <iostream>
using namespace std;
MSBoardTextView::MSBoardTextView(MinesweeperBoard &board):board(board){}
void MSBoardTextView::display()
{
    for(int y=0; y<board.getBoardHeight(); y++)
    {
            cout<<endl;
        for(int x=0; x<board.getBoardWidth(); x++)
        {
            cout<<"["<<board.getFieldInfo(x,y)<<"] ";
        }

    }
}