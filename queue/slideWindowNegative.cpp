#include<iostream>
#include<queue>
using namespace std;

void slideWindowNegative(int arr[],int n, int k ) {
    deque<int> q;
    //process first window of size k 
    for(int i=0; i<k; i++) {
            if(arr[i] < 0) {
                    q.push_back(i);
            }
    }

    //remaining window ko process kro
    for(int i=k; i<n; i++) {
            //answer dedo purani wondow ka 
            if(q.empty()) {
                    cout << 0 << " ";
            }
            else {
                    cout << arr[q.front()] << " ";
            }

            //out of window elements ko remove krdo
            while((!q.empty()) && (i - q.front() >= k)) {
                    q.pop_front();
            }

            //check current element for insertion 
            if(arr[i] < 0 ) 
                    q.push_back(i);

    }

    //answer print karonfor last window
   if(q.empty()) {
            cout << 0 << " ";
    }
    else {
            cout << arr[q.front()] << " ";
    }


}
void print(int arr[],int n) {
        for(int i=0; i<n; i++) {
                cout << arr[i] << " ";
        }
}
int main(){
        int n;
        cout << "Enter the size of array : ";
        cin >> n;
        int arr[n];
        cout << "Enter the elements of array : ";
        for(int i=0; i<n; i++) {
                cin >> arr[i];
        }
        int k;
        cout << "Enter the value of k : ";
        cin >> k;
        slideWindowNegative(arr,n,k);
        print(arr,n);
}