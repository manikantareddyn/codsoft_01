#include <iostream>
using namespace std;

void display(char B[3][3]) {
    for (int i = 0; i < 3; i++) {
        cout << '\t';
        for (int j = 0; j < 3; j++) {
            cout << B[i][j] << "  ";
        }
        cout << endl << endl;
    }
}

bool found_again(char B[3][3], char choice) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (B[i][j] == choice) {
                return true; // Position is available
            }
        }
    }
    return false; // Position not available
}

std::string check_win(char B[3][3], int count) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if ((B[i][0] == B[i][1]) && (B[i][1] == B[i][2]) && B[i][0] != ' ') {
            return B[i][0] == 'X' ? "Player_1" : "Player_2";
        }
        if ((B[0][i] == B[1][i]) && (B[1][i] == B[2][i]) && B[0][i] != ' ') {
            return B[0][i] == 'X' ? "Player_1" : "Player_2";
        }
    }

    // Check diagonals
    if ((B[0][0] == B[1][1]) && (B[1][1] == B[2][2]) && B[0][0] != ' ') {
        return B[0][0] == 'X' ? "Player_1" : "Player_2";
    }
    if ((B[0][2] == B[1][1]) && (B[1][1] == B[2][0]) && B[0][2] != ' ') {
        return B[0][2] == 'X' ? "Player_1" : "Player_2";
    }

    if (count > 8) {
        return "draw";
    }

    return "";
}

typedef char Board[3][3];

int main() {
    Board B = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char choice;
    cout << "Welcome to TIC TAC TOE game" << endl;
    cout << "Player_1 (X)" << endl << "Player_2 (O)" << endl << '\n';
    int count = 1;

    while (count < 10) {
        display(B);
        cout << endl;
        count % 2 != 0 ? cout << "Player_1" : cout << "Player_2";
        cout << " enter your choice: ";
        cin >> choice;

        // Validate input
        if (!(choice >= '1' && choice <= '9') || !found_again(B, choice)) {
            cout << "Invalid input or position already taken! Please enter a correct choice." << endl;
            continue; // Ask for input again
        }

        // Update the board
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (B[i][j] == choice) {
                    B[i][j] = (count % 2 != 0) ? 'X' : 'O'; // Assign X or O
                    break; // Exit the inner loop once the move is made
                }
            }
        }

        // Check for win or draw
        std::string result = check_win(B, count);
        if (result != "") {
            if (result == "draw") {
                cout << endl << "\t\t" << result << " Match" << endl;
            } else {
                cout << endl << "\t\t" << result << " Won the Match!" << endl;
            }
            break;
        }

        count++;
    }

    return 0;
}
