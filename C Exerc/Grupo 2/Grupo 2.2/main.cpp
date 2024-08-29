#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
 
using namespace std;
  


int main(int argc, char *argv[]) 
{
	setlocale(LC_ALL, "Portuguese");
	
	FILE *fp1; 
	FILE *fp2;
   	string a="Ana\n";
	char str[20]; 
   
   	fp1 = fopen("ficheiro1.txt" , "r");
   	fp2 = fopen("ficheiro2.txt" , "w");
   	if((fp1 == NULL)||(fp2 == NULL))
    {

      perror("Erro na abertura do ficheiro de leitura");
      return(-1);
    }
   	

    while( fgets (str, 20, fp1 ) != NULL )  {
    if(str!=a) fputs(str, fp2);
	
    }
    
	printf("Ficheiro escrito com sucesso\n\n");
	fclose(fp1);fclose(fp2);
	system("PAUSE");
		
	return 0;
}

