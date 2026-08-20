#include <iostream>
#include <stdexcept>
#include <string>
#include <optional>
#include <vector>
#include <format>
#include <algorithm>

std::optional<int> buscarMembro(const std::string& nome) {
    std::vector<std::string> membros{"Ana", "Bruno", "Carlos"};
    auto membro = std::find_if(membros.begin(), membros.end(), [&nome](const auto& m) {
        return m == nome;
    });
    if (membro != membros.end()) {
        return 100;
    }
    
    return std::nullopt;
}

double dividirOuro(double ouroTotal, int participantes) {
    if (participantes <= 0) {
        throw std::invalid_argument("Numero de participantes invalido!");
    } 
    return ouroTotal / participantes;
}

int main() {
    auto m = buscarMembro("Dath Vader");
    if (m) {
        std::cout << std::format("Membro encontrado, {}.\n", m.value());
    } else {
        std::cout << "Membro nao encontrado.\n";
    }
    try
    {
        dividirOuro(1000.0,0);
        std::cout << "Dividiu o ouro";
    }
    catch(const std::exception& e)
    {
        std::cerr << std::format("Erro no sistema da guilda: {}\n", e.what());
    }
    
}