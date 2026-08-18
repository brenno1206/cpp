#include <iostream>
#include <string>
#include <format>
/**
 * Adicionar:
 * Friend/Class Function
 * ENUM
 * Heranca multipla
 */
class Inimigo {
private:
    std::string nome;
protected:
    int vida;
public:
    Inimigo(const std::string& INome, int IVida = 50) : nome{INome}, vida{IVida}{}
    virtual ~Inimigo() = default;

    virtual void receberDano(int quantidade){
        if(vida > quantidade) {
            vida-=quantidade;
            std::cout << std::format("{} recebeu {} de dano. Vida restante: {}.\n", nome, quantidade, vida);
        } else if (vida == 0) {
            std::cout << std::format("{}. Ele ja foi eliminado.\n", nome);
        } else {
            vida = 0;
            std::cout << std::format("{} recebeu {} de dano. {} morreu.\n", nome, quantidade, nome);
        }
    }
    int getVida() const {
        return vida;
    }
    std::string getNome() const {
        return nome;
    }
};

class Chefe : public Inimigo {
public:
    Chefe() : Inimigo("Rei Orc", 200){
        vida = 200;
    }

    void receberDano(int quantidade) override {
        quantidade /= 2;
        Inimigo::receberDano(quantidade);
    }
};



class Jogador {
private:
    std::string nome;
    int vida;
    int estamina;

public:
    Jogador(const std::string& nomeJogador)
    : nome{nomeJogador}, vida{100}, estamina{50}
    {
        std::cout << std::format("{} Foi criado!\n", nome);
    }

    ~Jogador() {
        std::cout << std::format("{} Foi destruido!\n", nome);
    }

    void atacar(Inimigo& inimigo) {
        if (estamina >= 10){
            estamina -=10;
            std::cout << std::format("{} atacou ", nome);
            inimigo.receberDano(15);
            std::cout << std::format("{} tem {} de estamina restante.\n", nome, estamina);
        } else {
            std::cout << std::format("{} esta muito cansado para atacar!\n", nome);
        }
    }

    std::string getNome() const {
        return nome;
    }
};


int main() {
    std::cout << "--- Inicio do Escopo ---\n";
    {
        Chefe inimigo;
        Jogador player{"Ana"};
        player.atacar(inimigo);
        player.atacar(inimigo);
        player.atacar(inimigo);
        player.atacar(inimigo);
        player.atacar(inimigo);
    } 
    
    std::cout << "--- Fim do Escopo ---\n";
    return 0;
}