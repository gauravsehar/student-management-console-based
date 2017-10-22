//Made By Gaurav Sehar
#include<iostream>
#include<fstream>
#include<process.h>
#include<conio.h>
#include"dos.h"
#include<stdio.h>
#include<string.h>
#include<iomanip>

void main();
void menu(int );
fstream stud;
int checkroll;

/*set cursor  type according to requirement and calling conditions*/
int cursor(int c){
 if(c==0)
  _setcursortype(_NOCURSOR);
 else if(c==1)
  _setcursortype(_NORMALCURSOR);
 else if(c==2)
  _setcursortype(_SOLIDCURSOR);
return c;}

/*Print Border And Date*/
void border(int length,int breath,int posx,int posy){
 textattr(15);
 length-=1;breath-=1;
 gotoxy(posx,posy);
 for(int i=1;i<length;i++){gotoxy(i+posx,posy);
  cprintf("Ä");}
 for(i=1;i<breath;i++){gotoxy(posx+length,i+posy);
  cprintf("³");}
 for(i=1;i<breath;i++){gotoxy(posx,i+posy);
  cprintf("³");}
 for(i=1;i<length;i++){gotoxy(posx+i,posy+breath);
  cprintf("Ä");}
 gotoxy(posx,posy);
  cprintf("Ú");
 gotoxy(posx+length,posy);
  cprintf("¿");
 gotoxy(posx,posy+breath);
  cprintf("À");
 if(length<79){gotoxy(posx+length,posy+breath);
  cprintf("Ù");}
 if(breath==24&&length==79){
  gotoxy(69,1);
  textattr(8);
   cprintf(__DATE__);}
 gotoxy(80,25);
 textattr(15);}


/*Instructions to run program*/
void term(){
 clrscr();
 border(80,25,1,1);
 gotoxy(30,2);
  cout<<"TERM BEFORE EXECUTING";
 gotoxy(8,5);
 textattr(12);
  cprintf("Please Don't Press Any key Unnecessarily When Program Is Executing");
 gotoxy(30,6);
  cprintf("It Will Ruin The Output.");
 gotoxy(23,11);
 cout<<"This Program Can Handle Subjects In";
 gotoxy(20,12);
 cout<<"Non-Med, Med, Commerce With I.P And Maths";
 gotoxy(35,13);
 cout<<"Streams Only";
 gotoxy(25,20);
  cout<<"Press         to start the Program.";
 gotoxy(31,20);
 textattr(14);
  cprintf("Any Key");
 textattr(15); gotoxy(80,25);getch();}

/*Welcome to program and display coder name and class*/
void splash(){
 clrscr();
 gotoxy(1,1);
   cout<<"\n\t   ÛÛ      ÛÛ ÛÛÛÛÛÛÛ ÛÛ      ÛÛÛÛÛÛ  ÛÛÛÛÛÛ ÛÛÛ  ÛÛÛ ÛÛÛÛÛÛÛ";
   cout<<"\n\t   ÛÛ      ÛÛ ÛÛ      ÛÛ      ÛÛ      ÛÛ  ÛÛ ÛÛ ÛÛ ÛÛ ÛÛ";
   cout<<"\n\t   ÛÛ  ÛÛ  ÛÛ ÛÛÛÛÛ   ÛÛ      ÛÛ      ÛÛ  ÛÛ ÛÛ ÛÛ ÛÛ ÛÛÛÛÛ";
   cout<<"\n\t   ÛÛ  ÛÛ  ÛÛ ÛÛ      ÛÛ      ÛÛ      ÛÛ  ÛÛ ÛÛ    ÛÛ ÛÛ";
   cout<<"\n\t   ÛÛÛÛÛÛÛÛÛÛ ÛÛÛÛÛÛÛ ÛÛÛÛÛÛÛ ÛÛÛÛÛÛ  ÛÛÛÛÛÛ ÛÛ    ÛÛ ÛÛÛÛÛÛÛ";
   cout<<"\n\n\t\t\t        ÛÛÛÛÛÛÛÛ  ÛÛÛÛÛ";
   cout<<"\n\t\t\t           ÛÛ     Û   Û";
   cout<<"\n\t\t\t           ÛÛ     ÛÛÛÛÛ";
 gotoxy(31,12);
   cout<<"COMPUTER    PROJECT";
 gotoxy(39,14);
   cout<<"MADE";
 gotoxy(40,16);
   cout<<"BY";
 gotoxy(35,18);
  textattr(9);
   cprintf("Gaurav Sehar");
  textattr(15);
 gotoxy(40,20);
   cout<<"Of";
 gotoxy(35,22); cout<<"Class  XII-B"; }
