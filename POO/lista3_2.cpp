#include <iostream>
#include <string>

using namespace std;

class Pessoa {
protected:
    string nome;
    int idade;

public:
    Pessoa(const string& nome, int idade) : nome(nome), idade(idade) {}

    string getNome() const {
        return nome;
    }

    int getIdade() const {
        return idade;
    }
};

class Empregado : public Pessoa {
protected:
    double salarioBase;

public:
    Empregado(const string& nome, int idade, double salarioBase) : Pessoa(nome, idade), salarioBase(salarioBase) {}

    double getSalarioBase() const {
        return salarioBase;
    }
};

class Vendedor : public Empregado {
private:
    double valorVendas;
    double comissao;

public:
    Vendedor(const string& nome, int idade, double salarioBase, double valorVendas, double comissao) 
        : Empregado(nome, idade, salarioBase), valorVendas(valorVendas), comissao(comissao) {}

    double calcularSalario() const {
        return salarioBase + (valorVendas * (comissao / 100.0));
    }

    double getValorVendas() const {
        return valorVendas;
    }

    double getComissao() const {
        return comissao;
    }
};

int main() {
    Vendedor vendedor("Pedro", 20, 2000, 5000, 10);

    cout << "Nome: " << vendedor.getNome() << endl;
    cout << "Idade: " << vendedor.getIdade() << endl;
    cout << "Salario Base: " << vendedor.getSalarioBase() << endl;
    cout << "Valor de Vendas: " << vendedor.getValorVendas() << endl;
    cout << "Comissao: " << vendedor.getComissao() << "%" << endl;
    cout << "Salario Total: " << vendedor.calcularSalario() << endl;

    return 0;
}
