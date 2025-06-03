// TicTacToe.cpp - Implements the TicTacToe class logic and game flow
// Handles board display, game logic, AI, and tournament management
#include "../include/TicTacToe.h"
#include <iostream>
#include <limits>
#include <fstream>
#include <ctime>

// Constructor: Initializes a 3x3 board with empty spaces
TicTacToe::TicTacToe() : board(3, std::vector<char>(3, ' ')) {}

// Displays instructions for cell numbering
void TicTacToe::showInstructions() {
    std::cout << "\nChoose a cell numbered from 1 to 9 as below and play\n\n";
    std::cout << "\t\t\t 1 | 2 | 3 \n";
    std::cout << "\t\t\t-----------\n";
    std::cout << "\t\t\t 4 | 5 | 6 \n";
    std::cout << "\t\t\t-----------\n";
    std::cout << "\t\t\t 7 | 8 | 9 \n\n";
}

// Prints the current state of the board
void TicTacToe::showBoard() {
    for (int i = 0; i < size; ++i) {
        std::cout << "\t\t\t ";
        for (int j = 0; j < size; ++j) {
            std::cout << board[i][j];
            if (j < size - 1) std::cout << " | ";
        }
        std::cout << "\n";
        if (i < size - 1) std::cout << "\t\t\t-----------\n";
    }
    std::cout << "\n";
}

// Resets the board to empty spaces
void TicTacToe::resetBoard() {
    for (auto& row : board)
        std::fill(row.begin(), row.end(), ' ');
}

// Checks if any row has the same non-empty symbol (win condition)
bool TicTacToe::rowCrossed() {
    for (int i = 0; i < size; i++)
        if (board[i][0] == board[i][1] &&
            board[i][1] == board[i][2] &&
            board[i][0] != ' ')
            return true;
    return false;
}

// Checks if any column has the same non-empty symbol (win condition)
bool TicTacToe::columnCrossed() {
    for (int i = 0; i < size; i++)
        if (board[0][i] == board[1][i] &&
            board[1][i] == board[2][i] &&
            board[0][i] != ' ')
            return true;
    return false;
}

// Checks if any diagonal has the same non-empty symbol (win condition)
bool TicTacToe::diagonalCrossed() {
    if (board[0][0] == board[1][1] &&
        board[1][1] == board[2][2] &&
        board[0][0] != ' ')
        return true;
    if (board[0][2] == board[1][1] &&
        board[1][1] == board[2][0] &&
        board[0][2] != ' ')
        return true;
    return false;
}

// Returns true if the game is over (win condition met)
bool TicTacToe::gameOver() {
    return rowCrossed() || columnCrossed() || diagonalCrossed();
}

// Minimax algorithm with alpha-beta pruning for AI move calculation
int TicTacToe::minimax(int depth, bool isAI, int alpha, int beta) {
    if (gameOver()) return isAI ? -1 : 1;
    if (depth == size * size) return 0;

    if (isAI) {
        int bestScore = -999;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = AI_MOVE;
                    int score = minimax(depth + 1, false, alpha, beta);
                    board[i][j] = ' ';
                    bestScore = std::max(score, bestScore);
                    alpha = std::max(alpha, score);
                    if (beta <= alpha)
                        return bestScore;
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 999;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = HUMAN_MOVE;
                    int score = minimax(depth + 1, true, alpha, beta);
                    board[i][j] = ' ';
                    bestScore = std::min(score, bestScore);
                    beta = std::min(beta, score);
                    if (beta <= alpha)
                        return bestScore;
                }
            }
        }
        return bestScore;
    }
}

// Finds the best move for the AI using minimax
int TicTacToe::bestMove(int moveIndex) {
    int bestScore = -999, move = -1;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = AI_MOVE;
                int score = minimax(moveIndex + 1, false, -999, 999);
                board[i][j] = ' ';
                if (score > bestScore) {
                    bestScore = score;
                    move = i * size + j;
                }
            }
        }
    }
    return move;
}

// Returns the current date and time as a string
std::string TicTacToe::currentDateTime() {
    time_t now = time(0);
    char* dt = ctime(&now);
    return std::string(dt);
}

// Plays a single game between the player and the AI
void TicTacToe::playSingleGame(bool playerStarts) {
    resetBoard();
    int moveIndex = 0;
    bool isAITurn = !playerStarts;
    showBoard();

    while (!gameOver() && moveIndex < size * size) {
        if (isAITurn) {
            int move = bestMove(moveIndex);
            int x = move / size, y = move % size;
            board[x][y] = AI_MOVE;
            std::cout << "AI has put a " << AI_MOVE << " in cell " << (move + 1) << "\n\n";
        } else {
            int cell;
            std::cout << "Available positions: ";
            for (int i = 0; i < size * size; ++i)
                if (board[i / size][i % size] == ' ')
                    std::cout << i + 1 << " ";
            std::cout << "\nEnter position: ";
            std::cin >> cell;
            cell--;
            int x = cell / size, y = cell % size;
            if (cell >= 0 && cell < size * size && board[x][y] == ' ')
                board[x][y] = HUMAN_MOVE;
            else {
                std::cout << "Invalid or occupied cell. Try again.\n";
                continue;
            }
        }
        moveIndex++;
        showBoard();
        if(gameOver()) break;
        isAITurn = !isAITurn;
    }

    if (!gameOver())
        std::cout << "It's a draw\n";
    else {
        bool aiWon = isAITurn;
        if (aiWon) {
            aiScore++;
            std::cout << "AI has won this match.\n";
        } else {
            playerScore++;
            std::cout << "You have won this match.\n";
        }
    }
}

// Logs the result of a tournament to a file
void TicTacToe::logTournamentResult(int player, int ai, int totalMatches) {
    std::ofstream logFile("game_log.txt", std::ios::app);
    if (!logFile) {
        std::cout << "Error opening log file.\n";
        return;
    }
    logFile << "Tournament Started: " << currentDateTime();
    logFile << "Match Format: Best of " << totalMatches << "\n";
    logFile << "Final Score => You: " << player << " | AI: " << ai << "\n";
    logFile << "Winner: " << (player > ai ? "You" : (player < ai) ? "AI" : "Draw") << "\n";
    logFile << "----------------------------------------\n";
    logFile.close();
}

// Manages the tournament flow and user interaction
void TicTacToe::playTournament() {
    std::cout << "\nChoose tournament format (best of 3/5/7/10 or a single match): ";
    int totalMatches;
    std::cin >> totalMatches;

    showInstructions();

    int originalMatches = totalMatches;
    while (totalMatches--) {
        char first;
        std::cout << "\nDo you want to start first this match? (y/n): ";
        std::cin >> first;
        playSingleGame(first == 'y');
        std::cout << "Score => You: " << playerScore << " | AI: " << aiScore << "\n";
    }

    if (playerScore > aiScore)
        std::cout << "\nCongratulations! You won the tournament.\n";
    else if(playerScore == aiScore)
        std::cout << "\nSurprised right! Tournament ends in a draw.\n";
    else
        std::cout << "\nAI won the tournament. Better luck next time!\n";

    logTournamentResult(playerScore, aiScore, originalMatches);

    playerScore = aiScore = 0;
}