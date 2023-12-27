#include <iostream> 
#include <string> // For using the string type

using namespace std; 

// Deciphering a text using the Affine cipher
int main() { 
    int alphabet[27] = {' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 
                        'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'}; 
    int a = 0, b = 0;

    // The keys of the cipher are the integers a and b, where a is chosen to be relatively prime to 27
    cout << "Type your Deciphering keys: (a =? & b =?)    "; 

    cin >> a >> b; // Read the keys

    // Find the multiplicative inverse of 'a' in the group of integers modulo 27
    int a_inverse = 0;
    for (int i = 0; i < 27; ++i) { // For each integer in the group of integers modulo 27
        if ((a * i) % 27 == 1) { // If the multiplicative inverse of 'a' is found

            a_inverse = i; // Set the multiplicative inverse of 'a'

            break; 
        }
    }

    cin.ignore(); // Clear the input buffer
    cout << "\nEnter the ciphered text: "; 

    // Read the text to be deciphered
    string text;  
    getline(cin, text); // Read the whole line

    cout << "\nDeciphered text:\n"; 

    int charCount = 0;
    // Decipher the text
    for (char c : text) { // For each character in the text convert the character to an index in the alphabet
        int charIndex = (c == ' ') ? 0 : c - 'A' + 1;  

        int decoded_index = (a_inverse * (charIndex - b + 27)) % 27; // Decipher the character
        cout << static_cast<char>(alphabet[decoded_index]); // Print the deciphered character

    }

    cout << endl; 

    return 0; 
}
