#ifndef SAPER_MSTEXTCONTROLLER_H_
#define SAPER_MSTEXTCONTROLLER_H_
#include "MSBoardTextView.h"
#include "MinesweeperBoard.h"
class MSTextController
{
    MinesweeperBoard & board;
    MSBoardTextView & view;
public:
    MSTextController(MinesweeperBoard&,MSBoardTextView&);
    void play();
};
#endif SAPER_MSTEXTCONTROLLER_H_
