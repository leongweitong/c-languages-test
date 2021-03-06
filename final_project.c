#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
struct cinema  //structure of movie name, movie price, movie duration and publishing company
{
	char name[60];
	int core;
	float price;
	float hour;
	char Publishing_Company[60];
}; 

struct login //structure of admin's name and password for login
{
	char username[50], pw[50];
};

struct seatprice //structure for number or seat row
{
	int r1,r2,r3,balcony;
};

void login(); //for admin's login
void user(); //for user's login
char* check(char[], char[]); //for comparing username and password to login
void registration(); //for register a user account
void menu(); //for admin to add movie, delete movie, view movie and search movie
void menu1(); //for user to view movie and booking ticket
void choose(int); //for admin to choose what to do
int choose1(int); //for user to choose what to do
void book_ticket(); //for booking tickets
void add_cinema(); //for inserting new movie
void delete_cinema(); //for deleting movie
void view_cinema(); //for view movie information
void search_cinema(); //for searching movie with movie code
void other(); //for output developers' name
void GO(); //for admin to back to menu
void next(); //for user to back to menu


int main()
{
	int option;
l:
	printf("\n\n");
	printf("     *******************************************************************\n");
	printf("     ******  Admin only have 1 account, can not be registered!!!  ******\n");
	printf("     **********          Press 1 to Login    (admin)          **********\n");
	printf("     **********          Press 2 to Login    (user)           **********\n");
	printf("     **********          Press 3 to Register (user)           **********\n");
	printf("     *******************************************************************\n");
	printf("     *******************************************************************\n\n");
	printf("     Enter Your Option : ");
	scanf("%d", &option);	
	switch(option)//use switch function to connect to other functions
	{
		case 1:
			login(); //call function login for admin to login
			break;
		case 2:
			user(); //call function user for user to login
			break;
		case 3:
			registration(); //call function registration for guest to register their user account
			break;
	}
	if(option==1) //if admin successfully login, he will be sent to function menu and go
	{
		menu();
		GO();
	}
	else if(option==2)//if user successfully login, he will be sent to function menu1 and next
	{
		menu1();
		next();
	}
	else if(option==3)//if user succesfully registered a user's account, he will return back to the firstpage to login
	{
		goto l;
	}
	
	return 0;
}

void login()//function for admin to login
{
	FILE* p=fopen("loginpart.txt", "r"); //open file "loginpart.txt" by using p and read 
	if(p==NULL) //if the file does not exist, it will return NULL
	{
		printf("Cannot open the file...");
		exit(1);//terminate a process or function calling immediately in the program
	}
	char arr1[]="Welcome To The Cinema Management System";
	char arr2[]="#######################################";
	char user[60], usertxt[60];
	char pass[60], passtxt[60];
	char ch;
	int i, a;
	int left=0;
	int right=strlen(arr1)-1;
	
	
	fflush(stdin);//clear the output buffer and move the buffered data to console or disk
	system("color 02");
	while(left<=right) //while loop for the greeting to appear
	{
		arr2[left]=arr1[left];
		arr2[right]=arr1[right];
		printf("				---------------------------------------------------------\n");
		printf("					%s					\n",arr2);
		printf("				---------------------------------------------------------\n");
		
		Sleep(10);
		system("cls");//clear screen
		left++;
		right--;
	}
	printf("				---------------------------------------------------------\n");
		printf("					%s					\n",arr1);
		printf("				---------------------------------------------------------\n");
	
	fscanf(p, "%s%s", usertxt, passtxt);//read admin's name and password in the "loginpart.txt" file

	for(a=1; a<4; a++)
	{
		fflush(stdin);//clear the output buffer and move the buffered data to console or disk
		printf("\nWarning - error three times will exit the program (%d)\n",a);
		printf("Enter user name     : ");//prompt admin to enter his name
		gets(user);
		fflush(stdin);//clear the output buffer and move the buffered data to console or disk
		printf("Enter your password : ");//prompt admin to enter his password
		while(1) //while input the password, your input will be covered with "*"
		{
			ch=getch();
			if(ch == 13)
			{
			pass[i]='\0';
			break; 
			}
			else
			{
			pass[i]=ch;
			i++;
			printf("*");
			}
		}
		i=0;
		if(strcmp(user, usertxt)==0)//compare username(input) with the data in file
		{
			if(strcmp(pass, passtxt)==0)//compare password(input) with the data in file
			{
				printf("\nSuccess, welcome back %s\n",user);
				Sleep(2000);
				system("cls");//clear screen
				break; 	
			}
			else//when admin input the invalid username or password, program will output this
			{
				printf("\n\nInvalid\n");
				printf("Please input again");
			}
		}
		else if(a<3) //admin can only insert the wrong input for three time
		{
			printf("\n\nInvalid\n");
			printf("Please input again");
		}
	}
	if(a==4)//program will exit when admin insert wrong input for three time
	{
		printf("\nError, program will exit\n");
		exit(0);//terminate a process or function calling immediately in the program
	}			
}

