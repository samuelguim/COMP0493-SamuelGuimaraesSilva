#include <iostream>
#include <cmath> // Para a função pow e a constante M_PI

using namespace std;

int main() {
    double raio;
    
    cout << "Digite o valor do raio da seção transversal: ";
    cin >> raio;
    
    if (raio < 0) {
        cout << "O valor do raio deve ser positivo." << endl;
        return 1;
    }
    
    double area = M_PI * pow(raio, 2);
    
    cout << "A área da seção transversal é: " << area << " unidades quadradas." << endl;
    
    return 0;
}
