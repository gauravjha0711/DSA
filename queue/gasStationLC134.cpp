#include <iostream>
#include <vector>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int deficient = 0;
    int balance = 0;
    int start = 0;
    
    for(int i = 0; i < gas.size(); i++) {
        balance += gas[i] - cost[i];
        if (balance < 0) {
            deficient += balance;
            start = i + 1;
            balance = 0;
        }
    }
    
    return (deficient + balance >= 0) ? start : -1;
}

int main() {
    vector<int> gas = {1, 2, 3, 4, 5};
    vector<int> cost = {3, 4, 5, 1, 2};
    
    int result = canCompleteCircuit(gas, cost);
    cout << "Starting gas station index: " << result << endl;
    
    return 0;
}