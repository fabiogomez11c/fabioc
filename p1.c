#include <stdio.h>

int main()
{
    char input[100];
    printf("Enter a line text: ");
    fgets(input, 100, stdin);
    printf("You entered: %s", input);
    return 0;
}
