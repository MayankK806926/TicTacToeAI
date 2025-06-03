// main.cpp - Entry point for the Tic-Tac-Toe Tournament application
// Includes the TicTacToe class and manages the main game loop
#include "../include/TicTacToe.h"

int main() {
    // Print welcome banner
    std::cout << "\n-------------------------------------------------------------------\n\n";
    std::cout << "\t\tWelcome to Tic-Tac-Toe Tournament\n";
    std::cout << "\n-------------------------------------------------------------------\n\n";

    TicTacToe game; // Create a TicTacToe game instance
    char playAgain = 'y'; // Variable to control tournament replay
    while (playAgain == 'y') {
        game.playTournament(); // Start a new tournament
        std::cout << "\nDo you want to play another tournament? (y/n): ";
        std::cin >> playAgain; // Get user input to play again
    }

    std::cout << "\nThanks for playing!\n"; // Farewell message
    return 0;
}