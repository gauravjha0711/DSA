#include<iostream>
using namespace std;
int main(){
    // string s;
    // cin>>s;
    // cout<<"string: "<<s<<endl;
    // cout<<"Length: "<<s.length()<<endl;
    // cout<<"Position 0: "<<s.at(0)<<endl;
    // cout<<"front: "<<s.front()<<endl;
    // cout<<"back: "<<s.back()<<endl;

    // string str1 = "gaurav";
    // string str2 = "jha";
    // str1.append(str2);
    // cout<<str1<<endl;
    // string str3 = "Hello world";
    // str3.erase(5,3);
    // cout<<str3<<endl;
    // string name = "Gaurav jha";
    // string middle = "kumar ";
    // name.insert(7, middle);
    // cout<<name<<endl; 
    string str4 = "I am from Bihar";
    string str5 = "from";
    if(str4.find(str5)==string::npos){
        cout<<"not found"<<endl;
    }
    else{
        cout<<"found"<<endl;
    }
    cout<<str4.substr(5,5);
}