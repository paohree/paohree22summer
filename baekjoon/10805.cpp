#include<iostream>
using namespace std;
int main(void){
    int h1, w1, h2, w2,h3,w3;
    cin>>h1>>w1>>h2>>w2;
    int point;
    int number;
    h3=h1-h2;
    w3=w1-w2;
    while(h1==0&&w1==0){
    if(h3>w3){
        if(w1<h3){
            point=h3;
        }else{
            point=w1;
        }
        h1=h1-point;
        w1=w1-point;
        number++;
    }else if(h3<=w3){
        if(h1<w3){
            point=w3;
        }else{
            point=h1;
        }
        h1=h1-point;
        w1=w1-point;
        number++;
    }
    }
    cout<<"\n"<<number;
}

//못풀겠음 ㅈㅈ
//보류