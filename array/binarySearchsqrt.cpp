#include<iostream>
using namespace std;
int findsqrt(int n){
    int s=0,e=n;
    long long int mid = s+(e-s)/2;
    int ans = -1;
    while (s<=e){
        if(mid*mid==n){
            return mid;
        }
        else if(mid*mid<n){
            ans = mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter a number: ";
    cin>>n;
    int ans = findsqrt(n);
    cout<<"sqrt: "<<ans<<endl;
}