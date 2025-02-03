#include <stdio.h>
#include <math.h>
void findNoSetBits(int data){
    int count = 0;
    while(data){
        //Brian Kernighan’s Algorithm
        // data&=(data-1);
        // count++;
        //Usual Approach
        if(data%2)
            count++;
        data/=2;
    }
    printf("Number of Set Bits %d\n",count);
}
void swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
    /*Arithmetic Method
    *a = *a + *b;
    *a = *a - *b;
    *b = *a - *b;
    */
}
void reverseBits(int data){
    int rev = 0;
    while(data){
        rev = (rev<<1) | (data&1);
        data>>=1;
    }
    printf("reversed number %d\n",rev);
}
int main()
{
    int data,finalData,position;
    printf("Bitwise Operations\n");
    printf("Enter Integer\n");
    scanf("%d",&data);
    printf("Enter the position u want to set\n");
    scanf("%d",&position);
    finalData = data | (1<<position);
    printf("Original data : %d Final Data : %d\n",data,finalData);
    printf("Enter the position u want to clear\n");
    scanf("%d",&position);
    finalData = data & ~(1<<position);
    printf("Original data : %d Final Data : %d\n",data,finalData);
    printf("Enter the position u want to toggle\n");
    scanf("%d",&position);
    finalData = data ^ (1<<position);
    printf("Original data : %d Final Data : %d\n",data,finalData);
    printf("Enter the position u want to check it is set\n");
    scanf("%d",&position);
    data & (1<<position)?printf("Bit in %d postion is set\n",position):printf("Bit in %d position is not set\n",position);
    data & 1?printf("number is odd\n"):printf("number is even\n");
    printf("Last right set bit cleared number %d\n",(data&(data-1)));
    (data&(data-1))?printf("Number is not a power of 2\n"):printf("Number is power of 2\n");
    findNoSetBits(data);
    int a = 10,b=15;
    printf("Numbers before swap a = %d b = %d\n",a,b);
    swap(&a,&b);
    printf("Numbers after swap a = %d b = %d\n",a,b);
    /*
    Algorithm for extracing right most set bit
    Take two's complement and AND it.
    5 -> 00000101
    2's complement ->   11111011 (Considering MSB as Signbit -5)
    Taking AND of these two will retrive answer.
    */
    printf("Righmost set bit %d\n",data&(-data));
    reverseBits(data);
    printf("Position of First set bit %d\n",(int)(log2(data & -data))+1);
    return 0;
}