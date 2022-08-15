#include<iostream>
#include<string>
#include<string.h>
using namespace std;
template<class T>
class Array {
private:
	T *p;
	int size;
	int capacity;
	void resize(int newCapacity){
		T *newDate=new T[newCapacity];
		for(int i=0;i<size;i++){
			newDate[i]=p[i];
		}
		capacity=newCapacity;
		p=newDate;
	}
public:
	
    Array(int capa) {
		capacity = capa;
		p = new T[capacity];
		size = 0;
	}
	Array() {
		capacity = 10;
		p = new T[10];
		size = 0;
	}
	int getSize() {
		return size;
	}
	int getCapacity() {
		return capacity;	
	}
	bool isEmpty() {
		return size == 0;
	}
	void add(int index, T e) {
	
		if (index<0 || index>size) {
			
				try {
					throw"Add failed. Require index<0 || index>szie";
				}
				catch (const char* i) {
					cout << i << endl;
				}
			}
		if (size == capacity) {
			resize(2*capacity);
			}	
		for (int i = size - 1;i >= index;i--)
			p[i + 1] = p[i];
		p[index] = e;
		size++;
	}
	void addLast(T e) {
		add(size, e);
	}
	void addFirst(T e) {
		add(0, e);
	}
	int get(int index) {
		if (index < 0 || index >= size) {
			try {
				throw"Get failed. Index is illegal.";
			}
			catch (const char* i) {
				cout << i << endl;
			}
		}			
		return p[index];
	}
    int getLast(){
        return get(size-1);
    }
    int getFirst(){
        return get(0);
    }
	void set(int index, T e) {
		if (index < 0 || index >= size) {
			try {
				throw"Set failed. Index is illegal.";
			}
			catch (const char* i) {
				cout << i << endl;
			}
		}
		p[index] = e;
	}
	void print() {
		cout<<"Array:capacity="<<capacity<<",size="<<size<<endl;
		cout << "[ ";
		for (int i = 0;i < size;i++) {
			cout << p[i];
			if (i != size - 1)
				cout << ", ";
		}
		cout << "]" << endl;		
	}
	bool contains(T e) {
		for (int i = 0;i < size;i++) {
			if (p[i] == e)
				return true;
			return false;
		}
	}
	int find(T e) {
		for (int i = 0;i < size;i++) {
			if (p[i] == e)
				return i;
			return -1;
		}
	}
	T remove(int index) {
		if (index < 0 || index >= size) {
			try {
				throw"Remove failed. Index is illegal.";
			}
			catch (const char* i) {
				cout << i << endl;
			}
		}
		T ret = p[index];
		for (int i = index + 1;i < size;i++)
			p[i - 1] = p[i];
		size--;
		if(size==capacity/4 && (capacity/2) !=0){
			resize(capacity/2);
		}
		return ret;
	}
    T removeFirst() {
		return remove(0);
	}
	T removeLast() {
		return remove(size - 1);
	}
	void removeElement(T e) {
		int index = find(e);
		if (index != -1)
			remove(index);
	}
};
template<class T>
class ArrayStack:public Array<T>{
public:
    ArrayStack():Array<T>(10){}
    ArrayStack(int Capacity):Array<T>(Capacity){}
    T pop(){
        return Array<T>::removeLast();
    }
    void push(T e){
        Array<T>::addLast(e);
    }
    T peek(){
        return Array<T>::getLast();
    }
    void print(){
        cout<<"Stack:capacity="<<Array<T>::getCapacity()<<",size="<<Array<T>::getSize()<<endl;
		cout << "[ ";
		for (int i = 0;i <Array<T>::getSize();i++) {
			cout << Array<T>::get(i);
			if (i != Array<T>::getSize() - 1)
				cout << ", ";
		}
		cout << " ]top" << endl;
    }
};
class solution{
	public:
	bool isValid(string s){
		ArrayStack <char> stack;
		for(int i=0;i<s.length();i++){
			char c=s[i];
			if(c=='{'||c=='('||c=='[')
			    stack.push(s[i]);
			else{  
				if(stack.isEmpty())
				    return false;
				char topChar=stack.pop();
				if(c==')'&&topChar!='(')
				    return false;
				if(c==']'&&topChar!='[')
				    return false;
				if(c=='}'&&topChar!='{')
				    return false;
			}
		}
	    return stack.isEmpty();
	}

};
int main (){
    string s="{}([])";
	if( solution().isValid(s))
	cout<<"正确"<<endl;
	else
	cout<<"错误"<<endl;
	string S="{}(])";
	if( solution().isValid(S))
	cout<<"正确"<<endl;
	else
	cout<<"错误"<<endl;

}