/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package circulardoble;

/**
 *
 * @author Josec
 */
public class ListasCD {
    
    Nodo primero;
    Nodo ultimo;
    
    public ListasCD(){
        this.primero=null;
        this.ultimo=null;
    }
    
    public void ingresarNodo(int n){
        Nodo nuevo=new Nodo();
        nuevo.dato=n;
        if(primero==null){
            primero=nuevo;
            primero.siguiente=primero;
            nuevo.anterior=ultimo;
            ultimo=nuevo;
        }
        else{
            ultimo.siguiente=nuevo;
            nuevo.siguiente=primero;
            nuevo.anterior=ultimo;
            ultimo=nuevo;
            primero.anterior=ultimo;
        }
    }
    public boolean buscarNodo(int n){
        Nodo actual=new Nodo();
        actual=ultimo;
        boolean encontrado= false;
        do{
            if(actual.dato==n)
                encontrado=true;
            actual=actual.anterior;
        }while(actual!=ultimo);
        return encontrado;
    }
    
    public void modificarNodo(int n, int nuevoDato){
        Nodo actual=new Nodo();
        
        actual=primero;
        do{
            
            if(actual.dato==n){
                actual.dato=nuevoDato;
            }
            actual=actual.siguiente;
            
        }while(actual!= primero);
    }
    
    public void eliminarNodo(int n){
        Nodo actual=new Nodo();
        Nodo anterior=new Nodo();
        
        actual=primero;
        anterior=ultimo;
        
        do{
            if(actual.dato==n){
                if(actual == primero){
                    primero=primero.siguiente;
                    ultimo.siguiente=primero;
                    primero.anterior=ultimo;
                }else if(actual==ultimo){
                    ultimo=anterior;
                    primero.anterior=ultimo;
                    ultimo.siguiente=primero;
                }
                else{
                    anterior.siguiente=actual.siguiente;
                    actual.siguiente.anterior=anterior;
                }
                
            }
            anterior=actual;
            actual=actual.siguiente;
        }while(actual!= primero);
        
    }
    
    public void imprimir(){
        Nodo actual=new Nodo();
        actual=primero;
        do{
            System.out.println(actual.dato);
            actual=actual.siguiente;
        }while(actual!=primero);
    }
}
