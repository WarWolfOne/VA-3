//Matheus do Nascimento Saito - 2020262
// Marco Antônio Martins - 1910497
// Pedro Wilson Rodrigues de Lima - 2020267
// Alexandre Silva Oliveira - 2111127
// Guilherme Gomes de Almeida - 2020890
// Marcos Vinicius Fernandes Alves - 2021030
#include <stdio.h>
#include <time.h>

#define SZ 10000000
#define MOD 10000007
#define i64 long long int

i64 nums[SZ];

i64 L[SZ], R[SZ];

i64 seed = 0xff;
i64 srand(){
    seed = (seed + 17 * seed) % MOD;
    return seed;
}

void make(){
    for (register int i = 0; i < SZ; i++)
        nums[i] = srand() % MOD;
}

void swap(i64 *a, i64 *b){
    i64 t = *a;
    *a = *b;
    *b = t;
}

int pivote(int s, int e){

    int p = s + (e - s) / 2;

    i64 v = nums[p];
    int c = s;
    swap(nums + p, nums + e);
    for (register int i = s; i < e; i++){
        if (nums[i] < v){
            swap(nums + i, nums + c);
            c++;
        }
    }
    swap(nums + c, nums + e);
    return c;
}

void merge(i64 arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
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

void mergeSort(i64 arr[], int l, int r){
    if (l < r){
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void testMsort(){
    double s, e;

    make();

    s = clock();
    mergeSort(nums, 0, SZ - 1);
    e = clock();
    printf("msort aleatório: %Lf ms\n", (e - s) / 1);

    s = clock();
    mergeSort(nums, 0, SZ - 1);
    e = clock();
    printf("msort classificado: %Lf ms\n", (e - s) / 1);
}

int main(){

    testMsort();

    return 0;
}
