// TicTacToe.h - Header file for the TicTacToe class
// Declares the interface and members for the TicTacToe game logic
#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

class TicTacToe {
private:
    const int size = 3; // Board size 
    const char AI_MOVE = 'O';
    const char HUMAN_MOVE = 'X';
    vector<vector<char>> board;
    int playerScore = 0;
    int aiScore = 0;

    // Checks for win conditions
    bool rowCrossed();
    bool columnCrossed();
    bool diagonalCrossed();

    // Minimax algorithm for AI decision making
    int minimax(int depth, bool isAI, int alpha, int beta);
    // Finds the best move for the AI
    int bestMove(int moveIndex);
    // Gets the current date and time as a string to store results data
    string currentDateTime();

public:
    TicTacToe();
    void showInstructions();
    void showBoard();
    void resetBoard();
    bool gameOver();
    // Plays a single game (playerStarts: true if player goes first)
    void playSingleGame(bool playerStarts);
    // Logs the result of a tournament
    void logTournamentResult(int player, int ai, int totalMatches);
    // Manages the tournament flow
    void playTournament();
};

#endif
