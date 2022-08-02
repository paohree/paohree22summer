//트라이 검색창 화면이 떠야 하는 부분은 클라이언트임
//서버는 트라이 구현만 해놓고 단어 받아서 거기에 맞는 데이터들 보내주는 역할만 하면 됨

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include<iostream>

#include<fstream>
#include<cstring>
#include<queue>

#define BUF_SIZE 1024
void error_handling(char *message);
class node{
    public:
    char key;
    std::string data;
    int searchNumber;
    node *child[27];//띄어쓰기까지 하면 27개임
};
struct box{
    int searchNumber;
    std::string data;
    box(int number, std::string datas){
        searchNumber=number;
        data=datas;
    }
    bool operator<(const box b) const{
        return this->searchNumber<b.searchNumber;
    }
};
std::priority_queue<box>pq;
void inorder (node *pointer){
    if (pointer){
        //cout << pointer->data<<" "<<pointer->searchNumber<<"\n";
        for(int i=0;pointer->child[i]!=NULL;i++){
            inorder(pointer->child[i]);
        }
    }
}
char big[100];
void findWord(node *pointer, char wantuser[]){
    if (pointer){
        strcpy(big,pointer->data.c_str());
        if(strstr(big,wantuser)!=NULL&&pointer->searchNumber!=0){
            pq.push(box(pointer->searchNumber, pointer->data));
            //cout << pointer->data<<" "<<pointer->searchNumber<<"\n";
        }
        for(int i=0;pointer->child[i]!=NULL;i++){
            findWord(pointer->child[i],wantuser);
        }
    }
}

void setSearchNumber(node *pointer, std::string word,int searchNumber){
    if(pointer->data==word){
        pointer->searchNumber=searchNumber;
        //cout<<"다음과 같이 검색횟수가 설정됨\n";
        //cout<<pointer->key<<" "<<pointer->data<<" "<<pointer->searchNumber<<"\n";
    }
}
node *MakeTrie(node *pointer,char alphabet){
    int i=0;
    while(pointer->child[i]!=NULL){
        if(pointer->child[i]->key==alphabet){
            pointer=pointer->child[i];
            //cout<<"여기는 타고 들어간거임."<<pointer->key<<" "<<pointer->data<<"\n";
            return pointer;
        }else{
            i++;
        }
   }
    node *newChild=new node;
    newChild->key=alphabet;
    newChild->data=pointer->data+alphabet;
    newChild->searchNumber=0;
    //cout<<"이거는 새로 만들어지는거임"<<newChild->key<<" "<<newChild->data<<" "<<newChild->searchNumber<<"\n";
    for(i=0;;i++){
        if(pointer->child[i]==NULL){
            pointer->child[i]=newChild;
            pointer=pointer->child[i];
            return pointer;
        }else{
            continue;
        }
    }
}

int main(int argc, char *argv[])
{
	//트라이 구조부터 짬
	node *head=new node;
    node *set=new node;
    std::string sentence;
    std::string dummy;
    int searchNumber;
    std::ifstream file;
    int space;
    file.open("data.txt");
    if(file.is_open()){//데이터구조 만들고 검색횟수까지 넣어줌 ㅇㅇ
        while(std::getline(file,sentence,'\t')){
            file>>searchNumber;
            set=head;
            //cout<<sentence<<"\n";
            space=sentence.length();
            //cout<<space<<"\n";
            int j=0;
            //cout<<searchNumber<<"\n";
            for(int i=0;i<space;i++){
                set=MakeTrie(set,sentence.at(i));
                setSearchNumber(set,sentence,searchNumber);
            }
            getline(file,dummy);
        }
        file.close();//ㅇㅋ 확인함 퍄퍄!
    }

	int serv_sock, clnt_sock;
	char message[BUF_SIZE];
	int str_len, i;
	
	struct sockaddr_in serv_adr;
	struct sockaddr_in clnt_adr;
	socklen_t clnt_adr_sz;

	char userWant[100]={0};
    char c;
    int y;
	
	if(argc!=2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}
	
	serv_sock=socket(PF_INET, SOCK_STREAM, 0);   
	if(serv_sock==-1)
		error_handling("socket() error");
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=htonl(INADDR_ANY);
	serv_adr.sin_port=htons(atoi(argv[1]));

	if(bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("bind() error");
	
	if(listen(serv_sock, 5)==-1)
		error_handling("listen() error");
	
	clnt_adr_sz=sizeof(clnt_adr);

	for(i=0; i<5; i++)
	{
		clnt_sock=accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);
		if(clnt_sock==-1)
			error_handling("accept() error");
		else
			printf("Connected client %d \n", i+1);
	
		while((str_len=read(clnt_sock, message, BUF_SIZE))!=0){
			//여기서 받은 메세지로 트라이 검색 후 결과들 보내주면 됨
			//걍 박스 자체를 보내버리면 훨씬편하지않을까?

			printf("message form client: %s, length: %d\n",message, str_len);
			message[str_len-1]='\0';

			findWord(head,message);

			write(clnt_sock,&pq,sizeof(box));
			// str_len--;
			// printf("message from client: %s, length: %d\n",message, str_len);
			// if(strcmp(message,"a")==0){
			// 	printf("go to client: %s, length: %d\n","bb", strlen("bb"));
			// 	write(clnt_sock, "bb", strlen("bb"));//str_len);
			// }else if(strcmp(message,"aa")==0){
			// 	write(clnt_sock, "bbb", strlen("bbb"));//str_len);
			// }else if(strcmp(message,"aaa")==0){
			// 	write(clnt_sock, "bbbb", strlen("bbbb"));//str_len);
			// }else if(strcmp(message,"aaaa")==0){
			// 	write(clnt_sock, "bbbbb", strlen("bbbbb"));//str_len);
			// }else if(strcmp(message,"aaaaa")==0){
			// 	write(clnt_sock, "bbbbbb", strlen("bbbbbb"));//str_len);
			// }else{
			// 	write(clnt_sock, "abc", strlen("abc"));//str_len);
			// }
		}

		close(clnt_sock);
	}

	close(serv_sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}