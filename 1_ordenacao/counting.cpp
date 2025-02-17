#include <iostream>
#include <vector>
#include <algorithm>

void countingSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    // Encontra o valor máximo e mínimo do array
    int max_val = *std::max_element(arr.begin(), arr.end());
    int min_val = *std::min_element(arr.begin(), arr.end());

    // Calcula o range dos valores
    int range = max_val - min_val + 1;

    // Cria o array de contagem e o array de saída
    std::vector<int> count(range, 0);
    std::vector<int> output(arr.size());

    // Conta a frequência de cada elemento
    for (int num : arr) {
        count[num - min_val]++;
    }

    // Calcula as posições finais dos elementos
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[count[arr[i] - min_val] - 1] = arr[i];
        count[arr[i] - min_val]--;
    }

    // Copia o array ordenado de volta para o array original
    arr = output;
}

int main() {
    // Teste com um array de exemplo
    std::vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    
    std::cout << "Array original: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    countingSort(arr);

    std::cout << "Array ordenado: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    return 0;
}