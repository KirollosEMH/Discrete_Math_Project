#include <iostream>
#include <string>

using namespace std;

string affineCipher(const string& text)
{
    string cipheredText = "";
    int a = 8, b = 4;
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

    for (char c : text)
    {
   
        for (int i = 0; i < 77; i++)
        {
            if (c == Alphabet[i][0])
            {
                int x = (a * Alphabet[i][1] + b) % 77;
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

