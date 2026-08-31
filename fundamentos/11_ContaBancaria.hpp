#pragma once

#include <string>

class ContaBancaria {
private:
    std::string titular;
    double saldo;
public:
    ContaBancaria(const std::string& t, double s);
    double getSaldo() const;
    void depositar(double valor);
};