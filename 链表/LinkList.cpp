#include<iostream>
using namespace std;
template<class T>
struct Node
{
   T data;
   Node *next; 

};
template<class E>
class LinkList
{
private:
    Node <E> *dummyhead;
    int size;
public:
    LinkList(){
        dummyhead=new Node<E>;
        dummyhead->next=NULL; 
        size=0;  
    }
    LinkList(E a[], int n){
        dummyhead=new Node<E>;
        dummyhead->next=NULL;  
        for (int i=0; i<n; i++){
            Node <E>*s;
            s=new Node<E>; s->data=a[i];  
            s->next=dummyhead->next;       
            dummyhead->next=s;
        }
        size=n;
    }
    ~LinkList( ){
        Node <E> *p, *q;
        p=dummyhead;     
        while (p!=NULL)  {
            q=p;    
            p=p->next;  
            delete q;    
        }
    }          
    int getSize(){
        return size;
    }
    void add(int index, E x){
        if(index<0||index>size){
            throw "Add failed.Illeagl index.";
        }
        Node<E> *prev=dummyhead;
        for(int i=0;i<index;i++){
            prev=prev->next;
        }
        Node <E> *e;
        e=new Node<E>;
        e->data=x;
        e->next=prev->next;
        prev->next=e;
         
        size++;
    }
     void addFirst(E x){
        add(0, x);
    }
    void addLast(E x){
        add(size,x);
    }
    int get(int index){
        if(index<0||index>=size){
            throw "Get failed.Illegal index.";
        }
        Node <E> *cur=dummyhead->next;
        for(int i;i<index;i++){
            cur=cur->next;
        }
        return cur->data;
    }
    int getFirst(){
        return get(0);
    }
    int getLast(){
        return get(size-1);
    }
    void set(int index,E x){
        if(index<0||index>=size){
            throw "Get failed.Illegal index.";
        }
        Node<E> *cur=dummyhead->next;
        for(int i;i<index;i++){
            cur=cur->next;
        }
        cur->data=x;
    }
    int remove(int index){ 
        if(index<0||index>=size){
            throw "Remove failed.Illeagl index.";
        }
        Node<E> *prev=dummyhead;
        for(int i=0;i<index;i++){
            prev=prev->next;
        }
        Node<E> *retNode=prev->next;
        prev->next=retNode->next;
        retNode->next=NULL;
        size--;
        return retNode->data;
    }
    void removeFirst(){
        remove(0);
    }
    void removeLast(){
        remove(size-1);
    }       
    bool contain(E x){
        Node<E> *p; int j;
        p=dummyhead->next; j=1;
        while (p!=NULL && p->data!=x){
            p=p->next;
            j++;
        }
        if (p!=NULL) return true;
        else return false;
    }      
    void PrintList(){
        Node<E> *p;
	    p=dummyhead->next;
	    while (p!=NULL)
    {
	    cout<<p->data<<"  ";
	    p=p->next;
	}
	    cout<<endl;
    }       
};
int main(){
    LinkList<int> linklist;
    for(int i=0;i<=5;i++){
        linklist.addFirst(i);
        linklist.PrintList();
    }
    linklist.add(2,666);
    linklist.PrintList();
    linklist.remove(2); 
    linklist.PrintList();
    linklist.removeFirst();
    linklist.PrintList();
    linklist.removeLast();
     linklist.PrintList();
    return 0;
}

