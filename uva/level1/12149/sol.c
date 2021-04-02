#include <stdio.h>
#include <stdlib.h>
int main()
{
    int input;
    while (scanf("%d", &input) != EOF) {
        if (input == 0)
            break;
        int i, sum = 0;
        for (i = 1; i <= input; i++)
            sum += i * i;
        printf("%d\n", sum);
    }
    return 0;
}
