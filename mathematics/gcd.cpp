#include<iostream>
using namespace std;
int findgcd(int a, int b){
    if(a==0){
        return b;
    }
    if(b==0){
        return a;
    }
    while(a>0 && b>0){
        if(a>b){
            a-=b;
        }
        else{
            b-=a;
        }
    }
    return (a==0)?b:a;
}
int findlcm(int a, int b){
    int gcd = findgcd(a,b);
    int lcm = (a*b)/gcd;
    return lcm;
}
int main(){
    cout<<"enter two number for gcd and lcm: ";
    int a, b;
    cin>>a>>b;
    int gcd = findgcd(a,b);
    cout<<"GCD: "<<gcd<<endl;
    int lcm = findlcm(a,b);
    cout<<"LCM: "<<lcm<<endl;
}