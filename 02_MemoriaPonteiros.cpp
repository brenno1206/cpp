#include <iostream>
#include <format>
#include <vector>
#include <string>
// C++ Moderno
#include <memory> // Obrigatório para Smart Pointers

/**
 * STACK
 */
// Recebe apenas para leitura (const) sem copia (&)
void receberDano(const std::string& nome, int& vida){
    vida = vida > 15 ? vida-15 : 0;
    // if (vida > 15) {
    //     vida -= 15;
    // } else {
    //     vida = 0;
    // }
    std::cout << std::format("O jogador {} recebeu dano.\nNova vida: {}", nome, vida);
}

/**
 * HEAP
 */

 // C++ ANTIGO - NÃO USE A MENOS QUE SEJA OBRIGADO
void criarInimigo() {
    // Pede espaço na Heap. 'inimigoVida' é um ponteiro guardando o endereço.
    int* inimigoVida = new int{100}; 

    std::cout << "Vida do inimigo: " << *inimigoVida << '\n';

    // Se você esquecer a linha abaixo... PARABÉNS, VOCÊ CRIOU UM MEMORY LEAK!
    // A função acaba, o ponteiro da Stack morre, mas a memória na Heap fica ocupada para sempre.
    delete inimigoVida; 
}
// C++ MODERNO
void criarInimigoModerno() {
    // Cria um ponteiro inteligente na Stack, que gerencia um int(100) na Heap.
    // std::make_unique é a forma moderna e segura de alocar memória (C++14).
    std::unique_ptr<int> inimigoVida = std::make_unique<int>(100);

    // Usamos o ponteiro normalmente, com o * para desreferenciar
    std::cout << "Vida do inimigo: " << *inimigoVida << '\n';
    *inimigoVida -= 20;

    // Fim da função. O que acontece?
    // A Stack destrói 'inimigoVida'. Ao ser destruído, o smart pointer 
    // libera a memória da Heap automaticamente. Zero vazamentos!
}


int main() {
    /**
     * STACK -> LIMPA O PRÓPRIO LIXO
     */
    int vida = 100;

    // 1. REFERÊNCIA (O jeito C++)
    // Lê-se: "refVida é uma referência para um int, e aponta para vida"
    int& refVida = vida; 
    
    // 2. PONTEIRO (O jeito C)
    // Lê-se: "ptrVida é um ponteiro para um int, que recebe o ENDEREÇO (&) de vida"
    int* ptrVida = &vida; 

    // Modificando os valores:
    refVida = 90;       // Altera 'vida' para 90. A sintaxe é limpa!
    *ptrVida = 80;      // Altera 'vida' para 80. Precisamos "desreferenciar" usando o *

    std::cout << "Vida final: " << vida << '\n'; // Imprime 80

    std::string nomeJog{"Marcio"};
    receberDano(nomeJog, vida);
    std::cout << "\nVida final: " << vida << "\n\n\n";
    /**
     * HEAP
     */
    std::vector<std::unique_ptr<std::string>> inimigos;
    inimigos.push_back(std::make_unique<std::string>("Orc"));
    inimigos.push_back(std::make_unique<std::string>("Goblin"));
    inimigos.push_back(std::make_unique<std::string>("Troll"));

    for(auto& inimigo : inimigos) {
        std::cout << *inimigo << ' ';
    }

    return 0;
}

// Passagem por CÓPIA (Ruim para dados grandes)
void processarImagemRuim(std::vector<int> pixels) {
    // Aqui, o C++ duplicou toda a lista na memória!
}

// Passagem por REFERÊNCIA CONSTANTE (O padrão ouro do C++)
// O 'const' impede modificações. O '&' impede a cópia.
void processarImagemBoa(const std::vector<int>& pixels) {
    // Acessamos os dados originais rapidamente, sem copiar nada, e com segurança.
}