/*Display short description of program with name of teacher*/
void intro(){
 clrscr();
 border(80,25,1,1);
 gotoxy(15,4);
  cout<<"ANNUAL REPORT CARD MANAGEMENT SYSTEM PROJECT 2014-15";
 gotoxy(32,9);
   cout<<"Under Guidance Of";
 gotoxy(36,14);
  textattr(13);
   cprintf("Pooja Mam");
  textattr(15);
 gotoxy(25,20);
   cout<<"Our Teacher Of Computer Science";
 gotoxy(80,25);}

/*Make user to wait and see instruction from program */
void wait_maker(int w){
 textattr(8);
 for(int i=w;i>=0;i--){gotoxy(2,24);cprintf("Wait for ");
 if(i==1||i==0){cout<<"1";cprintf(" Second Don't Press Any key ");}
 else {cout<<i;cprintf(" Seconds Don't Press Any Key");}
 gotoxy(80,25);
 if(i>0)sleep(1);
 else sleep(1);}
 textattr(15); }

class passfile_processor{
 int i;
 char n[5],r[5],t[5];

/*check whether password file present on disk or not*/
int passfile_checker(){
 ifstream passcheck("spass.seh",ios::binary,ios::nocreate);
 if(!passcheck) {return 0;}
 else {passcheck.close();return 1;}}

/*Write password to file after accepting password from user*/
void pass_writer(){
 gotoxy(38,15);
 ofstream change("spass.seh",ios::binary);
 n[0]=getch();cout<<n[0];
 n[1]=getch();cout<<n[1];
 n[2]=getch();cout<<n[2];
 n[3]=getch();cout<<n[3];
 n[4]=getch();cout<<n[4];
 gotoxy(38,15);
  cout<<"SAVED";
 change.write((char*)&n,sizeof(n));change.close();wait_maker(3);}
/*If no pass file exist it request for master password and compare it*/
int mastercheck(){
 textattr(14);
 gotoxy(28,10);
  cprintf("Fail To Open Password File");
 gotoxy(27,11);
  cprintf("Enter Master Reset Password.");
 textattr(15);
 gotoxy(38,15);
  t[0]=getch();cout<<"";
  t[1]=getch();cout<<"";
  t[2]=getch();cout<<"";
  t[3]=getch();cout<<"";
  t[4]=getch();cout<<"";
 if( (t[0]==char(115)||t[0]==char(83))&&(t[1]==char(101)||t[1]==char(69))&&(t[2]==char(104)||t[2]==char(72))&&(t[3]==char(97)||t[3]==char(65))&&(t[4]==char(114)||t[4]==char(82)))
  return 1;
 else return 0;}

/*If pass file exist it request for password and compare it from password in file*/
int filecheck(){
 gotoxy(38,15);
  t[0]=getch();cout<<"";
  t[1]=getch();cout<<"";
  t[2]=getch();cout<<"";
  t[3]=getch();cout<<"";
  t[4]=getch();cout<<"";
 ifstream pass("spass.seh",ios::binary,ios::nocreate);
  pass.seekg(0);
  pass.read((char*)&r,sizeof(r));
 if((r[0]==t[0])&&(r[1]==t[1])&&(r[2]==t[2])&&(r[3]==t[3])&&(r[4]==t[4]))
  {pass.close();return 1;}
 else
  {pass.close();return 0;}}

/*it prints the format of screen which deals with password */
void format(){
 clrscr();
 border(80,25,1,1);
 gotoxy(30,2);
  cout<<"ÉÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ»";
 gotoxy(30,3);
  cout<<"º ENTER     PASSWORD º";
 if(i==1){
  textattr(14);
  gotoxy(38,3);
   cprintf("NEW");
  textattr(15);}
 else{
  gotoxy(38,3);
  cout<<"THE";  }
  gotoxy(30,4);
  cout<<"ÈÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¼";
 gotoxy(35,14);
  cout<<"ÕÍÍÍÍÍÍÍÍÍ¸";
 gotoxy(35,15);
  cout<<"³         ³";
 gotoxy(35,16);
  cout<<"ÔÍÍÍÍÍÍÍÍÍ¾";
  textattr(11);
  gotoxy(15,18);
   cprintf("CASE SENSITIVE { Password Length 5 Characters Only. }");
  textattr(15);  }

public:

/*initializing constructor*/
passfile_processor(){i=0;}

/*change existing password present in file or create new file*/
void passfile_changer(){
 i=1;
 format();
 pass_writer();
  i=0;
  menu(18); }

/*it calls the  filecheck() or mastercheck() according to existence of password file present in disk or not*/
int getpass(){
 format();
 if(!passfile_checker())
  return mastercheck();
 else
  return filecheck(); }

/*It calls the getpass() and give chances to user according to password is correct or not*/
void validater(){
 if(!getpass()){
  textattr(12);gotoxy(32,3);
   cprintf("  Think Once More  ");
  gotoxy(38,15);
   cprintf("");
  textattr(15); wait_maker(3);
 if(!getpass()){
  clrscr();border(80,25,1,1);
  gotoxy(21,10);textattr(12); cprintf("Invalid Password, Press Any Key To Exit.");
  textattr(15); gotoxy(80,25); getch();exit(105);}}}}p;
