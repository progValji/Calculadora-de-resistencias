#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<map>
using namespace std;

void calcularResistencia4();
void menu();
void res_Ohms(int);
void res_kiloOhms(int);
void res_megaOhms(int);
void res_gigaOhms(long long);
//funciones para saber los colores de dicha resistencia
void buscar_Ohms();
void buscar_KOhms();
void buscar_MOhms();
void buscar_GOhms();
bool entero_o_flotante(float); //para saber si el numero ingresado es entero o flotante

 map<string,int>tolerancia ={
	   	{"Marron",1},
	   	{"Rojo",2},
	   	{"Dorado",5},
	   	{"Plata",10}
};

 map<string,int>banda1_2 ={
	   	{"Negro",0},
	   	{"Marron",1},
	   	{"Rojo",2},
	   	{"Naranja",3},
	   	{"Amarillo",4},
	   	{"Verde",5},
	   	{"Azul",6},
	   	{"Violeta",7},
	   	{"Gris",8},
	   	{"Blanco",9},
	   	{"Dorado",10},
	   	{"Plata",11}
	   };

	map<int,string>valores_de_bandas = {
		{0,"Negro"},
		{1,"Marron"},
		{2,"Rojo"},
		{3,"Naranja"},
		{4,"Amarillo"},
		{5,"Verde"},
		{6,"Azul"},
		{7,"Violeta"},
		{8,"Gris"},
		{9,"Blanco"},
		{10,"Dorado"},
		{11,"Plata"}
	};   

string bandaTolerancia, banda3;
long long resistencia_aux = 0L;

int main(){
	    
    menu();
	return 0;
}

void menu(){
		int opcion=0,resp = 0;

  cout << "\tCalculadora de resistencias" <<endl;
  cout << "1.- Saber el valor de la resistencia" << endl;
  cout << "2.- Encontrar los colores de la resistencia"<<endl;
  cout << "3.- Salir"<<endl;
  cout << "Opcion: ";
  cin >> opcion;
  
  switch(opcion){
     case 1: calcularResistencia4();  break;  
     case 2:    system("cls");
             	cout<<"\t..FUNCIONAMIENTO.. "<<endl;
             	cout<<"Selecciona un rango de resistencia"<<endl;
             	cout<<"1) Ohms"<<endl;
             	cout<<"2) K Ohms"<<endl;
             	cout<<"3) M Ohms"<<endl;
             	cout<<"4) G Ohms"<<endl;
             	cout<<"Opcion: ";
             	cin>>resp;
             	
             	if(resp == 1){
             		buscar_Ohms();
				 }else if(resp == 2){
				 	buscar_KOhms();
				 }else if(resp == 3){
				 	buscar_MOhms();
				 }else if(resp == 4){
				 	buscar_GOhms();
				 }
     case 3: break;
     default:
            cout << "\nOpción no válida. Por favor, ingrese una opción válida." << endl;
            break;
 }	
}

