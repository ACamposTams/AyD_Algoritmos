#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <chrono>
#include <vector>
#include "Nodo.h"
#include <fstream>

void bubbleSort( int v[], int N);
void cocktailSort(int v[], int N);
void insertionSort(int v[], int N);
void bucketSort(int v[], const int N);
void merge(int v[], int l, int m, int n, int N);
void mergeSort(int v[], int l, int n, int N);
int getMax(int v[], int N);
void countSort(int v[], int N, int exp);
void radixSort(int v[], int N);
void shellSort(int v[], int N);
void selectionSort(int v[], int N);
void quickSort(int v[], int primero, int ultimo);
void findMinMax(int v[], int N, int& mi, int& max);
void countingSort( int v[], int N);
void shift_down(int heap[],int i, int max);
void to_heap(int arr[], int N);
void heap_sort(int arr[], int N);
void insert(Nodo*& nodo, int valor);
void inOrder(Nodo* nodo, std::vector<int>& a);
void binarySort(int a[], int N);
void copiaNumeros(int a[],int N);


int main() 
{
    const unsigned long int N = 100;
    
    std::cout << N << std::endl;

    srand((int) time(NULL));
    
    int * a = new int[N];
    int * aux = new int[N];

    copiaNumeros(a,N);
    
    for (int i = 0; i < N; ++i) 
    {
        aux[i] = a[i];
    }

    auto begin = std::chrono::high_resolution_clock::now();
    bubbleSort(a, N);
    auto end = std::chrono::high_resolution_clock::now();
    auto tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Bubble: "<<tiempo.count()<<std::endl;
    
    for( int i = 0; i<N; i++)
    {
        a[i] = aux[i];
    }
    begin = std::chrono::high_resolution_clock::now();
    cocktailSort(a, N);
    end = std::chrono::high_resolution_clock::now();
    tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Cocktail: "<<tiempo.count()<<std::endl;
    
    for( int i = 0; i<N; i++)
    {
        a[i] = aux[i];
    }
    begin = std::chrono::high_resolution_clock::now();
    insertionSort(a, N);
    end = std::chrono::high_resolution_clock::now();
    tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Insertion: "<<tiempo.count()<<std::endl;
    
    for( int i = 0; i<N; i++)
    {
        a[i] = aux[i];
    }
    begin = std::chrono::high_resolution_clock::now();
    bucketSort(a, N);
    end = std::chrono::high_resolution_clock::now();
    tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Bucket: "<<tiempo.count()<<std::endl;
    
    for( int i = 0; i<N; i++)
    {
        a[i] = aux[i];
    }
    begin = std::chrono::high_resolution_clock::now();
    countingSort(a, N);
    end = std::chrono::high_resolution_clock::now();
    tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Counting: "<<tiempo.count()<<std::endl;

    for( int i = 0; i<N; i++)
    {
        a[i] = aux[i];
    }
    begin = std::chrono::high_resolution_clock::now();
    mergeSort(a, 0, N-1, N);
    end = std::chrono::high_resolution_clock::now();
    tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Merge: "<<tiempo.count()<<std::endl;
    
    for( int i = 0; i<N; i++)
    {
        a[i] = aux[i];
    }
    begin = std::chrono::high_resolution_clock::now();
    radixSort(a, N);
    end = std::chrono::high_resolution_clock::now();
    tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Radix: "<<tiempo.count()<<std::endl;
    
    for( int i = 0; i<N; i++)
    {
        a[i] = aux[i];
    }
    begin = std::chrono::high_resolution_clock::now();
    shellSort(a, N);
    end = std::chrono::high_resolution_clock::now();
    tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Shell: "<<tiempo.count()<<std::endl;
    
    for( int i = 0; i<N; i++)
    {
        a[i] = aux[i];
    }
    begin = std::chrono::high_resolution_clock::now();
    selectionSort(a, N);
    end = std::chrono::high_resolution_clock::now();
    tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Selection: "<<tiempo.count()<<std::endl;
    
    for( int i = 0; i<N; i++)
    {
        a[i] = aux[i];
    }
    begin = std::chrono::high_resolution_clock::now();
    quickSort(a, 0, N-1);
    end = std::chrono::high_resolution_clock::now();
    tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Quick: "<<tiempo.count()<<std::endl;
    
    for( int i = 0; i<N; i++)
    {
        a[i] = aux[i];
    }
    begin = std::chrono::high_resolution_clock::now();
    heap_sort(a, N);
    end = std::chrono::high_resolution_clock::now();
    tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Heap: "<<tiempo.count()<<std::endl;

    for( int i = 0; i<N; i++)
    {
        a[i] = aux[i];
    }
    begin = std::chrono::high_resolution_clock::now();
    binarySort(a, N);
    end = std::chrono::high_resolution_clock::now();
    tiempo = std::chrono::duration_cast<std::chrono::microseconds>(end-begin);
    std::cout<<"Binary: "<<tiempo.count()<<std::endl;

    delete a;
    delete aux;

    return 0;
}