/*it display exit message to user and exit from program*/
void exiter(){
 clrscr();
 border(80,25,1,1);
  gotoxy(33,1);
  cout<<" EXIT SCREEN ";
 gotoxy(20,4);
  cout<<"NOW YOU ARE GOING TO EXIT THE PROGRAM";
 gotoxy(20,10);
 textattr(10);
  cprintf("HOPE YOU WILL LOVE THIS PROGRAM !!!.....");
 gotoxy(22,12);
  cprintf("Remember. The Coder Is Gaurav Sehar...");
 gotoxy(25,20);
  cout<<"Press         to exit the Program.";
 gotoxy(31,20);
 textattr(14);
  cprintf("Any Key");
 textattr(15);
 gotoxy(80,25);
 getch();
 exit(0);}

/*it display information in information panel of program*/
void message(int message){
char *info[] = {"PLEASE PRESS NUMBER DISPLAYING AGAINST THEIR COMMAND.         ",
		"STUDENT RECORD HAS BEEN CREATED.                             ",
		"STUDENT RECORD HAS BEEN MODIFIED.                            ",
		"STUDENT RECORD HAS BEEN DELETED.                             ",
		"RECORD FOUND; WANT TO DELETE PRESS [Y/N]                      ",
		"STUDENT RECORD HAS BEEN SEARCHED.                            ",
		"WANT TO MODIFY OTHER FIELD PRESS [Y/N]                        ",
		"STUDENT RECORD NOT FOUND..!!!                                 ",
		"YOU HAVE PRESSED A WRONG KEY, COOL DOWN AND THINK AGAIN.      ",
		"ENTER ROLL NUMBER TO MODIFY THE RECORD...                     ",
		"ENTER ROLL NUMBER TO DELETE THE RECORD...                     ",
		"ENTER ROLL NUMBER TO SEARCH THE RECORD...                     ",
		"PRESS ANY KEY TO PROCEED FURTHER...                           ",
		"RECENTLY YOU SEE THE RECORD OF ALL STUDENTS.                  ",
		"SUCCESSFULLY REMOVED ALL DATABASE FILES, PRESS ANY KEY TO EXIT",
		"NO DATABASE EXISTS. CHOOSE OPTION 1 TO CREATE NEW DATABASE.    ",
		"ARE YOU SURE??? IF YES TYPE {S}.....                        ",
		"DATABASE NOT DELETED. NOW OLD DATABASE WILL CONTINUE...       ",
		"RECENTLY YOU HAVE CHANGED THE PASSWORD.                       ",
		"ENTER NUMBER TO MODIFY SPECIFIC FIELD.                        ",
		"NOW ENTER NEW FIELD TO MODIFY EXISTING RECORD.                ",
		"YOU DO NOT MODIFY STUDENT RECORD.                           ",
		"Now... Press Any Key to Proceed. For Main Menu Press {*}...   ",
		"MARKS NOT IN RANGE. NO RECORD IS CREATED...   {Press Any Key} ",
		"MARKS SHOULD BE IN RANGE OF 0 TO 100.                         ",
		"NOW THE MODIFIED RECORD IS SHOWNED, Press Any Key For Main Menu",
		"RECENTLY YOU SEE MARKING SCHEME OF THE PROGRAM.               ",
		"RECENTLY YOU SUSPEND THE CREATION OF STUDENT RECORD.          ",
		"YOU ENTERED WRONG DETAILS IN CREATION OF STUDENT RECORD.      "};
  border(78,3,2,22);
  textattr(14);
if (message!=0||message==8){
  gotoxy(3,23);
  cprintf("Information ");
  gotoxy(17,23);
  cprintf("                                                              ");}
  delay(500);
  gotoxy(3,23);
  cprintf("Information ");
  if(message==0){textattr(10);}
  else if(message==6||message==7||message==15){textattr(13);}
  else if(message==8){textattr(12);}
  else{textattr(11);}
  gotoxy(17,23);
  cprintf(info[message]);
  textattr(15);
  gotoxy(77,23); }