void calcularResistencia4(){
	    system("cls");
	   string banda1,banda2;
	   float res_puntoDecimal = 0;
	   int indicador8_9 = 1;
	   
	   cout<<"\tParametros de resistencia de 4 bandas"<<endl;
	   cout<<"NOTA: Si su resistencia tiene color 'Morado' o 'Cafe' ingrese 'Violeta' o 'Marron'"<<endl;
	   cin.ignore();
	   cout<<"\nColor de la primera banda: "; getline(cin,banda1);
	   cout<<"\nColor de la segunda banda: "; getline(cin,banda2);
	   cout<<"\nColor de la tercera banda: "; getline(cin,banda3);
	   cout<<"\nColor de la ultima banda: "; getline(cin,bandaTolerancia);	 
	   
	long resistencia = (banda1_2[banda1] * 100 + banda1_2[banda2] * 10);
	
	int multiplicador = banda1_2[banda3];
	
	switch(multiplicador){
		case 0: resistencia /= 10; break;
		case 1: break;
		case 2: 
		case 3:
	    case 4:
	    case 5:
	    case 6:
		case 7:
		case 8: 
		case 9: multiplicador -= 1;
		        if((banda1_2)[banda3] == 8 || (banda1_2)[banda3] == 9){
		        	resistencia_aux = resistencia;
		        	resistencia_aux *= 1LL;
				}
		        for(int i = 0; i<multiplicador; i++){
		        	if((banda1_2)[banda3] == 8 || (banda1_2)[banda3] == 9){
		        		resistencia_aux *= 10LL;
		        		indicador8_9++;
					}
					else{
						resistencia *= 10;
					}
				}
				break;
		case 10: res_puntoDecimal = resistencia / 100;
		          break;
		case 11: res_puntoDecimal = resistencia / 100;
		         res_puntoDecimal /= 10;
				 break;	
		default: cout<<"\nLa ultima banda esta incorrecta";	break;  	
	}
	
	if(indicador8_9 != 1){
		 res_gigaOhms(resistencia_aux);
	}
	
	if(res_puntoDecimal == 0){ //cuando el mult no es dorado ni plateado 
	
	   if(resistencia > 1 && resistencia < 1000){ //ohms
	   	  res_Ohms(resistencia);
	   }
	   else if(resistencia > 1000 && resistencia < 1000000){ // k Ohms
	   	res_kiloOhms(resistencia);
	   }
	   else if(resistencia > 1000000 && resistencia < 1000000000){ //m Ohms
	   	res_megaOhms(resistencia);
	   }
       
	}else{
		if((banda1_2[banda3]) == 10){ //cuando el mult es dorado
		float aux = resistencia;
		aux /= 100; 
		cout<<"\n-------Resultado---------";
		cout<<"\nValor de la resistencia: "<<aux<<" Ohms "<<(tolerancia[bandaTolerancia])<<"%"<<endl;
		system("pause"); cin.ignore();
		}
		else if((banda1_2[banda3]) == 11){
		float aux = resistencia;	
		aux /= 1000; 
		cout<<"\n-------Resultado---------";
		cout<<"\nValor de la resistencia: "<<aux<<" Ohms "<<(tolerancia[bandaTolerancia])<<"%"<<endl;
		system("pause"); cin.ignore();
		}
	}
	system("cls");	
	menu();	
}

void res_Ohms(int resistencia){
		if(resistencia > 1 && resistencia < 1000){ 
			cout<<"\n-------Resultado---------";
			cout<<"\nValor de la resistencia: "<<resistencia<<" Ohms "<<(tolerancia[bandaTolerancia])<<"%"<<endl;
			system("pause"); cin.ignore();
		} 
	system("cls");	
	menu();	
}

void res_kiloOhms(int resistencia){
	
	if((banda1_2[banda3]) == 2){
		float aux = resistencia;
		aux /= 100; aux /= 10; 
		cout<<"\n-------Resultado---------";
		cout<<"\nValor: "<<resistencia<<" Ohms";
		cout<<"\nValor de la resistencia: "<<aux<<"k Ohms "<<(tolerancia[bandaTolerancia])<<"%"<<endl;
		system("pause"); cin.ignore();
	}
	else if((banda1_2[banda3]) == 3){
		int aux = resistencia;
		aux /= 1000;
	    cout<<"\n-------Resultado---------";
		cout<<"\nValor: "<<resistencia<<" Ohms";
		cout<<"\nValor de la resistencia: "<<aux<<"k Ohms "<<(tolerancia[bandaTolerancia])<<"%"<<endl;
		system("pause"); cin.ignore();
	}
	else if((banda1_2[banda3]) == 4){
		int aux = resistencia;
		aux /= 1000;
		cout<<"\n-------Resultado---------";
		cout<<"\nValor: "<<resistencia<<" Ohms";
		cout<<"\nValor de la resistencia: "<<aux<<"k Ohms "<<(tolerancia[bandaTolerancia])<<"%"<<endl;
		system("pause");cin.ignore();
	}
	system("cls");	
	menu();	
}

