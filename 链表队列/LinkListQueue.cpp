#include<iostream>
using namespace std;
template<class T>
struct Node
{
   T data;
   Node *next; 

};
template<class E>
class LinkListQueue
{
private:
    Node <E> *head;
    Node <E> *tail;
    int size=0;
public:
    LinkListQueue(){
        head=NULL;
        tail=NULL;
        size=0;
    }
    int getsize(){
        return size;
    }
    bool isEmpty(){
        return size==0;
    }
    void enqueue(E e){
        Node <E> *x;
        x=new Node<E>;
        x->data=e;
        x->next=NULL;
        if(tail==NULL){
            tail=x;
            head=tail;
        }
        else{
            tail->next=x;
            tail=tail->next;
        }
        size++;
    }
    E dequeue(){
        if(isEmpty()){
            throw "Dequeue failed.Queue is empty.";
        }
        Node <E> *retNode=head;
        head=head->next;
        if(head==NULL){
            tail=NULL;
        }
        size--;
        return retNode->data;
    }
    E getFront(){
         if(isEmpty()){
            throw "Queue is empty.";
        }
        return head->data;
    }
    void print(){
        Node<E> *p;
	    p=head;
        cout<<"Queue:front[";
	    while (p!=NULL)
            {
	    cout<<p->data<<" -> ";
	    p=p->next;
	        }
        cout<<"NULL ]tail";
	    cout<<endl;
    }       
};
int main(){
    LinkListQueue <int> linklistqueue;
    for(int i=0;i<10;i++){
        linklistqueue.enqueue(i);
        linklistqueue.print();
        if(i%3==2){
            linklistqueue.dequeue();
            linklistqueue.print();
        }
    }
    return 0;
}

