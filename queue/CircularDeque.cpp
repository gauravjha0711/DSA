#include<iostream>
using namespace std;
class CircularDeque{
    public:
    int *arr;
    int front;
    int rear;
    int capacity;
    void push_back(int val){
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
    void push_front(int val){
        if((rear==capacity-1 && front==0) || (rear+1==front)){
            cout<<"Queue is full"<<endl;
            return;
        }
        else if(front==-1){
            front = 0;
            rear = 0;
            arr[front] = val;
        }
        else if(front==0 && rear!=capacity-1){
            front = capacity-1;
            arr[front] = val;
        }
        else{
            front--;
            arr[front] = val;
        }
    }
    void pop_back(){
        if(front==-1){
            cout<<"Queue is empty"<<endl;
        }
        else if(front==rear){
            arr[rear] = 0;
            front = -1;
            rear = -1;
        }
        else if(rear==0){
            arr[rear] = 0;
            rear = capacity-1;
        }
        else{
            arr[rear] = 0;
            rear--;
        }
    }
    void pop_front(){
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
    CircularDeque q;
    q.capacity = 5;
    q.arr = new int[q.capacity];
    q.front = -1;
    q.rear = -1;
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.push_front(1);
    q.push_front(2);
    q.push_front(3);
    q.push_front(4);
    q.push_front(5);
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.push_front(1);
    q.push_front(2);
    q.push_front(3);
    q.push_front(4);
    q.push_front(5);
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.push_back(1);
    q.push_back(2);
    q.push_back(3);
    q.push_back(4);
    q.push_back(5);
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.pop_front();
    q.push_front(1);
    q.push_front(2);
    q.push_front(3);
    q.push_front(4);
    q.push_front(5);
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.pop_back();
    q.push_front(1);
}