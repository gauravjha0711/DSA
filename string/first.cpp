#include<iostream>
using namespace std;
char toLowerCase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char temp = ch - 'A' + 'a';
        return temp;
    }
}
bool checkpallindrome(char a[], int n){
    int s=0,e=n-1;
    while(s<=e){
        if(toLowerCase(a[s])!=toLowerCase(a[e])){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;
}
void reverse(char ch[], int n){
    int s=0,e=n-1;
    while(s<e){
        swap(ch[s++],ch[e--]);
    }
}
int getlength(char ch[]){
    int count=0;
    for(int i=0;ch[i]!='\0';i++){
        count++;
    }
    return count;
}
char getmaxoccur(string s){
    int arr[26] = {0};
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        int num = 0;
        if(ch>='a' && ch<='z'){
            num = ch-'a';
        }
        else{
            num = ch-'A';
        }
        arr[num]++;
    }
    int maxi = -1,ans = 0;
    for(int i=0;i<26;i++){
        if(maxi<arr[i]){
            ans=i;
            maxi = arr[i];
        }
    }
    char temp = ans+'a';
    return temp;
}
int main(){
    // cout<<"Enter name: ";
    // char ch[20];
    // cin>>ch;
    // cout<<"Your name is : "<<ch<<endl;
    // int n = getlength(ch);
    // cout<<"length is: "<<n<<endl;
    // if(checkpallindrome(ch, n)){
    //     cout<<ch<<" is pallindrome"<<endl;
    // }
    // else{
    //     cout<<ch<<" is not a pallindrome\n";
    // }
    // reverse(ch, n );
    // cout<<"After reverse: "<<ch<<endl;
    


    string s;
    cout<<"Enter a string: ";
    cin>>s;
    cout<<getmaxoccur(s)<<" is occur most\n";
}