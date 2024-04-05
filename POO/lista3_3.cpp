//Desenvolva um programa de gestão de funcionários que armazene informações dos empregados em um arquivo de texto.
//O sistema deve permitir adicionar funcionários, listar todos os funcionários cadastrados e calcular o salário total a ser pago pela empresa, 
//incluindo bonificações para os gerentes.
//Requisitos:
//- Implemente as classes Pessoa, Funcionario, Gerente e Sistema Gestão Funcionarios
//- Utilize herança
//- Utilize a classe fstream para armazenar os dados dos funcionários em um arquivo de texto.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Pessoa {
protected:
    string nome;
    int idade;

public:
    Pessoa(const string& nome, int idade) : nome(nome), idade(idade) {}
};

class Funcionario : public Pessoa {
protected:
    double salarioBase;
    int id;

public:
    Funcionario(const string& nome, int idade, double salarioBase, int id) : Pessoa(nome, idade), salarioBase(salarioBase), id(id) {}

    virtual double calcularSalario() const 
    {
        return salarioBase;
    }

    void salvarDados(ofstream& arquivo) const 
    {
        arquivo << "Nome: " << nome << ", Idade: " << idade << ", Salario Base: " << salarioBase;
    }
};

class Gerente : public Funcionario {
private:
    double bonificacao;

public:
    Gerente(const string& nome, int idade, double salarioBase, int id, double bonificacao) : Funcionario(nome, idade, salarioBase, id), bonificacao(bonificacao) {}

    double calcularSalario() const override 
    {
        return salarioBase + bonificacao;
    }

    void salvarDados(ofstream& arquivo) const 
    {
        Funcionario::salvarDados(arquivo);
        arquivo << ", Bonificacao: " << bonificacao;
    }
};

class SistemaGestaoFuncionarios {
public:
    void adicionarFuncionario(Funcionario* funcionario, const string& nomeArquivo) 
    {
        ofstream arquivo(nomeArquivo, ios::app);
        if (arquivo.is_open()) 
        {
            funcionario->salvarDados(arquivo);
            arquivo << endl;
            arquivo.close();
        } 
        else 
        {
            cout << "Erro ao abrir o arquivo." << endl;
        }
    }

    void listarFuncionarios(const string& nomeArquivo) const 
    {
        ifstream arquivo(nomeArquivo);
        if (arquivo.is_open()) 
        {
            string linha;
            while (getline(arquivo, linha)) 
            {
                cout << linha << endl;
            }
            arquivo.close();
        } 
        else 
        {
            cout << "Erro ao abrir o arquivo." << endl;
        }
    }

    double calcularSalarioTotal(const string& nomeArquivo) const 
    {
        double salarioTotal = 0.0;
        ifstream arquivo(nomeArquivo);
        if (arquivo.is_open()) 
        {
            string linha;
            while (getline(arquivo, linha)) 
            {
                size_t pos = linha.find("Salario Base: ");
                if (pos != string::npos) 
                {
                    double salarioBase = stod(linha.substr(pos + 14));
                    salarioTotal += salarioBase;
                }
                pos = linha.find("Bonificacao: ");
                if (pos != string::npos) 
                {
                    double bonificacao = stod(linha.substr(pos + 13));
                    salarioTotal += bonificacao;
                }
            }
            arquivo.close();
        } 
        else 
        {
            cout << "Erro ao abrir o arquivo." << endl;
        }
        return salarioTotal;
    }
};

int main() {
    SistemaGestaoFuncionarios sistema;
    sistema.adicionarFuncionario(new Funcionario("Pedro", 20, 2000, 1), "funcionarios.txt");
    sistema.adicionarFuncionario(new Gerente("Maria", 23, 3000, 2, 500), "funcionarios.txt");
    sistema.listarFuncionarios("funcionarios.txt");
    cout << "Salario Total: " << sistema.calcularSalarioTotal("funcionarios.txt") << endl;
    return 0;
}

