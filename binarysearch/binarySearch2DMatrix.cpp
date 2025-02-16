#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
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
int main(){
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target=3;
    cout<<searchMatrix(matrix,target);
    return 0;
}