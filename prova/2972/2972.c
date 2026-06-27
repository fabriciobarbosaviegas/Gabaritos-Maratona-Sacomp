#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);

    int bits = 0;

    while (n) {
        bits += n & 1;
        n >>= 1;
    }

    printf("%lld\n", 1LL << bits);

    return 0;
}