#include <iostream>

using namespace std;

int main()
{
    string str;
    bool curLetter;
    bool preLetter;

    while (getline(cin, str)) {
        short wordCount = 0;
        preLetter = false;

        int len = str.length();
        for (int i = 0; i < len; i++) {
            curLetter = (str[i] >= 'a' && str[i] <= 'z') ||
                        (str[i] >= 'A' && str[i] <= 'Z');

            if (preLetter && !curLetter)
                wordCount++;

            preLetter = curLetter;
        }

        if (curLetter)
            wordCount++;

        cout << wordCount << endl;
    }

    return 0;
}
