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
    int height;
    void setHeight(){
        height=end-start;
    }
};
int main(void){
    int numberOfNodes;
    int size;
    node *nodes[10000];
    hill *hills[10000];
    int j=0;
    cout<<"노드 갯수는?\n";
    cin>>numberOfNodes;
    for(int i=0;i<numberOfNodes;i++){
        nodes[i]=new node;
        cout<<"size는? \n";
        cin>>size;
        nodes[i]->size=size;
        if(i!=0){
            nodes[i-1]->pointer=nodes[i];
        }
    }
    int index=0;//0은 언덕 없음 1은 언덕 중
    for(int i=0;i<numberOfNodes;i++){
        if(i==numberOfNodes-1){
            if(index==0){
                cout<<"프로그램 끝\n";
                j++;
                break;
            }else if(index==1){
                hills[j]->end=nodes[i]->size;
                hills[j]->setHeight();
                cout<<"언덕 끝내고 프로그램 끝\n";
                j++;
            }
        }else{
            if(nodes[i]->size<nodes[i]->pointer->size&&index==0){
                hills[j]=new hill;
                hills[j]->start=nodes[i]->size;
                cout<<"언덕 시작\n";
                index=1;
            }else if(nodes[i]->size<nodes[i]->pointer->size&&index==1){
                cout<<"언덕 중간\n";
            }else if(nodes[i]->size>=nodes[i]->pointer->size){
                hills[j]->end=nodes[i]->size;
                hills[j]->setHeight();
                cout<<"언덕 끝\n";
                index=0;
                j++;
            }
        }
    }
    cout<<j;
    for(int i=0;i<j;i++){
        cout<<hills[j]->height<<"\n";
    }
}