/*it display making scheme used by program*/
void markscheme(){
clrscr();
textattr(15);
gotoxy(15,6);
 cout<<"Grade       Marks Range\n";
 cout<<"\t\tA+ \t    91 100\n";
 cout<<"\t\tA  \t    81 90\n";
 cout<<"\t\tB+ \t    71 80\n";
 cout<<"\t\tB  \t    61 70\n";
 cout<<"\t\tC+ \t    51 60\n";
 cout<<"\t\tC  \t    41 50\n";
 cout<<"\t\tD  \t    33 40\n";
 cout<<"\t\tF  \t     0 32\n";
border(80,25,1,1);
gotoxy(32,1);
 cout<<" Marking Scheme ";
message(12);
getch();
menu(26);}

class student{
 char name[20],gpref,gsuff,opt,add;
 float tot_m,per,m1,m2,m3,m4,m5,m6;
 int rollno;
/*it assign stream to student*/
void stream_assigner(){
 clrscr();
 border(80,25,1,1);
 for(int c=0,n=1;c<=6;c+=2,n++){
 gotoxy(56,c+8);cout<<"Ä";
 gotoxy(56,c+7);cout<<n;}
 gotoxy(31,1);
  cout<<" Stream Assigner ";
 gotoxy(12,4);
  cout<<"Enter Stream Of Student";
 border(42,9,16,6);
 gotoxy(17,7);
  cout<<"Non-Medical .........................";
 border(3,9,55,6);
 gotoxy(17,9);
  cout<<"Medical  [With Maths] ...............";
 gotoxy(17,11);
  cout<<"Commerce [With Maths] ...............";
 gotoxy(17,13);
  cout<<"Commerce  [With I.P] ................";
 gotoxy(80,25);
G:
 message(0); textattr(14);opt=getch();
 switch(opt){
   case '1' :  gotoxy(56,7); cprintf("û");    break;
   case '2' :  gotoxy(56,9); cprintf("û");    break;
   case '3' :  gotoxy(56,11);cprintf("û");    break;
   case '4' :  gotoxy(56,13);cprintf("û");    break;
   default  :  message(8);wait_maker(2);     goto G;}
 for(c=0,n=49;c<=6;c+=2,n++){gotoxy(56,c+7);
   if(n!=int(opt))
   {cout<<"þ";}}
S:
 border(42,11,16,6);
 gotoxy(17,15);
  cout<<"Is Student Having Physical Education      Press [Y/N] Only";
 border(3,11,55,6);
 cursor(2);
 gotoxy(56,15);
 textattr(14);
 add=getch();
 switch(add){
   case 'Y' :  gotoxy(56,15);cprintf("û");    break;
   case 'y' :  gotoxy(56,15);cprintf("û");    break;
   case 'N' :  gotoxy(56,15);cprintf("x");    break;
   case 'n' :  gotoxy(56,15);cprintf("x");    break;
   default  :  message(8);                   goto S;}
 gotoxy(80,25); message(22);char o=getch();if(o=='*'){menu(27);}}
/*it save current roll no to file on disk and increment on creation of new record*/
void rollassign(){
 ifstream r("lastroll.seh",ios::binary);
  r.read((char*)&rollno,sizeof(rollno));
  rollno++;
 r.close();
 ofstream n("lastroll.seh",ios::binary);
  n.write((char*)&rollno,sizeof(rollno));
 n.close();}

/*it calculate percentage of student according to its subject*/
void percalc(){
 if(add=='N'||add=='n'){
  tot_m=(m1+m2+m3+m4+m5);
  per=(tot_m/500)*100;}
 else if(add=='Y'||add=='y'){
  tot_m=(m1+m2+m3+m4+m5+m6);
  per=(tot_m/600)*100;}}

