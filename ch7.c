#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int cum = 0;
    int mod;
    int div;
    int divisor = 10;

    mod = n;
    for (int i=1; i < 6; i++){
        // get the last number
        div = mod % divisor;
        // get the modulus
        mod = mod / divisor;
        // update cum sum
        cum += div;
    }


    printf("%d", cum);

    return 0;
}