//비밀번호 추적하기 프로그램
//큐로 한다면? 스택으로 해야할거같기도 하고
#include<iostream>
#include<stack>
using namespace std;
class Answer{
    public:
    string answer;
};
string checkcheck(string before){
    stack<char> box;
    stack<char> backupBox;
    string after;
    string afterOneWord;
    int length=before.length();
    for(int i=0;i<length;i++){
        if(before.at(i)=='<'){
                //cout<<"와드 < \n";
            if(box.size()!=0){
                backupBox.push(box.top());
                box.pop();
            }else{

            }
        }else if(before.at(i)=='>'){
                //cout<<"와드 > \n";
            if(backupBox.size()!=0){
                box.push(backupBox.top());
                backupBox.pop();
            }else{

            }
        }else if(before.at(i)=='-'){
                //cout<<"와드 - \n";
            if(box.size()!=0){
                box.pop();
            }else{

            }
        }else{
                //cout<<"와드 알파벳임 \n";
            box.push(before.at(i));
            while(backupBox.size()!=0){
                box.push(backupBox.top());
                backupBox.pop();
            }
        }
    }
    length=box.size();
    for(int i=0;i<length;i++){
            //cout<<"와드 리턴값 넣는중...\n";
        afterOneWord=box.top();
        after=afterOneWord+after;
        box.pop();
    }
    return after;
}
int main(void){
    int number=0;
    Answer *answer[1000];
    string before;
    cout<<"enter number\n";
    cin>>number;
    for(int i=0;i<number;i++){
        answer[i]=new Answer;
        cout<<"enter sentence\n";
        cin>>before;
        before=checkcheck(before);
        answer[i]->answer=before;
    }
    for(int i=0;i<number;i++){
        cout<<answer[i]->answer<<"\n";
    }
}