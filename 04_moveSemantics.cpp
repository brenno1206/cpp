#include <iostream>
#include <format>

// & -> lvalue
void processar(std::string& texto) {
    std::cout << "Processando lvalue (Copia Proibica)\n";
}

// && -> rvalue
void processar(std::string&& texto) {
    std::cout << "Processando rvalue (Pode ROUBAR dados.)\n";
}

class Recurso {
private:
    int *dados{nullptr};
public:
    Recurso(int valor) {
        dados = new int{valor};
    }
    Recurso(Recurso&& outro) : dados{outro.dados} {
        outro.dados = nullptr;
        std::cout << "Recurso movido (Roubado)\n";
    }
    ~Recurso(){
        delete dados;
    }
};


int main(){
    std::string a = "Teste";
    processar(a);
    processar("Teste");
    processar(std::move(a));
    {
        Recurso a{100};
        Recurso b{std::move(a)};
    }
}