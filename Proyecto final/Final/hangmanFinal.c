//Código realizado por Cecilia Torres, las referencias se encuentran
//al final del documento.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "words.h"

//Prototipo o firma
void header();
void instrucciones();
void ingles();
void español();
void francés();
void mode();

void header()
{
    //Mensaje de bienvenida
    printf("\n");
    printf(" @    @    @@    @   @   @@@@  @   @    @@    @   @ \n");
    printf(" @    @   @  @   @@  @  @      @@ @@   @  @   @@  @ \n");
    printf(" @ @@ @  @ @@ @  @ @ @  @  @@  @ @ @  @ @@ @  @ @ @ \n");
    printf(" @    @  @    @  @  @@  @   @  @   @  @    @  @  @@ \n");
    printf(" @    @  @    @  @   @   @@@   @   @  @    @  @   @ \n\n");
}

void ingles()
{
    //Inicializa el generador de números aleatorios
    srand(time(NULL));

    //Índice para la palabra elegida aleatoriamente
    int randomI = rand() % 10;

    //Definición de variables
    int correctGuess = 0;
    int oldCorrect = 0;
    int intentos = 7;
    int salir = 0;
    int guiones = 0;
    int reguessed = 0;
    char guess[16];
    char inputLetter;

    //Length de una palabra
    int wordLen = strlen(en_words[randomI]);

    //Lista de palabras usadas
    int letterGuessed[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //Mientras la letra adivinada sea menor al largo de la palabra...
    while (correctGuess < wordLen)
    {
        printf("\n\nPalabra por adivinar: ");
        //Imprimir los guiones correspondientes al largo de la palabra
        for (guiones = 0; guiones < wordLen; guiones++)
        {
            //Si la letra adivinada se encuentra en la palabra, cambiar el guión por ella  
            if (letterGuessed[guiones] == 1)
            {
                printf("%c", en_words[randomI][guiones]);
            }
            //Si no, dejar el guión
            else
            {
                printf("_");
            }
        }

        printf("\n");
        printf("\nLetras adivinadas : %d\n", correctGuess);
        printf("\nAdivine una letra: ");
        fgets(guess, 16, stdin);

        //Salir del juego si el usuario así lo indica
        if (strncmp(guess, "salir", 5) == 0)
        {
            salir = 1;
            break;
        }

        //Guardar la letra ingresada a la lista
        inputLetter = guess[0];
        reguessed = 0;

        printf("\nLetra ingresada: %c\n", inputLetter);

        oldCorrect = correctGuess;

        for(guiones = 0; guiones < wordLen; guiones++)
        {
            //Si ya se había ingresado la letra en el array, ignorar y seguir
            if (letterGuessed[guiones] == 1)
            {
                 if(en_words[randomI][guiones] == inputLetter)
                 {
                     reguessed = 1;
                     break;
                }
                continue;
            }

            /* Si la letra ingresada por el usuario es igual al array de carácteres,
            por ejemplo 'abide', en la posición de guiones, entonces sabemos que la 
            letra fue adivinada correctamente. */
            if (inputLetter == en_words[randomI][guiones])
            {
                letterGuessed[guiones] = 1;
                correctGuess++;
            }
        }

        //Si la letra ingresada no se encuentra en la palabra, quitar un intento
        if (oldCorrect == correctGuess && reguessed == 0)
        {
            intentos--;
            printf("No está en la palabra\n");

            //Si nos quedamos sin vidas...
            if (intentos == 0)
            {
                break;
            }
        }
        //Si dicha letra ya había sido utilizada...
        else if (reguessed == 1)
        {
            printf("Ya habías adivinado esa letra\n");
        }
        //Si la letra no había sido utilizada...
        else
        {
            printf("Adivinaste correctamente\n");
        }
    }

    //Salir del juego en caso de que le usuario lo indique
    if (salir == 1)
    {
        system("clear");
        printf("Elegiste salir del juego\n\n");
    }
    //En caso de perder...
    else if (intentos == 0)
    {
        printf("\n\n\aHas perdido, la palabra era: %s\n", en_words[randomI]);
        printf("\n\n");
    }
    //En caso de ganar...
    else
    {
        printf("\n\n\a¡Felicidades! Has ganado\n\n");
    }
    return;
}

void español()
{
    srand(time(NULL));

    int randomI = rand() % 10;

    int correctGuess = 0;
    int oldCorrect = 0;
    int intentos = 7;
    int salir = 0;
    int guiones = 0;
    int reguessed = 0;
    char guess[16];
    char inputLetter;

    int wordLen = strlen(esp_words[randomI]);

    int letterGuessed[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (correctGuess < wordLen)
    {
        printf("\n\nPalabra por adivinar: ");
        for (guiones = 0; guiones < wordLen; guiones++)
        { 
            if (letterGuessed[guiones] == 1)
            {
                printf("%c", esp_words[randomI][guiones]);
            }
            else
            {
                printf("_");
            }
        }

        printf("\n");
        printf("\nLetras adivinadas : %d\n", correctGuess);
        printf("\nAdivine una letra: ");
        fgets(guess, 16, stdin);

        if (strncmp(guess, "salir", 5) == 0)
        {
            salir = 1;
            break;
        }

        inputLetter = guess[0];
        reguessed = 0;

        printf("\nLetra ingresada: %c\n", inputLetter);

        oldCorrect = correctGuess;

        for(guiones = 0; guiones < wordLen; guiones++)
        {
            if (letterGuessed[guiones] == 1)
            {
                 if(esp_words[randomI][guiones] == inputLetter)
                 {
                     reguessed = 1;
                     break;
                }
                continue;
            }
            if (inputLetter == esp_words[randomI][guiones])
            {
                letterGuessed[guiones] = 1;
                correctGuess++;
            }
        }

        if (oldCorrect == correctGuess && reguessed == 0)
        {
            intentos--;
            printf("No está en la palabra\n");

            if (intentos == 0)
            {
                break;
            }
        }
        else if (reguessed == 1)
        {
            printf("Ya habías adivinado esa letra\n");
        }
        else
        {
            printf("Adivinaste correctamente\n");
        }
    }

    if (salir == 1)
    {
        system("clear");
        printf("Elegiste salir del juego\n\n");
    }
    else if (intentos == 0)
    {
        printf("\n\n\aHas perdido, la palabra era: %s\n", esp_words[randomI]);
        printf("\n\n");
    }
    else
    {
        printf("\n\n\a¡Felicidades! Has ganado\n\n");
    }
    return;
}

void francés()
{
    srand(time(NULL));

    int randomI = rand() % 10;

    int correctGuess = 0;
    int oldCorrect = 0;
    int intentos = 7;
    int salir = 0;
    int guiones = 0;
    int reguessed = 0;
    char guess[16];
    char inputLetter;

    int wordLen = strlen(fran_words[randomI]);

    int letterGuessed[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    while (correctGuess < wordLen)
    {
        printf("\n\nPalabra por adivinar: ");
        for (guiones = 0; guiones < wordLen; guiones++)
        { 
            if (letterGuessed[guiones] == 1)
            {
                printf("%c", fran_words[randomI][guiones]);
            }
            else
            {
                printf("_");
            }
        }

        printf("\n");
        printf("\nLetras adivinadas : %d\n", correctGuess);
        printf("\nAdivine una letra: ");
        fgets(guess, 16, stdin);

        if(strncmp(guess, "salir", 5) == 0)
        {
            salir = 1;
            break;
        }

        inputLetter = guess[0];
        reguessed = 0;

        printf("\nLetra ingresada: %c\n", inputLetter);

        oldCorrect = correctGuess;

        for(guiones = 0; guiones < wordLen; guiones++)
        {
            if (letterGuessed[guiones] == 1)
            {
                 if(fran_words[randomI][guiones] == inputLetter)
                 {
                     reguessed = 1;
                     break;
                }
                continue;
            }
            if (inputLetter == fran_words[randomI][guiones])
            {
                letterGuessed[guiones] = 1;
                correctGuess++;
            }
        }

        if (oldCorrect == correctGuess && reguessed == 0)
        {
            intentos--;
            printf("No está en la palabra\n");

            if (intentos == 0)
            {
                break;
            }
        }
        else if (reguessed == 1)
        {
            printf("Ya habías adivinado esa letra\n");
        }
        else
        {
            printf("Adivinaste correctamente\n");
        }
    }

    if (salir == 1)
    {
        system("clear");
        printf("Elegiste salir del juego\n\n");
    }
    else if (intentos == 0)
    {
        printf("\n\n\aHas perdido, la palabra era: %s\n", fran_words[randomI]);
        printf("\n\n");
    }
    else
    {
        printf("\n\n\a¡Felicidades! Has ganado\n\n");
    }
    return;
}

void mode()
{
    int choice;
    do
    {
        //Opciones menu 
        printf("\t\tSeleccione el idioma con el que desee jugar:\n");
        printf("\t\t1: Español\n");
        printf("\t\t2: Inglés\n");
        printf("\t\t3: Francés\n");
        printf("\t\t4: Salir del juego\n\n");
        scanf("%d",&choice);

        switch(choice)
        {
            //En caso de elegir español
            case 1:
                system("clear");
                printf("Elegiste jugar con palabras en español\n\n");
                español();
                break;
            //En caso de elegir inglés
            case 2:
                system("clear");
                printf("ELegiste jugar con palabras en inglés\n\n");
                ingles();
                break;
            //En caso de elegir francés
            case 3:
                system("clear");
                printf("Elegiste jugar con palabras en francés\n\n");
                francés();
                break;
            //En caso de elegir salir
            case 4:
                system("clear");
                printf("Elegiste salir del juego\n\n");
                break;
            //Si ninguno de los casos anteriores aplica...
            default:
                system("clear");
                printf("Opción no válida\n\n");
        }
    } while (choice!=4);
}

void instrucciones()
{
    //Menú
    int op, op2;
    do
    {
        //Mostrar opciones
        printf("\t\tSeleccione una opción:\n");
        printf("\t\t1: Jugar\n");
        printf("\t\t2: Instrucciones\n");
        printf("\t\t3: Salir\n");
        scanf("%d", &op);

        switch(op)
        {
            //En caso de elegir jugar
            case 1:
                system("clear");
                printf("Elegiste Jugar\n\n");
                mode();
                break;
            //En caso de elegir instrucciones
            case 2:
                system("clear");
                printf("Elegiste Instrucciones\n\n");
                do
                {
                    printf("\t\t - - - - - - - - - - - - - - - - - - - - - - \n");
                    printf("\t\t| Hangman es un juego en el que tienes que  |\n");
                    printf("\t\t| adivinar la palabra. Debes escribir la    |\n");
                    printf("\t\t| letra que creas estará en la palabra a    |\n");
                    printf("\t\t| Contarás con seis intentos, si los gastas |\n");
                    printf("\t\t| todos y no adivinas la palabra, habrás    |\n");
                    printf("\t\t| perdido. Si adivinas la palabra y todavía |\n");
                    printf("\t\t| cuentas con intentos, habrás ganado. Si   |\n");
                    printf("\t\t| deseas salir una vez iniciado el juego,   |\n");
                    printf("\t\t| escribe la palabra 'salir'.               |\n");
                    printf("\t\t - - - - - - - - - - - - - - - - - - - - - - \n\n");
                    printf("Presiona '1' si quieres regresar al menú principal.\n");
                    scanf("%d", &op2);
                    switch(op2)
                    {
                        //Si el usuario presiona 1
                        case 1:
                            system("clear");
                            printf("Elegiste regresar al menú principal\n\n");
                            break;
                        // Si no...
                        default:
                            system("clear");
                            printf("Opción no válida\n\n");
                    }
                } while(op2 != 1);
                break;
            //En caso de elegir salir del juego
            case 3:
                system("clear");
                printf("Elegiste Salir\n\n");
                break;
            //Si ninguna de las opciones anteriores aplica...
            default:
                system("clear");
                printf("Opción no válida\n\n");
        }
    } while(op == 2);

}

int main()
{
    //Mostrar el header del juego y luego la función instrucciones
    header();
    instrucciones();
    return 0;
}
