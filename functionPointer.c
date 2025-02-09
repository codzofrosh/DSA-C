#include <stdio.h>
int add(int a, int b){
    return a + b;
}
int sub (int a, int b){
    return a - b;
}
int mul (int a, int b){
    return a * b;
}
int divid (int a, int b){
    return a/b;
}
void cal(int a,int b, int (*ops)(int,int)){
    printf("%d\n",ops(a,b));
}
int main()
{
    int a,b;
    printf("Enter numbers a and b\n");
    scanf("%d",&a);
    scanf("%d",&b);
    cal(a,b,add);
    cal(a,b,sub);
    printf("Hello World\n");
    int (*fp_array[])(int,int) = {add,sub,mul,divid};
    printf("%d\n",fp_array[0](a,b));
    printf("%d\n",fp_array[1](a,b));
    printf("%d\n",fp_array[2](a,b));
    printf("%d\n",fp_array[3](a,b));
    int *ptr();
    ptr = &main;
    printf(ptr());
    return 0;
}
