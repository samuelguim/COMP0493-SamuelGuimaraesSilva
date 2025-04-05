#include <iostream>
using namespace std;

// Algoritmo de Euclides estendido para encontrar coeficientes x, y
// tais que ax + by = mdc(a, b)
int euclidesEstendido(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    
    int x1, y1;
    int mdc = euclidesEstendido(b % a, a, x1, y1);
    
    x = y1 - (b / a) * x1;
    y = x1;
    
    return mdc;
}

// Calcula o inverso modular de a mod m
int inversoModular(int a, int m) {
    int x, y;
    int mdc = euclidesEstendido(a, m, x, y);
    
    // Se o MDC não é 1, então não existe inverso modular
    if (mdc != 1) {
        return -1; // Inverso não existe
    }
    
    // Garante que o resultado seja positivo
    return (x % m + m) % m;
}

int main() {
    int a, m;
    cout << "Digite o valor de a: ";
    cin >> a;
    cout << "Digite o valor de m: ";
    cin >> m;
    
    int inverso = inversoModular(a, m);
    
    if (inverso == -1) {
        cout << "O inverso modular de " << a << " mod " << m << " não existe." << endl;
    } else {
        cout << "O inverso modular de " << a << " mod " << m << " é " << inverso << endl;
        cout << "Verificação: " << a << " * " << inverso << " mod " << m << " = " << ((a * inverso) % m) << endl;
    }
    
    return 0;
}