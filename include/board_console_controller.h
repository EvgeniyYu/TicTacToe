#ifndef BOARD_CONSOLE_CONTROLLER_H
#define BOARD_CONSOLE_CONTROLLER_H

#include "board_model.h"
#include "board_console_viewer.h"
#include <memory>

class BoardConsoleController
{
    std::shared_ptr<BoardModel> sptr_board_model = std::make_shared<BoardModel>();
    std::unique_ptr<IBoardViewer> uptr_board_viewer = std::make_unique<BoardConsoleViewer>(sptr_board_model);
    void EnterPlayersNames();
public:
    void Start();
};

#endif