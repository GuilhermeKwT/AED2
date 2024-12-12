
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
using namespace std;

#include "ABB.h"

int main(void)
{
   no *T, *p;
   int x, c;

   T = ini_AB(T);
   
   do 
   {
      printf("\n");
      printf("1 - Insere Item na ARVORE DE BUSCA BINARIA\n");
      printf("2 - EMORDEM -  Lista Itens da ARVORE DE BUSCA BINARIA - Em-Ordem\n");
      printf("3 - PREORDEM - Lista Itens da ARVORE DE BUSCA BINARIA - Pre-Ordem\n");
      printf("4 - POSORDEM - Lista Itens da ARVORE DE BUSCA BINARIA - Pos-Ordem\n");
      printf("5 - PERCURSO EM LARGURA - TA1\n");
      printf("6 - BUSCA Item na ARVORE DE BUSCA BINARIA\n");
      printf("7 - Sair\n");
      printf("\n Escolha: ");

     cin >> c;

      switch(c) {
         case 1: 
			cout << " \nEntre com o item a ser inserido: ";
			cin >> x;
			T = insere_AB(T,x); 
			break;
         case 2: 
			emOrdem_AB(T);
 			printf("\n");	
			break;
         case 3: 
  		    preOrdem_AB(T);
 			printf("\n");	
			break;
         case 4: 
  		    posOrdem_AB(T);
 			printf("\n");	
			break;
		case 5:
			// ** Tema do Trabalho Avaliativo 1 **
			break;
		case 6:
			cout << " \nEntre com o item a ser procurado: ";
			cin >> x;
			// ** a ser desenvolvido pelo aluno **
			// ** o programa deve exibir "Valor ENCONTRADO" ou "Valor NAO ENCONTRADO"  
         busca_AB(T, x);
            break;
		case 7:
			exit(0);
            break;
      };
   } while (c != 7);
}
