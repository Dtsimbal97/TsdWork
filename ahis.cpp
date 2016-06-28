#include <stdio.h>
#include <string.h>

const int nrow=3;

struct Data {
	int height;
	char sex;
	char name;
};

int Smallest(struct Data *array){
	
	int hMin=0;
	int num=0;
	
	
	while (array[num].sex!='m'){
		num++;
		
	}
	hMin=array[num].height;
	int res=num;
	for (int i=num;i<nrow;i++){
		if ((array[i].sex='m') and (array[i].height<hMin)){
			hMin=array[i].height;	
				res=i;}
	}
	return res;
}

int main(){

int res;
struct Data array[nrow];

for (int i=0;i<nrow;i++){
	printf("Enter height ");
	scanf("%d",&array[i].height);
	printf("Enter sex ");
	scanf("%s",&array[i].sex);
	printf("Enter name ");
	scanf("%s",&array[i].name);
}

res=Smallest(array);
printf(&array[res].name);
 
return 0;
}
