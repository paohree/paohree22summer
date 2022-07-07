#include<iostream>
using namespace std;
class node{
    public:
    int data;
    string colour;
    node *left, *right;
};
void inorderPrint(node *nodes){//이거 고쳐야함
    if(nodes){
        inorderPrint(nodes->left);
        cout<<nodes->data<<" "<<nodes->colour<<"\n";
        inorderPrint(nodes->right);
    }
}
node *recolouring(node *grandparent,node*head){
    grandparent->left->colour="black";
    grandparent->right->colour="black";
    grandparent->colour="red";
    if(head==grandparent){
        grandparent->colour="black";
    }
    return grandparent;
}
node *restructing(node *child,node *parent,node *grandparent){
    node *big, *mid, *small;
    if(child->data<parent->data){
        if(parent->data>grandparent->data){
            big=parent;
            if(grandparent->data>child->data){
                mid=grandparent;
                small=child;
            }else{
                mid=child;
                small=grandparent;
            }
        }else{
            big=grandparent;
            mid=parent;
            small=child;
        }
    }else{
        if(parent->data>grandparent->data){
            small=grandparent;
            mid=parent;
            big=child;
        }else{
            if(grandparent->data<child->data){
                big=child;
                mid=grandparent;
                small=parent;
            }else{
                big=grandparent;
                mid=child;
                small=parent;
            }
        }
    }
    grandparent=mid;
    grandparent->colour="black";
    grandparent->left=small;
    grandparent->left->colour="red";
    grandparent->right=big;
    grandparent->left->colour="red";
    return grandparent;
}
int main(void){
    int i=0;
    int number=0;
    node *head, *parent, *grandparent, *child, *uncle, *newNode;
    while(1){
        cout<<"새 노드를 입력합니다. 새로운 노드의 숫자를 입력하세요.(정지: -1, 출력 -2) \n";
        cin>>number;
        if(number==-1){
            cout<<"정지합니다. \n";
            break;
        }else if(number==-2){
            inorderPrint(head);
        }else{

        newNode=new node;
        newNode->data=number;
        if(i==0){
            newNode->colour="black";
            head=newNode;
            parent=head;
            grandparent=head;
            uncle=head;
            i++;
        }else{
            cout<<"test1\n";
            newNode->colour="red";
            child=newNode;
            while(1){
                cout<<"test2\n";
                if(parent->data<child->data){
                    if(parent->right==NULL){
                        parent->right=child;
                        if(parent->colour=="red"&&child->colour=="red"){

                            if(uncle->colour=="red"){
                                cout<<"test3\n";
                                grandparent=recolouring(grandparent, head);
                            }else{
                                cout<<"test4\n";
                                grandparent=restructing(child, parent, grandparent);
                            }

                        }
                        parent=head;
                        break;
                    }else{
                        grandparent=parent;
                        if(parent->left==NULL){
                        }else{
                            uncle=parent->left;
                        }
                        parent=parent->right;
                    }
                }else if(parent->data>child->data){
                    if(parent->left==NULL){
                        parent->left=child;
                        if(parent->colour=="red"&&child->colour=="red"){

                            if(uncle->colour=="red"){
                                cout<<"test5\n";
                                grandparent=recolouring(grandparent, head);
                            }else{
                                cout<<"test6\n";
                                grandparent=restructing(child, parent, grandparent);
                            }

                        }
                        parent=head;
                        break;
                    }else{
                        grandparent=parent;
                        if(parent->right==NULL){
                        }else{
                            uncle=parent->right;
                        }
                        parent=parent->left;
                    }
                }else{
                    cout<<"같은 것을 입력하면 안됩니다. \n";
                    delete newNode;
                    break;
                }
            }
        }

        }
    }
}

//이거 uncle 위치를 못잡고있는거같음
//ㅈㅈ