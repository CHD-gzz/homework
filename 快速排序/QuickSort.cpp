#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
template<class E>
class QuickSort{
    private:
    QuickSort(){}
    public:
    static void swap(E *arr,int i,int j){
        E t=arr[i];
        arr[i]=arr[j];
        arr[j]=t;          
    }
    static int partition(E *arr,int l,int r){        
        int p= rand()%(r-l+1)+l;
        swap(arr,l,p);

        int j=l;
        for(int i=l+1;i<=r;i++){
            if(arr[i]<arr[l]){
                j++;
                swap(arr,i,j);
            }
        }
        swap(arr,l,j);
        return j;
       
    }
    static int partition2(E *arr,int l,int r){        
        int p= rand()%(r-l+1)+l;
        swap(arr,l,p);

        int i=l+1;
        int j=r;

        while (true)
        {
            while(i<=j && arr[i]<arr[l]){
                i++;
            }
            while(j>=i && arr[j]>arr[l]){
                j--;
            }
            if(i>=j){
                break;
            }
            swap(arr,i,j);
            i++;
            j--;  
        }
        swap(arr,l,j);
        return j;      
    }
    void static InsertSort(E* arr,int l,int r) {
		int n = r-l;
		for (int i = l; i <= r; i++) {
			for (int j = i; j - 1 >= 0; j--) {
				if (arr[j] < arr[j - 1])
					swap(arr, j, j - 1);
				else
					break;
			}
		}
	}
    static void sort(E* arr,int l,int r){
        if(l>=r){
            return;
        }
        int p=partition(arr,l,r);
        sort(arr,l,p-1);
        sort(arr,p+1,r);
    }
    static void sort(E* arr,int n){
        srand((int)time(0));
        sort(arr,0,n-1);
    }
    static void sort2(E* arr,int l,int r){
        if(l-r<=15){
            InsertSort(arr,l,r);
            return;
        }
        if(l>=r){
            return;
        }
        int p=partition(arr,l,r);
        sort2(arr,l,p-1);
        sort2(arr,p+1,r);
    }
    static void sort2(E* arr,int n){
        srand((int)time(0));

        sort2(arr,0,n-1);
    }
    static void sort2ways(E* arr,int l,int r){
        if(l-r<=15){
            InsertSort(arr,l,r);
            return;
        }
        if(l>=r){
            return;
        }
        int p=partition2(arr,l,r);
        sort2ways(arr,l,p-1);
        sort2ways(arr,p+1,r);
    }
    static void sort2ways(E* arr,int n){
        srand((int)time(0));

        sort2ways(arr,0,n-1);
    }
    static void sort3ways(E* arr,int l,int r){
        if(l-r<=15){
            InsertSort(arr,l,r);
            return;
        }
        if(l>=r){
            return;
        }
        int p= rand()%(r-l+1)+l;
        int lt=l;
        int i=l+1;
        int gt=r+1;
        while(i<gt){
            if(arr[i]<arr[l]){
                lt++;
                swap(arr,lt,i);
                i++;
            }
            else if(arr[i]>arr[l]){
                gt--;
                swap(arr,lt,i);
            }
            else{
                i++;
            }
        }
        swap(arr,l,lt);
        sort3ways(arr,l,lt-1);
        sort3ways(arr,gt,r);
    }
    static void sort3ways(E* arr,int n){
        srand((int)time(0));

        sort3ways(arr,0,n-1);
    }
    static E SelectK(E* arr,int l,int r,int k){
        int p=partition(arr,l,r);
        if(p=k){
            return arr[p];
        }
        else if(p<k){
            return SelectK(arr,p+1,r);
        }
        else{
            return SelectK(arr,l,p-1);
        }
    }
    static E SelectK(E* arr,int n,int k){
        srand((int)time(0));
        return SelectK(arr,0,n-1,k);
        
    }
    static E selectK2(E* arr, int n,int k){
        srand((int)time(0));

        int l = 0, r = n - 1;
        while(l <= r){

            int p = partition(arr, l, r);

            if(k == p) return arr[p];

            if(k < p) r = p - 1;
            else l = p + 1;
        }
        try {
			throw"No Solution";
		}
		catch (const char* i) {
			cout << i << endl;
		}

    }

    
   
    
};
int main(){
    int num[]={9,1,4,3,6,5,8,7,13,12,11,10,53,74,223,75,12,865,234,7,4345,6,23423,4543,0};
    int n=sizeof(num)/sizeof(num[0]);
    QuickSort<int>::sort3ways(num,0,n-1);
    for(int i=0;i<n;i++){
        cout<<num[i]<<" ";
    }
    cout<<QuickSort<int>::selectK2(num,n,11);
    cout<<endl;
    
    return 0;
}