#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    
    for (int i = n - 1; i >= 0; i--) {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr) {
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    st.push(-1);
    
    for (int i = 0; i < n; i++) {
        int curr = arr[i];
        while (st.top() != -1 && arr[st.top()] >= curr) {
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> next = nextSmallerElement(heights);
    vector<int> prev = prevSmallerElement(heights);
    
    // If next smaller element is -1, it means no smaller element on the right, so set to n
    for (int i = 0; i < n; i++) {
        if (next[i] == -1) {
            next[i] = n;
        }
    }

    int maxArea = 0;
    for (int i = 0; i < n; i++) {
        int width = next[i] - prev[i] - 1;
        int area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    int n;
    cout << "Enter the number of histogram bars: ";
    cin >> n;
    
    vector<int> heights(n);
    cout << "Enter the heights of the histogram bars: ";
    for (int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int maxRectangle = largestRectangleArea(heights);
    cout << "The largest rectangle area in the histogram is: " << maxRectangle << endl;
    
    return 0;
}