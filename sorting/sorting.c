#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void enter(int **arr, int *size); 
void display(int *arr, int size);
void select(int *arr, int size);
void bubble(int *arr, int size);
void insert(int *arr, int size);
void merge(int *arr, int size, int low, int high);
void msort(int *arr, int size, int low, int mid, int high);
void quick(int *arr, int l, int r);
void heap(int *arr, int size);
void count(int *arr, int size);
int main () {
    int ch = 0;
    int size = 0;
    int *arr = NULL;
    enter(&arr, &size);
    while (1) {
        printf("\n===============");
        printf("\nSORTING PROGRAM");
        printf("\n\n0 EXIT");
        printf("\n1 (RE)ENTER");
        printf("\n2 SELECTION");
        printf("\n3 BUBBLE");
        printf("\n4 INSERTION");
        printf("\n5 MERGE");
        printf("\n6 QUICK");
        printf("\n7 HEAP");
        printf("\n8 COUNT");
        printf("\nEnter your choice: ");
        do {
            scanf("%d", &ch);
        }while (ch == '\n');
        switch(ch) {
            case 0:
                exit(0);
            break;
            case 1:
                enter(&arr, &size);
            case 2:
                select(arr, size);
            break;
            case 3:
                bubble(arr, size);
            break;
            case 4:
                insert(arr, size);
            break;
            case 5:
                merge(arr, size, 0, size - 1);
                printf("\nAfter Merge Sort : \n");
                display(arr, size);
            break;
            case 6:
                quick(arr, 0, size - 1);
                printf("\nAfter Quick Sort : \n");
                display(arr, size);
            break;
            case 7:
                heap(arr, size);
                printf("\nAfter Heap Sort : \n");
                display(arr, size);
            break;
            case 8:
                count(arr, size);
            break;
            default:
            break;
        }
    }
    return 0;
}
/*
 * (Re)Enter elements of the array
 */
void enter(int **arr, int *size) 
{
    printf("\nEnter size of the array : ");
    scanf("%d", size);
    *arr = malloc(sizeof(int) * (*size));
    if (!arr) {
        printf("\nMem Allocation Failure!");
        exit(0);
    }
    printf("\nEnter Elements of the array : ");
    for(int i = 0;i < *size;i++) {
        scanf("%d", (*arr + i));
    }
}

/*
 * Display sorted array
 */
void display(int *arr, int size) 
{
    for(int i = 0; i < size; i++) {
        printf("%d\t", *(arr + i));
    }
}

/*
 * Selection Sort
 */
void select(int *arr, int size) 
{
    for (int i = 0; i < (size - 1);i++) {
        for (int j = i+1; j < size; j++) {
            if (arr[i] > arr[j]) {
                arr[i] = arr[i] ^ arr[j];
                arr[j] = arr[i] ^ arr[j];
                arr[i] = arr[i] ^ arr[j];
            }
        }
    }
    printf("\nAfter Selection Sort : \n");
    display(arr, size);
}

/*
 * Bubble Sort
 */
void bubble(int *arr, int size) 
{
    for (int i = 0; i < (size - 1);i++) {
        for (int j = i; j < (size - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                arr[j] = arr[j] ^ arr[j + 1];
                arr[j + 1] = arr[j] ^ arr[j + 1];
                arr[j] = arr[j] ^ arr[j + 1];
            }
        }
    }
    printf("\nAfter Bubble Sort : \n");
    display(arr, size);
}

/*
 * Insertion Sort
 */
void insert(int *arr, int size) 
{
    for (int i = 1; i < size; i++) {
        for (int j = i, k = i - 1; j > 0; j--, k--) {
            if (arr[j] < arr[k]) {
                arr[j] = arr[j] ^ arr[k];
                arr[k] = arr[j] ^ arr[k];
                arr[j] = arr[j] ^ arr[k];
            }
        }
    }
    printf("\nAfter Insert Sort : \n");
    display(arr, size);
}

/*
 * Merge Function
 */
