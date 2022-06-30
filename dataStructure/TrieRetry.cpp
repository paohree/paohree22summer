#include<iostream>
using namespace std;
class node{
    public:
    char key;
    string data;
    int numberOfChild;
    node *child[26];
};
void MatchTrie(node *pointer, string word){
    if(pointer->data==word){
        cout<<"해당 단어는 존재합니다. \n";
    }else{
    }
}
    node *MakeTrie(node *pointer,char alphabet){
        int i=0;
        while(pointer->child[i]!=NULL){
            if(pointer->child[i]->key==alphabet){
                cout<<"해당하는 알파벳 있음. \n";
                pointer=pointer->child[i];
                return pointer;
            }else{
                i++;
            }
        }
        cout<<"해당하는 알파벳 없음.\n";
        node *newChild=new node;
        newChild->key=alphabet;
        newChild->data=pointer->data+alphabet;
        cout<<newChild->key<<" "<<newChild->data<<"\n";
        for(i=0;;i++){
            if(pointer->child[i]==NULL){
                pointer->child[i]=newChild;
                pointer=pointer->child[i];
                return pointer;
            }else{
                continue;
            }
        }
    }
int main(void){
    node *head=new node;
    node *set=new node;
    string word;
    while(1){
        cout<<"단어를 입력하세요.\n";
        cin>>word;
        int length=word.length();
        set=head;
        for(int i=0;i<length;i++){
            set=MakeTrie(set,word.at(i));
            MatchTrie(set,word);
        }
    }
}