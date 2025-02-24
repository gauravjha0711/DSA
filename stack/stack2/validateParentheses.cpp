#include <iostream>
#include <stack>
using namespace std;


bool isValid(string s) {
        stack<char> st;
        for(int i=0; i<s.length(); i++){
            char ch = s[i];

            // Push opening brackets to stack
            if(ch == '(' || ch == '{' || ch == '['){
                st.push(ch);
            }
            else{
                // If stack is empty, there's no opening bracket to match
                if(st.empty()) return false;

                // Check for matching pairs
                if((ch == ')' && st.top() == '(') ||
                   (ch == '}' && st.top() == '{') ||
                   (ch == ']' && st.top() == '[')){
                    st.pop();
                }
                else{
                    return false;  // Mismatched brackets
                }
            }
        }

        // If stack is empty, all brackets are properly matched
        return st.empty();
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << (isValid(s) ? "Valid" : "Invalid") << endl;

    return 0;
}