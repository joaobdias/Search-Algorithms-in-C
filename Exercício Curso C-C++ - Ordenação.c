#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

////////////// BUSCAS //////////////////

void buscaseq (int *vet, int tam, int elem){
	int aux;
	
		for(aux = 0; aux <= tam; aux++){
			if (vet[aux] == elem){
			printf("Elemento encontrado:\n");
			printf("Elemento [%d] = %d\n", aux,elem);
			system("pause");
			return;
  }
}
			printf("Elemento n�o encontrado no vetor\n");
			system("pause");
} 

void buscaseqor (int *vet, int tam, int elem){
	int aux;
	
		for(aux = 0; aux <= tam; aux++){
			if (vet[aux] == elem){
			printf("Elemento encontrado:\n");
			printf("Elemento [%d] = %d\n", aux,elem);
			system("pause");
			return;
    }
			else if (elem < vet[aux]){
  			printf("Elemento n�o encontrado no vetor\n");
			system("pause");
			return;
    }
  }			
}

void buscabin (int *vet, int tam, int elem){
	
	int meio;
	int inicio, fim;
	inicio = 0;
	fim = tam;
	
	while (inicio <= fim){
		meio = (inicio+fim)/2;
		if (vet[meio] == elem){
			printf("Elemento encontrado:\n");
			printf("Elemento [%d] = %d\n", meio,elem);
			system("pause");
			return;
		}
		else if (elem < vet[meio])
			fim = meio-1;
		else 
			inicio = meio+1;
	}
		printf("Elemento n�o encontrado no vetor\n");
		system("pause");
		return;
}




///////////////////////////////////////



void bubblesort(int *vet,int tam){
	
	int aux1,aux2,aux3;
	
	for(aux1 = 0; aux1 <= tam; aux1++){
		for(aux2 = aux1 + 1; aux2<= tam; aux2++){
			if(vet[aux1] > vet[aux2]){
				aux3 = vet[aux1];
				vet[aux1] = vet[aux2];
				vet[aux2] = aux3;
			}
		}
	}
}

void selectionsort(int *vet, int tam) {
	
	int aux1,aux2,aux3,menor;
	
	for (aux1 = 0; aux1 <= tam; aux1++) {
		menor = aux1;
			for (aux2 = aux1+1; aux2 <= tam; aux2++) {
				if (vet[aux2] < vet[menor]) {
					menor = aux2;
 }
}
		if (menor != aux1){
			aux3 = vet[aux1];
			vet[aux1] = vet[menor];
			vet[menor] = aux3;
  }
 }
}

void insertionsort(int *vet, int tam){
	int aux1,aux2,atual;
	
	for (aux1 = 1; aux1 <= tam; aux1++) { 
		atual = vet[aux1]; 
		
		for (aux2 = aux1; (aux2 >= 0) && (atual < vet[aux2-1]); aux2--) 
				vet[aux2] = vet[aux2-1];			
		vet[aux2] = atual;
 }
}

void merge(int *vet, int inicio,int meio, int fim){
	int *temp, p1, p2, tamanho,i,j,k;
	int fim1 = 0, fim2 = 0;
	tamanho = fim - inicio + 1; // tamanho da array, funcionando para a parti��o que est� sendo processada
	p1 = inicio;
	p2 = meio+1;
	temp = (int*) malloc(tamanho*sizeof(int)); /*aloca��ode �rea na mem�ria para armazenar um array
	tempor�rio definido pelo tamanho*/
	
	/*a array tempor�ria vai receber os menores valores das arrays divididas (que s�o peda�os da array
	original). O for abaixo compara os valores de cada uma das metades e pega o menor e o armazena
	na array tempor�ria (que usa malloc para armazenar uma array com tamanho variavel, por isso usa
	malloc)*/
	
	if (temp != NULL){
		
		for (i=0; i<tamanho; i++){ //percorre o peda�o do vetor que ser� analisado
			
			if ((fim1 == 0) && (fim2 == 0)){ //se j� nao tiver sido totalmente analisada a metade do vetor
	
				if (vet[p1] < vet[p2]){ //compara os valores das duas metades do vetor (tamanho variado do vetor total) 
					temp[i] = vet[p1];
					p1++;
}
				else {
					temp[i] = vet[p2];
					p2++;
}
				if (p1>meio) 
					fim1=1; // quando termina de analisar a metade do vetor, indica o fim da metade
				if (p2>fim) 
					fim2=1; // quando termina de analisar a metade do vetor, indica o fim da metade
} 
				else { // aqui, a metade que ainda n�o foi analisada totalmente � totalmente passada ao vetor tempor�rio
				if (fim1==0)
					temp[i] = vet[p1++];
				else
					temp[i] = vet[p2++];
			 }
		}
		
		for (j=0, k=inicio; j<tamanho; j++, k++) // looping para passar os valores organizados no array tempor�rio para o original
			vet[k] = temp[j];
	}
	
	free(temp); //libera o espa�o da mem�ria utilizado para o array tempor�rio
	
}

