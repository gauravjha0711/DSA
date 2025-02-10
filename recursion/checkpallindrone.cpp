#include<iostream>
using namespace std;
bool checkPallindrone(string str,int i,int j){
    if(i>j){
        return true;
    }
    if(str[i]!=str[j]){
        return false;
    }
    else{
        return checkPallindrone(str,i+1,j-1);
    }
}
int main(){
    string name;
    cout<<"Enter the string: ";
    cin>>name;
    bool pallin = checkPallindrone(name, 0, name.length()-1);
    if(pallin){
        cout<<"String is pallindrone"<<endl;
    }
    else{
        cout<<"String is not pallindrone"<<endl;
    }
}