#include <fstream> 
#include <iostream>
#include <stdlib.h> 
#include <string.h> 
#include <iomanip> 
#include <conio.h> 
#include <windows.h>
using namespace std;
//----------------------константы----------------------------------------- 
const int  d_f=20,  //длина строки с ф.и.о.   
d_s=8;  //длина строки с адресом 
//---------------------структуры------------------------------------------- 
struct zap    // Описание  записи о человеке 
	{char fio[d_f];  
	char sex[d_s];
	int year, children, salary; 
	}; 
struct node   // Описание узла дерева 
	{zap data;  
	node* left;  
	node* right;  
	};
//-------------прототипы функций-------------------------------------- 
node* addtree(node *top,const zap &newnode); //добавление узла 
int menu();        //отображение меню 
void otobr(node *top, int otstup); //отображение структуры //дерева 
void prosmotr(node *top); //просмотр  значений узлов дерева слева направо 
int write_file(ofstream &f, node* top);  //запись в файл 
int read_file(const char* filename, node* &top); //чтение из файла 
zap vvod();      //ввод данных 
node *poisk_l(node *top);
//-------------------------основная функция------------------------------ 
int main() {   
SetConsoleCP(1251);
SetConsoleOutputCP(1251);   
node *top=0;       
const char *filename="derevo.txt";       
ofstream fout;   //объявление выходного потока       
read_file(filename,top);  //чтение данных из файла       //и создание дерева     
int n=0;
char k;
node *temp;
while (1)        
	{switch (menu())    //отображение и ввод пункта меню  
	{case 1: //пункт 1 - организация дерева
		while(1)
		{   cout<<"введите * для выхода"<<endl;
		cin>>k; 
		cin.get(); 
		if (k=='*')
		break;
		top=addtree(top,vvod());
		cin.get();}
		break; 
	case 2:    //пункт 2 - добавление элемента в дерево       
		top=addtree(top,vvod()); //ввод и  добавление элемента        
		break;  
	case 3:    //пункт 3 – просмотр значений в узлах      
		prosmotr(top);      
		cout<<"Нажмите любую клавишу "<<endl;     
		cin.get();      
		break; 
	case 4:    //пункт 4 – отображение структуры дерева      
		otobr(top,1);      
		cout<<"Нажмите любую клавишу "<<endl;      
		cin.get();      
		break;  
	case 5:     //пункт 5 - поиск самого левого элемента дерева
		if(!top){
		cout<<"Дерева не существует"<<endl;
		getchar();
		break;}
		if (top->left==NULL){
		cout<<"Левого ПД не существует"<<endl;
		getchar();
		break;
		}
		//top=poisk_l(top);
		cout<<poisk_l(top)->data.fio;
		getchar();
		break;	
	case 6:    //пункт 6 – запись в файл      
		fout.open(filename);  //открытие файла      
		if (!fout){   
			cout<<"Ошибка открытия файла"<<endl; 
			return 1;}      
		write_file(fout,top);   //сохранение данных в файле      
		cout<<"Данные сохранены в файле: "<<filename<<endl;      
		cout<<"=============================="<<endl;      
		fout.close();      
		cout<<"Нажмите любую клавишу "<<endl;      
		cin.get();      
		break;  
	case 7:     //пункт 7 – выход      
		return 0; 
	default:     //если неверно введен пункт меню      
		cout<<"Вам следует ввести число от 1 до 7"<< endl;      
		cin.get();      
		break;  }  }	} 
	//-------поиск самого левого элемента-------------------------
	node *poisk_l(node *top){
		while (top->left)
		top=top->left;
        return top; }
	//-----------------------добавление узла в дерево----------------------- 
	node* addtree(node *top,const zap& newnode)  
		{ if (!top)       //если находимся на уровне листа,   
		{top=new node;   //то выделить память под узел   
		if (!top) {cout<<"Не хватает памяти"<<endl;       
		return NULL;  //выход если память не выделена  
		}   
		top->data=newnode;  //запись данных в узел   
		top->left=NULL;   //обнуление указателей   
		top->right=NULL;  }  
		else        //иначе 
		if (strcmp(top->data.fio,newnode.fio)>0) //сравниваем значение в узле с добавляемым и     
		top->left=addtree(top->left,newnode);//добавляем в левое пд  
		else   
		top->right=addtree(top->right,newnode);//или правое поддерево 
		return top;     //возвращаем указатель на корень дерева 
}
// ----------------отображение структуры дерева------------------- 
//       Функция  отображения структуры дерева. 
//      Дерево отображается повернутым на 90 градусов против
//      часовой стрелки. Узлы дерева, находящиеся на одном 
//      уровне, отображаются с  одинаковым отступом от края 
//      экрана.
void otobr(node *top, int otstup)  
   		{ if (top)    
		   {otstup+=3;     //отступ от края экрана   
		   otobr(top->right,otstup);  //обход правого поддерева вывод значения фамилии, соответствующего узла   
		   cout<<setw(otstup)<<"*"<<top->data.fio<<endl;   
		   otobr(top->left,otstup);   //обход левого поддерева  	   
		   } } 
