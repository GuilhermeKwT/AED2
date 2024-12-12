#include <iostream>

#define ORDER 4

using namespace std;

template <int ORDEM>
struct noBTree {
    int chaves[ORDEM - 1]; 
    noBTree *filhos[ORDEM]; 
    int count; 

    noBTree() : count(0) {
        for (int i = 0; i < ORDEM - 1; i++) {
            chaves[i] = 0; 
        }
        for (int i = 0; i < ORDEM; i++) {
            filhos[i] = nullptr;
        }
    }
};


//Realiza o split de um nó da árvore B
template <int ORDEM>
void splitFilho(noBTree<ORDEM>* N, int i) {
    noBTree<ORDEM> *F = N->filhos[i];
    noBTree<ORDEM> *P = new noBTree<ORDEM>();
    P->count = ORDEM / 2 - 1;

    // Move a metade superior das chaves de F para P
    for (int j = 0; j < ORDEM / 2 - 1; j++) {
        P->chaves[j] = F->chaves[j + ORDEM / 2];
    }

    // Move os filhos de F para P
    if (F->filhos[0] != nullptr) {
        for (int j = 0; j < ORDEM / 2; j++) {
            P->filhos[j] = F->filhos[j + ORDEM / 2];
        }
    }

    F->count = ORDEM / 2 - 1;

    // Desloca os filhos de N para abrir espaço para P
    for (int j = N->count; j >= i + 1; j--) {
        N->filhos[j + 1] = N->filhos[j];
    }
    N->filhos[i + 1] = P;

    // Desloca as chaves de N para abrir espaço para a chave mediana de F
    for (int j = N->count - 1; j >= i; j--) {
        N->chaves[j + 1] = N->chaves[j];
    }
    N->chaves[i] = F->chaves[ORDEM / 2 - 1];
    N->count++;
}

//Insere um valor em uma árvore B caso não esteja cheia
template <int ORDEM>
void insereNaoCheioBTree(noBTree<ORDEM>* N, int valor) {
    int i = N->count - 1;

    if (N->filhos[0] == nullptr) {
        while (i >= 0 && valor < N->chaves[i]) {
            N->chaves[i + 1] = N->chaves[i];
            i--;
        }
        N->chaves[i + 1] = valor;
        N->count++;
    } else { 
        while (i >= 0 && valor < N->chaves[i]) {
            i--;
        }
        i++;
        if (N->filhos[i]->count == ORDEM - 1) {
            splitFilho(N, i);
            if (valor > N->chaves[i]) {
                i++;
            }
        }
        insereNaoCheioBTree(N->filhos[i], valor);
    }
}

//Insere um valor em uma árvore B
template <int ORDEM>
noBTree<ORDEM>* insereBTree(noBTree<ORDEM>* N, int valor) {
    if (N->count == ORDEM - 1) {
        noBTree<ORDEM> *S = new noBTree<ORDEM>();
        S->filhos[0] = N;
        splitFilho(S, 0);
        insereNaoCheioBTree(S, valor);
        return S;
    } else {
        insereNaoCheioBTree(N, valor);
        return N;
    }
}

//Imprime os valores da arvore B em ordem
template <int ORDEM>
void impressaoEmOrdem(noBTree<ORDEM> *N){
    int i;
    for (i = 0; i < N->count; i++) {
        if (N->filhos[0] != nullptr){
            impressaoEmOrdem(N->filhos[i]);
        }
        cout << " " << N->chaves[i];
    }

    if (N->filhos[0] != nullptr){
        impressaoEmOrdem(N->filhos[i]);
    }
}

int main(){
    noBTree<ORDER> *N = new noBTree<ORDER>();
    int c, valor;

    do {
        printf("\n");
        printf("1 - Insere Item na ARVORE B\n");
	    printf("2 - Valores em Ordem\n");
        printf("3 - Sair\n");
        printf("\n Escolha: ");

        cin >> c;

        switch (c){
            case 1:
                cout << " \nEntre com o item a ser inserido: ";
                cin >> valor;
                N = insereBTree(N, valor);
                break;
            case 2:
                impressaoEmOrdem(N);
                break;
            case 3:
                exit(0);
                break;
        }
    } while (c != 3);

    return 0;
}
