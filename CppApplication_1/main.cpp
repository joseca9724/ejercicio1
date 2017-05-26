/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Josec
 *
 * Created on 26 de mayo de 2017, 2:11
 */


#include <iostream>
#include <stddef.h>
#include <malloc.h>

using namespace::std;

struct nodo{
	char dato;
	nodo*siguiente;
	
}*primero,*ultimo;

void insertarNodo();
void desplegarLista();
void buscarNodo();
void modificarNodo();
void eliminarNodo();

int main (){
	insertarNodo();
	insertarNodo();
	insertarNodo();
	
	desplegarLista();
	buscarNodo();
	modificarNodo();
	
	desplegarLista();
	
	eliminarNodo();
	
	desplegarLista();
	return 0;
}

void insertarNodo(){
	nodo* nuevo=new nodo();
	cout<<"Ingrese el dato que tendra el nodo: ";
	cin>>nuevo->dato;
	
	if (primero==NULL){
		primero=nuevo;
		primero->siguiente=primero;
		ultimo=primero;
	}else{
		ultimo->siguiente=nuevo;
		nuevo->siguiente=primero;
		ultimo=nuevo;
	}
	cout<<"\n Nodo Ingresado \n\n";
}

void buscarNodo(){
	nodo*actual=new nodo();
	actual=primero;
	bool encontrado=false;
	char nodoBuscado='a';
	cout<<" \n Ingrese el dato a buscar: ";
	cin>>nodoBuscado;
	if(primero!=NULL){
		do{
			
			if(actual->dato==nodoBuscado){
				cout<<"\n El nodo con el dato ( "<<nodoBuscado<<" ) Encontrado \n\n";
				encontrado=true;
			}
			actual=actual->siguiente;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout<<"\n Nodo no Encontrado \n\n";
		}
	}else{
		cout<<"\n La lista se encuentra vacia \n\n";
	}
}

void modificarNodo(){
	nodo*actual=new nodo();
	actual=primero;
	bool encontrado=false;
	char nodoBuscado='a';
	cout<<"\n Ingrese el dato a buscar para modificar: ";
	cin>>nodoBuscado;
	if(primero!=NULL){
		do{
			
			if(actual->dato==nodoBuscado){
				cout<<"\n El nodo con el dato ( "<<nodoBuscado<<" ) Encontrado \n\n";
				cout<<"\n Ingrese el nuevo dato para este nodo: ";
				cin>>actual->dato;
				cout<<"\n Nodo Modificado \n\n";
				encontrado=true;
			}
			
			actual=actual->siguiente;
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout<<"\n Nodo no Encontrado \n\n";
		}
	}else{
		cout<<"\n La lista se encuentra vacia \n\n";
	}
}

void eliminarNodo(){
	nodo*actual=new nodo();
	actual=primero;
	nodo*anterior=new nodo();
	anterior=NULL;
	bool encontrado=false;
	char nodoBuscado='a';
	cout<<" \n Ingrese el dato a eliminar: ";
	cin>>nodoBuscado;
	if(primero!=NULL){
		do{
			
			if(actual->dato==nodoBuscado){
				cout<<"\n El nodo con el dato ( "<<nodoBuscado<<" ) Encontrado \n\n";
				
				if(actual==primero){
					primero=primero->siguiente;
					ultimo->siguiente=primero;
				}else if(actual==ultimo){
					anterior->siguiente=primero;
					ultimo=anterior;
				}else{
					anterior->siguiente=actual->siguiente;
				}
				cout<<"\n Nodo Eliminado \n\n";
				encontrado=true;
			}
			anterior=actual;
			actual=actual->siguiente;
			
		}while(actual!=primero && encontrado != true);
		if(!encontrado){
			cout<<"\n Nodo no Encontrado \n\n";
		}
	}else{
		cout<<"\n La lista se encuentra vacia \n\n";
	}
}

void desplegarLista(){
	nodo*actual=new nodo();
	actual=primero;
	if(primero!=NULL){
		do{
			cout <<"\n "<< actual->dato;
			actual=actual->siguiente;
		}while(actual!=primero);
	}else{
		cout<<"\n La lista esta vacia \n\n";
	}
}

