#include <string.h>
#include "aluno.h"

Aluno criar_aluno(int registro_academico, float desempenho)
{
   Aluno novo;
   novo.registro_academico = registro_academico;
   novo.desempenho = desempenho;
   novo.num_disciplinas = 0;
   return novo;
}

Aluno adicionar_disciplina(Aluno aluno, const char disciplina[])
{
   int len = aluno.num_disciplinas;
   strcpy(aluno.disciplinas[len], disciplina);
   aluno.num_disciplinas = len + 1;
   return aluno;

}

float obter_desempenho(Aluno aluno)
{   
   return aluno.desempenho;
}

int validar_matricula(Aluno aluno, const char disciplina[])
{
   int len = aluno.num_disciplinas, matriculado = 0;
   for (int i = 0; i < len ; i++)
   {
      if (strcmp(disciplina, aluno.disciplinas[i]) == 0) {
         matriculado = 1;
      }
   }
   return matriculado;
   
}
