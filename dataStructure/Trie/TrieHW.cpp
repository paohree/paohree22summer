#include<iostream>
#include<fstream>
#include<cstring>
#include<queue>
#define green "\033[32m"
#define normal "\033[0m"
using namespace std;
class node{
    public:
    char key;
    string data;
    int searchNumber;
    node *child[27];//띄어쓰기까지 하면 27개임
};
struct box{
    int searchNumber;
    string data;
    box(int number, string datas){
        searchNumber=number;
        data=datas;
    }
    bool operator<(const box b) const{
        return this->searchNumber<b.searchNumber;
    }
};
priority_queue<box>pq;
void inorder (node *pointer){
    if (pointer){
        cout << pointer->data<<" "<<pointer->searchNumber<<"\n";
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

void setSearchNumber(node *pointer, string word,int searchNumber){
    if(pointer->data==word){
        pointer->searchNumber=searchNumber;
        cout<<"다음과 같이 검색횟수가 설정됨\n";
        cout<<pointer->key<<" "<<pointer->data<<" "<<pointer->searchNumber<<"\n";
    }
}
node *MakeTrie(node *pointer,char alphabet){
    int i=0;
    while(pointer->child[i]!=NULL){
        if(pointer->child[i]->key==alphabet){
            pointer=pointer->child[i];
            cout<<"여기는 타고 들어간거임."<<pointer->key<<" "<<pointer->data<<"\n";
            return pointer;
        }else{
            i++;
        }
   }
    node *newChild=new node;
    newChild->key=alphabet;
    newChild->data=pointer->data+alphabet;
    newChild->searchNumber=0;
    cout<<"이거는 새로 만들어지는거임"<<newChild->key<<" "<<newChild->data<<" "<<newChild->searchNumber<<"\n";
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
    string sentence;
    string dummy;
    int searchNumber;
    ifstream file;
    int space;
    file.open("data.txt");
    if(file.is_open()){//데이터구조 만들고 검색횟수까지 넣어줌 ㅇㅇ
        while(getline(file,sentence,'\t')){
            file>>searchNumber;
            set=head;
            cout<<sentence<<"\n";
            space=sentence.length();
            cout<<space<<"\n";
            int j=0;
            cout<<searchNumber<<"\n";
            for(int i=0;i<space;i++){
                set=MakeTrie(set,sentence.at(i));
                setSearchNumber(set,sentence,searchNumber);
            }
            getline(file,dummy);
        }
        file.close();//ㅇㅋ 확인함 퍄퍄!
    }
    cout<<"트래버설 확인\n";
    inorder(head);
    cout<<"트래버설 끝\n";
    string userWant;
    char wantUser[100];
    while(1){
        printf("\n검색어를 입력하세요. (정지는 quit)\n");
        printf("%s  ||==========================||\n",green);
        printf("%s  ||                          ||\n",green);
        printf("%s  ||==========================||\n",green);
        printf("%s",normal);
        printf("\x1b[%dA",2);
        printf("\x1b[%dC",7);
        getline(cin,userWant);
        printf("\x1b[%dB",4);
        if(userWant=="quit"){
            cout<<"장비를 정지합니다.\n";
            break;
        }
        strcpy(wantUser,userWant.c_str());
        findWord(head,wantUser);
        while(!pq.empty()){
            box b=pq.top();
            pq.pop();
            cout<<b.data<<" "<<b.searchNumber<<"\n";
        }
    }
}//c++ 문법을 아직 잘 모르는거같음 책하나살까? 몰루겠다 일단 구글에서 알아야할듯
