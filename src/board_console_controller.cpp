#include "board_console_controller.h"
#include "board_model.h"
#include <iostream>

void BoardConsoleController::Start()
{
    sptr_board_model->IntializeBoard();
    EnterPlayersNames();
    uptr_board_viewer->Display();

    bool finished = false;
    
    while (!finished)
    {
        unsigned cell_number;
        std::cin >> cell_number;

        auto move_result = sptr_board_model->MakeMove(cell_number);

        uptr_board_viewer->Display();
        
        if (move_result == MoveResultType::INCORRECT_MOVE)
        {
            continue;
        }
        else if (move_result == MoveResultType::GAME_DRAW)
        {
            finished = true;
        }
        else if (move_result == MoveResultType::WIN)
        {
            finished = true;
        }
        else
        {
            /* NOT USED*/
        }
        
    }
}

void BoardConsoleController::EnterPlayersNames()
{
    std::string player_name1, player_name2;
    do {
        std::cout << "Input name of first player: ";
        std::cin >> player_name1;
        std::cout << "Input name of second player: ";
        std::cin >> player_name2;
        std::cout << "\n";
    } while (player_name1 == player_name2);
    sptr_board_model->SetPlayersNames(player_name1, player_name2);
}