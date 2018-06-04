#ifndef _PILHA_H_
#define _PILHA_H_

//DEFINE OS DADOS DA PILHA
typedef struct {
    int valor;
} Dado;

//DEFINE OS NODES DA PILHA
typedef struct Nodo {
    Dado dado;
    struct Nodo *prox;
} node;

//DEFINE A PILHA
typedef struct {
    node *prox;
    int sizeF;
} pilha;

//CRIA PILHA
pilha *create();
//VERIFICA SE A PILHA ESTA VAZIA
int vazia(pilha *p);
//ALOCA OS NODE DA PILHA
node *alocar();
//ADICIONAR UM NODE AO FINAL DA PILHA
//RECEBE A PILHA E UM CARACTER (COLCHETES OU PARANTESES)
node *push(pilha *p, char s);
//REMOVE UM NODE DO FINAL DA PILHA
int pop(pilha *p);
//DESTROI A PILHA
void destroy(pilha *p);
//LISTAR PILHA
void viewPilha(pilha *p);
//function da prova final
void aMove(pilha *p);
void pMove(pilha *p);
void eMove(pilha *p);
void fMove(pilha *p);
void gMove(pilha *p);

#endif // _PILHA_H_
