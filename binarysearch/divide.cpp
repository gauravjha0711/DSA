#include<iostream>
using namespace std;
int divide(int a, int b){
    int s=0,e=b;
    int mid = s+(e-s)/2;
    int ans = 0;
    while(s<=e){
        if(mid*a==b){
            return mid;
        }
        if(mid*a<b){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
int main(){
    int a = 7;
    int b =  -29;
    int r = divide(abs(a),abs(b));
    if((a<0&&b>0) || (a>0&&b<0)){
        r = 0-r;
    }
    cout<<"Remainder : "<<r<<endl;
}