 /*it check and save marks to variables*/
void marksvalidater(int v,int m){
 if(v==1||v==2||v==3||v==4||v==5||v==6){
  if(m<=100&&m>=0){
   if(v==1){m1=m;}
   else if(v==2){m2=m;}
   else if(v==3){m3=m;}
   else if(v==4){m4=m;}
   else if(v==5){m5=m;}
   else if(v==6){m6=m;}}
  else{
   message(23);
   getch();
   menu(28);}}}

/*it assign grade according to the marks of student*/
void analyser(){
 gsuff=' ';
      if(per>90){gpref='A';gsuff='+';}
 else if(per>=81 && per<=90){gpref='A';}
 else if(per>=71 && per<=80){gpref='B';gsuff='+';}
 else if(per>=61 && per<=70){gpref='B';}
 else if(per>=51 && per<=60){gpref='C';gsuff='+';}
 else if(per>=41 && per<=50){gpref='C';}
 else if(per>=33 && per<=40){gpref='D';}
 else {gpref='F';}}




/*it provide user interface for user to accept details of student*/
void getformat(){
 clrscr();
 border(80,25,1,1);
 textattr(11);
 gotoxy(5,4);
  cprintf("Enter Name Of Student  ................. ");gets(name);
 gotoxy(10,1);
 textattr(10);
  cprintf(" CREATING ANNUAL RECORD OF ... ");cout<<name<<" ";
 message(24);
 gotoxy(5,6);
  if(opt=='1'||opt=='2'){
   cprintf("Enter Marks Of ");cout<<name;cprintf(" in Physics ............");}
  else if(opt=='3'||opt=='4'){
   cprintf("Enter Marks Of ");cout<<name;cprintf(" in Accounts ...........");}
 gotoxy(5,8);
  if(opt=='1'||opt=='2'){
   cprintf("Enter Marks Of ");cout<<name;cprintf(" in Chemistry ..........");}
  else if(opt=='3'||opt=='4'){
   cprintf("Enter Marks Of ");cout<<name;cprintf(" in Business Studies ...");}
 gotoxy(5,10);
  if(opt!='4'){
   cprintf("Enter Marks Of ");cout<<name;cprintf(" in Mathematics ........");}
  else if(opt=='4'){
   cprintf("Enter Marks Of ");cout<<name;cprintf(" in I.P ................");}
 gotoxy(5,12);
  if(opt=='1'){
   cprintf("Enter Marks Of ");cout<<name;cprintf(" in Computer Science ...");}
  else if(opt=='2'){
   cprintf("Enter Marks Of ");cout<<name;cprintf(" in Biology ............");}
  else if(opt=='3'||opt=='4'){
   cprintf("Enter Marks Of ");cout<<name;cprintf(" in Economics ..........");}
 gotoxy(5,14);
  cprintf("Enter Marks Of ");cout<<name;cprintf(" in English ............");
 gotoxy(5,16);
  if(add=='Y'||add=='y'){
   cprintf("Enter Marks Of ");cout<<name;cprintf(" in Physical Edu. ......");}
 textattr(15);}

/*it display details of student*/
void putformat(){
 clrscr();
 int fc=0;
 border(80,25,1,1);
 textattr(11);
 gotoxy(10,1);
 textattr(10);
  cprintf(" SHOWING ANNUAL RECORD OF ... ");cout<<name<<" ";
 textattr(11);
 gotoxy(5,4);
  cprintf("Roll No. Assigned To ");cout<<name;cprintf(" Is .....");
 gotoxy(5,6);
  if(opt=='1'||opt=='2'){
   cprintf("Marks Of ");cout<<name;cprintf(" in Physics ............");}
  else if(opt=='3'||opt=='4'){
   cprintf("Marks Of ");cout<<name;cprintf(" in Accounts ...........");}
 gotoxy(5,8);
  if(opt=='1'||opt=='2'){
   cprintf("Marks Of ");cout<<name;cprintf(" in Chemistry ..........");}
  else if(opt=='3'||opt=='4'){
   cprintf("Marks Of ");cout<<name;cprintf(" in Business Studies ...");}
 gotoxy(5,10);
  if(opt!='4'){
   cprintf("Marks Of ");cout<<name;cprintf(" in Mathematics ........");}
  else if(opt=='4'){
   cprintf("Marks Of ");cout<<name;cprintf(" in I.P ................");}
 gotoxy(5,12);
  if(opt=='1'){
   cprintf("Marks Of ");cout<<name;cprintf(" in Computer Science ...");}
  else if(opt=='2'){
   cprintf("Marks Of ");cout<<name;cprintf(" in Biology ............");}
  else if(opt=='3'||opt=='4'){
   cprintf("Marks Of ");cout<<name;cprintf(" in Economics ..........");}
 gotoxy(5,14);
  cprintf("Marks Of ");cout<<name;cprintf(" in English ............");
 gotoxy(5,16);
  if(add=='Y'||add=='y'){
   fc=2;
   cprintf("Marks Of ");cout<<name;cprintf(" in Physical Edu. ......");}
 gotoxy(5,16+fc);
  cprintf("Total Marks gained by ");cout<<name;cprintf(" ..................");
 gotoxy(5,17+fc);
  cprintf("Annual Passing per of ");cout<<name;cprintf(" ..................");
 gotoxy(5,18+fc);
  cprintf("Grade Secured by ");cout<<name;cprintf(" ...............");
 textattr(15);}

/*it display modifiable details of student */
void modformat(){
 clrscr();
 border(80,25,1,1);
 textattr(11);
 gotoxy(5,4);
  cout<<"1¯ ";cprintf("Name Of Student  .................. ");cout<<name;
 gotoxy(10,1);
 textattr(10);
  cprintf(" MODIFING ANNUAL RECORD OF ... ");cout<<name<<" ";
 textattr(11);
 gotoxy(5,6);
  cout<<"þ¯ ";cprintf("Roll Number Of ");cout<<name;cprintf(" ................. ");
 cout<<rollno;
 gotoxy(5,8);
  cout<<"2¯ ";
 if(opt=='1'||opt=='2'){
  cprintf("Marks Of ");cout<<name;cprintf(" in Physics .............");}
 else if(opt=='3'||opt=='4'){
  cprintf("Marks Of ");cout<<name;cprintf(" in Accounts ............");}
 cout<<m1;
 gotoxy(5,10);
  cout<<"3¯ ";
 if(opt=='1'||opt=='2'){
  cprintf("Marks Of ");cout<<name;cprintf(" in Chemistry ...........");}
 else if(opt=='3'||opt=='4'){
  cprintf("Marks Of ");cout<<name;cprintf(" in Business Studies ....");}
 cout<<m2;
 gotoxy(5,12);
  cout<<"4¯ ";
 if(opt!='4'){
  cprintf("Marks Of ");cout<<name;cprintf(" in Mathematics .........");}
  else if(opt=='4'){
  cprintf("Marks Of ");cout<<name;cprintf(" in I.P .................");}
 cout<<m3;
 gotoxy(5,14);
  cout<<"5¯ ";
  if(opt=='1'){
  cprintf("Marks Of ");cout<<name;cprintf(" in Computer Science ...");}
 else if(opt=='2'){
  cprintf("Marks Of ");cout<<name;cprintf(" in Biology .............");}
 else if(opt=='3'||opt=='4'){
  cprintf("Marks Of ");cout<<name;cprintf(" in Economics ...........");}
 cout<<m4;
 gotoxy(5,16);
  cout<<"6¯ ";cprintf("Marks Of ");cout<<name;cprintf(" in English ............ ");cout<<m5;
 gotoxy(5,18);
 if(add=='Y'||add=='y'){
  cout<<"7¯ ";cprintf("Marks Of ");cout<<name;cprintf(" in Physical Edu. ...... ");cout<<m6;}
 gotoxy(4,21);
 cout<<"You May Press Any Other Key Which is Not Specified to Suspend Modification";
 textattr(15);}







/*display modifiable marks to user*/
void modrecord(char n){
 int len=strlen(name),marks;
 if(n=='1'){
  message(20);gotoxy(45+len,4);textattr(12);cprintf(" ");textattr(15);gets(name);}
 else if(n=='2'){
  message(20);gotoxy(45+len,8);textattr(12);cprintf(" ");textattr(15);
  cin>>marks;marksvalidater(1,marks);}
 else if(n=='3'){
  message(20);gotoxy(45+len,10);textattr(12);cprintf(" ");textattr(15);
  cin>>marks;marksvalidater(2,marks);}
 else if(n=='4'){
  message(20);gotoxy(45+len,12);textattr(12);cprintf(" ");textattr(15);
  cin>>marks;marksvalidater(3,marks);}
 else if(n=='5'){
  message(20);gotoxy(45+len,14);textattr(12);cprintf(" ");textattr(15);
  cin>>marks;marksvalidater(4,marks);}
 else if(n=='6'){
  message(20);gotoxy(45+len,16);textattr(12);cprintf(" ");textattr(15);
  cin>>marks;marksvalidater(5,marks);}
 else if(n=='7'&&add=='Y'||add=='y'){
  message(20);gotoxy(45+len,18);textattr(12);cprintf(" ");textattr(15);
  cin>>marks;marksvalidater(6,marks);}
 else
 menu(21);}

/*it display marks on marks displaying screen*/
void putrecord(){
 int len=strlen(name),fc=0;
 gotoxy(39+len,4);cout<<rollno;
 gotoxy(39+len,6);cout<<m1;
 gotoxy(39+len,8);cout<<m2;
 gotoxy(39+len,10);cout<<m3;
 gotoxy(39+len,12);cout<<m4;
 gotoxy(39+len,14);cout<<m5;
 if(add=='Y'||add=='y'){fc=2;gotoxy(39+len,16);cout<<m6;}
 gotoxy(47+len,16+fc);cout<<tot_m;
      if(add=='Y'||add=='y'){cout<<"/600";}
 else if(add=='N'||add=='n'){cout<<"/500";}
 gotoxy(47+len,17+fc);cout<<setprecision(3)<<per<<"%";
 gotoxy(39+len,18+fc);cout<<gpref<<gsuff; }








/*it accept marks and other details of student*/
void getrecord(){
 int len=strlen(name),marks;
gotoxy(45+len,6);cin>>marks;
 marksvalidater(1,marks);
gotoxy(45+len,8);cin>>marks;
 marksvalidater(2,marks);
gotoxy(45+len,10);cin>>marks;
 marksvalidater(3,marks);
gotoxy(45+len,12);cin>>marks;
 marksvalidater(4,marks);
gotoxy(45+len,14);cin>>marks;
 marksvalidater(5,marks);
 if(add=='Y'||add=='y'){
gotoxy(45+len,16);cin>>marks;marksvalidater(6,marks);}}

public:

/*return roll no*/
int rollret(){return rollno;}

/*it calls the functions required for creation of record*/
void get(){
 stream_assigner();
 getformat();
 getrecord();
 rollassign();
 percalc();
 analyser(); }

/*it calls the functions required for modification of record*/
void mod(){
 char n,rep='n';
 do{
  modformat();
  message(19);
  n=getch();
  modrecord(n);
  percalc();
  analyser();
  message(6);
  cin>>rep;
 }while(rep=='y'||rep=='Y');
 if(rep=='n'||rep=='N'){put(2);}}





/*it calls the functions required for display of record*/
void put(int msg){
 putformat();
 putrecord();
 if(msg==1)
 message(12);
 else if(msg==2){message(25);getch();}}
}stu;

