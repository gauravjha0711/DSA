#include<iostream>
#include<vector>
using namespace std;
//using sieve for fast execution and reduce time complexity
// int countPrime(int n){
//     if(n==0){
//         return 0;
//     }
//     vector<bool> prime(n, true);
//     prime[0]=prime[1]=false;
//     int count=0;
//     for(int i=2;i<n;i++){
//         if(prime[i]){
//             count++;
//             int j=i*i;
//             while(j<n){
//                 prime[j]=false;
//                 j+=i;
//             }
//         }
//     }
//     return count;
// }
// int main(){
//     int n;
//     cout<<"Enter the number: ";
//     cin>>n;
//     cout<<"Total prime number between 0 to "<<n<<" are: "<<countPrime(n)<<endl;
// }




vector<bool> Prime(int n){
    vector<bool> prime(n+1, true);
    prime[0]=prime[1]=false;
    for(int i=2;i*i<n;i++){
        if(prime[i]){
            int j=i*i;
            while(j<n){
                prime[j]=false;
                j+=i;
            }
        }
    }
    return prime;
}
int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    vector<bool> prime = Prime(n);
    cout<<"Prime number between 0 to "<<n<<" are: ";
    for(int i=0;i<n;i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;
}