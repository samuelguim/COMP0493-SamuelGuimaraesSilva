#include <iostream>

int main(){
    int TC;
    scanf("%d", &TC); // número de casos teste
    while (TC--) { // repetir até 0
        int a, b; scanf("%d %d", &a, &b);
        printf("%d\n", a+b);
    }

    int a, b;
    // para quando os dois inteiros são 0
    while (scanf("%d %d", &a, &b), (a || b)){
        printf("%d\n", a+b);}
    return 0;
}