void bubbleSort( int v[], int N)
{    
    int temp;
    for (int i = 0; i < N; i++)
    {
        for(int j= N-1; j>i; j--)
        {
            if (v[j-1] > v[j])
            {
                temp = v[j-1];
                v[j-1] = v[j];
                v[j] = temp;
            }
        }
    }
}

void cocktailSort(int v[], int N)
{
    int lo = 0, hi = (N-1), mov = lo, temp;
    while (lo<hi){
        for(int i=hi; i>lo; --i)
        {
            if(v[i-1]>v[i])
            {
                temp = v[i-1];
                v[i-1]=v[i];
                v[i]= temp;
                mov=i;
            }
        }
        
        lo = mov;
        
        for(int i=lo; i<hi; ++i)
        {
            if(v[i] > v[i+1])
            {
                temp = v[i];
                v[i] = v[i+1];
                v[i+1]= temp;
                mov = i;
            }
        }
        hi=mov;
    }
}

void insertionSort(int v[], int N)
{
    int index;
    for (int i=1; i < N; i++)
    {
        index = v[i];
        
        int j = i-1;
        
        while (j >= 0 && v[j] > index)
        {
            v[j + 1] = v[j];
            j--;
        }
        
        v[j+1] = index;
    }

}

void bucketSort(int v[], const int N)
{
    int m = 10001;
    int buckets[m];
    for(int i=0; i< m; ++i)
    {
        buckets[i]=0;
    }
    
    for (int i = 0; i < N; ++i)
    {
        ++buckets[v[i]];
    }
    
    for (int i =0, j = 0; j < m; ++j)
    {
        for (int k = buckets[j]; k > 0; --k)
        {
            v[i++] = j;
        }
    }  
}

void merge(int v[], int l, int m, int n, int N)
{
    int i, j, k;
    int aux[N];
    for(i=m+1;i>l;i--)
    {
        aux[i-1] = v[i-1];
    }
    
    for (j=m; j<n; j++)
    {
        aux[n+m-j] = v[j+1];
    }
    
    for(k=l;k<=n;k++)
    {
    	if (!(aux[i]> aux[j]))
    	{
            v[k] = aux[i++];
    	}
        else
        {
            v[k] = aux[j--];
        }
    }
}

void mergeSort(int v[], int l, int n, int N)
{
    int m = (n+l)/2;
    if (n > l)
    {
        mergeSort (v, l, m, N);
        mergeSort (v, m+1, n, N);
        merge (v, l, m, n, N);
    }
}

int getMax(int v[], int N)
{   
    int max = v[0];
    for(int i=1; i<N; i++)
    {
        if(v[i]>max)
        {
            max = v[i];
        }
    }

    return max;
}

void countSort(int v[], int N, int exp)
{
    int output[N];
    int count[10] = {0};
    
    for(int i=0; i<N; i++)
    {
        count[(v[i]/exp)%10]++;
    }
    
    for(int i=1; i<10;i++)
    {
        count[i]+=count[i-1];
    }
    
    for (int i = N-1; i>=0; i--)
    {
        
        output[count[( v[i]/exp ) %10 ] -1] = v[i];
        count[(v[i]/exp)%10]--;
    }
    
    for(int i=0;i<N; i++)
    {
        v[i]=output[i];
    }
}

void radixSort(int v[], int N)
{
    int m = getMax(v, N);
    
    for(int exp = 1; m/exp>0; exp*=10)
    {
        countSort(v, N, exp);
    }
}