void user()//function for user to login
{
	FILE* u=fopen("register.txt", "r"); //open file "register.txt" by using u and read
	if(u==NULL) //if the file does not exist, it will return NULL
	{
		printf("Cannot open the file...");
		exit(1);//terminate a process or function calling immediately in the program
	}
	char arr1[]="Welcome To The Marionette Cinema Booking system";
	char arr2[]="###############################################";
	char user1[60], utxt[60];
	char pass1[60], pwtxt[60];
	char ch1;
	char r[60];
	int j, b;
	int left=0;
	int right=strlen(arr1)-1;
	
	system("color 06");
	while(left<=right)//while loop for the greeting to appear
	{
		arr2[left]=arr1[left];
		arr2[right]=arr1[right];
		printf("				***************************************************************\n");
		printf("					%s					\n",arr2);
		printf("				***************************************************************\n");
		
		Sleep(10);
		system("cls");//clear screen
		left++;
		right--;
	}
		printf("				***************************************************************\n");
		printf("					%s					\n",arr2);
		printf("				***************************************************************\n");
	
	for(b=1; b<4; b++)//for loop for user to re-enter their username and password for 2 time if they insert incorrect username and password
	{
		fflush(stdin);//clear the output buffer and move the buffered data to console or disk
		printf("\nWarning - error three times will exit the program (%d)\n",b);
		printf("Enter username     : ");//prompt user to enter their username
		gets(user1);
		printf("Enter your password : ");//prompt user to enter their password
		while(1)//while input the password, your input will be covered with "*"
		{
			ch1=getch();
			if(ch1 == 13)
			{
			pass1[j]='\0';
			break; 
			}
			else
			{
			pass1[j]=ch1;
			j++;
			printf("*");
			}
		}
		j=0;
		strcpy(r, check(user1, pass1));///check whether user entered correct username and password, then stringcopy r which is "success" or "fail"
		if(strcmp(r, "success")==0)//compare whether user entered correct username and password or not
		{
			printf("\nSuccess, welcome back %s\n",user1);
			Sleep(2000);
			system("cls");//clear screen
			break;
		}
		else if(b<3)//user can only insert the wrong input for three time
		{
			printf("\nInvalid.......\n");
			printf("Try again\n");
		}	
	}		
	if(b==4)//program will exit when user insert wrong input for three time
	{
		printf("\nError, program will exit\n");
		exit(1);//terminate a process or function calling immediately in the program
	}	
}

char* check(char user1[], char pass1[])//function for comparing username and password to login
{
	FILE* p=fopen("register.txt", "r"); //open file "register.txt" by using p and read
	static char r[60];
	struct login a;//call structure login by a
	if(p==NULL)//if the file does not exist, it will return NULL
	{
		printf("Could not open the file");
		exit(1);//terminate a process or function calling immediately in the program
	}
	
	else
	{
		while(!feof(p))//return true in case end of the file reached
		{
			fscanf(p, "%s %s\n", a.username, a.pw);
			//printf("%s %s\n", a.username, a.pw);
			if(strcmp(user1, a.username)==0)//compare whether user entered correct username or not
			{
				if(strcmp(pass1, a.pw)==0)//compare whether user entered correct password or not
				{
					strcpy(r, "success");
					fclose(p);//close the file
					return r;
				}
			}
			else
			{
				strcpy(r, "fail");
			}
		}
		if(strcmp(r, "fail")==0)
		{
			fclose(p); //close the file
			return r;
		}
	}
	
}

void registration()//function for registration a user account
{ 
  FILE *reg;//open the file by using reg
  reg=fopen("register.txt","a+");//open file "register.txt"
  struct login l;//call structure login by l
  
  system("cls");//clear screem
  printf("\nWelcome to Marionette Cinema. We need some details for registration."); 
  printf("\nNow please enter your username and password~~~");
  printf("\nThank you.");
  printf("\nEnter username(without space!):\n");
  scanf("%s",l.username);//prompt user to insert a username
  printf("\nEnter password:\n");
  scanf("%s",l.pw);//prompt user to insert a password
  printf("\nConfirm your password:\n");
  
  fprintf(reg,"%s %s\n",l.username,l.pw); //copy the user's username and password to "register.txt" file
  fclose(reg);//close the file
  
  printf("\nConfirming Details");
  Sleep(750);
  printf(".");
  Sleep(750);
  printf(".");
  Sleep(750);
  printf(".");
  printf("\nRegistration Successful!");
  Sleep(1600);
  system("cls");//clear screen
}

