#include <fstream> 
#include <iostream>
#include <stdlib.h> 
#include <string.h> 
#include <iomanip> 
#include <conio.h> 
#include <windows.h>
using namespace std;
//----------------------���������----------------------------------------- 
const int  d_f=20,  //����� ������ � �.�.�.   
d_s=8;  //����� ������ � ������� 
//---------------------���������------------------------------------------- 
struct zap    // ��������  ������ � �������� 
	{char fio[d_f];  
	char sex[d_s];
	int year, children, salary; 
	}; 
struct node   // �������� ���� ������ 
	{zap data;  
	node* left;  
	node* right;  
	};
//-------------��������� �������-------------------------------------- 
node* addtree(node *top,const zap &newnode); //���������� ���� 
int menu();        //����������� ���� 
void otobr(node *top, int otstup); //����������� ��������� //������ 
void prosmotr(node *top); //��������  �������� ����� ������ ����� ������� 
int write_file(ofstream &f, node* top);  //������ � ���� 
int read_file(const char* filename, node* &top); //������ �� ����� 
zap vvod();      //���� ������ 
node *poisk_l(node *top);
//-------------------------�������� �������------------------------------ 
int main() {   
SetConsoleCP(1251);
SetConsoleOutputCP(1251);   
node *top=0;       
const char *filename="derevo.txt";       
ofstream fout;   //���������� ��������� ������       
read_file(filename,top);  //������ ������ �� �����       //� �������� ������     
int n=0;
char k;
node *temp;
while (1)        
	{switch (menu())    //����������� � ���� ������ ����  
	{case 1: //����� 1 - ����������� ������
		while(1)
		{   cout<<"������� * ��� ������"<<endl;
		cin>>k; 
		cin.get(); 
		if (k=='*')
		break;
		top=addtree(top,vvod());
		cin.get();}
		break; 
	case 2:    //����� 2 - ���������� �������� � ������       
		top=addtree(top,vvod()); //���� �  ���������� ��������        
		break;  
	case 3:    //����� 3 � �������� �������� � �����      
		prosmotr(top);      
		cout<<"������� ����� ������� "<<endl;     
		cin.get();      
		break; 
	case 4:    //����� 4 � ����������� ��������� ������      
		otobr(top,1);      
		cout<<"������� ����� ������� "<<endl;      
		cin.get();      
		break;  
	case 5:     //����� 5 - ����� ������ ������ �������� ������
		if(!top){
		cout<<"������ �� ����������"<<endl;
		getchar();
		break;}
		if (top->left==NULL){
		cout<<"������ �� �� ����������"<<endl;
		getchar();
		break;
		}
		//top=poisk_l(top);
		cout<<poisk_l(top)->data.fio;
		getchar();
		break;	
	case 6:    //����� 6 � ������ � ����      
		fout.open(filename);  //�������� �����      
		if (!fout){   
			cout<<"������ �������� �����"<<endl; 
			return 1;}      
		write_file(fout,top);   //���������� ������ � �����      
		cout<<"������ ��������� � �����: "<<filename<<endl;      
		cout<<"=============================="<<endl;      
		fout.close();      
		cout<<"������� ����� ������� "<<endl;      
		cin.get();      
		break;  
	case 7:     //����� 7 � �����      
		return 0; 
	default:     //���� ������� ������ ����� ����      
		cout<<"��� ������� ������ ����� �� 1 �� 7"<< endl;      
		cin.get();      
		break;  }  }	} 
	//-------����� ������ ������ ��������-------------------------
	node *poisk_l(node *top){
		while (top->left)
		top=top->left;
        return top; }
	//-----------------------���������� ���� � ������----------------------- 
	node* addtree(node *top,const zap& newnode)  
		{ if (!top)       //���� ��������� �� ������ �����,   
		{top=new node;   //�� �������� ������ ��� ����   
		if (!top) {cout<<"�� ������� ������"<<endl;       
		return NULL;  //����� ���� ������ �� ��������  
		}   
		top->data=newnode;  //������ ������ � ����   
		top->left=NULL;   //��������� ����������   
		top->right=NULL;  }  
		else        //����� 
		if (strcmp(top->data.fio,newnode.fio)>0) //���������� �������� � ���� � ����������� �     
		top->left=addtree(top->left,newnode);//��������� � ����� ��  
		else   
		top->right=addtree(top->right,newnode);//��� ������ ��������� 
		return top;     //���������� ��������� �� ������ ������ 
}
// ----------------����������� ��������� ������------------------- 
//       �������  ����������� ��������� ������. 
//      ������ ������������ ���������� �� 90 �������� ������
//      ������� �������. ���� ������, ����������� �� ����� 
//      ������, ������������ �  ���������� �������� �� ���� 
//      ������.
void otobr(node *top, int otstup)  
   		{ if (top)    
		   {otstup+=3;     //������ �� ���� ������   
		   otobr(top->right,otstup);  //����� ������� ��������� ����� �������� �������, ���������������� ����   
		   cout<<setw(otstup)<<"*"<<top->data.fio<<endl;   
		   otobr(top->left,otstup);   //����� ������ ���������  	   
		   } } 
