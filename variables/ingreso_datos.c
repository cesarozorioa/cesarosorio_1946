#include <stdio.h>


int main()
{
    int num;
    
    char letra;   
    float peso;
    double altura;
    printf("Ingrese un valor entero: ");
    scanf("%d",&num);     
    printf("Ingrese un valor char: ");
    fflush(stdin);    
    scanf("%c",&letra);   
    printf("Ingrese un valor float: ");
    scanf("%f",&peso);
    printf("Ingrese un valor double: ");
    scanf("%lf",&altura);
    printf("Valores ingresados:\n");
    printf("El valor entero es: %d\n",num);  
    printf("El valor en octal es %o\n",num); 
    printf("El valor en hexadecimal es %x\n",num);
    printf("El valor char es %c\n",letra);   
    printf("El valor float es %f\n",peso);
    printf("El valor double es %lf\n",altura);
    return 0;
}