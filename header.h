#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


void mochila(int valor);/*mostrar uma representação gráfica de uma mochila*/
void mostra_peso(int *peso); /*mostra a tabela de peso*/
void mostra_valor(int *valor);/*mostra a tabela de valor*/
int* preenche_peso(int *peso);/*preenche o peso*/
int* preenche_valor(int *valor);/*preenche o valor*/
int* remove_valor(int *valor, int obj); /*remove um obj pelo peso*/
int* remove_peso(int *peso, int obj);/*remove um obj pelo valor*/
int verifica(int itens[], int obj); /*verifica se um objeto ja foi colocado em uma das mochilas*/
void printa(int itens[]); /*printa vetor pra auxiliar na depuração*/
void mostra_capacidade();/*mostra a capacidade maxima da mochila*/
void mostra_obj();/*mostra um tabela de objetos*/
void mostra_mochila(int bag, int value);/*mostra o peso e o valor da mochila do jogador, os objetos guardados ate o momento*/
void menu();/*mostra o menu inicial*/
int preenche_vetor(int vetor[]);/*preenche os vetores com valores aleatorios*/
void arquivo(int vitoria_jogador, int vitoria_maquina);/*cria arquivo*/
void cenarios();/*faz a leitura do cenário*/
int dificuldade(int dificuldade, int *valor, int itens_maquina[]);/*retorna o melhor valor para ser jogado pela maqina*/
int salva_indices(int indice);
#endif // HEADER_H_INCLUDED
