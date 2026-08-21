#include <iostream>
#include <vector>
#include <format>
#include <limits>

int main() {
    std::vector<std::string> nomes;
    std::vector<double> precos;

    char continuar;
    do {
        std::string nomeProduto;
        double precoProduto;

        std::cout << "\ndigite o nome do produto: ";
        std::cin >> nomeProduto;

        std::cout << "digite o preco do produto: ";
        while (!(std::cin >> precoProduto)) {
            std::cout << "Entrada invalida.\nDigite um preco valido: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        nomes.push_back(nomeProduto);
        precos.push_back(precoProduto);

        std::cout << "Deseja cadastrar outro produto? (s/n): ";
        std::cin >> continuar;
        

    } while(continuar == 'S' || continuar == 's');

    std::cout << "----LISTA DE PRODUTOS----";
    double total{0};

    for(auto i{0}; i < nomes.size(); i++){
        const std::string& nomeProduto{nomes.at(i)};
        double precoProduto{precos.at(i)};

        std::cout << std::format("\nProduto: {}\nPreco: R$ {:.2f}\n", nomeProduto, precoProduto);
    }
    // Geralmente eu pegaria o preco total no loop anterior
    // Mas como estou treinando C++ quero usar o Range based for
    for(double preco : precos) {
        total += preco;
    }

    std::cout << std::format("\nPreco total: {:.2f}", total);

    return 0;
}
