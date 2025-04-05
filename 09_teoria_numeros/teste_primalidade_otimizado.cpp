#include <iostream>
#include <cmath>
using namespace std;

bool ehPrimoOtimizado(int n) {
    // Verificação para números menores que 2 ou pares (exceto 2)
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    
    // Verifica apenas divisores ímpares até a raiz quadrada de n
    int limite = sqrt(n);
    for (int i = 3; i <= limite; i += 2) {
        if (n % i == 0) {
            return false; // Encontrou um divisor
        }
    }
    
    return true; // Não encontrou divisores, é primo
}

int main() {
    int numero;
    cout << "Digite um número para verificar se é primo (otimizado): ";
    cin >> numero;
    
    if (ehPrimoOtimizado(numero)) {
        cout << numero << " é primo." << endl;
    } else {
        cout << numero << " não é primo." << endl;
    }
    
    return 0;
}