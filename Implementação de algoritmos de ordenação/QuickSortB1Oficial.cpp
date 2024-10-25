#include <cstdio>
#include <cstdlib>
#include <climits>
#include <iostream>

using namespace std;

int nTroca = 0;
int nCompararativo = 0;
float mediaMin =0, mediaMax=0;
int somaMinEsquerdo = 0;
int somaMaxEsquerdo =0;



//Realiza troca de valores baseado na comparacao dos valores com o pivo.
void troca(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
    nTroca++;
}

//Realiza a particao do vetor
int particao(int vetor[], int Nmenor, int Nmaior)
{
    int pivo = vetor[Nmaior];
    int i = (Nmenor - 1);
    for (int j = Nmenor; j < Nmaior; j++)
    {
        if (vetor[j] <= pivo)
        {
            i++;
            troca(&vetor[i], &vetor[j]);
        }
    }
    troca(&vetor[i + 1], &vetor[Nmaior]);
    return (i + 1);
}

//Inicia o QuickSort e ordena o vetor
void quickSort(int vetor[], int Nmenor, int Nmaior)
{
    if (Nmenor < Nmaior)
    {
        int pi = particao(vetor, Nmenor, Nmaior);
        quickSort(vetor, Nmenor, pi - 1);
        quickSort(vetor, pi + 1, Nmaior);
        nCompararativo++;

    
    }
}


void printvetor(int vetor[], int tam)
{
    int i;
    cout << "[";
    for (i = 0; i < tam; i++)
    {
        cout << vetor[i] << " ";
         somaMinEsquerdo = somaMinEsquerdo + vetor[0];
         somaMaxEsquerdo = somaMinEsquerdo + vetor[tam-1];

    }
    cout << "]" << endl;
}



//Informa o vetor que serao usado
int main()
{
    int vetor[] = {8, 7, 6, 9, 5, 10, 11};
    int n = sizeof(vetor) / sizeof(vetor[0]);  
    cout << "----------------------------------------------------------------------" << endl;
    cout << "RESULTADO:\n";
    cout << "Vetor sem ordenar:" << endl;
    printvetor(vetor, n);
    quickSort(vetor, 0, n - 1);
    cout << "Vetor ordenado em ordem crescente:" << endl;
    printvetor(vetor, n);
    cout << "Comparacoes: " << nCompararativo << endl;
    cout << "Total trocas -> " << nTroca << endl;
    cout << "Total minimo -> " << somaMinEsquerdo<<endl;
    cout << "Total maximo -> " << somaMaxEsquerdo<<endl;
    mediaMin = somaMinEsquerdo/2;
    mediaMax = somaMaxEsquerdo/2;
    cout << "Media minimo -> " << mediaMin<<endl;
    cout << "Media maximo -> " << mediaMax<<endl;



    cout << "-------------------------------------------------------------------------" << endl;
}
