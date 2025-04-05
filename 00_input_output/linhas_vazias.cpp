#include <iostream>

int main(){
    int a, b, c = 0;
    while (scanf("%d %d", &a, &b) != EOF){
        printf("Case %d: %d\n\n", ++c, a+b);}
    return 0;
}