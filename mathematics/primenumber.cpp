#include<iostream>
#include<vector>
using namespace std;
//using sieve for fast execution and reduce time complexity
vector<bool> Sieve(int n){
    vector<bool>sieve(n+1,true);
    sieve[0]=sieve[1]=false;
    for(int i=2;i<=n;i++){
        if(sieve[i]==true){
            int j=i*i;
            while(j<=n){
                sieve[j]=false;
                j+=i;
            }
        }
    }
    return sieve;
}
int main(){
    cout<<"Enter number: ";
    int n;
    cin>>n;
    vector<bool>prime = Sieve(n);
    for(int i=0;i<n;i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }
}