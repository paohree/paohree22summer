#include<iostream>
using namespace std;
class ball{
    public:
    int colour;
    int size;
    int canWinSizeSum;
};
int main(void){
    int number;
    int size;
    int colour;
    ball *balls[200000];
    cout<<"공의 갯수를 입력하세요. \n";
    cin>>number;
    for(int i=0;i<number;i++){
        balls[i]=new ball;
    }
    for(int i=0;i<number;i++){
        cout<<"공의 색깔과 크기를 입력하세요. \n";
        cin>>balls[i]->colour;
        cin>>balls[i]->size;
    }
    for(int i=0;i<number;i++){
        for(int j=0;j<number;j++){
            if(balls[i]->colour!=balls[j]->colour&&balls[i]->size>balls[j]->size){
                balls[i]->canWinSizeSum=balls[i]->canWinSizeSum+balls[j]->size;
            }else{
                continue;
            }
        }
    }
    for(int i=0;i<number;i++){
        cout<<balls[i]->canWinSizeSum<<" ";
    }
}
//끝!
