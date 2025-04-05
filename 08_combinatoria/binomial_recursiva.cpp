#include <iostream>
using namespace std;

long long fatorial(int n) {
    long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

long long coeficienteBinomialAnalitico(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    
    if (k > n - k) {
        k = n - k;
    }
    
    long long resultado = 1;
    
    for (int i = 0; i < k; i++) {
        resultado *= (n - i);
        resultado /= (i + 1);
    }
    
    return resultado;
}

int main() {
    int n, k;
    
    cout << "Digite o valor de n: ";
    cin >> n;
    
    cout << "Digite o valor de k: ";
    cin >> k;
    
    long long resultado = coeficienteBinomialAnalitico(n, k);
    
    cout << "C(" << n << "," << k << ") = " << resultado << endl;
    
    return 0;
}