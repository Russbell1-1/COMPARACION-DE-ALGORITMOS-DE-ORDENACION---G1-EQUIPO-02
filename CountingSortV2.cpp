#include <iostream>
#include <chrono>
#include <fstream>  
#include <string>
using namespace std;

void CountSort(int A[], int n);
void random(int A[], int n);
int Menu();

int main() 
{
    int n, comp=0, intr=0, op;
    cout<<"Ingrese la cantidad de elementos\n";
	cin>>n;
    int A[n];
    string algoritmo, patron;
    op=Menu();
    switch (op)
    {
    	case 1:
    		patron="Aleatorio uniforme";
    		break;
    	case 2:
    		patron="Ordenado ascendente";
    		break;
    	case 3:
    		patron="Ordenado descendente";
    		break;
    	case 4:
    		patron="Casi ordenado";
    		break;
    	case 5:
    		patron="Con duplicado";
    		break;
    	default:
    		break;
	}
	cout<<"Ingrese elementos del arreglo\n";
	for (int i=0; i<n; i++)
    {
		cin>>A[i];
	}
    ofstream archv("resultados.csv");
    archv<<"prueba,CountSort,n,patron,repeticion,tiempo_microsegundos,comparaciones,intercambios\n";
        auto start=chrono::steady_clock::now();
        CountSort(A, n);
        auto end=chrono::steady_clock::now();
        auto tiempo=chrono::duration_cast<chrono::nanoseconds>(end - start).count();
        archv<<","<<"CountingSort"<<","<<n<<","<<patron<<","<<","<<tiempo<<","<<comp<<","<<intr<<","<<"\n";
    archv.close();
    cout << "\nDatos guardados en resultados.csv\n";
    return 0;
}

void CountSort(int A[], int n) 
{
    int max=A[0];
    for (int i=1; i<n; i++)
	{
        if (A[i]>max)
            max=A[i];
    }
    int cont[max+1]={0};
    int ord[n];
    for (int i=0; i<n; i++)
    {
    	cont[A[i]]++;
	}
    for (int i=1; i<=max; i++)
    {
    	cont[i]=cont[i]+cont[i-1];
	}
    for (int i =n-1; i>=0; i--) 
	{
        ord[cont[A[i]]-1]=A[i];
        cont[A[i]]--;
    }
    for (int i=0; i<n; i++)
    {
    	A[i]=ord[i];
	}
}

int Menu()
{
	int op;        
		cout<<"Seleccione tipo de prueba\n";
        cout<<"1. Aleatorio uniforme\n";
        cout<<"2. Ordenado ascendente\n";
        cout<<"3. Ordenado descendente\n";
        cout<<"4. Casi ordenado\n";
        cout<<"5. Con duplicado\n";
        cin>> op;
	return op;
}

