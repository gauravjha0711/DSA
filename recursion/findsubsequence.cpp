#include<iostream>
#include<vector>
using namespace std;
void findsubsequence(string &str, string output, int index){
    if(index>=str.length()){
        cout<<"-> "<<output<<endl;
        return;
    }
    char ch = str[index];
    findsubsequence(str,output,index+1);
    output.push_back(ch);
    findsubsequence(str,output,index+1);
}
int main(){
    string str = "sbc";
    string output = "";
    int index = 0;
    findsubsequence(str,output,index);
}