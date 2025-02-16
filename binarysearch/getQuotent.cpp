#include<iostream>
using namespace std;
int getQuotent(int dividend, int divisor){
    int s=0, e=dividend;
    int ans=-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(mid*divisor==dividend){
            return mid;
        }
        else if(mid*divisor<dividend){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
}
int main(){
    int dividend=-10;
    int divisor=3;
    int ans = getQuotent(abs(dividend),abs(divisor));
    if((dividend<0 && divisor>0) || (dividend)){
        ans = 0- ans;
    }
    cout<<"Quotent is: "<<ans<<endl;
    return 0;
}