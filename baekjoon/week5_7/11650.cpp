//좌표 정렬하기
//https://jungeu1509.github.io/algorithm/use-priorityqueue/ 블로그 보고 했음
//프라이어리티 큐 아직 못쓰는거같음
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
struct Point{
    int x;
    int y;
    Point(int a, int b){
        x=a;
        y=b;
    }
};
struct cmp{
    bool operator()(Point a, Point b){
        if(a.x==b.x){
            //cout<<a.y<<" "<<b.y<<"\n";
            return a.y>b.y;
        }
        //cout<<a.x<<" "<<b.x<<"\n";
        return a.x>b.x;
    }
};
int main(void){
    priority_queue <Point,vector<Point>,cmp> pq;
    int numberOfOrder=0;
    int x,y;
    cin>>numberOfOrder;
    for(int i=0;i<numberOfOrder;i++){
        cin>>x>>y;
        pq.push(Point(x,y));
    }
    for (int i=0;i<numberOfOrder;i++){
        Point end =pq.top();
        cout<<end.x<<" "<<end.y<<"\n";
        pq.pop();
    }
}