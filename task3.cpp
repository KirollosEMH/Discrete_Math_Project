#include <iostream>
#include <string>

using namespace std;

string affineCipher(const string& text)
{
    string cipheredText = "";
    int a = 8, b = 4;
    const char Alphabet[18][2]
    {
        // Alphabet: A, B, C, D, E, F, G, H, I, L, M, N, O, P, R, S, T, U
        {'A', 0}, {'B', 1}, {'C', 2}, {'D', 3}, {'E', 4}, {'F', 5}, {'G', 6}, {'H', 7}, {'I', 8}, {'L', 9}, {'M', 10},
         {'N', 11}, {'O', 12}, {'P', 13}, {'R', 14}, {'S', 15}, {'T', 16}, {'U', 17}
    };

    for (char c : text)
    {
        if (c == ' ')
        {
            cipheredText += ' ';
            continue;
        }
        
        for (int i = 0; i < 18; i++)
        {
            if (c == Alphabet[i][0])
            {
                int x = (a * Alphabet[i][1] + b) % 18;
                cipheredText += Alphabet[x][0];
            }
        } 
    }

    return cipheredText;
}

int main()
{
    string origText;
    string cipheredText;

    cout << "Enter text to cipher: ";
    getline(cin, origText);

    cipheredText = affineCipher(origText);

    cout << "Ciphered text: " << cipheredText << endl;

    return 0;
}

