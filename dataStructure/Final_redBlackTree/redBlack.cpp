//오늘 날짜는 10월 31일 이번주 안으로 끝내는게 목표
//삽입, 회전, 삭제 내맘대로 할거임 하는데까지는 해보자고
#include<iostream>
using namespace std;
class Node{
    public:
    Node* parent;
    Node* rightNode;
    Node* leftNode;
    int number;
    int color;//0은 블랙 1은 레드
    Node(int wantNumber, int wantColor){
        number=wantNumber;
        color=wantColor;
    }
    Node(){

    }
};
Node *insert(Node *tree, Node *inserted){

}
Node *reconstructing(Node *tree){

}
Node *recoloring(Node *tree){

}

Node *deleteNode(Node *tree, Node *deleted){

}
void print(Node *tree){
    int want=0;
    cout<<"어떤 방법으로 출력하시겠습니까?\n1. inorder\n2. levelorder\n3. preorder\n.4. postorder\n";
    cin>>want;
    if(want==1){

    }else if(want==2){

    }else if(want==3){

    }else if(want==4){

    }else{
        cout<<"다시 입력하세요.\n";
    }

}