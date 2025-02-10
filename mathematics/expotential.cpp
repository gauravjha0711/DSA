#include<iostream>
using namespace std;
int fastExpotential(int a, int b){
    int ans = 1;
    while(b>0){
        if(b & 1){
            ans = ans*a;
        }
        a=a*a;
        b=b/2;
    }
    return ans;
}
int main(){
    cout<<"Enter two number first for base and second for power: ";
    int a, b;
    cin>>a>>b;
    int num = fastExpotential(a,b);
    cout<<"Number: "<<num<<endl;  
}