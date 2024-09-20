/*
 * ABB.h
 */

typedef struct TreeNo {
	int info;
	struct TreeNo *Llink;
	struct TreeNo *Rlink;
} no;

no *ini_AB(no *T) {
	return NULL;
}

no *insere_AB(no *T, int x) {
	if (T == NULL){
		T = (no *) malloc (sizeof(no));
		T->info = x;
		T->Llink = NULL;
		T->Rlink = NULL;
		return T;
	}
	else {
		if (x < T->info) 
			T->Llink = insere_AB(T->Llink, x);
		else {	 
			T->Rlink = insere_AB(T->Rlink, x);
		}
		return T;
	}
}

void emOrdem_AB(no *T) {
	if(T != NULL) {
		emOrdem_AB(T->Llink);
		printf("\n %d", T->info);	
		emOrdem_AB(T->Rlink);
	}
}

void preOrdem_AB(no *T) {
	if(T != NULL) {
		printf("\n %d", T->info);	
		preOrdem_AB(T->Llink);
		preOrdem_AB(T->Rlink);
	}
}

void posOrdem_AB(no *T) {
	if(T != NULL) {
		posOrdem_AB(T->Llink);
		posOrdem_AB(T->Rlink);
		printf("\n %d", T->info);	
	}
}

no *maior_AB(no *T) {
    no *p;
	if (T != NULL) {
		while (T->Rlink != NULL){
			T = T->Rlink;
		}
		return T;  
	}
	else
		return NULL;
}

int altura_AB(no *T) {
	int aL, aR;
		
	if(T == NULL) {
		return -1;
	}
	else {
		aL = altura_AB(T->Llink);
		aR =  altura_AB(T->Rlink);
		if (aL < aR){
			return (aR+1);
		}
		else{
			return (aL+1);
		}
	}
}

no *remove_AB(no *T, int x){
	no *p;

	if (T == NULL) {
		return NULL;
	}
	else{
		if (x < T->info)
			T->Llink = remove_AB(T->Llink, x);
		else {
			if (x > T->info)
				T->Rlink = remove_AB(T->Rlink, x);
			else {
				//no folha
				if ((T->Llink == NULL) && (T->Rlink == NULL)){
					p = T;
					free(p);
					T = NULL;
					return T;
				}
				else{
					// so tem o filho da direita
					if (T->Llink == NULL){ 
						p = T;
						T = T->Rlink;
						free(p);
						return T;
					}
					else{
						// so tem o filho da esquerda 
						if (T->Rlink == NULL){ 
							p = T;
							T = T->Llink;
							free(p);
							return T;
						}
						else {
							// NO tem 2 filhos 
							p = maior_AB(T->Llink);
							T->info = p->info;
							T->Llink = remove_AB(T->Llink,p->info);
						}
					}
				}
			}
		}
		return T;
	}
}

no *rodaDireita(no *p) {
    no *temp, *q;
	q = p->Llink;
	temp = q->Rlink;
	q->Rlink = p;
	p->Llink = temp;
	return q;
}

void q1(no *p) {
	if (p == NULL){
		return;
	}
	if (p->Llink != NULL && p->Rlink != NULL){
		cout << p->Llink->info << " " << p->Rlink->info << " ";
	}
	q1(p->Llink);
	q1(p->Rlink);
}

void q2(no *T, int x){
	if (x == T->Llink->info || x == T->Rlink->info){
		cout << T->info << endl;
	}
	else if (x < T->info){
		q2(T->Llink, x);
	}
	else {
		q2(T->Rlink, x);
	}
}

void q3(no *T){
	if(T != NULL) {
		q3(T->Rlink);
		printf("\n %d", T->info);	
		q3(T->Llink);
	}
}

no* q4(no *T){
	if (T == NULL){
		return NULL;
	}
	q4(T->Llink);
	q4(T->Rlink);
	delete (T);
	return NULL;
}

int q5(no *T){
	int count = 0;
	if (T == NULL){
		return count;
	}
	count += q5(T->Llink);
	count += q5(T->Rlink);
	count++;
	return count;
}

int q6(no *T){
	int soma = 0;
	if(T == NULL){
		return soma;
	}
	soma += q6(T->Llink);
	soma += q6(T->Rlink);
	soma += T->info;
	return soma;
}

no *rodaEsquerda(no *p) {
    no *temp, *q;
	q = p->Rlink;
	temp = q->Llink;
	q->Llink = p;
	p->Rlink = temp;
	return q;
}

no *q7(no *p, int x){
	if (x == p->info){
		p = rodaEsquerda(p);
	}
	else if (x < p->info){
		p->Llink = q7(p->Llink, x);
	}
	else {
		p->Rlink = q7(p->Rlink, x);
	}
	return p;
}

no *q8(no *p, int x){
	if (x == p->info){
		p = rodaDireita(p);
	}
	else if (x < p->info){
		p->Llink = q8(p->Llink, x);
	}
	else {
		p->Rlink = q8(p->Rlink, x);
	}
	return p;
}

int q9(no *T){
	while (T->Llink != NULL){
		T = T->Llink;
	}
	return T->info;
}

