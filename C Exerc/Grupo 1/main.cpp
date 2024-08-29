#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
using namespace std;


void contaVogal();
void contaConsoante();
void contaPalavra();

int main(int argc, char *argv[]){
	setlocale(LC_ALL, "Portuguese");

	FILE *fp;
	fp = fopen("Text.txt", "r");
	if (fp != NULL){// Verifica se o ficheiro foi aberto
		
		
		cout<<"Neste ficheiro existem:"<<endl<<endl;
		contaVogal();
		contaConsoante();
		contaPalavra();

		fclose(fp);
	}else{
		cout << "Erro na abretura do ficheiro";
	}

	system("pause");
	fclose(fp);
	return 0;
}

void contaVogal(){/* Este método é utilizado para contar o numero de vogais, ele percorre todo o ficheiro e sempre que o caracter apontado 
                     é uma vogal, é adicionado mais 1 ao valor da variavel vogal, para assim saber quantas vogais existem  */
	
	FILE *fp;
	fp = fopen("Text.txt", "r");
	int Vogal = 0;
	int a=0;
	int e=0;
	int i=0;
	int o=0;
	int u=0;
	char ch;
	
	while( (ch=fgetc(fp)) != EOF){
		
		if ((ch=='A') || (ch=='a')){Vogal++;a++;} 
		else if ((ch=='E')||(ch=='e')){Vogal++;e++;}
		else if ((ch=='I')||(ch=='i')){Vogal++;i++;}
		else if ((ch=='O')||(ch=='o')){Vogal++;o++;}
		else if ((ch=='U')||(ch=='u')){Vogal++;u++;} 
		
		
	}cout<<"Existem "<<Vogal<<" vogais"<<endl<<"Existem "<< a << " A"<<endl<<"Existem "<< e << " E"<<endl<<"Existem "<< i << " I"<<endl<<"Existem "<< o << " O"<<endl<<"Existem "<< u << " U"<<endl<<endl;
}
void contaConsoante(){/* Este metodo é utilizado para contar o numero de consoantes, percorre todo o ficheiro e sempre que o caractere apontado 
                     é uma consoante, é adicionado mais 1 ao valor da variavel consoantes, para assim saber quantas consoantes existem  */
	
	FILE *fp;
	fp = fopen("Text.txt", "r");
	int Consoante = 0;
	char ch;
	
	while ((ch=fgetc(fp)) != EOF){
		
		if ((ch=='B') || (ch=='C') || (ch=='D') || (ch=='F') || (ch=='G') || (ch=='H') || (ch=='J') || (ch=='K') || (ch=='L') || (ch=='M') || (ch=='N') || (ch=='P') || (ch=='Q') || (ch=='R') || (ch=='S') || (ch=='T') || (ch=='V') || (ch=='W') || (ch=='X') || (ch=='Y') || (ch=='Z') ||
			(ch=='b') || (ch=='c') || (ch=='d') || (ch=='f') || (ch=='g') || (ch=='h') || (ch=='j') || (ch=='k') || (ch=='l') || (ch=='m') || (ch=='n') || (ch=='p') || (ch=='q') || (ch=='r') || (ch=='s') || (ch=='t') || (ch=='v') || (ch=='w') || (ch=='x') || (ch=='y') || (ch=='z'))
		{	
			Consoante++;
		}
	}cout<<"Existem "<<Consoante<<" Consoantes"<<endl;
}

void contaPalavra(){/* Este metodo serve para contar o numero de palavras, percorre todo o ficheiro e sempre que o caracter apontado 
                     é um espaço ou um \n (enter), é adicionado mais 1 ao valor na variavel Palavra, a variavel Palavra começa a 1, porque 
					 um texto nunca começa com um espaço ou um \n  */
	
	FILE *fp;
	fp = fopen("Text.txt", "r");
	char ch;
	int Palavra = 1;
	
	while((ch=fgetc(fp)) != EOF){
		if ((ch == ' ')||(ch=='\n')){
			Palavra++;
		}
	}
	cout<<"Existem "<< Palavra<<" Palavras"<<endl<<endl;
}
