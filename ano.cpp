#include <iostream>
#include <format>

int main() {
    int anos;

    std::cout << "Digite a quantidade de anos: ";
    std::cin >> anos;
    
    int dias = anos * 365;

    std::string msg = std::format("O intervalo de anos {} tem {} dias.", anos, dias);
    std::cout << msg << std::endl;

    return 0;
}