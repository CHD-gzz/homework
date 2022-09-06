#include<iostream>
using namespace std;
template<class E>
class MergeSort{
    private:
    MergeSort(){}
    public:
    static void merge(E *arr,int l,int mid,int r ){
    
        E* temp=new E[r-l+1];       
        for(int n=0;n<=(r-l);n++){
            temp[n]=arr[n+l];
        }

        int i=l;
        int j=mid+1;
        for(int k=l;k<=r;k++){
            if(i>mid){
                arr[k]=temp[j-l];j++;
            }
            else if(j>r){
                arr[k]=temp[i-l];i++;
            }
            else if(temp[i-l]<temp[j-l]){
                arr[k]=temp[i-l];i++;
            }
            else{
                arr[k]=temp[j-l];j++;
            }

        }            
    }
    static void sort(E *arr,int l,int r){
        if(l>=r)
        return;
        int mid=(l+r)/2;
        sort(arr,l,mid);
        sort(arr,mid+1,r);      
        merge(arr,l,mid,r);
    }
    static void sort(E *arr,int n){
       
        sort(arr,0,n);

    }
    static void sort2(E *arr,int l,int r){
        if(l>=r)
        return;
        int mid=(l+r)/2;
        sort2(arr,l,mid);
        sort2(arr,mid+1,r);
        if(arr[mid]>arr[mid+1])      
        merge(arr,l,mid,r);
    }
    static void sort2(E *arr,int n){
       
        sort2(arr,0,n);

    }
    
    
};
int main(){
    int a[]={99,4,6,55,33,21,56,32,65,31,56,12};
    int n=sizeof(a)/sizeof(a[0]);
    MergeSort<int>::sort(a,n-1);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}