void menu()//function for admin to add movie, delete movie, view movie and search movie
{
	int input;
	system("cls");//clear screen
	system("color 07");
	printf("***********************************************\n");
	printf("   ****      1. Add Movie         ****   \n");
	printf("   ****      2. Delete Movie      ****   \n");
	printf("   ****      3. View Movie        ****   \n");
	printf("   ****      4. Search Movie      ****   \n");
	printf("   ****      5. Other             ****   \n");
	printf("   ****      0. Exit System       ****   \n");
	printf("***********************************************\n");
	printf("\n\n");
	printf("*****************\n");
	printf("Enter : ");
	scanf("%d", &input);
	while(input<0 || input > 5)//admin can only enter from 0 until 5, otherwise invalid input
	{
		printf("Invalid. Enter again : ");
		scanf("%d", &input);
	}
	choose(input);//call choose(input) funtion for connecting other functions
}

void menu1()//function for user to view movie and booking ticket
{
	int input1;
	system("cls");//clear screen
	system("color 07");
	printf("\t\t***********************************************\n");
	printf("\t\t   ****      1. View Movie       ****   \n");
	printf("\t\t   ****      2. Book Ticket      ****   \n");
	printf("\t\t   ****      0. Exit System      ****   \n");
	printf("\t\t***********************************************\n");
	printf("\n\n");
	printf("\t\tEnter : ");
	scanf("%d", &input1);
	while(input1<0 || input1 > 2)//admin can only enter from 0 until 2, otherwise invalid input
	{
		printf("Invalid. Enter again : ");
		scanf("%d", &input1);
	}
	choose1(input1);//call choose1(input1) funtion for connecting other functions	
}

void choose(int input)//function for admin to choose what to do
{
	switch(input)
	{
		case 1:
			add_cinema();
			break;
		case 2:
			delete_cinema();
			break;
		case 3:
			view_cinema();
			break;
		case 4:
			search_cinema();
			break;
		case 5:
			other();
			break;
		case 0:
			exit(0);//terminate a process or function calling immediately in the program
			
	}
	
}

int choose1(int input1)//function for user to choose what to do
{
	switch(input1)
	{
		case 1:
			view_cinema();
			break;
		case 2:
			book_ticket();
			break;
		case 0:
			exit(0);//terminate a process or function calling immediately in the program
			
	}
}

