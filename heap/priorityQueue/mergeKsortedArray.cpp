#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class info{
    public:
    int data;
    int row, col;
    info(int d, int r, int c){
        data = d;
        row = r;
        col = c;
    }
};
class compare{
    public:
    bool operator()(info* a, info* b){
        return a->data > b->data;
    }
};
vector<int> mergeKsortedArray(vector<vector<int>> arr){
    vector<int> ans;
    priority_queue<info*, vector<info*>, compare> pq;
    int row = arr.size();
    int col = arr[0].size();
    for(int i=0;i<row;i++){
        info* temp = new info(arr[i][0],i,0);
        pq.push(temp);
    }
    while(!pq.empty()){
        info* top = pq.top();
        pq.pop();
        int element = top->data;
        int r = top->row;
        int c = top->col;
        ans.push_back(element);
        if(c+1<col){
            info* temp = new info(arr[r][c+1],r,c+1);
            pq.push(temp);
        }
    }
    return ans;
}
int main(){
    vector<vector<int>> arr = {{2,6,12,15},{1,3,14,20},{3,5,8,10}};
    vector<int> ans = mergeKsortedArray(arr);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}