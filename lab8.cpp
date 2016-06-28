#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;


int main() {
 	const int n = 80;
	ifstream myfile("d:\\data.txt", ios::in);
	char s[n];
	char vowels[]="aoeiyuAOEIYU";
	while (!myfile.eof()) { 
		myfile.getline(s,n); 
		cout<<s<<endl;
		
		char *w=strtok(s," !,.?:;");
		while (w!=NULL) {
			
			if (strchr(vowels,w[0])&&(strchr(vowels,w[strlen(w)-1]))) {
				cout<<w<<endl;
			}
			w=strtok(NULL," !,.?:;");	
			}
		}
	return(0);
}
