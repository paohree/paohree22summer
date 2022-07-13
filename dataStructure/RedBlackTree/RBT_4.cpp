//abcd누가이기나 해보자고
#include<iostream>
using namespace std;
class node{
    private:
    int data;
    int color;//black 0 red 1
    public:
    node *parent;
    node *left, *right;
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
    int getData(){
        return data;
    }
    int getColor(){
        return color;
    }
    /* //이거를 이렇게까지 해야할까?
    void setParent(node *over, node *under){
        over=under->parent;
    }
    void setLeft(node *over, node *under){
        over->left=under;
    }
    void setRight(node *over, node *under){
        over->right=under;
    }
    */
    void insertion(node *head, node *newOne){
        //일단 자리에 넣고 부모랑 색깔이 같을 경우에 수정하는 걸로 가자고
        //일단 자리에 넣음->부모랑 더블 레드다?->삼촌 색 확인->
        //recoloring 혹인 restructing->중간꺼랑 그 부모랑 색 비교->
        //또 같으면 다시 실행
        //while로 묶어도 될듯?

        //색깔 미리 정해놓고 콜하도록 하자 생성시 무조건 빨강색

        node *find=head;
        node *uncle=NULL;
        node *parent=NULL;
        node *grand=NULL;
        node *kid=NULL;
        if(head==NULL){
            newOne->color=0;
            head=newOne;
        }else{
    //1. 일단 자리 배치
            if(find->data>newOne->data&&find->left==NULL){
                find->left=newOne;
                newOne->parent=find;
            }else if(find->data>newOne->data&&find->left!=NULL){
                find=find->left;
            }else if(find->data<newOne->data&&find->right==NULL){
                find->right=newOne;
                newOne->parent=find;
            }else if(find->data<newOne->data&&find->right!=NULL){
                find=find->right;
            }else{
                cout<<"같은거 넣으면 안됨 ㅇㅇ\n";
            }
    //배치끝!
    //2. 더블레드 확인
    //2.1. 배치
    //newNode위치 이용해야할거같음
    //삼촌이 없다면 검정색이 있는 것으로 간주한다
            while(1){
                if(newOne->color==1&&newOne->parent->color==1){
                    kid=newOne;
                    parent=newOne->parent;
                    if(parent->parent!=NULL){
                        grand=parent->parent;
                        if(parent==grand->left&&grand->right!=NULL){
                        //삼촌있다
                            uncle=grand->right;
                        }else if(parent==grand->left&&grand->right==NULL){
                        //삼촌없다
                            uncle=NULL;
                        }else if(parent==grand->right&&grand->left!=NULL){
                        //삼촌있다
                            uncle=grand->left;
                        }else if(parent==grand->right&&grand->left==NULL){
                        //삼촌없다
                            uncle=NULL;
                        }else{
                            cout<<"이게 나오면 안됨. 근데 보기좋으라고 일단 채워놓음.\n";
                        }
                    }//그랜드 삼촌 부모 자식 노드 배치 끝난거지 여기까지 하면
    //2.2. recoloring 인지 restructing인지 판단
    //0이 검정임
                if(uncle==NULL||uncle!=NULL&&uncle->color==0){
                    //여기는 restructing임
                    if(uncle!=NULL){

                    }else{

                    }
                }else if(uncle!=NULL&&uncle->color==1){
                    //여기는 recoloring임

                }else{
                    cout<<"이 경우는 나올 수 없음. 보기좋으라고 채워놓음.\n";
                }
            }else{
                if(newOne->parent!=NULL){
                    newOne=newOne->parent;//부모로 넘김 ㅇㅇ
                }else{
                    break;//parent가 null이면 head라는 소리지 그럼 break 할거임
                }
            }
        }
        }
    }
    void deletion(node *head, node *something){
        //일단 위치 찾아야하는거아님?
        int numberBig;
        int numberSmall;
        node* target=NULL;
        node* smallNumber;
        node* bigNumber;
        target=find(head,something);
        if(target!=NULL){
            if(target->left==NULL&&target->right==NULL){//무자식
                if(target->parent->left==target){
                    target->parent->left=NULL;
                    delete target;
                }else if(target->parent->right=target){
                    target->parent->right=NULL;
                    delete target;
                }
            }else if(target->right!=NULL&&target->left==NULL){//오른자식
                if(target->parent->left==target){
                    target->parent->left=target->right;
                    delete target;
                }else if(target->parent->right=target){
                    target->parent->right=target->right;
                    delete target;
                }
            }else if(target->right==NULL&&target->left!=NULL){//왼자식
                if(target->parent->left==target){
                    target->parent->left=target->left;
                    delete target;
                }else if(target->parent->right=target){
                    target->parent->right=target->left;
                    delete target;
                }
            }else{//둘자식 오른쪽에서 제일 작은거 또는 왼쪽에서 제일 큰거를 삭제당하는 애 자리로
                smallNumber=target;//작은거중에 제일 큰거
                if(smallNumber->left!=NULL){
                    smallNumber=smallNumber->left;
                    numberSmall++;
                    while(smallNumber->right!=NULL){
                        smallNumber=smallNumber->right;
                        numberSmall++;
                    }
                }
                bigNumber=target;//큰거중에 제일 작은거
                if(bigNumber->right!=NULL){
                    bigNumber=bigNumber->right;
                    numberBig++;
                    while(bigNumber->left!=NULL){
                        bigNumber=bigNumber->left;
                        numberBig++;
                    }
                }
                if(numberBig>numberSmall){//왼쪽에서 제일 큰게 더 깊게 있는거임
                    if(target->parent->left==target){
                        target->parent->left=bigNumber;
                        bigNumber->parent->left=NULL;
                        bigNumber->left=target->left;
                        bigNumber->right=target->right;
                        delete target;
                    }else if(target->parent->right=target){
                        target->parent->right=bigNumber;
                        bigNumber->parent->left=NULL;
                        bigNumber->left=target->left;
                        bigNumber->right=target->right;
                        delete target;
                    }
                }else if(numberBig<=numberSmall){//오른쪽에서 제일 큰게 더 깊게 있는거임
                    if(target->parent->left==target){
                        target->parent->left=smallNumber;
                        smallNumber->parent->right=NULL;
                        smallNumber->left=target->left;
                        smallNumber->right=target->right;
                        delete target;
                    }else if(target->parent->right=target){
                        target->parent->right=smallNumber;
                        smallNumber->parent->right=NULL;
                        smallNumber->left=target->left;
                        smallNumber->right=target->right;
                        delete target;
                    }
                }
            }
        }else{
            cout<<"그런거없음\n";
        }
    }
    void inorderPrint(node *head){//이거는 일단 된거같음
        if(head!=NULL){
            inorderPrint(head->left);
            cout<<head->getData()<<"\n";
            inorderPrint(head->right);
        }
    }
    node* find(node *head, node* target){//이러면 되지 않을까? 이거 포인터 반환임
        if(head!=NULL){
            if(head->getData()==target->getData()){
                //cout<<head->getData()<<"\n";
                return head;
            }else{
                find(head->left, target);
                find(head->right, target);
            }
        }
    }
    void restructing(node *grand, node *parent, node *kid, node* uncle){
        
    }
    void restructing(node *grand, node *parent, node *kid){

    }
    void recoloring(node *grand, node *parent, node *uncle, node *kid){

    }
};