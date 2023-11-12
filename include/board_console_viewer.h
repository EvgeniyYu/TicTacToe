#ifndef BOARD_CONSOLE_VIEWER_H
#define BOARD_CONSOLE_VIEWER_H

#include "iboard_viewer.h"
#include "board_model.h"
#include <memory>

class BoardConsoleViewer: public IBoardViewer
{
    std::shared_ptr<BoardModel> sptr_board_model;
    void DisplayBoardState(const BoardElements& cells, bool default_cell_numbers);
public:
    BoardConsoleViewer(std::shared_ptr<BoardModel> _sptr_board_model);
    void Display() override;
};



#endif