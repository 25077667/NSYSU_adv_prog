#include <bits/stdc++.h>
using namespace std;

const string NOUN("(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)");
const string VERB("(hate|love|know|like)s*");
const string ARTICLE("(a|the)");
const string ACTOR = "(" + NOUN + "|" + ARTICLE + " " + NOUN + ")";
const string ACTIVE_LIST = "(" + ACTOR + " and )*" + ACTOR;
const string ACTION = ACTIVE_LIST + " " + VERB + " " + ACTIVE_LIST;
const string STATEMENT = ACTION + "( , " + ACTION + ")*";

int main()
{
    regex re(STATEMENT);
    string line;
    while (getline(cin, line)) {
        stringstream ss;
        ss << line;
        if (regex_match(line.data(), re))
            cout << "YES I WILL" << endl;
        else
            cout << "NO I WON'T" << endl;
    }
    return 0;
}