void msort(int *arr, int size, int low, int mid, int high) 
{
    int *dup = NULL;
    int i = low, j = mid + 1, k = low;
    dup = malloc(sizeof(int) * size);
    if (!dup) {
        printf("\nMem Allocation Failure!");
        exit(0);
    }
    while((i <= mid) && (j <= high))  {
        if (arr[i] < arr[j]) {
            dup[k++] = arr[i++];
        } else {
            dup[k++] = arr[j++];
        }
    }
    while(i <= mid) {
        dup[k++] = arr[i++];
    }
    while(j <= high) {
        dup[k++] = arr[j++];
    }
    for (int i = low; i <= high;i++) {
        arr[i] = dup[i];
    }
}
/*
 * Merge Sort
 */
void merge(int *arr, int size, int low, int high)
{
    if(low < high) {
        int mid = (low + high)/2;
        merge(arr, size, low, mid);
        merge(arr, size, mid + 1, high);
        msort(arr, size, low, mid, high);
    }
}


int partition(int a[], int l, int r) {
    int pivot, i, j, t;
    pivot = a[l];
    i = l; j = r + 1;
             
    while (1) {
        do ++i; while ( a[i] <= pivot && i <= r );
        do --j; while ( a[j] > pivot );
        if ( i >= j ) break;
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[l]; a[l] = a[j]; a[j] = t;
    return j;
}

/*
 * Quick Sort
 */
void quick(int *arr, int l, int r) 
{
    int j;

    if ( l < r ) 
    {
        // divide and conquer
        j = partition( arr, l, r);
        quick( arr, l, j - 1);
        quick( arr, j + 1, r);
    }
}

/*
 * Finding Left Child index
 */
int left(int i) {
    return (i * 2 + 1);
}

/*
 * Finding Right Child index
 */
int right(int i) {
    return (i * 2 + 2);
}

/*
 *  Maintain the heap
 */
void heapify(int *arr, int i, int heap_size) 
{
    int l = left(i);
    int r = right(i);
    int l_index = i;

    if ((l < heap_size) && (arr[l] > arr[l_index])) {
        l_index = l;
    }  else if((r < heap_size) && (arr[r] > arr[l_index])) {
        l_index = r;
    }

   if (l_index != i) {
       arr[i] = arr[i] ^ arr[l_index];
       arr[l_index] = arr[i] ^ arr[l_index];
       arr[i] = arr[i] ^ arr[l_index];
       heapify(arr, l_index, heap_size);
   }
}

/*
 * Build the heap
 */
void build_heap(int *arr, int heap_size) 
{
    for (int i = heap_size/2; i >= 0; i--) {
        heapify(arr, i, heap_size);    
    }
}

/*
 * Heap Sort
 */
void heap(int *arr, int size) 
{
    int heap_size = size;
        
    build_heap(arr, heap_size);
    for (int i = size - 1; i >= 1; i--) {
        arr[i] = arr[i] ^ arr[0];
        arr[0] = arr[i] ^ arr[0];
        arr[i] = arr[i] ^ arr[0];

        --heap_size;
        heapify(arr, 0, heap_size);
    }
}

/*
 * Count Sort
 */
void count(int *arr, int size) 
{
    int range = 0;
    int *count = NULL;
    int *out = NULL;

    for(int i = 0; i < size; i++) {
        if (arr[i] > range) {
            range = arr[i];
        }
    }
    range++;

    count = malloc(sizeof(int) * range);
    if (!count) {
        printf("\nMem Allocation Failure!");
        exit(0);
    }
    memset(count, 0, sizeof(int) * range);
    for (int i = 0; i < size; i++) {
        ++count[arr[i]];
    }

    /*
     * Fix for cumulative count
     */
    for (int i = 1; i < range; i++) {
        count[i] += count[i - 1];
    }

    // Initialize output array
    out = malloc(sizeof(int) * size);
    if (!out) {
        printf("\nMem Allocation Failure!");
        exit(0);
    }

    // Fill output array in sorted fashion
    for(int i = 0; i < size; i++) {
        out[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }
    display(out, size);
}
