#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
using namespace std;

class imc
{
private: 
    float altura; // atributo privado

public:

float IMC;
float massa;

   void setAltura(float a)//setter
    {
        altura = a;
    }


    int getAltura()//getter
    {
        return altura;
    }

    imc(float x, float y, float z) {//construtor 
      IMC = x;
      massa = y;
      setAltura(z);
    }

    };

int main(){
	setlocale(LC_ALL, "Portuguese");//ativação dos caracteres especiais portugueses 

	float y, x, z;//massa, IMC, altura    
	
	cout<<"Digite a sua massa: "<<endl;
   	fflush(stdin);//limpar cache do teclado
   	cin>>y;
   
   	cout<<endl<<endl<<"Digite a sua altura em metros: "<<endl;
   	fflush(stdin);
   	cin>>z;
   	
    x=y/(z*z);//calcular o IMC
    imc pessoa(x, y, z);//criação do 1 obj
    cout<<endl<<"A sua altura é "<<z<<" m, a sua massa é "<<pessoa.massa<<" kg, o seu IMC é de "<<pessoa.IMC<<" kg/m2"<<endl<<endl;
   
    y=25*(z*z);//calcular o peso maximo que se pode ter no estado saudavel
    imc ImcCorreto(25,y,z);
    y=18.5*(z*z);//calcular o peso minimo no estado saudavel
    imc ImcCorreto2(18.5,y,z);
    cout<<"A sua massa ideal esta entre os "<<ImcCorreto2.massa<<" kg e os "<<ImcCorreto.massa<<" kg"; 

	if(pessoa.IMC<16) cout<<endl<<endl<<"\t\tClassificação : Magreza grave"<<endl<<endl<<"\t\tConsequências : Insuficiência cardíaca, Anemia grave, Enfraquecimento do sistema imunológico.";
	else if(pessoa.IMC<17) cout<<endl<<endl<<"\t\tClassificação : Magreza moderada"<<endl<<endl<<"\t\tConsequências : Infertilidade, Queda de cabelo, Falta damenstruação."; 
	else if(pessoa.IMC<18.5) cout<<endl<<endl<<"\t\tClassificação : Magreza leve"<<endl<<endl<<"\t\tConsequências : Stress, Ansiedade, Fadiga"; 
	else if(pessoa.IMC<25) cout<<endl<<endl<<"\t\tClassificação : Saudável"<<endl<<endl<<"\t\tConsequências : Menor risco para doenças."; 
	else if(pessoa.IMC<30) cout<<endl<<endl<<"\t\tClassificação : Sobrepeso"<<endl<<endl<<"\t\tConsequências : Fadiga, Varizes, Má circulação."; 
	else if(pessoa.IMC<35) cout<<endl<<endl<<"\t\tClassificação : Obesidade Grau 1"<<endl<<endl<<"\t\tConsequências : Diabetes, Infarto, Angina, Aterosclerose."; 
	else if(pessoa.IMC<40) cout<<endl<<endl<<"\t\tClassificação : Obesidade Grau 2 (Severa)"<<endl<<endl<<"\t\tConsequências : Apneia do sono, Falta de ar."; 
	else if(pessoa.IMC>40)  cout<<endl<<endl<<"\t\tClassificação : Obesidade Grau 3 (Morbida)"<<endl<<endl<<"\t\tConsequências : Refluxo, infarto, AVC, Dificuldade de locomocao, Escaras."; 
	     
	    
	return 0;
}
