#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 2000000

void swap(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}

void addElement(int a[], int * n, int x) {//добавление элемента в кучу
    a[*n] = x;
    int p = *n;
    *n = *n + 1;
    while (a[p] < a[p / 2] && p > 0) {
        swap(&a[p], &a[p / 2]);
        p /= 2;
    }
}

int RM(int a[], int * n) {//удаление элемента из кучи
    int m = a[0];
    a[0] = a[*n - 1];
    *n = *n - 1;
    int p = 0;
    int flag = 1;
    while (2 * p <= *n && flag) {
        flag = 0;
        int min = p * 2;
        if (min + 1 <= *n && a[min] > a[min+1])
            min++;
        if (a[p] > a[min]) {
            flag = 1;
            swap(&a[p], &a[min]);
            p = min;
        }
    }
    return m;
}

void heapSort(int *a, int * heap_size, int n) {
    for (int i  = 0; i < n; i++){
        addElement(a, heap_size, a[i]);
    }
    for (int i = 0; i < n; i++){
        int el = RM(a, heap_size);
        printf("%d ", el);
    }
    //for (int i = n / 2 - 1; i >= 1; i--) {
        //swap(a, a + i);
        //addElement(a, 0, i);
        //RM(a, &n);
    //}
    //if (*a > a[1])
        //swap(a, a + 1);
}

int main() {
    int i = 0;
    int n = 0;
    int heap_size = 0;
    scanf("%d", &n);
    int * a = (int *) malloc(sizeof(int) * n);
    if (a == NULL)
        return 1;
    for (i; i < n; ++i)
        scanf("%d", &a[i]);

    heapSort(a, &heap_size, n);

    return 0;
}