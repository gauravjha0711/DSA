#include<iostream>
using namespace std;
class stack{
    public:
    int *arr;
    int size;
    int top1;
    int top2;
    stack(int n){
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = size;
    }
    void push1(int x){
        if(top2-top1==1){
            cout<<"Stack is full"<<endl;
        }
        else{
            top1++;
            arr[top1] = x;
        }
    }
    void push2(int x){
        if(top2-top1==1){
            cout<<"Stack is full"<<endl;
        }
        else{
            top2--;
            arr[top2] = x;
        }
    }
    void pop1(){
        if(top1==-1){
            cout<<"Stack is empty"<<endl;
        }
        else{
            arr[top1] = 0;
            top1--;
        }
    }
    void pop2(){
        if(top2==size){
            cout<<"Underflow"<<endl;
        }
        else{
            arr[top2] = 0;
            top2++;
        }
    }
    void print(){
        cout<<"Top1: "<<top1<<endl;
        cout<<"Top2: "<<top2<<endl;
        // cout<<"Stack1: ";
        // for(int i=0;i<=top1;i++){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;
        // cout<<"Stack2: ";
        // for(int i=size-1;i>=top2;i--){
        //     cout<<arr[i]<<" ";
        // }
        // cout<<endl;

        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){
    stack st(6);
    // st.print();

    st.push1(10);
    st.push1(20);

    st.push2(60);
    st.push2(50);
    st.push2(40);
    st.push2(30);
    st.pop1();
    st.push2(25);
    st.print();
}