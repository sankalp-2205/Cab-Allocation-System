#include<bits/stdc++.h>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<cstdio>
#include<time.h>
#include<conio.h>
using namespace std;
struct ride
{
    char sloc[30], floc[30];
    int dd, mm, yyyy;
    int hr, mins, secs;
    //cabs *c;
    int id;
    float fare;
};
class customer
{
    char custname[50];
    int custid;
    int trides;
    int bd, bm, by;
    char gender;
    char phone[11];
    char password[15];
    ride *r;

    public: customer()
            {
                trides=0;
                r=NULL;
            }
            void getcustdets()
            {
                cout<<"\n\n\n\n\n";
                cout<<"      --------------------------------------------------------------------------------------------------------\n\n";
                cout<<"\t\t\t\t ENTER CUSTOMER DETAILS\n\n";
                cout<<"      --------------------------------------------------------------------------------------------------------\n\n";
                cout<<"\t\t\t ENTER USER ID:";
                cin>>custid;
                cin.get();
                cout<<"\t\t\t ENTER USER NAME:";
                gets(custname);
                cout<<"\t\t\t ENTER GENDER:";
                cin>>gender;
                cout<<"\t\t\t ENTER DOB:";
                cin>>bd>>bm>>by;
                cout<<"\t\t\t ENTER PHONE NO.:";
                cin>>phone;
                cout<<"\t\t\t ENTER PASSWORD:";
                cin>>password;
                /*cout<<"\t\t\t ENTER PASSWORD:";
                cin>>password;*/
            }
            void modify()
            {
                int k, l;
                char cpass[15];
                cout<<"\n\t\t CUSTOMER DETAILS ";
                cout<<"\n\t CUSTOMER ID: "<<custid;
                cout<<"\n\t CUSTOMER NAME: "<<custname;
                cout<<"\n\t PHONE NO.: "<<phone;
                cout<<"\t\t DOB: "<<bd<<"-"<<bm<<"-"<<by;
                cout<<"\t\t GENDER: "<<gender;
                cout<<"\n\t DO YOU WANT TO CHANGE THE PHONE NO.(0 to retain old): ";
                cin>>k;
                if(k!=0)
                    {
                        cout<<"\n\t ENTER NEW PHONE NO.: ";
                        cin>>phone;
                    }
                cout<<"\n\t DO YOU WANT TO CHANGE THE PASSWORD(0 to retain old): ";
                cin>>l;
                if(l!=0)
                {
                    check:
                    cout<<"\n\t ENTER OLD PASSWORD:";
                    cin>>cpass;
                    if(strcmp(cpass, password)==0)
                    {
                        cout<<"\t ENTER NEW PASSWORD:";
                        cin>>password;
                    }
                    else
                    {
                        cout<<" ******** ERROR!!! PASSWORD DOES NOT MATCH!! TRY AGAIN! **************** ";
                        goto check;
                    }
                }
            }
            int retcustid()
            {
                return custid;
            }
            char* retpassword()
            {
                return password;
            }
            ride* retridedets()
            {
                return r;
            }
            char retgend()
            {
                return gender;
            }
            void custdisp()
            {
                cout<<"\n"<<setw(16)<<custid<<setw(24)<<custname<<setw(10)<<gender<<setw(12)<<bd<<"-"<<bm<<"-"<<by<<setw(19)<<phone<<setw(11)<<trides;
            }
};

void custaread()
{
 fstream f("customers.dat",ios::in|ios::binary);
 customer c;
 system("cls");
 cout<<"\n\t\t\t\t   \n\n";
cout<<"      ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ CUSTOMER'S LIST ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\n";
 cout<<setw(15)<<"ID"<<setw(20)<<"NAME"<<setw(17)<<"GENDER"<<setw(18)<<"BIRTH DATE"<<setw(17)<<"PHONE NO."<<setw(18)<<"TOTAL RIDES\n\n";
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
  c.custdisp();
 }
 getch();
 return;
}
void custappend()
{
 char ans='y';
 customer c;
 fstream f("customers.dat",ios::binary|ios::out|ios::app);
  if(!f)
 {
  cout<<"\t CAN'T PROCEED\t";
  getch();
  exit(0);
 }
 while(ans=='y'||ans=='Y')
 {
  c.getcustdets();
  f.write((char*)&c,sizeof(c));
  cout<<"\n RECORD ADDED \n \t DO YOU WISH TO CONTINUE?";
  cin>>ans;
 }
 f.close();
}
void custadelete()
{
 fstream temp,f;
 f.open("customers.dat",ios::in|ios::binary);
 temp.open("temp.dat",ios::out|ios::binary);
  if(!f||!temp)
 {
  cout<<"\n\t CAN'T PROCEED";
  getch();
  exit(0);
 }
 char nm[50],ans3;
 customer c;
 int k;
 int flag=0;
 //custaread();
 cout<<"\n\n\t ENTER CUSTOMER ID OF THE CUSTOMER WHOSE ACCOUNT IS TO BE DELETED:";
 cin>>k;
 while(f)
 {
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  {
      getch();
      break;
  }
  if(c.retcustid()==k)
  {
   cout<<"\n\t\tTHE DETAILS ARE....\n";
   c.custdisp();
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
remove("customers.dat");
rename("temp.dat","customers.dat");
  if(flag==0)
  cout<<"\n\t record not found\t\n";
  f.close();
 }

void custamodify()
{
 int flag=0, k;
 char cpass[15];
 customer c;
 fstream f;
 f.open("customers.dat",ios::in|ios::out|ios::binary);
 if(!f)
 {
  cout<<"Cannot proceed. Exitting..";
  getch();
  exit(0);
 }
 //custaread();
 cout<<"\n\n\tENTER ID OF CUSTOMER WHOSE DETAILS ARE TO BE MODIFIED: ";
 cin>>k;
int p;
 while(f)
{
  p=f.tellg();
  f.read((char*)&c,sizeof(c));
  if(f.eof())
  { break;  }
   if(c.retcustid()==k)
 {
    cout<<"\n\t RECORD FOUND \t\n";
    flag=1;
    check2:
    cout<<"ENTER PASSWORD TO ACCOUNT:";
    cin>>cpass;
    if(strcmp(cpass, c.retpassword())==0)
    {
        c.modify();
        f.seekg(p,ios::beg);
        f.write((char*)&c,sizeof(c));
        cout<<"\tRECORD MODIFIED \n";
        c.custdisp();
        break;
    }
    else
    {
        cout<<"********** ERROR WRONG PASSWORD!! RETRY!!! ***********";
        goto check2;
    }
 }
}
if(flag==0)
  cout<<"\tRecord Not Found";
 f.close();
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
                      if(strcmpi(p,"cabss123")!=0)	  //password is "cabss123"
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
                         /*cout<<"\n\t\t===================================================================================\n";
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
                         }*/
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
                                     custappend();
                                     goto tk;
                             case 2: system("cls");

                                     goto tk;
                             case 3: system("cls");
                                     custamodify();
                                     goto tk;
                             case 4: system("cls");
                                     custadelete();
                                     goto tk;
                             case 5: system("cls");
                                     custaread();
                                     goto tk;
                             /*case 6: system("cls");
                                     aread2();
                                     goto tk;*/
                             case 7: system("cls");
                                     goto start;
                         }
                     break;
            case 4:  getch();
                     exit(0);


        }
    return 0;
}
