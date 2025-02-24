#include<iostream>
#include<stack>
using namespace std;
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        st.push(ch);
    }
    cout<<"Reversed string: ";
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
}