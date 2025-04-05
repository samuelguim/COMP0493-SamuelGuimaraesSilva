#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double A, B, C;
    cout << "Digite os coeficientes A, B, C da reta (Ax + By + C = 0): ";
    cin >> A >> B >> C;

    double x0, y0;
    cout << "Digite as coordenadas do ponto (x0, y0): ";
    cin >> x0 >> y0;

    // Verifica se a reta é válida (A e B não podem ser ambos zero)
    if (A == 0 && B == 0) {
        cout << "Coeficientes inválidos. A e B não podem ser ambos zero." << endl;
        return 1;
    }
    
    // Cálculo do numerador da fórmula (valor absoluto)
    double numerador = fabs(A * x0 + B * y0 + C);
    // Cálculo do denominador da fórmula (raiz quadrada da soma dos quadrados de A e B)
    double denominador = sqrt(A * A + B * B);

    double distancia = numerador / denominador;

    cout << "A distancia entre o ponto e a reta é: " << distancia << endl;
    
    return 0;
}
