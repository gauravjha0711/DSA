#include<iostream>
using namespace std;
bool checkPallindrome(char ch[], int n){
    int i=0;
    int j=n-1;
    while(i<=j){
        if(ch[i]==ch[j]){
            i++;
            j--;
        }
        else{
            return false;
        }
    }
    return true;
}
void getCapital(char ch[]){
    int i=0;
    while(ch[i]!='\0'){
        if(ch[i]>='a' && ch[i]<='z'){
            ch[i] = ch[i]-'a'+'A';
        }
        i++;
    }
}
int getLen(char ch[]){
    int index = 0;
    while(ch[index] != '\0'){
        index++;
    }
    return index;
}
int main(){
    char ch[100];
    cout<<"Enter string: ";
    cin.getline(ch,100);
    cout<<ch<<endl;
    int len = getLen(ch);
    cout<<"Length: "<<len<<endl;
    getCapital(ch);
    cout<<"After: \n";
    cout<<ch<<endl;
    bool valid = checkPallindrome(ch,len);
    if(valid){
        cout<<"Valid Pallimdrome"<<endl;
    }
    else{
        cout<<"Invalid Pallindrome"<<endl;
    }
}