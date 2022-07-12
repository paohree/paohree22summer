//abcd
#include<iostream>
using namespace std;
class node{
    private:
    int data;
    int color;//black 0 red 1
    node *parent;
    node *left, *right;
    public:
    node(int number, int colour){
        data=number;
        color=colour;
    }
    ~node(){
        delete this;
    }
    void setData(int number){
        data=number;
    }
    void setColor(int colour){
        color=colour;
    }
    void getData(){
        cout<<data<<"\n";
    }
    void getColor(){
        cout<<color<<"\n";
    }
    void setParent(node *something){
        parent=something;
    }
    void setLeft(node *something){
        left=something;
    }
    void setRight(node *something){
        right=something;
    }
    node* insertion(node *head, node *newOne){

    }
    node* deletion(node *head, node *target){

    }
    void inorderPrint(node *head){//이거는 일단 된거같음
        if(head!=NULL){
            inorderPrint(head->left);
            head->getData();
            inorderPrint(head->right);
        }
    }
    void find(node *head, node* target){

    }
};