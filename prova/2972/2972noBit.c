#include <stdio.h>

int main(void) {
    long long n;
    scanf("%lld", &n);

    int bits = 0;

    while (n > 0) {
        bits += n % 2;
        n /= 2;
    }

    long long resultado = 1;
    while (bits > 0) {
        resultado *= 2;
        bits--;
    }

    printf("%lld\n", resultado);

    return 0;
}