void book_ticket()//function for booking tickets
{
    system("color 06");
    struct cinema b;//call structure cinema by b
    struct seatprice a;//call structure seatprice by a
    FILE *fread;//open file cinema by using fread
	FILE *fp6; //open file cinema by using fp6
    
    char entername[60];
    int total_seat,total_amount,row,temp_row,i,j,k,s1,s2,s3,s4;
    float rp;
    int in;
    long long int mobile;
    char user_name[55],user_name2[55];
    char ch,choice,ch1;
    
    fread=fopen("cinema.txt","r");//open file "cinema.txt" and read
    if(fread==NULL)//if the file does not exist, it will return NULL
    {
        printf("File does not found!");
        exit(1);//terminate a process or function calling immediately in the program
    }
    
    else if(ch=fgetc(fread)==EOF)//If it is end of the file, execute the code below it
    {
        printf("\nNo Movie is available to book right now! Check after few days!!!");
        main();//call main function to return to main
    }
    fp6=fopen("stprc.txt","r");//open file "stprc.txt" and read
    if(fp6==NULL)//if the file does not exist, it will return NULL
    {
        printf("File does not found!");
        exit(1);//terminate a process or function calling immediately in the program
    }  
	
		system("cls");//clear screen
        fread=fopen("cinema.txt","r");//open file "cinema.txt" and read
        fscanf(fread, "%d", &b.core);
        fscanf(fread, "\n%[^\n]", b.name);
		fscanf(fread, "%f", &b.price);
		fscanf(fread, "%f", &b.hour);
		fscanf(fread, "\n%[^\n]", b.Publishing_Company);
		fp6=fopen("stprc.txt","r");
		fscanf(fp6, "%d", &a.r1);
		fscanf(fp6, "%d", &a.r2);
		fscanf(fp6, "%d", &a.r3);
		fscanf(fp6, "%d", &a.balcony);
		fflush(stdin);//clear the output buffer and move the buffered data to console or disk
		while(!feof(fread))//return true in case end of the file reached
		{			
        	printf("\n=================== Now Playing ========================");
        	printf("\nMovie Name            : %s",b.name);
        	printf("\nMovie code            : %d", b.core);
        	printf("\nTicket Price(per seat): RM %.2f",b.price);
       		printf("\nMovie Duration(hour)  : %.2f",b.hour);
       		printf("\nFilm Publisher        : %s", b.Publishing_Company);
        	printf("\n\t\tRow 1 to 4  : RM%d.",a.r1);
        	printf("\n\t\tRow 5 to 8  : RM%d.",a.r2);
        	printf("\n\t\tRow 9 to 12 : RM%d.",a.r3);
        	printf("\n\t\tBalcony     : RM%d.",a.balcony);
        	printf("\n========================================================");
        	fflush(stdin);//clear the output buffer and move the buffered data to console or disk
			printf("\n");
		 
        	fflush(stdin); //clear the output buffer and move the buffered data to console or disk
        	fscanf(fread, "%d", &b.core);
        	fscanf(fread, "\n%[^\n]", b.name);
			fscanf(fread, "%f", &b.price);
			fscanf(fread, "%f", &b.hour);
			fscanf(fread, "\n%[^\n]", b.Publishing_Company);
 		}
    goto choose;//"goto" statement transfers to the choose part 
    fclose(fread);//close file
    choose:
    {
        fread=fopen("cinema.txt","r");//open file "cinema.txt" and read
        fscanf(fread, "%d", &b.core);
        fscanf(fread, "\n%[^\n]", b.name);
		fscanf(fread, "%f", &b.price);
		fscanf(fread, "%f", &b.hour);
		fscanf(fread, "\n%[^\n]", b.Publishing_Company);
        fclose(fread);//close file
        printf("\nDo you want to Book tickets for above movie?(y/n)\n");
        printf("Enter : ");
        scanf("%c",&choice);
        if((choice=='y')||(choice=='Y'))//if else to choose whether yes or no 
        {
        	fflush(stdin);
            printf("Which movie do you want to watch?: ");
 			gets(entername);
 			fflush(stdin);
 			printf("Enter the movie code : ");
 			scanf("%d", &in);
 			fflush(stdin);
			printf("\n**Fill Details**");
            name:
                printf("\nEnter your name (First Name<space>Last Name):");
                scanf("%s %s",user_name,user_name2);
                for(i=0;i<strlen(user_name);i++)//
                {
                    int j=user_name[i];
                    if((j>=97 && j<=122) || (j>=65 && j<=90) || (j==32 && j==92))
                    {
                        continue;//bring the program control to the beginning of the loop.
                    }
                    else
                    {
                        printf("\nFirst name is invalid! Enter alphabets only!!!");
                        goto name;//"goto" statement transfers to the name part
                    }
                }
                for(i=0;i<strlen(user_name2);i++)
                {
                    k=user_name2[i];
                    if((k>=97 &&k <=122) || (k>=65 && k<=90) || (k==32 && k==92))
                    {
                        continue;//bring the program control to the beginning of the loop.
                    }
                    else
                    {
                        printf("\nLast name invalid! Enter alphabets only!!!");
                        goto name;//"goto" statement transfers to the name part
                	}
                }
            next:
            	fflush(stdin);
                mobile=0;
                printf("\nEnter mobile number (0xxxxxxxxx) : 0");
                scanf("%lld",&mobile);
                if(mobile<=000000000)
                {
                    printf("\nInvalid mobile number!!!\n");
                    goto next;//"goto" statement transfers to the next part
                }
                else if(mobile>999999999)
                {
                    printf("\nInvalid mobile number!!!\n");
                    goto next;//"goto" statement transfers to the next part
                }
                else if(mobile>=000000000 && mobile<=999999999)
                {
                    goto seats;//"goto" statement transfers to the seats part
                }
            seats:
            	fp6=fopen("stprc.txt","r");//open file "stprc.txt" and read
            	fscanf(fp6,"%d %d %d %d\n%d %d %d %d",&a.r1,&a.r2,&a.r3,&a.balcony,&s1,&s2,&s3,&s4);
                printf("\nSelect rows:\n1.Row 1 to 4: RM%d per seat (%d seats available)\n2.Row 5 to 8: RM%d per seat (%d seats available)\n3.Row 9 to 12: RM%d per seat (%d seats available)\n4.Balcony: RM%d per seat (%d seats available)\n",a.r1,s1,a.r2,s2,a.r3,s3,a.balcony,s4);
                printf("Enter : ");
				scanf("%d",&row);
                temp_row=row;//define temp_row with row
                //connect the row price which the row that user selected
                if(row==1)
                row=a.r1;
                else if(row==2)
                row=a.r2;
                else if(row==3)
                row=a.r3;
                else if(row==4)
                row=a.balcony;
                else
                {
                    printf("\nWrong choice!!!");
                    goto seats;//"goto" statement transfers to the seats part
                }
            fp6=fopen("stprc.txt","r");//open file "stprc.txt" and read
            fscanf(fp6,"%d %d %d %d\n%d %d %d %d",&a.r1,&a.r2,&a.r3,&a.balcony,&s1,&s2,&s3,&s4);
            fclose(fp6);//close file
            enter:
            printf("\nEnter total number of seats:");
            scanf("%d",&total_seat);
            if(total_seat==0)
            {
                printf("\nNumber of seats should not be 0...");
                goto enter;//"goto" statement transfers to the enter part
            }
            else if(temp_row==1)//if the user enter '1' for chosen row 
            {
                if(total_seat>s1)//if the required seat is more than available seat
                {
                    printf("\n%d seats are not available in row 1 to 4!",total_seat);
                    choice1:
                    printf("\nDo you want to change row?(1=Yes, 0=No)");
                    scanf("%d",&ch1);
                    if(ch1==1) //if else statement for 1(yes) or 0(no)
                    goto seats;
                    else if(ch1==0)
                    {
                        printf("\nOkay! No problem!!!\n\n");
                        Sleep(1500);
                        main();  //call main function to return to main  
					}
                    else
                    {
                        printf("\nWrong choice!!!");
                        goto choice1;//"goto" statement transfers to the choice1 part
                    }
                }
                else if(total_seat<=s1)//if required seat is less than the available seat
                {
                    s1=s1-total_seat;//calculate the remaining available seat
                    goto booking;
                }
            }
            else if(temp_row==2)//if the user enter '2' for chosen row 
            {
                if(total_seat>s2)//if the required seat is more than available seat
                {
                    printf("\n%d seats are not available in row 5 to 8!",total_seat);
                    choice2:
                    printf("\nDo you want to change row?(1=Yes, 0=No): ");
                    scanf("%d",&ch1);
                    if(ch1==1)//if else statement for 1(yes) or 0(no)
                    goto seats;//"goto" statement transfers to the seats part
                    else if(ch1==0)
                    {
                        printf("\nOkay! No problem!!!\n\n");
                        main();//call main function to return to main
                    }
                    else
                    {
                        printf("\nWrong choice!!!");
                        goto choice2;//"goto" statement transfers to the choice2 part
                    }
                }
                else if(total_seat<=s2)//if required seat is less than the available seat
                {
                    s2=s2-total_seat;
                    goto booking;//"goto" statement transfers to the booking part
                }
            }
            else if(temp_row==3)
            {
                if(total_seat>s3)//if the required seat is more than available seat
                {
                    printf("\n%d seats are not available in row 9 to 12!",total_seat);
                    choice3:
                    printf("\nDo you want to change row?(1=Yes, 0=No)");
                    scanf("%d",&ch1);
                    if(ch1==1)//if else statement for 1(yes) or 0(no)
                    goto seats;//"goto" statement transfers to the seats part
                    else if(ch1==0)
                    {
                        printf("\nOkay! No problem!!!\n\n");
                        main();//call main function to return to main
                    }
                    else
                    {
                        printf("\nWrong choice!!!");
                        goto choice3;//"goto" statement transfers to the choice3 part
                    }
            	}
                else if (total_seat<=s3)//if required seat is less than the available seat
                {
                    s3=s3-total_seat;
                    goto booking;//"goto" statement transfers to the booking part
                }
            }
            else if(temp_row==4)
            {
                if(total_seat>s4)
                {
                    printf("\n%d seats are not available in balcony!",total_seat);
                    choice4:
                    printf("\nDo you want to change row and book tickets? (1=Yes, 0=No)\n: ");
                    scanf("%d",&ch1);
                    if(ch1==1)//if else statement for 1(yes) or 0(no)
                    goto seats;//"goto" statement transfers to the seats part
                    else if(ch1==0)
                    {
                        printf("\nOkay! No problem!!!\n\n");
                        main();//call main function to return to main
                    }
                    else
                    {
                        printf("\nWrong choice!!!");
                        goto choice4;//"goto" statement transfers to the choice4 part
                    }
            	}
                else if(total_seat<=s4)//if required seat is less than the available seat
                {
                    s4=s4-total_seat;
                    goto booking;//"goto" statement transfers to the booking part
                
                }
        	}
            booking:
            {
				fread=fopen("cinema.txt", "r");
				if(fread==NULL)//if the file does not exist, it will return NULL
				{
					printf("Cannot open the file");
					exit(1); //terminate a process or function calling immediately in the program
				}
				else
				{
					fscanf(fread, "%d", &b.core);
					fscanf(fread, "\n%[^\n]", b.name);
					fscanf(fread, "%f", &b.price);
					fscanf(fread, "%f", &b.hour);
					fscanf(fread, "\n%[^\n]", b.Publishing_Company);
					while(!feof(fread))//return true in case end of the file reached
					{
						if(in==b.core)
						{
							rp=b.price;
						}
						fscanf(fread, "%d", &b.core);
						fscanf(fread, "\n%[^\n]", b.name);
						fscanf(fread, "%f", &b.price);
						fscanf(fread, "%f", &b.hour);
						fscanf(fread, "\n%[^\n]", b.Publishing_Company);
					}	
				}
				fclose(fread);//close file
                total_amount=total_seat*rp+(row*total_seat);//calculation for the total price
                printf("\nTickets Booked successfully!!!\n** ENJOY MOVIE **\nGenerating Bill");
                Sleep(750);
                printf(".");
                Sleep(750);
                printf(".");
                Sleep(750);
                printf(".");
                Sleep(750);
                printf("\n\t\t** Bill **");
                printf("\n========================================================");
                printf("\n\t\tName : %s %s",user_name,user_name2);
                printf("\n\t\tMobile number : 0%lld",mobile);
                printf("\n\t\tMovie name : %s",entername);
                if(temp_row==1)//if else statement for the chosen row
                printf("\n\t\tRow : 1 to 4");
                else if(temp_row==2)
                printf("\n\t\tRow : 5 to 8");
                else if(temp_row==3)
                printf("\n\t\tRow : 9 to 12");
                else if(temp_row==4)
                printf("\n\t\tRow : Balcony");
                printf("\n\t\tTotal seats : %d",total_seat);
                printf("\n\t\tCost per seat : RM%d",row);
                printf("\n\t\tCost per ticket: RM%.2f",rp);
                printf("\n\t\tTotal amount : RM%d",total_amount);
                printf("\n========================================================");
                printf("\n\nThank You! Visit again!!!\n\n");

            }
        }
        else if((choice=='n')||(choice=='N'))
        {
            printf("No problem! Visit after few days!");
            exit(0);
        }
        else
        {
            printf("\nWrong Choice!!!");
            goto choose;//"goto" statement transfers to the choose part
        }
    }
}


