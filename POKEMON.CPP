#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<iomanip.h>
#include<fstream.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int hp,ohp;

void display(char a[])
{ gotoxy(1,10);
  int i;
  i=strlen(a);
  if(i<=10)
  gotoxy(35,10);
  for(int j=0;j<i;j++)
  { cout<<a[j];
    delay(100);
  }
}

void batinfo(int a,int b)
{ void batdisp(char[6][25],char[6][25]);
  char mydata[6][25],odata[6][25];
  int i=0;
  switch(a)
  { case 1:
	   ifstream cha("Charazard.txt");
	   for(;i<6;++i)
	   {cha>>mydata[i];}
	   cha.close();
	   i=0;
	   break;

    case 2:
	   ifstream pi("Pikachu.txt");
	   for(;i<6;++i)
	   {pi>>mydata[i];}
	   pi.close();
	   i=0;
	   break;

    case 3:
	   ifstream bla("Blastoise.txt");
	   for(;i<6;++i)
	   {bla>>mydata[i];  }
	   bla.close();
	   i=0;
	   break;

    case 4:
	   ifstream ven("Venasaur.txt");
	   for(;i<6;++i)
	   {ven>>mydata[i];}
	   ven.close();
	   i=0;
	   break;

    case 5:
	   ifstream hit("Hitmonchan.txt");
	   for( ;i<6;++i)
	   {hit>>mydata[i];}
	   hit.close();
	   i=0;
	   break;


    case 6:
	   ifstream atr("Atricuno.txt");
	   for(; i<6;++i)
	   {atr>>mydata[i];}
	   atr.close();
	   i=0;
	   break;

  };
  i=0;
  switch(b)
  { case 1:
	   ifstream cha("Charazard.txt");
	   for(; i<6;++i)
	   {cha>>odata[i];}
	   cha.close();
	   i=0;
	   break;
    case 2:
	   ifstream pi("Pikachu.txt");
	   for( ;i<6;++i)
	   {pi>>odata[i];}
	   pi.close();i=0;
	   break;
    case 3:
	   ifstream bla("Blastoise.txt");
	   for( ;i<6;++i)
	   {bla>>odata[i];}
	   i=0;
	   bla.close();
	   break;
    case 4:
	   ifstream ven("Venasaur.txt");
	   for(;i<6;++i)
	   { ven>>odata[i];}
	   ven.close();
	   i=0;
	   break;
    case 5:
	   ifstream hit("Hitmonchan.txt");
	   for( ;i<6;++i)
	   {hit>>odata[i];}
	   hit.close();
	   i=0;
	   break;
    case 6:
	   ifstream atr("Atricuno.txt");
	   for(;i<6;++i)
	   { atr>>odata[i];}
	   atr.close();
	   i=0;
	   break;

  };
 batdisp(mydata,odata);
}
void batdisp(char x[6][25],char y[6][25])
{ int j;
  j=0;
  for(;j<6;j++)
  {if(j==0)
    { gotoxy(5,1);
      cout<<"HP"<<hp;
      gotoxy(53,1);
      cout<<"OHP"<<ohp;
      gotoxy(5,j+2);
      cout<<"YOU";
      gotoxy(52,j+2);
      cout<<"OPPONENT";
    }
    gotoxy(2,j+4);cout<<x[j];
    delay(250);
    gotoxy(49,j+4);cout<<y[j];

  }
}

void MATCH()
{ void battle();
  int match,nom;
  clrscr();
  char laba[200]={"Nice to see you again."
		   "Do you want to play \n1.single match? \n2.Tournament? \n(press 1 or 2)\n"};

   display(laba);
   cin>>match;
   if(match==1)
   nom=1;
   else if(match==2)
   nom=4;
   else
   exit(0);
   for(int i=0;i<nom;++i)
   battle();
}

void battle()
{   randomize();
    char ans;
    void batstat(int,int &,int,int);
    void batinfo(int,int);

    int p,op,tm,to,at;
    hp=ohp=100;
    cout<<"\n CHOOSE YOUR POKEMON WISELY (enter 1 to 6) : ";
    cin>>p;
    delay(1000);
    clrscr();
    cout<<"\n WELL! INTERESTING CHOICE.";
    delay(500);
    cout<<"\n Let the battle";
    char lb[10]={"BEGIN!"};
    display(lb);
    delay(2000);
    clrscr();
    op=random(6)+1;
    delay(1000);
    for(;(hp>0)&&(ohp>0);)
    { clrscr();
      batinfo(p,op);
      gotoxy(2,15);
      cout<<" Remember,the sum of the tosses should be an EVEN NUMBER for you to attack.";
      cout<<"\n Select a number : ";
      cin>>tm;
      to=random(6)+1;
      cout<<"\n OPPONENT PUTS : "<<to;
      delay(250);
      if((to+tm)%2==0)
      { cout<<"\n You attack";
	cout<<"\n Select a number from 1 to 4 to attack the opponent:";
	cin>>at;
	batstat(at,ohp,p,op);
      }
      else
      { cout<<"\n Opposition is gonna ATTACK!";
	at=random(6)+1;
	batstat(at,hp,op,p);
      }
    }
    if (!(hp<=0))
    { clrscr();
      gotoxy(35,10);
      cout<<"\n You WON!!!";
      delay(2000);
      clrscr();
      char ap[200]={"OAK:Well I am quite surprised...guess you are really a good pokemon trainer.Good work!"};
      display(ap);delay(2000);
      clrscr();

    }
    else
    { clrscr();
      gotoxy(35,10);
      cout<<"\n You LOST!";
      delay(2000);
      clrscr();
      char dap[200]={"OAK:Hmm...You gotta work hard to become a good pokemon trainer.Better luck next time!"};
      display(dap);delay(2000);
      clrscr();
    }
}

