//로프문제
//이거이렇게풀면안될거같은데
//이거 그리디래
#include<iostream>
using namespace std;
class Rope{
    public:
    int length;
};
int main(void){
    int numberOfRope=0;
    int ropeLength=0;
    int maxLength=0;
    int smallLength=0;
    Rope *rope[100000];
    cin>>numberOfRope;
    for(int i=0;i<numberOfRope;i++){
        rope[i]=new Rope;
        cin>>ropeLength;
        rope[i]->length=ropeLength;
    }
    for(int i=0;i<numberOfRope;i++){
        if(i==0){
            smallLength=rope[i]->length;
        }else{
            if(smallLength>rope[i]->length){
                smallLength=rope[i]->length;
            }
        }
        maxLength=(i+1)*smallLength;
        if(rope[i]->length>maxLength){
            maxLength=maxLength;
        }
    }
    cout<<maxLength;
}