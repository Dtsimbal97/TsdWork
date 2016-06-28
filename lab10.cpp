#include <fstream>
#include <stdlib.h>
#include <string.h> 
#include <iomanip> 
#include <conio.h> 
#include <iostream> 
#include <windows.h>
using namespace std; 
const int d_fio=15, //����� �.�.�.
          d_s=6;  //����� ����
struct human{
	char fio[d_fio];  //�.�.�.
	char sex[d_s];    //���
	int year;         //��� ��������
	int children;     //���������� �����
	int salary;       //�����
    struct human* next;      //��������� �� ��������� �������
};  
human* dob(human* end, const human& h); //���������� �������� � ������� 
human* dob_first(const human& h);  //���������� ������� �������� 
human* udal(human* beg);   //�������� �������� �� ������� 
human vvod_znacheniy();
human* dobav_first(human *beg, const human &h);    //���� �������� ��������   
int menu();                //����������� ���� � ���� ��� ������
void print(const human& h); //����� ��������  �������� 
void prosmotr(human* beg);  //�������� ������� 
int read_file(const char* filename, human** beg, human** end);  //������ ����� 
int write_file(const char* filename, human* temp);  //������ � ���� 
int main(){
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251); 
	human *beg=0;
	human *end=0;
	const char *filename="human1.txt";
	read_file(filename, &beg, &end);
	while (1){
		switch (menu()){
		case 1:
		   if(beg)
		   end=dob(end, vvod_znacheniy());
		  else{
			beg=dob_first(vvod_znacheniy());
			end=beg;}
		 break;
		case 2:
			beg=udal(beg);
			getch();
			break;
		case 3:
			prosmotr(beg);
			break;
		case 4: write_file(filename, beg);
		    break;  
		case 5:
			if (beg)
			beg=dobav_first(beg, vvod_znacheniy());
			else{
			beg=dob_first(vvod_znacheniy());
			end=beg;}
			break;	
		case 6:
		     return 0;
		default:
		    cout<<"��� ������� ������ ����� �� 1 �� 6"<<endl;
			cin.get(); 
			break;}}}
    //dobavlenie el-ta
   human* dob(human *end, const  human& h) {         
   		human *newE=new human;  
   		*newE=h;    
   		newE->next=0;   
   		end->next=newE;   
   		end=newE;    
    	return end;    }  
	//sozdanie pervogo el-ta
	human *dob_first( const human& h){
		human*beg=new human;
		*beg=h;
		beg->next=0;
		return beg;}	
	human* dobav_first(human *beg, const human &h){
		human *temp=new human;
		*temp=h;
		temp->next=beg;
		beg=temp;
		return beg;}
	//pehat' i udalenie el-ta
	human* udal(human *beg)  { 
	human *temp;  if (!beg) { 
	cout<<"Ochered' pystaya"<<endl; 
	return 0; }  
	cout<<"============================================"<<endl;  
	print(*beg);    
	cout<<"============================================"<<endl;  
	temp=beg;    
	beg=beg->next;   
	delete temp;
	cout<<"������� ��� ������� ������"<<endl;
	getchar;     
	return beg;  } 
	 //vvod znacheniy el-ta
	  human vvod_znacheniy()  {   
	  char buf[10];  
	  human h;  
	  cout<<"������� �.�.�."<<endl;  
	  cin.getline(h.fio,d_fio);  
	  cout<<"������� ��� ��������"<<endl;  
	  cin.getline(h.sex,d_s);  
	  cout<<"������� ��� ��������"<<endl;  
	  cin>>h.year;  
	  cout<<"������� ���������� �����"<<endl;  
	  cin>>h.children;
	  cout<<"������� c������� �����"<<endl;  
	  cin>>h.salary;  
	  return h; } 
	//otobrajenie menu
	int menu() {  
	char buf[10];  
	int item;  
	do    {
	system("cls");     
	cout<<endl;     
	cout<<"===����� ���������� � ���������==="<<endl<<endl;     
	cout<<"1- ���������� �������� � �������"<<endl;     
	cout<<"2- ������ � �������� ��������"<<endl;
	cout<<"3- �������� �������"<<endl;     
	cout<<"4- ������ ������ � ����"<<endl;     
	cout<<"5- ������� ������� �������� � �������"<<endl;
	cout<<"6- �����"<<endl;     
	cout<<"============================"<<endl;     
	cout<<"������� ����� ������ ����"<<endl;     
	cin>>buf;     
	cin.get();     
	item=atoi(buf);    
	if (!item) {  
	cout<<"��� ������� ������� ����� �� 1 �� 6"<<endl;                     
	cin.get(); }  } 
	while (!item);   
	return item;   }
	//pechat' inphormacii
	void print(const human& h)  { 
	cout<<"|"<<setw(15)<<h.fio<<"|"<<setw(6)<<h.sex<<"|"<<setw(5)<<h.year<<"|"<<setw(5)<<h.children<<"|"<<setw(7)<<h.salary<<"|"<<endl;  }
	//prosmotr oceredi
	void prosmotr(human *beg)  { 
	if (!beg) { 
	cout<<"������� ������"<<endl;
	getch(); 
	return ;  }  
	human *temp=beg; 
	cout<<"--------------------------------------------"<<endl; 
	cout<<"|"<<setw(16)<<"�.�.O |"<<setw(7)<<"���|"<<setw(6)<<"���|"<<setw(6)<<"����|"<<setw(8)<<"�����|"<<endl;  
	cout<<"--------------------------------------------"<<endl; 
	while (temp) {   //������������� ���� temp!=0   
	print(*temp);  //�������� �������� �������� �� ���������        
	temp=temp->next; } 
	cout<<"--------------------------------------------"<<endl; 
	getchar();}
	//chtenie iz faila
	int read_file(const char* filename, human** beg, human** end)  { 
	ifstream fin(filename,ios::in); 
	if (!fin) {
	cout<<"��� �����"   
	<<filename<<endl;
	getch(); 
	return 1;}   
	human h;  
	*beg = 0; 
  while (fin.getline(h.fio,d_fio))  {    
  fin.getline(h.sex,d_s);   
  fin>>h.year>>h.children>>h.salary;   
  fin.get();         
  if (*beg)     
  *end=dob(*end,h);   
  else    
  {*beg=dob_first(h); *end=*beg;} }  
  return 0; } 
  // zapic v fail
  int write_file(const char* filename, human* temp)  { 
  ofstream fout(filename);  
  if (!fout) {
  cout<<"�� ���� ������� ���� ��� ������"<<endl; 
  return 1;}  
  while (temp)  {  
  fout<<temp->fio<<endl;
  fout<<temp->sex<<endl; 
  fout<<temp->year<<endl; 
   fout<<temp->children<<endl;
   fout<<temp->salary<<endl; 
   temp=temp->next;   }  
   cout<<"������ ��������� � �����: "<<filename<<endl;  
   cout<<"=============================="<<endl;  
   cout<<"������� ����� �������"<<endl;  
   cin.get();  
   return 0; }
