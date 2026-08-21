#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

int ouroTotal{0};
std::mutex cadeado;

void minerar(int idMinerador, int quantidadeVezes) {
    int ouroLocal = 0;
    for(int i{0}; i < quantidadeVezes; i++) {
        ouroLocal+=10;
    }
    std::lock_guard<std::mutex> guard(cadeado);
    ouroTotal += ouroLocal;

}

int main(){
    std::vector<std::thread> equipe;
    for(int i{0}; i < 5; i++) {
        equipe.push_back(std::thread(minerar, i, 100000));
    }

    for(auto& e : equipe) {
        e.join();
    }
    std::cout << "Saldo final: " << ouroTotal << '\n';
    return 0;
}