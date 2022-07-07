#include<iostream>
using namespace std;
class node{
    public:
    int size;
    node *pointer;
};
class hill{
    public:
    int start;
    int end;
    int size;
    void setSize(){
        size=end-start;
    }
};
int main(void){
    int numberOfNode;
    int size;
    node *nodes[1000];
    node *head;
    node *set;
    hill *hills[1000];
    int j=0;
    cout<<"갯수는?\n";
    cin>>numberOfNode;
    for(int i=0;i<numberOfNode;i++){
        nodes[i]=new node;
        cin>>nodes[i]->size;
        if(i==0){
            head=nodes[i];
            set=head;
        }else{
            set->pointer=nodes[i];
            set=set->pointer;
        }
    }
    int index=0;
    set=head;
    for(int i=0;i<numberOfNode;i++){
        if(i==numberOfNode-1){
            if(index==1){
                hills[j]->end=set->size;
                hills[j]->setSize();
                cout<<"언덕끝남 0 "<<hills[j]->size<<" \n";
                index=0;
                break;
            }else if(index==0){
                cout<<"언덕끝남 1 \n";
                index=0;
                break;
            }
        }else if(set->size<set->pointer->size&&index==0){
            hills[j]=new hill;
            cout<<"언덕만듦\n";
            index=1;
            hills[j]->start=set->size;
        }else if(set->size<set->pointer->size&&index==1){
            cout<<"언덕이어짐\n";
        }else if(set->size>set->pointer->size&&hills[j]!=NULL){
            hills[j]->end=set->size;
            hills[j]->setSize();
            cout<<"언덕끝남 2 "<<hills[j]->size<<" \n";
            j++;
            index=0;
        }else{
            hills[j]->end=set->size;
            hills[j]->setSize();
            cout<<"언덕끝남 3 "<<hills[j]->size<<" \n";
            index=0;
        }
        set=set->pointer;
    }
    cout<<"어디가 문제라는거야\n";
    int numberOfhills=j+1;
    int big=-1;
    cout<<numberOfhills;
    for(j=0;j<numberOfhills;j++){
        if(j==0){
            big=hills[j]->size;
        }else{
            if(big<hills[j]->size){
                big=hills[j]->size;
            }
        }
    }
    if(big==-1){
        cout<<"언덕없는데요\n";
    }else{
        cout<<"제일 높은 언덕의 높이는 "<<big<<"임\n";
    }
}
//나올 수 있는 경우의 수 다시 생각해봐야할듯 
//세그폴트가 너무많이남 그게 무슨말이냐면 걍 한다는거임 생각없이
