#include<iostream>
#include<bits/stdc++.h>
using namespace std;



class Node{
    public:
    // array of nodes for storing letters
    Node* links[26];
    // when the word is finished we set this flag to true so that we know the word ends here
    bool flag=false;
    // checks if the word is already present or not
    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    // adds the letter to the correct position if not present
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    //  returns the letter and reference ahead
    Node* get(char ch){
     return links[ch-'a'];
    }
    void setEnd(){
        flag=true;
    }
    bool isEnd(){
        return flag;
    }

};

class Trie {
    private:
    Node* root;
 public:
   Trie(){
    // intitially this is where we stand
     root=new Node();
   }

//    inserting a word,O(n)
   void insert(string word){
   Node* temp=root;
   for(int i=0;i<word.length();i++){
    // if the letter doesnt exist in the trie
    if(!temp->containsKey(word[i])){
        // add the letter to the trie
      temp->put(word[i],new Node);
    }
    // move to the reference trie
    temp->get(word[i]);
   }
   temp->setEnd();
   }

//    search a word in trie,O(n)

bool search(string word){
    Node* temp=root;
    for(int i=0;i<word.length();i++){
        if(!temp->containsKey(word[i])){
           return false;
        }
        temp=temp->get(word[i]);
    }
    return temp->isEnd();
}


// check if a word starts with a given string,O(n)
bool startsWith(string prefix){
    Node* temp=root;
    for(int i=0;i<prefix.length();i++){
        if(!temp->containsKey(prefix[i])) return false;
        temp->get(prefix[i]);
    }
    return true;
}

};


int main(){
    return 0;
}