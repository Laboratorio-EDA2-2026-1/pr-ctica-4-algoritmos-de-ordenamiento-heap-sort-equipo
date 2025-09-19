/*
 * Objetivo: Completar las funciones Max-Heapify, Build-Max-Heap y Heap-Sort.
 * Entradas (stdin):
 *   n

 *   a1 a2 ... an

 * Salida (stdout):
 *   a1 a2 ... an  // en orden ascendente
 */

#include <stdio.h>
#include <stdlib.h>

/* PROTOTIPOS: NO CAMBIAR LAS FIRMAS */
void max_heapify(int a[], int n, int i);
void build_max_heap(int a[], int n);
void heap_sort(int a[], int n);

/* MAIN de prueba mínima */
int main(void) {
    int n; if (scanf("%d", &n) != 1 || n <= 0) return 0;
    int *a = (int*)malloc(sizeof(int) * n);
    if (!a) return 0;
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);

    heap_sort(a, n);

    for (int i = 0; i < n; ++i) {
        if (i) putchar(' ');
        printf("%d", a[i]);
    }
    putchar(' ');

    free(a);
    return 0;
}

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*(i+1);
}

void Exchange(int *x, int *y){
    int key = *x;
    *x = *y;
    *y = key;
}

/* IMPLEMENTAR AQUÍ */
void max_heapify(int a[], int n, int i) {
    int l = left(i);
    int r = right(i);
    int largest;
    if (l < n && a[l] > a[i])
        largest = l;
    else
        largest = i;

    if (r < n && a[r] > a[largest])
        largest = r;

    if (largest != i)
    {
        Exchange (&a[i], &a[largest]);
        max_heapify(a, n, l);
        max_heapify(a, n, r);
    }
    
 
}

void build_max_heap(int a[], int n) {
    
    for (int i = n/2 - 1; i >=0; i--)
    {
        max_heapify(a, n , i);
    }
    
}

void heap_sort(int a[], int n) {
    build_max_heap(a, n);
    
    for (int i =n-1; i >= 1; i--){
        Exchange(&a[0], &a[i]);
        n--;
        max_heapify(a, i, 0);
    }
}
