#include <iostream>

int binsearch(int start,int end, int v, int A[]){
    if(start > end) return -1;

    if(A[(start + end)/2] == v){return (start + end)/2;}

    else if(A[(start + end)/2] > v){
        return binsearch(start,(start + end)/2 - 1, v, A);
    }
    else{
        return binsearch((start + end)/2 + 1, end, v, A);
    }
}

int main(){
    int A[11] = {0,1,2,3,4,5,6,7,8,9,123123};
    std::cout << binsearch(0,10,123123,A);
    return 0;
}

