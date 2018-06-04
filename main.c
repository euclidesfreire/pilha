#include <stdio.h>
#include <stdlib.h>

//DEFINE OS DADOS DA PILHA
typedef struct {
    char seq;
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
node *alocar(pilha *p, char s){

    node *novo = (node *) malloc(sizeof(node));

    if(!novo) {
        printf("Sem memoria disponivel\n");
        exit(1);
    } else{
        //ATRIBUI S = CARACTER(COLCHETES OU PARANTESES) AO DADO DO NODE
        novo->dado.seq = s;

        return novo;
    }

}
//ADICIONAR UM NODE AO FINAL DA PILHA
//RECEBE A PILHA E UM CARACTER (COLCHETES OU PARANTESES)
node *push(pilha *p, char s) {
    node *novo = alocar(p, s);

    //VERIFICAR SE A FILA ESTA VAZIA
    if(vazia(p)){
        p->prox = novo;
    } else {
        node *tmp = p->prox;
        //PROCURA O FINAL DA FILA
        while(tmp->prox != NULL){
            tmp = tmp->prox;
        }
        tmp->prox = novo;
    }

    return novo;
}

//REMOVE UM NODE DO FINAL DA PILHA
char pop(pilha *p){

     if(vazia(p)){
        printf("Pilha já esta vazia!\n");
        return NULL;
    } else {
        //PARA PEGAR O NODE ANTERIOR E POSTERIOR
        node *ultimo = p->prox,
              *penultimo = p;

        while(ultimo->prox != NULL){
            penultimo = ultimo;
            ultimo = ultimo->prox;
        }
        //FAZ O ANTERIOR EM RELAÇÃO AO ULTIMO NODE AGORA APONTAR PARA NULL
        penultimo->prox = NULL;

        //RETORNA O CARACTER
        return ultimo->dado.seq;
    }
}

//DESTROI A PILHA
void destroy(pilha *p){
  if (vazia(p)) {
    printf("A PILHA esta vazia!\n");
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

//INSERIR OS CARACTER NA PILHA VERIFICANDO SE ESTAO BEM FORMADOS
int pDone(pilha *p){
    //VETOR PARA OS ACARCTERES
    char stringSeq[] = "\0";
    int i;

    //ENTRADA DOS CARACTER
    printf("Digite a sequencia: ");
    scanf("%s", &stringSeq);

    //ANDA ATÉ O FINAL DO VETOR
    for(i = 0; stringSeq[i] != '\0'; i++){
        char c;
            //ANALISA SE O COLCHETE OU PARANTESES SÃO FECHADOS, ENTAO CHAMA pop, ATÉ O FINAL DO VETOR OU
            //ATÉ FOR VERIFICADO UM ERRO NA FORMCAO DOS CARACTERES
            switch (stringSeq[i]) {
                case ')':
                    if(vazia(p)) return 0;
                    c = pop(p);
                    if(c != '(') return 0;
                    break;
                case ']':
                    if(vazia(p)) return 0;
                    c = pop(p);
                    if(c != '[') return 0;
                    break;
                default:
                    push(p, stringSeq[i]);
            }
    }

    return 1;

}

void menu() {
  //printf("IA = %3d; FA = %3d;\nIL = %3d; FL = %3d;\n", ll.ia, ll.fa, ll.il, ll.fl);
  printf ("========== [ ( PILHA ) ]  ==========\n\n");
  printf ("1 - Digitar e Verificar Sequencia\n");
  printf ("0 - Sair\n");
  printf ("\n");
  printf ("Informe a opcao desejada: ");
}

main() {
  pilha *PILHA;
  PILHA = create();

  int t;
  int k = -1;
  int op = -1;

  do {
    system("cls || clear");
    menu();
    scanf("%d", &op);

     switch (op) {
      case 1:
        t = pDone(PILHA);
        printf("%d\n", t);
        //SE A FUNÇÃO ESTA VAZIA ENTAAO A SEQUENCIA ESTA BEM FORMADA SENAO NAO ESTA BEM FORMADA
        if(t) {
            printf("A sequencia esta correta");
        } else {
            printf("A sequencia esta errada");
        }
        destroy(PILHA);
        PILHA = create();
        break;
    }
    //Sequencia de comandos equivalentes ao system("pause");
    getchar();
    scanf("c\n");
  } while (op != 0);
}
