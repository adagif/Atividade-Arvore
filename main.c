#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

struct aluno x();
void menu();
void imprimir(struct aluno al);

int main(){
	
	Arvore *a;
	int opc,y,mat;

	a = NULL;

	struct aluno al;

	do{

		menu();
		printf("-> ");
		scanf("%d",&opc);

		switch(opc){

			case 1:
			if(a != NULL){
				printf("Esta arvore ja foi criada :) \n");
			}else{
				a = criar();
				if(a != NULL){
					printf("Arvore criada! (cuide bem dela - ba dum tiz)\n");
				} 
			}
			break;

			case 2:
			if(inserir(a,x())==0){
				printf("Nao deu certo inserir!\n");
			}else{
				printf("Inserido com sucesso!\n");
			}
			break;

			case 3:
			printf("Matricula:\n->");
			scanf("%d",&mat);

			if(acessar(a,mat,&al)==0){
				printf("ERRO!\n");
			}
			else{
				imprimir(al);
			}
			break;

			case 4:
			percorrer(a);
			break;

			case 5:
			printf("%d\n", maior(a));
			break;

			default:
			printf("INCORRETO\n");
			break;
		}
		

	}while(opc != 0);
}

void menu(){
	printf("\n ----------------------\n");
	printf("|ATIVIDADE 03 - ARVORES|\n");
	printf(" ----------------------\n");
	printf("|        MENU          |\n");
	printf("| 1.Criar              |\n");
	printf("| 2.Inserir            |\n");
	printf("| 3.Imprimir           |\n");
	printf("| 4.Percorrer          |\n");
	printf("| 5.Maior              |\n");
	printf("| 0.Sair               |\n");
	printf(" ----------------------\n");

}

struct aluno x(){
	struct aluno al;
	printf("Matricula:\n-> ");
	scanf("%d",&al.matricula);

	printf("Nota Geral:\n-> ");
	scanf("%d",&al.notaGeral);

	return al;
}

void imprimir (struct aluno al){
	printf("\nMatricula: %d\n",al.matricula);
	printf("Nota Geral: %d",al.notaGeral);

}