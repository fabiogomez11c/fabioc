#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int n;
    // scanf("%d", &n);
    n = 10564;
    //Complete the code to calculate the sum of the five digits on n.
    int cum = 0;
    int mod;
    int div;
    int divisor = 10000;

    mod = n;
    for (int i=1; i < 7; i++){
        // get the first number
        div = mod / divisor;
        // get the modulus
        mod = mod % divisor;
        // udpate divisor
        divisor = divisor/10;
        // update cum sum
        cum += div;
    }


    printf("%d", cum);

    return 0;
}