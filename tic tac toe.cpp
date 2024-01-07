#include <iostream>
using namespace std;

// A 3x3 board of characters
char board[3][3];

// A function to initialize the board with empty spaces
void init_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

// A function to display the board on the screen
void display_board() {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; i++) {
        cout << i << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << "|"; // print vertical lines
        }
        cout << "\n";
        if (i < 2) cout << "  -+-+-\n"; // print horizontal lines
    }
}

// A function to check if a player has won the game
// Returns 'X' if player X has won, 'O' if player O has won, or ' ' if no one has won
char check_winner() {
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }
    // Check columns
    for (int j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return board[0][j];
        }
    }
    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // No winner yet
    return ' ';
}

// A function to check if the board is full
// Returns true if the board is full, false otherwise
bool is_full() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// A function to get the user's input and validate it
// Returns true if the input is valid, false otherwise
bool get_input(char player) {
    int row, col;
    cout << "Player " << player << ", enter your move (row and column): ";
    cin >> row >> col;
    if (row >= 0 && row <= 2 && col >= 0 && col <= 2 && board[row][col] == ' ') {
        // Valid input, mark the board and return true
        board[row][col] = player;
        return true;
    }
    else {
        // Invalid input, show an error message and return false
        cout << "Invalid move, try again.\n";
        return false;
    }
}

// The main function
int main() {
    // Initialize the board
    init_board();

    // The game loop
    char player = 'X'; // The current player, either X or O
    char winner = ' '; // The winner, either X, O, or ' ' for tie
    while (true) {
        // Display the board
        display_board();

        // Get the user's input
        bool valid = get_input(player);
        if (!valid) continue; // If the input is invalid, ask again

        // Check if the game is over
        winner = check_winner();
        if (winner != ' ') break; // If there is a winner, end the game
        if (is_full()) break; // If the board is full, end the game

        // Switch the player
        player = (player == 'X') ? 'O' : 'X';
    }

    // Display the final board
    display_board();

    // Display the result
    if (winner == ' ') {
        cout << "It's a tie!\n";
    }
    else {
        cout << "Player " << winner << " has won the game!\n";
    }

    return 0;
}
