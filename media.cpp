/**
 * Professor registra a nota dos alunos
 * Prof tem matricula, nome, teleforne
 * Ele digita o nome e as 2 ou 3 notas do aluno
 * Se o aluno ficar >= 7 com 2 notas, nao pede a terceira e ele passa direto
 * Se o aluno ficar >= 3 e <= 7, pede a terceira nota e vai pra rec
 * Se o aluno ficar < 3, ele reprova direto sem direito a terceira nota
 * Se o aluno for para recuperacao e tirar >= 5 ele passa
 * NOTA PARCIAL = (nota1 + nota2) / 2
 * NOTA REC = (notaParcial + nota3) / 2
 * No final imprime os dados do professor, o nome da disciplina
 * Os alunos ordenados pela nota, dizendo quem foi aprovado direto, com prova final e reporvado
 * Os alunos ordenados por ordem alfabetica
 */

#include <iostream>
#include <format>

using namespace std;

enum Ordenacao {
    Nome,
    Nota,
    Matricula
};

class Professor {
    private:
        string matricula;
        string nome;
        string email;
        string telefone;
    
    public:
        Professor(string pNome, string pMatricula, string pEmail, string pTelefone) : nome(pNome), matricula(pMatricula), email(pEmail), telefone(pTelefone) {}
        
};

class Aluno{};

class Disciplina{};

string getNomeProf(){}

string getMatriculaProf(){}

string getTelefoneProf(){}

string getMailProf(){}

string getNomeDisciplina(){}

int getQtdAlunos(){}

int getAlunoDados(){}

void printAlunos(string ordenacao){}

int main() {
    int numAlunos;
    string profNome, profMatricula, profTel, profMail, disciplina;

    cout << "Bem vindo ao Sistema Sabia\n";

    profNome = getNomeProf();
    profMatricula = getMatriculaProf();
    profTel =  getTelefoneProf();
    profMail = getMailProf();
    
    disciplina = getNomeDisciplina();

    numAlunos = getQtdAlunos();



    return 0;
}