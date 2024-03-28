#include <iostream>
#include <string>

using namespace std;

class AgendaTelefonica {
public:
    AgendaTelefonica(const string& telefone, const string& nome, const string& endereco, const string& cep)
        : telefone(telefone), nome(nome), endereco(endereco), cep(cep) {}

    void setTelefone(const string& telefone) { this->telefone = telefone; }
    void setNome(const string& nome) { this->nome = nome; }
    void setEndereco(const string& endereco) { this->endereco = endereco; }
    void setCep(const string& cep) { this->cep = cep; }
    
    string getTelefone() const { return telefone; }
    string getNome() const { return nome; }
    string getEndereco() const { return endereco; }
    string getCep() const { return cep; }

    void imprimirContato() const {
        cout << "Nome: " << nome << endl;
        cout << "Telefone: " << telefone << endl;
        cout << "Endereço: " << endereco << endl;
        cout << "CEP: " << cep << endl;
        cout << endl;
    }

private:
    string telefone;
    string nome;
    string endereco;
    string cep;
};

int main() {

    AgendaTelefonica contato1("123456789", "João", "Rua A, 123", "12345-678");
    AgendaTelefonica contato2("987654321", "Maria", "Av. B, 456", "56789-012");
    AgendaTelefonica contato3("111222333", "Pedro", "Rua C, 789", "90123-456");
    AgendaTelefonica contato4("444555666", "Ana", "Av. D, 987", "34567-890");

    cout << "Contatos na agenda telefônica:" << endl;
    contato1.imprimirContato();
    contato2.imprimirContato();
    contato3.imprimirContato();
    contato4.imprimirContato();

    return 0;
}
