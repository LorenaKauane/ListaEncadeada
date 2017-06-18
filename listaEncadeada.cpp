
#include <iostream>

using namespace std;

class Node{
public:
	int elemento;
	Node * proximo; 
};

class ListaEnc{
	
	Node * inicio;
	int quantidade_de_elementos;
public:
	ListaEnc(){
		inicio = NULL;
		quantidade_de_elementos = 0;
	}
	//Destrutor 
	~ListaEnc(){
		/*Node * aux;
		aux = inicio;
		while(aux!=NULL){
			inicio = inicio->proximo;
			delete aux;
			aux= inicio;
		}*/
	}
	
	bool estaVazia(){
		if(quantidade_de_elementos == 0){
			return true;
		}else{
			return false;
		}
	}
	
	bool verificaPosicaoValida(int posicao){
		if(posicao > quantidade_de_elementos){
			return false;
		}else{
			return true;
		}
		
	}
	/*========== Inserções ========== */
	bool insereInicio(int elemento){
		Node * aux 	  = new Node;
		aux->elemento = elemento;
		aux->proximo = inicio;
		inicio = aux;

		quantidade_de_elementos++;
		return true;
	}
	
	bool insereFim(int elemento){
		Node * no;

		if(quantidade_de_elementos ==0){
			insereInicio(elemento);	
		}else{
			no = new Node;
			no->elemento = elemento;
			no->proximo = NULL;
			
			Node * aux = inicio;
			
			while(aux->proximo != NULL){
				aux = aux->proximo;
			}
			aux->proximo = no;	
			quantidade_de_elementos++;	
		}

		
		return true;
	}
	
	bool inserePosicao(int posicao, int elemento){
		if(verificaPosicaoValida(posicao)){
			if(posicao==0){
				//Inicio
				insereInicio(elemento);
			}else if(posicao == quantidade_de_elementos){
				//Fim
				insereFim(elemento);
			}else{
				//Meio
				Node * atual 	= inicio;
				Node * anterior;
				Node * no = new Node;
				no ->elemento = elemento;
				for(int i =0; i< posicao;i++){
					anterior = atual;
					atual = atual-> proximo;
				}
				no->proximo = atual;
				anterior->proximo = no;	
				quantidade_de_elementos++;
			}
		}else{
			return false;
		}
		return true;
	}
	
	
	/*========== Remover ========== */
	void removeInicio(){
		Node * no = inicio;
		inicio = no -> proximo;
		delete no;
		quantidade_de_elementos--;
	}
	
	void removeFim(){
		Node * no = inicio;
		Node * anterior;	
		while(no->proximo != NULL){
			anterior = no;
			no = no->proximo;
		}

		anterior->proximo = no->proximo;
		quantidade_de_elementos--;
		delete no;
	}
	
	void removeMeio(int posicao){
		Node * atual 	= inicio;
		Node * anterior;

		for(int i =0; i< posicao;i++){
			anterior = atual;
			atual = atual-> proximo;
		}
		
		if(atual == NULL){
			cout<<"Não foi encontrado!";
		}else{
			anterior->proximo = atual->proximo;	
			delete atual;
			quantidade_de_elementos--;
		}		
	}
	
	bool removeElemento(int posicao){
		
		if(estaVazia()){
			cout<<"Lista Vazia!!!!!\n";
			return false;
		}else{
			if(verificaPosicaoValida(posicao)){
				if(posicao==0){
					//Inicio
					removeInicio();
				}else if(posicao == quantidade_de_elementos-1){
					//Fim
					removeFim();
				}else{
					//Meio
					removeMeio(posicao);
				}
				
				return true;
			}else{
				cout<<"POSICAO INVALIDA!\n";
				return false;
			}
		}
	
		
		
	}
	
	/*========== Impressoes ========== */
	void imprimeInicio(){
		if(estaVazia()){
			cout << "A LISTA estÃ¡ vazia!" << endl;
		}else{
			cout << inicio->elemento << endl;
		}
	}
	
	void imprimeFim(){
		if(estaVazia()){	
			cout << "A LISTA estÃ¡ vazia!" << endl;
		}else{
			Node * aux = inicio;
			
			while(aux->proximo != NULL){
				aux = aux->proximo;
			}
			cout<<aux->elemento;
		}
	}
	
	void imprimeTamanhoLista(){
		cout << "A Lista possui " << quantidade_de_elementos << " elementos!" << endl;
	}
	
	void imprimeLista(){
		if(estaVazia()){
			cout<<"TA VAZIA!!";
		}else{
			Node * aux;
			aux = inicio;
			for(int i =0;quantidade_de_elementos > i;i++){
				cout<<" [ "<<i<<" ] -";
				cout<<aux->elemento<<endl;
				aux = aux->proximo;
			}
		}
		
	}
	void imprimeFilaRecursiva(Node * aux){
		if(aux == NULL){
			return;
		}else{
			cout<<aux->elemento<<endl;
			aux = aux->proximo;
			imprimeFilaRecursiva(aux);
		}
	}
	void imprimeListaRecursiva(){
		imprimeFilaRecursiva(inicio);
	}
	
