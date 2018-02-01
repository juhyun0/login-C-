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
				printf("�߸��Է�\n");
				break;
		}
	}	
	return 0;
}

int menudisp(){
	int a;
	printf("1.ȸ������  2.�α���  3.����\n>> "); 
	scanf("%d",&a);
	
	return a;
}

void join(char *gID, char *gPASS, char *gNAME){
	
	while(1){
		printf("���̵� : ");
		scanf("%s", gID);
		
		if((isuppercheck(gID)+islowercheck(gID)+isnumcheck(gID)+isSpecial(gID) == 4) && strlen(gID)>=6) {
			break;
		}
		else {
			printf(" ���̵� �ۼ���Ģ�� ���� �ʽ��ϴ�\n");
			printf(" ���� �빮��, �ҹ���, ����, Ư������1���̻� �ݵ�� ����, 6�ڸ� �̻�\n");
		}
	}
		
	while(1){
		printf("��ȣ : ");
		scanf("%s", gPASS);
		
		if((isuppercheck(gPASS)+islowercheck(gPASS)+isnumcheck(gPASS)+isSpecial(gPASS) == 4) && strlen(gPASS)>=6) {
			break;
		}
		else {
			printf(" �н�����  �ۼ���Ģ�� ���� �ʽ��ϴ�\n");
			printf(" ���� �빮��, �ҹ���, ����, Ư������1���̻� �ݵ�� ����, 6�ڸ� �̻�\n");
		}
	}
		
	 printf(" �̸� : ");
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
	char newPASS[10];//����ȣ 
	char PASS[10];//Ȯ�ξ�ȣ 
	char prevPASS[10];
	
	if(*ad_count==1){
		printf("�� ��ȣ �Է� : ");
		scanf("%s",newPASS);
		printf("Ȯ�� ��ȣ �Է� : ");
		scanf("%s",PASS);
		printf("���� ��ȣ �Է� : ");
		scanf("%s",prevPASS); 
		if(strcmp(newPASS, PASS)==0 && strcmp(adPASS,prevPASS)==0){
			strcpy(adPASS, newPASS);
			printf("������ ��ȣ���� ����\n"); 
		}

	}	
	printf(" ������ �α�����\n"); 
	
	
}
void member(char *gID, char *gPASS, char *gNAME, int *g_count){
	char newNAME[10];
	char tPASS[10];
	
	if(*g_count==1){
		printf("�� �̸� �Է� : ");
		scanf("%s",newNAME);
		
		printf("��й�ȣ �Է� : ");
		scanf("%s",tPASS);
		
		if(strcmp(tPASS,gPASS)==0){
			strcpy(gNAME, newNAME);
			printf("�̸� ���� ����\n"); 
			return;
		}
		
	}
	
	printf("%s �α��� ��\n", gNAME);
}
void login(char * gID, char * gPASS, char *gNAME, char * adID, char * adPASS, int *g_count, int *ad_count, int *failcount){
	
	char tID[10], tPASS[10],newNAME[10];
	 
	printf("���̵� : "); 
	scanf("%s", tID);
	
	if(strcmp(tID,adID)==0 && *failcount>=3){
		printf("���ݱ���\n"); 
		return;
	}
	
	printf(" �н����� : "); 
	scanf("%s", tPASS);
	
	
	if(strcmp(tID, adID)==0 && strcmp(tPASS, adPASS)==0){
	
		(*ad_count)++;
		admin(adID, adPASS, ad_count);
		printf("�����ڴ� �α��� ����!!\n"); 
		(*failcount)=0;
	}
	else if(strcmp(tID, adID)!=0 || strcmp(tPASS, adPASS)!=0){
		(*failcount)++;
	}
	else if(strcmp(tID, gID)==0 && strcmp(tPASS, gPASS)==0){
		(*g_count)++;
		member(gID, gPASS, gNAME, g_count);
		printf("%s�� �α��� ����!!\n",gNAME); 
	}
	else {
		printf(" ȸ�� ������ ����ϼ���\n");
		return;
	}
}
		
