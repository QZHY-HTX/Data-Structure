#include <stdio.h>
Sum1(int n)
{
    int p = 1, sum = 0, m;
    for (m = 1; m <= n; m++)
    {
        p *= m;
        sum += p;
    }
    return (sum);
}
Sum2(int n)
{
    int sum = 0, p, m, t;
    for (m = 1; m <= n; m++)
    {
        p = 1;
        for (t = 1; t <= m; t++)
            p *= t;
        sum += p;
    }
    return (sum);
}
fact(int n)
{
    if (n <= 1)
        return (1);
    else
        return (n * fact(n - 1));
}
int main()
{
    printf("%d\n", Sum1(5));
    printf("%d\n", Sum2(5));
    printf("%d\n", fact(5));
    return 0;
}