#include<iostream>
using namespace std;
void reverse(string &str,int i,int j){
    if(i>j){
        return ;
    }
    swap(str[i],str[j]);
    i++;
    j--;
    reverse(str,i,j);
}
int main(){
    string name;
    cout<<"Enter the string: ";
    cin>>name;
    cout<<"String before reverse: "<<name<<endl;
    reverse(name,0,name.length()-1);
    cout<<"String after reverse: "<<name<<endl;
}