    #include<iostream>
    #include<utility>
    #include<climits>
    #include<tuple>
    //Arrays Vectors Pointers
    /*
    C++ does not support Variable-Length Arrays (VLA) in standard templates.
    Your int arr[size] and int arr2d[size][size2] are VLAs, which are not allowed in C++ function templates -> solved using vectors.
    Templates require compile-time sizes, but size and size2 are known only at runtime.
    */
    void printArray(auto arr[],int size){
        std::cout<<"Array elements are "<<std::endl;
        for(int i=0;i<size;i++){
            std::cout<<arr[i]<<"\t";
        }
    }
    void printArray(auto **arr2d, int row, int col){
        std::cout<<"Array elements are "<<std::endl;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                std::cout<<arr2d[i][j]<<"\t";
            }
            std::cout<<std::endl;
        }
    }
    std::pair<int, int>getMinMax(auto arr[],int size){
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i=0;i<size;i++){
            if(arr[i]>max)
                max = arr[i];
            if(arr[i]<min)
                min = arr[i];
        }
        return{min,max};
    }
    std::pair<int, int>getMinMax(auto **arr,int row,int col){
        int min = INT_MAX;
        int max = INT_MIN;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(arr[i][j]>max)
                max = arr[i][j];
                if(arr[i][j]<min)
                min = arr[i][j];
            }
        }
        return{min,max};
    }
    void reverseArray(auto arr[],int size){
        int begin = 0,end = size-1,mid = size/2,temp;;
        while(begin!=mid && end!=mid){
            temp = arr[begin];
            arr[begin] = arr[end];
            arr[end] = temp;
            begin+=1;
            end-=1;
        }
    }
    std::tuple<bool,int,int>findKey(auto **arr2d,int row,int col,auto key){
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(key == arr2d[i][j]){
                    return std::make_tuple(true,i,j);
                }
            }
        }
        return std::make_tuple(false,0,0);
    }
    void transpose2dArray(int**& arr2d, int& row, int& col) {  
        int** transposed = new int*[col];
        for (int i = 0; i < col; i++) {
            transposed[i] = new int[row];
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                transposed[j][i] = arr2d[i][j];  
            }
        }
        for (int i = 0; i < row; i++) {
            delete[] arr2d[i];
        }
        delete[] arr2d;
        arr2d = transposed;
        std::swap(row, col);
    }
    int main(){
        int size;
        std::cout<<"Enter size of array"<<std::endl;
        std::cin>>size;
        int arr[size];
        for(int i=0;i<size;i++){
            std::cout<<"Enter "<<i+1<<"th element"<<std::endl;
            std::cin>>arr[i];
        }
        printArray(arr,size);
        std::pair<int,int>result = getMinMax(arr,size);
        std::cout<<"Min element is "<<result.first<<" Max element is "<<result.second;
        reverseArray(arr,size);
        std::cout<<"Array after reverse from Main function"<<std::endl;
        printArray(arr,size);
        std::cout<<"Enter another size for 2d Array"<<std::endl;
        int size2;
        std::cin>>size2;
        //For 2D arrays we will follow dynamic memory allocation concept.
        int **arr2d = new int*[size];
        for(int i=0;i<size;i++)
            arr2d[i] = new int[size2];
        for(int i=0;i<size;i++){
            for(int j=0;j<size2;j++){
                std::cout<<"Enter "<<i+1<<"row's" <<j+1<<"element"<<std::endl;
                std::cin>>arr2d[i][j];
            }
        }
        printArray(arr2d,size,size2);
        result = getMinMax(arr2d,size,size2);
        std::cout<<"Min element is "<<result.first<<" Max element is "<<result.second;
        int key;
        std::cout<<"Enter element u want to search"<<std::endl;
        std::cin>>key;
        auto findResult = findKey(arr2d,size,size2,key);
        if(std::get<0>(findResult))
            std::cout<<"Key found at "<<std::get<1>(findResult)<<" row "<<std::get<2>(findResult)<<" column"<<std::endl;
        else    
            std::cout<<"Key not found"<<std::endl;
        transpose2dArray(arr2d,size,size2);
        std::cout<<"Transpose of 2d Array is "<<std::endl;
        printArray(arr2d,size,size2);
        return 0;
    }