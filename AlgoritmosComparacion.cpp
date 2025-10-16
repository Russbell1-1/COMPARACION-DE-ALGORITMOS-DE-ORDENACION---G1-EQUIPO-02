#include <bits/stdc++.h>
#include <chrono>
#include <fstream>
using namespace std;

void CountSort(int A[], int n);
void InterDirectoBi(int A[], int n, long long &comp, long long &intr);
void tipoPrueba(string &patron);

int main() 
{
    int n, mtd, prueba=1;
    long long intr=0, comp=0;
    string patron;
    
    cout<<"--------- Menu ---------\n";
    cout<<"1. Intercambio Directo Bidireccional\n";
    cout<<"2. Counting Sort\n";
    cout<<"Ingrese el metodo que desea usar: ";
    cin>>mtd;
    system("cls");
    
    cout<<"Ingrese cantidad de elementos del arreglo: ";
    cin>>n;
    system("cls");
    
    tipoPrueba(patron);
    
    int A[n];
    cout<<"Ingrese los elementos del arreglo:\n";
    for (int k=0; k<n; k++) cin>>A[k];
    
    ofstream archv("resultados.csv");
    if (!archv)
    {
        cerr<<"Error al crear el archivo CSV.\n";
        return 1;
    }
    
    archv<<"Prueba,Algoritmo,n,Patron,Tiempo_microsegundos,Comparaciones,Intercambios\n";
    
    if (mtd==1)
    {	
        comp=0;
        intr=0;
        auto start=chrono::steady_clock::now();
        InterDirectoBi(A, n, comp, intr);
        auto end=chrono::steady_clock::now();
        auto tiempo=chrono::duration_cast<chrono::microseconds>(end - start).count();
        
        archv<<prueba<<",Intercambio Directo Bidireccional,"<<n<<","<<patron<<","<<tiempo<<","<<comp<<","<<intr<<"\n";
       
    }
    else if (mtd==2)
    {
        auto start=chrono::steady_clock::now();
        CountSort(A, n);
        auto end=chrono::steady_clock::now();
        auto tiempo=chrono::duration_cast<chrono::microseconds>(end - start).count();
        
        archv<<prueba<<",Counting Sort,"<<n<<","<<patron<<","<<tiempo<<",0,0\n";
       
    }
    else
    {
        cout<<"Opción invalida.\n";
        archv.close();
        return 0;
    }
    
    archv.close();
    cout<<"\nDatos guardados en resultados.csv\n";
    return 0;
}

void CountSort(int A[], int n)
{
    int max=A[0];
    int min=A[0];
    for (int i=1; i<n; i++)
    {
        if (A[i]>max) max=A[i];
        if (A[i]<min) min=A[i];
    }

    if (min<0)
    {
        cout<<"Error: Counting Sort no funciona con números negativos.\n";
        exit(1);
    }

    int cont[max+1]={0};
    int ord[n];
    for (int i=0; i<n; i++) cont[A[i]]++;
    for (int i=1; i<=max; i++) cont[i]+=cont[i-1];
    for (int i=n-1; i>=0; i--)
    {
        ord[cont[A[i]]-1]=A[i];
        cont[A[i]]--;
    }
    for (int i=0; i<n; i++) A[i]=ord[i];
}

void InterDirectoBi(int A[], int n, long long &comp, long long &intr) 
{
    int izq=0, der=n-1, k=n-1;
    while (izq<der) 
    {
        for (int i=der; i>izq; i--) 
        {
            comp++;
            if (A[i-1]>A[i]) 
            {
                swap(A[i-1], A[i]);
                intr++;
                k=i;
            }
        }
        izq=k;
        for (int i=izq; i<der; i++) 
        {
            comp++;
            if (A[i]>A[i+1]) 
            {
                swap(A[i], A[i+1]);
                intr++;
                k=i;
            }
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
        case 1: patron="Aleatorio uniforme"; break;
        case 2: patron="Ordenado ascendente"; break;
        case 3: patron="Ordenado descendente"; break;
        case 4: patron="Casi ordenado"; break;
        case 5: patron="Con duplicado"; break;
        case 6: cout<<"Saliendo...\n"; exit(0);
        default: patron="Desconocido"; break;
    }
}