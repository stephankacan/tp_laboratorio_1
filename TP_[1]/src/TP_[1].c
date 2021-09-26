/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Stephan Kacan
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style

 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "KacanZanov.h"



int main()
{

    int num1=0;
    int num2=0;

    int resultadoSuma;
    int resultadoResta;

    float resultadoDivision;
    float resultadoMultiplicacion;

    long int resultadoFactorialA;
    long int resultadoFactorialB;

    int flatNumeroUno=0;
    int flatNumeroDos=0;
    int flatCalculos=0;

    char seguir= 's';

    while(seguir=='s')
    {
        switch(menu(num1,num2))
        {
        case 1:
            printf("Ingrese el primer numero:(A)  ");



            scanf("%d",&num1);
            flatNumeroUno=1;
            break;
        case 2:
            if (flatNumeroUno==1)
            {
                printf("ingrese el segundo numero:(B)  ");


                scanf("%d",&num2);
                flatNumeroDos=1;
            }
            else
            {
                printf ("Ingresa el primer numero para continuar\n" );

                system("pause");

            }
            break;
        case 3:
            if (flatNumeroUno==1 && flatNumeroDos==1)
            {
                printf ("Calculos realizados con exito!!\n");

                system("pause");

                resultadoSuma=suma(num1,num2);
                resultadoResta=resta(num1,num2);
                resultadoDivision=division(num1,num2);
                resultadoMultiplicacion=multiplicacion(num1,num2);
                resultadoFactorialA=factorial(num1);
                resultadoFactorialB=factorial(num2);
                flatCalculos=1;
            }
            else
            {
                printf("Para resolver calculos,debes ingresar los numeros\n");

                system("pause");


            }
            break;
        case 4:
            if(flatNumeroUno==1 && flatNumeroDos==1 && flatCalculos==1)
            {
                printf("El resultado de la suma es %d\n",resultadoSuma);
                printf("El resultado de la resta es %d\n",resultadoResta);
                if(num2==0)
                {
                    printf("No se puede dividir por 0\n");
                }
                else
                {
                    resultadoDivision=division(num1,num2);
                    printf("El resultado de la division es %.2f\n",resultadoDivision);
                }

                printf("El resultado de la multiplicacion es %.f\n",resultadoMultiplicacion);
                printf("El resultado de factorial es %ld \n",resultadoFactorialA);
                printf("El resultado de factorial es %ld \n",resultadoFactorialB);
                flatNumeroUno=0;
                flatNumeroDos=0;
                flatCalculos=0;

                system("pause");





            }
            else
            {
                printf("Para ver los resultados,primero debes RESOLVERLOS! con la opcion 3\n");


                system("pause");


            }

            break;
        case 5:

            printf("Vuelva Pronto");
            seguir='n';
            break;
        }
    }
    return 0;
}
