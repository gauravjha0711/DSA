#include<iostream>
#include<stack>
using namespace std;
void insertSorted(stack<int> &st, int element){
    if(st.empty() || st.top()<=element){
        st.push(element);
        return;
    }
    
    int temp = st.top();
    st.pop();

    //recursion
    insertSorted(st, element);

    //backtracking step
    st.push(temp);
}
void sortStack(stack<int> &st){
    if(st.size()==1){
        return;
    }

    int temp = st.top();
    st.pop();

    //recursion
    sortStack(st);

    //backtracking
    insertSorted(st, temp);
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
    cout<<"Stack before sorting: ";
    print(st);
    sortStack(st);
    cout<<"Stack after sorting: ";
    print(st);
}