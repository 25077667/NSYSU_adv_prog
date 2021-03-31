#include <bits/stdc++.h>
using namespace std;

#define NOUN "(tom|jerry|goofy|mickey|jimmy|dog|cat|mouse)"
#define VERB "(hate|love|know|like)s*"
#define ARTICLE "(a|the)"
#define ACTOR  "(" NOUN "|" ARTICLE " " NOUN ")"
#define ACTIVE_LIST "(" ACTOR " and )*" ACTOR
#define ACTION  ACTIVE_LIST " "  VERB  " " ACTIVE_LIST
#define STATEMENT  ACTION "( , " ACTION ")*"
// string macros


int main()
{
    regex re(STATEMENT);
    string line;
    while (getline(cin, line)) {
        if (regex_match(line.data(), re))
            cout << "YES I WILL" << endl;
        else
            cout << "NO I WON'T" << endl;
    }
    return 0;
}
