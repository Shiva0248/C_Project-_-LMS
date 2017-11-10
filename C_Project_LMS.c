/*C-Programming Defence (Library Management System)
							Programmers:-
										Shiva Tripathi
										Prashant Satyal
*/
#include<windows.h>
#include<stdio.h>                
#include<conio.h>                   
#include <stdlib.h>
#include<string.h>                
#include<ctype.h>                   
#include<dos.h>                    
#include<time.h>

/*Functions for LMS*/

void Password(void);
void mainmenu();
void check_book(void);
void add_book(void);
void  issue_book(void);
void return_book(void);
void loading();
void quote();
void dt();
void rock_paper_scissor();
void battleship();


char password[10]={"over9000"};

int main()
{
	Password();
	return 0;
}


		void Password(void)
		{
				dt();
				printf("_________________________________________________________________\n");
				system("cls");
				char ch,pass[10];
				int i=0,j;
				printf("\t\t\t**********Welcome to Library********** \n\n\n\n");
				printf("\t\t\t\tEnter Password:\n");
				printf("\n\t\t\t\t");
				scanf("%s",&pass);
				dt();
				if(strcmp(pass,password)==0)
				{
					printf("\n");
				printf("Password match \n");
				printf("Press any key to countinue");
				loading();
				mainmenu();
				}
				else
				{
				printf("Warning!! Incorrect Password");
				Password();
				}
		}
		
		
		void mainmenu()
				{
				system("cls");
				int choice;
				dt();
				printf("_________________________________________________________________\n");
				printf("\t\t\t\t1.Add Book \n\n");
				printf("\t\t\t\t2.Check Book \n\n");
				printf("\t\t\t\t3.Issue Book \n\n");
				printf("\t\t\t\t4.Return Book \n\n");
				printf("\t\t\t\t5.Update Book \n\n");
				printf("\t\t\t\t6.Exit \n\n");
				printf("\t\t\t\t7.Games \n\n");
				printf("Please, Enter your choice");
				printf("\t");
				scanf("%d",&choice);
				switch(choice)
				{
					case 1:
						system("cls");
						add_book();
					break;
					case 2:
						system("cls");
						check_book();
					break;
					case 3:
						system("cls");
						issue_book();
					break;
					case 4:
						system("cls");
						return_book();
					break;
					case 5:
						system("cls");
						printf("Coming Soon\n");
						int loadbar;
							for(loadbar=1;loadbar<3;loadbar++)
							{
								Sleep(500);
								printf(".");
							}
							{
							Sleep(1000);
							}
					break;
					case 6:
						system("cls");
						exit(0);
					break;
					case 7:
						system("cls");
						int n;
						printf("\t\t\t     ********Choose Game********\n\n");
						printf("\t1.Rock Paper Scissor \t\t\t\t 2.Battleship\n\n");
						printf("\t\t\t\t\t");
						scanf("%d",&n);
						switch(n)
						{
							dt();
							printf("_________________________________________________________________\n");
							case 1:
								system("cls");
								rock_paper_scissor();
								 break;
							case 2:
								system("cls");
								battleship();
								 break;
							default:
								system("cls");
								dt();
								printf("_________________________________________________________________\n");
								printf("\n\n\n\n\n\n\n\n\n");
								printf("\t\t\t\t");
								printf("Invalid Option!!!");
								Sleep(800);
								mainmenu();
						}
					break;
					default:
						printf("Invalid Option \nPlease enter the valid password\n");
						mainmenu();
				}
		}
		
		/*Structure for book details*/
struct books
{
	int s_roll;
	char s_name[20];
	char book_number[5];
    char bname[20];
    char author[20];
    int quantity;
    int section;
    struct issuegarne
	{
	int s_roll;
	char s_name[20];
//	char book_number[5];
	}issuestr;
};


