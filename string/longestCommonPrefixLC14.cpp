#include<bits/stdc++.h>
using namespace std;
string longestCommonPrefix(vector<string>& strs) {
    string ans = "";
    for(int i=0;i<strs[0].length();i++){
        char ch = strs[0][i];
        bool match = true;
        for(int j=1;j<strs.size();j++){
            if(strs[j].size()<i || ch != strs[j][i]){
                match = false;
                break;
            }
        }
        if(match==false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}
int main(){
    vector<string> strs = {"flower","flow","flight"};
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}