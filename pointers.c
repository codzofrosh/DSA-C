#include <stdio.h>
#include <stdlib.h>

int value = 10;

void allocateElementsfor2dArray(int **ptr, int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            *(*(ptr + i) + j) = value * i + j;
        }
    }
}

void print2dArray(int **ptr, int rows, int columns) {
    printf("\nElements in 2D Array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%d\t", *(*(ptr + i) + j));
        }
        printf("\n");
    }
}

int main() {
    int a = 10, b = 20;
    int *ptr = &a;
    printf("Value of a: %d\nAddress of a: %p\nValue of Ptr: %p\n", a, &a, ptr);

    printf("Dynamic Memory Allocation for 1D Array\n");
    int size;
    printf("Enter initial size for array: ");
    scanf("%d", &size);

    int *array = malloc(size * sizeof(int));
    int *array1 = calloc(size, sizeof(int));

    printf("Initial value of array using malloc: %d\n", *array);
    printf("Initial value of array using calloc: %d\n", *array1);

    for (int i = 0; i < size; i++) {
        *(array + i) = i;
    }

    printf("Initial array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");
    printf("Dynamic Memory Allocation for 2D Array\n");
    int rows, columns;
    printf("\nEnter number of rows and columns: ");
    scanf("%d %d", &rows, &columns);
    int **arr2d = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        arr2d[i] = (int *)malloc(columns * sizeof(int));
    }

    allocateElementsfor2dArray(arr2d, rows, columns);
    print2dArray(arr2d, rows, columns);

    printf("Enter newly needed size for 1D array: ");
    scanf("%d", &size);
    array = realloc(array, size * sizeof(int));
    
    for (int i = 0; i < size; i++) {
        *(array + i) = i;
    }

    printf("New array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", *(array + i));
    }
    printf("\n");

    int newRows;
    printf("\nEnter new row size: ");
    scanf("%d", &newRows);

    if (newRows > rows) {
        arr2d = (int **)realloc(arr2d, newRows * sizeof(int *));
        for (int i = rows; i < newRows; i++) {
            arr2d[i] = (int *)malloc(columns * sizeof(int));
            for (int j = 0; j < columns; j++) {
                arr2d[i][j] = value * i + j;
            }
        }
    }

    printf("2D Array after resizing rows:\n");
    print2dArray(arr2d, newRows, columns);

    int newColumns;
    printf("\nEnter new column size: ");
    scanf("%d", &newColumns);

    if (newColumns > columns) {
        for (int i = 0; i < newRows; i++) {
            arr2d[i] = (int *)realloc(arr2d[i], newColumns * sizeof(int));
            for (int j = columns; j < newColumns; j++) {
                arr2d[i][j] = value * i + j;
            }
        }
    }

    printf("2D Array after resizing columns:\n");
    print2dArray(arr2d, newRows, newColumns);

    printf("Dangling Pointers\n");
    free(array1);
    printf("\nArray1 before NULL assignment: %p\n", array1);
    array1 = NULL;
    printf("Array1 after NULL assignment: %p\n", array1);
    
    int *const ptra = &a;   // Constant Pointer (address cannot change)
    const int *ptr1 = &b;   // Pointer to Constant (value cannot change)
    const int *const ptr2 = &a; // Constant Pointer to Constant (both fixed)

    printf("\nPointer Types:\n");
    printf("Constant Pointer (ptr to a): %p\n", ptra);
    printf("Pointer to Constant (ptr1 to b): %p\n", ptr1);
    printf("Constant Pointer to Constant (ptr2): %p\n", ptr2);

    free(array);
    for (int i = 0; i < newRows; i++) {
        free(arr2d[i]);
    }
    free(arr2d);

    return 0;
}
