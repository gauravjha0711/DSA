#include<iostream>
using namespace std;
void stringPermutation(string &input, int index){
    if(index>=input.length()){
        cout<<input<<" ";
        return;
    }
    for(int j=index;j<input.length();j++){
        swap(input[index], input[j]);
        stringPermutation(input, index+1);
        swap(input[index], input[j]);
    }
}
int main(){
    string input;
    cout<<"Enter the string: ";
    cin>>input;
    stringPermutation(input, 0);
    return 0;
}