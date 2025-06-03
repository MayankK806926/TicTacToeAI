# Tic-Tac-Toe AI Game

A C++ implementation of Tic-Tac-Toe with an unbeatable AI opponent using the Minimax algorithm with alpha-beta pruning.

## Features

- 🎮 Human vs AI gameplay
- 🏆 Tournament mode (best of 3/5/7/10)
- 📊 Score tracking
- 📝 Game logging to file
- 🤖 Optimal AI moves using Minimax algorithm
- ♟️ Alpha-beta pruning for efficient move calculation

## Directory Structure
```
tic-tac-toe-ai/
├── include/
│ └── TicTacToe.h # Class declaration
├── src/
│ ├── TicTacToe.cpp # Class implementation
│ └── main.cpp # Main game program
└── README.md # This file
```


## Requirements

- C++ compiler (g++ or clang++)
- Linux/MacOS terminal or Windows with WSL

## Installation & Running

### Compilation

1. Compile all source files:
```bash
g++ src/TicTacToe.cpp src/main.cpp -Iinclude -o tic_tac_toe
```
then 
```
tic_tac_toe.exe
```

## How to Play

1. **Choose tournament format**  
   Select from best of 3, 5, 7, 10 matches or a single match:
   ```bash
   Choose tournament format (best of 3/5/7/10 or a single match): 3
   ```
2. **Select starting player**
   Choose who makes the first move each match:
   ```bash
   Do you want to start first this match? (y/n): y
3. **Make your moves**
   When prompted, enter numbers 1-9 corresponding to board positions:
   ```
   1 | 2 | 3
   -----------
   4 | 5 | 6
   -----------
   7 | 8 | 9
   ```
   Example move:
   ```bash
   Available positions: 1 2 3 5 7 8 9
   Enter position: 5
   Game outcome

   Win 3 matches to win a best-of-5 tournament
   ```

   Games can end in win, loss, or draw
💡 Pro Tip: The AI uses perfect strategy - your best hope is a draw!

## Technical Details

| Component               | Implementation Details                        |
|-------------------------|-----------------------------------------------|
| **Algorithm**           | Minimax with alpha-beta pruning               |
| **Search Depth**        | Full game tree (9 plies max)                  |
| **Board Representation**| `vector<vector<char>>` (3×3 grid)             |
| **AI Difficulty**       | Unbeatable (perfect play)                     |
| **Memory Management**   | RAII principles, stack-based allocation       |
| **Time Complexity**     | O(b<sup>d</sup>) with pruning (b ≈ 4, d = 9)  |
| **Space Complexity**    | O(d) for recursion depth                      |

### Key Features

- 📈 **Alpha-beta pruning** reduces search space by ~50%
- ♻️ **Board state reset** between matches
- 📊 **Score persistence** during tournaments
- ⚡ **Efficient move evaluation** (average 50-100ms/move)
- 🔄 **Recursive tree traversal** with depth-first search
