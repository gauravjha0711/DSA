#include<iostream>
#include<queue>
using namespace std;
void firstNonRepeatingChar(string s){
    queue<char> q;
    int freq[26]={0};
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        freq[ch-'a']++;
        q.push(ch);

        while(!q.empty()){
            char frontChar = q.front();
            if(freq[frontChar-'a']>1){
                q.pop();
            }
            else{
                cout<<frontChar<<"->";
                break;
            }
        }
        if(q.empty()){
            cout<<"#->";
        }
    }
}
int main(){
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    firstNonRepeatingChar(s);
    return 0;
}