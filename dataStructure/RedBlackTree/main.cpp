#include<iostream>
#include"RBT_4.cpp"
using namespace std;
int main(void){
    node *head=NULL;
    node *newOne=NULL;
    node *get=NULL;
    int find;
    string userWant;
    while(1){
        cout<<"\n";
        cout<<"1. 새 노드 저장 (new 또는 1 입력)\n"<<"2. 노드 삭제 (delete 또는 2 입력)\n"<<"3. 노드 찾기 (find 또는 3 입력)\n";
        cout<<"4. 전체 노드 출력 (print 또는 4 입력)\n"<<"5. 정지 (stop 또는 5 입력)\n\n"<<"무엇을 원하십니까?\n\n";
        cin>>userWant;
            cout<<"\n";
        if(userWant=="new"||userWant=="1"){
            newOne=new node;
            head=newOne->node::insertion(head,newOne);
        }else if(userWant=="delete"||userWant=="2"){
        }else if(userWant=="print"||userWant=="4"){
            head->node::inorderPrint(head);
        }else if(userWant=="find"||userWant=="3"){
            cout<<"숫자를 입력하세요.\n";
            cin>>find;
            cout<<"\n";
            get=head->node::find(head,find);
            if(get==NULL){
                cout<<"그런거없음\n";
            }else{
                cout<<"색깔은 "<<get->getColor()<<" 데이터는 "<<get->getData()<<"\n";
            }
        }else if(userWant=="stop"||userWant=="5"){
            cout<<"장비를 정지합니다\n";
            break;
        }else{
            cout<<"다시 입력하십시오.\n";
        }
    }
}