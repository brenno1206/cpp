#include "11_ContaBancaria.hpp"
// #include <string>
#include <iostream>



ContaBancaria::ContaBancaria(const std::string& t, double s) : titular{t}, saldo{s} {}
    
double ContaBancaria::getSaldo() const { return saldo; }
    
void ContaBancaria::depositar(double valor) { if (valor > 0) saldo += valor; }
