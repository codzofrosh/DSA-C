#include <stdio.h>

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
    
    return 0;
}