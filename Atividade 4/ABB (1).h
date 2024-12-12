/*
 * ABB.h
  */

struct no {
	int info;
	no *Llink;
	no *Rlink;
};

no *ini_AB(no *T) {
	return NULL;
}

no *novoNo_AB(no *T, int x) {
	T = new no;
	if (T != NULL) {
		T->info = x;
		T->Llink = NULL;
		T->Rlink = NULL;
	}
	return T;
}

no *insere_AB(no *T, int x) {
	if (T == NULL){
		T = novoNo_AB(T,x);
		return T;
	}
	else {
		if (x < T->info){ 
			T->Llink = insere_AB(T->Llink, x);
		}
		else {	 
				T->Rlink = insere_AB(T->Rlink, x);
		}
		return T;
	}
}

void emOrdem_AB(no *T) {
	if(T != NULL) {
		emOrdem_AB(T->Llink);
		cout << T->info << " ";
		emOrdem_AB(T->Rlink);
	}
}

void preOrdem_AB(no *T) {
	if(T != NULL) {
		cout << T->info << " ";
		preOrdem_AB(T->Llink);
		preOrdem_AB(T->Rlink);
	}
}

void posOrdem_AB(no *T) {
	if(T != NULL) {
		posOrdem_AB(T->Llink);
		posOrdem_AB(T->Rlink);
		cout << T->info << " ";
	}
}

// ** PERCURSO EM LARGURA - TRABALHO AVALIATIVO 1 **

// ** funcao buscaAB - a ser desenvolvida pelo aluno **
bool busca_AB(no *T, int x) {
	while (T != NULL){
		if (T->info == x){
			cout << "Valor ENCONTRADO" << endl;
			return 1;
		}
		else if (T->info > x){
			T = T->Llink;
		}
		else {
			T = T->Rlink;
		}
	}
	cout << "Valor NAO ENCONTRADO" << endl;
	return 0;
}

