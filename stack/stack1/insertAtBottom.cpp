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
    cout<<"Enter the element to insert at bottom: ";
    int element;
    cin>>element;
    insertAtBottom(st, element);
    cout<<"Stack after inserting element at bottom: ";
    print(st);
    
}