void add_cinema()//function for inserting new movie
{
	int x=0;
	int y=0;
	struct cinema c1;//call structure cinema by c1
	FILE* FP;//open file cinema by using FP
	FP=fopen("cinema.txt", "a");//open file "cinema.txt" and append
	if(FP==NULL)//if the file does not exist, it will return NULL
	{
		printf("Cannot open the file");
		exit(1);//terminate a process or function calling immediately in the program 
	}
	else
	{
		printf("How many movie you want to add? : ");
		scanf("%d", &x);
		printf("***********************************************\n");
		printf("***********************************************\n");
		while(y<x)
		{
			printf("Enter your movie code      : ");
			scanf("%d", &c1.core);
			fflush(stdin);//clear the output buffer and move the buffered data to console or disk
			printf("Enter your movie name      : ");
			gets(c1.name);
			printf("Enter your movie price     : ");
			scanf("%f", &c1.price);
			printf("Enter your movie hour      : ");
			scanf("%f", &c1.hour);
			fflush(stdin);//clear the output buffer and move the buffered data to console or disk
			printf("Enter your movie publisher : ");
			gets(c1.Publishing_Company);
			printf("\n");
		
			fprintf(FP, "%d\n%s\n%.2f\n%.2f\n%s\n", c1.core, c1.name, c1.price, c1.hour, c1.Publishing_Company);//scan all the data and added the data to the end of file
			y++;
		}
		printf("Finish ~~");
		Sleep(1500);
		system("cls");//clear screen
		fclose(FP);//close file
	}
}