void shellSort(int v[], int N)
{
    int temp;
    
    for(int gap= N/2; gap>0; gap/=2)
    {
        for(int i=gap; i<N; i++)
        {
            for(int j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap)
            {
                temp = v[j];
                v[j]= v[j+gap];
                v[j+gap] = temp;
            }
        }
    }
}

void selectionSort(int v[], int N)
{
    int minimo = 0;
    int temp;
    
    for(int i = 0; i < N-1; i++)
    {
        minimo = i;
        for(int j = i + 1; j < N; j++)
        {
            if (v[minimo] > v[j])
                minimo = j;
        }
        temp = v[minimo];
        v[minimo] = v[i];
        v[i] = temp;
    }
}

void quickSort(int v[], int primero, int ultimo)
{
    int izquierdo = primero;
    int derecho = ultimo;
    int temp;
    
    int pivote = v[primero];
    
    if ( primero < ultimo)
    {
        while ( izquierdo < derecho)
        {
            while ( (izquierdo < derecho) && !(v[izquierdo] > pivote)) izquierdo++;
            while (v[derecho]> pivote ) derecho--;
            
            if ( izquierdo < derecho)
            {
                temp = v[derecho];
                v[derecho] = v[izquierdo];
                v[izquierdo] = temp;
            }
        }
        
        temp = v[derecho];
        v[derecho] = v[primero];
        v[primero] = temp;
        
        quickSort ( v, primero, derecho-1);
        quickSort ( v, izquierdo, ultimo);
    }
}

void findMinMax(int v[], int N, int& mi, int& max)
{
    mi = 100;
    max = 0;
    
    for( int i = 0; i < N; i++ )
    {
        if( v[i] > max ) max = v[i];
        if( v[i] < mi ) mi = v[i];
    }
    
}


void countingSort( int v[], int N)
{
    int mi, max;
    int z=0;
    findMinMax(v, N, mi, max);
    int nlen = (max-mi)+1;
    int* temp = new int[nlen];
    memset(temp, 0, nlen * sizeof( int ));
    
    for( int i = 0; i < N; i++ )
    {
        temp[v[i] - mi]++;
    }
    
    for( int i = mi; i <= max; i++ )
    {
        while( temp[i - mi] )
        {
            v[z++] = i;
            temp[i - mi]--;
        }
    }
    
    
    delete [] temp;
}

void shift_down(int heap[],int i, int max) 
{
    int i_big, c1, c2;
    while(i < max) 
    {
        i_big = i;
        c1 = (2*i) + 1;
        c2 = c1 + 1;
        if( c1<max && heap[c1]>heap[i_big] )
            i_big = c1;
        if( c2<max && heap[c2]>heap[i_big] )
            i_big = c2;
        if(i_big == i) return;
        std::swap(heap[i],heap[i_big]);
        i = i_big;
    }
}

void to_heap(int arr[], int N) 
{
    int i = (N/2) - 1;
    while(i >= 0) 
    {
        shift_down(arr, i, N);
        --i;
    }
}

void heap_sort(int arr[], int N)
 {
    to_heap(arr, N);
    int end = N - 1;
    while (end > 0) 
    {
        std::swap(arr[0], arr[end]);
        shift_down(arr, 0, end);
        --end;
    }
}

void insert(Nodo*& nodo, int valor)
{
    if (!nodo)
    {
        nodo = new Nodo(valor);
    }
    else if (valor < nodo->valor)
    {
    	insert(nodo->left, valor);
    }
    else
    {
        insert(nodo->right, valor);
    }
}

void inOrder(Nodo* nodo, std::vector<int>& a)
{
    if (nodo) 
    {
        inOrder(nodo->left, a);
        a.push_back(nodo->valor);
        inOrder(nodo->right, a);
    }
}

void binarySort(int a[], int N)
{
    Nodo* root = nullptr;
    for (int i = 0; i < N; ++i)
    {
        insert(root, a[i]);
    }

    std::vector<int> aux;
    inOrder(root, aux);

    root->destroy();

    for (int i = 0; i < aux.size(); ++i)
    {
        a[i] = aux[i];
    }
}

void copiaNumeros(int enteros[],int n)
{
    std::ifstream file("./numeros.txt");
    if(file.is_open())
    {
        for(int i = 0; i < n; ++i)
        {
            file >> enteros[i];
        }
    }
}
