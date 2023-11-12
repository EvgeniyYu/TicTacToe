#include "board_model.h"


bool BoardModel::IsMoveValid(unsigned index)
{
    return (index >= 1 && index <= BOARD_ELEMENTS_SIZE && m_cells[index - 1] == DEFAULT_VALUE)? true: false;
}

bool BoardModel::IsBoardFull()
{
    return (moves_count == BOARD_ELEMENTS_SIZE)? true: false;
}
    
bool BoardModel::IsWin(char sign)
{
    if ((sign == m_cells[2] && m_cells[2] == m_cells[4] && m_cells[4] == m_cells[6]) || (sign == m_cells[0] && m_cells[0] == m_cells[4] && m_cells[4] == m_cells[8]))
    {
        return true;
    }
    for (int i = 0; i < LINE_ELEMENTS_SIZE; i++) 
    {
        if (sign == m_cells[i * LINE_ELEMENTS_SIZE] && m_cells[i * LINE_ELEMENTS_SIZE] == m_cells[i * LINE_ELEMENTS_SIZE + 1] && m_cells[i * LINE_ELEMENTS_SIZE + 1] == m_cells[i * LINE_ELEMENTS_SIZE + 2])
            return true; 
        else if (sign == m_cells[i] && m_cells[i] == m_cells[i + LINE_ELEMENTS_SIZE] && m_cells[i + LINE_ELEMENTS_SIZE] == m_cells[i + LINE_ELEMENTS_SIZE * 2]) 
            return true;
    }
    return false;
}

void BoardModel::IntializeBoard()
{
    for (auto i = 0; i < BOARD_ELEMENTS_SIZE; i++)
    {
        m_cells[i] = '-';
    }
}

void BoardModel::SetPlayersNames(const std::string& _player_name1, const std::string& _player_name2)
{
    player_name1 = _player_name1;
    player_name2 = _player_name2;
    current_player_name = player_name1;
}

const std::string BoardModel::GetResult() const
{
    std::string result;
    switch (move_result)
    {
        case MoveResultType::GAME_DRAW:
            result = "game draw!";
            break;
        case MoveResultType::WIN:
            result = "congratulations! You are winner!";
            break;
        case MoveResultType::INCORRECT_MOVE:
            result = "input correct cell number ( 1-9 ) for empty ( --- ) cell for making step:";
            break;
        case MoveResultType::OK:
            result = "input cell number, make you step!:";
            break;
        default:
            break;
    }
    return current_player_name + ", " + result;
}

const BoardElements& BoardModel::GetCells() const 
{
    return m_cells;
}
    
MoveResultType BoardModel::MakeMove(unsigned index)
{
    if (!IsMoveValid(index)) 
    {
        move_result = MoveResultType::INCORRECT_MOVE;
        return move_result;
    }

    auto sign = (current_player_name == player_name1)? 'X': '0';
    m_cells[index - 1] = sign;
    moves_count++;

    if (IsBoardFull())
    {
        move_result = MoveResultType::GAME_DRAW;
        return move_result;
    }
        
    if (IsWin(sign))
    {
        move_result = MoveResultType::WIN;
        return move_result;
    }

    current_player_name = (current_player_name == player_name1)? player_name2: player_name1;
    move_result = MoveResultType::OK;
    return move_result;
}