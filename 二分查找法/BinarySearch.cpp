#include<iostream>
using namespace std;
template<class E>
class BinarySearch{
    private:
    BinarySearch(){};
    public:
    static int search(E* data,E target,int n){
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(data[mid]==target){
                return mid;
            }
            else if(data[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return -1;
    }
    static int search2(E* data,E target,int n){
        int l=0;
        int r=n;
        while(l<r){
            int mid=l+(r-l)/2;
            if(data[mid]==target){
                return mid;
            }
            else if(data[mid]<target){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return -1;
    }
    static int searchR(E* data,E target,int n){
        return searchR(data,0,n-1, target);
    }
    static int searchR(E* data,int l, int r,int target){
        if(l>r){
            return -1;
        }
        int mid=l+(r-l)/2;
        if(data[mid]==target){
            return mid;
        }
        else if(data[mid]>target){
            return searchR(data,l,mid-1,target);
        }
        else{
            return searchR(data,mid+1,r,target);
        }
    }
    static int upper(E* data,E target,int n){
        int l=0;
        int r=n;
        while(l<r){
            int mid=l+(r-l)/2;
            if(data[mid]<=target){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return l;
    }
    static int upper_ceil(E* data,E target,int n){
        int u=upper(data,target,n);
        if(data[u-1]==target){
            return u-1;
        }
        return u;
    }
    static int lower_ceil(E* data,E target,int n){
        int u=upper(data,target,n);
        if(data[u-1]==target){
            while(data[u-2]==target){
                u--;
            }
            return u-1;
        }
        return u;
    }
    static int lower(E* data,E target,int n){
        int l=-1;
        int r=n-1;
        while(l<r){
            int mid=l+(r-l+1)/2;
            if(data[mid]<target){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        
        return l;
    }
    static int lower_floor(E* data,E target,int n){
        int u=lower(data,target,n);
        if(data[u+1]==target){
            return u+1;
        }
        return u;
    }
    static int upper_floor(E* data,E target,int n){
        int l = -1, r = n - 1;       
        while(l < r){

            int mid = l + (r - l + 1) / 2;
            
            if(data[mid]<=target)
                l = mid;
            else
                r = mid - 1;
        }
        return l;   
    }
    static int search3(E* data, E target,int n){

        int l = 0, r = n-1;
        while(l < r){

            int mid = l + (r - l) / 2;
            if(data[mid]<target)
                l = mid + 1;
            else
                r = mid;
        }
        if(l < n-1 && data[l]==target)
            return l;
        return -1;
    }



};
int main(){
    int data[]={0,1,2,3,4,4,6,7,8,9,10};
    int n=sizeof(data)/sizeof(data[0]);

    cout<<BinarySearch<int>::search2(data,9,n)<<endl;
    cout<<BinarySearch<int>::upper(data,5,n)<<endl;
    cout<<BinarySearch<int>::upper_ceil(data,5,n)<<endl;
    cout<<BinarySearch<int>::lower_ceil(data,4,n)<<endl;
    cout<<BinarySearch<int>::lower(data,5,n)<<endl;
    cout<<BinarySearch<int>::lower_floor(data,5,n)<<endl;
    cout<<BinarySearch<int>::upper_floor(data,5,n)<<endl;
    cout<<BinarySearch<int>::search3(data,9,n)<<endl;
    

    return 0;
}