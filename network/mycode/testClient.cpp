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

#define green "\033[32m"
#define normal "\033[0m"

#define BUF_SIZE 1024
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

void error_handling(char *message);

int main(int argc, char *argv[])
{
	int sock;
	char message[BUF_SIZE];
	int str_len, recv_len, recv_cnt;
	struct sockaddr_in serv_adr;

	char userWant[100]={0};
    char c;
    int y;

	if(argc!=3) {
		printf("Usage : %s <IP> <port>\n", argv[0]);
		exit(1);
	}
	
	sock=socket(PF_INET, SOCK_STREAM, 0);   
	if(sock==-1)
		error_handling("socket() error");
	
	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family=AF_INET;
	serv_adr.sin_addr.s_addr=inet_addr(argv[1]);
	serv_adr.sin_port=htons(atoi(argv[2]));
	
	if(connect(sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr))==-1)
		error_handling("connect() error!");
	else
		puts("Connected...........");
	
	while(1) 
	{
		fputs("Input message(Q to quit): ", stdout);
		fgets(message, BUF_SIZE, stdin);
		
		//if(!strcmp(message,"q\n") || !strcmp(message,"Q\n"))
		//	break;


printf("\n\n\n\n\n\n\n\n\n\n");
    printf("\x1b[%dA",10);
    while(1){
        printf("\n");
        printf("%s==========================정지는 esc\n",green);
        printf("%s",normal);
        printf("\x1b[%dA",2);
        system("stty raw");
        c=getchar();
        if(c==27){
            system("stty cooked");//system from 아는 형
            std::cout<<"장비를 정지합니다.\n";
            exit(0);
        }else{
            system("stty cooked");
        }
        printf("\x1b[%dB",2);
        for(int i=0;i<10;i++){
            printf("                                    \n");//이게 콘솔창 지우는거임
        }
        printf("\x1b[%dA",12);
        if(c==9){
            for(y=0;y<100;y++){
                printf("                              ");
                printf("\x1b[%dD",30);
                if(userWant[y]==0){
                    userWant[y-1]=0;
                    break;
                }
            }
        }else{
            for(y=0;y<100;y++){
                if(userWant[y]==0){
                    userWant[y]=c;
                    break;
                }
            }
        }
        for(int i=0;i<100;i++){
            if(userWant[i]=='0'){
                break;
            }else{
                std::cout<<userWant[i];
            }
        }

		//여기서 서버로 보내고 
		str_len=write(sock, userWant, strlen(userWant));
		printf("와드1\n");
		if(!strcmp(userWant,"q\n") || !strcmp(userWant,"Q\n"))
			break;
		printf("와드2\n");

        int k=2;
        int index=0;
        if(userWant[0]==0){
            continue;
        }else{
			//여기서 받는거임 그걸 프린트
			printf("\x1b[%dB",2);
            printf("\x1b[%dD",y+1); 

			read(sock,&pq,BUF_SIZE-1);
			std::cout<<message<<"\n";

			printf("\x1b[%dA",k);
		// recv_len=0;
		// while(recv_len<str_len)
		// {
		// 	printf("와드3\n");
		// 	recv_cnt=read(sock, &message[recv_len], BUF_SIZE-1);
		// 	if(recv_cnt==-1)
		// 		error_handling("read() error!");
		// 	recv_len+=recv_cnt;
		// }
		// printf("와드4\n");
		// message[recv_len]=0;
		// printf("와드5\n");
		// printf("Message from server: %s\n", message);
		// printf("와드6\n");

            // findWord(head,userWant);
            // printf("\x1b[%dB",2);
            // printf("\x1b[%dD",y+1); 
            // while(!pq.empty()){
            //     box b=pq.top();
            //     pq.pop();
            //     k++;
            //     std::cout<<b.data<<" "<<b.searchNumber<<"\n";
            // }
        }
    }
		// str_len=write(sock, message, strlen(message));
		// printf("와드1\n");
		// if(!strcmp(message,"q\n") || !strcmp(message,"Q\n"))
		// 	break;
		// printf("와드2\n");
		// recv_len=0;
		// while(recv_len<str_len)
		// {
		// 	printf("와드3\n");
		// 	recv_cnt=read(sock, &message[recv_len], BUF_SIZE-1);
		// 	if(recv_cnt==-1)
		// 		error_handling("read() error!");
		// 	recv_len+=recv_cnt;
		// }
		// printf("와드4\n");
		// message[recv_len]=0;
		// printf("와드5\n");
		// printf("Message from server: %s\n", message);
		// printf("와드6\n");
	}
	
	close(sock);
	return 0;
}

void error_handling(char *message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}