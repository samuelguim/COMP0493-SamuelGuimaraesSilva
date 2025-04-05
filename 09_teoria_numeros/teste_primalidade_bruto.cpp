#include <iostream>
#include <cmath>
using namespace std;

bool ehPrimoForcaBruta(int n) {
    // Verificação para números menores que 2 (não são primos)
    if (n <= 1) return false;
    
    // Verifica divisibilidade por todos os números de 2 até n-1
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false; // Encontrou um divisor
        }
    }
    
    return true; // Não encontrou divisores, é primo
}

int main() {
    int numero;
    cout << "Digite um número para verificar se é primo (força bruta): ";
    cin >> numero;
    
    if (ehPrimoForcaBruta(numero)) {
        cout << numero << " é primo." << endl;
    } else {
        cout << numero << " não é primo." << endl;
    }
    
    return 0;
}