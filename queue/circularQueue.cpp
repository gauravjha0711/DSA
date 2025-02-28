#include<iostream>
using namespace std;
class circularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int capacity;
    circularQueue(int n){
        this->arr = new int[n];
        this->front = -1;
        this->rear = -1;
        this->capacity = n;
    }
    void push(int val){
        if((rear==capacity-1 && front==0) || (rear+1==front)){
            cout<<"Queue is full"<<endl;
            return;
        }
        else if(rear==-1){
            front = 0;
            rear = 0;
            arr[rear] = val;
        }
        else if(rear==capacity-1 && front!=0){
            rear = 0;
            arr[rear] = val;
        }
        else{
            rear++;
            arr[rear] = val;
        }
    }
    void pop(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front==rear){
            arr[front] = 0;
            front = -1;
            rear = -1;
        }
        else if(front==capacity-1){
            arr[front] = 0;
            front = 0;
        }
        else{
            arr[front] = 0;
            front++;
        }
    }
    void display(){
        for(int i=0;i<capacity;i++){
            cout<<arr[i]<<" ";
        }
    }
};
int main(){
    circularQueue q(5);
    // q.push(1);
    // q.push(2);
    // q.push(3);
    // q.push(4);
    // q.push(5);
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    // q.pop();
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    // q.push(6);
    q.pop();
    q.push(6);
    q.push(7);
    q.display();
}