#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char* get_char(int number_input)
{
    char* number_char;

    if (number_input == 1)
        number_char = "one";
    else if (number_input == 2)
        number_char = "two";
    else if (number_input == 3)
        number_char = "three";
    else if (number_input == 4)
        number_char = "four";
    else if (number_input == 5)
        number_char = "five";
    else if (number_input == 6)
        number_char = "six";
    else if (number_input == 7)
        number_char = "seven";
    else if (number_input == 8)
        number_char = "eight";
    else if (number_input == 9)
        number_char = "nine";
    else if (number_input % 2 == 0 && number_input > 9)
        number_char = "even";
    else if (number_input % 2 != 0 && number_input > 9)
        number_char = "odd";

    return number_char;
}

int main() 
{
    int a, b;
    scanf("%d\n%d", &a, &b);
  	// Complete the code.
    char* number_char;
    for (int i = a; i < b + 1; i++){
        number_char = get_char(i);
        printf("%s\n", number_char);
    }

    return 0;
}

