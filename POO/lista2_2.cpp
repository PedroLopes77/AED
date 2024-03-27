// a principal diferença entre struct e class em C++ é a visibilidade padrão de seus membros. struct tem por padrão tudo público, enquanto class tem por padrão tudo privado. 
//No entanto, em termos de funcionalidade, elas são praticamente equivalentes.
// Exemplo disso:
// struct 
struct Pessoa {
    string nome;
    int idade;
    void mostrarNome() {
        cout << nome << endl;
    }
};

//class
class Pessoa {
private:
    string nome;
    int idade;
public:
    void setNome(string n) {
        nome = n;
    }
    string getNome() {
        return nome;
    }
};
//Modificadores de Visibilidade:
//+ Publico: Membros públicos são acessíveis de qualquer lugar.
//- Privado: Membros privados só são acessíveis dentro da própria classe.
//# Protegido: Membros protegidos são semelhantes aos privados, mas também podem ser acessados por classes derivadas.
//Exemplo :
class Instagram {
public:
    int perfil;
private:
    int editarPerfil;
protected:
    int seguidores;
};


