# include <iostream>
# include <stdlib.h>
using namespace std;
struct listas
{
	int valor;
	listas *direccionA;
};
listas *listao,*listaaux, *anterior;
void ingreso();
void mostrar();
void eliminar();
void buscar();
int main()
{
	int opcion;
	while(true){
		cout<<"1 Ingreso de datos a la Lista"<<endl;
		cout<<"2 Leer datos de la Lista"<<endl;
		cout<<"3 Eliminar datos de la Lista"<<endl;
		cout<<"4 Buscar datos en la Lista"<<endl;
		cin>>opcion;
		switch(opcion){
			case 1:{
				ingreso();
				break;
			}
			case 2:{
				mostrar();
				break;
			}
			case 3:{
				eliminar();
				break;
			}
			case 4:{
				buscar();
				break;
			}

			
		}
	}
}
void ingreso(){
	if(listao==NULL){
		listao=new(listas);
		cout<<"Mi Direccion "<<listao<<endl;
		cout<<"Ingrese PRIMER dato a la Lista"<<endl;
		cin>>listao->valor;
		cout<<"Dato ingresado correctamente"<<endl;
		listao->direccionA=NULL;
		cout<<"Direccion Anterior "<<listao->direccionA<<endl;
		return;
	}
	listaaux=new(listas);
	cout<<"Ingrese dato a la Lista"<<endl;
	cout<<"Mi Direccion "<<listaaux<<endl;
	cin>>listaaux->valor;
	cout<<"Dato ingresado correctamente"<<endl;
	listaaux->direccionA=listao;
	cout<<"Direccion Anterior "<<listaaux->direccionA<<endl;
	listao=listaaux;
}
void mostrar(){
	if(listao==NULL){
		cout<<"No hay datos en la Lista"<<endl;
	}
	listaaux=listao;
	cout<<"Los datos de la Lista son: "<<endl;
	while(listaaux!=NULL){
		cout<<listaaux->valor<<endl;
		listaaux=listaaux->direccionA;
	}
	cout<<"FIN"<<endl;
}
void buscar(){
	if(listao==NULL){
		cout<<"La Lista esta vacia"<<endl;
		return;
	}
	int buscardatos;
	bool encontrado=false;
	listaaux=listao;
	cout<<"Ingrese dato a buscar"<<endl;
	cin>>buscardatos;
	while(listaaux!=NULL){
		if(buscardatos==listaaux->valor){
			cout<<"Encontrador, el valor es; "<<listaaux->valor<<endl;
			encontrado=true;
			break;
		}
		listaaux=listaaux->direccionA;
	}
	if(encontrado==false){
		cout<<"No se encontro el valor"<<endl;
	}
}
void eliminar(){
	int buscardato;
	bool encontrado=false;
	if(listao==NULL){
		cout<<"No hay datos en la lista"<<endl;
		listaaux=NULL;
		return;
	}
	listaaux=listao;
	anterior=listaaux;
	cout<<"Ingrese el dato a eliminar"<<endl;
	cin>>buscardato;
	while(listaaux!=NULL){
		if(buscardato==listaaux->valor){
			cout<<"Encontrado el valor a eliminar es; "<<listaaux->valor<<endl;
			if(listaaux==listao){
				listao=listao->direccionA;
			}
			else{
				anterior->direccionA=listaaux->direccionA;
			}
			delete(listaaux);
			encontrado=true;
			break;
		}
		anterior=listaaux;
		listaaux=listaaux->direccionA;
	}
	if(listaaux=NULL){
		listao=NULL;
	}
	if(encontrado=false){
		cout<<"no se encontro el valor"<<endl;
	}
}
