//근데이거어캐함?

#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node *left, *right;
};
void postOrder(node* head){
    if(head!=NULL){
        postOrder(head->left);
        postOrder(head->right);
        cout<<head->data<<"\n";
    }
}
int main(void){
    int number=0;
    int i=0;
    node *nodes=NULL;
    node *head=NULL;
    node *finder=NULL;
    while(cin>>number){
        if(i==0){
            nodes=new node;
            head=nodes;
            finder=head;
            nodes->data=number;
            i++;
        }else{
            nodes=new node;
            nodes->data=number;
            finder=head;
            while(1){
                if(finder->data<nodes->data){
                    if(finder->right==NULL){
                        finder->right=nodes;
                        cout<<"오른쪽에 붙음\n";
                        break;
                    }else{
                        finder=finder->right;
                        cout<<"오른쪽으로 감\n";
                    }
                }else if(finder->data>nodes->data){
                    if(finder->left==NULL){
                        finder->left=nodes;
                        cout<<"왼쪽에 붙음\n";
                        break;
                    }else{
                        finder=finder->left;
                        cout<<"왼쪽으로 감\n";
                    }
                }else{
                    cout<<"같은거 넣으면 안됨\n";
                    delete nodes;
                    break;
                }
            }
        }
    }
    postOrder(head);
}