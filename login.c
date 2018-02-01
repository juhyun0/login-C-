#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menudisp(); 
void join(char *, char *, char *);
int isuppercheck(char *);
int islowercheck(char *);
int isnumcheck(char *);
int isSpecial(char *);
void login(char *, char *, char *, char *, char *, int *, int *, int *);
void admin(char *, char *, int *);
void member(char *, char *, char *, int *);

int main(int argc, char *argv[]) {
	char gID[10], gPASS[10], gNAME[10];
	char adID[10]="admin", adPASS[10]="1234";
	int g_count=0;
	int ad_count=0, failcount=0;
	int m;
	
	while((m=menudisp())!=3){
		switch(m){
			case 1:
			    join(gID, gPASS, gNAME);
				break;
			case 2: ;
			    login(gID, gPASS, gNAME, adID, adPASS, &g_count, &ad_count, &failcount);
			    break;
			default:
				printf("잘못입력\n");
				break;
		}
	}	
	return 0;
}

int menudisp(){
	int a;
	printf("1.회원가입  2.로그인  3.종료\n>> "); 
	scanf("%d",&a);
	
	return a;
}

void join(char *gID, char *gPASS, char *gNAME){
	
	while(1){
		printf("아이디 : ");
		scanf("%s", gID);
		
		if((isuppercheck(gID)+islowercheck(gID)+isnumcheck(gID)+isSpecial(gID) == 4) && strlen(gID)>=6) {
			break;
		}
		else {
			printf(" 아이디 작성규칙에 맞지 않습니다\n");
			printf(" 영어 대문자, 소문자, 숫자, 특수문자1자이상 반드시 포함, 6자리 이상\n");
		}
	}
		
	while(1){
		printf("암호 : ");
		scanf("%s", gPASS);
		
		if((isuppercheck(gPASS)+islowercheck(gPASS)+isnumcheck(gPASS)+isSpecial(gPASS) == 4) && strlen(gPASS)>=6) {
			break;
		}
		else {
			printf(" 패스워드  작성규칙에 맞지 않습니다\n");
			printf(" 영어 대문자, 소문자, 숫자, 특수문자1자이상 반드시 포함, 6자리 이상\n");
		}
	}
		
	 printf(" 이름 : ");
	 scanf("%s", gNAME);
}


int isuppercheck(char *ap){
	while(*ap!='\0'){
		if(*ap>='A'&& *ap<='Z'){
			return 1;
		}
		ap++;
	}
	return 0;
}

int islowercheck(char *ap){
	while(*ap!='\0'){
		if(*ap>='a'&& *ap<='z'){
			return 1;
		}
		ap++;
	}
	return 0;
}
int isnumcheck(char *ap){
	while(*ap!='\0'){
		if(*ap>='1'&& *ap<='9'){
			return 1;
		}
		ap++;
	}
	return 0;
}
int isSpecial(char *ap){
	while(*ap!='\0'){
		if(!(*ap>='a'&& *ap<='z') && !(*ap>='A'&& *ap<='Z') && !(*ap>='0'&& *ap<='9'))  {
			return 1;
		}
		ap++;
	}
	
	return 0;
}

void admin(char *adID, char *adPASS, int *ad_count){
	char newPASS[10];//새암호 
	char PASS[10];//확인암호 
	char prevPASS[10];
	
	if(*ad_count==1){
		printf("새 암호 입력 : ");
		scanf("%s",newPASS);
		printf("확인 암호 입력 : ");
		scanf("%s",PASS);
		printf("이전 암호 입력 : ");
		scanf("%s",prevPASS); 
		if(strcmp(newPASS, PASS)==0 && strcmp(adPASS,prevPASS)==0){
			strcpy(adPASS, newPASS);
			printf("관리자 암호변경 성공\n"); 
		}

	}	
	printf(" 관리자 로그인중\n"); 
	
	
}
void member(char *gID, char *gPASS, char *gNAME, int *g_count){
	char newNAME[10];
	char tPASS[10];
	
	if(*g_count==1){
		printf("새 이름 입력 : ");
		scanf("%s",newNAME);
		
		printf("비밀번호 입력 : ");
		scanf("%s",tPASS);
		
		if(strcmp(tPASS,gPASS)==0){
			strcpy(gNAME, newNAME);
			printf("이름 변경 성공\n"); 
			return;
		}
		
	}
	
	printf("%s 로그인 중\n", gNAME);
}
void login(char * gID, char * gPASS, char *gNAME, char * adID, char * adPASS, int *g_count, int *ad_count, int *failcount){
	
	char tID[10], tPASS[10],newNAME[10];
	 
	printf("아이디 : "); 
	scanf("%s", tID);
	
	if(strcmp(tID,adID)==0 && *failcount>=3){
		printf("접금금지\n"); 
		return;
	}
	
	printf(" 패스워드 : "); 
	scanf("%s", tPASS);
	
	
	if(strcmp(tID, adID)==0 && strcmp(tPASS, adPASS)==0){
	
		(*ad_count)++;
		admin(adID, adPASS, ad_count);
		printf("관리자님 로그인 성공!!\n"); 
		(*failcount)=0;
	}
	else if(strcmp(tID, adID)!=0 || strcmp(tPASS, adPASS)!=0){
		(*failcount)++;
	}
	else if(strcmp(tID, gID)==0 && strcmp(tPASS, gPASS)==0){
		(*g_count)++;
		member(gID, gPASS, gNAME, g_count);
		printf("%s님 로그인 성공!!\n",gNAME); 
	}
	else {
		printf(" 회원 가입후 사용하세요\n");
		return;
	}
}
		
