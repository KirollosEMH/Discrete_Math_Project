#include <iostream>
#include <string>

using namespace std;

// Function to calculate the modular inverse of 'alpha' modulo 'mod'
int calculateModularInverse(int alpha, int mod) {
    alpha = alpha % mod;
    // Check if 'alpha' and 'mod' are relatively prime
    for (int x = 1; x < mod; x++)

    // If 'alpha' and 'mod' are relatively prime, then the modular inverse is 'x'
        if ((alpha * x) % mod == 1)
            return x;

    return -1; // Inverse doesn't exist
}

int main() {
    // Upper Case alphabet array
    int alphabet[27] = { ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

    // Lower Case alphabet array
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

    cin.ignore(); // Ignore the newline character left in the buffer
    cout << "\nEnter the ciphered text: ";

    string text;
    getline(cin, text); // Get the ciphered text

    cout << "\nDeciphered text:\n";
    bool type;
    for (char c : text){ // Loop through each character in the ciphered text
        for (int i = 0; i < 27; i++){ // Loop through each character in the alphabet array 
            // Check if the character is a space
            if (c == ' ') {
                type = type;
                break;
            }
            // Check if the character is an underscore
            if (alphabet[i] == c) {

                type = 1; // Uppercase
                break;
            }
            // Check if the character is an underscore
            if (alphabets[i] == c) {
                type = 0; // Lowercase
                break;
            }
        }
        // Check if the character is a space or underscore
        int charIndex = (c == ' ' || c == '_') ? 0 : toupper(c) - 'A' + 1;
        if ((c == ' ' || c == '_')) { // Space
            charIndex = 0;
        }
        else if (type == 1) { // Uppercase
            charIndex = c - 'A' + 1;
        }
        else if (type == 0) { // Lowercase
            charIndex = c - 'a' + 1;
        }

        if (charIndex >= 0 && charIndex < 27 && type == 1) { // Check if the character is in the alphabet array
            int decoded_index = (a_inverse * (charIndex - b + 27)) % 27; // Calculate the decoded index
            cout << static_cast<char>(alphabet[decoded_index]); // Print the decoded character
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