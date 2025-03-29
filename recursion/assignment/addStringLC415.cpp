#include<bits/stdc++.h>
using namespace std;
string solve(string &num1, int p1,string &num2, int p2, int carry=0){
    if(p1<0 && p2<0){
        if(carry!=0){
            return string(1,carry+'0');
        }
        return "";
    }
    int n1 = (p1>=0 ? num1[p1] : '0') - '0';
    int n2 = (p2>=0 ? num2[p2] : '0') - '0';
    int csum = n1+n2+carry;
    int digit = csum%10;
    carry = csum/10;
    string ans = "";
    ans.push_back(digit+'0');
    ans += solve(num1,p1-1,num2,p2-1,carry);
    return ans;
}
string addStrings(string num1, string num2) {
    string ans = solve(num1,num1.size()-1,num2,num2.size()-1);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    string num1 = "123";
    string num2 = "456";
    cout<<addStrings(num1,num2)<<endl;
    return 0;
}