void batstat(int l,int &m,int o,int p)
{ if(((o==1)&&(l==1))||((o==1)&&(l==2))||((o==5)||(l==1)))
  { switch(p)
    { case 1:
	     m=m-5;cout<<"\n INEFFECTIVE";delay(2000);
	     break;
      case 2:
	     m=m-15;delay(2000);
	     break;
      case 3:
	     m=m-1;cout<<"\n POOR CHOICE OF ATTACK";delay(2000);
	     break;
      case 4:
	     m=m-25;delay(2000);
	     cout<<"\n SUPER EFFECTIVE";
	     break;
      case 5:
	     m=m-15;delay(2000);break;
      case 6:
	     m=m-20;delay(2000);break;
    }
  }
  else if ((o==2)&&((l==1)||(l==2))||((o==5)&&(l==3)))
  { switch(p)
    { case 1:
      case 4:
      case 5:
	     m=m-15;delay(2000);break;
      case 2:
	     m=m+15;cout<<"\n OUCH!";delay(2000);
	     break;
      case 3:
	     m=m-25;cout <<"\n Good!";
	     delay(2000);
	     break;
      case 6:
	     m=m-20;delay(2000);
	     break;
    }
  }
  else if((o==3)&&((l==1)||(l==2))||((o==6)&&(l==3)))
  { switch(p)
    { case 2:
      case 4:
      case 5:
      case 6:
	     m=m-10;delay(2000);
	     break;
      case 1:
	     m=m-33;
	     cout<<"\n Yeah!";
	     delay(2000);
	     break;
      case 3:
	     m=m-15;
	     delay(2000);
	     break;
     }
  }

  else if ((o==4)&&((l==1)||(l==3)))
  { switch (p)
    { case 2:
      case 3:
      case 5:
	     cout<<"Good";
	     m=m-20;
	     delay(2000);
	     break;
      case 1:
      case 4:
      case 6:cout<<"\n Facepalm";
	     m=m-10;
	     delay(2000);
	     break;
    }
  }
  else if(((o==1)&&(l==4))||((o==2)&&((l==3)||(l==4)))||((o==3)&&(l==4))||((o==5)&&(l==4))||((o==6)&&((l==2)||(l==4))))
  { switch(p)
    { case 1:
      case 2:
      case 3:
      case 4:
      case 5:
      case 6:
	     m=m-15;
	     delay(2000);
	     break;
    }
  }

  else
  { switch(p)
    { case 2:
      case 3:
      case 4:
	     m=m-25;
	     cout<<"\n WOW";
	     delay(2000);
	     break;
      case 1:
      case 6:
	     m=m-1;
	     cout<<"\n Ha ha ha!";
	     delay(2000);
	     break;
       case 5:
	      m=m-15;
	      delay(2000);
	      break;
     }
   }
}

void main()
{ void MATCH();
  ofstream po("Charazard.txt");
  po<<"CHARAZARD[FIRE_TYPE] \nAttacks:\n1.FLAMETHOWER \n2.BLAZE \n3.DRAGON_CLAW \n4.SEISMIC_TOSS";
  po.close();
  ofstream pt("Pikachu.txt");
  pt<<"PICKACHU[ELECTRIC_TYPE] \nATTACK:\n1.THUNDERBOLT \n2.SPARK \n3.IRON_TAIL \n4.TACKLE";
  pt.close();
  ofstream pth("Blastoise.txt");
  pth<<"BLASTOISE[WATER_TYPE] \nATTACK \n1.WATER_CANNON \n2.SURF \n3.BITE \n4.BODY_SLAM";
  pth.close();
  ofstream pf("Venasaur.txt");
  pf<<"VENASAUR[GRASS_TYPE] \nATTACK:\n1.RAZOR_LEAF \n2.SURF \n3.EARTHQUAKE \n4.BITE";
  pf.close();
  ofstream pfv("Hitmonchan.txt");
  pfv<<"HITMONCHAN[FIGHTING_TYPE] \nATTACK:\n1.FIRE_PUNCH \n2.ICE_PUNCH \n3.THUNDER_PUNCH \n4.SEISMIC_TOSS";
  pfv.close();
  ofstream ps("Articuno.txt");
  ps<<"ARTICUNO[ICE_TYPE]  \nATTACK:\n1.ICE_BEAM \n2.FLY \n3.SURF \n4.GUST";
  ps.close();
  clrscr();randomize();
  char ans;
  int match,nom;
  gotoxy(35,10);
  cout<<"POKEMON";
  gotoxy(30,11);
  cout<<"GO CATCH THEM ALL!!!";
  delay(2000);
  clrscr();
  char alaba[200]={"Hi! I am Professor Oak."
		    "And welcome to the WORLD OF POKEMON."
		    "Let's see if you are a good pokemon trainer."
		    "Do you want to play \n1.single match? \n2.Tournament? \n(press 1 or 2)\n"};
  display(alaba);
  cin>>match;
  if(match==1)
   nom=1;
  else if(match==2)
   nom=4;
  else
   exit(0);
  for(int i=0;i<nom;++i)
   battle();
	cout<<"\n Ready for another match?(Y/N)";
	cin>>ans;
	if(ans=='Y'||ans=='y')
	MATCH();
	if(ans=='N'||ans=='n')
	{
	  gotoxy(35,10);
	  cout<<"GOOD BYE";
	  exit(0);
	}

   getch();
}
