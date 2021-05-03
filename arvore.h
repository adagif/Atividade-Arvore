/*Faça um TAD de Árvore Binária Dinâmica com a seguintes funções:




v) n-ésimo menor valor da árvore (árvore tem os elementos: 5, 4, 3 e 1. Se n = 2, a função retornaria o valor 3).
*/


struct aluno{
	int matricula;
	int notaGeral;
};

typedef struct no* Arvore;
typedef struct no No;
//i) Básicas mínimas. Criar e inserir;
Arvore* criar();
int inserir(Arvore* ,struct aluno);
int acessar(Arvore *, int, struct aluno *);
//ii) Extras mínimas. Algum percurso (se quiser fazer um imprimir mais bonitinho também fique a vontade);
void percorrer (Arvore *);
void preOrdem(No *);
int vazia (Arvore *);
//iii) Maior valor da árvore;
int maior(Arvore *);
//iv) Quantidade de folhas da árvore;