/*write all details of student to the external file on disk*/
void filewrite(){
 stud.open("database.seh",ios::binary|ios::app);
 stu.get();
  stud.write((char*)&stu,sizeof(stu));
 stud.seekg(0);
 while(!stud.eof()){
  stud.read((char*)&stu,sizeof(stu));
  if(stu.rollret()==stu.rollret()){
   clrscr();
   stu.put(1);
   message(12);
   getch();}}
  stud.close();
  menu(1); }

/*it alter details of student on database*/
void modify(){
 clrscr();
 int mod,found=0;
 long pos;
  message(9);
 cin>>mod;
 stud.open("database.seh",ios::in|ios::out|ios::binary);
 stud.seekg(0);
 while(!stud.eof()){
  pos=stud.tellg();
  stud.read((char*)&stu,sizeof(stu));
  if(stu.rollret()==mod){
   clrscr();
   stu.mod();
   found=1;
   stud.seekg(pos);
   stud.write((char*)&stu,sizeof(stu));
   stud.close();
   menu(2);}}
 if(found==0){menu(7);}}



/*delete the student record present in database file made by user through program*/
void deleter(){
 clrscr();
 int del,found=0;
 char confirm='n';
 ofstream o("database.gs",ios::binary);
 message(10);
 cin>>del;
 stud.open("database.seh",ios::in);
 stud.seekg(0);
 while(!stud.eof()){
  stud.read((char*)&stu,sizeof(stu));
  if(stu.rollret()==del){
   clrscr();
   stu.put(0);
   message(4);
   found=1;
   cin>>confirm;
    if(confirm=='n'||confirm=='N'){
     o.write((char*)&stu,sizeof(stu));}}
  else{
  if(confirm=='y'||confirm=='Y'){
   o.write((char*)&stu,sizeof(stu));}}}
 stud.close();
 o.close();
 remove("database.seh");
 rename("database.gs","database.seh");
 if(found==0){menu(7);}
 else if(found==1){menu(3);}}

