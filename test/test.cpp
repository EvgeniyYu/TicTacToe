#include "board_model.h"
#include "gtest/gtest.h"
#include <memory>

class TicTacToeTest : public ::testing::TestWithParam<
                          std::tuple<std::vector<unsigned>, MoveResultType>> {};

TEST_P(TicTacToeTest, WhenTheseMovesAreDone_ExpectCorrespondingResult) {
  auto param = GetParam();
  auto moves = std::get<0>(param);
  auto expected_result = std::get<1>(param);

  std::unique_ptr<BoardModel> sptr_board_model = std::make_unique<BoardModel>();
  sptr_board_model->IntializeBoard();
  sptr_board_model->SetPlayersNames("Player1", "Player2");
  MoveResultType move_result;
  for (unsigned i = 0; i < moves.size(); i++) {
    move_result = sptr_board_model->MakeMove(moves[i]);
  }
  EXPECT_TRUE(move_result == expected_result);
}

INSTANTIATE_TEST_SUITE_P(
    TestTicTacToeMoves, TicTacToeTest,
    ::testing::Values(
        std::make_tuple(std::vector<unsigned>{5, 3, 1, 9, 6, 4, 8, 2, 7},
                        MoveResultType::GAME_DRAW),
        std::make_tuple(std::vector<unsigned>{5, 3, 1, 6, 9},
                        MoveResultType::WIN),
        std::make_tuple(std::vector<unsigned>{1, 5, 9, 3, 8, 7},
                        MoveResultType::WIN),
        std::make_tuple(std::vector<unsigned>{1, 5, 2, 9, 3},
                        MoveResultType::WIN),
        std::make_tuple(std::vector<unsigned>{2, 4, 8, 5, 9, 6},
                        MoveResultType::WIN),
        std::make_tuple(std::vector<unsigned>{1, 7, 6, 9, 5, 8},
                        MoveResultType::WIN),
        std::make_tuple(std::vector<unsigned>{1, 5, 4, 6, 7},
                        MoveResultType::WIN),
        std::make_tuple(std::vector<unsigned>{1, 2, 3, 5, 9, 8},
                        MoveResultType::WIN),
        std::make_tuple(std::vector<unsigned>{3, 1, 6, 5, 9},
                        MoveResultType::WIN),
        std::make_tuple(std::vector<unsigned>{3, 1, 3},
                        MoveResultType::INCORRECT_MOVE),
        std::make_tuple(std::vector<unsigned>{3, 1, 4, 10},
                        MoveResultType::INCORRECT_MOVE),
        std::make_tuple(std::vector<unsigned>{3, 1, 4}, MoveResultType::OK)));
