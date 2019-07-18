#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<alloc.h>

struct entry
{
	char name[50];
	char email[50];
	char city[50];
	char cont[50];
	char num[50];
	struct entry *lptr;
	struct entry *rptr;
};
typedef struct entry node;
node *temp,*new1,*l,*r;

typedef struct entry *liist;

char n[50];
void newentry();

void display(char []);
void deletentry(char []);
void displayall();
void makempty();
void deleteall();

int isempty()
{
	return l==NULL;
}

int check_num(char a[50])
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]<48 || a[i]>57 || strlen(a)!=10)
		return(0);
	}
	return(1);
}

int check_at_the_rate(char a[50])
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
		if(a[i]==64)
		return(1);
	}
	return(0);
}

int check_email(char a[50])
{
	if(a[strlen(a)-4]=='.'  && a[strlen(a)-3]=='c'  && a[strlen(a)-2]=='o'  && a[strlen(a)-1]=='m')
		return(1);
	return(0);
}

void newentry()
{
	char a[50],b[50],c[50],d[50],e[50];
	int i,k=0;
	printf("enter the datas for new entry\n");
	printf("name :");
	scanf("%s",a);
	printf("email :");
	scanf("%s",b);
	printf("city :");
	scanf("%s",c);
	printf("country :");
	scanf("%s",d);
	printf("contact number :");
	scanf("%s",e);
	
	if(check_num(e)==1 && check_at_the_rate(b)==1 && check_email(b)==1)
	{
		new1=(struct entry*)malloc(sizeof(struct entry));
		for(i=0;i<50;i++)
		{
			new1->name[i]=' ';
			new1->email[i]=' ';
			new1->city[i]=' ';
			new1->cont[i]=' ';
			new1->num[i]=' ';
		}
		for(i=0;i<50;i++)
		{
			new1->name[i]=a[i];
			new1->email[i]=b[i];
			new1->city[i]=c[i];
			new1->cont[i]=d[i];
			new1->num[i]=e[i];
		}
		if(isempty())
		{
			new1->lptr=new1->rptr=NULL;
			l=r=new1;
			printf("your entry is added\n");
		}
		else
		{
			temp=l;
			while(temp!=NULL)
			{
				i=stricmp(new1->name,temp->name);
				if(i<0)
				break;
				else if(i>0)
				temp=temp->rptr;
				else if(i==0)
				{
					printf("name already exists entry cannot be added\n");
					k=1;
					break;
				}
			}
			if(k!=1)
			{
				if(temp==l)
				{
					new1->lptr=NULL;
					new1->rptr=l;
					l->lptr=new1;
					l=new1;
					printf("your node is added\n");
				}
				else if(temp==NULL)
				
{
					new1->rptr=NULL;
					new1->lptr=r;
					r->rptr=new1;
					r=new1;
					printf("your entry is added\n");
				}
				else
				{
					new1->rptr=temp;
					new1->lptr=temp->lptr;
					temp->lptr=new1;
					(new1->lptr)->rptr=new1;
					printf("your entry is added\n");
				}
			}
		}
	}
	else
	printf("\n\nInvallid Contact no Or Email ID\n\n");
}


void displayall()
{
	int n=1;
	if(!isempty())
	{
		temp=l;
		while(temp!=NULL)
		{
			printf("[%d] name :%s\n email id :%s\n city :%s\n  country :%s\n phone number :%s\n",n,temp->name,temp->email,temp->city,temp->cont,temp->num);
			temp=temp->rptr;
			n++;
		}
	}
	else
	{
		printf("adress book is empty\n");
	}
}

void deletentry(char n[50])

{
	int i;
	if(isempty())
	{
		printf("adress book is empty\n");
	}
	else
	{
		temp=l;
		while(temp!=NULL)
		{
			i=stricmp(temp->name,n);
			if(i==NULL)
			{
				if(l==r)
				{
					l=r=NULL;
					printf("entry deleted\n");
					break;
				}
				else if(temp==l)
				{
					l=l->rptr;
					l->lptr=NULL;
					printf("entry deleted\n");
					break;
				}
				else if(temp==r)
				{
					r=r->lptr;
					r->rptr=NULL;
					printf("entry deleted\n");
					break;
				}
				else
				{
					(temp->lptr)->rptr=temp->rptr;
					(temp->rptr)->lptr=temp->lptr;
					printf("entry deleted\n");
					break;
				}
			}
			temp=temp->rptr;
		}
		if(temp==NULL)
		
{
			printf("not found\n");
		}
	}
}

void makempty()
{
	l=r=NULL;
	printf("addres book is emptied\n");
}


void display(char n[50])
{
	int i,p=1;
	if (isempty())
	printf("address book is empty\n");
	else
	{
		temp=l;
		while(temp!=NULL)
		{
			i=stricmp(temp->name,n);
			if(i==NULL)
			{
				if(p==1)
				{
					printf("entry is found in %dst position",p);
				}
				else if(p==2)
				{
					printf("entry is found in %dnd position",p);
				}
				else if(p==3)
				{
					printf("entry is found in %drd position",p);
				}
				else
				{
					printf("entry is found in %dth position",p);
				}
				printf("name :%s\n email :%s\n city :%s\n  country :%s\n contact no :%s\n",temp->name,temp->email,temp->city,temp->cont,temp->num);
				
break;
			}
			temp=temp->rptr;
			p++;
		}
		if(temp==NULL)
		printf("entry not found\n");
	}
}

int main()
{
	int x=1,ch;
	char n[50];
	system("cls");
	while(x)
	{
		printf("enter your choice\n");
		printf("1.newentry\t2.deletentry\t3.displayall\t4.makempty\t5.display\n");
		scanf("%d",&ch);
		if(ch==1)
		{
			newentry();
		}
		else if(ch==2)
		{
			printf("enter the name of person to delete\n");
			scanf("%s",&n);
			deletentry(n);
		}
		else if(ch==3)
		{
			displayall();
		}
		else if(ch==4)
		{
			makempty();
		}
		else if(ch==5)
		{
			printf("enter name of person to display\n");
			scanf("%s",&n);
			display(n);
		}
		
else
		{
			printf("incorresct option\n");
		}
		printf("press 1 to continue 0 to exit\n");
		scanf("%d",&x);
	}
	getch();
	return 0;
 }










 
