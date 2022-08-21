#include<iostream>
using namespace std;
struct Node
{
   int data;
   Node *next;
   
};

class LinkList
{
private:
    Node *first;
    int size;
public:
LinkList(){
        first=new Node;
        first->next=NULL;   
    }
    LinkList(int a[], int n){
        first=new Node;
        first->next=NULL;  
        for (int i=0; i<n; i++){
            Node *s;
            s=new Node; s->data=a[i];  
            s->next=first->next;       
            first->next=s;
        }
        size=n;
    }
    ~LinkList( ){
        Node *p, *q;
        p=first;     
        while (p!=NULL)  {
            q=p;    
            p=p->next;  
            delete q;    
        }
    }          
    void add(int i, int x){
        Node *p;
        int j;
        p=first ; 
        j=0;   
        while (p!=NULL && j<i-1){
            p=p->next;   
            j++;
        }
        if (p==NULL) throw "位置";
        else { 
	        Node *s;
            s=new Node; 
	        s->data=x;  
            s->next=p->next;       
            p->next=s;
        }  
        size++;
    }
    void addFirst(int x){
        add(0, x);
    }
    void addLast(int x){
        add(size,x);
    }
    int Delete(int i){ 
        Node *p;
        int j;
        p=first ; j=0;  
        while (p!=NULL && j<i-1)  {
            p=p->next;
            j++;
        }
        if (p==NULL || p->next==NULL) throw "位置";  
        else {
            Node *q; int x;
            q=p->next; x=q->data; 
            p->next=q->next; 
            delete q;
            size--; 
            return x;
        }
    }
    void deleteFirst(){
        Delete(0);
    }
    void deleteLast(){
        Delete(size);
    }       
    bool contaun(int x){
        Node *p; int j;
        p=first->next; j=1;
        while (p!=NULL && p->data!=x){
            p=p->next;
            j++;
        }
        if (p!=NULL) return true;
        else return false;
    }      
    void PrintList(){
        Node *p;
	    p=first->next;
	    while (p!=NULL)
    {
	    cout<<p->data<<"  ";
	    p=p->next;
	}
	    cout<<endl;
    }       
};
int main(){
     LinkList linklist;
    for(int i=0;i<=5;i++){
        linklist.addFirst(i);
        linklist.PrintList();
    }
    linklist.add(2,666);
    linklist.PrintList();
    return 0;
}