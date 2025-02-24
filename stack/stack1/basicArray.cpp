#include<iostream>
using namespace std;
class Stack{
    public:
    int top;
    int size;
    int* arr;
    Stack(int n){
        size=n;
        top=-1;
        arr=new int[size];
    }
    void push(int data){
        if(top==size-1){
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            top++;
            arr[top] = data;
        }
    }
    void pop(){
        if(top==-1){
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else{
            top--;
        }
    }
    int peek(){
        if(top==-1){
            cout<<"Stack is empty" <<endl;
            return -1;
        }
        else{
            return arr[top];
        }
    }
    int len(){
        return top+1;
    }
    bool isEmpty(){
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    bool full(){
        if(top==size-1){
            return true;
        }
        else{
            return false;
        }
    }
    void print(){
        cout<<"Stack: ";
        for(int i=0;i<=top;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Stack s(5);
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();
    cout<<s.peek()<<endl;
    cout<<"Size of stack: "<<s.len()<<endl;
    s.pop();
    s.print();
    cout<<s.peek()<<endl;
    cout<<"Size of stack: "<<s.len()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}