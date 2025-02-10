#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(0);
    v.push_back(5);
    v.push_back(3);
    v.push_back(2);
    cout<<"find 3: "<<binary_search(v.begin(),v.end(),5)<<endl;

    int a=3,b=5;
    cout<<"max: "<<max(a,b)<<endl;
    cout<<"min: "<<min(a,b)<<endl;
    swap(a,b);
    cout<<"a: "<<a<<" b: "<<b<<endl;

    string s = "Gaurav";
    reverse(s.begin(),s.end());
    cout<<"reverse: "<<s<<endl;
}