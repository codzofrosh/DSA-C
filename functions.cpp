#include<iostream>
#include<cmath>
#include<utility> //For returning in pairs 
#include<tuple> //For returning in tuples
/*
This file is about functions.
1. C++ has the feature of having default paramaters for functions.
    Say if a particular parameter is not passed, it takes the default value assigned to it. 
2. Function overloading allows multiple functions with the same name but different parameter lists.
    C++ determines which function to call based on arguments.
    The return type does NOT differentiate overloaded functions.
    int func(int x) { return x; } double func(int x) { return x; } -> this is ambigious.
    int func(int x) { return x; } double func(double x) { return x; } -> this is fine.
    What If we Need Different Return Types?
    Use extra parameters to differentiate return types:
        int func(int x, bool) { return x; } double func(int x, double) { return x; } -> second parameter will decide which function to be called.
    Use Function Template
        template <typename T>
        T func(T x) { return x; }  // Single function for int, double, etc.
    This will decide the return type.
*/
void print(int a = 20){
    std::cout<<"Value "<<a<<std::endl;
}
void area(int r){
    std::cout<<"Area of Square is "<<r*r<<std::endl;
}
void area(int l,int b){
    std::cout<<"Area of Rectangle is "<<l*b;
}
void area(double r){
    std::cout<<"Area of circle is "<<3.14*r*r;
}
inline int square(int num){
    return num*num;
    /*
    This line gave output as 24 when num = 5
    Reason pow() returns a double, but function returns an int.
    Solution : static_cast<int>(pow(num, 2)) to explicitly convert the result to an integer else use normal multiplication.
    */
    //return pow(num,2);

}
template <typename T>
int fibo(T num){
    /*This type is not a recomended one -> O(2^n)
    Recomended is straight forward approach 
    We can try it with vectors later.
    */
    if(num == 0 || num == 1)
        return num;
    else
        return fibo(num - 1) + fibo(num - 2);
}
template <typename T>
void swapValues(T *a,T *b){
    std::cout<<"Function using pointers"<<std::endl;
    //Using Arithmetic operator
    * a = * a + * b;
    * b = * a - * b;
    * a = * a - * b;
    //Using bitwise
    * a = * a ^ * b;
    * b = * a ^ * b;
    * a = * a ^ * b;
}
template <typename T>
void swapValues(T &a,T &b){
    std::cout<<"Function using address"<<std::endl;
    //Using Arithmetic operator
     a =  a +  b;
     b =  a -  b;
     a =  a -  b;
    //Using bitwise
     a =  a ^  b;
     b =  a ^  b;
     a =  a ^  b;
}
int add(int x,int y){
    return x+y;
}
int sub(int x,int y){
    return x-y;
}
int mul(int x,int y){
    return x*y;
}
int divi(int x,int y){
    return x/y;
}
int modlo(int x,int y){
    return x%y;
}
void calc(int x,int y,int (*ops)(int,int)){
    int result = ops(x,y);
    std::cout<<"Result "<<result<<std::endl;
}
std::pair <int,int>getMaxMin(int a,int b){
    return {std::max(a,b),std::min(a,b)};
}
std::tuple<int,int,int>tupleFun(int a,int b){
    return std::make_tuple(std::min(a,b), std::max(a,b), a+b);
}
int main(){
    //In C++ main's return type should be int.(C++ (C++98 and later)).
    print();
    print(10);
    area(10.0);
    area(10);
    area(10,10);
    int num;
    std::cout<<"Enter number u want to finnd square"<<std::endl;
    std::cin>>num;
    int squareResult = square(num);
    std::cout<<"Square of number "<<num<<" is "<<squareResult<<std::endl;
    int num2;
    std::cout<<"Enter another number"<<std::endl;
    std::cin>>num2;
    std::cout<<"Before swap "<<num<<" "<<num2<<std::endl;
    swapValues(&num,&num2);
    swapValues(num,num2);
    std::cout<<"After swap "<<num<<" "<<num2<<std::endl;
    std::swap(num,num2);
    std::cout<<"After using std::swap "<<num<<" "<<num2<<std::endl;
    num = (num>num2)?num:num2;
    std::cout<<"Fibonaci series for "<<num<<" terms is"<<std::endl;
    for(int i=0;i<num;i++)
        std::cout<<fibo(i)<<'\t';
    int (*funcPtr) (int);
    funcPtr = fibo;
    std::cout<<"Fibonaci sequence value of "<<num<<" term is"<<funcPtr(num);
    std::cout<<"What do u want to do with two nums\nAdd sub mul div rem(mod)"<<std::endl;
    char op;
    std::cin >> op;
    switch(op){
        case 'a': calc(num,num2,add);break;
        case 's': calc(num,num2,sub);break;
        case 'm': calc(num,num2,mul);break;
        case 'd': calc(num,num2,divi);break;
        case 'r': calc(num,num2,modlo);break;
        default:std::cout<<"Operation not supported"<<std::endl;
    }
    //Return values in pair
    std::pair <int,int> result = getMaxMin(num,num2);
    std::cout<<"Max is "<<result.first<<" Min is "<<result.second<<std::endl;
    //Return multiple values
    auto tupleResult = tupleFun(num,num2);
    std::cout<<"Min is "<< std::get<0>(tupleResult)<<" Max is "<<std::get<1>(tupleResult)<<" Sum of numbers is "<<std::get<2>(tupleResult)<<std::endl;
    //For dynamic data we can use vector.
    /*
    Lambda Functions - allow defining short functions inline, without needing separate function definitions.
    [ capture ] ( parameters ) -> return_type { function_body }
    [ capture ]	Captures surrounding variables ([] if none)
    ( parameters )	List of function parameters
    -> return_type	(Optional) Explicit return type
    { function_body }	Function definition
    */
   auto square = [](int x) { return x * x; };
   std::cout<<"Square from Lambda "<<square(num2)<<std::endl;
   std::cout<<"num2 before lambda call "<<num2<<std::endl;
   auto inc = [num2](){return num2+1;};
   std::cout<<"Result of Lambda fucntion inc is "<<inc()<<std::endl;
   num2 = 100; // Changing `num2` won't affect lambda's captured value
   std::cout<<"num2 after lambda call and assigning value to it "<<inc()<<std::endl;
   auto incR = [&num2](){return num2+10;};
   std::cout<<"num2 after lambda call incR "<<incR()<<std::endl;
    return 0;
}