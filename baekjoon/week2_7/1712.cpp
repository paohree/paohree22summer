#include<iostream>
using namespace std;
int main(void){
    int fixedOutcome=0;//A
    int manufacturingCost=0;//B
    int numberOfMachine=0;
    int outcome=0;
    int price=0;//C
    int income=0;
    cout<<"고정비용, 가변비용, 개당 비용\n";
    cin>>fixedOutcome>>manufacturingCost>>price;
    
    while(1){
        numberOfMachine++;
        if(-manufacturingCost+price<0){
            cout<<"-1\n";
            break;
        }
        outcome=fixedOutcome+manufacturingCost*numberOfMachine;//판매비용(A+B)
        income=price*numberOfMachine;
        if(income>outcome){
            cout<<numberOfMachine;
            break;
        }
    }
}