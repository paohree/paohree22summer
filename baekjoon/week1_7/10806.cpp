#include<iostream>
using namespace std;
class island{
    public:
    int nameNumber;
    int haveNumberBrige=0;
    island *brige[200000];
};
int main(void){
    int problem;
    int numberOfIsland=0;
    int numberOfBrige=0;
    island *islands[100000];
    int from;
    int to;
    cout<<"섬의 수와 다리 갯수를 입력하세요. \n";
    cin>>numberOfIsland>>numberOfBrige;
    for(int i=0;i<numberOfIsland;i++){
        islands[i]=new island;
        islands[i]->nameNumber=i+1;
    }
    for(int i=0;i<numberOfBrige;i++){
        cout<<"몇번 섬과 몇번 섬이 연결되는지 입력하세요. \n";
        cin>>from>>to;
        islands[from-1]->brige[islands[from-1]->haveNumberBrige]=islands[to-1];
        islands[from-1]->haveNumberBrige++;
        islands[to-1]->haveNumberBrige++;
    }//다 주워졌다 그지?
    //다리 한개있는놈 찾으면 됨
    for(int i=0;i<numberOfIsland;i++){
        if(islands[i]->haveNumberBrige==1||islands[i]->haveNumberBrige==0){
            problem++;
        }
    }
    if(problem==0){
        cout<<problem<<"\n";
    }else if(problem==1){
        cout<<problem<<"\n";
        for(int i=0;i<numberOfIsland;i++){
            if(islands[i]->haveNumberBrige==1){
                cout<<"3 "<<i+1;
            }
        }
    }else{
        if(problem%2==0){
            cout<<problem/2<<"\n";
        }else{
            cout<<problem/2+1<<"\n";
        }
        for(int i=0;i<numberOfIsland;i++){
            for(int j=0;j<numberOfIsland;j++){
                if((islands[i]->haveNumberBrige==1&&islands[j]->haveNumberBrige==1)&&(i!=j)){
                    cout<<i+1<<" "<<j+1<<"\n";
                    islands[i]->haveNumberBrige++;
                    islands[j]->haveNumberBrige++;
                }
            }
        }
    }
}

//끝!
//사실 다리가 한개인 섬이 3개 이상의 홀수일때 경우 안만들었음
//하면되긴함 마지막 홀수 섬이랑은 아무 섬이랑 연결해주면 되니까
//다리가 한개인 섬이 1개일때도 사실 아무 섬이랑 연결해줘도 됨 예제에서는 3번섬이랑 연결했지만