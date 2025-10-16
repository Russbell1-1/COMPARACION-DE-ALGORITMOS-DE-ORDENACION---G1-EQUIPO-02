#include <iostream>
#include <chrono>
using namespace std;

void InterDirectoBi(int A[], int n) 
{
    int izq=0, der=n-1, k=n-1;

    while (izq<der) 
	{
        for (int i=der; i> izq; i--) 
		{
            if (A[i-1]>A[i]) 
			{
                int aux=A[i-1];
                A[i-1]=A[i];
                A[i]=aux;
                k=i;
            }
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
            }
        }
        der=k;
    }
}

int main() 
{
    int n;
    cin>>n;
    int A[n];
    for (int i=0; i<n; i++) 
	{
        cin>>A[i];
    }
    auto start=chrono::steady_clock::now();
    InterDirectoBi(A, n);
    auto end=chrono::steady_clock::now();
    cout <<"\nTiempo de ejecucion: "<<chrono::duration_cast<chrono::microseconds>(end - start).count()<<" microsegundos\n";
	for (int i=0; i<n; i++)
    {
		cout<<A[i]<<" ";
	}
    return 0;
}
