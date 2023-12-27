#include <iostream>
#include <string>

using namespace std;

// Function to calculate the modular inverse of 'alpha' modulo 'mod'
int calculateModularInverse(int alpha, int mod) {
    alpha = alpha % mod;

    for (int x = 1; x < mod; x++)
        if ((alpha * x) % mod == 1)
            return x;

    return -1; // Inverse doesn't exist
}

int main() {
    int alphabet[27] = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
    int alphabets[27] = { ' ', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                        'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    int a = 0, b = 0;

    cout << "Type your Deciphering keys: (a =? & b =?)    ";
    cin >> a >> b;

    // Check if 'a' is relatively prime to 27, if not, request new keys
    while (calculateModularInverse(a, 27) == -1) {
        cout << "Error: 'a' must be relatively prime to 27. Enter new keys: ";
        cin >> a >> b;
    }

    int a_inverse = calculateModularInverse(a, 27); // Find the multiplicative inverse of 'a'

    cin.ignore();
    cout << "\nEnter the ciphered text: ";

    string text;
    getline(cin, text);

    cout << "\nDeciphered text:\n";
    bool type;
    for (char c : text) {
       
        for (int i = 0; i < 27; i++) {
            if (c == ' ') {
                type = type;
                break;
            }
            if (alphabet[i] == c) {

                type = 1; // Uppercase
                break;
            }
            if (alphabets[i] == c) {
                type = 0; // Lowercase
                break;
            }
        }

        int charIndex = (c == ' ' || c == '_') ? 0 : toupper(c) - 'A' + 1;
        if ((c == ' ' || c == '_')) {
            charIndex = 0;
        }
        else if (type == 1) {
            charIndex = c - 'A' + 1;
        }
        else if (type == 0) {
            charIndex = c - 'a' + 1;
        }

        if (charIndex >= 0 && charIndex < 27 && type == 1) {
            int decoded_index = (a_inverse * (charIndex - b + 27)) % 27;
            cout << static_cast<char>(alphabet[decoded_index]);
        }
        else if (charIndex >= 0 && charIndex < 27 && type == 0) {
            int decoded_index = (a_inverse * (charIndex - b + 27)) % 27;
            cout << static_cast<char>(alphabets[decoded_index]);
        }
        else {
            cout << c;
        }
    }

    cout << endl;

    return 0;
}