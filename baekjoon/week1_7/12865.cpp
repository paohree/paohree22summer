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
    if(things->small==NULL){
        if(things->big==NULL){
            cout<<things->getWeight()<<"\n";
        }else{
            things=things->big;
            inorderPrint(things);
        }
    }else{
        things=things->small;
        inorderPrint(things);
    }
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
        if(i==0){
            head=things[0];
            child=head;
            parent=head;
        }else{
            child=things[i];
            while(1){
                if(child->getWeight()>parent->getWeight()){
                    if(parent->big==NULL){
                        parent->big=child;
                        break;
                    }else{
                        parent=parent->big;
                    }
                }else{
                    if(parent->small==NULL){
                        parent->small=child;
                        break;
                    }else{
                        parent=parent->small;
                    }
                }
            }
        }
        cout<<"입력됨\n";//데이터구조까지는 짠거같음 ㅇㅇ
    }
    inorderPrint(head);
}