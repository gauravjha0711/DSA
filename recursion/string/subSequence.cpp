#include<iostream>
#include<vector>
using namespace std;
void subSequence(string input, string output, int index, vector<string> &v){
    if(index>=input.length()){
        // cout<<"-> "<<output<<endl;abc
        v.push_back(output);
        return;
    }
    char ch = input[index];
    //exclude
    subSequence(input, output, index+1, v);
    //include
    output.push_back(ch);
    subSequence(input, output, index+1, v);
}
int main(){
    string input;
    cout<<"Enter the string: ";
    cin>>input;
    string output="";
    vector<string> v;
    subSequence(input, output, 0, v);
    cout<<"Total subsequence: "<<v.size()<<endl;
    cout<<"Subsequence are: "<<endl;
    for(auto x:v){
        cout<<"->"<<x<<endl;
    }
    return 0;
}