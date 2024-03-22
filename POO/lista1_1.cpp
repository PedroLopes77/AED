#include <iostream>
#include <string>

using namespace std;

class agenda_tel
{
private:
int telefone;
string nome;

    public:
    agenda_tel(int telefone, string nome) 
    {
        this->telefone = telefone;
        this->nome = nome;
    }
    int getTelefone() 
    {
        return telefone;
    }

    string getNome() 
    {
        return nome;
    }

    void mostrarTelefone() 
    {
        cout << "O telefone é: " << telefone<<"\n";
    }

    void mostrarNome() 
    {
        cout << "O nome é: " << nome<<"\n";
    }
};

int main() {
    agenda_tel Myagenda_tel(98489765, "Pedro");
    Myagenda_tel.mostrarTelefone();
    Myagenda_tel.mostrarNome();

    return 0;
}