void delete_cinema()//function for deleting movie
{	
	system("color 03");
	int x, a, code;
	FILE *fread, *fwrite;//open file by using fread and fwrite

	char c;
	struct cinema d;//call structure cinema by d
	
	fread=fopen("cinema.txt", "r");//open file "cinema.txt" and read
	if(fread==NULL)//if the file does not exist, it will return NULL
	{
		printf("Cannot open the file");
		exit(1); //terminate a process or function calling immediately in the program
	}
	else
	{
		printf("*****************\n");
		printf("*****************\n");
		
		fscanf(fread, "%d", &d.core);
		fscanf(fread, "\n%[^\n]", d.name);
		fscanf(fread, "%f", &d.price);
		fscanf(fread, "%f", &d.hour);
		fscanf(fread, "\n%[^\n]", d.Publishing_Company);
			
			while(!feof(fread))//return true in case end of the file reached
			{
				{
					printf("%d\n%s\n%.2f\n%.2f\n%s\n", d.core, d.name, d.price, d.hour, d.Publishing_Company);
					fflush(stdin);//clear the output buffer and move the buffered data to console or disk
					printf("\n");
				
					fscanf(fread, "%d", &d.core);
					fscanf(fread, "\n%[^\n]", d.name);
					fscanf(fread, "%f", &d.price);
					fscanf(fread, "%f", &d.hour);
					fscanf(fread, "\n%[^\n]", d.Publishing_Company);
				}
			}	
			rewind(fread);//sets the file position to the beginning of the file
			printf("\nEnter the movie code you want to delete: ");
			scanf("%d", &code);
			
		fwrite=fopen("copy.txt","w");//open file "copy.txt" fwrite and write
		fscanf(fread, "%d", &d.core);
		fscanf(fread, "\n%[^\n]", d.name);
		fscanf(fread, "%f", &d.price);
		fscanf(fread, "%f", &d.hour);
		fscanf(fread, "\n%[^\n]", d.Publishing_Company);
		while (!feof(fread))//return true in case end of the file reached
		{ 
		
			if(d.core!=code)//is the entered code is not same with the movie code
			{
				fprintf(fwrite, "%d\n%s\n%.2f\n%.2f\n%s\n", d.core, d.name, d.price, d.hour, d.Publishing_Company);
				
			}	
			fscanf(fread, "%d", &d.core);
			fscanf(fread, "\n%[^\n]", d.name);
			fscanf(fread, "%f", &d.price);
			fscanf(fread, "%f", &d.hour);
			fscanf(fread, "\n%[^\n]", d.Publishing_Company);
		}
		
	}
		printf("\nMovie Deleted Successfully!!!\n");
		Sleep(1500);
		system("cls");//clear screen
		fclose(fread);//close file
		fclose(fwrite);//close file
		remove("cinema.txt");//deletes the given filename so that it is no longer accessible.
		rename("copy.txt", "cinema.txt");//rename the file name "copy.txt" with "cinema.txt"
}

