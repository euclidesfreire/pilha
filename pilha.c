#include "pilha.h"

//CRIA PILHA
pilha *create(){
    pilha *PILHA = (pilha *) malloc(sizeof(pilha));

    if(!PILHA) {
        printf("Sem memoria disponivel\n");
        exit(1);
    } else{
        //INICIALIZA OS DADOS DE PILHA
        PILHA->prox = NULL;
        PILHA->sizeF = 0;

        return PILHA;
    }

}
//VERIFICA SE A PILHA ESTA VAZIA
int vazia(pilha *p){

    if(p->prox == NULL)
        return 1;
    else
        return 0;
}

//ALOCA OS NODE DA PILHA
node *alocar(){

    node *novo = (node *) malloc(sizeof(node));

    if(!novo) {
        printf("Sem memoria disponivel\n");
        exit(1);
    } else{
        return novo;
    }

}
//ADICIONAR UM NODE AO FINAL DA PILHA
//RECEBE A PILHA E UM CARACTER (COLCHETES OU PARANTESES)
node *push(pilha *p, char s) {
    node *novo = alocar();
    //INICIALIZAR
    novo->dado.valor = s;
    novo->prox = NULL;
    //VERIFICAR SE A FILA ESTA VAZIA
    if(vazia(p)){
        p->prox = novo;
        p->sizeF++;
    } else {
        node *tmp = p->prox;
        //PROCURA O FINAL DA FILA
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
        p->sizeF++;
    }

    return novo;
}

//REMOVE UM NODE DO FINAL DA PILHA
int pop(pilha *p){

     if(vazia(p)){
        printf("PILHA VAZIA!\n");
        return NULL;
    } else {
        //PARA PEGAR O NODE ANTERIOR E POSTERIOR
        node *ultimo = p->prox,
              *penultimo = p->prox;

        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        //FAZ O ANTERIOR EM RELAÇÃO AO ULTIMO NODE AGORA APONTAR PARA NULL
        penultimo->prox = NULL;
        p->sizeF--;
        if(p->sizeF == 0)
            p->prox = NULL;
        //RETORNA O CARACTER
        return ultimo->dado.valor;
    }
}

//DESTROI A PILHA
void destroy(pilha *p){
  if (vazia(p)) {
    printf("PILHA VAZIA!\n");
    return;
  } else {
      node *tmp = p->prox;
      node *proxNode;
      while(tmp->prox != NULL){
        proxNode = tmp->prox;
        free(tmp);
        tmp = proxNode;
      }

  }
}

void viewPilha(pilha *p) {

    //VERIFICAR SE A FILA ESTA VAZIA
    if(vazia(p)){
        printf("PILHA VAZIA");
    } else {
        node *tmp = p->prox;
        //LISTAR
        int i = 1;

        printf("\n------ Lista ------\n");

        while(tmp->prox != NULL){
            printf("\n[ %d ] - %d", i, tmp->dado.valor);
            tmp = tmp->prox;
            i++;
        }
        printf("\n[ %d ] - %d", i, tmp->dado.valor);
        printf("\n\n-------------------\n");
    }
}

//function da prova final
 void aMove(pilha *p){
    node *i = (node*) malloc(sizeof(node));
    int valor;
    printf("Digite o valor do Nodo i: ");
    scanf("%d", &valor);
    i->dado.valor = valor;

    if(vazia(p)){
        push(p, i->dado.valor);
    } else {
        //LISTAR
        int aux = p->sizeF;
        int aux2 = 1;
        if(aux >= 2)
            aux2 = aux - 2;

        while(aux > aux2){
            pop(p);
            aux--;
        }

        push(p, i->dado.valor);
    }

 }

 void bMove(pilha *p){
    node *i = (node*) malloc(sizeof(node));
    int valor;
    printf("Digite o valor do Nodo i: ");
    scanf("%d", &valor);
    i->dado.valor = valor;

    if(vazia(p)){
        push(p, i->dado.valor);
    } else {
        pilha *ptmp = create();
        node *ntmp = p->prox;

        //LISTAR
        int aux = p->sizeF;
        printf("%d", aux);
        int aux2 = 1;
        if(aux >= 2)
            aux2 = aux - 2;

        while(aux > aux2){
            push(ptmp, ntmp->dado.valor);
            ptmp->sizeF++;
            if(ntmp->prox != NULL)
                ntmp = ntmp->prox;
            pop(p);
            aux--;
        }

        push(p, i->dado.valor);

        ntmp = ptmp->prox;
        push(p, ntmp->dado.valor);
        ntmp = ntmp->prox;
        push(p, ntmp->dado.valor);
    }

 }

void eMove(pilha *p){
    node *i = (node*) malloc(sizeof(node));
    int valor;
    printf("Digite o valor do Nodo i: ");
    scanf("%d", &valor);
    i->dado.valor = valor;

    if(vazia(p)){
        push(p, i->dado.valor);
    } else {
        //LISTAR
        int aux = p->sizeF;

        while(aux > 0){
            pop(p);
            aux--;
        }

        push(p, i->dado.valor);
    }

 }

void fMove(pilha *p){
    node *i = (node*) malloc(sizeof(node));
    int valor;
    printf("Digite o valor do Nodo i: ");
    scanf("%d", &valor);
    i->dado.valor = valor;

    if(vazia(p)){
        push(p, i->dado.valor);
    } else {
        pilha *ptmp = create();
        node *ntmp = p->prox;

        int aux = p->sizeF;

        while(aux){
            push(ptmp, ntmp->dado.valor);
            if(ntmp->prox != NULL){
                ntmp = ntmp->prox;
            }
            aux--;
        }

        aux = p->sizeF;

        while(aux){
            pop(p);
            aux--;
        }

        push(p, i->dado.valor);

        node *tmp = ptmp->prox;

        while(ptmp->sizeF){
            push(p, tmp->dado.valor);
            tmp = tmp->prox;
            ptmp->sizeF--;
        }

    }

 }

 void gMove(pilha *p){
    node *i = (node*) malloc(sizeof(node));
    int valor;
    printf("Digite o valor do Nodo i: ");
    scanf("%d", &valor);
    i->dado.valor = valor;

    if(vazia(p)){
        push(p, i->dado.valor);
    } else {
        pilha *ptmp = create();
        node *ntmp = p->prox;

        int aux = p->sizeF;

        int aux2 = 1;

        while(aux2 < 3){
            ntmp = ntmp->prox;
            aux--;
            aux2++;
        }

        while(aux){
            push(ptmp, ntmp->dado.valor);
            if(ntmp->prox != NULL){
                ntmp = ntmp->prox;
            }
            aux--;
        }

        aux = p->sizeF;

        while(aux > 2){
            pop(p);
            aux--;
        }

        push(p, i->dado.valor);

        node *tmp = ptmp->prox;

        while(ptmp->sizeF){
            push(p, tmp->dado.valor);
            tmp = tmp->prox;
            ptmp->sizeF--;
        }

    }

 }
