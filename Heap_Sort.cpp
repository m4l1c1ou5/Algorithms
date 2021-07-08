#include<iostream>
using namespace std;
int max(int a[],int c,int b){
    if(a[c]>a[b])
    return c;
    else
    {
        return b;
    }
}
void swap(int a[],int b,int c){
    int temp=a[b];
    a[b]=a[c];
    a[c]=temp;
}
void max_heapify(int a[],int k,int size){
    if(k<size/2){
        int num;
        if(size>(2*k)+2)
        num=max(a,(2*k)+1,(2*k)+2);
        else
        num=(2*k)+1;
        if(a[k]<a[num]){
            swap(a,k,num);
            max_heapify(a,num,size);
        }
    }
}
void build_max_heap(int a[],int size){
    for(int i=(size-1)/2;i>=0;i--){
        max_heapify(a,i,size);
    }
}
void heap_sort(int arr[],int size){
    for(int i=0;i<size;i++){
        swap(arr,size-i-1,0);
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        max_heapify(arr,0,size-i-1);
    }
}
int main(){
    int arr[]={23,11,78,12,5,12,6,11,7,44,11,50,22,45};
    int size=sizeof(arr)/sizeof(arr[0]);
    //mergesort(arr,0,size-1);
    build_max_heap(arr,size);
    heap_sort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
