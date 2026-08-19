#include <iostream>
#include <string>

template <typename T>
void imprimirVetor(const std::vector<T>& vetor){
    for (const auto& elemento : vetor) {
        std::cout << elemento << ", ";
    }
    std::cout << '\n';
}

int main(){
    std::vector<int> vet1{1,2,3,4};
    std::vector<std::string> vet2{"Mago", "Guerreiro", "Arqueiro"};

    imprimirVetor(vet1);
    imprimirVetor(vet2);
    return 0;
}