#include <iostream>
#include <vector>

// Função para mesclar duas metades ordenadas do array
void merge(std::vector<int>& arr, int left, int mid, int right) {
    // Calcula o tamanho dos subarrays
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    // Cria arrays temporários
    std::vector<int> L(n1);
    std::vector<int> R(n2);
    
    // Copia os dados para os arrays temporários
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    
    // Índices iniciais dos subarrays e do array principal
    int i = 0;    // Índice inicial do primeiro subarray
    int j = 0;    // Índice inicial do segundo subarray
    int k = left; // Índice inicial do array mesclado
    
    // Mescla os arrays temporários de volta no array principal
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    // Copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    // Copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Função principal do Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right) {
    if (left < right) {
        // Encontra o ponto médio
        int mid = left + (right - left) / 2;
        
        // Ordena a primeira e a segunda metade
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        // Mescla as metades ordenadas
        merge(arr, left, mid, right);
    }
}

// Função auxiliar para imprimir o array
void printArray(const std::vector<int>& arr) {
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

int main() {
    // Casos de teste
    std::vector<std::vector<int>> testCases = {
        {64, 34, 25, 12, 22, 11, 90},           // Array aleatório
        {1, 2, 3, 4, 5},                        // Array já ordenado
        {5, 4, 3, 2, 1},                        // Array inversamente ordenado
        {1},                                     // Array com um elemento
        {2, 2, 1, 1, 3, 3},                     // Array com elementos repetidos
        {}                                       // Array vazio
    };
    
    for (int i = 0; i < testCases.size(); i++) {
        std::vector<int> arr = testCases[i];
        std::cout << "\nCaso de teste " << i + 1 << ":\n";
        std::cout << "Array original: ";
        printArray(arr);
        
        mergeSort(arr, 0, arr.size() - 1);
        
        std::cout << "Array ordenado: ";
        printArray(arr);
    }
    
    return 0;
}