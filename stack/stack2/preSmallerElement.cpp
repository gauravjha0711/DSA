#include<iostream>
#include<stack>
#include<vector>
using namespace std;
vector<int> preSmallerElement(int *arr, int size, vector<int> &ans){
    stack<int> st;
    st.push(-1);
    for(int i=0;i<size;i++){
        int curr = arr[i];
        while(st.top()>=curr){
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
    return ans;
}
int main(){
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    int *arr = new int[size];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    vector<int> ans(size);
    preSmallerElement(arr, size, ans);
    cout<<"The previous smaller element of each element is: ";
    for(int i=0;i<size;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}