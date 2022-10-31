#include<iostream>
#include"redBlack.cpp"
using namespace std;
void main(){
    int userWant=0;
    int newNodeNumber=0;
    Node* head=new Node;
    while(1){
        cout<<"숫자를 입력하세요\n";
        cin>>userWant;
        cout<<"###############\n1. tree 조회\n2. node 넣기\n3. node 삭제\n4. 종료\n###############\n";
        if(userWant==1){
            cout<<"새로 넣을 노드의 숫자를 입력하세요.";
            cin>>newNodeNumber;
            Node *newNode=new Node(newNodeNumber,0);
            head=insert(head,newNode);
        }else if(userWant==2){

        }else if(userWant==3){

        }else if(userWant==4){

        }else{
            cout<<"다시 입력하세요.\n";
        }
    }
}