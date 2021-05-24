#include <iostream>
#define estandar	100
#define premium 	300
using namespace std;

void celdaVacia(int disponibilidad [4][5]){
		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
			if(disponibilidad[i][j]==1){
				cout<<"["<<i+1<<","<<j+1<<"]";
			}
			
		}
		cout<<" "<<endl;
	}
}

void llenarBarco(int disponibilidad [4][5],string marca [4][5],string puertoCarga [4][5],float peso [4][5],string tipoArticulo [4][5],string nombrePuerto[100],int puertos){
	int contenedor=0;
	int fila=1;
	int columna=1;
	int porcentaje=0;
	int contador=0;
	int recaudado=0;
	int opcionMarca=0;
	int opcionTipo=0;
	
	for(int i=0;i<puertos;i++){
		cout<<" "<<endl;
		cout<<"Digite la cantidad de contenedores que se ingresaran en el puerto: "<<nombrePuerto[i]<<endl;
		cin>>contenedor;
		recaudado=0;
		for(int j=0;j<contenedor;j++){
			int aux=0;
			
			while(disponibilidad[fila-1][columna-1]==1 |fila<1 |fila>4 | columna<1 |columna>5 |aux==0){
			
			cout<<" "<<endl;
			cout<<"Digite la posicion del barco en la que guardara el contenedor: "<<j+1<<endl;
			cout<<" "<<endl;
			celdaVacia(disponibilidad);
			
			cout<<" "<<endl;
			cout<<"Fila: "<<endl;
			cin>>fila;
			
			cout<<" "<<endl;
			cout<<"Columna: "<<endl;
			cin>>columna;
			
				
				if (disponibilidad[fila-1][columna-1]==1){
					disponibilidad[fila-1][columna-1]=0;
					aux=1;
					contador=contador+1;
					puertoCarga[fila-1][columna-1]=nombrePuerto[i];
					
					if((fila-1==1 & columna-1==1) | (fila-1==1 & columna-1==2) | (fila-1==1 & columna-1==3) | (fila-1==2 & columna-1==1) | (fila-1==2 & columna-1==2) | (fila-1==2 & columna-1==3)){
						recaudado=recaudado+premium;
					}
					else{
						recaudado=recaudado+estandar;
					}
				}
				else{
					cout<<"Error ingrese una posicion adecuada"<<endl;
				}
							
			}
			
			cout<<" "<<endl;
			cout<<"Que marca ingresara el contenedor: "<<endl;
			cout<<"1.maersk "<<endl;
			cout<<"2.hamburg "<<endl;
			cout<<"3.wds "<<endl;
			cin>>opcionMarca;
			if(opcionMarca==1){
				marca[fila-1][columna-1]="maersk";
			}
			if(opcionMarca==2){
				marca[fila-1][columna-1]="hamburg";
			}
			if(opcionMarca==3){
				marca[fila-1][columna-1]="wds";
			}
			
			cout<<" "<<endl;
			cout<<"Digite el peso del contenedor: "<<endl;
			cin>>peso[fila-1][columna-1];
			
			
			cout<<" "<<endl;
			cout<<"Que tipo de articulo ingresara en el contenedor: "<<endl;
			cout<<"1= Tipo A: Alimentos "<<endl;
			cout<<"2= Tipo B: Dispositivos Electronicos "<<endl;
			cout<<"3= Tipo C: Ropa "<<endl;
			cin>>opcionTipo;
			
			if(opcionTipo==1){
				tipoArticulo[fila-1][columna-1]="A";
			}
			if(opcionTipo==2){
				tipoArticulo[fila-1][columna-1]="B";
			}
			if(opcionTipo==3){
				tipoArticulo[fila-1][columna-1]="C";
			}
			
		}
		porcentaje=contador*5;
		cout<<" "<<endl;
		cout<<"El porcentaje de ocupacion del barco es: "<<porcentaje<<"%"<<endl;
		cout<<"El recaudado del puerto "<<nombrePuerto[i]<<" es: "<<recaudado<<"$"<<endl;
		
		
	}
}

void cantidadContenedores(int disponibilidad[4][5]){
	int contador;
	for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
			if(disponibilidad[i][j]==0){
				contador=contador+1;
			}	
		}	
	}
	cout<<" "<<endl;
	cout<<"1.cantidad de contenedores ingresados en el barco: "<<contador<<endl;
}

