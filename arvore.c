#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct no{

	struct no *dir;
	struct no *esq;
	struct aluno dados;
};

typedef struct no No;

Arvore* criar(){

	Arvore *a;
	a = (Arvore*)malloc(sizeof(Arvore));
	if(a == NULL){
		printf("Ta alocado nao oh\n");
	}else{
		*a = NULL;
	}
	return a;
}

int inserir(Arvore *a, struct aluno ndados){
	if(a==NULL){
		return 0;
	}
	No *novo = (No *)malloc(sizeof(No));
	if(novo==NULL){
		return 0;
	}
	novo->dados = ndados;
	novo->esq = NULL;
	novo->dir = NULL;

	if(*a == NULL){
		*a = novo;
	}else{
		No *aux = *a,*painho;

		while(aux != NULL){
			painho = aux;
			if(ndados.matricula<painho->dados.matricula){
				aux = aux->esq;
			}
			else if(ndados.matricula>painho->dados.matricula){
				aux = aux->dir;
			}else{
				free(novo);
				return 0;
			}

		}
		if(ndados.matricula<painho->dados.matricula<painho->dados.matricula){
			painho->esq = novo;
		}else{
			painho->dir = novo;
		}
	}
	return 1;
}

int acessar(Arvore *b,int x,struct aluno *a){
	if(vazia(b)==1){
		printf("Vazia\n");
		return 0;
	}
	No *aux = *b;

	while(aux != NULL){
		if(x<aux->dados.matricula){
			aux = aux->esq;
		}
		else if(x>aux->dados.matricula){
			aux = aux->dir;
		}
		else{
			*a = aux->dados;
			return 1;
		}
	}
	return 0;
}

void percorrer(Arvore *a){
	if(vazia(a) == 1){
		printf("Vazia\n");
	}
	preOrdem(*a);
}

void preOrdem(No *n){
	if(n != NULL){
		printf("Matricula: %d\n",n->dados.matricula);
		printf("Nota Geral: %d\n",n->dados.notaGeral);
		preOrdem(n->esq);
		preOrdem(n->dir);

	}
}

int vazia (Arvore *a){
	if(a == NULL){
		return 1;
	}
	else if(*a == NULL){
		return 1;
	}
	else{
		return 0;
	}
}
int maior(Arvore *a){
	
	if(vazia(a)==1){
		printf("Vazio");
	}
	int maior=0;
	No *aux = *a;

	while(aux != NULL){
	
		maior = aux->dados.matricula;
		aux = aux->dir;

	}
	return maior;
}


