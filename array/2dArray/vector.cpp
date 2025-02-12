#include<iostream>
#include<vector>
using namespace std;
int main(){
    // vector<int> v(5, 0);
    // for(int i=0;i<v.size();i++){
    //     cout<<v[i]<<" ";
    // }


    // vector<vector<int>> v(5, vector<int>(10, 0));
    // for(int i=0;i<v.size();i++){
    //     for(int j=0;j<v[i].size();j++){
    //         cout<<v[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }


    vector<vector<int>> v;
    vector<int> temp1(5,0);
    vector<int> temp2(7,1);
    vector<int> temp3(3,2);
    vector<int> temp4(4,3);
    vector<int> temp5(8,4);
    v.push_back(temp1);
    v.push_back(temp2);
    v.push_back(temp3);
    v.push_back(temp4);
    v.push_back(temp5);
        for(int i=0;i<v.size();i++){
        for(int j=0;j<v[i].size();j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}