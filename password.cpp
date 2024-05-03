#include <iostream>
#include <conio.h>
using namespace std;

bool Password_valid(const char* password_array) {
    int length = 0;
    int upper_case = 0;
    int lower_case = 0;
    int digit = 0;

    while (password_array[length] != '\0') {
        char c = password_array[length];

        if (isupper(c)) {
            upper_case++;
        }
        else if (islower(c)) {
            lower_case++;
        }
        else if (isdigit(c)) {
            digit++;
        }

        length++;
    }

    if (length < 6) {
        cout << "Password must contain 6 or more characters. Please try again." << endl;
        return false;
    }

    if (upper_case == 0 || lower_case == 0 || digit == 0) {
        cout << "Password must contain at least one uppercase letter, one lowercase letter, and one digit." << endl;
        return false;
    }

    return true;
}

void hide_password(char* password_array, int size) {
    int i = 0;
    while (i < size - 1) {
        char input_char = _getch(); // Use _getch() to hide characters on screen

        if (input_char == 13) {
            break;
        }

        if (input_char == '\b' && i > 0) {
            // Clear the screen
            cout << "\b \b";
            i--;
        }
        else {
            password_array[i++] = input_char;
            cout << '*';
        }
    }

    password_array[i] = '\0';
}

int main() {
    char password_array[50] = {};

    bool valid = false;
    while (!valid) {
        cout << "\nEnter your password: ";
        hide_password(password_array, sizeof(password_array));

        cout << "\nYou entered: " << password_array << endl;

        if (Password_valid(password_array)) {
            cout << "\nPassword is valid." << endl;
            valid = true;
        }
        else {
            cout << "\nPassword is not valid. Do you want to enter the password again? (yes/no): ";
            string choice;
            cin >> choice;
            if (choice == "no")
            {
                break;
            }
        }
    }

    return 0;
}