#include <iostream>
#include <string>

using namespace std;

class Aluno {
public:
    Aluno(string nome, string matricula, string curso) : nome(nome), matricula(matricula), curso(curso), nota(0), faltas(0) {}
    string getNome() 
    { 
        return nome;
    }
    string getMatricula() 
    { 
        return matricula;
    }
    string getCurso() 
    { 
        return curso;
    }
    float getNota() 
    { 
        return nota;
    }
    int getFaltas() 
    { 
        return faltas;
    }
    void setNota(float novaNota) { nota = novaNota; }
    void setFaltas(int novasFaltas) { faltas = novasFaltas; }

private:
    string nome;
    string matricula;
    string curso;
    float nota;
    int faltas;
};

class CadastroAlunos 
{
public:
    CadastroAlunos(int capacidade) : capacidade(capacidade), numAlunos(0) 
    {
        alunos = new Aluno*[capacidade];
    }

    CadastroAlunos() 
    {
        for (int i = 0; i < numAlunos; ++i) 
        {
            delete alunos[i];
        }
        delete[] alunos;
    }

    void cadastrarAluno(string nome, string matricula, string curso) 
    {
        if (numAlunos < capacidade) 
        {
            alunos[numAlunos] = new Aluno(nome, matricula, curso);
            cout << "Aluno: " << nome << " cadastrado com sucesso!\n";
            numAlunos++;
        } 
        else 
        {
            cout << "Limite de alunos atingido.";
        }
    }

    void consultarAluno(string matricula) 
    {
        for (int i = 0; i < numAlunos; i++) 
        {
            if (alunos[i]->getMatricula() == matricula) 
            {
                cout << "\nNome: " << alunos[i]->getNome();
                cout << "\nMatrícula: " << alunos[i]->getMatricula();
                cout << "\nCurso: " << alunos[i]->getCurso();
                cout << "\nNota: " << alunos[i]->getNota();
                cout << "\nFaltas: " << alunos[i]->getFaltas();
                return;
            }
        }
        cout << "Aluno não encontrado.";
    }

private:
    Aluno** alunos;
    int capacidade;
    int numAlunos;
};

int main() {
    CadastroAlunos cadastro(10);

    cadastro.cadastrarAluno("Pedro", "23209909", "Engenharia de Redes");
    cadastro.cadastrarAluno("João", "23209908", "Engenharia de Software");

    cout << "\nConsulta de aluno:";
    cadastro.consultarAluno("23209909");

    return 0;
}
