#include <iostream>
#include <chrono>
#include <fstream>  
#include <string>
#include <bits/stdc++.h>
using namespace std;

void CountSort(int A[], int n);
void InterDirectoBi(int A[], int n, int &comp, int &intr);
void tipoPrueba(string &patron);

int main() 
{
	int mtd, prueba=1, n, intr=0, comp=0, ord=0;
	string patron;
	
	cout<<"--------- Menu ---------\n";
    cout<<"1. Intercambio Directo Bidireccional\n";
    cout<<"2. Counting Sort\n";
    cout<<"Ingrese el metodo que desea usar: \n";
    cin>>mtd;
    system("cls");
    cout<<"Ingrese cantidad de elementos del arreglo: ";
    cin>>n;
	system("cls");
    ofstream archv("resultados.csv");
    archv<<"Prueba,Algoritmo,n,Patron,Tiempo_microsegundos,Comparaciones,Intercambios\n";
	
	tipoPrueba(patron);

	int A[n];    
		if (mtd==1)
		{	
			for (int i=0; i<30; i++)
			{
				A[n]={};
				for (int k=0;k<n;k++) 
				{
					cin>>A[k];
			    }
				comp=0;
				intr=0;
				auto start=chrono::steady_clock::now();
		    	InterDirectoBi(A, n, comp, intr);
		        auto end=chrono::steady_clock::now();
		        auto tiempo=chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		        archv<<prueba<<",Intercambio Directo Bidireccional,"<<n<<","<<patron<<","<<tiempo<<","<<comp<<","<<intr<<","<<","<<"\n";
		        prueba++;
			}
			
		}
		else
		{
			for (int i=0; i<30; i=i+n)
			{
				A[n]={};
				for (int k= 0; k<n; k++) 
				{
					cin>>A[k];
			    }
				auto start=chrono::steady_clock::now();
		        CountSort(A, n);
		        auto end=chrono::steady_clock::now();
		        auto tiempo=chrono::duration_cast<chrono::nanoseconds>(end - start).count();
		        archv<<prueba<<",Counting Sort,"<<n<<","<<patron<<","<<tiempo<<","<<comp<<","<<intr<<","<<","<<"\n";
		        prueba++;
			}
		}
    
    archv.close();
    cout<<"\nDatos guardados en resultados.csv\n";
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

void InterDirectoBi(int A[], int n, int &comp, int &intr) 
{
    int izq=0, der=n-1, k=n-1;
    while (izq<der) 
	{
        for (int i=der; i>izq; i--) 
		{
            if (A[i-1]>A[i]) 
			{
                int aux=A[i-1];
                A[i-1]=A[i];
                A[i]=aux;
                k=i;
                intr++;
                
            }
            comp++;
        }
        izq=k;
        for (int i=izq; i<der; i++) 
		{
            if (A[i]>A[i+1]) 
			{
                int aux=A[i];
                A[i]=A[i+1];
                A[i+1]=aux;
                k=i;
                intr++;
            }
            comp++;
        }
        der=k;
    }
}

void tipoPrueba(string &patron)
{
	int op;
	cout<<"Tipos de datos de entrada\n";
    cout<<"1. Aleatorio uniforme\n";
    cout<<"2. Ordenado ascendente\n";
    cout<<"3. Ordenado descendente\n";
    cout<<"4. Casi ordenado\n";
    cout<<"5. Con duplicado\n";
    cout<<"6. Salir\n";
    cout<<"Seleccione el tipo de prueba: ";
    cin>>op;
    system("cls");
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
            case 6:
                cout << "Saliendo del programa...\n";
                exit(0);
            default:
                cout<<"Intente de nuevo.\n";
                break;
	}
}