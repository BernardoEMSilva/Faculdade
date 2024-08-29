#include <stdio.h>
#include <conio.h> 
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <string.h>
using namespace std;

struct Aluno
{
    char Nome[100], Turma;
	int Numero, Ano;
};
struct Aluno Aluno;


void Inserir();
void Consultar();
void Pesquisar();
void Atualizar();
void Eliminar();

 int main( )
 {
	 setlocale(LC_ALL, "Portuguese");
  FILE *fp;
 
 
  char ch;
  int opcao, sair=0;
    
  fp = fopen("dados.dat", "a");
  if ((fp == NULL))
  {
     printf("ERRO!\nO Ficheiro não foi aberto.\n");
     
     printf("\n\nDigite uma tecla para terminar Programa\n");
     
     fflush(stdin);
     ch = getchar();   
              
     exit(0);     
  }
  	fclose(fp);

//                  MENU
  	do{do{
		printf("Escolha uma opção\n");
		printf("\t\t1 - Inserir Novo Aluno\n");
    	printf("\t\t2 - Ver todos os Alunos\n");
    	printf("\t\t3 - Pesquisar um Aluno\n");
    	printf("\t\t4 - Atualizar info\n");
    	printf("\t\t5 - Eliminar Aluno\n");
    	printf("\t\t0 - SAIR\n\n");
    	printf("\nESCOLHE UMA OPCAO: ");
    	scanf("%d", &opcao);
    	} while (opcao < 0 || opcao > 6);
    	switch(opcao){
    		case 1:
    			Inserir();
    			break;
    			
    		case 2:
    			Consultar();
    			break;
    		case 3:
    			Pesquisar();
    			break;
    		case 4:
    			Atualizar();
    			break;
    		case 5:
    			Eliminar();
    			break;
    		case 0 :
    			sair=1;
    			break;
    		default:
    			cout<<"Erro";
    			break;
    	}
   } while (sair==0);
  

 

  printf("\n\n\n");
  system("PAUSE");	
  
  return 0;
 }
 
 
 
 void Inserir(){
 	
 	FILE *fp;   
	fp = fopen("dados.dat", "a");
  
	do
  {


   system("cls"); 
     
   printf("\n\nNome ");
   fflush(stdin);
   gets(Aluno.Nome); 
   
   printf("\n\nNumero ");
   fflush(stdin);
   scanf("%ld", &Aluno.Numero);

      
   printf("\n\nTurma: ");
   fflush(stdin);
   scanf("%c", &Aluno.Turma);   
   
   printf("\n\nAno: ");
   fflush(stdin);
   scanf("%ld", &Aluno.Ano);
   

   
   fwrite(&Aluno, sizeof(Aluno), 1, fp);
    
   printf("\n\nClique em ESC para sair\n\n");  
   printf("\t ou em outra tecla para novo registo\n\n");
       
   fflush(stdin);        
  }
  while (getch() != 27);    

    fclose(fp); 
 }
 
 void Consultar(){
 	system("cls");    
	FILE *fp;
	fp = fopen("dados.dat", "r");    
 
    
    while (fread(&Aluno, sizeof(Aluno), 1, fp))
    {
          printf("\n\n\nNome %s", Aluno.Nome);
          
          printf("\nNumero %d", Aluno.Numero);
          
          printf("\nTurma: %c", Aluno.Turma);
          
          printf("\nAno: %d", Aluno.Ano);  
    } 
	fclose(fp);  
 }
 
 void Pesquisar(){
 	system("cls");    
	FILE *fp;
	fp = fopen("dados.dat", "r");  
	int n;  
 
    cout<<"Qual o numero de aluno?"<<endl;
    cin>>n;
    
    
    while (fread(&Aluno, sizeof(Aluno), 1, fp))
    {
    	if(Aluno.Numero==n){
	
          printf("\n\n\nNome %s", Aluno.Nome);
          
          printf("\nNumero %d", Aluno.Numero);
          
          printf("\nTurma: %c", Aluno.Turma);
          
          printf("\nAno: %d", Aluno.Ano);  }
    } 
	fclose(fp);  
 }
 
 void Atualizar(){
 	system("cls");    
	FILE *fp;
	FILE *fp2; 
	fp = fopen("dados.dat", "r"); 
	fp2 = fopen("copiadados.dat", "a"); 
	int n,i=1;   
    cout<<"Qual o numero de aluno?"<<endl;
    cin>>n;
    
    
	while((!feof(fp))||(i!=0)){
        fread(&Aluno, sizeof(Aluno), 1, fp);
        if(n!=Aluno.Numero){
            fwrite(&Aluno, sizeof(Aluno), 1, fp2);
        }else{
        	cout<<"insira o novo nome:  ";
        	cin>>Aluno.Nome;
        	cout<<"insira o novo numero:  ";
        	cin>>Aluno.Numero;
        	cout<<"insira o nova turma:  ";
        	cin>>Aluno.Turma;
        	cout<<"insira o novo ano letivo:  ";
        	cin>>Aluno.Ano;i=0;n=0;
		}
    } 
	while(!feof(fp)){
	fread(&Aluno, sizeof(Aluno), 1, fp);fwrite(&Aluno, sizeof(Aluno), 1, fp2);
	}
	fclose(fp); fclose(fp2);
	

	remove("dados.dat");
    rename("copiadados.dat", "dados.dat");
 }
 
 void Eliminar(){
 	system("cls");    
	FILE *fp;
	FILE *fp2; 
	fp = fopen("dados.dat", "r"); 
	fp2 = fopen("copiadados.dat", "a"); 
	int n;   
    cout<<"Qual o numero de aluno?"<<endl;
    cin>>n;
    
    
	while(!feof(fp)){
        fread(&Aluno, sizeof(Aluno), 1, fp);
        if(n!=Aluno.Numero){
            fwrite(&Aluno, sizeof(Aluno), 1, fp2);
        }
    } 
	fclose(fp); fclose(fp2);
	

	remove("dados.dat");
    rename("copiadados.dat", "dados.dat");
 	
 }
 
 
