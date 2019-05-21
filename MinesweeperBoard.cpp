#include <iostream>
#include "MinesweeperBoard.h"
#include <time.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;
MinesweeperBoard::MinesweeperBoard(int w, int h, GameMode mode)
{
    width=w;
    height=h;
    for(int i=0; i<=width; i++)
    {
        for(int j=0; j<=height; j++)
        {
            board[i][j].hasFlag=false;
            board[i][j].hasMine=false;
            board[i][j].isRevealed=false;
        }
    }
    if(mode == DEBUG)
    {
        for(int i=0; i<width; i++)
            board[i][0].hasMine=true;
    }

    if(mode==HARD)
    {
        int k,l;
        srand(time(NULL));
        int wynik=(width*height)*0.3;
        int liczbamin=0;
        while(wynik>0)
        {
            k=rand()%width;
            l=rand()%height;
            if(board[k][l].hasMine==false)
            {
                board[k][l].hasMine=true;
                wynik--;
            }
        }
    }
    if(mode == NORMAL)
    {
        int k,l;
        srand(time(NULL));
        int wynik=(width*height)*0.2;
        int liczbamin=0;
        while(wynik>0)
        {
            k=rand()%width;
            l=rand()%height;
            if(board[k][l].hasMine==false)
            {
                board[k][l].hasMine=true;
                wynik--;
            }
        }
    }
    if(mode == EASY)
    {
        int k,l;
        srand(time(NULL));
        int wynik=(width*height)*0.1;
        while(wynik>0)
        {
            k=rand()%width;
            l=rand()%height;
            if(board[k][l].hasMine==false)
            {
                board[k][l].hasMine=true;
                wynik--;
            }
        }
    }
}
//sprawdza, czy dane pole jest ujawnione
bool MinesweeperBoard::isRevealed(int x, int y)
{
    if(board[x][y].isRevealed==true)
        return true;
    else
        return false;
}
//liczba min w grze
int MinesweeperBoard::getMineCount()
{
    int liczbamin=0;
    for(int i=0; i<width; i++)
    {
        for (int j=0; j<height; j++)
        {
            if(board[i][j].hasMine==true)
                liczbamin++;
        }
    }
    return liczbamin;
}
//status gry - wygrana/przegrana
GameState MinesweeperBoard::getGameState()
{
    int trwa=0;
    int liczba=0;
    int rozmiar, liczbaotwartych=0;
    int plansza;
    plansza=width*height;
    rozmiar=(width*height)-getMineCount();

    for(int i=0; i<width; i++)
    {
        for(int j=0; j<height; j++)
        {
            if((board[i][j].hasMine==true)&&(board[i][j].isRevealed==true))
                trwa=1;
            if(board[i][j].isRevealed==false)
                liczba++;
        }
    }
    if(liczba==getMineCount())
        trwa=2;
    if(trwa==1)
        return FINISHED_LOSS;
    if(trwa==2)
        return FINISHED_WIN;
    else
        return RUNNING;
}
//ilosc min dookola pola, ktore sprawdzamy
int MinesweeperBoard::countMines(int x, int y)
{
    if(x>=width||y>=height)
        return -1;
    if(board[x][y].isRevealed==false)
        return -1;
    if(board[x][y].isRevealed==true)
    {
        int liczbamin=0;
        if(x==0 && y!=0)
        {
            if(board[x][y-1].hasMine==1)
                liczbamin++;
            if(board[x][y+1].hasMine==1)
                liczbamin++;
            if(board[x+1][y-1].hasMine==1)
                liczbamin++;
            if(board[x+1][y].hasMine==1)
                liczbamin++;
            if(board[x+1][y+1].hasMine==1)
                liczbamin++;
        }
        else if(y==0 && x!=0)
        {
            if(board[x-1][y].hasMine==1)
                liczbamin++;
            if(board[x-1][y+1].hasMine==1)
                liczbamin++;
            if(board[x][y+1].hasMine==1)
                liczbamin++;
            if(board[x+1][y].hasMine==1)
                liczbamin++;
            if(board[x+1][y+1].hasMine==1)
                liczbamin++;
        }
        else if(x==width && y!=height)
        {
            if(board[x-1][y-1].hasMine==1)
                liczbamin++;
            if(board[x-1][y].hasMine==1)
                liczbamin++;
            if(board[x-1][y+1].hasMine==1)
                liczbamin++;
            if(board[x][y-1].hasMine==1)
                liczbamin++;
            if(board[x][y+1].hasMine==1)
                liczbamin++;
        }
        else if(y==height && y!=width)
        {
            if(board[x-1][y-1].hasMine==1)
                liczbamin++;
            if(board[x-1][y].hasMine==1)
                liczbamin++;
            if(board[x][y-1].hasMine==1)
                liczbamin++;
            if(board[x+1][y-1].hasMine==1)
                liczbamin++;
            if(board[x+1][y].hasMine==1)
                liczbamin++;
        }
        else if(x==0 && y==0)
        {
            if(board[x][y+1].hasMine==1)
                liczbamin++;
            if(board[x+1][y].hasMine==1)
                liczbamin++;
            if(board[x+1][y+1].hasMine==1)
                liczbamin++;
        }
        else if(x==width && y!=0)
        {
            if(board[x-1][y].hasMine==1)
                liczbamin++;
            if(board[x-1][y+1].hasMine==1)
                liczbamin++;
            if(board[x][y+1].hasMine==1)
                liczbamin++;

        }
        else if(x==width and y==height)
        {
            if(board[x-1][y-1].hasMine==1)
                liczbamin++;
            if(board[x-1][y].hasMine==1)
                liczbamin++;
            if(board[x][y-1].hasMine==1)
                liczbamin++;
        }
            else if(x!=0 and y==width)
        {
            if(board[x][y-1].hasMine==1)
                liczbamin++;
            if(board[x+1][y-1].hasMine==1)
                liczbamin++;
            if(board[x+1][y].hasMine==1)
                liczbamin++;
        }
        else
        {

            if(board[x-1][y-1].hasMine==1)
                liczbamin++;
            if(board[x-1][y].hasMine==1)
                liczbamin++;
            if(board[x-1][y+1].hasMine==1)
                liczbamin++;
            if(board[x][y-1].hasMine==1)
                liczbamin++;
            if(board[x][y+1].hasMine==1)
                liczbamin++;
            if(board[x+1][y-1].hasMine==1)
                liczbamin++;
            if(board[x+1][y].hasMine==1)
                liczbamin++;
            if(board[x+1][y+1].hasMine==1)
                liczbamin++;
        }
        return liczbamin;
    }
}

