#include<bits/stdc++.h>
using namespace std;
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    queue<pair<string,int>> q;
    unordered_set<string> st(wordList.begin(),wordList.end());
    q.push({beginWord,1});
    st.erase(beginWord);
    while(!q.empty()){
        pair<string,int> fnode = q.front();
        q.pop();
        string curString = fnode.first;
        int curCount = fnode.second;
        if(curString==endWord) return curCount;
        for(int i=0;i<curString.length();i++){
            char original = curString[i];
            for(char ch='a';ch<='z';ch++){
                curString[i]=ch;
                if(st.find(curString)!=st.end()){
                    q.push({curString,curCount+1});
                    st.erase(curString);
                }
            }
            curString[i]=original;
        }
    }
    return 0;
}
int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    int result = ladderLength(beginWord, endWord, wordList);
    cout << "Length of shortest transformation sequence: " << result << endl;
    return 0;
}
//time complexity is O(n*m*26) where n is the number of words and m is the length of each word.
//space complexity is O(n) for the queue and the set.