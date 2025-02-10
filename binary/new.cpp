#include<iostream>
#include<cmath>
using namespace std;
void decimalToBinary(int n){
    int pow=1,sum=0,rem;
    while(n>0){
        rem=n%2;
        sum=sum+rem*pow;
        pow*=10;
        n/=2;
    }
    cout<<"After change: "<<sum<<endl;
}
void binaryToDecimal(int n){
    int sum=0,power=0,rem;
    while(n>0){
        rem=n%10;
        sum=sum+(rem*pow(2,power++));
        n/=10;
    }
    cout<<"After change: "<<sum<<endl;
}
int main(){
    int a;
    cout<<"Enter number: ";
    cin>>a;
    //decimalToBinary(a);
    binaryToDecimal(a);
}