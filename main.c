#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 2000000

void swap(int *a, int *b) {
    int x = *a;
    *a = *b;
    *b = x;
}

void addElement(int a[], int * heapSize, int x) { //добавление элемента в кучу
    a[*heapSize] = x;
    int p = *heapSize;
    *heapSize = *heapSize + 1;
    while (a[p] < a[p / 2] && p > 0) {
        swap(&a[p], &a[p / 2]);
        p /= 2;
    }
}

int removeElement(int a[], int * heapSize) { //удаление элемента из кучи
    int m = a[0];
    a[0] = a[*heapSize - 1];
    *heapSize = *heapSize - 1;
    int p = 0;
    int flag = 1;
    while (2 * p <= *heapSize && flag) {
        flag = 0;
        int min = p * 2;
        if (min + 1 <= *heapSize && a[min] > a[min+1])
            min++;
        if (a[p] > a[min]) {
            flag = 1;
            swap(&a[p], &a[min]);
            p = min;
        }
    }
    return m;
}

void heapSort(int *a, int * heapSize, int n) {
    for (int i  = 0; i < n; i++){
        addElement(a, heapSize, a[i]);
    }
    for (int i = 0; i < n; i++){
        int el = removeElement(a, heapSize);
        printf("%d ", el);
    }
}

int main() {
    int n = 0;
    int heapSize = 0;
    scanf("%d", &n);
    int *a = (int *) malloc(sizeof(int) * n);
    if (a == NULL)
        return 1;
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    heapSort(a, &heapSize, n);
    free(a);
    return EXIT_SUCCESS;
}