void res_megaOhms(int resistencia){
	
	if((banda1_2[banda3]) == 5){
		float aux = resistencia;
		aux /= 1000000;
		cout<<"\n-------Resultado---------";
		cout<<"\nValor: "<<resistencia<<" Ohms";
		cout<<"\nValor de la resistencia: "<<aux<<"M Ohms "<<(tolerancia[bandaTolerancia])<<"%"<<endl;
		system("pause"); cin.ignore();
    }
    else if((banda1_2[banda3]) == 6){
    	int aux = resistencia;
		aux /= 1000000;
		cout<<"\n-------Resultado---------";
		cout<<"\nValor: "<<resistencia<<" Ohms";
		cout<<"\nValor de la resistencia: "<<aux<<"M Ohms "<<(tolerancia[bandaTolerancia])<<"%"<<endl;
		system("pause"); cin.ignore();
	} 
	else if((banda1_2[banda3]) == 7){
		int aux = resistencia;
		aux /= 1000000;
		cout<<"\n-------Resultado---------";
		cout<<"\nValor: "<<resistencia<<" Ohms";
		cout<<"\nValor de la resistencia: "<<aux<<"M Ohms "<<(tolerancia[bandaTolerancia])<<"%"<<endl;
		system("pause");cin.ignore();
	}
    system("cls");	
	menu();	
}

void res_gigaOhms(long long resistencia){
	
	if((banda1_2[banda3]) == 8){
		float aux = resistencia;
		aux /= 1000000000;
		cout<<"\n-------Resultado---------";
		cout<<"\nValor: "<<resistencia<<" Ohms";
		cout<<"\nValor de la resistencia: "<<aux<<"G Ohms "<<(tolerancia[bandaTolerancia])<<"%"<<endl;
		system("pause"); cin.ignore();
	}
	else if((banda1_2[banda3]) == 9){
		long long aux = resistencia;
		aux /= 1000000000;
		cout<<"\n-------Resultado---------";
		cout<<"\nValor: "<<resistencia<<" Ohms";
		cout<<"\nValor de la resistencia: "<<aux<<"G Ohms "<<(tolerancia[bandaTolerancia])<<"%"<<endl;
		system("pause"); cin.ignore();
	}
	system("cls");
	menu();	
}

bool entero_o_flotante(float f){
	int ent;
	ent = f;

	if(f-ent){
		return true; //retorna true si el numero es flotante
	}
	else{
		return false;//retorna false si el numero es entero
	}
}

void buscar_Ohms(){
	
}

void buscar_KOhms(){
	system("cls");
	float valorMomentaneo,resistenciaFlotante = 0;
	int resistenciaEntera;
	string terceraBanda,numero,primerBanda,segundaBanda;
	int digito1,digito2,aux;


	cout<<"\tParametros de la resistencia";
	cout<<"\nPon cualquier valor de resistencia que desees buscar,estas en la escala de K Ohms";
	cout<<"\nEse valor obviamente debe de estar en dicha escala para poder mostar los resusltados correctos";
	cout<<"\n\nIngresa un valor de resistencia: "; cin>>valorMomentaneo;
	if(entero_o_flotante(valorMomentaneo)){
		resistenciaFlotante = valorMomentaneo;
	}
	else{
		resistenciaEntera = valorMomentaneo;
	}
	if (resistenciaEntera != 0){
		numero = to_string(resistenciaEntera);
		digito1 = numero[0]-'0';
		digito2 = numero[1]-'0';
		primerBanda  = valores_de_bandas[digito1];
		segundaBanda = valores_de_bandas[digito2];
		if(resistenciaEntera < 100){
		    terceraBanda = "Naranja";
		}else{
			 terceraBanda = "Amarillo";
		}
	}else{
		aux = resistenciaFlotante * 10;
		numero = to_string(aux);
		digito1 = numero[0]-'0';
		digito2 = numero[1]-'0';
		primerBanda  = valores_de_bandas[digito1];
		segundaBanda = valores_de_bandas[digito2];
		terceraBanda = "Rojo";
	}

	cout<<"\n--Impriendo Datos--";
	cout<<"\nBanda 1: "<<primerBanda; cout<<"\nBanda 2: "<<segundaBanda; cout<<"\nBanda 3: "<<terceraBanda<<endl;
	system("pause"); system("cls"); menu(); 
}

void buscar_MOhms(){
	cout<<"Hola";
}

void buscar_GOhms(){
	cout<<"Hola";
}
