#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 1000
struct record
{
	char name[30];
	char pass[30];	
};

struct cust_info
{
	char id[10];
	char fund;
	float total_amount;
	float dividend;
	float profit;
	float total_profit;	
};
void registration();
void login();
void dividen(struct cust_info* );
void calculation(struct cust_info* c);
void main()
{
	int choose;
	printf("*****************************************\n");
	printf("1. Registration\n");
	printf("2. Login\n");
	printf("*****************************************\n");
	printf("Enter menu : ");
	scanf("%d", &choose);
	while(choose>2 || choose <1)
	{
		printf("Invalid. Enter the correct menu.\n");
		printf("Enter menu : ");
		scanf("%d", &choose);
	}
	switch(choose)
	{
		case 1:
			registration();
			break;
		case 2:
			login();
			break;
	}
}

void registration()
{
	struct record r;
	int c;
	FILE *FP=fopen("user_record.txt", "a");
	if(FP==NULL)
	{
		printf("Cannot open the file");
		exit(1);
	}
	else
	{
		fflush(stdin);
		printf("Enter your username: ");
		gets(r.name);
		printf("Enter your password: ");
		gets(r.pass);
		c=strlen(r.pass);
		while(c<6)
		{
			printf("Please enter 6 digits or more.\n");
			printf("Enter your a new password: ");
			gets(r.pass);
			c=strlen(r.pass);
		}
		printf("\nSUCCESSFUL REGISTRATION\n");
		fprintf(FP, "%s %s\n", r.name, r.pass);
		fclose(FP);
	}
	
}

void login()
{
	struct record r;
	struct cust_info c[max];
	int numc;
	int a;
	int found=0;
	float agentc;
	float ta;
	FILE *FP=fopen("user_record.txt", "r");
	FILE *fp=fopen("investment_info.txt", "a");
	if(FP==NULL || fp==NULL)
	{
		printf("Cannot open the file.");
		exit(1);
	}
	else
	{
		char n[30];
		char p[30];
		int a=1;
		system("cls");
		fflush(stdin);
		printf("Login Page.\n");
		printf("Enter your username: ");
		gets(r.name);
		printf("Enter your password: ");
		gets(r.pass);
		fscanf(FP, "%s %s", n, p);
		if(strcmp(r.name, n)==0)
		{
			if(strcmp(r.pass, p)==0)
			{
				printf("Successfully login.");
				found=1;
			}
		}
		else
		{
			printf("Login error!!.");
			while(a<3)
			{
				++a;
				fflush(stdin);
				printf("\n\nEnter your username: ");
				gets(r.name);
				printf("Enter your password: ");
				gets(r.pass);
				if(strcmp(r.name, n)==0)
				{
					if(strcmp(r.pass, p)==0)
					{
						printf("Successfully login.");
						found=1;
					}
				}
				else
				{
					printf("Login error!!.\n");
					printf("\nRepeatedly entering an incorrect username and password. Call your administrator to unlock your account.");
					exit(1);
				}
					
				
			}
		}
		printf("\n\nHow many customer : ");
		scanf("%d", &numc);
		printf("***************************************************\n");
		printf("         Welcome Trading Agent %s\n", r.name);
		printf("***************************************************\n");
		
		for(a=0; a<numc; a++)
		{
			char z;
			printf("\n**** ONLINE TRADING 2020 ****\n");
			printf("Enter customer ID : ");
			scanf("%s", &c[a].id);
			fflush(stdin);
			do
			{
				fflush(stdin);
				printf("\nSelect investment fund A || B || C : ");
				scanf("%c", &c[a].fund);
				printf("Enter investment amount : ");
				scanf("%f", &c[a].total_amount);
				dividen(&c[a]);
				//printf("%f", c[a].dividend);
				calculation(&c[a]);
				fflush(stdin);
				printf("\nDo you want to keep invest in other funds : ");
				scanf("%c", &z);
				printf("\n");
			}while(z=='Y');
			fprintf(fp, "%s %.2f\n", c[a].id, c[a].total_profit);
			agentc=0.015*c[a].total_profit;
			ta+=agentc;
			printf("\n*********************************************\n");
			printf("Customer ID : %s\n", c[a].id);
			printf("Customer Total Profit : %.2f\n", c[a].total_profit);
			printf("Your profit charge : RM %.2f", agentc);
			printf("\n*********************************************\n");
		}
		printf("\nTotal profit charge for all customers: RM %.2f\n", ta);
		fclose(fp);
		fclose(FP);
	}
}

void dividen(struct cust_info* c)
{
	if(c->fund=='A')
		c->dividend=0.13;
	else if(c->fund=='B')
		c->dividend=0.10;
	else if(c->fund=='C')
		c->dividend=0.25;
	else
		c->dividend=0.00;
}

void calculation(struct cust_info* c)
{
	c->profit=c->total_amount+(c->total_amount*c->dividend);
	c->total_profit+=c->profit;
}








