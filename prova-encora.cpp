#include <iostream>
#include <set>
#include <vector>

// Coleta valores do usuário e armazena em um set
void getConjuntos(std::set<int>& A) {
    int qntd, nmr;

    std::cout << "Digite a quantidade de números que deseja inserir: ";

    while (!(std::cin >> qntd) || qntd <= 0) {
        std::cout << "O número deve ser positivo: ";
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    while (A.size() < static_cast<size_t>(qntd)) {
        std::cout << "Digite o " << (A.size() + 1) << "º número: ";
        std::cin >> nmr;

        if (A.count(nmr)) {
            std::cout << "Este número é repetido, digite outro número.\n";
        } else {
            A.insert(nmr);
        }
    }
}

// Gera os subconjuntos deste set
std::vector<std::set<int>> getSubconjuntos(const std::set<int>& A) {
    std::vector<std::set<int>> todosSubconjuntos;
    std::vector<int> elementos(A.begin(), A.end());
    int n = elementos.size();

    for (int i = 0; i < (1 << n); i++) {
        std::set<int> subconjunto;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subconjunto.insert(elementos[j]);
            }
        }
        todosSubconjuntos.push_back(subconjunto);
    }

    return todosSubconjuntos;
}

int main() {
    std::set<int> A;

    getConjuntos(A);

    std::vector<std::set<int>> subconjuntos = getSubconjuntos(A);

    std::cout << "\nOs subconjuntos do conjunto { "; for (int x : A) std::cout << x << " "; std::cout << "} são: \n";
    for (auto& s : subconjuntos) {
        std::cout << "{ ";
        for (int x : s) std::cout << x << " ";
        std::cout << "}" << std::endl;
    }

    return 0;
}