#include <iostream>
using namespace std;

#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;
/** Genera un array  con num de tamaño **/
void generateArray(int arr[], int arr2[], int num)
{
    srand(time(NULL));

    for(int a=0; a<num; a++)
    {
        arr[a] = 1 + rand() % (num);
        arr2[a]=arr[a];
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl;
}


void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l+(r-l)/2;

        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

void inter(int A[],int p,int q,int r)
{
    int B[r];
    for (int i=p;i<q;i++)
    {
        B[i]=A[i];
    }
    for (int j=q;j<r;j++)
    {
        B[r+q-j]=A[j];
    }
    int i=p;
    int j=r;
    for (int k=p;k<r;k++)
    {
        if(B[i]<=B[j])
        {
            A[k]=B[i];
            i++;
        }
        else{
            A[k]=B[j];
            j--;
        }
    }
}

int mergetime(int arr[],int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr,0,n-1);
    auto finish = std::chrono::high_resolution_clock::now();
    int tmpmerge=std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
    return tmpmerge;
}

int intertime(int arr[],int p, int q, int r)
{
    auto start=std::chrono::high_resolution_clock::now();
    inter(arr, p, q, r);
    auto finish=std::chrono::high_resolution_clock::now();
    int tmpinter=std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
    return tmpinter;
}

int main()
{
    int num;
    cout<<"Elementos del array: ";
    cin>>num;
    int A[num];
    int B[num];
    int mitad=num/2;
    int x=1;
    for (int i=0;i<num;i++)
    {
        if(i>=mitad)
        {
            A[i]=i-mitad;
            B[i]=i-mitad;
        }
        else
            A[i]=i+mitad;
            B[i]=i+mitad;
    }
    print(A,num);
    int Tmerge=mergetime(A,num);
    int Tinter=intertime(B,0,mitad,num);
    cout<<"TimeMerge ="<<Tmerge<<endl<<"TimeIntercalacion ="<<Tinter<<endl;
    if(Tinter<Tmerge)
        cout<<"Inter mejor";
    //print(A,num);
    return 0;
}
