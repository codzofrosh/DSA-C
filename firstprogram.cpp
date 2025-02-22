#include<iostream>
/*
Namespaces in C++ provide a way to group related functions, classes, and variables to avoid name conflicts.
say if we need to define two functions with same function name,we can give it under different name spaces for resolving conflicts.
*/
using namespace std; //Avoid this line in big programs
int main(){
    int a;
    char b;
    string c;
    //cout<<"Hello World From C++\n"; To append a new line we can use endl at end of statement to move cursor to newline.
    cout<<"Hello World from C++"<<endl;
    cout<<"Enter data for values int,char,string"<<endl;
    cin>>a>>b>>c;
    //This is the commonly used string formatting style. However other formats are also available.
    cout<<"Values Entered are "<<a<<" "<<b<<" "<<c<<endl;
    /*
    1. printf("%d %c %s",a,b,c); -> Similar to C
     
    2. Using String Stream
    stringstream ss;
    ss << "Values Entered are " << a << " " << b << " " << c;
    
    string formatted_string = ss.str();
    cout << formatted_string << endl;

    3. std::format -> Similar to python  
    cout << format("Values Entered are {} {} {}", a, b, c) << endl;
    */
}