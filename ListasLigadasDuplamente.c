#include<stdio.h>
#include<stdlib.h>

struct duplo
{
	int num;
	struct duplo* ant;
	struct duplo* prox;
};
typedef struct duplo Duplo;

Duplo* criaListaNula()
{

	return NULL;
}
Duplo* criaNo()
{
	Duplo *novo = (Duplo*) malloc(sizeof(Duplo));
	return novo;
}

Duplo* insereInicio(Duplo* Cabeca, int dado)
{
	Duplo* novo = criaNo();
	novo->num = dado;
	novo->ant = NULL;
	if(Cabeca == NULL)
	{
		Cabeca = novo;
		novo->prox = NULL;
		novo->ant = NULL;
	}
				else
	{
		novo->prox = Cabeca;
		Cabeca = novo;
	}
	return novo;
}
void imprime(Duplo* Cabeca)
{
	Duplo* aux = Cabeca;
	while(aux != NULL)
	{
		printf("%d ", aux->num);
		aux = aux->prox;
	}
}
int buscaDado(Duplo* Cabeca, int dado)
{
	Duplo *aux;
	for(aux = Cabeca; aux != NULL; aux = aux->prox)
		if((aux->num = dado))
		{
			return 1;
		}

	return 0;
}
Duplo* removeInicio(Duplo* Cabeca)
{
	Duplo *aux;
	if(Cabeca == NULL)
	{
		return 0;
	}
	else
	{
		aux = Cabeca;
		Cabeca = Cabeca->prox;
		Cabeca->ant = NULL;
		free(aux);
	}
	return Cabeca;
}


int main()
{
	Duplo *Cabeca;
	int resp;

	Cabeca = criaListaNula();
	Cabeca = insereInicio(Cabeca, 5);
	Cabeca = insereInicio(Cabeca, 4);
	Cabeca = insereInicio(Cabeca, 7);
	Cabeca = removeInicio(Cabeca);
	imprime(Cabeca);
	resp = buscaDado(Cabeca, 744);
	if((resp=1))
	{
		printf("encontrado");
	}
	else
	{
		printf("n Encontramos");
	}
	return 0;
}
