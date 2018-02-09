#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
using namespace std;



//menu principal, devuelve un entero 1-3
int menu();

//ejercicio 1
void ejercicio1();
//ejercio 2
//void ejercicio2();
//ejercicio 3
//void ejercicio3();


int main (){
	char resp = 's';
	do{
		int opcion = menu();	
		switch(opcion){
			case 1:
				ejercicio1();
				break;
			case 2:
				break;
			case 3:
				break;
		}
		cout<< "¿Desea continuar?";
		cin >> resp;
	}while(resp == 's');
	return 0;
}





//menu principal,d evuelve un entero 1-3
int menu(){
	cout <<"Ingrese un numero del 1 - 3,:"<<endl <<"Cada numero equvale al numero de ejercico";
	int resp = 0;
	cin >> resp;
	return resp; 
}
//ejerciocio 1
void ejercicio1(){
	string fechaIngresada = "";
	int fecha[8] = {0,0,0,0,0,0,0,0};
	bool fechaCorrecta = false;
	string meses[12] = {
		"enero", "febrero", "marzo", "abril", "mayo", "junio", "julio", "agosto",
		 "septiembre", "octubre", "noviembre", "diciembre"
	};
	int ano = 0;
	int mes = 0;
	int dia = 0;
		
	do{
		fechaCorrecta = false;
		cout << "Ingrese la fecha (YYYYMMDD):"<<endl;
		cin >> fechaIngresada;
		cout << endl;
		//fecha = atoi(fechaIngresada.c_str());
		for(int i = 0; i < fechaIngresada.size(); i++){
			fecha[i] = (int) fechaIngresada.at(i)-48;
			cout << fecha[i] << endl;
		}
		if(fecha[4]>1){
			fechaCorrecta = true;
		}
		if(fecha[5] >9){
			fechaCorrecta = true;
		}
		string temp = fechaIngresada.substr(4,5);
		if(temp == "01" || temp == "03" || temp == "05" || temp == "07" || temp == "07"
			|| temp == "10" || temp == "12"){
			if(fechaIngresada.at(6)=='3'){
				if(fechaIngresada.at(7) != '1' && fechaIngresada.at(7) != '0'){
					fechaCorrecta = true;
				}
			}else{
				int comp = (int)fechaIngresada.at(6)-48;
				if(comp >3){
					fechaCorrecta = true;
				}
			}
		}
		if(temp == "04" || temp == "06" || temp == "09" || temp == "11"){
			if(fechaIngresada.at(6) != '3'){
				if(fechaIngresada.at(7) != '0'){
					fechaCorrecta = true;
				}
			}else{
				int comp = (int)fechaIngresada.at(6)-48;
				if(comp > 3){
					fechaCorrecta = true;
				}
			}
		}

		int anio = ((int)fechaIngresada.at(0)-48)*1000 + ((int)fechaIngresada.at(1)-48)*100+
				((int)fechaIngresada.at(2)-48)*10 + ((int)fechaIngresada.at(3)-48);
		if(anio%4 == 0){
			if(fechaIngresada.substr(4,5)== "02" && fechaIngresada.substr(6,7)=="29")
				fechaCorrecta = false;
		}
			
		if(fechaCorrecta){
			cout<< "Fecha Incorrecta" << endl;
		}else{
			ano = anio;
		}
	}while(fechaCorrecta);
	//cout<<"ano "<< ano<< endl;
	mes = ((int) fechaIngresada.at(4)-48)*10 + ((int) fechaIngresada.at(5)-48);
	dia = ((int) fechaIngresada.at(6)-48)*10 + ((int) fechaIngresada.at(7)-48);
	cout << "mes " << mes << " dia " << dia;
	
	int totalDia = 0;
	int dia_mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	for(int i = 0; i < mes-1 ; i++){
		totalDia += dia_mes[i];
	}
	
	int totalDias = (ano*365) + ((int)(ano/4)) + totalDia + dia;
	//cout << "bisiestos: "<<((int)ano/4)<< "   totalDia:" << totalDia << " dia: " << dia << endl;
	int dia_semana = totalDias - ((int)(totalDias/7))*7;
	//cout << "dia_semana " << dia_semana;
	string dia_semana_final = "";
	if(ano%4==0){
		dia_semana += 1;
	}
	dia_semana += 1;
	switch(dia_semana){
		case 0:
			dia_semana_final = "Jueves";
			break;
		case 1:
			dia_semana_final = "Viernes";
			break;
		case 2:
			dia_semana_final = "Sabado";
			break;
		case 3:
			dia_semana_final = "Domingo";
			break;
		case 4:
			dia_semana_final = "Lunes";
			break;
		case 5:
			dia_semana_final = "Martes";
			break;
		case 6:
			dia_semana_final = "Miercoles";
			break;
	}
	

	string fechaFinal2 [4] = {dia_semana_final,""+ dia,""+ meses[mes-1],""+ ano};	
	//string fechaFinal  =""+ dia_semana_final + ",  " + dia + " de " + meses[mes-1] + " del "
	//			 + ano;
	//cout << fechaFinal;  
	for(int i = 0; i < 4 ; i++){
		cout << fechaFinal2[i] << endl;
	}

}
