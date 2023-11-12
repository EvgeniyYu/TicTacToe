#include "board_console_viewer.h"
#include <iostream>

BoardConsoleViewer::BoardConsoleViewer(std::shared_ptr<BoardModel> _sptr_board_model): sptr_board_model(_sptr_board_model) 
{
}


void BoardConsoleViewer::DisplayBoardState(const BoardElements& cells, bool default_cell_numbers)
{
    for (auto i = 0; i < cells.size(); i++)
    {
        if (default_cell_numbers)
        {
            std::cout << "-" << static_cast<unsigned>(i + 1) << "-";
        }
        else
        {
            std::cout << "-" << static_cast<char>(cells[i]) << "-";
        }
            
        if ((i + 1) % LINE_ELEMENTS_SIZE == 0)
        {
            std::cout << "\n";
        }
        else
        {
            std::cout << "|";
        }   
    }
}

void BoardConsoleViewer::Display()
{
    auto cells = sptr_board_model->GetCells();
    std::cout << "Cell number: \n";
    DisplayBoardState(cells, true);
    std::cout << "Current state (\"---\" - empty cell):\n" << std::endl;
    DisplayBoardState(cells, false);
    std::cout << sptr_board_model->GetResult() << std::endl;
}
