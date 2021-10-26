#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#define BAG_VALUE 20
#define ITEM_VALUE 9



void mochila(int valor)
{
    for(int i=1; i<=valor; i++)
    {
        printf("%c", 178);
    }
}

int* preenche_peso(int *peso)
{
    /*PREENCHENDO O PONTEIRO/VETOR PESO*/
    for(int i=0; i<=ITEM_VALUE; i++)
    {
        int a = rand()%10+1;
        peso[i] = a;
    }
    return peso;
}

int* preenche_valor(int *valor)
{
    for(int i=0; i<=ITEM_VALUE; i++)
    {
        int a = rand()%10+1;
        valor[i] = a;
    }
    return valor;
}

int* remove_peso(int *peso, int obj)
{
    int i=0;
    int *aux = malloc(sizeof(int));
    aux = peso[obj-1];
    for(i=obj-1; i<=ITEM_VALUE; i++)
    {
        peso[i] = peso[i++];
    }
    peso[i] = aux;
    peso = realloc(peso, i*sizeof(int));
    return peso;
}

int* remove_valor(int *valor, int obj)
{
    int i=0;
    int *aux = malloc(sizeof(int));
    aux = valor[obj-1];
    for(i=obj-1; i<=ITEM_VALUE; i++)
    {
        valor[i] = valor[i++];
    }
    valor[i] = aux;
    valor = realloc(valor, i*sizeof(int));
    return valor;
}

int verifica(int itens[], int obj)
{
    for(int i=0; i < ITEM_VALUE; i++)
    {
        if(itens[i] == obj)
        {
            return 1;
        }
    }
    return 0;
}

void printa(int itens[])
{
    printf("Vetor: \n");
    for(int i=0; i <= ITEM_VALUE; i++)
    {
        printf("%d\n", itens[i]);
    }
}

void mostra_peso(int *peso)
{
    printf("PESOS: ");
    for(int i=0; i<=ITEM_VALUE; i++)
    {
        printf("%d\t", peso[i]);
    }
    printf("\n");
}

void mostra_valor(int *valor)
{
    printf("VALOR: ");
    for(int i=0; i<=ITEM_VALUE; i++)
    {
        printf("%d\t", valor[i]);
    }
    printf("\n");
}

void mostra_capacidade()
{
    printf("Capacidade da mochila: %d\n", BAG_VALUE);
}

void mostra_obj()
{
    printf("OBJET: ");
    for(int i=0; i<=ITEM_VALUE; i++)
    {
        printf("%d\t", i+1);
    }
    printf("\n");
}

void mostra_mochila(int bag, int value)
{
    printf("sua mochila pesa: %d/%d e vale: %d\n", bag, BAG_VALUE, value);
}

void menu()
{
    printf("1 - Jogar\n");
    printf("2 - Leitura de arquivos\n");
    printf("Qualquer outra tecla para sair\n");
}

int preenche_vetor(int vetor[])
{
    for(int i=0; i<ITEM_VALUE+1; i++)
    {
        vetor[i] = i+11;
    }
    return vetor;
}

void arquivo(int vitoria_jogador, int vitoria_maquina)
{
    FILE *arq;

    arq = fopen("texto3.txt", "w");
    fprintf(arq, "Jogador - Maquina\n");
    fprintf(arq, "%d\t%d", vitoria_jogador, vitoria_maquina);
    fclose(arq);
}

void Menu_Dificuldade()
{
    printf("1 - FACIL\n");
    printf("2 - MEDIO\n");
    printf("3 - DIFICIL\n");
}

