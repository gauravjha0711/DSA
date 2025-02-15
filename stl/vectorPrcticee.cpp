#include<iostream>
#include<vector>
using namespace std;
void print(vector<int> v){
    for(int i=0;i<v.size();i++){
        // cout<<v[i]<<" ";
        cout<<v.at(i)<<" ";
    }
    cout<<endl;
}
int main(){
    // vector<int> v;
    // int n;
    // cout<<"Enter size: ";
    // cin>>n;
    // cout<<"Enter elements: ";
    // for(int i=0;i<n;i++){
    //     int data;
    //     cin>>data;
    //     v.push_back(data);
    // }
    // for(int i=0;i<10;i++){
    //     v.push_back(7);
    // }
    // print(v);
    // v.pop_back();
    // print(v);
    // v.clear();
    // v.push_back(100);
    // print(v);


    vector<int> v2(5,-1);
    v2.push_back(7);
    print(v2);

    vector<int> v3 = {1,2,3,4,5};
    v3.pop_back();
    print(v3);

    vector<int> v4(v3);
    print(v4);

    cout<<v4.front()<<endl;
    cout<<v4.back()<<endl;
}