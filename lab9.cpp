#include <stdio.h> 
#include <string.h> 
#include <conio.h> 
#include <iostream>
#include <windows.h>

const int len_fio=15;  
struct person { 
char fio[len_fio];  
int groupe;    
int p1, p2, p3, p4, p5;   
}; 
const int size_p=sizeof(person); 

int create_file(FILE *fbin);  
int sort_file(FILE *fbin);  
int print_file(FILE *fbin);  
int poisk_2(FILE *fbin);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	
	FILE *fbin;
	char c;
	fbin=fopen("text_bin.txt", "r+b");
	if (!fbin){
	  fbin=fopen("text_bin.txt", "w+b");
	  if (!fbin){
	  	puts("ne mogy otkryt'(sozdat') fail\n");
	  	return 1;
	  }
	}
 while (1)       {  
 system("cls");   
 puts("1- zapis v fail");   
 puts("2- Sortirovka faila");   
 puts("3- Vyvod faila");   
 puts("4- Poisk studentov s dvoikami");   
 puts("5- exit");   
 puts("______________________________");   
 puts("vvedite nomer punkta menu\n");   
 c=getch();   
 switch (c)                 
 { case '1':create_file(fbin);break;   
 case '2':sort_file(fbin);break;   
 case '3':print_file(fbin);break;   
 case '4':poisk_2(fbin); break;   
 case '5':return 0;        
  } 
   } 	
}
 //создание файла
 int create_file(FILE *fbin){  
 int i;
 person elem; 
 fseek(fbin,0,SEEK_END);  
 puts("vvod dannyh o sotrydnicah");  
 puts("dlya vyhoda vvedite *");  
 puts("_________________________________\n");  
 while (1) {   
 puts("Vvedite FIO"); 
std::cin.get(elem.fio,15);

if (!strcmp(elem.fio,"*")) {
	std::cin.get();
 	return 1;  
	}
  puts("vvedite nomer gruppy");   
  scanf("%i",&elem.groupe); 
  puts("vvedite ocenki");   
  scanf("%d",&elem.p1);
  scanf("%d",&elem.p2);
  scanf("%d",&elem.p3);
  scanf("%d",&elem.p4);
  scanf("%d",&elem.p5);
  fwrite(&elem,size_p,1,fbin);
  std::cin.get();
  } 
  } 
  int print_file(FILE *fbin){  
  person elem;  
  int n, i;
 system("cls");    
  rewind(fbin);  
  puts("    FIO        |groupe| marks");
  puts("_____________________________________");    
  do {   n=fread(&elem,size_p,1,fbin);
  if (n<1) break;  
  printf("%-15s|%-6i|",elem.fio,elem.groupe);
printf("%d  ", elem.p1); 
 printf("%d  ",elem.p2); 
 printf("%d  ",elem.p3); 
 printf("%d  ",elem.p4); 
 printf("%d\n",elem.p5);     
  } while (1);  
  puts("_____________________________________"); 
  puts("najmite lubyu klavishy");  
  getch();  
  return 0; }
int sort_file(FILE *fbin) {  
 long i,j;  
 person elem1,elem2;   
 puts("dlya sortirovki najmite lubyu klavishy");  
 getch(); 
 fseek(fbin,0,SEEK_END); 
long len=ftell(fbin)/size_p; 
rewind(fbin); 
for(i=len-1;i>=1;i--)     
for (j=0;j<=i-1;j++) {   
fseek(fbin,j*size_p,SEEK_SET); 
fread(&elem1,size_p,1,fbin); 
fread(&elem2,size_p,1,fbin);  
if (strcmp(elem1.fio,elem2.fio)>=1) {     
fseek(fbin,(-2)*size_p,SEEK_CUR);   
fwrite(&elem2,size_p,1,fbin); 
fwrite(&elem1,size_p,1,fbin); }     }  
puts("najmite lubyu klavishy");  
getch();  
return 0; } 
int poisk_2 (FILE *fbin){
	long i=0, j=0, n=0, k=0;
	person elem,elem2; 
	puts("studenty, kotorye imeut dvoiki: ");	
	fseek(fbin, 0, SEEK_END);
	long len=ftell(fbin)/size_p;
	rewind(fbin);
	for(j=n;j<=len-1;j++)     {   
fseek(fbin,j*size_p,SEEK_SET); 
fread(&elem,size_p,1,fbin); 
if((elem.p1==2)||(elem.p2==2)||(elem.p3==2)||(elem.p4==2)||(elem.p5==2)){
k++;
printf("%-15s\n", elem.fio);}
n=i+1;		}
	if (k==0) {
		system("cls");
		puts("studentov s dvoikami net");}
	puts("najmite lubyu klavishy");  
getch();  
return 0;
}

