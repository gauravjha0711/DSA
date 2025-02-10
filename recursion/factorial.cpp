#include<iostream>
using namespace std;
// int factorial(int n){
//     if(n==0){
//         return 1;
//     }
//     else{
//         return n*(factorial(n-1));
//     }
// }
// int main(){
//     int n;
//     cout<<"Enter a number: ";
//     cin>>n;
//     int fact = factorial(n);
//     cout<<"Factorial of "<<n<<" is: "<<fact<<endl;
// }



// int power(int n){
//     if(n==0){
//         return 1;
//     }
//     return 2*power(n-1);
// }
// int main(){
//     int n;
//     cout<<"Enter a number: ";
//     cin>>n;
//     int pow = power(n);
//     cout<<"Power of "<<n<<" on 2: "<<pow<<endl;
// }



void print(int n){
    if(n==0){
        return ;
    }
    // cout<<n<<" "; 
    print(n-1);
    cout<<n<<" ";
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    print(n);
}