#include <fstream> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 
#include <iomanip> 
#include <conio.h> 
#include <iostream> 
using namespace std; 
const int nrow=3;

struct stud{
	int num;
	char surname[15];
	char name[10];
	char fthrname[15];
	int math;
	int progr;
	int phys;
	struct stud* next;
	};
	
	
int insertE1AfterE(const stud& E1, char surnameE2[15], stud *First){
	struct stud *current=First;
	struct stud *temp;
	int cnt=0;
	
	//printf("surnameE2 %s\n", surnameE2);
	while (current != NULL) {
		//current->num=current->num+100;
		if (strcmp(current->surname, surnameE2)==0) {
	 		printf("current %d  ", current->num);
			temp = current->next;
		  	current->next = new stud;
		  	current=current->next;
			*current=E1;
			current->next=temp;	 
			printf("insert E1 %d\n", current->num); 	
			};
		printf("search E %d\n",current->num);
		current = current->next;
		//current=temp;
			
		cnt++;
 		} ;
	return cnt;	
	}
	
int main () {
  struct stud class1[nrow];
  struct stud E1;
  struct stud *temp;
  struct stud *current;
  char surnameE[15];
  int cnt;
  
  for (int i=0;i<nrow;i++){
	printf("Enter num ");
	scanf("%d",&class1[i].num);
	printf("Enter name ");
	scanf("%s",&class1[i].name);
	printf("Enter surname ");
	scanf("%s",&class1[i].surname);
	printf("Enter fthrname ");
	scanf("%s",&class1[i].fthrname);
	printf("Enter math ");
	scanf("%d", &class1[i].math);
	printf("Enter progr ");
	scanf("%d", &class1[i].progr);
	printf("Enter phys ");
	scanf("%d", &class1[i].phys);	
	if (i<nrow-1)
		class1[i].next=&class1[i+1];
	else	
		class1[i].next=NULL;
	};
	
	
	printf("Entering of inserted data \n");
	printf("Enter num ");
	scanf("%d",&E1.num);
	printf("Enter name ");
	scanf("%s",&E1.name);
	printf("Enter surname ");
	scanf("%s",&E1.surname);
	printf("Enter fthrname ");
	scanf("%s",E1.fthrname);
	printf("Enter math ");
	scanf("%d", &E1.math);
	printf("Enter progr ");
	scanf("%d", &E1.progr);
	printf("Enter phys ");
	scanf("%d", &E1.phys);	

	printf("Entering E1 \n");
	printf("Enter surname ");
	scanf("%s",&surnameE);
	
	cnt=insertE1AfterE(E1, surnameE, &class1[0]);
	
	printf("-------result --------- %d\n\n",cnt);
	current=&class1[0];
	while (current != NULL) {
		printf("num %d ",current->num);
		printf(" name %s ",current->name);
		printf(" surname %s",current->surname);
		printf(" fthrname %s",current->fthrname);
		printf(" math %d", current->math);
		printf(" progr %d", current->progr);
		printf(" phys %d \n", current->phys);
			//temp = current->next;
			//current=temp;
			current=current->next;
		} ;
				
	
	return 0;
}
