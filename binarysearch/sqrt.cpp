#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int mySqrt(int x) {
    int s=0,e=x;
    long long int mid = s+(e-s)/2;
    int ans=-1;
    while(s<=e){
        if(mid*mid==x){
            return mid;
        }
        else if(mid*mid<x){
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int main(){
    int x=8;
    cout<<mySqrt(x);
    return 0;
}





bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int r=matrix.size();
    int c=matrix[0].size();
    int n= r*c;
    int s=0,e=n-1;
    while(s<=e){
        int mid= s+(e-s)/2;
        int row=mid/c;
        int col=mid%c;
        int cur = matrix[row][col];
        if(cur==target){
            return true;
        }
        else if(cur<target){
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }    
    return false; 
}