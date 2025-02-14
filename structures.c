#include <stdio.h>
#include <string.h>

typedef struct{
    int age;
    char name[10];
    float mark;
}data;
typedef struct {
    int a;
    char b;
    char c;
}optimized;
typedef struct {
    char a;
    int b;
    char c;
}unoptimized;
typedef struct {
    char a;
    int b;
    char c;
}__attribute__((packed)) unoptimizedPacked;
void modify(data *data2){
    data2->age++;
    data2->mark--;
    strcpy(data2->name,"rock");
}
int main()
{
    printf("Hello World\nStructures in C\n");
    //Way to initialize Structure
    data data1;
    data1.age = 15;
    strcpy(data1.name ,"rick");
    data1.mark = 16.25;
    printf("Age %d\nName %s\nMark %.1f\n",data1.age,data1.name,data1.mark);
    //Copy a Structure
    //This type of copy allows shallow copy.
    data data2;
    data2 = data1;
    printf("Data from Data 2 struct\nAge %d\nName %s\nMark %.1f\n",data2.age,data2.name,data2.mark);
    //Structure Pointer
    data *ptr;
    ptr = &data2;
    //modify(&data2);
    modify(ptr);
    printf("Data after modification Data 2 struct\nAge %d\nName %s\nMark %.1f\n",data2.age,data2.name,data2.mark);
    printf("Size of Struct unoptimized %d\n",sizeof(unoptimized));
    printf("Size of structure optimized %d\n",sizeof(optimized));
    /*
    Difference in structure size occours due to padding.
    Structure padding is a concept where the compiler adds extra bytes between the 
    members of a structure to align the data in memory according to the architecture's alignment requirements. 
    This alignment can improve the performance of the system by ensuring 
    that data is accessed in the most efficient way possible.
    For unoptimized structure size would be 12 bytes because of
    | a (1 byte) | padding (3 bytes) | b (4 bytes) | c (1 byte) | padding (3 bytes) |
    3 bytes of padding to align the structure size to a multiple of the largest alignment requirement (4 bytes in this case).
    For optimized structure size would be 8 because of
    | a (4 bytes) | b (1 byte) | c (1 byte) | padding (2 bytes) |
    */
    printf("Size of Struct unoptimizedPacked %d\n",sizeof(unoptimizedPacked));
    /*
    Now the Difference occours because of keyword "__attribute__((packed))" which leads to Structure Packing.
    Structure packing is a technique used to reduce the memory footprint of structures by eliminating 
    or minimizing the padding bytes that are automatically added by the compiler for alignment purposes. 
    */
    //Array of structures
    data data3[2];
    data3[0].age = 16;
    strcpy(data3[0].name ,"rack");
    data3[0].mark = 17.25;
    data3[1].age = 17;
    strcpy(data3[1].name ,"reck");
    data3[1].mark = 18.25;
    for(int i=0;i<2;i++){
        printf("Age %d\nName %s\nMark %f\n",data3[i].age,data3[i].name,data3[i].mark);
    }
    return 0;
}