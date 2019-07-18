#include<iostream>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
using namespace std;

class typhoid
	 {
	    protected:
		    char name[40];
		    float age;
		    int wt;
		    float ht;
		    char sex;
		    char s[10];
	
	    public:
		 friend void welcome_screen();

		 void getvalue();
		 void putvalue()
		 {
		 	cout<<"\nN A M E        :"<<name;
			cout<<"\nA G E          :"<<age;
			cout<<"\nW E I G H T    :"<<wt;
			cout<<"\nH E I G H T    :"<<ht;
			cout<<"\nS E X (M/F)    :"<<sex;
		 }
		  
		 
	};

class symptoms:public typhoid
	 {
	    public:
		  void getlevel1_symptoms();
		  void getlevel2_symptoms();
		  void getlevel3_symptoms();
		  int analyse_symptoms(int);
		  char display_message(int,int);
		  void diagnosis();
		   void*operator new(size_t size)
		  { void*ptr;
		    ptr=malloc(size);
		    return ptr;
		  	
		  }
	 };


 void welcome_screen() 
	 {
	   system("cls");
	  cout<<"**************************************************** W E L C O M E*************************************************** "<<endl ;
	  cout<<" **************************************NEW HORIZON COLLEGE OF ENGINEERING**********************************************"<<endl  ;
	  cout<<"******************************* M E D I C A L   D I A G N O S I S   S O F T W A R E ***********************************"<<endl;
	  cout<<"******************************************** PRESS ANY KEY TO CONTINUE *************************************************"<<endl ;
	   getch();
	}
 
 
 
int main()
	{
	 char ch,choice,cho;
	 float m;
	 int n=1;
	 void typhoid(void);
	 symptoms *typ;
	 typ=new symptoms();
	
	welcome_screen();
	typ-> getvalue();
	 typ->diagnosis();
	 typ->getlevel1_symptoms();
	 m=typ->analyse_symptoms(n);
	 choice=typ->display_message(m,n);
	 choice=toupper(choice);
	 if(choice=='Y')
	 {
	  ++n;
	  typ->getlevel2_symptoms();
	  m=typ->analyse_symptoms(n);
	  choice=typ->display_message(n,m);
	  choice=toupper(choice);
	  if(choice=='Y')
	  {
	   ++n;
	  typ->getlevel3_symptoms();
	   m=typ->analyse_symptoms(n);
	   cho=typ->display_message(n,m);
	   cho=toupper(cho);
	   if(cho=='Y')
	   {
	    ++n;
	    typ->getlevel3_symptoms();
	    m=typ->analyse_symptoms(n);
	    choice=typ->display_message(m,n);
	   }
	  }
	 }
	 return 0;
	}
 
 
void typhoid::getvalue()
	{
	 system("cls");
	cout<<" P E R S O N A L   I N F O R M A T I O N";
	cout<<"\nN A M E        :";
	 gets(name);
	cout<<"\nA G E          :";
	 cin>>age;
	cout<<"\nW E I G H T    :";
	 cin>>wt;
	cout<<"\nH E I G H T    :";
	 cin>>ht;
	cout<<"\nS E X (M/F)    :";
	 cin>>sex;
     return;
	}
 
 
void symptoms::diagnosis()
     {
     system("cls");
    cout<<" **  D I A G N O S I S   W I N D O W **   "<<endl;
     cout<<"\n\n\n";
    cout<<" Let's have a look at  symptoms........."<<endl;
     cout<<"\n\n\n\n\n\n\t\t\t ";
    cout<<"***** PRESS ANY KEY ***** ";
     getch();
     }
 
void symptoms::getlevel1_symptoms(void)
    {
     system("cls");
     char ch;
     int i=0;
    cout<< " *** MEDICAL DIAGONOSIS FORM *** "<<endl;
    r1:cout<<"\nBODY TEMPERATURE (H(HIGH),/N(NORMAL):";
     cin>>s[i];
     if(s[i] == 'h' || s[i] == 'H' || s[i] == 'n' || s[i] == 'N')
     ++i;
     else
     {
     	cout<<"Invalid char";
     	goto r1;
     }
    r2:cout<<"\nCOUGH(Y(YES)/N(NO):";
       cin>>s[i];
    if(s[i] == 'y' || s[i] == 'Y' || s[i] == 'n' || s[i] == 'N')
     ++i;
     else
     {
     	cout<<"Invalid char";
     	goto r2;
     }
    r3:cout<<"\nHEADACHE(Y(YES)/N(NO):";
       cin>>s[i];
     if(s[i] == 'y' || s[i] == 'Y' || s[i] == 'n' || s[i] == 'N')
     ++i;
     else
     {
     	cout<<"Invalid char";
     	goto r3;
     }
     r4:cout<<"\nEPISTAXIS / NOSEBLEED (Y(YES)/N(NO):";
        cin>>s[i];
     if(s[i] == 'y' || s[i] == 'Y' || s[i] == 'n' || s[i] == 'N')
     ++i;
     else
     {
     	cout<<"Invalid char";
     	goto r4;
     }
    r5:cout<<"\nABDOMINAL PAIN(Y(YES)/N(NO):";
     cin>>s[i];
    if(s[i] == 'y' || s[i] == 'Y' || s[i] == 'n' || s[i] == 'N')
     ++i;
     else
     {
     	cout<<"Invalid char";
     	goto r5;
     }
     s[i]='\0';
     strupr(s);
         }
 
