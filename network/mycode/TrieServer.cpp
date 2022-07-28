#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024
void error_handling(char *message);

int main(int argc, char *argv[])
{
	int serv_sock, clnt_sock;
	char message[BUF_SIZE];
	int str_len, i;
	
	struct sockaddr_in serv_adr;
	struct sockaddr_in clnt_adr;
	socklen_t clnt_adr_sz;
	
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
			//printf("message form client: %s, length: %d\n",message, str_len);
			message[str_len-1]='\0';
			//str_len--;
			printf("message from client: %s, length: %d\n",message, str_len);
			if(strcmp(message,"a")==0){
				printf("go to client: %s, length: %d\n","bb", strlen("bb"));
				write(clnt_sock, "bb", strlen("bb"));//str_len);
			}else if(strcmp(message,"aa")==0){
				write(clnt_sock, "bbb", strlen("bbb"));//str_len);
			}else if(strcmp(message,"aaa")==0){
				write(clnt_sock, "bbbb", strlen("bbbb"));//str_len);
			}else if(strcmp(message,"aaaa")==0){
				write(clnt_sock, "bbbbb", strlen("bbbbb"));//str_len);
			}else if(strcmp(message,"aaaaa")==0){
				write(clnt_sock, "bbbbbb", strlen("bbbbbb"));//str_len);
			}else{
				write(clnt_sock, "abc", strlen("abc"));//str_len);
			}
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