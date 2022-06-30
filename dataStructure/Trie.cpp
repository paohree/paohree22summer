//트레이를 만들어보자
//트레이는 한글자 한글자 포인터라고 생각하면 될거같음 ㅇㅇ
#include<iostream>
using namespace std;
typedef struct node_node{
    char key;//한글자
    char data[10];//최대 10글자까지 받으니까
    node_node *child[10];//일단 10개 두고 시작
}node;

void makeTrie(char alphabet, node *pointer){
    int check;
    int j;
    int copyPoint;
    for(int i=0;i<10;i++){//이미 알파벳을 가진 노드가 있을 경우
        if(pointer->child[i]!=NULL){
            if(pointer->child[i]->key==alphabet){
                pointer=pointer->child[i];
                cout<<"해당하는 알파벳을 지칭하는 포인터 있음! 퍄퍄\n";
                return;      
            }
        }
        cout<<"해당하는 알파벳을 지칭하는 포인터 없음 ㅇㅇ\n";
    }//여기서 안넘어갔으면 해당 알파벳의 노드가 없다는 소리임
    for(j=0;j<10;j++){
        if(pointer->child[j]==NULL){
            check=j;
            break;
        }
    }
    node *new_node=new node;
    new_node->key=alphabet;
    for(int i=0;i<10;i++){
        new_node->data[i]=pointer->data[i];
        if(pointer->data[i]=='\0'){
            copyPoint=i;
            break;
        }
    }
    new_node->data[copyPoint]=alphabet;
    new_node->data[copyPoint+1]='\0';
    pointer->child[j]=new_node;

}

int main(void){
    node *head, *set,*child;
    head=new node;//항상 맨 위에서 가만히 있을 포인터
    set=new node;//설정할때 찾을때 이리저리 굴릴 포인터
    child=new node;
    char space[10]={0};//일단 최대 알파벳 열개로 하자고
    int wantToPrint;
    int length;
    int i=0;
    while(1){
        cout<<"단어를 입력하세요.\n취소하려면 1을 입력하세요.\n";
        cin>>space;
        if(space[0]=='1'){
            cout<<"정지합니다";
            break;
        }else{
            for(int i=0;i<10;i++){
                if(space[i]=='\0'){
                    length=i-1;
                    break;
                }
            }
            child->key=space[0];
            head->child[0]=child;
            set=head;
            for(int i=0;i<length;i++){
                makeTrie(space[i],set);
            }
            cout<<"완료했습니다.\n";
        }
    }
}