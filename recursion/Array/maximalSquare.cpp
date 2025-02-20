#include<iostream>
#include<vector>
using namespace std;
void maximalSquare(vector<vector<int>>& matrix,int n, int m, int i, int j, int &maxx){
    if(i>=n || j>=j){
        return 0;
    }
    int right = maximalSquare(matrix,n,m,i,j+1,maxx);
    int down = maximalSquare(matrix,n,m,i+1,j,maxx);
    int diagonal = maximalSquare(matrix,n,m,i+1,j+1,maxx);
    if(matrix[i][j]==1){
        int ans = 1+min(right,min(down,diagonal));
        maxx = max(maxx,ans);
        return ans;
    }
    else{
        return 0;
    }
}
int main(){
    int n,m;
    cout<<"Enter the row and column: ";
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m,0));
    cout<<"Enter the matrix: ";
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    int maxx = 0;
    int i=0,j=0;
    maximalSquare(matrix,n,m,i,j,maxx);
    cout<<"Maximal square: "<<maxx*maxx;
    return 0;
}