int MinesweeperBoard::getBoardWidth()
{
    return width;
}

bool MinesweeperBoard::hasFlag(int x, int y)
{
    if(board[x][y].hasFlag==true)
        return true;
    else
        return false;
}

bool MinesweeperBoard::hasMine(int x, int y)
{
    if(board[x][y].hasMine==true)
        return true;
    else
        return false;
}

int MinesweeperBoard::getBoardHeight()
{
    return height;
}
//stawia flage
void MinesweeperBoard::toggleFlag(int x, int y)
{
    board[x][y].hasFlag=true;
}
//odkrywane jest pole
void MinesweeperBoard::Reveal(int x, int y)
{
    board[x][y].isRevealed=true;
}
//plansza - funkcja ja wyswietla
void MinesweeperBoard::debug_display()
{

    for(int i=0; i<width; i++)
    {
        cout<<endl;
        for(int j=0; j<height; j++)
        {
            cout<<"[";
            if (board[j][i].hasMine==false)
                cout<<".";
            else
                cout<<"M";
            if (board[j][i].isRevealed==false)
                cout<<".";
            else
                cout<<"o";
            if (board[j][i].hasFlag==false)
                cout<<".";
            else
                cout<<"F";
            cout<<"]";
        }
    }
    cout<<endl;
}

char MinesweeperBoard::getFieldInfo(int x, int y)
{
    if(board[x][y].isRevealed==true&&board[x][y].hasMine==true)return 'X';
    if(board[x][y].isRevealed==false&&board[x][y].hasFlag==true) return 'F';
    if(board[x][y].isRevealed==true&&countMines(x,y)==0) return ' ';
    if(board[x][y].isRevealed==true&&board[x][y].hasMine==true) return 'X';
    if(board[x][y].isRevealed==true&&board[x][y].hasMine==false) return countMines(x,y)+48;
    if(board[x][y].isRevealed==false&&board[x][y].hasFlag==false) return '.';
    if(x>=width||y>=height) return '#';
}

