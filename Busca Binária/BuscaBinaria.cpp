#include <iostream> 
using namespace std;

main(){
	setlocale(LC_ALL, "portuguese");
	int n;
	int *vet,i,posi,numero,inicio,fim,achou,elementosexcluidos,qtdeTeste;
   
    cout<<"Informe a quantidade de elementos de forma ordenada para procurar"<<endl;
    cin>>n;
     vet = new int[n];
	for(i=0;i<=n;i++){
		cout<<"Informe os elementos"<<endl;
		cin>>vet[i];
	}

	cout<<"Informe o n�mero para a busca: "<<endl;
	cin>>numero;
	
	achou=0;
	inicio=0;
	fim=n;
	posi=(inicio+fim)/2;
	qtdeTeste=0;
	
	while((inicio<fim)&&(achou==0)){
	qtdeTeste++;
		if(vet[posi]==numero){
			achou=1;
			
		}
		else if(vet[posi]<numero){
				elementosexcluidos = (posi+1) - inicio;
				inicio=posi+1;
				posi=(inicio+fim)/2;
				cout<<"Exclu�dos: "<<elementosexcluidos<<endl;
				
			}
			else{
				elementosexcluidos =fim - (posi-1);
				fim=posi-1;
				posi=(inicio+fim)/2;
				cout<<"Exclu�dos: "<<elementosexcluidos<<endl;
			}
			
		}
	if(achou==0){
		cout<<"N�mero "<<numero<<" n�o encontrado"<<endl;
		cout<<"-1"<<endl;
		cout<<"Quantidade de testes realizados: "<<qtdeTeste;
	}	
	else{
		cout<<"N�mero "<<numero<<" encontrado com sucesso, na posi��o: "<<posi<<endl;
		cout<<"Quantidade de testes realizados: "<<qtdeTeste;
	}
	
}


