#include<bits/stdc++.h>
using namespace std;
void solve(vector<int> &arr, int i, int sum, int &maxi){
    if(i>=arr.size()){
        maxi = max(maxi, sum);
        return;
    }
    solve(arr, i+2, sum+arr[i], maxi);
    solve(arr, i+1, sum, maxi);
    
}
int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8};
    int sum = 0;
    int maxi = INT_MIN;
    int i=0;
    solve(arr,i, sum, maxi);
    cout<<"Max sum: "<<maxi<<endl;
}