#include <iostream>
#include <string>

using namespace std;

class Pessoa {
public:
    Pessoa(string nome, string telefone, string tipoSanguineo, int idade) : nome(nome), telefone(telefone), tipoSanguineo(tipoSanguineo), idade(idade) {}

    string getNome() 
    { 
        return nome;
    }
    string getTelefone() 
    { 
        return telefone;
    }
    string getTipoSanguineo() 
    { 
        return tipoSanguineo;
    }
    int getIdade() 
    { 
        return idade;
    }

    void setNome(string novoNome) { nome = novoNome; }
    void setTelefone(string novoTelefone) { telefone = novoTelefone; }
    void setTipoSanguineo(string novoTipoSanguineo) { tipoSanguineo = novoTipoSanguineo; }
    void setIdade(int novaIdade) { idade = novaIdade; }

private:
    string nome;
    string telefone;
    string tipoSanguineo;
    int idade;
};

int main() {

    const int capacidade = 4;

    Pessoa pessoas[capacidade] 
    {
        Pessoa("Fulano\n", "998276372\n", "O+", 30),
        Pessoa("Ciclano\n", "987654321\n", "O-", 40),
        Pessoa("Beltrano\n", "98727366\n", "AB+", 25),
        Pessoa("Xablau\n", "989983228\n", "O-", 35)
    };

    cout << "Doadores Universais:\n";
    for (int i = 0; i < capacidade; ++i) 
    {
        if (pessoas[i].getTipoSanguineo() == "O-") 
        {
            cout << "Nome: " << pessoas[i].getNome();
            cout << "Telefone: " << pessoas[i].getTelefone();
            cout << "Tipo Sanguíneo: " << pessoas[i].getTipoSanguineo();
            cout << "\nIdade: " << pessoas[i].getIdade() << " anos\n";
        }
    }

    return 0;
}

