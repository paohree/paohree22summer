#include<iostream>
#include<stdio.h>
#include<fstream>
#include<cstring>
#include<queue>
#define green "\033[32m"
#define normal "\033[0m"
//using namespace std;
class node{
    public:
    char key;
    std::string data;
    int searchNumber;
    node *child[27];//띄어쓰기까지 하면 27개임
};
struct box{
    int searchNumber;
    std::string data;
    box(int number, std::string datas){
        searchNumber=number;
        data=datas;
    }
    bool operator<(const box b) const{
        return this->searchNumber<b.searchNumber;
    }
};
std::priority_queue<box>pq;
void inorder (node *pointer){
    if (pointer){
        //cout << pointer->data<<" "<<pointer->searchNumber<<"\n";
        for(int i=0;pointer->child[i]!=NULL;i++){
            inorder(pointer->child[i]);
        }
    }
}
char big[100];
void findWord(node *pointer, char wantuser[]){
    if (pointer){
        strcpy(big,pointer->data.c_str());
        if(strstr(big,wantuser)!=NULL&&pointer->searchNumber!=0){
            pq.push(box(pointer->searchNumber, pointer->data));
            //cout << pointer->data<<" "<<pointer->searchNumber<<"\n";
        }
        for(int i=0;pointer->child[i]!=NULL;i++){
            findWord(pointer->child[i],wantuser);
        }
    }
}

void setSearchNumber(node *pointer, std::string word,int searchNumber){
    if(pointer->data==word){
        pointer->searchNumber=searchNumber;
        //cout<<"다음과 같이 검색횟수가 설정됨\n";
        //cout<<pointer->key<<" "<<pointer->data<<" "<<pointer->searchNumber<<"\n";
    }
}
node *MakeTrie(node *pointer,char alphabet){
    int i=0;
    while(pointer->child[i]!=NULL){
        if(pointer->child[i]->key==alphabet){
            pointer=pointer->child[i];
            //cout<<"여기는 타고 들어간거임."<<pointer->key<<" "<<pointer->data<<"\n";
            return pointer;
        }else{
            i++;
        }
   }
    node *newChild=new node;
    newChild->key=alphabet;
    newChild->data=pointer->data+alphabet;
    newChild->searchNumber=0;
    //cout<<"이거는 새로 만들어지는거임"<<newChild->key<<" "<<newChild->data<<" "<<newChild->searchNumber<<"\n";
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
    std::string sentence;
    std::string dummy;
    int searchNumber;
    std::ifstream file;
    int space;
    file.open("data.txt");
    if(file.is_open()){//데이터구조 만들고 검색횟수까지 넣어줌 ㅇㅇ
        while(std::getline(file,sentence,'\t')){
            file>>searchNumber;
            set=head;
            //cout<<sentence<<"\n";
            space=sentence.length();
            //cout<<space<<"\n";
            int j=0;
            //cout<<searchNumber<<"\n";
            for(int i=0;i<space;i++){
                set=MakeTrie(set,sentence.at(i));
                setSearchNumber(set,sentence,searchNumber);
            }
            getline(file,dummy);
        }
        file.close();//ㅇㅋ 확인함 퍄퍄!
    }
    //cout<<"트래버설 확인\n";
    //inorder(head);
    //cout<<"트래버설 끝\n";
    char userWant[100]={0};
    char c;
    int y;
    //printf("\x1b[%dA",10);
    printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\x1b[%dA",10);
    while(1){
        printf("\n");
        printf("%s==========================정지는 esc\n",green);
        printf("%s",normal);
        printf("\x1b[%dA",2);
        system("stty raw");
        c=getchar();
        if(c==27){
            system("stty cooked");//system from 아는 형
            std::cout<<"장비를 정지합니다.\n";
            exit(0);
        }else{
            system("stty cooked");
        }
        printf("\x1b[%dB",2);
        for(int i=0;i<10;i++){
            printf("                                    \n");//이게 콘솔창 지우는거임
        }
        printf("\x1b[%dA",12);
        if(c==9){
            for(y=0;y<100;y++){
                printf("                              ");
                printf("\x1b[%dD",30);
                if(userWant[y]==0){
                    userWant[y-1]=0;
                    break;
                }
            }
        }else{
            for(y=0;y<100;y++){
                if(userWant[y]==0){
                    userWant[y]=c;
                    break;
                }
            }
        }
        for(int i=0;i<100;i++){
            if(userWant[i]=='0'){
                break;
            }else{
                std::cout<<userWant[i];
            }
        }
        int k=2;
        int index=0;
        if(userWant[0]==0){
            continue;
        }else{
            findWord(head,userWant);
            printf("\x1b[%dB",2);
            printf("\x1b[%dD",y+1); 
            while(!pq.empty()){
                box b=pq.top();
                pq.pop();
                k++;
                std::cout<<b.data<<" "<<b.searchNumber<<"\n";
            }
            printf("\x1b[%dA",k);
        }
    }
}