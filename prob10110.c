#include <stdio.h>
#include <math.h>
#define PI acos(-1)

int primos[50000];
int num;

void crivo(int max) {
    int i, j;
    int sim;

    primos[0] = 2;
    num = 1;

    for (i = 3; i <= max; i++) {
        sim = 1;
        for (j = 0; j < num; j++) {
            if (i % primos[j] == 0) {
                sim = 0;
                break;
            }
        }
        if (sim == 1) {
            primos[num++] = i;
        }
    }
    return;
}

int main(void) {
    long long int n;
    int par;
    int aux;
    int i;

    crivo(65536);

    //printf("num = %d\n", num);

    scanf(" %lld", &n);

    while(n != 0) {
        par = 1;
        for (i = 0; i < num && n != 1; i++) {
            aux = 0;
            /* printf("n = %d\n", n); */
            while(n % primos[i] == 0) {
                n /= primos[i];
                aux++;
            }
            if (aux != 0 && (aux + 1) % 2 == 0) {
                par = 0;
                break;
            }
        }
        if (n != 1) {
            par = 0;
        }
        if (par == 0) {
            printf("no\n");
        } else {
            printf("yes\n");
        }
        scanf(" %lld", &n);
    }
    return 0;
}