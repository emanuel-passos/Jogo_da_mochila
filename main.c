#include <stdio.h>
#include <stdlib.h>
#include "header.h"
#include <time.h>
#define BAG_VALUE 20
#define ITEM_VALUE 9
#define TRUE 1
#define FALSE 0


int main()
{
    srand(time(NULL)); /*comando para gerar valores aleatórios diferentes*/
    int *valor = malloc(ITEM_VALUE*sizeof(int)); //valores em dinheiro dos objetos
    int *peso = malloc(ITEM_VALUE*sizeof(int));//peso em kg dos objetos
    int jogar = TRUE;
    int opcao = 0;
    int obj;//essa variável irá guardar o objeto escolhido
    int mochila_peso = 0;//essa variavel representara o peso mochila do jogador
    int mochila_valor = 0;//essa variavel representara o valor mochila do jogador
    int itens[ITEM_VALUE] = {10,20,30,40,50,60,70,80,90,100,110};
    int recebe_retorno;
    int aux=0; /*sera incrementada cada vez que um item entrar na mochila*/
    int valida_jogada_jogador = FALSE;
    int vitoria_jogador = 0;
    //variaveia para jogo contra a máquina
    int mochila_peso_maquina = 0;//essa variavel representara o peso mochila da maquina
    int mochila_valor_maquina = 0;//essa variavel representara o valor mochila da maquina
    int turno = 0; /*indica o turno da jogada*/
    int itens_maquina[ITEM_VALUE] = {10,20,30,40,50,60,70,80,90,100,110}; /*vetor que guardará os itens da máquina*/
    int aux_maquina = 0; /*recebe a validacao*/
    int rand_maquina; /*pega valores aleatorios para jogar na mochila da maquina*/
    int ind_maquina = 0;
    int valida_jogada_maquina = FALSE;
    int vitoria_maquina = 0;
    int z;
    //preenchendo os objetos que entrarão na mochila
    preenche_peso(peso);
    preenche_valor(valor);

    /*LOOP princiapl do jogo*/
    while(jogar == TRUE)
    {
        printf("Menu principal!\n");
        menu();
        scanf("%d", &opcao);
        if(opcao == 1)
        {
            int nivel = 0;
            Menu_Dificuldade();
            scanf("%d", &nivel);
            while(opcao == 1)
            {
                while(mochila_peso < 20 && mochila_peso_maquina <20)
                {
                    valida_jogada_maquina = FALSE;
                    valida_jogada_jogador = FALSE;
                    mostra_capacidade();
                    mostra_mochila(mochila_peso, mochila_valor);
                    printf("\nDA MAQUINA: \n");
                    mostra_mochila(mochila_peso_maquina, mochila_valor_maquina);
                    //printf("DA MAQUINA!!! \n");
                    mostra_obj();
                    mostra_peso(peso);
                    mostra_valor(valor);
                    while(valida_jogada_jogador == FALSE)
                    {
                        if(turno%2 == 0)
                        {
                            printf("Escolha o numero do OBJET para colocar na mochila:");
                            scanf("%d", &obj);
                            recebe_retorno = verifica(itens, obj-1);
                            if(recebe_retorno == 0)
                            {
                                recebe_retorno = verifica(itens_maquina, obj-1);
                                if(recebe_retorno == 0)
                                {
                                    itens[aux] = obj-1;
                                    mochila_peso += peso[obj-1];
                                    mochila_valor += valor[obj-1];
                                    printf("Objeto foi colocado na mochila\n");
                                    aux++;
                                    turno++;
                                    valida_jogada_jogador = TRUE;
                                }else
                                {
                                    printf("A maquina ja escolheu esse objeto. Por favor escolha outro:\n");
                                }
                            }else
                            {
                                printf("voce ja escolheu esse objeto. Por favor escolha outro:\n");
                            }
                        }
                    }
                    if(turno%2 != 0)
                    {
                        while(valida_jogada_maquina == FALSE)
                        {
                            rand_maquina = rand()%10;
                            //z = rand_maquina; APENAS PARA TESTE
                            //printf("aleatorio: %d\n", z); APENAS PARA TESTE
                            rand_maquina = dificuldade(nivel, valor, itens_maquina);
                            //z = rand_maquinA; APENAS PARA TESTE
                            //printf("modificado: %d\n", z);
                            //printf("\nVALORDO RAND MAQUINA: %d\n", rand_maquina); APENAS PARA TESTE
                            aux_maquina = verifica(itens, rand_maquina);
                            if(aux_maquina == 0)
                            {
                                aux_maquina = verifica(itens_maquina, rand_maquina);
                                if(aux_maquina == 0)
                                {
                                    itens_maquina[ind_maquina] = rand_maquina;
                                    mochila_peso_maquina +=  peso[rand_maquina];
                                    mochila_valor_maquina +=  valor[rand_maquina];
                                    printf("A vez da maquina acabou. Chegou sua vez de jogar:\n");
                                    ind_maquina++;
                                    turno++;
                                    valida_jogada_maquina = TRUE;
                                }
                            }
                        }
                    }
                }
                if(mochila_peso >= 20 || mochila_peso_maquina >= 20)
                {
                    if(mochila_valor < mochila_valor_maquina)
                    {
                        vitoria_maquina++;
                        printf("\nA maquina venceu!");
                        printf("Capacidade: %d/%d. Valor da mochila: %d\n", mochila_peso, BAG_VALUE, mochila_valor);
                        printf("Capacidade(maquina): %d/%d. Valor da mochila(maquina): %d\n", mochila_peso_maquina, BAG_VALUE, mochila_valor_maquina);
                        menu();
                        if(opcao == 1)
                        {
                            *valor = malloc(ITEM_VALUE*sizeof(int)); //valores em dinheiro dos objetos
                            *peso = malloc(ITEM_VALUE*sizeof(int));//peso em kg dos objetos
                            jogar = TRUE;
                            opcao = 1;
                            mochila_peso = 0;//essa variavel representara o peso mochila do jogador
                            mochila_valor = 0;//essa variavel representara o valor mochila do jogador
                            free(itens);
                            aux=0; /*sera incrementada cada vez que um item entrar na mochila*/
                            preenche_peso(peso);
                            preenche_valor(valor);
                            valida_jogada_maquina = FALSE;
                            valida_jogada_jogador = FALSE;
                            mochila_peso_maquina = 0;//essa variavel representara o peso mochila do jogador
                            mochila_valor_maquina = 0;
                            free(itens_maquina);
                            aux_maquina = 0;
                            valida_jogada_maquina = FALSE;
                            ind_maquina = 0;
                            preenche_vetor(itens);
                            preenche_vetor(itens_maquina);
                            Menu_Dificuldade();
                            scanf("%d", &nivel);
                        }
                        else if(opcao == 2)
                        {
                            jogar = FALSE;
                        }
                    }else if(mochila_valor_maquina < mochila_valor)
                    {
                        vitoria_jogador++;
                        printf("\nVoce venceu!");
                        printf("Capacidade: %d/%d. Valor da mochila: %d\n", mochila_peso, BAG_VALUE, mochila_valor);
                        printf("Capacidade(maquina): %d/%d. Valor da mochila(maquina): %d\n", mochila_peso_maquina, BAG_VALUE, mochila_valor_maquina);
                        menu();
                        scanf("%d", &opcao);
                        if(opcao == 1)
                        {
                            *valor = malloc(ITEM_VALUE*sizeof(int)); //valores em dinheiro dos objetos
                            *peso = malloc(ITEM_VALUE*sizeof(int));//peso em kg dos objetos
                            jogar = TRUE;
                            opcao = 1;
                            mochila_peso = 0;//essa variavel representara o peso mochila do jogador
                            mochila_valor = 0;//essa variavel representara o valor mochila do jogador
                            free(itens);
                            aux=0; /*sera incrementada cada vez que um item entrar na mochila*/
                            preenche_peso(peso);
                            preenche_valor(valor);
                            valida_jogada_maquina = FALSE;
                            valida_jogada_jogador = FALSE;
                            mochila_peso_maquina = 0;//essa variavel representara o peso mochila do jogador
                            mochila_valor_maquina = 0;
                            free(itens_maquina);
                            aux_maquina = 0;
                            valida_jogada_maquina = FALSE;
                            ind_maquina = 0;
                            preenche_vetor(itens);
                            preenche_vetor(itens_maquina);
                            Menu_Dificuldade();
                            scanf("%d", &nivel);
                        }
                        else if(opcao == 2)
                        {
                            jogar = FALSE;
                        }
                    }
                }
            }
        }else if(opcao == 2)
        {
            cenarios();
            jogar = FALSE;
        }else
        {
            jogar = FALSE;
        }
    }
    arquivo(vitoria_jogador, vitoria_maquina);
    printf("OBRIGADO POR JOGAR!\n");
    return 0;
}
