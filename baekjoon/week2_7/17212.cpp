#include<iostream>
using namespace std;
int main(void){
    int totalPrice=0;//1,2,5,7
    int divide=0;
    int ash=0;
    int totalNumber=0;
    cout<<"얼마를 지불해야 함?\n";
    cin>>totalPrice;
    for(int i=0;i<4;i++){
        if(i==0){
            ash=totalPrice%7;
            divide=totalPrice/7;
            totalNumber=totalNumber+divide;
            totalPrice=totalPrice-divide*7;
            if(ash==0){
                break;
            }
        }else if(i==1){
            ash=totalPrice%5;
            divide=totalPrice/5;
            totalNumber=totalNumber+divide;
            totalPrice=totalPrice-divide*5;
            if(ash==0){
                break;
            }
        }else if(i==2){
            ash=totalPrice%2;
            divide=totalPrice/2;
            totalNumber=totalNumber+divide;
            totalPrice=totalPrice-divide*2;
            if(ash==0){
                break;
            }
        }else{
            ash=totalPrice%1;
            divide=totalPrice/1;
            totalNumber=totalNumber+divide;
            totalPrice=totalPrice-divide*1;
        }
    }
    cout<<totalNumber<<"\n";
}
//dp가 뭐임?
//다이나믹 프로그래밍
//큰 문제를 작은 문제로 나눠서 푸는 알고리즘임
//bfs? dfs? 그게뭘까
//아무튼 문제 틀렸음
