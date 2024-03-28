#include <iostream>
#include <string>

using namespace std;

class Aluno 
{
public:
    Aluno(string nome, string matricula, string curso, string idade, string semestre) : nome(nome), matricula(matricula), curso(curso), idade(idade), semestre(semestre) {}
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
    string getIdade()
    {
        return idade;
    }
    string getSemestre()
    {
        return semestre;
    }
    
private:
    string nome;
    string matricula;
    string curso;
    string idade;
    string semestre;
    
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

    void cadastrarAluno(string nome, string matricula, string curso, string idade, string semestre) 
    {
        if (numAlunos < capacidade) 
        {
            alunos[numAlunos] = new Aluno(nome, matricula, curso, idade, semestre);
            cout << "Aluno:  " << nome << " cadastrado com sucesso!\n";
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
                cout << "\nIdade: " << alunos[i]->getIdade();
                cout << "\nSemestre: " << alunos[i]->getSemestre();
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

int main() 
{
    CadastroAlunos cadastro(10);

    cadastro.cadastrarAluno("Pedro", "23209909", "Engenharia de Redes", "19 anos", "2° Semestre");
    cadastro.cadastrarAluno("João", "23209908", "Engenharia de Redes", "20 anos", "2° Semestre");

    cout << "\nConsulta de aluno:\n";
    cadastro.consultarAluno("23209909");

    return 0;
}
