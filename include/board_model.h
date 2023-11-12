#ifndef BOARD_MODEL_H
#define BOARD_MODEL_H

#include <array>
#include <string>

constexpr unsigned LINE_ELEMENTS_SIZE = 3;
constexpr unsigned BOARD_ELEMENTS_SIZE = LINE_ELEMENTS_SIZE* LINE_ELEMENTS_SIZE;
using BoardElements = std::array<char, BOARD_ELEMENTS_SIZE>;
enum class MoveResultType {OK, INCORRECT_MOVE, WIN, GAME_DRAW};

class BoardModel
{
    const char DEFAULT_VALUE{'-'};
    MoveResultType move_result;
    int moves_count{0};
    BoardElements m_cells;
    std::string player_name1, player_name2;
    std::string current_player_name;
    bool IsMoveValid(unsigned index);
    bool IsBoardFull();
    bool IsWin(char sign);
public:
    void IntializeBoard();
    void SetPlayersNames(const std::string& _player_name1, const std::string& _player_name2);
    const std::string GetResult() const;
    const BoardElements& GetCells() const;
    MoveResultType MakeMove(const unsigned index);
};

#endif