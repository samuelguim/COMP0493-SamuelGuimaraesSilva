#include <iostream>

int main(){
    while (1) {
        int ans = 0, v;
        char dummy;
        while (scanf("%d%c", &v, &dummy) != EOF) {
            ans += v;
            if (dummy == ’\n’) break;
        }
        if (feof(stdin)) break;
        printf("%d\n", ans);
    }
    return 0;
}