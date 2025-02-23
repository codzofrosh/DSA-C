#include<iostream>
#include<typeinfo> // for typeid
/*
Auto Keyword - allows the compiler to automatically determine the type of a variable at compile time
constexpr - The constexpr keyword is used to declare compile-time constants.
*/
int globalVar = 10;
void func(){
    int locVar = 10;
    globalVar+=1;
}
constexpr int fact(int n){
    int num=1;
    while (n)
    {
        num*=n;
        n-=1;
    }
    /*
    We cannot modify global variables inside constexpr .
    globalVar+=1;
    std::cout<<"Value of GlobalVariable "<<globalVar<<std::endl;
    */
    
    return num;
    
}
int main(){
    auto a = 1;
    auto f = 1.5;
    auto c = 'a';
    auto s = "hello";
    int n;
    std::cout<<"Global variable from main "<<globalVar<<std::endl;
    std::cout<<"ENter number to compute factorial"<<std::endl;
    std::cin>>n;
    std::cout<<"Factorial of number"<<fact(n)<<std::endl;
    std::cout<<"Type of variables "<<typeid(a).name()<<" "<<typeid(f).name()<<" "<<typeid(c).name()<<" "<<typeid(s).name()<<std::endl;
    func();
    //std::cout<<"Local Variable "<<locVar<<std::endl;
    std::cout<<"Global Variable value "<<globalVar<<std::endl;
    //Implicict Type cast -> automatically converts smaller types to larger types to prevent data loss.
    double d = 10.1;
    int sum_i = d + a;
    double sum_d = d + a; 
    std::cout<<"Sum_i "<<sum_i<<"Sum_d"<<sum_d<<std::endl;
    std::cout<<"Type of d before conversion "<<typeid(d).name()<<std::endl;
    //Static_Cast -> safe type conversions between compatible types. Cannot cast unrelated types
    int d = static_cast<int> (d);
    std::cout<<"Type of d after conversion "<<typeid(d).name()<<std::endl;
    /*
    Other Casting types
    1. reinterpret_cast is used to convert between unrelated pointer types (e.g., int* → char*).Use it only when absolutely necessary!
        eg:  reinterpret_cast<char*>(ptr)
    2. const_cast removes the const qualifier from a variable.
        eg: changeConst(&num);
    3. dynamic_cast is used in polymorphism for safe downcasting of a base class pointer to a derived class pointer.
    */
    return 0;
}