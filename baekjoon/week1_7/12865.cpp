#include<iostream>
using namespace std;
class something{
    private:
    int value;
    int weight;
    public:
    something *big;
    something *small;
    void SetValue(int number){
        this->value=number;
    }
    void SetWeight(int number){
        this->weight=number;
    }
    int getValue(){
        return value;
    }
    int getWeight(){
        return weight;
    }
    void plusValue(int number){
        this->value=this->value+number;
    }
};
class bag{
    private:
    int value;
    int weight;
    public:
    bag(){
        value=0;
        weight=0;
    }
    int checkBagWeight(){
        return weight;
    }
    int checkBagValue(){
        return value;
    }
    void insertThing(something *things){
        this->value=this->value+things->getValue();
        this->weight=this->weight+things->getWeight();
    }
    void copyBag(bag bag){
        this->value=bag.value;
        this->weight=bag.weight;
    }
};
void inorderPrint(something *things){//이거 고쳐야함
    if(things){
        inorderPrint(things->small);
        cout<<things->getWeight()<<" "<<things->getValue()<<"\n";
        inorderPrint(things->big);
    }
}
void findAns(something *things){

}
int main(void){
    int number=0;
    int weight=0;
    int thingWeight=0;
    int thingValue=0;
    something *things[100];
    something *head;
    something *child;
    something *parent;
    bag firstBag;
    bag secondBag;
    cout<<"물품의 수와 최대 무게를 입력하세요. \n";
    cin>>number>>weight;
    for(int i=0;i<number;i++){
        cout<<"이 물건의 무게와 가치는? \n";
        cin>>thingWeight>>thingValue;
        things[i]=new something;
        things[i]->SetValue(thingValue);
        things[i]->SetWeight(thingWeight);
        head=things[0];
        if(i==0){
            head=things[0];
        }else{
            parent=head;
            child=things[i];
            while(1){
                if(child->getWeight()>parent->getWeight()){
                    if(parent->big==NULL){
                        parent->big=child;
                        child->plusValue(parent->getValue());
                        break;
                    }else{
                        child->plusValue(parent->getValue());
                        parent=parent->big;
                    }
                }else{
                    if(parent->small==NULL){
                        child->plusValue(parent->getValue());
                        parent->small=child;
                        break;
                    }else{
                        child->plusValue(parent->getValue());
                        parent=parent->small;
                    }
                }
            }
        }
        cout<<"입력됨\n";//데이터구조까지는 짠거같음 ㅇㅇ
    }
    inorderPrint(head);
}

//이거 이렇게 하면 안될듯함
//ㅇㅇ
//맨 첫번째 입력값이 너무 중요해져버림
//for문으로 여러번 돌리는게 답 구하기에는 더 적합할듯함
