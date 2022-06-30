#include<iostream>
using namespace std;
int main(void){
    int a=0, b=0;
    int empty=0;
    int array[20]={0};
    for(int i=0;i<20;i++){
        array[i]=i+1;
    }
    for(int i=0;i<10;i++){
        cout<<"구간을 띄워서 입력하세요. \n";
        cin>>a;
        cin>>b;
        a--;
        b--;
        while(1){
            if(a>b||a==b){
                break;
            }
            empty=array[a];
            array[a]=array[b];
            array[b]=empty;
            a++;
            b--;
        }
    }
    for(int i=0;i<20;i++){
        cout<<array[i]<<" ";
    }
}

//끝!