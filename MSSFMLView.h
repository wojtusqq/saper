#ifndef SAPER_MSSFMLView_H_
#define SAPER_MSSFMLView_H_
#include "MinesweeperBoard.h"
class MSSFMLView
{
    MinesweeperBoard & board;
public:
    MSSFMLView(MinesweeperBoard & );
    void view();
    void gameresult();
};
#endif SAPER_MSSFMLView_H_