void contenedorOrdenado(string puertoCarga [4][5],string nombrePuerto[100],int puertos, int disponibilidad[4][5]){
	int vector[100];
	int contador=0;
	for(int i=0;i<4;i++){
		contador=0;
			for(int j=0;j<5;j++){
			if(disponibilidad[i][j]==0 & puertoCarga[i][j]==nombrePuerto[i]){
				contador++;
			
			}	
		}
			vector[i]=contador;	
	}
	
	int aux;
	string aux2;
	for(int i=0;i<puertos;i++){
		for(int j=0;j<puertos;j++){
			if(vector[i]>vector[j]){
				aux=vector[i];
				vector[i]=vector[j];
				vector[j]=aux;
				
				aux2=nombrePuerto[i];
				nombrePuerto[i]=nombrePuerto[j];
				nombrePuerto[j]=aux;
			}	
		}	
	}
	cout<<" "<<endl;
	cout<<"2.Reporte de contenedores ingresados en puertos de mayor a menor: "<<endl;
	for(int i=0;i<puertos;i++){
		
		cout<<nombrePuerto[i]<<": "<<vector[i]<<endl;
				
	}	
	
}

void listadoEconomico(string marca[4][5],int disponibilidad[4][5]){
		cout<<" "<<endl;
		cout<<"3.marcas en la seccion estandar: "<<endl;
		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
				if(disponibilidad[i][j]==0 & ((i!=1 & j!=1) | (i!=1 & j!=2) | (i!=1 & j!=3) | (i!=2 & j!=1) | (i!=2 & j!=2) | (i!=2 & j!=3))){
				cout<<marca[i][j]<<endl;
			}
			
		}
	
	}
}

void listadoPremium(string marca[4][5],int disponibilidad[4][5]){
	cout<<" "<<endl;
	cout<<"4.marcas en la seccion premium: "<<endl;
		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
			if(disponibilidad[i][j]==0 & ((i==1 & j==1) | (i==1 & j==2) | (i==1 & j==3) | (i==2 & j==1) | (i==2 & j==2) | (i==2 & j==3))){
				cout<<marca[i][j]<<endl;
			}
			
		}
	
	}
}	

int valorAPagar(string nombre,string marca[4][5],int disponibilidad[4][5]){
		int contadorP=0;
		int contadorE=0;
		int acumulador=0;
	
		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
				
		//	if(marca[i][j]==nombre){
			
				if(marca[i][j]==nombre & (disponibilidad[i][j]==0 & !((i==1 & j==1) | (i==1 & j==2) | (i==1 & j==3) | (i==2 & j==1) | (i==2 & j==2) | (i==2 & j==3)))){	
					contadorE++;
				}
				
			if(marca[i][j]==nombre & (disponibilidad[i][j]==0 & ((i==1 & j==1) | (i==1 & j==2) | (i==1 & j==3) | (i==2 & j==1) | (i==2 & j==2) | (i==2 & j==3)))){
				
				contadorP++;
					}
				
			//	}
			}
			
		}
		
	
	cout<<"\n5.la marca "<<nombre<<" tiene "<<contadorE<<" contenedor(es) estandar y "<<contadorP<<" contenedor(es) premium"<<endl;	
	acumulador=(contadorP*premium)+(contadorE*estandar);
	cout<<"total a pagar: "<<acumulador<<endl;
	return acumulador;
}	

float promedioPeso(float peso[4][5],int disponibilidad[4][5]){
		float promedio=0;
		float acumulador=0;
		int contador=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
			if(disponibilidad[i][j]==0){
				acumulador=acumulador+peso[i][j];
				contador=contador+1;
			}
			
		}
	}
	promedio=acumulador/contador;
	return promedio;
}

float masCarga(float peso[4][5],int disponibilidad[4][5]){
	float vector[100];
	int indice=0;
	float aux=0;
	float aux2=0;
	for(int i=0;i<4;i++){
		aux2=0;
			for(int j=0;j<5;j++){
				if(disponibilidad[i][j]==0){
					aux2=aux2+peso[i][j];
				
			}
				
		}
		vector[i]=aux2;
	}
	for(int i=0;i<4;i++){
		if(vector[i]>aux){
			aux=vector[i];
			indice=i+1;
		}
	
	}
	return indice;
	
}

float menosCarga(float peso[4][5],int disponibilidad[4][5]){
	float vector[100];
	float aux=111111111110;
	int indice=0;
	float aux2=0;
	for(int i=0;i<4;i++){
		aux2=0;
			for(int j=0;j<5;j++){
				if(disponibilidad[j][i]==0){
					aux2=aux2+peso[j][i];		
			}
			
		}
			vector[i]=aux2;
	}
	for(int i=0;i<4;i++){
		if(vector[i]<aux){
			aux=vector[i];
			indice=i+1;
		}
	
	}
	return indice;
}