struct books kitabstr;
FILE *fp,*ft,*fs;


	void check_book(void)
		{
			dt();
			printf("_________________________________________________________________\n");	
		    printf("Book Searching....\n");
		    ft=fopen("searchfrom.txt","r");
			int vetio=0;
			    char nammkhoj[15];
			    rewind(ft); 
			    printf("Enter Book Name: \n");
			    fflush(stdin);
			    gets(nammkhoj);
			   while (!feof(ft))
			     	{
				 		fscanf(ft, "%s  %s  %d",&kitabstr.bname,&kitabstr.author, &kitabstr.quantity);//(fread(&kitabstr,sizeof(kitabstr),1,ft)==1)
			    	
						if(strcmp(kitabstr.bname,(nammkhoj))==0) 
						{
						    printf("Entered book is available\n");
						    printf("\n Name: %s",kitabstr.bname);
						    printf("\n Author: %s",kitabstr.author);
						    printf("\n Quantity: %d \n",kitabstr.quantity);
						    vetio++;
						}
			    	}
			    	if(vetio==0)
			    	{
			    	printf("\nRecord not Found\n");
			    	}
			   		
			    	char get;
					printf("check another book: (Y/N) \n");
					if(getch()=='y')
			   		 check_book();
			   		 else
			   		 mainmenu();
			    
		}


	void add_book(void)  
		{
			dt();
			printf("_________________________________________________________________\n");
			fp=fopen("new_book.txt","a");//for data keepig 
			ft=fopen("searchfrom.txt","ab+");//for data reading
			printf("Please, Enter a book details \n");
			fflush(stdin);
			fprintf(fp,"________________________________________________________________\n");
			printf("Book Name:\n");
			gets(kitabstr.bname);
			fflush(stdin);
		    printf("Author:\n");
		    gets(kitabstr.author);
		    printf("Quantity:\n");
		    scanf("%d",&kitabstr.quantity);
			fprintf(fp,"Book Name: %s \nAuthor: %s\nQuantity:%d\n",kitabstr.bname,kitabstr.author,kitabstr.quantity);
			fprintf(ft," %s %s %d",kitabstr.bname,kitabstr.author,kitabstr.quantity);
			fprintf(fp,"________________________________________________________________\n");
			fclose(fp);
			fclose(ft);
			system("cls");
			printf("Sucessfully Recorded!!!!\n");
			char get;
			printf("Add another data: (Y/N) \n");
			scanf("%s",&get);
			if(get=='y'||get=='Y')
			{
				system("cls");
				add_book();
			}
			else
			{
			system("cls");
			mainmenu();
			}
		}


	void issue_book(void)
		{
			dt();
			printf("_________________________________________________________________\n");
			fp=fopen("issue_book_view.txt","a");
			ft=fopen("issue_book.txt","a");
			printf("Please, Enter book id:\n ");
			scanf("%s",&kitabstr.book_number);
			fflush(stdin);
			printf("enter book name:\n");
				scanf("%[^\n]",&kitabstr.bname);
			fflush(stdin);
			printf("Enter student's roll number: \n");
			scanf("%d",&kitabstr.issuestr.s_roll);
			time_t dt;
				time(&dt);
			fprintf(fp,"Date and Time:\t%s\nBook Name:%s\nBook ID:%s\nStudent ID:%d \n ",ctime(&dt),kitabstr.bname,kitabstr.book_number,kitabstr.issuestr.s_roll);
			fprintf(fp,"________________________________________________________________\n");
			fprintf(ft,"%s\n%s %s %d",ctime(&dt),kitabstr.bname,kitabstr.book_number,kitabstr.issuestr.s_roll);
			printf("Book has been issued!!!");
			fclose(fp);
			fclose(ft);
			char get;
			printf("Issue Another Book: (Y/N) \n");
			scanf("%s",&get);
			if(get=='y'||get=='Y')
			{
				system("cls");
				issue_book();
			}
			else
			{
			system("cls");
			mainmenu();
			}
		}

	void return_book(void)
		{
			dt();
			printf("_________________________________________________________________\n");
			fp=fopen("return_book_view.txt","a");
			ft=fopen("return_book.txt","a");
			printf("Book ID:\n ");
			scanf("%s",&kitabstr.book_number);
			fflush(stdin);
			printf("Book Name:\n");
				scanf("%[^\n]",&kitabstr.bname);
			fflush(stdin);
			printf("Student's Roll Number: \n");
			scanf("%d",&kitabstr.issuestr.s_roll);
			time_t dt;
			time(&dt);
			fprintf(fp,"Date and Time:\t%s\nBook Name:%s\nBook ID:%s\nStudent ID:%d \n ",ctime(&dt),kitabstr.bname,kitabstr.book_number,kitabstr.issuestr.s_roll);
			fprintf(fp,"________________________________________________________________\n");
			fprintf(ft,"%s\n%s %s %d",ctime(&dt),kitabstr.bname,kitabstr.book_number,kitabstr.issuestr.s_roll);
			printf("Book returned sucessfully!!!");
			fclose(fp);
			fclose(ft);
			char get;
			printf("Return Another Book: (Y/N) \n");
			scanf("%s",&get);
			if(get=='y'||get=='Y')
			{
				system("cls");
				return_book();
			}
			else
			{
			system("cls");
			mainmenu();
			}
		}

	void loading()
				{
					dt();
					printf("_________________________________________________________________\n");
				int loadbar;
				system("cls");
				quote();
				for(loadbar=1;loadbar<81;loadbar++)
				{
				Sleep(100);
				printf("%c",219);
				}
				system("cls");
				printf("\n\n\n\n\n\n\n\n");
				printf("\t\t\tWelcome to the library");
				for(loadbar=1;loadbar<3;loadbar++)
				{
					Sleep(500);
					printf(".");
				}
				Sleep(1000);
				}
		void quote()
				{
					dt();
					printf("_________________________________________________________________\n");
					srand(time(0));
				 int i  = rand()%5;
				
					if (i==0)
					{
					printf("Google can bring you back 100,000 answers. A librarian can bring you back the right one.\n");
					}
					
					if (i==1)
					{
					printf("The three rules of the Librarians of Time and Space are: \n1) Silence; \n2) Books must be returned no later than the last date shown; and \n3) Do not interfere with the nature of causality.\n");
					}	
					if (i==2)
						{
						printf("The librarians were mysterious. \nIt was said they could tell what book you needed just by looking at you, \nand they could take your voice away with a word.\n");
						}
					if (i==3)
						{
						printf("I found the idea of being a librarian very appealing - working in a place where people had to whisper and only speak when necessary. \nIf only the world were like that!\n");
						}
				}
				
		
	void dt()
			{
			time_t dt;
			time(&dt);
			system("cls");
			printf("\t\t\t\t\t\t       %s",ctime(&dt));
			}

	void rock_paper_scissor()
		{
			dt();
					printf("_________________________________________________________________\n");
			 int i,user,comp,player=0,computer=0;
			printf("rock paper sissor the game\n");
			for (i=1;i<=3;i++)
		{
			
			printf(" 0 for rock\n 1 for paper\n 2 for scissor\n");
		    scanf("%d",&user);
		    srand(time(0));
			comp=rand()%3;
			if (user==comp)
			printf("tie!!\n");
			switch(comp)
			{
			   case 0:
		       if (user==1)
		       {
		   	   printf("YOU WIN! \n");
		   	   player++;
		       }
		    
		       if (user==2)
		       {
		       	printf("YOU LOOSE!\n");
		   	   computer++;
			   }
		   	   
		       break;
		       
				case 1:
			   if (user==0)
			   {
		   	      printf("YOU LOOSE!\n");
		   	      computer++;
		       }
			   
			  if (user==2)
			   {
		   	    	printf("YOU WIN!\n");
		   	    	player++;
		       }
		       break;
		       case 2:
		       if (user==1)
		       {
		       	printf("YOU LOOSE!\n");
		       	computer++;
			   }
			   if (user==0)
			   {
			   	printf("YOU WIN!\n");
			   	player++;
			   }
			   break;
			   default:
			   	printf("invalid!\n");
			   	break;
			}
			
		}
		if (player>computer)
			{
				printf("you Won! congratulations!\n");
			}
			else if (player<computer)
			{
				printf("you lost! better luck next time!\n");
			}
			else
			{
				printf("It's a TIE!\n");
			}
		}


		void battleship()
				{
					dt();
					printf("_________________________________________________________________\n");
					{
						int r,c;
						int var1,var2;
						int x,y;
						int i,j;
						char sea[4][4] = {{'*','*','*','*'},{'*','*','*','*'},{'*','*','*','*'},{'*','*','*','*'}};
						printf("let's play battleship\n");
						printf("\n----------------------------------------------------\n");
						printf("\t");
							for(c=0;c<4;c++)
							{
								printf("\t%d",c);
							}
							
							printf("\n");
								for (r=0;r<4;r++)
								{
									printf("\t%d",r);	
										for(c=0;c<4;c++)
										{	
											printf("\t%c",sea[r][c]);
										}
										printf("\n");	
									}	
			srand(time(0));
			x=rand()%4;
			y=rand()%4;
			//printf("%d",x);
			//printf("%d",y);
			for(i=0;i<3;i++)
			{
				printf("\n----------------------------------------------------\n");
				printf("enter the coordinates to place the bomb!(row then column): ");
				scanf("%d %d",&var1,&var2);
				if(var1==x && var2==y)
				{
						printf("\t");
						for(c=0;c<4;c++)
						{
							printf("\t%d",c);
						}
						printf("\n");
						for (r=0;r<4;r++)
						{
							printf("\t%d",r);	
							for(c=0;c<4;c++)
							{	
								if(var1==r && var2 ==c)
								{
									sea[r][c]='b';
								}
								printf("\t%c",sea[r][c]);
							}
							printf("\n");	
						}	
					printf("CONGRATULATIONS ITS A BLAST!\n");
					break;
				}
				else 
				{
							printf("\t");
						for(c=0;c<4;c++)
						{
							printf("\t%d",c);
						}
						printf("\n");
						for (r=0;r<4;r++)
						{
							printf("\t%d",r);	
							for(c=0;c<4;c++)
							{	
			 					if(var1==r && var2 ==c)
								{
									sea[r][c]='m';
								}
							printf("\t%c",sea[r][c]);
							}
							printf("\n");	
						}	
					printf("miss!\n");
				}
			}
		}
			
				}
				
			
