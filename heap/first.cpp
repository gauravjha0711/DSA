#include<iostream>
using namespace std;
class Heap{
    public:
    int arr[50]={-1};
    int size;
    Heap(){
        size=0;
    }
    void insert(int val){
        size++;
        int index=size;
        arr[index]=val;
        while(index>1){
            int parentIndex = index/2;
            if(arr[index]>arr[parentIndex]){
                swap(arr[index],arr[parentIndex]);
                index=parentIndex;
            }
            else{
                break;
            }
        }
    }
    int deletion(){
        int ans=arr[1];
        arr[1]=arr[size];
        arr[size]=-1;
        size--;
        int index=1;
        int left=2*index;
        int right = 2*index+1;
        while(index<=size){
            int maxIndex=index;
            if(left<=size && arr[left]>arr[maxIndex]){
                maxIndex=left;
            }
            if(right<=size && arr[right]>arr[maxIndex]){
                maxIndex=right;
            }
            if(maxIndex==index){
                break;
            }
            swap(arr[index],arr[maxIndex]);
            index=maxIndex;
        }
        return ans;
    }
    void print(){
        for(int i=0;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(30);
    h.insert(40);
    h.insert(50);
    h.insert(60);
    h.insert(70);
    h.print();
    cout<<h.deletion()<<endl;
    cout<<"After deletion"<<endl;
    h.print();
}