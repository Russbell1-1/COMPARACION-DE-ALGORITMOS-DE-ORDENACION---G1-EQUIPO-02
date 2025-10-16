#include <fstream>
#include <iostream>
#include <chrono>
using namespace std;

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

int main() 
{
	srand(time(nullptr));
    int n;
    cin>>n;
    int A[n];
    for (int i=0; i<n; i++)
    {
    	cin>>A[i];
	}
	
	ofstream archv("resultados.csv");
    archv<<"algoritmo,n,patron,repeticion,prueba,tiempo_microsegundos,comparaciones,intercambios,profundidad_recursion,semilla,commit_hash\n";
	
	auto start=chrono::steady_clock::now();
    CountSort(A, n); 
    auto end=chrono::steady_clock::now();
    cout <<"\nTiempo de ejecucion: "<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<" microseconds\n";
    archv<<"CountingSort"<<","<<n<<","<<patron<<","<<prueba<<","<<tiempo<<","<<comp<<","<<intr<<","<<","<<"\n";
    for (int i=0; i<n; i++)
    {
    	cout<<A[i]<<" ";
	}
	
	archv.close();
    cout<<"\nDatos guardados en resultados.csv\n";
	
    return 0;
}

