#include <stdio.h>

int climb(int n);

int main() {
    int n = 44, steps;
    steps = climb(n);

    printf("%d",steps);

    return 0;
}

int climb(int n)
{

    int steps[n+1];
    steps[0] = 1;
    steps[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        steps[i] = steps[i-1] + steps[i-2];
    }
    return steps[n];
}

/* 精简代码
int a = 1, b = 1;

while (n--)
{
b += a;
a = b - a;
}
return a;
 */
/*
int climbStairs(int n) {
    int a = 1, b = 1;
    while (n--)
        a = (b += a) - a;
    return a;


}
 */