#include <iostream>
#include <chrono>
#include <vector>
using namespace std;

void CountSort(int A[], int n) 
{
    int max=A[0];
    for (int i=1;i<n;i++)
        if(A[i]>max) max=A[i];

    vector<int> cont(max+1,0); 
    vector<int> ord(n);

    for(int i=0;i<n;i++)
        cont[A[i]]++;

    for(int i=1;i<=max;i++)
        cont[i]+=cont[i-1];

    for(int i=n-1;i>=0;i--)
    {
        ord[cont[A[i]]-1]=A[i];
        cont[A[i]]--;
    }

    for(int i=0;i<n;i++)
        A[i]=ord[i];
}

int main() 
{
    int n;
    cout<<"Ingrese cantidad de elementos: ";
    cin>>n;
    int A[n];
    cout<<"Ingrese los elementos:\n";
    for(int i=0;i<n;i++)
        cin>>A[i];

    auto start=chrono::steady_clock::now();
    CountSort(A,n);
    auto end=chrono::steady_clock::now();

    cout<<"\nTiempo de ejecucion: "
        <<chrono::duration_cast<chrono::microseconds>(end - start).count()
        <<" microsegundos\n";

    cout<<"Arreglo ordenado:\n";
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
    cout<<"\n";
    return 0;
}