void mergesort(int *vet,int inicio,int fim){
	int meio;
	if(inicio < fim){
		meio = floor((inicio+fim)/2); // retorna um inteiro de um poss�vel retorno float
		mergesort(vet,inicio,meio); //aqui � o calculo da primeira metade (do inicio ao meio) do array
		mergesort(vet,meio+1,fim); //aqui � o calculo da outra metade (meio+1 ao fim) do array
		
		/*nessa recurs�o acima, ela vai fazendo at� n�o conseguir mais dividir (inicio >= fim) e ent�o,
		a partir disso, ela volta, chamando merge com os par�metros de cada recurs�o feita*/
		
		merge(vet,inicio,meio,fim); /* ap�s todo o array ser dividido em v�rios peda�os pelas recurs�es
		acima, come�a a etapa de intercala��o do array*/
		/*esta fun��o � chamda v�rias vezes at� o array original for totalmente feito ordenadamente*/
	}
}

int particiona (int *vet, int inicio,int final){
	int esq,dir,pivo,aux; 
	esq = inicio; // o inicio da parti��o ficar� na variavel auxiliar esq
	dir = final; // o final da parti��o ficar� na variavel auxiliar dir
	pivo = vet[inicio]; //o piv�
	
while (esq < dir){ // looping para parar quando os indices da direita e esquerda se encontrarem 
	while(vet[esq] <= pivo) { // incrementa os elementos da esquerda enquanto os valores forem menor que o pivo
		esq++;
	}
	while (vet[dir] > pivo) { // incrementa os elementos da direita enquanto os valores forem maior que o pivo
		dir--;
	}
	
	/*vale ressaltar que o while s� sai no momento que a condi��o � quebrada. Dessa forma, � analisado os 
	elementos da esquerda primeiro e depois o da direita, e se um dos dois quebra a condi��o, o looping 
	continua sem contar o outro looping, e depois que os dois quebrarem, vem o if e faz a troca. Esse
	processo � repetido at� os lados se encontrarem, at� chegar ao centro*/
	
if (esq < dir){ /* compara os indices esquerda e direita para se certificar de trocar valores que est�o
	a esquerda e o outro a direita do centro, sem se cruzarem*/
		aux = vet[esq];
		vet[esq] = vet[dir];
		vet[dir] = aux;
	}
  }    
  
  /* at� essa parte do codigo, � entend�vel, afinal, vai sendo percorrido os elementos da esquerda
  at� encontrar um maior, depois os da direita at� um menor, e caso haja algum n�mero fora de ordem, como maior na esquerda
  ou menor na direita, � feita a troca. Esse processo continua at� os elementos da direita encontrarem o da esquerda, ou seja,
  percorrerem toda a parti��o.*/
  
  	vet[inicio] = vet[dir]; 	  
  	vet[dir] = pivo; //OBS: pivo = vet[inicio]; 
  	
  	/*a rela��o que consigo pensar do pivo com o vet[dir] � que ele seria o elemento mais pr�ximo do centro para servir como
	pivo para dividir a array em mais 2 peda�os. E toda vez que vet[dir] � passado, ele � o elemento mais do centro da parti��o,
	sendo o elemento ideal para ser o piv� na proxima chamada, e dividindo essa array em v�rios peda�os*/
	
  	return dir; // retorna o dir como o novo pivo
}

void quicksort(int *vet, int inicio,int fim){
	int pivo; // pivo que � o centro da parti��o e ser� usado como par�metro
	
	if (fim > inicio){ // se o final for maior que o inicio (se ainda tiver elementos para verificar no vetor)
		pivo = particiona(vet,inicio,fim); // pivo ser� o que retornar de particion (o vet[dir] que � o elementos mais pr�ximo do centro)
		quicksort(vet,inicio,pivo-1); // aqui, � calculado o lado esquerdo do pivo, sendo o inicio 0 at� 1 elemento antes do pivo
		quicksort(vet,pivo+1,fim); // aqui � calculado o lado direito do pivo, sendo o primeiro elemento ap�s o pivo central at� o fim do vetor
		
		/*ap�s a chamada desses dois quicksort, h� uma recurs�o de particiona para o lado esquerdo e direito, e ap�s voltarem, se ainda n�o
		tiver totalmente fragmentado o vetor, ser� particionado novamente*/
	}
}

