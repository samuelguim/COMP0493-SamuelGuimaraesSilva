#include <iostream>
#include <vector>
#include <algorithm>

// Estrutura que representa uma tarefa com tempo de início e término
struct Tarefa {
    int inicio;
    int fim;
};

// Função de comparação para ordenar as tarefas pelo tempo de término
bool compararTarefas(const Tarefa &a, const Tarefa &b) {
    return a.fim < b.fim;
}

int main() {
    int n;
    std::cout << "Digite o número de tarefas: ";
    std::cin >> n;
    
    std::vector<Tarefa> tarefas(n);
    
    // Leitura dos dados das tarefas
    for (int i = 0; i < n; i++) {
        std::cout << "\nTarefa " << i + 1 << ":\n";
        std::cout << "Inicio: ";
        std::cin >> tarefas[i].inicio;
        std::cout << "Fim: ";
        std::cin >> tarefas[i].fim;
    }
    
    // Ordena as tarefas pelo tempo de término
    std::sort(tarefas.begin(), tarefas.end(), compararTarefas);
    
    // Vetor para armazenar as tarefas selecionadas
    std::vector<Tarefa> selecionadas;
    
    // Seleciona a primeira tarefa
    selecionadas.push_back(tarefas[0]);
    int ultimoFim = tarefas[0].fim;
    
    // Itera pelas demais tarefas e seleciona as compatíveis
    for (int i = 1; i < n; i++) {
        if (tarefas[i].inicio >= ultimoFim) {
            selecionadas.push_back(tarefas[i]);
            ultimoFim = tarefas[i].fim;
        }
    }
    
    // Exibe as tarefas selecionadas
    std::cout << "\nTarefas selecionadas:\n";
    for (const auto &t : selecionadas) {
        std::cout << "Inicio: " << t.inicio << " - Fim: " << t.fim << "\n";
    }
    
    return 0;
}
