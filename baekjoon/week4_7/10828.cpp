//끝!

//asdf
//making stack
//class stack have 5 functions, push, pop, size, empty, top.
//each function work like their name.
#include<iostream>
using namespace std;
class Stack{
    private:
    int data[100];
    int index;
    public:
    Stack(){
        index=0;
    }
    void push(int number){
        //data[index]=new int;
        data[index]=number;
        index++;
    }
    void pop(){
        if(index==0){
            cout<<"-1\n";
        }else{
            cout<<data[index-1]<<"\n";
            //delete data[index];
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
            cout<<"0\n";
        }
    }
    void top(){
        if(index==0){
            cout<<"-1\n";
        }else{
            cout<<data[index-1]<<"\n";
        }
    }
};
int main(void){
    Stack *stack;
    int input=0;
    string userWant={0};
    int pushNumber=0;
    cout<<"enter the number.\n";
    cin>>input;
    if(1<=input&&input<=10000){
        cout<<"stack is made\n";
        stack=new Stack;
        while(1){
            cout<<"enter the function name\n";
            cin>>userWant;
            if(userWant=="push"){
                cout<<"number?\n";
                cin>>pushNumber;
                stack->push(pushNumber);
            }else if(userWant=="pop"){
                stack->pop();
            }else if(userWant=="size"){
                stack->size();
            }else if(userWant=="empty"){
                stack->empty();
            }else if(userWant=="top"){
                stack->top();
            }else if(userWant=="stop"){
                cout<<"finish\n";
                break;
            }else{
                cout<<"wrong name \n";
            }
        }
    }else{
        cout<<"finish\n";
    }
}