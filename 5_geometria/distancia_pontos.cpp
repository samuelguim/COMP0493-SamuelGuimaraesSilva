#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Declaração das variáveis para as coordenadas dos dois pontos
    double x1, y1, x2, y2;
    
    // Solicita ao usuário as coordenadas do primeiro ponto
    cout << "Digite as coordenadas do primeiro ponto (x1 y1): ";
    cin >> x1 >> y1;
    
    // Solicita ao usuário as coordenadas do segundo ponto
    cout << "Digite as coordenadas do segundo ponto (x2 y2): ";
    cin >> x2 >> y2;
    
    // Calcula as diferenças entre as coordenadas
    double dx = x2 - x1;
    double dy = y2 - y1;
    
    // Calcula a distância utilizando a fórmula da distância euclidiana
    double distancia = sqrt(dx * dx + dy * dy);
    
    // Exibe o resultado
    cout << "A distancia entre os dois pontos e: " << distancia << endl;
    
    return 0;
}
