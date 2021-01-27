#include<bits/stdc++.h>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<cstdio>
#include<time.h>
#include<conio.h>
using namespace std;

struct drivers
{
    char dname[50];
    char city[30];
    char pno[11];
    char gender;
    int rating;
};

class cabs
{
    char type[20];
    char model[20];
    float distance;
    drivers d;
    int rate;
    float fuel;
    int mileage;
    int norides;
    float earned;
    int cabid;
    char location[30];
    //location *startloc, *endloc;
    public: cabs()
            {
                d.rating=norides=0;
                earned=0.0;

            }
            void getcabdets()
            {
                cout<<" ENTER MODEL:";
                cin>>model;
                cout<<" ENTER CABID:";
                cin>>cabid;
                cin.get();
                cout<<"\n ENTER DRIVER'S DETAILS \n  NAME: ";
                gets(d.dname);
                cout<<"  CITY: ";
                cin>>d.city;
                cout<<"  PHONE NO.:";
                cin>>d.pno;
                cout<<"  GENDER:";
                cin>>d.gender;
                cabtype:
                cout<<"\n CHOOSE TYPE:";
                cout<<"\n 1. PREMIUM \n 2. SUV  \n 3. MINI \n   CHOICE:";
                int c;
                cin>>c;
                switch(c)
                {
                    case 1: strcpy(type, "PREMIUM");
                            rate=10;
                            fuel=24;
                            mileage=25;
                            break;
                    case 2: strcpy(type, "SUV");
                            rate=14;
                            fuel=22.0;
                            mileage=16;
                            break;
                    case 3: strcpy(type, "MINI");
                            rate=7;
                            fuel=20.0;
                            mileage=22;
                            break;
                    default: cout<<"**********************INVALID CHOICE*************************";
                             goto cabtype;
                }
            }
            void modify()
            {
                int cmileage, crate, k, l;
                char dnam[50], dpno[11];
                char typ[20], dcit[30];
                float fu;
                crate=-1;
                cmileage=-1;
                strcpy(dpno, "*");
                strcpy(dcit, "*");
                cout<<"\n\t CAB ID :"<<cabid;
                cout<<"\n\t CAB model: "<<model;
                cout<<"\n\t CAB TYPE: "<<type;
                cout<<"\n\t CAB RATE: "<<rate;
                cout<<"\t\t MILEAGE "<<mileage;
                cout<<"\t\t FUEL: "<<fuel;
                cout<<"\n\t DRIVER NAME: "<<d.dname;
                cout<<"\n\t DRIVER CITY: "<<d.city;
                cout<<"\n\t DRIVER PHONE NO.: "<<d.pno;
                cout<<"\n\t DO YOU WANT TO CHANGE THE TYPE OF CAB(0 to retain old): ";
                cin>>k;
                if(k==0)
                    {
                        cout<<"\n\t ENTER MILEAGE(-1 to retain old): ";
                        cin>>cmileage;
                        cout<<"\n\t ENTER RATE(-1 to retain old): ";
                        cin>>crate;
                    }
                else
                {
                    cout<<"\n CHOOSE TYPE:";
                    cout<<"\n 1. PREMIUM \n 2. SUV  \n 3. MINI \n   CHOICE:";
                    int c;
                    cin>>c;
                    switch(c)
                    {
                        case 1: strcpy(type, "PREMIUM");
                                rate=10;
                                fuel=24;
                                mileage=25;
                                break;
                        case 2: strcpy(type, "SUV");
                                rate=14;
                                fuel=22.0;
                                mileage=16;
                                break;
                        case 3: strcpy(type, "MINI");
                                rate=7;
                                fuel=20.0;
                                mileage=22;
                                break;
                     }
                  }
                cout<<"\n\t DO YOU WANT TO CHANGE THE DRIVER OF CAB(0 to retain old): ";
                cin>>l;
                if(l==0)
                {
                    cout<<"\n\t ENTER CITY OF DRIVER(* to retain old): ";
                    cin>>dcit;
                    cout<<"\n\t ENTER PHONE NO. OF DRIVER(* to retain old): ";
                    cin>>dpno;
                }
                else
                {
                    cin.get();
                    cout<<"\n ENTER DRIVER'S DETAILS \n  NAME: ";
                    gets(d.dname);
                    cout<<"  CITY: ";
                    cin>>d.city;
                    cout<<"  PHONE NO.:";
                    cin>>d.pno;
                    cout<<"   GENDER:";
                    cin>>d.gender;
                }
                if(strcmp( "*", dcit)!=0)
                    strcpy(d.city, dcit);
                if(strcmp("*", dpno)!=0)
                    strcpy(d.pno, dpno);
                if(crate!=-1)
                    {rate=crate;}
                if(cmileage!=-1)
                    {mileage=cmileage;}
            }
            char* rettype()
            {
                return type;
            }
            char* retloc()
            {
                return location;
            }
            int retcid()
            {
                return cabid;
            }
            int retnorides()
            {
                return norides;
            }
            float retearned()
            {
                return earned;
            }
            void cabdisplay1()
            {
                cout<<"\n"<<setw(10)<<cabid<<setw(14)<<model<<setw(15)<<type<<setw(17)<<location<<setw(19)<<d.dname<<setw(13)<<norides<<setw(14)<<earned<<setw(11)<<d.rating;
            }
            void driverdisplay()
            {
                cout<<"\n"<<setw(14)<<cabid<<setw(19)<<d.dname<<setw(14)<<d.city<<setw(15)<<d.pno<<setw(8)<<d.gender<<setw(13)<<norides<<setw(17)<<earned<<setw(11)<<d.rating;
            }
            void cabdisplay2()
            {
                cout<<"\n"<<setw(14)<<cabid<<setw(18)<<model<<setw(20)<<type<<setw(25)<<d.dname<<setw(19)<<rate<<setw(12)<<mileage;
            }
};
/*void awrite()
{
 char ans='y';
 cabs c;
 fstream f("cabss.dat",ios::out|ios::binary);
 if(!f)
 {
  cout<<"\tCannot proceed";
  getch();
  exit(0);
 }
 while(ans=='y'||ans=='Y')
 {
  c.getcabdets();
  f.write((char*)&c,sizeof(c));
  cout<<"\n RECORD ADDED \n \t DO YOU WISH TO CONTINUE?";
  cin>>ans;
 }
 f.close();
}*/
void aread()
{
 fstream f("cabss.dat",ios::in|ios::binary);
 cabs c;
 system("cls");
 cout<<"\n\t\t\t\t   \n\n";
cout<<"      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ CAB LIST ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
 cout<<setw(15)<<"CAB ID"<<setw(16)<<"model"<<setw(20)<<"TYPE"<<setw(25)<<"DRIVER'S NAME"<<setw(20)<<"RATE"<<setw(15)<<"MILEAGE\n\n";
 cout<<"      ---------------------------------------------------------------------------------------------------------\n\n";
  if(!f)
{
       cout<<"\t no record";
       getch();
      return;
}
  while(f)
 {
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  break;
  c.cabdisplay2();
 }
 getch();
 return;
}
void aread1()
{
 fstream f("cabss.dat",ios::in|ios::binary);
 cabs c;
 system("cls");
 cout<<"\n\t\t\t\t   \n\n";
cout<<"   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ CAB LIST ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
 cout<<setw(10)<<"CAB ID"<<setw(15)<<"NAME"<<setw(14)<<"TYPE"<<setw(18)<<"LOCATION"<<setw(20)<<"DRIVER'S model"<<setw(16)<<"NO. OF RIDES"<<setw(12)<<"EARNDED"<<setw(13)<<"RATING\n\n";
 cout<<"   ----------------------------------------------------------------------------------------------------------------\n\n";
  if(!f)
{
       cout<<"\t no record";
       getch();
      return;
}
  while(f)
 {
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  break;
  c.cabdisplay1();
 }
 getch();
 return;
}
void aread2()
{
 fstream f("cabss.dat",ios::in|ios::binary);
 cabs c;
 system("cls");
 cout<<"\n\t\t\t\t   \n\n";
cout<<"      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ CAB LIST ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
 cout<<setw(15)<<"CAB ID"<<setw(17)<<"DRIVER'S NAME"<<setw(13)<<"CITY"<<setw(16)<<"PHONE NO."<<setw(12)<<"GENDER"<<setw(18)<<"NO. OF RIDES"<<setw(12)<<"EARNDED"<<setw(13)<<"RATING\n\n";
 cout<<"      ---------------------------------------------------------------------------------------------------------\n\n";
  if(!f)
{
       cout<<"\t no record";
       getch();
      return;
}
  while(f)
 {
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  break;
  c.driverdisplay();
 }
 getch();
 return;
}
void append()
{
 char ans='y';
 cabs c;
 fstream f("cabss.dat",ios::binary|ios::out|ios::app);
  if(!f)
 {
  cout<<"\t CAN'T PROCEED\t";
  getch();
  exit(0);
 }
 while(ans=='y'||ans=='Y')
 {
  c.getcabdets();
  c.cabdisplay1();
  c.cabdisplay2();
  c.driverdisplay();
  f.write((char*)&c,sizeof(c));
  cout<<"\n RECORD ADDED \n \t DO YOU WISH TO CONTINUE?";
  cin>>ans;
 }
 f.close();
}
void adelete()
{
 fstream temp,f;
 f.open("cabss.dat",ios::in|ios::binary);
 temp.open("temp.dat",ios::out|ios::binary);
  if(!f||!temp)
 {
  cout<<"\n\t CAN'T PROCEED";
  getch();
  exit(0);
 }
 char nm[50],ans3;
 cabs c;
 int k;
 int flag=0;
 aread();
 cout<<"\n\t ENTER CAB ID OF THE CAB TO BE DELETED:";
 cin>>k;
 while(f)
 {
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  {
      getch();
      break;
  }
  if(c.retcid()==k)
  {
   cout<<"\n\t\tTHE DETAILS ARE....\n";
   c.cabdisplay1();
   flag=1;
   cout<<"\n\tDO YOU WISH TO DELETE(Y or N)= ";
   cin>>ans3;
    if(ans3=='y'||ans3=='Y')
      cout<<"\n\t RECORD DELETED \t\n";
    else
    temp.write((char*)&c,sizeof(c));
  }
  else
{
   temp.write((char*)&c,sizeof(c));
}
}
f.close();
temp.close();
remove("cabss.dat");
rename("temp.dat","cabss.dat");
  if(flag==0)
  cout<<"\n\t record not found\t\n";
  f.close();
 }

