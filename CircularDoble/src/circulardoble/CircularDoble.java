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
public class CircularDoble {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        ListasCD prueba=new ListasCD();
        
        prueba.ingresarNodo(1);
        prueba.ingresarNodo(2);
        prueba.ingresarNodo(3);
        prueba.ingresarNodo(4);
        
        prueba.imprimir();
        
        System.out.println(prueba.buscarNodo(3));
        System.out.println(prueba.buscarNodo(6));
        
        prueba.modificarNodo(3, 6);
        
        prueba.imprimir();
        
        System.out.println(prueba.buscarNodo(3));
        System.out.println(prueba.buscarNodo(6));
        
        prueba.eliminarNodo(2);
        
        prueba.imprimir();
    }
    
}
