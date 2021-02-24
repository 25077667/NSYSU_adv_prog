#include <ctype.h>
#include <math.h>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
using namespace std;
struct data {
    int m, s, t;
} d[1000];

int main()
{
    char wrong[] = "1234567890-=WERTYUIOP[]\\SDFGHJKL;'XCVBNM,./";
    char right[] = "`1234567890-QWERTYUIOP[]ASDFGHJKL;ZXCVBNM,.";
    map<char, char> t;
    for (int i = 0; i < strlen(wrong); i++)
        t[wrong[i]] = right[i];
    char a;
    while ((a = getchar()) != EOF)
        (t.find(a) != t.end()) ? putchar(t[a]) : putchar(a);



    return 0;
}
