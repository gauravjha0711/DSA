#include<iostream>
#include<stack>
using namespace std;
void insertAtBottom(stack<int> &st, int element){
    if(st.empty()){
        st.push(element);
        return;
    }

    int temp = st.top();
    st.pop();

    //recursion
    insertAtBottom(st, element);

    //backtracking step
    st.push(temp);
}
void reverseStack(stack<int> &st){
    if(st.empty()){
        return;
    }
    int temp = st.top();
    st.pop();

    reverseStack(st);

    insertAtBottom(st, temp);

}
void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}
int main(){
    stack<int> st;
    cout<<"Enter the number of elements: ";
    int n;
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.push(x);
    }
    cout<<"Stack before reverse: ";
    print(st);
    reverseStack(st);
    cout<<"Stack after reverse: ";
    print(st);
    
}