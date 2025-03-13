#include<iostream>
using namespace std;
class TrieNode{
    public:
    char data;
    TrieNode* children[26];
    bool isTerminal;
    TrieNode(char data){
        this->data = data;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        isTerminal = false;
    }
};
void insertWord(TrieNode* root, string word){
    //Base case
    if(word.length()==0){
        root->isTerminal = true;
        return;
    }
    char ch = word[0];
    int index = ch - 'a';
    TrieNode* child;
    //present
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    //not present
    else{
        child = new TrieNode(ch);
        root->children[index] = child;
    }
    insertWord(child, word.substr(1));
}
bool searchWord(TrieNode* root, string word){
    //Base case
    if(word.length()==0){
        return root->isTerminal;
    }
    char ch = word[0];
    int index = ch-'a';
    TrieNode* child;
    //present
    if(root->children[index] != NULL){
        child = root->children[index];
    }
    //not present
    else{
        return false;
    }
    return searchWord(child, word.substr(1));
}
int main(){
    TrieNode* root = new TrieNode('\0');
    insertWord(root, "apple");
    insertWord(root, "code");
    insertWord(root, "coding");
    insertWord(root, "coder");
    if(searchWord(root, "apple")){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Not Present"<<endl;
    }
}