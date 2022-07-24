//호텔 방 넣어주기 프로그램
//테스트 갯수, 세로, 가로, 손님 번호 로 입력받음.
//해결!
 
#include<iostream>
using namespace std;
class Hotel{
    public:
    int height;
    int depth;
    int number;
    int answer;
};
int main(void){
    Hotel *hotel[1000];
    int numberOfTest=0;
    int share=0;
    int rest=0;
    int i=0;
    cout<<"number of test?  ";
    cin>>numberOfTest;
    cout<<"\n";
    for(i=0;i<numberOfTest;i++){
        hotel[numberOfTest]=new Hotel;
        cout<<"Case "<<i+1<<"\n";
        cout<<"Height?  ";
        cin>>hotel[i]->height;
        cout<<"Depth?  ";
        cin>>hotel[i]->depth;
        cout<<"Guest?  ";
        cin>>hotel[i]->number;
        rest=(hotel[i]->number-1)%hotel[i]->height;
        rest++;
        //cout<<rest<<"\n";
        share=(hotel[i]->number-1)/hotel[i]->height;
        share++;
        //cout<<share<<"\n";
        hotel[i]->answer=rest*100+share;
        //cout<<hotel[i]->answer<<"\n";
    }
    for(i=0;i<numberOfTest;i++){
        cout<<hotel[i]->answer<<"\n";
    }
}