#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char ch;
    scanf("%c", &ch);
    printf("%c\n", ch);

    char s[100];
    scanf("%99s%*c", s);
    printf("%s\n", s);
    // scanf("\n"); // not needed because I used %*c in the last scanf

    char sen[100];
    scanf("%[^\n]", sen); // read until newline then discard, not need %*c because it is the last scanf
    printf("%s", sen);

    return 0;
}