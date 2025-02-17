#include <iostream>
#include <vector>
#include <algorithm>

// Função auxiliar para encontrar o maior número no array
int getMax(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

// Função auxiliar para realizar o counting sort para cada dígito
void countingSortByDigit(std::vector<int>& arr, int exp) {
    const int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0);  // Array para contar os dígitos (0-9)

    // Conta a frequência de cada dígito na posição atual
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calcula as posições finais dos elementos
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Constrói o array de saída
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copia o array ordenado de volta para o array original
    arr = output;
}

void radixSort(std::vector<int>& arr) {
    if (arr.empty()) {
        return;
    }

    // Encontra o maior número para saber o número de dígitos
    int max_val = getMax(arr);

    // Realiza o counting sort para cada dígito
    // exp é 10^i onde i é a posição atual do dígito
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        countingSortByDigit(arr, exp);
    }
}

// Função auxiliar para imprimir o array
void printArray(const std::vector<int>& arr, const std::string& message) {
    std::cout << message;
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    // Teste com um array de exemplo
    std::vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};
    
    printArray(arr, "Array original: ");
    radixSort(arr);
    printArray(arr, "Array ordenado: ");

    return 0;
}