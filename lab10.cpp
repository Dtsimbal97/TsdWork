#include <fstream>
#include <stdlib.h>
#include <string.h> 
#include <iomanip> 
#include <conio.h> 
#include <iostream> 
#include <windows.h>
using namespace std; 
const int d_fio=15, //длина Ф.И.О.
          d_s=6;  //длина пола
struct human{
	char fio[d_fio];  //Ф.И.О.
	char sex[d_s];    //пол
	int year;         //год рождения
	int children;     //количество детей
	int salary;       //оклад
    struct human* next;      //указатель на следующий элемент
};  
human* dob(human* end, const human& h); //добавление элемента в очередь 
human* dob_first(const human& h);  //добавление первого элемента 
human* udal(human* beg);   //удаление элемента из очереди 
human vvod_znacheniy();
human* dobav_first(human *beg, const human &h);    //ввод значений элемента   
int menu();                //отображение меню и ввод его пункта
void print(const human& h); //вывод значений  элемента 
void prosmotr(human* beg);  //просмотр очереди 
int read_file(const char* filename, human** beg, human** end);  //чтение файла 
int write_file(const char* filename, human* temp);  //запись в файл 
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
		    cout<<"Вам следует ввести номер от 1 до 6"<<endl;
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
	cout<<"Элемент был успешно удален"<<endl;
	getchar;     
	return beg;  } 
	 //vvod znacheniy el-ta
	  human vvod_znacheniy()  {   
	  char buf[10];  
	  human h;  
	  cout<<"Введите Ф.И.О."<<endl;  
	  cin.getline(h.fio,d_fio);  
	  cout<<"Введите пол человека"<<endl;  
	  cin.getline(h.sex,d_s);  
	  cout<<"Введите год рождения"<<endl;  
	  cin>>h.year;  
	  cout<<"Введите количество детей"<<endl;  
	  cin>>h.children;
	  cout<<"Введите cемейный оклад"<<endl;  
	  cin>>h.salary;  
	  return h; } 
	//otobrajenie menu
	int menu() {  
	char buf[10];  
	int item;  
	do    {
	system("cls");     
	cout<<endl;     
	cout<<"===Вывод информации о человекее==="<<endl<<endl;     
	cout<<"1- Добавление элемента в очередь"<<endl;     
	cout<<"2- Печать и удаление элемента"<<endl;
	cout<<"3- Просмотр очереди"<<endl;     
	cout<<"4- Запись данных в файл"<<endl;     
	cout<<"5- Вставка первого элемента в очередь"<<endl;
	cout<<"6- Выход"<<endl;     
	cout<<"============================"<<endl;     
	cout<<"Введите номер пункта меню"<<endl;     
	cin>>buf;     
	cin.get();     
	item=atoi(buf);    
	if (!item) {  
	cout<<"Вам следует вводить число от 1 до 6"<<endl;                     
	cin.get(); }  } 
	while (!item);   
	return item;   }
	//pechat' inphormacii
	void print(const human& h)  { 
	cout<<"|"<<setw(15)<<h.fio<<"|"<<setw(6)<<h.sex<<"|"<<setw(5)<<h.year<<"|"<<setw(5)<<h.children<<"|"<<setw(7)<<h.salary<<"|"<<endl;  }
	//prosmotr oceredi
	void prosmotr(human *beg)  { 
	if (!beg) { 
	cout<<"Очередь пустая"<<endl;
	getch(); 
	return ;  }  
	human *temp=beg; 
	cout<<"--------------------------------------------"<<endl; 
	cout<<"|"<<setw(16)<<"Ф.И.O |"<<setw(7)<<"пол|"<<setw(6)<<"год|"<<setw(6)<<"дети|"<<setw(8)<<"оклад|"<<endl;  
	cout<<"--------------------------------------------"<<endl; 
	while (temp) {   //просматриваем пока temp!=0   
	print(*temp);  //печатаем значения элемента по указателю        
	temp=temp->next; } 
	cout<<"--------------------------------------------"<<endl; 
	getchar();}
	//chtenie iz faila
	int read_file(const char* filename, human** beg, human** end)  { 
	ifstream fin(filename,ios::in); 
	if (!fin) {
	cout<<"Нет файла"   
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
  cout<<"Не могу открыть файл для записи"<<endl; 
  return 1;}  
  while (temp)  {  
  fout<<temp->fio<<endl;
  fout<<temp->sex<<endl; 
  fout<<temp->year<<endl; 
   fout<<temp->children<<endl;
   fout<<temp->salary<<endl; 
   temp=temp->next;   }  
   cout<<"Данные сохранены в файле: "<<filename<<endl;  
   cout<<"=============================="<<endl;  
   cout<<"Нажмите любую клавишу"<<endl;  
   cin.get();  
   return 0; }
