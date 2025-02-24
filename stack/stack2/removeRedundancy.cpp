#include<iostream>
#include<stack>
using namespace std;
bool removeRedundancy(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch=='(' || ch=='+' || ch=='-' || ch=='*' || ch=='/'){
            st.push(ch);
        }
        else if(ch==')'){
            int operatorCount = 0;
            while(!st.empty() && st.top()!='('){
                char temp = st.top();
                if(temp=='+' || temp=='-' || temp=='*' || temp=='/'){
                    operatorCount++;
                }
                st.pop();
            }
            st.pop();
            if(operatorCount==0){
                return true;
            }
        }
    }
    return false;
}
int main(){
    string s;
    cout<<"Enter the expression: ";
    cin>>s;
    cout<<(removeRedundancy(s)?"Redundant":"Not Redundant")<<endl;
}