int tipoContenedor(string tipoAriculo[4][5],int disponibilidad[4][5],string nombre){
	int contador=0;
	for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
			if(disponibilidad[i][j]==0 & tipoAriculo[i][j]==nombre){
				contador++;
			}
			
		}
	}
	return contador;
}

float promedioPuerto(string puertoCarga[4][5],int disponibilidad[4][5],float peso[4][5],string nombre){
		float promedio=0;
		int contador=0;
		
		for(int i=0;i<4;i++){
			for(int j=0;j<5;j++){
			if(disponibilidad[i][j]==0 & puertoCarga[i][j]==nombre){
				promedio=promedio+peso[i][j];
				contador++;
			}
			
		}
	}
	promedio=promedio/contador;
	return promedio;
}

string marcaPesada(string marca[4][5],int disponibilidad[4][5],float peso[4][5]){
		float aux=0;
		int fila=0;
		int columna=0;
		for(int i=0;i<4;i++){
			
			for(int j=0;j<5;j++){
				
			if(disponibilidad[i][j]==0 & peso[i][j]>aux){
				aux=peso[i][j];
				fila=i;
				columna=j;
			}
			
		}
	}
	return marca[fila][columna];
}

string marcaLiviana(string marca[4][5],int disponibilidad[4][5],float peso[4][5]){
		float aux=1111111110;
		int fila=0;
		int columna=0;
		for(int i=0;i<4;i++){
			
			for(int j=0;j<5;j++){
			if(disponibilidad[i][j]==0 & peso[i][j]<aux){
				aux=peso[i][j];
				fila=i;
				columna=j;
			}
			
		}
	}
	return marca[fila][columna];
}

int main(int argc, char** argv) {	
	
	int disponibilidad [4][5]={
	{1,1,1,1,1},
	{1,1,1,1,1},
	{1,1,1,1,1},
	{1,1,1,1,1},
	};
	string marca [4][5];
	string puertoCarga [4][5];
	float peso [4][5];
	string tipoArticulo [4][5];
	
	int puertos;
	cout<<"Digite el numero de puertos a visitar: "<<endl;
	cin>>puertos;
	
	string nombrePuerto[100];
	
	for(int i=0;i<puertos;i++){
		cout<<"Digite el nombre del puerto "<<i+1<<endl;
		cin>>nombrePuerto[i];
	}
	llenarBarco(disponibilidad,marca,puertoCarga,peso,tipoArticulo,nombrePuerto,puertos);
	cantidadContenedores(disponibilidad);
	contenedorOrdenado(puertoCarga,nombrePuerto,puertos,disponibilidad);
	listadoEconomico(marca,disponibilidad);
	listadoPremium(marca,disponibilidad);
	
	string nombre;
	
	cout<<"\nDigite el nombre de la marca que guardo el contenedor: "<<endl;
	cin>>nombre;
	valorAPagar(nombre,marca,disponibilidad);
	
	cout<<"\n6.promedio del peso de los contenedores: "<<promedioPeso(peso,disponibilidad)<<endl;
	
	cout<<"\n7.La Fila que lleva mas carga en el barco es: fila "<<masCarga(peso,disponibilidad)<<endl;
	
	cout<<"\n8.La columna que lleva menos carga en el barco es: columna "<<menosCarga(peso,disponibilidad)<<endl;
	
	string tipo;
	cout<<"\nDigite el tipo de articulo que busca en los contenedores: \nA: Alimentos\nB:Dispositivos electronicos \nC:Ropa"<<endl;
	cin>>tipo;
	
	cout<<"\n9.La cantidad de contenedores de tipo "<<tipo<<" en el barco son: "<<tipoContenedor(tipoArticulo,disponibilidad,tipo)<<endl;

	string puerto;
	cout<<"\nDigite el nombre del puerto de origen: "<<endl;
	cin>>puerto;
	cout<<"\n10.El promedio de peso del puerto "<<puerto<<" es: "<<promedioPuerto(puertoCarga,disponibilidad,peso,puerto)<<endl;
	
	cout<<"\n11.La marca que lleva el contenedor mas pesado: "<<marcaPesada(marca,disponibilidad,peso)<<endl;
	
	cout<<"\n12.La marca que lleva el contenedor mas liviano: "<<marcaLiviana(marca,disponibilidad,peso)<<endl;
	return 0;
}

