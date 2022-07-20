

//코드 폐기함

#include<iostream>
#include<queue>
using namespace std;
class node{
    private:
    int data;
    int color;//black 0 red 1
    public:
    node *parent;
    node *left, *right;
    node(){
        int number;
        cout<<"숫자를 입력하세요\n";
        cin>>number;
        //cout<<"test\n";
        setData(number);
        //cout<<"test\n";
        setColor(1);
        //cout<<"test\n";
        parent=NULL;
        left=NULL;
        right=NULL;
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
    node* insertion(node *head, node *newOne){
        //일단 자리에 넣고 부모랑 색깔이 같을 경우에 수정하는 걸로 가자고
        //일단 자리에 넣음->부모랑 더블 레드다?->삼촌 색 확인->
        //recoloring 혹인 restructing->중간꺼랑 그 부모랑 색 비교->
        //또 같으면 다시 실행
        //while로 묶어도 될듯?

        //색깔 미리 정해놓고 콜하도록 하자 생성시 무조건 빨강색

        //cout<<"test\n";

        int check=0;

        node *find=head;
        node *uncle=NULL;
        node *parent=NULL;
        node *grand=NULL;
        node *kid=NULL;
        //cout<<"test\n";
        if(head==NULL){
            cout<<"test\n";
            newOne->setColor(0);
            head=newOne;
            return head;
        }else{
    //1. 일단 자리 배치
            while(1){
                if(find->data>newOne->data&&find->left==NULL){
                    find->left=newOne;
                    newOne->parent=find;
                    break;
                }else if(find->data>newOne->data&&find->left!=NULL){
                   find=find->left;
                }else if(find->data<newOne->data&&find->right==NULL){
                    find->right=newOne;
                    newOne->parent=find;
                    break;
                }else if(find->data<newOne->data&&find->right!=NULL){
                    find=find->right;
                }else{
                    cout<<"같은거 넣으면 안됨 ㅇㅇ\n";
                    return head;
                }
            }
    //배치끝!
    //2. 더블레드 확인
    //2.1. 배치
    //newNode위치 이용해야할거같음
    //삼촌이 없다면 검정색이 있는 것으로 간주한다
    //이거 하고보니까 삼촌 확인할 필요가 없노
    //확인은 해야하는데 역시 함수 따로 짤 필요가 없음 ㅋㅋㅋㅋ
            while(1){
                if(newOne->getColor()==1&&newOne->parent->getColor()==1){//더블레드라면
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
                    }   //그랜드 삼촌 부모 자식 노드 배치 끝난거지 여기까지 하면
                            //2.2. recoloring 인지 restructing인지 판단
                            //0이 검정임
                    if(uncle==NULL||uncle!=NULL&&uncle->getColor()==0){
                            //여기는 restructing임
                        if(uncle!=NULL){
                            if(grand==head){
                                cout<<"여기까지 와서 삼촌있 재건축 조상이 헤드\n";
                                grand=restructing(grand, parent, kid,uncle);
                                head=grand;
                            }else{
                                cout<<"여기까지 와서 삼촌있 재건축 조상 노 헤드\n";
                                grand=restructing(grand, parent, kid,uncle);
                            }
                        }else{
                            if(grand==head){
                                cout<<"여기까지 와서 삼촌없 재건축 조상 헤드\n";
                                grand=restructing(grand, parent, kid);
                                head=grand;
                            }else{
                                cout<<"여기까지 와서 삼촌없 재건축 조상 노 헤드\n";
                                grand=restructing(grand, parent, kid);
                                inorderPrint(head);
                            }
                        }
                    }else if(uncle!=NULL&&uncle->getColor()==1){
                            //여기는 recoloring임
                        cout<<"리컬러링 ㅇㅇ\n";
                        recoloring(grand, parent, uncle, kid);
                        if(grand==head){
                            cout<<"리컬러링 했는데 조상이 헤드라 검정칠해줌\n";
                            grand->color=0;
                        }
                    }else{
                        cout<<"이 경우는 나올 수 없음. 보기좋으라고 채워놓음.\n";
                    }
                }else{//더블 레드가 아니라면
                    if(newOne->parent==NULL){
                        cout<<"헤드와서 리턴";
                        return head;//parent가 null이면 head라는 소리지 그럼 return 할거임
                    }else{
                        cout<<"부모로 넘김\n";
                        newOne=newOne->parent;//부모로 넘김 ㅇㅇ
                        check++;
                        cout<<newOne->getColor()<<" "<<newOne->getData()<<"\n";
                        if(check>10){
                            return head;
                        }
                    }
                }
            }
        }
    }
    queue<node*> q;
    void inorderPrint(node *head){//이거는 일단 된거같음 블로그보고함
        if(head!=NULL){
            q.push(head);
        }
        while(q.empty()==false){
            node *nodes = q.front();
            cout<<nodes->data<<" "<<nodes->getColor()<<"   ";
            q.pop();
            if(nodes->left!=NULL){
                q.push(nodes->left);
            }
            if(nodes->right!=NULL){
                q.push(nodes->right);
            }
        }
        // if(head!=NULL){
        //     inorderPrint(head->left);
        //     cout<<head->getData()<<" ";
        //     if(head->getColor()==1){
        //         cout<<"RED\n";
        //     }else{
        //         cout<<"BLACK\n";
        //     }
        //     inorderPrint(head->right);
        //}
    }
    node* find(node *head, int target){//이러면 되지 않을까? 이거 포인터 반환임
        while(head!=NULL){
            cout<<"find에 있음\n";
            if(head->getData()==target){
                return head;
            }else if(head->getData()<target){
                head=head->right;
            }else{
                head=head->left;
            }
        }
        return NULL;
    }
    node* restructing(node *grand, node *parent, node *kid, node* uncle){
        node *backup=NULL;
        int index;
        cout<<"와드\n";
        if(grand->parent!=NULL){//조상의 부모 노드 있으면 저장해놓음
            if(grand->parent->left==grand){
                backup=grand->parent;
                index=0;//0이면 left
            }else if(grand->parent->right==grand){
                backup=grand->parent;
                index=1;//0이면 right
            }
            cout<<"이게 지금 백업 내용임. ";
            cout<<backup->getColor()<<" "<<backup->getData()<<"\n";
        }

        //일단 관계 다 끊음 조상의 부모 포인터는 저장해뒀으니까 마지막에 붙여주면 됨
        //수정//
        //관계 다 끊으면 안됨 그래서 안됬던거임 ㅇㅇ
        //cout<<"와드\n";
        //grand->parent=NULL;
        //if(uncle==grand->left){
        //    grand->right=NULL;
        //}else if(uncle==grand->right){
        //    grand->left=NULL;
        //}
        //if(grand->right==parent){
        //    grand->right==NULL;
        //}
        //parent->parent=NULL;
        //parent->right=NULL;
        //if(parent->left!=NULL){

        //}
        //parent->left=NULL;
        //kid->parent=NULL;
        //kid->right=NULL;
        //kid->left=NULL;




        cout<<"패런트 "<<parent->data<<" 키드 "<<kid->data<<" 그랜드 "<<grand->data<<"\n";
        //관계 정리했으니까 이제 순서대로 세우고 다시 연결해주면 됨
        //사실 grand는 중간에 갈 수 없음 그 경우 나오면 안됨
        if(grand->data>parent->data){
            if(parent->data>kid->data){//작은순대로 kid parent grand 이건 있을수있음

                if(parent->right!=NULL){
                    grand->left=parent->right;
                    parent->right=NULL;
                }else{
                    grand->left=NULL;
                }
                parent->parent=NULL;

                parent->left=kid;
                parent->right=grand;
                parent->setColor(0);
                kid->parent=parent;
                kid->setColor(1);
                grand->parent=parent;
                grand->setColor(1);
                if(backup!=NULL){
                    if(index==0){
                        backup->left=parent;
                        parent->parent=backup;
                    }else{
                        backup->right=parent;
                        parent->parent=backup;
                    }
                }
                return parent;
            }else{
                if(grand->data>kid->data){//parent kid grand //이것도 있을수있음

                    if(kid->right!=NULL){
                        grand->left=kid->right;
                        kid->right=NULL;
                    }else{
                        grand->left=NULL;
                    }
                    if(kid->left!=NULL){
                        parent->right=kid->left;
                        kid->left=NULL;
                    }else{
                        parent->right=NULL;
                    }
                    kid->parent=NULL;
                    cout<<"패런트 키드 그랜드 순임\n";
                    kid->left=parent;
                    kid->right=grand;
                    kid->setColor(0);
                    parent->parent=kid;
                    parent->setColor(1);
                    grand->parent=kid;
                    grand->setColor(1);
                    if(backup!=NULL){
                        if(index==0){
                            backup->left=kid;
                            kid->parent=backup;
                        }else{
                            backup->right=kid;
                            kid->parent=backup;
                        }
                    }
                    //cout<<"여기까지 오냐?\n";
                    return kid;
                }else{//parent grand kid //이건 나올수 없음
                    grand->left=parent;
                    grand->right=kid;
                    grand->setColor(0);
                    parent->parent=grand;
                    parent->setColor(1);
                    kid->parent=grand;
                    kid->setColor(1);
                    if(backup!=NULL){
                        if(index==0){
                            backup->left=grand;
                            grand->parent=backup;
                        }else{
                            backup->right=grand;
                            grand->parent=backup;
                        }
                    }
                    return grand;
                }
            }
        }else{
            if(parent->data<kid->data){//grand parent kid 있을수있음
                cout<<"야 4885 밥은먹고다니냐?\n";

                if(parent->left!=NULL){
                    grand->right=parent->left;
                    parent->left=NULL;
                }else{
                    grand->right=NULL;
                }
                parent->parent=NULL;

                parent->left=grand;
                parent->right=kid;
                parent->setColor(0);
                grand->parent=parent;
                grand->setColor(1);
                kid->parent=parent;
                kid->setColor(1);
                if(backup!=NULL){
                    if(index==0){
                        backup->left=parent;
                        parent->parent=backup;
                    }else{
                        backup->right=parent;
                        parent->parent=backup;
                    }
                }
                return parent;
            }else{
                if(kid->data>grand->data){//grand kid parent 있을수있음

                    if(kid->right!=NULL){
                        parent->left=kid->right;
                        kid->right=NULL;
                    }else{
                        parent->left=NULL;
                    }
                    if(kid->left!=NULL){
                        grand->right=kid->left;
                        kid->left=NULL;
                    }else{
                        grand->right=NULL;
                    }
                    kid->parent=NULL;

                    kid->left=grand;
                    kid->right=parent;
                    kid->setColor(0);
                    grand->parent=kid;
                    grand->setColor(1);
                    parent->parent=kid;
                    parent->setColor(1);
                    if(backup!=NULL){
                        if(index==0){
                            backup->left=kid;
                            kid->parent=backup;
                        }else{
                            backup->right=kid;
                            kid->parent=backup;
                        }
                    }
                    return kid;
                }else{//kid grand parent 있을수없음
                    grand->left=kid;
                    grand->right=parent;
                    grand->setColor(0);
                    kid->parent=grand;
                    kid->setColor(1);
                    parent->parent=grand;
                    parent->setColor(1);
                    if(backup!=NULL){
                        if(index==0){
                            backup->left=grand;
                            grand->parent=backup;
                        }else{
                            backup->right=grand;
                            grand->parent=backup;
                        }
                    }
                    return grand;
                }
            }
        }
    }
    node* restructing(node *grand, node *parent, node *kid){
        node *backup=NULL;
        int index;
        cout<<"와드\n";
        if(grand->parent!=NULL){//조상의 부모 노드 있으면 저장해놓음
            if(grand->parent->left==grand){
                backup=grand->parent;
                index=0;//0이면 left
            }else if(grand->parent->right==grand){
                backup=grand->parent;
                index=1;//0이면 right
            }
            cout<<"이게 지금 백업 내용임. ";
            cout<<backup->getColor()<<" "<<backup->getData()<<"\n";
        }

        //일단 관계 다 끊음 조상의 부모 포인터는 저장해뒀으니까 마지막에 붙여주면 됨
        //수정//
        //관계 다 끊으면 안됨 그래서 안됬던거임 ㅇㅇ
        //cout<<"와드\n";
        //grand->parent=NULL;
        //if(uncle==grand->left){
        //    grand->right=NULL;
        //}else if(uncle==grand->right){
        //    grand->left=NULL;
        //}
        //if(grand->right==parent){
        //    grand->right==NULL;
        //}
        //parent->parent=NULL;
        //parent->right=NULL;
        //if(parent->left!=NULL){

        //}
        //parent->left=NULL;
        //kid->parent=NULL;
        //kid->right=NULL;
        //kid->left=NULL;




        cout<<"패런트 "<<parent->data<<" 키드 "<<kid->data<<" 그랜드 "<<grand->data<<"\n";
        //관계 정리했으니까 이제 순서대로 세우고 다시 연결해주면 됨
        //사실 grand는 중간에 갈 수 없음 그 경우 나오면 안됨
        if(grand->data>parent->data){
            if(parent->data>kid->data){//작은순대로 kid parent grand 이건 있을수있음

                if(parent->right!=NULL){
                    grand->left=parent->right;
                    parent->right=NULL;
                }else{
                    grand->left=NULL;
                }
                parent->parent=NULL;

                parent->left=kid;
                parent->right=grand;
                parent->setColor(0);
                kid->parent=parent;
                kid->setColor(1);
                grand->parent=parent;
                grand->setColor(1);
                if(backup!=NULL){
                    if(index==0){
                        backup->left=parent;
                        parent->parent=backup;
                    }else{
                        backup->right=parent;
                        parent->parent=backup;
                    }
                }
                return parent;
            }else{
                if(grand->data>kid->data){//parent kid grand //이것도 있을수있음

                    if(kid->right!=NULL){
                        grand->left=kid->right;
                        kid->right=NULL;
                    }else{
                        grand->left=NULL;
                    }
                    if(kid->left!=NULL){
                        parent->right=kid->left;
                        kid->left=NULL;
                    }else{
                        parent->right=NULL;
                    }
                    kid->parent=NULL;
                    cout<<"패런트 키드 그랜드 순임\n";
                    kid->left=parent;
                    kid->right=grand;
                    kid->setColor(0);
                    parent->parent=kid;
                    parent->setColor(1);
                    grand->parent=kid;
                    grand->setColor(1);
                    if(backup!=NULL){
                        if(index==0){
                            backup->left=kid;
                            kid->parent=backup;
                        }else{
                            backup->right=kid;
                            kid->parent=backup;
                        }
                    }
                    //cout<<"여기까지 오냐?\n";
                    return kid;
                }else{//parent grand kid //이건 나올수 없음
                    grand->left=parent;
                    grand->right=kid;
                    grand->setColor(0);
                    parent->parent=grand;
                    parent->setColor(1);
                    kid->parent=grand;
                    kid->setColor(1);
                    if(backup!=NULL){
                        if(index==0){
                            backup->left=grand;
                            grand->parent=backup;
                        }else{
                            backup->right=grand;
                            grand->parent=backup;
                        }
                    }
                    return grand;
                }
            }
        }else{
            if(parent->data<kid->data){//grand parent kid 있을수있음
                cout<<"야 4885 밥은먹고다니냐?\n";

                if(parent->left!=NULL){
                    grand->right=parent->left;
                    parent->left=NULL;
                }else{
                    grand->right=NULL;
                }
                parent->parent=NULL;

                parent->left=grand;
                parent->right=kid;
                parent->setColor(0);
                grand->parent=parent;
                grand->setColor(1);
                kid->parent=parent;
                kid->setColor(1);
                if(backup!=NULL){
                    if(index==0){
                        backup->left=parent;
                        parent->parent=backup;
                    }else{
                        backup->right=parent;
                        parent->parent=backup;
                    }
                }
                return parent;
            }else{
                if(kid->data>grand->data){//grand kid parent 있을수있음

                    if(kid->right!=NULL){
                        parent->left=kid->right;
                        kid->right=NULL;
                    }else{
                        parent->left=NULL;
                    }
                    if(kid->left!=NULL){
                        grand->right=kid->left;
                        kid->left=NULL;
                    }else{
                        grand->right=NULL;
                    }
                    kid->parent=NULL;

                    kid->left=grand;
                    kid->right=parent;
                    kid->setColor(0);
                    grand->parent=kid;
                    grand->setColor(1);
                    parent->parent=kid;
                    parent->setColor(1);
                    if(backup!=NULL){
                        if(index==0){
                            backup->left=kid;
                            kid->parent=backup;
                        }else{
                            backup->right=kid;
                            kid->parent=backup;
                        }
                    }
                    return kid;
                }else{//kid grand parent 있을수없음
                     grand->left=kid;
                     grand->right=parent;
                     grand->setColor(0);
                     kid->parent=grand;
                     kid->setColor(1);
                     parent->parent=grand;
                     parent->setColor(1);
                     if(backup!=NULL){
                         if(index==0){
                             backup->left=grand;
                             grand->parent=backup;
                         }else{
                             backup->right=grand;
                             grand->parent=backup;
                         }
                     }
                     return grand;
                }
            }
        }
    } 
    void recoloring(node *grand, node *parent, node *uncle, node *kid){
        grand->color=1;
        kid->color=1;
        uncle->color=0;
        parent->color=0;
    }
    node* leftRotation(node *grand, node *left, node *right, node *rightleft){
        grand->parent=right;
        right->left=grand;
        if(rightleft!=NULL){
            rightleft->parent=grand;
            grand->right=rightleft;
        }
        return grand;        
    }
    node* rightRotation(node *grand, node *left, node*right, node*leftright){
        grand->parent=left;
        left->right=grand;
        if(leftright!=NULL){
            grand->left=leftright;
            leftright->parent=grand;
        }
        return left;
    }
void doubleBlack(node* child, node* parent)
{
	while (nullptr != parent)
	{
		bool left = parent->left == child;
		node* sibling = left ? parent->right : parent->left;
		if (1 == parent->getColor())
		{
			if (0 == sibling->left->getColor() && 0 == sibling->right->getColor())
			{
				// case 1
				// parent : red, sibling : black, sibling left : black, sibling right : black
				sibling->setColor(1);
				parent->setColor(0);
				break; 
			}
		}
		else if(0 == sibling->left->getColor() && 0 == sibling->right->getColor())
		{
			if (0 == sibling->getColor())
			{
				// case 4
				// parent : black, sibling : black, sibling left : black, sibling right : black
				sibling->setColor(1);
				child = parent;
				parent = parent->parent;
				continue; 
			}
			else // RED == sibling->_color
			{
				// case 5
				// parent : black, sibling : red, sibling left : black, sibling right : black
				parent->setColor(1);
				sibling->setColor(0);
				if (left)
				{
                    if(parent->right!=NULL&&parent->right->left!=NULL){
					    leftRotation(parent,parent->left,parent->right,parent->right->left);
                    }else{
                        leftRotation(parent, parent->left,parent->right,NULL);
                    }
					sibling = parent->right;
				}
				else
				{
                    if(parent->left!=NULL&&parent->left->right!=NULL){
                        rightRotation(parent,parent->left,parent->right,parent->left->right);
                    }else{
                        rightRotation(parent,parent->left,parent->right,NULL);
                    }
					sibling = parent->left;
				}
				continue;
			}
		}

		if (0 == sibling->getColor() &&
			((left && 1 == sibling->left->getColor() && 0 == sibling->right->getColor())
				|| (!left && 0 == sibling->left->getColor() && 1 == sibling->right->getColor())))
		{
			// case 3
			// parent : all, sibling : black, sibling left : red, sibling right : black
			if (left)
			{
                if(sibling->right!=NULL&&sibling->right->left!=NULL){
                    rightRotation(sibling, sibling->left,sibling->right,sibling->left->right);
                }else{
                    rightRotation(sibling, sibling->left,sibling->right,NULL);
                }
				parent->right->setColor(0);
				parent->right->right->setColor(1);
				sibling = parent->right;
			}
			else
			{
                if(sibling->right!=NULL&&parent->right->left!=NULL){
                    leftRotation(sibling, sibling->left,sibling->right,sibling->right->left);
                }else{
                    leftRotation(sibling, sibling->left, sibling->right, NULL);
                }
				parent->left->setColor(0);
				parent->left->left->setColor(1);
				sibling=parent->left;
			}
		}
		
		if (0 == sibling->getColor() && ((left && 1 == sibling->right->getColor()) || (!left && 1 == sibling->left->getColor())))
		{
			// case 2
			// parent : all, sibling : black, sibling left : all, sibling right : red
			left ? leftRotation(parent,parent->left,parent->right,parent->right->left) :rightRotation(parent,parent->left,parent->right,parent->left->right);
			int temp = parent->getColor();
			parent->setColor(sibling->getColor());
			sibling->setColor(temp);
			left ? sibling->right->setColor(0) : sibling->left->setColor(0);
			break; 
		}
	}
}
    void deletion(node *head, int something){
        //일단 위치 찾아야하는거아님?
        int numberBig=0;
        int numberSmall=0;
        int check=0;
        int index=0;//대체자와 대체자의 자녀가 모두 블랙일 경우 함수호출을 위한 표식
        node* target=NULL;
        node* smallNumber=NULL;
        node* bigNumber=NULL;
        node* checkPoint=NULL;
        node *uncle=NULL;
        node *parent=NULL;
        node *grand=NULL;
        node *kid=NULL;
        cout<<"딜리션 시작 find 시작\n";
        target=find(head,something);
        cout<<"find 끝났다\n";
        //헤드삭제 고려 안한거같은데?????
        if(target!=NULL){
            // if(target->getColor()==0){
            //     index=0;
            // }else if(target->getColor()==1){
            //     index=1;
            // }else{
            //     cout<<"이 경우는 나올 수 없음.\n";
            // }
            if(target->left==NULL&&target->right==NULL){//무자식
                if(target->parent->left==target){
                    target->parent->left=NULL;
                    checkPoint=target->parent;
                    index=1;
                    delete target;
                    doubleBlack(NULL,checkPoint);
                }else if(target->parent->right==target){
                    target->parent->right=NULL;
                    checkPoint=target->parent;
                    index=1;
                    delete target;
                    doubleBlack(NULL,checkPoint);
                }
            }else if(target->right!=NULL&&target->left==NULL){//오른자식
                if(target->parent->left==target){
                    target->parent->left=target->right;
                    target->right->parent=target->parent;
                    checkPoint=target->right;
                    if(checkPoint->getColor()==0&&
                    (
                        (checkPoint->left!=NULL&&checkPoint->left->getColor()==0)||
                        (checkPoint->right!=NULL&&checkPoint->right->getColor()==0)||
                        checkPoint->left==NULL||
                        checkPoint->right==NULL
                    )
                    ){
                        index=1;
                    }
                    checkPoint->setColor(target->getColor());
                    // if(checkPoint->getColor()==0){
                    //     index=0;
                    // }else if(checkPoint->getColor()==1){
                    //     index=1;
                    // }else{
                    //     cout<<"이 경우는 나올 수 없음.\n";
                    // }
                    delete target;
                    if(index==1){
                        doubleBlack(checkPoint,checkPoint->parent);
                    }
                }else if(target->parent->right==target){
                    //cout<<"이 문장이 나와야 함\n";
                    //cout<<"내가 문제다 1\n";
                    target->parent->right=target->right;
                    //cout<<"내가 문제다 2\n";
                    target->right->parent=target->parent;
                    //cout<<"내가 문제다 3\n";
                    checkPoint=target->right;
                    checkPoint->setColor(target->getColor());
                    if(checkPoint->getColor()==0&&
                    (
                        (checkPoint->left!=NULL&&checkPoint->left->getColor()==0)||
                        (checkPoint->right!=NULL&&checkPoint->right->getColor()==0)||
                        checkPoint->left==NULL||
                        checkPoint->right==NULL
                    )
                    ){
                        index=1;
                    }
                    // if(checkPoint->getColor()==0){
                    //     index=0;
                    // }else if(checkPoint->getColor()==1){
                    //     index=1;
                    // }else{
                    //     cout<<"이 경우는 나올 수 없음.\n";
                    // }
                    delete target;
                    if(index==1){
                        doubleBlack(checkPoint,checkPoint->parent);
                     }
                    //cout<<"내가 문제다 4\n";
                }
            }else if(target->right==NULL&&target->left!=NULL){//왼자식
                if(target->parent->left==target){
                    target->parent->left=target->left;
                    target->left->parent=target->parent;
                    checkPoint=target->left;
                    if(checkPoint->getColor()==0&&
                    (
                        (checkPoint->left!=NULL&&checkPoint->left->getColor()==0)||
                        (checkPoint->right!=NULL&&checkPoint->right->getColor()==0)||
                        checkPoint->left==NULL||
                        checkPoint->right==NULL
                    )
                    ){
                        index=1;
                    }
                    checkPoint->setColor(target->getColor());
                    // if(checkPoint->getColor()==0){
                    //     index=0;
                    // }else if(checkPoint->getColor()==1){
                    //     index=1;
                    // }else{
                    //     cout<<"이 경우는 나올 수 없음.\n";
                    // }
                    delete target;
                    if(index==1){
                        doubleBlack(checkPoint,checkPoint->parent);
                    }
                }else if(target->parent->right==target){
                    target->parent->right=target->left;
                    target->left->parent=target->parent;
                    checkPoint=target->left;
                    if(checkPoint->getColor()==0&&
                    (
                        (checkPoint->left!=NULL&&checkPoint->left->getColor()==0)||
                        (checkPoint->right!=NULL&&checkPoint->right->getColor()==0)||
                        checkPoint->left==NULL||
                        checkPoint->right==NULL
                    )
                    ){
                        index=1;
                    }
                    checkPoint->setColor(target->getColor());
                    // if(checkPoint->getColor()==0){
                    //     index=0;
                    // }else if(checkPoint->getColor()==1){
                    //     index=1;
                    // }else{
                    //     cout<<"이 경우는 나올 수 없음.\n";
                    // }
                    delete target;
                    if(index==1){
                        doubleBlack(checkPoint,checkPoint->parent);
                    }
                }
            }else{//둘자식 오른쪽에서 제일 작은거 또는 왼쪽에서 제일 큰거를 삭제당하는 애 자리로
                //cout<<"어디까지 왔나 와드\n";
                smallNumber=target;//왼쪽에서 제일 큰거
                if(smallNumber->left!=NULL){//그래도 타겟보다 작으니까 스몰넘버임
                    smallNumber=smallNumber->left;
                    numberSmall++;
                    while(smallNumber->right!=NULL){
                        smallNumber=smallNumber->right;
                        numberSmall++;
                    }
                    cout<<smallNumber->getData()<<" "<<smallNumber->getColor()<<" "<<"작은거중에 제일큰거 구함\n";
                    cout<<"numberSmall은 "<<numberSmall<<"임\n";
                }
                // bigNumber=target;//오른쪽에서 제일 작은거
                // if(bigNumber->right!=NULL){//그래도 타겟보다 크므로 빅넘버임
                //     bigNumber=bigNumber->right;
                //     numberBig++;
                //     while(bigNumber->left!=NULL){
                //         bigNumber=bigNumber->left;
                //         numberBig++;
                //     }
                //     cout<<bigNumber->getData()<<" "<<bigNumber->getColor()<<" "<<"큰거중에 제일 작은거 구함\n";
                //     cout<<"numberBig은 "<<numberBig<<"임\n";
                // }//여기까지는 돌아가는데 문제가 없음 

                // //if(numberBig>=numberSmall){//오른쪽에서 제일 작은게 더 깊게 있는거임 혹은 같은거임
                //     checkPoint=bigNumber;
                //     // if(checkPoint->getColor()==0){
                //     //     index=0;
                //     // }else if(checkPoint->getColor()==1){
                //     //     index=1;
                //     // }else{
                //     //     cout<<"이 경우는 나올 수 없음.\n";
                //     // }
                //     cout<<"자식이 두갠데 움직이는 노드는 "<<bigNumber->getData()<<"에 "<<bigNumber->getColor()<<"색임\n";
                //     if(target->parent->left==target){//1
                //         if(numberBig==1){
                //             bigNumber->left=target->left;
                //             target->left->parent=bigNumber;
                //             bigNumber->parent=target->parent;
                //             target->parent->left=bigNumber;       
                //             delete target;
                //         }else{
                //             bigNumber->parent->left=NULL;
                //             bigNumber->parent=target->parent;
                //             target->parent->left=bigNumber;
                //             bigNumber->left=target->left;
                //             target->left->parent=bigNumber;
                //             bigNumber->right=target->right;
                //             target->right->parent=bigNumber;
                //             delete target;
                //         }
                //     }else if(target->parent->right==target){//2
                //         if(numberBig==1){
                //             bigNumber->left=target->left;
                //             target->left->parent=bigNumber;
                //             bigNumber->parent=target->parent;
                //             target->parent->right=bigNumber;
                //             //cout<<"타겟자리 차지하는 노드는 "<<bigNumber->getData()<<"에 "<<bigNumber->getColor()<<"색임\n";
                //             delete target;
                //         }else{
                //             bigNumber->parent->left=NULL;
                //             bigNumber->parent=target->parent;
                //             target->parent->right=bigNumber;
                //             bigNumber->left=target->left;
                //             target->left->parent=bigNumber;
                //             bigNumber->right=target->right;
                //             target->right->parent=bigNumber;
                //             delete target;
                //             //cout<<"어디까지 왔나 와드\n";
                //         }
                //     }else{
                //         cout<<"나올수없는경우임\n";
                //     }
                //}
                 //else 
                 if(numberBig<numberSmall){//왼쪽에서 제일 큰게 더 깊게있는거임
                     checkPoint=smallNumber;
                    //  if(checkPoint->getColor()==0){
                    //      index=0;
                    //  }else if(checkPoint->getColor()==1){
                    //      index=1;
                    //  }else{
                    //      cout<<"이 경우는 나올 수 없음.\n";
                    //  }
                     //cout<<"자식이 두갠데 움직이는 노드는 "<<bigNumber->getData()<<"에 "<<bigNumber->getColor()<<"색임\n";
                     if(target->parent->left==target){//3
                         if(numberSmall==1){
                             smallNumber->right=target->right;
                             target->right->parent=smallNumber;
                             target->parent->left=smallNumber;
                             smallNumber->parent=target->parent;
                    if(checkPoint->getColor()==0&&
                    (
                        (checkPoint->left!=NULL&&checkPoint->left->getColor()==0)||
                        (checkPoint->right!=NULL&&checkPoint->right->getColor()==0)||
                        checkPoint->left==NULL||
                        checkPoint->right==NULL
                    )
                    ){
                        index=1;
                    }
                             checkPoint->setColor(target->getColor());
                             delete target;
                            if(index==1){
                                doubleBlack(checkPoint,checkPoint->parent);
                             }
                             //cout<<"어디까지 왔나 와드\n";
                         }else{
                             smallNumber->parent->right=NULL;
                             smallNumber->parent=target->parent;
                             smallNumber->left=target->left;
                             target->left->parent=smallNumber;
                             smallNumber->right=target->right;
                             target->right->parent=smallNumber;
                             target->parent->left=smallNumber;
                            if(checkPoint->getColor()==0&&
                            (
                                (checkPoint->left!=NULL&&checkPoint->left->getColor()==0)||
                                (checkPoint->right!=NULL&&checkPoint->right->getColor()==0)||
                                checkPoint->left==NULL||
                                checkPoint->right==NULL
                            )
                            ){
                                index=1;
                            }
                             checkPoint->setColor(target->getColor());
                             delete target;
                            if(index==1){
                                doubleBlack(checkPoint,checkPoint->parent);
                             }
                             //cout<<"어디까지 왔나 와드\n";
                         }
                     }else if(target->parent->right==target){//4
                         if(numberSmall==1){
                             smallNumber->parent=target->parent;
                            target->parent->right=smallNumber;
                             smallNumber->right=target->right;
                             target->right->parent=smallNumber;
                            if(checkPoint->getColor()==0&&
                            (
                                (checkPoint->left!=NULL&&checkPoint->left->getColor()==0)||
                                (checkPoint->right!=NULL&&checkPoint->right->getColor()==0)||
                                checkPoint->left==NULL||
                                checkPoint->right==NULL
                            )
                            ){
                                index=1;
                            }
                             checkPoint->setColor(target->getColor());
                             delete target;
                            if(index==1){
                                doubleBlack(checkPoint,checkPoint->parent);
                             }
                             //cout<<"어디까지 왔나 와드\n";
                         }else{
                             smallNumber->parent->right=NULL;
                             smallNumber->parent=target->parent;
                             target->parent->right=smallNumber;
                             smallNumber->left=target->left;
                             smallNumber->right=target->right;
                             target->right->parent=smallNumber;
                             target->left->parent=smallNumber;
                            if(checkPoint->getColor()==0&&
                            (
                                (checkPoint->left!=NULL&&checkPoint->left->getColor()==0)||
                               (checkPoint->right!=NULL&&checkPoint->right->getColor()==0)||
                                checkPoint->left==NULL||
                                checkPoint->right==NULL
                            )
                            ){
                                index=1;
                            }
                             checkPoint->setColor(target->getColor());
                             delete target;
                             if(index==1){
                                doubleBlack(checkPoint,checkPoint->parent);
                             }
                             //cout<<"어디까지 왔나 와드\n";
                         }
                     }else{
                    cout<<"나올수없는경우임\n";
                    }
                }
                else{
                    cout<<"나올 수 없는 경우임 이거 나오면 안됨\n";
                }
            }


                //여기서 더블레드 확인하면 됨. 아니면 제일큰거 제일작은거 있는 그 부분 가서 코드 두개 따로 만들어도 됨.
                //index를따로 주는것도 괜찮을듯? small이면 1, big이면 0 이런식으로 줘가지고
                //인덱스 따로 주는게 코드 한번만 짜도 되겠다
            



                // while(checkPoint!=NULL){
            //     if(index==0){//움직인 노드의 색이 검정임
            //         cout<<"움직인 노드의 색깔이 검정입니다. 경우의 수를 확인합니다. \n";
            //         // if(checkPoint->parent->left==checkPoint){
            //         //     if(checkPoint->parent->right!=NULL&&checkPoint->parent->right->getColor()==1){
            //         //         cout<<"경우의 수 1 형제가 red\n";
            //         //         break;
            //         //     }else if((checkPoint->parent->right!=NULL&&checkPoint->parent->right->getColor()==0)&&
            //         //             ((checkPoint->parent->right->left!=NULL&&checkPoint->parent->right->left->getColor()==0)||
            //         //             checkPoint->parent->right->left==NULL)&&
            //         //             ((checkPoint->parent->right->right!=NULL&&checkPoint->parent->right->right->getColor()==0)||
            //         //             checkPoint->parent->right->right==NULL)
            //         //             ){
            //         //         cout<<"경우의 수 2 형제가 블랙 형제 자식도 블랙\n";
            //         //         break;
            //         //     }else if((checkPoint->parent->right!=NULL&&checkPoint->parent->right->getColor()==0)&&
            //         //             (checkPoint->parent->right->left!=NULL&&checkPoint->parent->right->left->getColor()==1)&&
            //         //             ((checkPoint->parent->right->right!=NULL&&checkPoint->parent->right->right->getColor()==0)||
            //         //             checkPoint->parent->right->right==NULL)
            //         //             ){
            //         //         cout<<"경우의 수 3 형제가 블랙 형제 자식 왼쪽 블랙 오른쪽 레드\n";
            //         //         break;
            //         //     }else if((checkPoint->parent->right!=NULL&&checkPoint->parent->right->getColor()==0)&&
            //         //             (checkPoint->parent->right->right!=NULL&&checkPoint->parent->right->right->getColor()==1)
            //         //             ){
            //         //         cout<<"경우의 수 4 형제가 블랙 형제 자식 오른쪽 레드\n";
            //         //         break;
            //         //     }
            //         // }else if(checkPoint->parent->right==checkPoint){
            //         //     if(checkPoint->parent->left!=NULL&&checkPoint->parent->left->getColor()==1){
            //         //         cout<<"경우의 수 1 형제가 red\n";
            //         //     }else if((checkPoint->parent->left!=NULL&&checkPoint->parent->left->getColor()==0)&&
            //         //             ((checkPoint->parent->left->left!=NULL&&checkPoint->parent->left->left->getColor()==0)||
            //         //             checkPoint->parent->left->left==NULL)&&
            //         //             ((checkPoint->parent->left->right!=NULL&&checkPoint->parent->left->right->getColor()==0)||
            //         //             checkPoint->parent->left->right==NULL)
            //         //             ){
            //         //         cout<<"경우의 수 2 형제가 블랙 형제 자식도 블랙\n";
            //         //         break;
            //         //     }else if((checkPoint->parent->left!=NULL&&checkPoint->parent->left->getColor()==0)&&
            //         //             (checkPoint->parent->left->left!=NULL&&checkPoint->parent->left->left->getColor()==1)&&
            //         //             ((checkPoint->parent->left->right!=NULL&&checkPoint->parent->left->right->getColor()==0)||
            //         //             checkPoint->parent->left->right==NULL)
            //         //             ){
            //         //         cout<<"경우의 수 3 형제가 블랙 형제 자식 왼쪽 레드 오른쪽 블랙\n";
            //         //         break;
            //         //     }else if((checkPoint->parent->left!=NULL&&checkPoint->parent->left->getColor()==0)&&
            //         //             (checkPoint->parent->left->right!=NULL&&checkPoint->parent->left->right->getColor()==1)
            //         //             ){
            //         //         cout<<"경우의 수 4 형제가 블랙 형제 자식 오른쪽 레드\n";
            //         //         break;
            //         //     }
            //         // }
            //         else{
            //             cout<<"나올수없는경우임\n";
            //         }
            //     }else if(index==1){//움직인 노드의 색이 빨강임
            //         cout<<"움직인 노드의 색깔이 빨강입니다. 검정을 칠해줍니다. \n";
            //         checkPoint->setColor(0);
            //         break;
            //     }else if(index==2){//가져오는 노드가 없음(자식없는노드삭제)(걍 검정색 가져오는건데 따로 뽑아서 만들거임)
            //         cout<<"자식이 없는 상황임. 부모 노드를 가져왔음. \n";
            //         break;
            //     }
            // }
            // if(index==1){//bigNumber가 타겟의 자리를 차지한 경우
            //     if(bigNumber->getColor()==1){//빅넘버의 색이 빨강일 때
            //         bigNumber->setColor(0);
            //     }else if(bigNumber->getColor()==0){//빅넘버의 색이 검정일 때
            //         cout<<"이제 여기를 만들어보자 1\n";
            //     }else{
            //         cout<<"나올수 없는 경우임";
            //     }
            // }else if(index==0){//smallNumber가 타겟의 자리를 차지한 경우
            //     if(smallNumber->getColor()==1){//스몰넘버의 색이 빨강일때
            //         smallNumber->setColor(0);
            //     }else if(smallNumber->getColor()==0){//스몰넘버의 색이 검정일 때
            //         cout<<"이제 여기를 만들어보자 2\n";
            //     }else{
            //         cout<<"나올수 없는 경우임";
            //     }
            // }else if(index==2){//자식이 한개라서 대체노드가 그냥 올라왔는데
            //     if(checkPoint->getColor()==1){//대체노드 색이 빨강일때
            //         checkPoint->setColor(0);
            //     }else if(checkPoint->getColor()==0){//대체노드 색이 검정일때
            //         cout<<"이제 여기를 만들어보자 3\n";
            //     }else{
            //         cout<<"나올수 없는 경우임";
            //     }
            // }else{
            //     cout<<"나오면 안되는 경우임.\n";
            // }
            // while(1){
            //     if(checkPoint->getColor()==1&&checkPoint->parent->getColor()==1){//더블레드라면
            //         kid=checkPoint;
            //         parent=checkPoint->parent;
            //         if(parent->parent!=NULL){
            //             grand=parent->parent;
            //                if(parent==grand->left&&grand->right!=NULL){
            //             //삼촌있다
            //                 uncle=grand->right;
            //             }else if(parent==grand->left&&grand->right==NULL){
            //                 //삼촌없다
            //                 uncle=NULL;
            //             }else if(parent==grand->right&&grand->left!=NULL){
            //             //삼촌있다
            //                 uncle=grand->left;
            //             }else if(parent==grand->right&&grand->left==NULL){
            //             //삼촌없다
            //                 uncle=NULL;
            //             }else{
            //                 cout<<"이게 나오면 안됨. 근데 보기좋으라고 일단 채워놓음.\n";
            //             }
            //         }   //그랜드 삼촌 부모 자식 노드 배치 끝난거지 여기까지 하면
            //             //2.2. recoloring 인지 restructing인지 판단
            //             //0이 검정임
            //         if(uncle==NULL||uncle!=NULL&&uncle->getColor()==0){
            //             //여기는 restructing임
            //             if(uncle!=NULL){
            //                 if(grand==head){
            //                     cout<<"여기까지 와서 삼촌있 재건축 조상이 헤드\n";
            //                     grand=restructing(grand, parent, kid,uncle);
            //                     head=grand;
            //                 }else{
            //                     cout<<"여기까지 와서 삼촌있 재건축 조상 노 헤드\n";
            //                     grand=restructing(grand, parent, kid,uncle);
            //                 }
            //             }else{
            //                 if(grand==head){
            //                     cout<<"여기까지 와서 삼촌없 재건축 조상 헤드\n";
            //                     grand=restructing(grand, parent, kid);
            //                     head=grand;
            //                 }else{
            //                     cout<<"여기까지 와서 삼촌없 재건축 조상 노 헤드\n";
            //                     grand=restructing(grand, parent, kid);
            //                     inorderPrint(head);
            //                 }
            //             }
            //         }else if(uncle!=NULL&&uncle->getColor()==1){
            //                 //여기는 recoloring임
            //             cout<<"리컬러링 ㅇㅇ\n";
            //             recoloring(grand, parent, uncle, kid);
            //             if(grand==head){
            //                 cout<<"리컬러링 했는데 조상이 헤드라 검정칠해줌\n";
            //                 grand->color=0;
            //             }
            //         }else{
            //             cout<<"이 경우는 나올 수 없음. 보기좋으라고 채워놓음.\n";
            //         }
            //     }else{//더블 레드가 아니라면
            //         if(checkPoint->parent==NULL){
            //             cout<<"헤드와서 리턴";
            //             return;// head;//parent가 null이면 head라는 소리지 그럼 return 할거임
            //         }else{
            //             cout<<"부모로 넘김\n";
            //             checkPoint=checkPoint->parent;//부모로 넘김 ㅇㅇ
            //             check++;
            //             cout<<checkPoint->getColor()<<" "<<checkPoint->getData()<<"\n";
            //             if(check>10){
            //                 return;// head;
            //             }
            //         }
            //     }
            // }
        
        
        }else{
            cout<<"그런거없음\n";
        }
    }
};