void view_cinema() //function for view movie information
{
	//open file
	struct cinema v;//call structure cinema by v
	FILE* fp= fopen("cinema.txt", "r");//open file "cinema.txt" and read
	if(fp== NULL)//if the file does not exist, it will return NULL
	{
		printf("File read failed\n");
		exit(1);//terminate a process or function calling immediately in the program
	}
	system("cls");//clear screen
	fscanf(fp, "%d\n", &v.core);
	fscanf(fp, "\n%[^\n]", v.name);
	fscanf(fp, "\n%f %f", &v.price, &v.hour);
	fscanf(fp, "\n%[^\n]", v.Publishing_Company);
	while(!feof(fp))//return true in case end of the file reached
	{
		printf("Movie Code       : %d\n", v.core);
		printf("Movie Name       : %s\n", v.name);
		printf("Movie Price      : RM %.2f\n", v.price);
		printf("Movie Time(hour) : %.2f\n", v.hour);
		printf("Movie Publisher  : %s\n", v.Publishing_Company);
		fflush(stdin);//clear the output buffer and move the buffered data to console or disk
		printf("\n");
		
		fflush(stdin);//clear the output buffer and move the buffered data to console or disk
		fscanf(fp, "%d\n", &v.core);
		fscanf(fp, "\n%[^\n]", v.name);
		fscanf(fp, "\n%f %f", &v.price, &v.hour);
		fscanf(fp, "\n%[^\n]", v.Publishing_Company);
	}
	fclose(fp);//close file
}

