#include<iostream>
#include<vector>
using namespace std;
int solve(vector<int> &arr, int s, int e){
    if(s>e){
        return 0;
    }
    int option1 = arr[s] + solve(arr, s+2, e);
    int option2 = 0 + solve(arr, s+1, e);
    return max(option1, option2);
}
int robCircle(vector<int> &arr){
    int n = arr.size();
    if(n==1){
        return arr[0];
    }
    int option1 = solve(arr, 0, n-2);
    int option2 = solve(arr, 1, n-1);
    return max(option1, option2);
}
int main(){
    int n;
    cout<<"Enter the size: ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter element: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int sum = robCircle(arr);
    cout<<"Maximum amount: "<<sum<<endl;
    return 0;
}