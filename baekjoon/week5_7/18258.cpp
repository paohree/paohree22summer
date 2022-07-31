//큐 2
//끝!
#include<iostream>
using namespace std;
class Stack{
    public:
    int data[100];
    int index;
    Stack(){
        index=0;
    }
    void push(int number){
        data[index]=number;
        data[index+1]=0;
        index++;
    }
    void pop(){
        if(index==0){
            cout<<"-1\n";
        }else{
            cout<<data[0]<<"\n";
            for(int i=0;i<index;i++){
                if(data[i+1]!=0){
                    data[i]=data[i+1];
                    data[i+1]=0;
                }
            }
            index--;
        }
    }
    void size(){
        cout<<index<<"\n";
    }
    void empty(){
        if(index==0){
            cout<<"1\n";
        }else{
            cout<<"0"<<"\n";
        }
    }
    void front(){
        if(index==0){
            cout<<"-1\n";
        }else{
            cout<<data[0]<<"\n";
        }
    }
    void back(){
        if(index==0){
            cout<<"-1\n";
        }else{
            cout<<data[index-1]<<"\n";
        }
    }
};
int main(void){
    Stack stack;
    int numberOfOrder=0;
    string userWant={0};
    int number=0;
    cin>>numberOfOrder;
    for(int i=0;i<numberOfOrder;i++){
        cin>>userWant;
        if(userWant=="push"){
            cin>>number;
            stack.push(number);
        }else if(userWant=="pop"){
            stack.pop();
        }else if(userWant=="size"){
            stack.size();
        }else if(userWant=="empty"){
            stack.empty();
        }else if(userWant=="front"){
            stack.front();
        }else if(userWant=="back"){
            stack.back();
        }else{
            cout<<"잘못입력함\n";
        }
    }
}