#include <iostream>
#include <string>

using namespace std;

int main() {
    int alphabet[27] = {0, 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    int a = 0, b = 0;

    cout << "Type your Deciphering keys: a =? & b =? ";
    cin >> a >> b;

    // Find the multiplicative inverse of 'a' in the group of integers modulo 27
    int a_inverse = 0;
    for (int i = 0; i < 27; ++i) {
        if ((a * i) % 27 == 1) {
            a_inverse = i;
            break;
        }
    }

    cin.ignore(); // Clear the input buffer
    cout << "\nEnter the ciphered text: ";
    string text;
    getline(cin, text);

    cout << "\nDeciphered text:\n";

    int charCount = 0;
    for (char c : text) {
        int charIndex = (c == ' ') ? 0 : c - 'A' + 1;

        int decoded_index = (a_inverse * (charIndex - b + 27)) % 27;
        cout << static_cast<char>(alphabet[decoded_index]);

        // Insert a space every 3 characters
        if (++charCount % 3 == 0) {
            cout << " ";
        }
    }

    cout << endl;

    return 0;
}