// ----------------�������� ������-------------------------------------- 
	void prosmotr(node *top)     //�������� ������ ���� 
		{ if (top)    {
		cout<<"|"<<setw(15)<<top->data.fio<<"|"<<setw(6)<<top->data.sex<<"|"<<setw(5)<<top->data.year<<"|"<<setw(5)<<top->data.children<<"|"<<setw(7)<<top->data.salary<<"|"<<endl;
		prosmotr(top->left);   //����� ������ ���������   
		prosmotr(top->right);   //����� ������� ���������  
		} } 
//-------------------���� ������---------------------------------------- 
	zap vvod()  
		{ zap p;  
		cout<<"������� �.�.�."<<endl;  
		cin.getline(p.fio,d_f);
		cout<<"������� ���"<<endl;  
		cin.getline(p.sex,d_s);
		cout<<"������� ��� ��������"<<endl;  
	    cin>>p.year;  
	    cout<<"������� ���������� �����"<<endl;  
	    cin>>p.children;
	    cout<<"������� c������� �����"<<endl;  
	    cin>>p.salary;  
		return p; } 
//---------------����������� � ���� ������� ����----------------- 
	int menu()  
		{ char buf[10];  
		int item;  
		do     
		{system("cls");     
		cout<<endl;     
		cout<<"==========�������==========="<<endl<<endl;
		cout<<"1- ����������� ������"<<endl;     
		cout<<"2- �������� ������� � ������"<<endl;         
		cout<<"3- �������� ������"<<endl; 
		cout<<"4- ���������� ��������� ������"<<endl; 
		cout<<"5- ����� ������ ������ �������� ������"<<endl;   
		cout<<"6- ������ ������ � ����"<<endl; 
        cout<<"7- �����"<<endl;  
		cout<<"============================"<<endl;     
		cout<<"������� ����� ������ ����"<<endl;     
		cin>>buf;      //���� ������ ������     
		cin.get();     item=atoi(buf);     //������������� ��� � �����     
		if (!item)       //���� ������         
		{  cout<<"��� ������� ������ ����� �� 1 �� 7"<<endl;            
		cin.get();        } } 
		while (!item);  //��������� ���� �� ����� ������� ���������  
		return item;  //������� ����� ���������� ������ ���� 
		} 
// -----------------------------������ �����--------------------------
	int read_file(const char* filename, node* &top )  
		{ ifstream fin(filename,ios::in);   //�������� �����  
		if (!fin) {
		cout<<"�� ������ ����"<<filename<<endl; 
		return 1;} 
		zap p;  
		top = 0;  
		while (fin.getline(p.fio,d_f))   //������ �.�.�. ���� �� ����� �����  
		{  fin.getline(p.sex,d_s); //������ ������  
		  fin>>p.year>>p.children>>p.salary;   
          fin.get();      
		top=addtree(top,p);  //�������� ��-� � ������  
		}  
		return 0; } 
		
	// --------------------������ ������ � ����----------------------------
	int write_file(ofstream &f, node* top)  
		{ if (top)       
		{  f<<top->data.fio<<endl;  //������ ����� ���(������)        
		f<<top->data.sex<<endl;
		f<<top->data.year<<endl;
		f<<top->data.children<<endl;
		f<<top->data.salary<<endl;         
		write_file(f,top->left);  //������ ������ ���������        
		write_file(f,top->right);  //������ ������� ��������� 
        }  
		return 0;}
