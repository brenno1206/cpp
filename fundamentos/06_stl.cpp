#include <iostream>
#include <algorithm>
#include <vector>
#include <format>

struct Membro {
    std::string nome;
    int nivel;
    Membro(const std::string& MNome, int MNivel) : nome{MNome}, nivel{MNivel} {}
    void imprimir() const {
        std::cout << std::format("Nome: {}, Nivel: {}.\n", nome, nivel);
    }
};

int main() {
    std::vector <Membro> membros{
        Membro{"Arthur", 50},
        Membro{"Bia", 12},
        Membro{"Carlos", 80},
        Membro{"Daniela", 30},
        Membro{"Eduardo", 5},
    };
    std::sort(membros.begin(), membros.end(), [](const Membro& a, const Membro& b) {
        return a.nivel > b.nivel;
    });

    for (const auto& membro : membros) {
        membro.imprimir();
    }
    int levelEspecial = 70;
    auto resultado = std::find_if(membros.begin(), membros.end(), [levelEspecial](const Membro& m) {
        return m.nivel > levelEspecial;
    });
    if (resultado != membros.end()) {
        std::cout << std::format("Usuario com nivel > {}: {} - Nivel {}.\n", levelEspecial, resultado->nome, resultado->nivel);
    } else {
        std::cout << std::format("Nao ha nenhum membro cadastrado com o level maior que {}.\n", levelEspecial);
    }
    return 0;
}