void amodify()
{
 int flag=0, k;
 char nm[50];
 cabs c;
 fstream f;
 f.open("cabss.dat",ios::in|ios::out|ios::binary);
 if(!f)
 {
  cout<<"Cannot proceed. Exitting..";
  getch();
  exit(0);
 }
 aread();
 cout<<"\tENTER CABID OF CAB WHOSE RECORDS ARE TO BE MODIFIED: ";
 cin>>k;
int p;
 while(f)
{
  p=f.tellg();
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  { break;  }
   if(c.retcid()==k)
 {
  cout<<"\n\t RECORD FOUND \t\n";
  c.modify();
  f.seekg(p,ios::beg);
  f.write((char*)&c,sizeof(c));
  cout<<"\tRECORD MODIFIED \n";
  c.cabdisplay2();
  flag=1;
  break;
 }
}
if(flag==0)
  cout<<"\tRecord Not Found";
 f.close();
 getch();
}

void intro()
{
    system("cls");
    cout<<"\n\n\n\n\n\n\n\n";
    cout<<"                |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n";
    cout<<"                ||----------------------------------------------------------------------------|| \n";
    cout<<"                ||  @@      @@  @@@@@@@@   @@      @@@@@@@   @@@@@@    @@       @@   @@@@@@@@ || \n";
    cout<<"                ||  @@      @@  @@         @@      @@       @@    @@   @@ @   @ @@   @@       || \n";
    cout<<"                ||  @@  @   @@  @@@@@      @@      @@       @@    @@   @@   @   @@   @@@@@    || \n";
    cout<<"                ||  @@ @  @ @@  @@         @@      @@       @@    @@   @@       @@   @@       || \n";
    cout<<"                ||  @@      @@  @@@@@@@@   @@@@@@  @@@@@@@   @@@@@@    @@       @@   @@@@@@@@ || \n";
    cout<<"                ||----------------------------------------------------------------------------|| \n";
    cout<<"                |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||| \n";
    cout<<"\n\n\n";
    getch();
}

