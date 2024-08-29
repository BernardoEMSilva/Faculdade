#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


int main()
{
   
   // declaração das variaveis
    char m[60];
    int i=0;

    cout<<"Digite um conjunto de nomes:"<<endl<<endl;
    fflush(stdin);
    gets(m);


    while (m[i] != '\0')// É executado em quanto o caracter apontado n for \0 (final do array)
    {
        if(m[i] == ' ')// altera o espaço por um \n
        {
            m[i] = '\n';
        }

        i++;
    }
    
    
    FILE *fp;// apontador do ficheiro


    i=0;// reutilização da var i
    fp = fopen("ficheiro1.txt", "w");

    if (fp != NULL)// verifica se o ficheiro foi aberto
    {
        for (; m[i]; i++)//escreve no ficheiro o array
        {
            fputc(m[i], fp);
        }
        cout<<endl<<endl<<"Texto escrito com sucesso"<<endl<<endl;

        fclose(fp);
    }
    else
    {
        cout<<endl<<endl<<"\n\nTexto Erro na abretura do ficheiro\n\n"<<endl<<endl;
    }


    system("pause");
    return 0;}
