#include<iostream>
using namespace std;
void printDigit(int n){
    if(n==0){
        return;
    }
    int digit = n%10;
    printDigit(n/10);
    cout<<digit<<" ";
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    printDigit(n);
    cout<<endl;
    return 0;
}