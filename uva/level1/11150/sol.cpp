#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    int cola;

    while (cin >> cola) {
        cola = (cola + cola / 2);
        cout << cola << endl;
        //借多少=餘多少
    }

    return 0;
}