/*it display all records present in database of students to user*/
void display(){
 clrscr();
 stud.open("database.seh",ios::in);
 while(stud.read((char*)&stu,sizeof(stu))){
  stu.put(1);
  getch();}
 stud.close();
 menu(13); }

/*it search student record in database file and display it to user*/
void search(){
 clrscr();
 int flag=0,n;
 stud.open("database.seh",ios::in);
 message(11);
 cin>>n;
 stud.seekg(0);
 while(!stud.eof()){
  stud.read((char*)&stu,sizeof(stu));
  if(stu.rollret()==n){
   clrscr();
   stu.put(1);
   flag=1;
   message(12);
   getch();}}
 stud.close();
 if(flag==0){menu(7);}
 else if(flag==1){menu(5);} }

/*remove all database file in case of undesirable output shown to user*/
void database_remove(){
 char confirm='0';
 message(16);
 cin>>confirm;
 if(confirm=='s'||confirm=='S'){
  remove("database.seh");
  remove("database.gs");
  remove("lastroll.seh");
  message(14);cursor(0);getch();exit(0);}
 else {menu(17);} }

/*it divert the route of program to their respective function in case of database file is present on disk otherwise it give error message to user*/
void master_diverter(int divert){
 ifstream check("database.seh",ios::nocreate);
 if (check){
       if (divert==2){modify();}
  else if (divert==3){deleter();}
  else if (divert==4){display();}
  else if (divert==5){search();}}
 else {menu(15);}}

