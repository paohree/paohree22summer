//멀리뛰기
#include<iostream>
using namespace std;
int main(void){
    int number=0;
    int answer=0;
    cin>>number;
    if(number==1){
        cout<<number;
    }else if(number==2){
        cout<<number;
    }else{
        int number1=0;
        int number2=1;
        for(int i=1;i<=number;++i){
            answer=number1+number2;
            number1=number2;
            number2=answer;
        }
        cout<<answer;
    }
}