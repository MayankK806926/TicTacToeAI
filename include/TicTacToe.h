// TicTacToe.h - Header file for the TicTacToe class
// Declares the interface and members for the TicTacToe game logic
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <string>
#include <iostream>

class TicTacToe {
private:
    const int size = 3; // Board size (3x3)
    const char AI_MOVE = 'O'; // Symbol for AI moves
    const char HUMAN_MOVE = 'X'; // Symbol for human moves
    std::vector<std::vector<char>> board; // 2D board representation
    int playerScore = 0; // Player's score in tournament
    int aiScore = 0;     // AI's score in tournament

    // Checks for win conditions
    bool rowCrossed();
    bool columnCrossed();
    bool diagonalCrossed();
    // Minimax algorithm for AI decision making
    int minimax(int depth, bool isAI, int alpha, int beta);
    // Finds the best move for the AI
    int bestMove(int moveIndex);
    // Gets the current date and time as a string
    std::string currentDateTime();

public:
    // Constructor
    TicTacToe();
    // Shows instructions for the game
    void showInstructions();
    // Displays the current board
    void showBoard();
    // Resets the board to empty
    void resetBoard();
    // Checks if the game is over
    bool gameOver();
    // Plays a single game (playerStarts: true if player goes first)
    void playSingleGame(bool playerStarts);
    // Logs the result of a tournament
    void logTournamentResult(int player, int ai, int totalMatches);
    // Manages the tournament flow
    void playTournament();
};

#endif