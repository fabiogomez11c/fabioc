#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max_of_four(int a, int b, int c, int d)
{
    int max_number = a;
    
    if (b > max_number)
        max_number = b;
    if (c > max_number)
        max_number = c;
    if (d > max_number)
        max_number = d;
    
    return max_number;
}

int main()
{
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);

    return 0;
    
}