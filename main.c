#include <stdio.h>
#include <stdlib.h>
#include "pilha.c";

void menu() {
  printf ("========== [  PILHA  ]  ==========\n\n");
  printf ("1 - PUSH\n");
  printf ("2 - POP\n");
  printf ("3 - View Pilha\n");
  printf ("4 - (a) Definir i com o segundo elemento a partir do topo da pilha, \ndeixando a pilha sem seus dois elementos superiores\n");
  printf ("5 - (b) Definir i com o segundo elemento a partir do topo da pilha, \ndeixando a pilha inalterada.\n");
  printf ("8 - (e) Definir i como o ultimo elemento da pilha, deixando a pilha vazia.\n");
  printf ("9 - (f) Definir i como o ultimo elemento da pilha, deixando a pilha inalterada.\n");
  printf ("10 - (g) Definir i como o terceiro elemento a partir do final da pilha.\n");
  printf ("\n0 - Sair\n");
  printf ("\n");
  printf ("Informe a opcao desejada: ");
}

main() {
  pilha *PILHA;
  PILHA = create();

  int op = -1;
  int valor;

  do {
    system("cls || clear");
    menu();
    scanf("%d", &op);

     switch (op) {
      case 1:
          printf("Digite um valor: ");
          scanf("%d", &valor);
          push(PILHA, valor);
        break;
      case 2:
          valor = pop(PILHA);
          if(valor != NULL)
            printf("\n{ %d } - REMOVIDO\n", valor);
        break;
      case 3:
          viewPilha(PILHA);
        break;
      case 4:
          aMove(PILHA);
        break;
      case 5:
          bMove(PILHA);
        break;
      case 8:
          eMove(PILHA);
        break;
      case 9:
          fMove(PILHA);
          break;
      case 10:
          gMove(PILHA);
        break;
      case 0:
        return 0;
      default:
        break;
    }
    //Sequencia de comandos equivalentes ao system("pause");
    getchar();
    scanf("c\n");
  } while (op != 0);
}