/*it provide menu interface to user and take input from user and calls the desire function according to user.*/
void menu(int returned){
  clrscr();
  char choice;
  cursor(0);
  cout<<"\n\n\n\t   1. Create Student Record";
  cout<<"\n\n\t   2. Modify Student Record";
  cout<<"\n\n\t   3. Delete Student Record";
  cout<<"\n\n\t   4. Display All Students Record";
  cout<<"\n\n\t   5. Search Student Record";
  cout<<"\n\n\t   6. Marking Scheme";
  cout<<"\n\n\t   7. Change Password";
  cout<<"\n\n\t   8. Exit";
  cout<<"\n\n     G. Clear Data Files.{Recommended Only When Output Is Not Satisfactory}";
  border(80,25,1,1);
  gotoxy(30,1);
  cout<<" CLASS RESULT MENU \n";
  message(returned);
  sleep(2);
  message(0);
  gotoxy(80,25);
  choice=getch();
  switch(choice){
   case '1' :  filewrite();                     break;
   case '2' :  cursor(2);master_diverter(2);    break;
   case '3' :  cursor(3);master_diverter(3);    break;
   case '4' :  cursor(0);master_diverter(4);    break;
   case '5' :  cursor(1);master_diverter(5);    break;
   case '6' :  cursor(0);markscheme();          break;
   case '7' :  cursor(2);p.passfile_changer();  break;
   case '8' :  cursor(0);exiter();
   case 'G' :  cursor(2);database_remove();     break;
   case 'g' :  cursor(2);database_remove();	break;
   case 'S' :  //showcode();
   default  :  menu(8);}
}
/*Here Program Start its execution*/
void main(){
 clrscr();
 textattr(15);
 cursor(0);
 term();
 splash();
 wait_maker(4);
 intro();
 wait_maker(4);
 cursor(2);
 p.validater();
 cursor(1);
 menu(0);}
