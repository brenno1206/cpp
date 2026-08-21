#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <format>

int main() {
    std::vector<std::string> saque{"Moeda", "Pocao", "Moeda", "Espada", "Moeda", "Pocao", "Escudo"};
    std::map<std::string, int> inventario_final;
    int i = 0;
    for(const auto& item : saque) {
        inventario_final[item]++;
    }

    for(const auto& [chave, valor] : inventario_final) {
        std::cout << std::format("{} : {}\n", chave, valor);
    }
    return 0;
}