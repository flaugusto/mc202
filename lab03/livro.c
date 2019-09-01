#include "livro.h"
#include <string.h>

Livro criar_livro(const char* titulo, Data emprestimo)
{
   Livro novo;
   strcpy(novo.titulo, titulo);
   novo.emprestimo = emprestimo;
   return novo;
}

Data obter_data_emprestimo(const Livro* livro)
{
   return livro->emprestimo;
}

const char* obter_titulo(const Livro* livro)
{
   return livro->titulo;
}
