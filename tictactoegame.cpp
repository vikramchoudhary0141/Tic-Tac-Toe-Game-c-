#include <iostream>
using namespace std;
class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    void initializeBoard() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                board[i][j] = '1' + 3 * i + j; // Filling the board with numbers 1-9
            }
        }
    }
    void displayBoard() const {
        cout << "Current Board: \n";
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << board[i][j];
                if (j < 2) cout << " | ";
            }
            cout << "\n";
            if (i < 2) cout << "--|---|--\n";
        }
    }
    bool isValidMove(int row, int col) const {
        return (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] != 'X' && board[row][col] != 'O');
    }
    bool checkWin() const {
        for (int i = 0; i < 3; i++) {
            if ((board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
                (board[0][i] == board[1][i] && board[1][i] == board[2][i])) {
                return true;
            }
        }
        // Check diagonals
        if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[1][1] == board[2][0])) {
            return true;
        }
        return false;
    }
    // Function to check if the board is full
    bool isBoardFull() const {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] != 'X' && board[i][j] != 'O') {
                    return false;
                }
            }
        }
        return true;
    }
public:
    TicTacToe() : currentPlayer('X') {
        initializeBoard();
    }
    // Function to switch player turns
    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    // Function to play the game
    void playGame() {
        int move;
        bool gameWon = false;
        while (!gameWon && !isBoardFull()) {
            displayBoard();
            cout << "Player " << currentPlayer << ", enter your move (1-9): ";
            cin >> move;
            int row = (move - 1) / 3;
            int col = (move - 1) % 3;
            if (isValidMove(row, col)) {
                board[row][col] = currentPlayer;
                gameWon = checkWin();
                if (!gameWon) {
                    switchPlayer();
                }
            } else {
                cout << "Invalid move! Try again.\n";
            }
        }
        displayBoard();

        if (gameWon) {
            cout << "Player " << currentPlayer << " wins!\n";
        } else {
            cout << "It's a draw!\n";
        }
    }
};
int main() {
    TicTacToe game;
    game.playGame();
    return 0;
}