int main()
{
    //intro();
    int choice, c, i;
    char p[20];
    int d, c1, c2, c3;
    //aread2();
    //cabs c;
    start:
	    system("cls");
	    cout<<"\n\n\n\n\n";
	    cout<<"\t\t===========================================================================================\n";
	    cout<<"\t\t\t\t\t\t    * * * * * * * * * \n";
        cout<<"\t\t\t\t\t\t    *   MAIN MENU   * \n";
        cout<<"\t\t\t\t\t\t    * * * * * * * * * \n";
        cout<<"\t\t===========================================================================================\n";
        cout<<"\n\n\t\t\t\t 1. LOCATIONS";
        cout<<"\n\t\t\t\t 2. CABS";
        cout<<"\n\t\t\t\t 3. CUSTOMERS";
        cout<<"\n\t\t\t\t 4. EXIT";
        cout<<"\n\t\t\t\t    CHOICE:";
        cin>>choice;
        switch(choice)
        {
            case 1:   cout<<"\n\n\n\n"<<setw(50)<<" PLEASE ENTER THE PASSWORD ";
                       i=0;
                      char ch;
                      ch=getch();
                      p[0]=ch;
                      while(ch!=char(13))
                      {
                            cout<<"*";
                            ch=getch();
                            if(ch==char(13))
                                break;
                            i++;
                            p[i]=ch;
                      }
                      p[++i]='\0';
                      //cout<<p;
                      if(strcmp(p,"cabss123")!=0)	  //password is "cabss123"
                      {
                         cout<<"\n\n\n"<<setw(50)<<"  WRONG PASSWORD ";
                         cout<<"\n\t\t......access denied......\t\t\n";
                         getch();
                         exit(0);
                      }
                      tkk:
                         system("cls");
                         cout<<"\n\n\n\n\n\t"<<setw(45)<<" MENU \n";
                         cout<<"\n\t================================================================================\n";
                         cout<<"\t\t\t\t\t\t\t\t 1. ADDING LOCATION TO THE LIST\n";
                         cout<<"\t\t\t\t\t\t\t\t 2. DISPLAYING LOCATION ON THE LIST\n";
                        //cout<<setw(48)<<" 3. MODIFYING ANY MOVIE DETAILS\n";
                        //cout<<setw(36)<<" 4. DELETING MOVIE \n";
                        //cout<<setw(49)<<" 5. SEEING THE WEEK'S MOVIE LIST\n";
                         cout<<"\t\t\t\t\t\t\t\t 3. RETURN TO MAIN MENU\n";
                         cout<<"\t\t\t\t\t\t\t\t CHOICE=";
                         cin>>c1;
                         switch(c1)
                         {
                             case 1: system("cls");
                                     goto tkk;
                             case 2: system("cls");
                                     goto tkk;
                             case 3: system("cls");
                                     goto start;
                         }
                    //cout<<"hi";
                    break;
            case 2:
                    ttk:
                         system("cls");
                         cout<<"\n\n\n\n\n\n\t\t"<<setw(45)<<" MENU \n";
                         cout<<"\n\t\t===================================================================================\n";
                         cout<<"\n\t\t\t\t\t"<<" 1. ADDING CABS TO THE LIST\n";
                         cout<<"\t\t\t\t\t"<<" 2. END RIDE\n";
                         cout<<"\t\t\t\t\t"<<" 3. MODIFYING CAB DETAILS\n";
                         cout<<"\t\t\t\t\t"<<" 4. DELETING CABS \n";
                         cout<<"\t\t\t\t\t"<<" 5. DISPLAY CAB DETAILS\n";
                         cout<<"\t\t\t\t\t"<<" 6. DISPLAY DRIVER DETAILS\n";
                         cout<<"\t\t\t\t\t"<<" 7. DISPLAY RIDE DETAILS\n";
                         cout<<"\t\t\t\t\t"<<" 8. RETURN TO MAIN MENU\n";
                         cout<<"\t\t\t\t\t"<<" CHOICE=";
                         cin>>c2;
                         switch(c2)
                         {
                             case 1: system("cls");
                                     append();
                                     goto ttk;
                             case 2: system("cls");

                                     goto ttk;
                             case 3: system("cls");
                                     amodify();
                                     goto ttk;
                             case 4: system("cls");
                                     adelete();
                                     goto ttk;
                             case 5: system("cls");
                                     aread1();
                                     goto ttk;
                             case 6: system("cls");
                                     aread2();
                                     goto ttk;
                             case 7: system("cls");
                                     //aread2();
                                     goto ttk;
                             case 8: system("cls");
                                     goto start;
                         }
                     break;
            case 3:
                     tk:
                         system("cls");
                         cout<<"\n\n\n\n\n\n\t\t"<<setw(45)<<" MENU \n";
                         cout<<"\n\t\t===================================================================================\n";
                         cout<<"\n\t\t\t\t\t"<<" 1. ADDING CUSTOMER ACCOUNT\n";
                         cout<<"\t\t\t\t\t"<<" 2. START RIDE\n";
                         cout<<"\t\t\t\t\t"<<" 3. MODIFYING CUSTOMER DETAILS\n";
                         cout<<"\t\t\t\t\t"<<" 4. DELETING CUSTOMER ACCOUNT \n";
                         cout<<"\t\t\t\t\t"<<" 5. DISPLAY CUSTOMER ACCOUNTS\n";
                         cout<<"\t\t\t\t\t"<<" 6. DISPLAY CUSTOMER RIDES\n";
                         cout<<"\t\t\t\t\t"<<" 7. RETURN TO MAIN MENU\n";
                         cout<<"\t\t\t\t\t"<<" CHOICE=";
                         cin>>c3;
                         switch(c3)
                         {
                             case 1: system("cls");
                                     append();
                                     goto tk;
                             case 2: system("cls");

                                     goto tk;
                             case 3: system("cls");
                                     amodify();
                                     goto tk;
                             case 4: system("cls");
                                     adelete();
                                     goto tk;
                             case 5: system("cls");
                                     aread1();
                                     goto tk;
                             case 6: system("cls");
                                     aread2();
                                     goto tk;
                             case 7: system("cls");
                                     goto start;
                         }
                     break;
            case 4:  getch();
                     exit(0);


        }
//    c.cabdisplay1();
  //  c.driverdisplay();
    return 0;
}