void criaHeap(int *vet,int pai, int fim) {
	int aux = vet[pai]; // pai armazenado em auxiliar
	
	int filho = 2*pai+1; // c�lculo do primeiro filho (o segundo � s� somar +1)

	while(filho <= fim){ // enquanto posi��o do filho na array existir (percorrer todo array)
	
		if (filho < fim){ // se a posi��o do filho existir na array
			if (vet[filho] < vet[filho + 1]){ // esse filho � menor que o filho da direita?
				filho++; // se sim, vai pro da direita, j� que ele � maior
			}
		}
		// se o pai for menor que o filho, troca essa merda ne, pai � maior caralho
		if (aux < vet[filho]){
			vet[pai] = vet[filho];
			pai = filho;
			
			filho = 2*pai+1; //j� v� se o pai que desceu tem mais filhos ainda
		} else {
			filho = fim + 1; // pera, ent�o o pai � maior nessa merda? Ah, entao deixa baixo, ACABA A FUN��O
		}
	}
	vet[pai] = aux;	/*se ele ja saiu do looping, viu que o novo pai nao tem filhos, ai armazena no vet[pai], que 
	nada mais � do que a posi��o nova que o pai possui ap�s trocar com o filho, o valor do pai antigo no local do filho que trocou de posi��o com ele*/
}

void heapSort(int *vet,int N){
	int i, aux;
	for (i=N/2; i >= 0; i--){ /*respons�vel por fazer toda a organiza��o inicial do vetor em
	pais e filhos, com pais maiores que os filhos. Alem disso, o i = N/2 pelo fato de a an�lise
	ocorrer apenas nos pais, que por sua vez j� compara com os filhos, necessitando de metade das 
	an�lises*/
	
		criaHeap(vet,i,N); // passando o �ndice de baixo para cima (numero maior = baixo)
}
  	for (i = N; i>= 1; i--){ /* nessa parte do c�digo, a �rvore j� foi organizada. Por isso,
	  os elementos que est�o em cima s�o enviados para a ultima posi��o do array, construindo-o
	  de tr�s para frente. E a cada remo��o, � considerado um array com uma posi��o a menos (i-1)
	  para que o pr�ximo elemento fique na pr�xima posi��o (logo ap�s o inserido anteriormente).
	  Ele chama criaHeAP para verificar se o elemento trocado � o ideal para ficar no topo, e se n�o
	  for, reorganiza na ordem do heap*/
  		aux = vet[0]; 
  		vet[0] = vet[i]; 
  		vet[i] = aux;
  		criaHeap(vet,0,i-1); /* envia o novo topo sem contar o ultimo elemento (inserido anteriormente)
		para verificar se esse topo � o maior elemento para inserir*/
  }
}


void main(){
	
	setlocale(LC_ALL,"Portuguese");
	int tam,i,n,aux;
	bool sair = false;
	bool ordenada = false;
	
	printf("Digite o tamanho do vetor desejado: ");
	scanf("%d",&tam);
	tam = tam - 1;
	
	int vetor[tam];
	
	for (i = 0; i<=tam; i++){
		printf("\nO valor que ser� inserido: ");
		scanf("%d",&aux);
		vetor[i] = aux;
	}
	
	printf("\n");
	system("pause");
	
do {
	system("cls");
	fflush(stdin);
	printf("Digite o que deseja fazer: ");
	printf("\n1 - Imprimir");
	printf("\n2 - Busca sequencial/linear");
	printf("\n3 - Busca sequencial/linear ordenada");
	printf("\n4 - Busca bin�ria");
	printf("\n5 - Bubblesort");
	printf("\n6 - Selectionsort");
	printf("\n7 - Insertionsort");
	printf("\n8 - Quicksort");
	printf("\n9 - Mergesort");
	printf("\n0 - Heapsort");
	printf("\nOutro - Sair\n");
	scanf("%d",&aux);
	
	system("cls");
	switch(aux){
		case 1:
			for (i = 0; i<=tam; i++){
			printf("Elemento [%d] = %d",i,vetor[i]);
			printf("\n");
}
			system("pause");
			break;
		case 2:
			system("cls");
			printf("Digite o elemento a ser procurado: ");
			fflush(stdin);
			scanf("%d",&n);
			buscaseq(vetor,tam,n);
			break;
		case 3:
		if (ordenada == true){
			system("cls");
			printf("Digite o elemento a ser procurado: ");
			fflush(stdin);
			scanf("%d",&n);
			buscaseqor(vetor,tam,n);
} 			
		else {
			printf("Vetor n�o ordenado, imposs�vel buscar\n");
			system("pause");
}
			break;
		case 4:
		if (ordenada == true){
			system("cls");
			printf("Digite o elemento a ser procurado: ");
			fflush(stdin);
			scanf("%d",&n);
			buscabin(vetor,tam,n);
}
		else {
			printf("Vetor n�o ordenado, imposs�vel buscar\n");
			system("pause");			
}
			break;
		case 5:
			bubblesort(vetor,tam);
			ordenada = true;
			break;
		case 6:
			selectionsort(vetor,tam);
			ordenada = true;
			break;
		case 7:
			insertionsort(vetor,tam);
			ordenada = true;
			break;
		case 8:
			quicksort(vetor,0,tam);
			ordenada = true;
			break;
		case 9:
			mergesort(vetor,0,tam);
			ordenada = true;
			break;
		case 0:
			heapSort(vetor,tam);
			ordenada = true;
			break;
		default:
			sair = true;
			break;
}
} while (sair == false);
}
	
	

