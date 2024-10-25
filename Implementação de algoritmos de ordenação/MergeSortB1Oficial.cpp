#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;

void merge(int *a, int p, int q, int r);

void mergeSort(int *a, int p, int r);


int main() {
    int n;
    int *vetor;
    int i;
    int c;
    //solicita ao usuário informar os elementos para ordenar
    cout<<"vetor de teste [8, 7, 6, 9, 5, 10, 11]"<<endl;
    
    cout<<"Digite o numero 7 para realizar o teste para ordenar o vetor a cima!"<<endl;
    cin>>n;
    //mostra a quantidade de posições do vetor para digitar os elementos
    vetor = new int[n];
    cout << "Vetor criado com " << n << " posicoes!" << endl;
    //solicita ao usuário digitar os elementos
    cout << "Digite o elementos acima para o teste"<<endl;
	for(c = 0; c < n; c++){
		cout<<" "<<endl;
		cin>>vetor[c];
	}
	//mostra o vetor "desordenado" com os elementos digitados 
    cout<<"Vetor desordenado: "<<endl;
    cout<<"[";
    for (int cont = 0; cont < n; cont++) {
    cout<<vetor[cont]<<" ";
	}
   	cout<<"]"<<endl;
    cout<<"----------------"<<endl;
    //chamado função mergeSort
        mergeSort(vetor, 0, n - 1);
    // mostra vetor ordendo após a operação
    cout << "Vetor ordenado: "<<endl;
    cout<<"[";
    for (int cont_dois = 0; cont_dois < n; cont_dois++) {
    cout<<vetor[cont_dois]<<" ";
	}
   	cout<<"]"<<endl;
    cout<<"----------------"<<endl;
  
    
}

 // função merge
void merge(int *a, int g, int q, int r) {
    int num1;
	int num2;
	int i;
	int j; 
	int k;
    int *ladoDireito;
	int *ladoEsquedo;
    int somaMinEsquerdo = 0;
    int somaMaxEsquerdo = 0;
    int somaMinDireito = 0;
    int somaMaxDireito = 0;
     

    num1 = q - g + 1;
    num2 = r - q;
    ladoEsquedo = new int[num1 + 1];
    ladoDireito = new int[num2 + 1];
    int numeroComp; // numeroComp
    int numeroTroca; // numeroTroca
    numeroTroca = 0;
    numeroComp = 0;
    for (i = 0; i < num1; i++) {
        ladoEsquedo[i] = a[g + i];
        numeroTroca++;
    } 
    for (j = 0; j < num2; j++) {
        ladoDireito[j] = a[q + j+1];
        numeroTroca++;
    }
    ladoEsquedo[num1] = INT_MAX;
    ladoDireito[num2] = INT_MAX;

   cout<<"/////////////////"<<endl; 
    printf("---- MERGE LADO ESQUERDO: ----");
    for (i = 0; i < num1; i++)
    
    {   
        somaMinEsquerdo = somaMinEsquerdo + ladoEsquedo[0]; 
        somaMaxEsquerdo = somaMaxEsquerdo + ladoEsquedo[num1-1];
        cout << endl;
        cout<<"incremento minimo "<<ladoEsquedo[0]<<endl;
        cout<<"incremento maximo "<<ladoEsquedo[num1-1]<<endl;
    }
    

       float mediaMinEsq, mediaMaxEsq;
       mediaMinEsq = somaMinEsquerdo/2;
       mediaMaxEsq = somaMaxEsquerdo/2;
       cout<<"Total Minimo: "<<somaMinEsquerdo<<endl;
       cout<<"Total Maximo: "<<somaMaxEsquerdo<<endl;
       cout<<"Media Minimo: "<<mediaMinEsq<<endl;
       cout<<"Media Maximo: "<<mediaMaxEsq<<endl;
       cout<<endl;
       cout<<endl;
   
    cout << endl;
    printf("---- MERGE LADO DIREITO: ----");
    for (j = 0; j < num2; j++)
    {
        somaMinDireito = somaMinDireito + ladoDireito[0]; 
        somaMaxDireito = somaMaxDireito + ladoDireito[num2-1];
        cout << endl;
        cout<<"incremento minimo "<<ladoDireito[0]<<endl;
        cout<<"incremento maximo "<<ladoDireito[num2-1]<<endl;
    }
          float mediaMinDir, mediaMaxDir;
       mediaMinDir = somaMinDireito/2;
       mediaMaxDir = somaMaxDireito/2;
       cout<<"Total Minimo: "<<somaMinDireito<<endl;
       cout<<"Total Maximo: "<<somaMaxDireito<<endl;
       cout<<"Media Minimo: "<<mediaMinDir<<endl;
       cout<<"Media Maximo: "<<mediaMaxDir<<endl;
        cout<<"/////////////////"<<endl; 
    
    
    cout << endl;
    
    i = 0;
    j = 0;
  
    for (k = g; k <= r; k++) {
 
            numeroComp++;
        if (ladoEsquedo[i] <= ladoDireito[j]) {
            a[k] = ladoEsquedo[i];
            i++;
            numeroTroca++;
        } else {
            a[k] = ladoDireito[j];
            j++;
            numeroTroca++;
        }


    }
       cout<<"Quantidade de Comparacoes Merge: "<< numeroComp<<endl;
       cout<<"Quantidade do trocas Merge:  "<< numeroTroca<<endl;
}

 // função mergeSort
void mergeSort(int *a, int g, int r)
{

    int q;
  int numeroTroca2 =0;
  int numeroComp2 =0;
    numeroComp2++;
    if (g < r) {
        q = (g + r) / 2;
        mergeSort(a, g, q);
        mergeSort(a, q + 1, r);

        merge(a, g, q, r);
    }
  cout<<"Quantidade de Comparacoes  Merge Sort:  "<< numeroComp2<<endl;

}

