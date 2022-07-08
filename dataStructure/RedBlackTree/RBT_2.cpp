#include<iostream>
using namespace std;
class node{
    public:
    int number;
    int color;//0은 black, 1은 red
    node *left, *right;
};
node *restructing(node *grandGrand,node *head, node *child, node* grand, node* parent, node* uncle){//삼촌있는버전
    grand->left=NULL;
    grand->right=NULL;
    parent->left=NULL;
    parent->right=NULL;
    grand->left=NULL;
    grand->right=NULL;
    if(grand->number>parent->number){
        if(parent->number>child->number){//             그랜드 패런트 차일드
            if(grand==head){
                head=parent;
            }
            if(grand==grandGrand->left){
                grandGrand->left=parent;
            }else if(grand==grandGrand->right){
                grandGrand->right=parent;
            }
            parent->left=child;
            parent->right=grand;
            parent->color=0;
            parent->left->color=1;
            parent->right->color=1;
            parent->right->right=uncle;
            return grandGrand;
            
        }else{
            if(grand->number>child->number){//          그랜트 차일드 패런트
                if(grand==head){
                    head=child;
                }
                if(grand==grandGrand->left){
                    grandGrand->left=child;
                }else if(grand==grandGrand->right){
                    grandGrand->right=child;
                }
                child->left=parent;
                child->right=grand;
                child->color=0;
                child->left->color=1;
                child->right->color=1;
                child->right->right=uncle;
                return grandGrand;
            }else{//                                    차일드 그랜드 패런트
                grand->left=parent;
                grand->right=child;
                grand->color=0;
                grand->left->color=1;
                grand->right->color=1;
                grand->right->right=uncle;
                return grandGrand;
            }
        }
    }else{
        if(grand->number>child->number){//          패런트 그랜드 차일드
                grand->left=child;
                grand->right=parent;
                grand->color=0;
                grand->left->color=1;
                grand->right->color=1;
                grand->right->right=uncle;
                return grandGrand;
        }else{
            if(parent->number>child->number){//     패런트 차일드 그랜드
                if(grand==head){
                    head=child;
                }
                if(grand==grandGrand->left){
                    grandGrand->left=child;
                }else if(grand==grandGrand->right){
                    grandGrand->right=child;
                }
                child->left=grand;
                child->right=parent;
                child->color=0;
                child->left->color=1;
                child->right->color=1;
                child->right->right=uncle;
                return grandGrand;
            }else{//                                차일드 패런트 그랜드
                if(grand==head){
                    head=parent;
                }
                if(grand==grandGrand->left){
                    grandGrand->left=parent;
                }else if(grand==grandGrand->right){
                    grandGrand->right=parent;
                }
                parent->left=grand;
                parent->right=child;
                parent->color=0;
                parent->left->color=1;
                parent->right->color=1;
                parent->right->right=uncle;
                return grandGrand;
            }
        }   
    }

}
node *restructing(node *grandGrand,node *head, node *child, node* grand, node* parent){//삼촌없는버전
    grand->left=NULL;
    grand->right=NULL;
    parent->left=NULL;
    parent->right=NULL;
    grand->left=NULL;
    grand->right=NULL;
    if(grand->number>parent->number){
        if(parent->number>child->number){//             그랜드 패런트 차일드
            if(grand==head){
                head=parent;
            }
            if(grand==grandGrand->left){
                grandGrand->left=parent;
            }else if(grand==grandGrand->right){
                grandGrand->right=parent;
            }
            parent->left=child;
            parent->right=grand;
            parent->color=0;
            parent->left->color=1;
            parent->right->color=1;
            return grandGrand;
        }else{
            if(grand->number>child->number){//          그랜트 차일드 패런트
                if(grand==head){
                    head=child;
                }
                if(grand==grandGrand->left){
                    grandGrand->left=child;
                }else if(grand==grandGrand->right){
                    grandGrand->right=child;
                }
                cout<<"여기 맞지?\n";
                child->left=parent;
                child->right=grand;
                child->color=0;
                child->left->color=1;
                child->right->color=1;
                return grandGrand;
            }else{//                                    차일드 그랜드 패런트
                grand->left=parent;
                grand->right=child;
                grand->color=0;
                grand->left->color=1;
                grand->right->color=1;
                return grandGrand;
            }
        }
    }else{
        if(grand->number>child->number){//          패런트 그랜드 차일드
                grand->left=child;
                grand->right=parent;
                grand->color=0;
                grand->left->color=1;
                grand->right->color=1;
                return grandGrand;
        }else{
            if(parent->number>child->number){//     패런트 차일드 그랜드
                if(grand==head){
                    head=child;
                }
                if(grand==grandGrand->left){
                    grandGrand->left=child;
                }else if(grand==grandGrand->right){
                    grandGrand->right=child;
                }
                child->left=grand;
                child->right=parent;
                child->color=0;
                child->left->color=1;
                child->right->color=1;
                return grandGrand;
            }else{//                                차일드 패런트 그랜드
                if(grand==head){
                    head=parent;
                }
                if(grand==grandGrand->left){
                    grandGrand->left=parent;
                }else if(grand==grandGrand->right){
                    grandGrand->right=parent;
                }
                parent->left=grand;
                parent->right=child;
                parent->color=0;
                parent->left->color=1;
                parent->right->color=1;
                return grandGrand;
            }
        }   
    }
}
void recoloring(node *head, node *child, node* grand, node* parent, node* uncle){
    grand->color=1;
    child->color=1;
    parent->color=0;
    uncle->color=0;
    if(grand==head){
        grand->color=0;
    }
}
void traversal(node *pointer){
    if(pointer!=NULL){
        traversal(pointer->left);
        cout<<"숫자는 "<<pointer->number;
        if(pointer->color==0){
            cout<<" 색깔은 black\n";
        }else{
            cout<<" 색깔은 red\n";
        }
        traversal(pointer->right);
    }
}
int main(void){
    int number;
    node *nodes=NULL;
    node *head=NULL;
    node *child=NULL, *parent=NULL;
    node *grand=NULL, *uncle=NULL;
    node *grandGrand=NULL;
    int check=0;
    while(1){
        cout<<"숫자를 입력하셈 (나가려면 -11) (전체 조회는 -1)\n";
        cin>>number;
        if(number==-11){
            cout<<"장비를 정지합니다.\n";
            break;
        }else if(number==-1){
            if(head==NULL){
                cout<<"아무것도 없어요\n";
            }else{
                traversal(head);
            }
        }
        else{
            nodes=new node;
            if(check==0){//첫번째 노드니까 부모노드 자식노드 다 0번째껄로 설정
                head=nodes;
                head->number=number;
                head->color=0;
                grandGrand=uncle=grand=child=parent=head;
                check++;
            }else{
                while(1){
                    child=nodes;
                    child->color=1;
                    child->number=number;
                    if(child->number>parent->number&&parent->right==NULL){
                        parent->right=child;


                        if(parent->color==child->color){
                            if(uncle==NULL){
                                cout<<"restrucing임(no삼촌)\n";
                                grandGrand=restructing(grandGrand,head, child,grand,parent);
                            }else{
                                if(uncle->color==0){
                                    cout<<"restrucing임(yes삼촌)\n";
                                    grandGrand=restructing(head, child,grand,parent,uncle);
                                }else if(uncle->color==1){
                                    cout<<"recoloring임\n";
                                    recoloring(head, child,grand,parent,uncle);
                                }
                            }
                        }


                        break;
                    }else if(child->number>parent->number&&parent->right!=NULL){
                        grandGrand=grand;
                        grand=parent;
                        if(parent->left!=NULL){
                            uncle=parent->left;
                        }else{
                            uncle=NULL;
                        }
                        parent=parent->right;
                    }else if(child->number<parent->number&&parent->left==NULL){
                        parent->left=child;


                        if(parent->color==child->color){
                            if(uncle==NULL){
                                cout<<"restrucing임(no삼촌)\n";
                                grandGrand=restructing(grandGrand,head, child,grand,parent);
                            }else{
                                if(uncle->color==0){
                                    cout<<"restrucing임(yes삼촌)\n";
                                    grandGrand=restructing(head, child,grand,parent,uncle);
                                }else if(uncle->color==1){
                                    cout<<"recoloring임\n";
                                    recoloring(head, child,grand,parent,uncle);
                                }
                            }
                        }


                        break;
                    }else if(child->number<parent->number&&parent->left!=NULL){
                        grandGrand=grand;
                        grand=parent;
                        if(parent->right!=NULL){
                            uncle=parent->right;
                        }else{
                            uncle=NULL;
                        }
                        parent=parent->left;
                    }else if(child->number==parent->number){
                        cout<<"같은 것은 불가합니다\n";
                        break;
                    }
                }
            }
            uncle=grand=parent=head;//초기화
        }
    }
}