void search_cinema()//function for searching movie with movie code
{
	struct cinema d; //call structure cinema by d
	int i=0;
	FILE *p=fopen("cinema.txt", "r");
	int input;
	if(p==NULL)//if the file does not exist, it will return NULL
	{
		printf("Cannot open the file");
		exit(1); //terminate a process or function calling immediately in the program
	}
	
	else
	{
		printf("*****************\n");
		printf("*****************\n");
		fscanf(p, "%d", &d.core);
		fscanf(p, "\n%[^\n]", d.name);
		fscanf(p, "%f", &d.price);
		fscanf(p, "%f", &d.hour);
		fscanf(p, "\n%[^\n]", d.Publishing_Company);
		printf("Enter cinema code to search : ");
		scanf("%d", &input);
		if(input==d.core)
		{
			++i;
			printf("Movie Code       : %d\n", d.core);
			printf("Movie Name       : %s\n", d.name);
			printf("Movie Price      : RM %.2f\n", d.price);
			printf("Movie Time(hour) : %.2f\n", d.hour);
			printf("Movie Publisher  : %s\n", d.Publishing_Company);
			fflush(stdin);
			printf("\n");
		}
		fflush(stdin);//clear the output buffer and move the buffered data to console or disk
		fscanf(p, "%d", &d.core);
		fscanf(p, "\n%[^\n]", d.name);
		fscanf(p, "%f", &d.price);
		fscanf(p, "%f", &d.hour);
		fscanf(p, "\n%[^\n]", d.Publishing_Company);
			while(!feof(p))//return true in case end of the file reached
			{
					if(input==d.core)//if entered cinema code is equal to cinema code
					{
						++i;
						printf("Movie Code       : %d\n", d.core);
						printf("Movie Name       : %s\n", d.name);
						printf("Movie Price      : RM %.2f\n", d.price);
						printf("Movie Time(hour) : %.2f\n", d.hour);
						printf("Movie Publisher  : %s\n", d.Publishing_Company);
						fflush(stdin);//clear the output buffer and move the buffered data to console or disk
						printf("\n");
					}
					fflush(stdin);//clear the output buffer and move the buffered data to console or disk
					fscanf(p, "%d", &d.core);
					fscanf(p, "\n%[^\n]", d.name);
					fscanf(p, "%f", &d.price);
					fscanf(p, "%f", &d.hour);
					fscanf(p, "\n%[^\n]", d.Publishing_Company);
			}
			if(i==0)
			{
				printf("Could not find what you are search for...\n\n");
			}
		fclose(p);	//close file
	}
}

void other()//function for output developers' name
{
	printf("******************************\n");
	printf("Developer list ------\n");
	printf("******************************\n");
	printf("Name : LEE JIN SEN\n");
	printf("ID   : 1211205241\n");
	printf("Sex  : Male\n\n");
	printf("Name : LEONG WEI TONG\n");
	printf("ID   : 1211204085\n");
	printf("Sex  : Male\n\n");
	printf("Name : LIEW ZHI TONG\n");
	printf("ID   : 1211203835\n");
	printf("Sex  : Female\n\n");
	printf("Name : TAN SHI YI\n");
	printf("ID   : 1211204585\n");
	printf("Sex  : Female\n\n");
}

void GO()//function for admin to back to menu
{
	char i;
	do//do while loop for back to menu or exit program
	{
		fflush(stdin); //clear the output buffer and move the buffered data to console or disk
		printf("Do you want to go back menu?\n");
		printf("Key [ Y ] go to menu\n");
		printf("Key [ N ] will exit program\n");
		printf("Enter : ");
		scanf("%c", &i);
		switch(i)//create a switch case to back to menu or exit the program
		{
			case 'Y':
				menu();//call menu function to return to menu
				break;
			case 'N':
				exit(1);//terminate a process or function calling immediately in the program

			default:
				printf("Invalid input\n");
		}
	}while(i!='Y' || i !='N');
	
}

void next()//function for user to back to menu
{
	char i;
	do//do while loop for back to menu or exit program
	{
		fflush(stdin);//clear the output buffer and move the buffered data to console or disk
		printf("Do you want to go back menu?\n");
		printf("Key [ Y ] go to menu\n");
		printf("Key [ N ] will exit program\n");
		printf("Enter : ");
		scanf("%c", &i);
		switch(i)//create a switch case to back to menu or exit the program
		{
			case 'Y':
				menu1();//call menu1 function to return to menu 1
				break;
			case 'N':
				exit(1);//terminate a process or function calling immediately in the program

			default:
				printf("Invalid input\n");
		}
	}while(i!='Y' || i !='N');	
}