// ----------------просмотр дерева-------------------------------------- 
	void prosmotr(node *top)     //просмотр сверху вниз 
		{ if (top)    {
		cout<<"|"<<setw(15)<<top->data.fio<<"|"<<setw(6)<<top->data.sex<<"|"<<setw(5)<<top->data.year<<"|"<<setw(5)<<top->data.children<<"|"<<setw(7)<<top->data.salary<<"|"<<endl;
		prosmotr(top->left);   //обход левого поддерева   
		prosmotr(top->right);   //обход правого поддерева  
		} } 
//-------------------ввод данных---------------------------------------- 
	zap vvod()  
		{ zap p;  
		cout<<"Введите ф.и.о."<<endl;  
		cin.getline(p.fio,d_f);
		cout<<"Введите пол"<<endl;  
		cin.getline(p.sex,d_s);
		cout<<"Введите год рождения"<<endl;  
	    cin>>p.year;  
	    cout<<"Введите количество детей"<<endl;  
	    cin>>p.children;
	    cout<<"Введите cемейный оклад"<<endl;  
	    cin>>p.salary;  
		return p; } 
//---------------отображение и ввод пунктов меню----------------- 
	int menu()  
		{ char buf[10];  
		int item;  
		do     
		{system("cls");     
		cout<<endl;     
		cout<<"==========ДЕРЕВЬЯ==========="<<endl<<endl;
		cout<<"1- Организация дерева"<<endl;     
		cout<<"2- Добавить элемент в дерево"<<endl;         
		cout<<"3- Просмотр дерева"<<endl; 
		cout<<"4- Отобразить структуру дерева"<<endl; 
		cout<<"5- Поиск самого левого элемента дерева"<<endl;   
		cout<<"6- Запись данных в файл"<<endl; 
        cout<<"7- Выход"<<endl;  
		cout<<"============================"<<endl;     
		cout<<"Введите номер пункта меню"<<endl;     
		cin>>buf;      //ввод номера пункта     
		cin.get();     item=atoi(buf);     //преобразовать его в целое     
		if (!item)       //если ошибка         
		{  cout<<"Вам следует ввести число от 1 до 7"<<endl;            
		cin.get();        } } 
		while (!item);  //повторять пока не будет введено правильно  
		return item;  //вернуть номер введенного пункта меню 
		} 
// -----------------------------чтение файла--------------------------
	int read_file(const char* filename, node* &top )  
		{ ifstream fin(filename,ios::in);   //открытие файла  
		if (!fin) {
		cout<<"Не найден файл"<<filename<<endl; 
		return 1;} 
		zap p;  
		top = 0;  
		while (fin.getline(p.fio,d_f))   //чтение ф.и.о. пока не конец файла  
		{  fin.getline(p.sex,d_s); //чтение адреса  
		  fin>>p.year>>p.children>>p.salary;   
          fin.get();      
		top=addtree(top,p);  //добавить эл-т в дерево  
		}  
		return 0; } 
		
	// --------------------запись данных в файл----------------------------
	int write_file(ofstream &f, node* top)  
		{ if (top)       
		{  f<<top->data.fio<<endl;  //запись корня под(дерева)        
		f<<top->data.sex<<endl;
		f<<top->data.year<<endl;
		f<<top->data.children<<endl;
		f<<top->data.salary<<endl;         
		write_file(f,top->left);  //запись левого поддерева        
		write_file(f,top->right);  //запись правого поддерева 
        }  
		return 0;}
