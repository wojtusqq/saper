#ifndef SAPER_MINESWEEPERBOARD_H_
#define SAPER_MINESWEEPERBOARD_H_
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <stdlib.h>
using namespace std;
enum GameMode {DEBUG, EASY, NORMAL, HARD};
enum GameState {RUNNING, FINISHED_WIN, FINISHED_LOSS};
struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};
class MinesweeperBoard
{
    Field board[50][50];
    int width;
    int height;
public:
    MinesweeperBoard(int, int, GameMode mode);
    void debug_display();
    int countMines(int x, int y);
    void toggleFlag(int x, int y);
    bool isRevealed(int x, int y);
    bool hasFlag(int x, int y);
    bool hasMine(int x, int y);
    void Reveal(int x, int y);
    int getBoardWidth();
    int getBoardHeight();
    int getMineCount();
    GameState getGameState();
    char getFieldInfo(int x, int y);
};
#endif SAPER_MINESWEEPERBOARD_H_






