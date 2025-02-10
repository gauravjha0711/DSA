#include<iostream>
using namespace std;
void pyramid(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void invertedPyramid(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=0;j<n-i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}
void hallowInvertedPyramid(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            cout<<" ";
        }
        for(int j=0;j<n-i;j++){
            if(j==0 || j==n-i-1){
                cout<<"* ";
            }
            else{
                cout<<"  ";
            }
        }
        cout<<endl;
    }
}
void fullHallow(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        for(int j=0;j<2*i+1;j++){
            cout<<" ";
        }
        for(int j=0;j<n-i;j++){
            cout<<"*";
        }
        cout<<endl;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        for(int j=0;j<2*n-2*i-1;j++){
            cout<<" ";
        }
        for(int j=0;j<i+1;j++){
            cout<<"*";
        }
        cout<<endl;
    }
}
void mirrorAlpha(int n){
    for(int i=0;i<n;i++){
        int j;
        for(j=0;j<i+1;j++){
            cout<<char(65+j)<<" ";
        }
        char ch=char(65+j);
        for(char k=ch-2;k>='A';k--){
            cout<<k<<" ";
        }          
        cout<<endl;
    }
}
int main(){
    int n;
    cout<<"Enter number: ";
    cin>>n;
    // pyramid(n);
    // cout<<endl;
    // invertedPyramid(n);
    // cout<<endl;
    // hallowInvertedPyramid(n);
    // cout<<endl;
    // fullHallow(n);
    // cout<<endl;
    mirrorAlpha(n);
    cout<<endl;
}