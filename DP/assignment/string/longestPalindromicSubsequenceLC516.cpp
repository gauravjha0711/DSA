#include<bits/stdc++.h>
using namespace std;
int solveSopt(string a,string b){
    vector<int> cur(b.size()+1,0);
    vector<int> next(b.size()+1,0);
    for(int i=a.length()-1;i>=0;i--){
        for(int j=b.length()-1;j>=0;j--){
            int ans = 0;
            if(a[i]==b[j]){
                ans = 1+next[j+1];
            }
            else{
                ans = 0+max(cur[j+1],next[j]);
            }
            cur[j]=ans;
        }
        next=cur;
    }
    return next[0];
}
int longestPalindromeSubseq(string s) {
    string first =s;
    reverse(s.begin(),s.end());
    string second = s;
    return solveSopt(first,second);
}
int main(){
    string s = "bbbab";
    cout << longestPalindromeSubseq(s) << endl; // Output: 4
    return 0;
}