int symptoms::analyse_symptoms(int n)
 
    {
      int i=0;
      int count=0;
      int result=0;
      switch(n)
	{
	 case 1:   
		       if(s[0]=='H'&& s[3]=='Y' && s[4]=='Y')
			  result=-1;
		       else
			  {
			    for(i=0;i<5;i++)
			    {
			      if(s[i]=='H'|| s[i]=='Y')
				count++;
			     }
			     if(count>=3)
				result=-1;
			  }
		       break;
 
	 case 2: if((s[0]=='Y')||(s[1]=='Y')||(s[2]=='H')||(s[3]=='Y')||(s[4]=='H'))
		     result=0;
		 else
		     result=-1;
		     break;
	 case 3: if((s[0]=='L')&&(s[1]=='Y')&&(s[2]=='Y')&&(s[3]=='Y')||
 
	 (s[0]=='L')&&(s[1]=='Y')&&(s[2]=='N')&&(s[3]=='N')||
 
	 (s[0]=='L')&&(s[1]=='Y')&&(s[2]=='Y')&&(s[3]=='N')||
 
	 (s[0]=='L')&&(s[1]=='Y')&&(s[2]=='N')&&(s[3]=='Y')||
	 
	 (s[0]=='N')&&(s[1]=='Y')&&(s[2]=='Y')&&(s[3]=='Y')||
 
	 (s[0]=='N')&&(s[1]=='Y')&&(s[2]=='N')&&(s[3]=='N')||
 
	 (s[0]=='N')&&(s[1]=='Y')&&(s[2]=='Y')&&(s[3]=='N')||
 
	 (s[0]=='N')&&(s[1]=='Y')&&(s[2]=='N')&&(s[3]=='Y'))
		  result=-1;
		else
		   result=0;
		 break;
	 default:break;
	}
       return(result);
      }
 
char symptoms::display_message(int n,int m)
 
      {
       char ch;
       system("cls");
       putvalue();
       cout<<"\n";
       switch(n)
	 {
	  case 1:
		  switch(m);
		      {
		       case 0: 
			      cout<<"THE PERSON IS NOT HAVING TYPHOID\n"<<endl;
			      cout<<"PRESS ANY KEY TO QUIT.\n"<<endl ;
			       
			       exit(0);
 
		       case -1:
 
			       
			      cout<<"\nTHE PERSON IS HAVING TYPHOID \n"<<endl;
			      cout<<"PROCEED (Y/N)  ?\n"<<endl;

			       
			       cin>>ch;
			       break;
		      }

 
 
 
 
		case 2:
			switch(m)
			{
			   case 0: 
				  cout<<"\nIT IS I STAGE OF TYPHOID AND ITS SEVERE\n"<<endl;
				  cout<<"Proceed(Y/N)?\n"<<endl;
				   cin>>ch;
				   break;
 
			   case -1: 
				  cout<<"\nIT IS SECONDARY LEVEL TYPHOID.\n"<<endl;
				  cout<<"PRESS ANY KEY TO QUIT\n"<<endl;
				   getch();
				   break;
 
				   }
			break;
 
		case 3:switch(m)
		 {
			   case 0: 
				cout<<"\nIT IS PNEUMONIC TYPHOID\n"<<endl;
				
				cout<<"THANK YOU. TAKE CARE .";
				
				cout<<"PRESS ANY KEY TO QUIT"<<endl;
				getch();
				break;
 
 
			   case -1:
			      cout<<"\nIT IS NON PNEUMONIC TYPHOID\n"<<endl;
			      	cout<<"THANK YOU. TAKE CARE .";
			      cout<<"PRESS ANY  KEY TO QUIT .\n";
			       getch();
			       break;
 
		     
 
		 }
 
	     
	       }
	       return (ch);
	     }
 
 
 
 
void symptoms::getlevel2_symptoms()
	       {
		system("cls");
		int j=0;
		 cout<<"DELIRIUM(Y(YES)/N(NO):";
		  cin>>s[j];
		  s[j]=toupper(s[j]);
		  ++j;
		 cout<<"RED SPOTS(Y(YES)/N(NO):";
		  cin>>s[j];
		  s[j]=toupper(s[j]);
		  ++j;
		 cout<<"APPETITE(H(HIGH),/N(NORMAL):";
		  cin>>s[j];
		  s[j]=toupper(s[j]);
		  ++j;
		  cout<<"CONSTIPATION(ADULT) DIARREAH(KIDS)(Y(YES)/NO(NO):";
		   cin>>s[j];
		  s[j]=toupper(s[j]);
		  ++j;
		 cout<<"PULSE RATE(H(HIGH),/N(NORMAL):";
		  cin>>s[j];
		  s[j]=toupper(s[j]);
		  ++j;
		 
		  return;
	      }
 
void symptoms::getlevel3_symptoms()
	     {
		 int k=0;
		 system("cls");
		cout<<" PLATELETS LEVEL(H(HIGH),/N(NORMAL):";
		 cin>>s[k];

		 s[k]= toupper (s[k]);
		 ++k;
		cout<<"PNEUMONIA(Y(YES)/N(NO):";
		 cin>>s[k];
		 s[k]= toupper(s[k]);
		 ++k;
		cout<<"DIARRHEA(Y(YES)/N(NO):";
		 cin>>s[k];
		 s[k]= toupper(s[k]);
		 ++k;
		cout<<"DEHYDRATION(Y(YES)/N(NO):";
		 cin>>s[k];
		 s[k]= toupper(s[k]);
		 ++k;
				 return;
	}
 

