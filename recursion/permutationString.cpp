#include<iostream>
using namespace std;
void permutation(string str, int index){
    if(index>=str.length()){
        cout<<str<<" ";
        return;
    }
    for(int j=index;j<str.length();j++){
        swap(str[index],str[j]);
        permutation(str, index+1);
        //backtranking  (optional)
        swap(str[index],str[j]);
    }
}
int main(){
    string str;
    cout<<"Enter string: ";
    cin>>str;
    int index = 0;
    permutation(str, index);
}