	/*========== Buscas ========== */
	void buscaIndice(int posicao){
		if(estaVazia()){
			cout<<"Não foi possivel buscar lista vazia!\n";
		}else{
			if(verificaPosicaoValida(posicao)){
				Node * aux = inicio;
				
				for(int i=0; i<posicao;i++){
					aux = aux->proximo;
				}
				cout<<aux->elemento<<endl;
			}else{
				cout<<"Posição INVALIDA!!\n";
			}	
		}
	}
	
	void buscaElemento(int elemento){
		Node * aux = inicio;
		int i = 0;
		int verificacao = 0;
		
		for(i=0; i<=quantidade_de_elementos;i++){
			if(aux->elemento == elemento){
				cout<<"Indice deste elemento é : " <<i<<endl;
				verificacao =1;
				break;
			}
			aux = aux->proximo;	
		}
		if(verificacao!=1){
			cout<<"NÃO FOI ENCONTRADO ESTE ELEMENTO";
		}
	}

};

int main(){
	char opcao;
	int elemento;
	ListaEnc p = ListaEnc();
	int posicao = 0;
	system("cls");
	while(1){
		cout << "--Lista de Inteiros--" 			<< endl;
		cout << "1 - Inserir elemento do inicio" 	<< endl;
		cout << "2 - Inserir elemento do fim" 		<< endl;
		cout << "3 - Inserir elemento da posição" 	<< endl << endl;
		cout << "4 - Remover elemento" 				<< endl << endl;
		cout << "5 - Imprime elemento do inicio"	<< endl;
		cout << "6 - Imprime elemento do fim" 		<< endl;
		cout << "7 - Imprime tamanho da pilha" 		<< endl;
		cout << "8 - Imprime  Lista" 				<< endl;
		cout << "9 - Imprime  Lista recursiva" 		<< endl << endl;
		cout << "A - Busca pelo indice"				<< endl;
		cout << "B - Busca pelo elemento" 			<< endl;
		cout << "0 - Sair" 							<< endl;
		cout << "Escolha uma opÃ§Ã£o: ";
		cin >> opcao;
		switch(opcao){
			case '1' : 
						//Inicio
						system("cls");
						cout << "--Lista de Inteiros--" << endl;
						cout << "Insira o elemento: ";
						cin >> elemento;
						system("cls");
						if(p.insereInicio(elemento)){
							cout << "Elemento inserido com sucesso!" << endl;
						}else{
							cout << "Erro ao inserir elemento! A Lista estÃ¡ cheia!" << endl;
						}
						break;
			case '2' : 
						//Fim
						system("cls");
						cout << "--Lista de Inteiros--" << endl;
						cout << "Insira o elemento: ";
						cin >> elemento;
						if(p.insereFim(elemento)){
							cout << "Elemento inserido com sucesso!" << endl;
						}else{
							cout << "Erro ao inserir elemento! A Lista estÃ¡ cheia!" << endl;
						}
						break;
			case '3' : 
						//Posicao
						system("cls"); 
						cout << "--Lista de Inteiros--" << endl;
						cout << "Insira o elemento: ";
						cin >> elemento;
						cout << "Insira a posicao: ";
						cin >> posicao;
						if(p.inserePosicao(posicao,elemento)){
							cout << "Elemento inserido com sucesso!" << endl;
						}else{
							cout << "Erro ao inserir elemento!" << endl;
						}
						break;
			case '4' : 
						//remover
						system("cls");
						cout << "Insira a posicao: ";
						cin >> posicao;
			 			if(p.removeElemento(posicao)){
							cout << "Elemento removido com sucesso!" << endl;
						}else{
							cout << "Erro ao remover elemento! " << endl;
						}
						break;
			case '5' : 
						//Imprime inicio
						system("cls"); 
						p.imprimeInicio();
						break;
			case '6' : 
						//Imprime fim
						system("cls"); 
						p.imprimeFim();
						break;
			
			case '7' :
						//imprime tamanho
						system("cls"); 
						p.imprimeTamanhoLista();
			break;
			
			case '8' :
						//Imprime lista
						system("cls"); 
						p.imprimeLista();
			break;
			
			case '9' :
						//imprime recursiva
						system("cls"); 
						p.imprimeListaRecursiva();
			break;
			
			case 'A' :
						//Busca indice
						system("cls"); 
						cout << "Insira a posicao: ";
						cin >> posicao;
						p.buscaIndice(posicao);
			
			break;
			
			case 'B' :
						//Busca elemento
						cout << "Insira o elemento ";
						cin >> elemento;
						p.buscaElemento(elemento);
			break;					
			
			case '0' : system("cls");  return 0; break;
		}
	}
	return 0;
}
