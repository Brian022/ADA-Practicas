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

void print(int arr[],int arr2[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
        cout << arr2[i] << " ";
    }

    cout << endl;
}

void insertSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
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

int mergetime(int arr[],int n)
{
    auto start = std::chrono::high_resolution_clock::now();
    mergeSort(arr,0,n-1);
    auto finish = std::chrono::high_resolution_clock::now();
    int tmpmerge=std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
    return tmpmerge;
}

int inserttime(int arr[],int n)
{
    auto start=std::chrono::high_resolution_clock::now();
    insertSort(arr,n);
    auto finish=std::chrono::high_resolution_clock::now();
    int tmpinsert=std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count();
    return tmpinsert;
}

int main()
{
    int num;
    cout<<"Elementos del array: ";
    cin>>num;
    int arr[num];
    int arr2[num];
    generateArray(arr,arr2,num);
    //print(arr,num);

    int Tinsert=inserttime(arr,num);
    int Tmerge=mergetime(arr2,num);
    cout<<"Timeinsert ="<<Tinsert<<endl<<"Timemerge ="<<Tmerge<<endl;
    if(Tinsert<Tmerge)
        cout<<"Insert mejor";

    //print(arr, arr2, num);

}
