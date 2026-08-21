#include <iostream>
#include <format>
#include <vector>
#include <string>
#include <algorithm>
#include <optional>
#include <memory>

class Personagem {
protected:
    std::string nome;
    int vida;
    int ataqueBase;
public:
    Personagem(const std::string& pNome,int pVida,int pAtaqueBase) : nome{pNome}, vida{pVida}, ataqueBase{pAtaqueBase} {}
    virtual ~Personagem() = default;
    bool isVivo() const {
        return vida > 0;
    }
    std::string getNome() const {
        return nome;
    }
    void receberDano(int dano) {
        if(!this->isVivo()) {
            std::cout << std::format("{} ja morreu.\n", nome);
        } else if(vida <= dano) {
            vida = 0;
            std::cout << std::format("{} recebeu {} de dano. {} Morreu. Vida restante: 0.\n", nome, dano, nome);
        } else {
            vida -=dano;
            std::cout << std::format("{} recebeu {} de dano. Vida restante: {}\n", nome, dano, vida);
        }
    }
    virtual void atacar (Personagem& alvo) = 0;
};

class Guerreiro : public Personagem {
public:
    Guerreiro(const std::string& pNome,int pVida,int pAtaqueBase) : Personagem(pNome, pVida, pAtaqueBase) {}
    void atacar (Personagem& alvo) override {
        std::cout << std::format("Guerreiro {} desfere um golpe de espada contra {}.\n", nome, alvo.getNome());
        alvo.receberDano(ataqueBase + 10);
    }
    void regenerarVida(int cura) {
        if(this->isVivo()) {
            vida+=cura;
            std::cout << std::format("{} curado. Vida atual: {}\n", nome, vida);
        } else {
            std::cout << std::format("{} ja esta morto.\n", nome);
        }
    }
};

class Orc : public Personagem {
public: 
    Orc(const std::string& pNome,int pVida,int pAtaqueBase) : Personagem(pNome, pVida, pAtaqueBase) {}
    void atacar (Personagem& alvo) override {
        std::cout << std::format("Orc {} ataca {} com um machado enferrujado.\n", nome, alvo.getNome());
        alvo.receberDano(ataqueBase);
    }
};

struct Item {
    std::string nome;
    int poderCura;
    Item(const std::string& pNome, int pPoderCura) : nome{pNome}, poderCura{pPoderCura} {}
};

class Inventario {
private:
    std::vector<Item> pocOes;
public:
    Inventario() : pocOes{} {}
    
    void adicionarItem(const std::string& nome, int cura) {
        // pocOes.push_back(Item{nome, cura});
        pocOes.emplace_back(nome, cura);
    }
    std::optional<Item> usarItem(const std::string& nomeBusca) {
        auto it = std::find_if(pocOes.begin(), pocOes.end(), [&nomeBusca](const Item& i) {
            return i.nome == nomeBusca;
        });
        if (it != pocOes.end()) {
            Item item = *it;
            pocOes.erase(it);
            return item;
        }
        return std::nullopt;
    }
};

int main() {
    Guerreiro g{"Heroi", 150, 20};
    Inventario i{};
    i.adicionarItem("Pocao de Vida", 20);
    i.adicionarItem("Pocao Maxima", 50);
    std::vector<std::unique_ptr<Orc>> inimigos{};
    inimigos.push_back(std::make_unique<Orc>("Soldado Orc", 100, 10));
    inimigos.push_back(std::make_unique<Orc>("Mago Orc", 50, 20));
    inimigos.push_back(std::make_unique<Orc>("Chefe Orc", 200, 20));

    g.atacar(*(inimigos.at(0)));
    for(auto& inimigo : inimigos) {
        inimigo->atacar(g);
    }
    auto item1 = i.usarItem("Pocao Maxima");
    if(item1) {
        g.regenerarVida(item1.value().poderCura);
    } else {
        std::cout << std::format("Item Pocao Maxima nao encontrado.");
    }

    auto item2 = i.usarItem("Agua Magica");
    if(item2) {
        g.regenerarVida(item2.value().poderCura);
    } else {
        std::cout << std::format("Item Agua Magica nao encontrado.");
    }

    return 0;
}