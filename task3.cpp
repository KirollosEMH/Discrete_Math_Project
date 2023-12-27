#include <iostream>
#include <string>

using namespace std;


// Scottish Gaelic: " A, B, C, D, E, F, G, H, I, L, M, N, O, P, R, S, T, U "

// Affine Cipher
string affineCipher(const string& text)
{
    string cipheredText = "";

    // Ciphering Coefficients
    int a = 5, b = 8;

    // Alphabet
    const char Alphabet[19][2]
    {
        // Alphabet: A, B, C, D, E, F, G, H, I, L, M, N, O, P, R, S, T, U
        {' ',0}, {'A',1}, {'B',2}, {'C',3}, {'D',4}, {'E',5}, {'F',6}, {'G',7}, {'H',8}, {'I',9}, {'L',10}, {'M',11},
        {'N',12}, {'O',13}, {'P',14}, {'R',15}, {'S',16}, {'T',17}, {'U',18}
    };

    for (char c : text)
    {
        // Looping through the alphabet
        for (int i = 0; i < 19; i++)
        {
            // Checking if the current letter is in the alphabet
            if (c == Alphabet[i][0])
            {
                // Ciphering formula: E(x) = (ax + b) mod 19
                int x = (a * Alphabet[i][1] + b) % 19;
                // Adding ciphered letter to the ciphered text
                cipheredText += Alphabet[x][0];
            }
        }
    }

    return cipheredText;
}

// Affine Cipher Extended
string affineCipherExtended(const string& text)
{
    string cipheredText = "";

    // Ciphering Coefficients
    int a = 8, b = 4;

    // Alphabet
    const char Alphabet[77][2]
    {
        // Alphabet: A, B, C, D, E, F, G, H, I, L, M, N, O, P, R, S, T, U
        {' ',0}, {'A',1}, {'B',2}, {'C',3}, {'D',4}, {'E',5}, {'F',6}, {'G',7}, {'H',8}, {'I',9}, {'L',10}, {'M',11},
        {'N',12}, {'O',13}, {'P',14}, {'R',15}, {'S',16}, {'T',17}, {'U',18},{'a',19}, {'b',20}, {'c',21}, {'d',22},
        {'e',23}, {'f',24}, {'g',25}, {'h',26}, {'i',27}, {'l',28}, {'m',29}, {'n',30}, {'o',31}, {'p',32}, {'r',33},
        {'s',34}, {'t',35}, {'u',36},{'1',37}, {'2',38}, {'3',39}, {'4',40}, {'5',41}, {'6',42}, {'7',43}, {'8',44},
        {'9',45}, {'0',46},{'.',47}, {',',48}, {'!',49}, {'?',50}, {'-',51}, {'_',52}, {'@',53}, {'#',54}, {'$',55},
        {'%',56}, {'&',57}, {'*',58}, {'(',59}, {')',60}, {'+',61}, {'=',62}, {'/',63}, {'<',64}, {'>',65}, {'[',66},
        {']',67}, {'{',68}, {'}',69}, {'|',70}, {'^',71}, {'~',72}, {'`',73}, {';',74}, {':',75}, {'"',76}
    };


    // Looping through the text
    for (char c : text)
    {

        // Looping through the alphabet
        for (int i = 0; i < 77; i++)
        {
            // Checking if the current letter is in the alphabet
            if (c == Alphabet[i][0])
            {
                // Ciphering formula: E(x) = (ax + b) mod 77
                int x = (a * Alphabet[i][1] + b) % 77;
                // Adding ciphered letter to the ciphered text
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

    // Scottish Gaelic: "THA GAOL AGAM AIR MATAMATAIG"
    // Given text
    cout << "====================== Given Sentence ======================" << endl;
    string givenText = "THA GAOL AGAM AIR MATAMATAIG";
    cout << "Given text: " << givenText << endl;
    cout << "Ciphered text: " << affineCipher(givenText) << endl;
    cout << "Ciphered text Extended: " << affineCipherExtended(givenText) << endl << endl;


    // User input
    cout << "====================== User Input ======================" << endl;
    cout << "Enter text to cipher: ";
    getline(cin, origText);
    cout << "Ciphered text: " << affineCipher(origText) << endl;
    cout << "Ciphered text Extended: " << affineCipherExtended(origText) << endl << endl;


    return 0;
}