int dificuldade(int dificuldade, int *valor, int itens_maquina[])
{

    int aux_rand = rand()%100;
    int maior = 0;
    int pega_indice = 0;
    /*FACIL*/
    if(dificuldade == 1)
    {
       if(aux_rand < 50)
        {
            for(int i=0; i<=ITEM_VALUE; i++)
            {
                if(valor[i] > maior)
                {
                    for(int j=0; j<=ITEM_VALUE; j++)
                    {
                        if(i == itens_maquina[j])
                        {
                            break;
                        }else
                        {
                            maior = valor[i];
                            pega_indice = i;
                        }
                    }
                }
            }
            maior = 0;
            return pega_indice;
        }else
        {
            maior = 0;
            pega_indice = rand()%10;
            return pega_indice;
        }
    }


    /*MEDIO*/
    if(dificuldade == 2)
    {
       if(aux_rand < 75)
        {
            for(int i=0; i<=ITEM_VALUE; i++)
            {
                if(valor[i] > maior)
                {
                    for(int j=0; j<=ITEM_VALUE; j++)
                    {
                        if(i == itens_maquina[j])
                        {
                            break;
                        }else
                        {
                            maior = valor[i];
                            pega_indice = i;
                        }
                    }
                }
            }
            maior = 0;
            return pega_indice;
        }else
        {
            maior = 0;
            pega_indice = rand()%10;
            return pega_indice;
        }
    }

    /*DIFICIL*/
    if(dificuldade == 3)
    {
       if(aux_rand < 95)
        {
            for(int i=0; i<=ITEM_VALUE; i++)
            {
                if(valor[i] > maior)
                {
                    for(int j=0; j<=ITEM_VALUE; j++)
                    {
                        if(i == itens_maquina[j])
                        {
                            break;
                        }else
                        {
                            maior = valor[i];
                            pega_indice = i;
                        }
                    }
                }
            }
            maior = 0;
            return pega_indice;
        }else
        {
            maior = 0;
            pega_indice = rand()%10;
            return pega_indice;
        }
    }
}


void cenarios()
{
    FILE *arq;
    arq = fopen("mochila1.txt", "r");
    int i=0;

    int n_itens = 0;
    int capacidade_max = 0;
    fscanf(arq, "%d%d",&n_itens, &capacidade_max);
    int nochila[n_itens];
    int pesos[n_itens];
    int valores[n_itens];
    printf("%d %d\n", n_itens, capacidade_max);
    int j=0;
    int k=0;
    int l=0;

    while((fscanf(arq, "%d", &nochila[i])) != EOF)
    {

        if(l<n_itens)
        {
            valores[j] = nochila[i];
            j++;
            l++;
        }else
        {
            pesos[k] = nochila[i];
            k++;
            l++;
        }
        printf("%d ", nochila[i]);
    }
    printf("\n\n\n");
    printf("Valores:\n");
    for(int i=0; i<n_itens; i++)
    {
        printf("%d ", valores[i]);
    }
    printf("\n\n\n");
    printf("Pesos:\n");
    for(int i=0; i<n_itens; i++)
    {
        printf("%d ", pesos[i]);
    }
    printf("\n\n\n");
    fclose(arq);
    /*Inserindo os arquivos na mochila*/
    int nova_mochila_peso[n_itens];
    int nova_mochila_valor[n_itens];
    int conta_peso_mochila = 0;
    int conta_valor_mochila = 0;
    for(int i=0; i<n_itens;i++)
    {

        if(conta_peso_mochila < capacidade_max)
        {
            nova_mochila_peso[i] = pesos[i];
            nova_mochila_valor[i] = valores[i];
            conta_peso_mochila += nova_mochila_peso[i];
            conta_valor_mochila += nova_mochila_valor[i];
            if(conta_peso_mochila < capacidade_max)
            {
                printf("%d - Peso: %d\n", i+1, conta_peso_mochila);
                printf("%d -Valor: %d\n", i+1, conta_valor_mochila);
            }else
            {
                conta_peso_mochila -= nova_mochila_peso[i];
                conta_valor_mochila -= nova_mochila_valor[i];
                break;
            }
        }
    }
    printf("a mochila atingiu o peso maximo permitido\n");
    printf("Peso: %d/%d Valor: %d\n", conta_peso_mochila, capacidade_max, conta_valor_mochila);
}
