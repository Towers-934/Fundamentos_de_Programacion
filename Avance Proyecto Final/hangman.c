#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "words.h"

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

int game()
{
    srand(time(NULL));

    //Índice para palabra elegida aleatoriamente
    int randomIndex = rand() % 6;

    int correctGuess = 0;
    int oldCorrect = 0;
    int intentos = 5;

    int wordLen = strlen(en_words[randomIndex]);

    int letterGuessed[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    int salir = 0;

    int guiones = 0;
    int reguessed = 0;

    char guess[16];
    char inputLetter;

    //printf("guessWords: %s, randomIndex: %d, wordLen: %d\n", en_words[randomIndex], randomIndex, wordLen);

    while (correctGuess < wordLen)
    {
        printf("\n\nPalabra por adivinar: ");
        for (guiones = 0; guiones < wordLen; guiones++)
        {
            if (letterGuessed[guiones] == 1)
            {
                printf("%c", en_words[randomIndex][guiones]);
            }
            else
            {
                printf("_");
            }
        }

        printf("\n");
        printf("\ncorrectGuess so far: %d\n", correctGuess);
        printf("\nAdivine una letra: ");
        fgets(guess, 16, stdin);

        if (strncmp(guess, "salir", 5) == 0)
        {
            salir = 1;
            break;
        }

        inputLetter = guess[0];
        reguessed = 0;

        printf("\ninputLeter: %c\n", inputLetter);

        oldCorrect = correctGuess;

        for (guiones = 0; guiones < wordLen; guiones++)
        {
            //Si ya se había ingresado la letra en el array. ignorar y seguir
            if (letterGuessed[guiones] == 1)
            {
                 if(en_words[randomIndex][guiones] == inputLetter)
                 {
                     reguessed = 1;
                     break;
                }
                continue;
            }

            /* Si la letra ingresada por el usuario es igual al array de carácteres,
            por ejemplo 'tipsy', en la posición de guiones, entonces sabemos que la 
            letra fue adivinada correctamente. */
            if (inputLetter == en_words[randomIndex][guiones])
            {
                letterGuessed[guiones] = 1;
                correctGuess++;
            }
        }

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
        printf("Has perdido, la palabra era: %s\n", en_words[randomIndex]);
    }
    else
    {
        printf("¡Felicidades! Has ganado\n");
    }
    return 0;
}

/*void mode()
{
    int choice;
    do
    {
        printf("\t\tSeleccione el idioma con el que desee jugar:\n");
        printf("\t\t1: Español\n");
        printf("\t\t2: Inglés\n");
        printf("\t\t3: Francés\n");
        printf("\t\t4: Regresar al menú principal\n\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                system("clear");
                printf("Elegiste jugar con palabras en español\n\n");
                break;
            case 2:
                system("clear");
                printf("ELegiste jugar con palabras en inglés\n\n");
                ingles();
                break;
            case 3:
                system("clear");
                printf("Elegiste jugar con palabras en francés\n\n");
                break;
            case 4:
                system("clear");
                printf("Elegiste regresar al menú principal\n\n");
                break;
            default:
                system("clear");
                printf("Opción no válida\n\n");
        }
    } while (choice!=4);
    
}*/

int instructions()
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

        switch (op)
        {
        case 1:
            system("clear");
            printf("Elegiste Jugar\n\n");
            game();
            break;
        case 2:
            system("clear");
            printf("Elegiste Instrucciones\n\n");
            do
            {
                printf("\t\t - - - - - - - - - - - - - - - - - - - - - -\n");
                printf("\t\t| Hangman es un juego en el que tienes que |\n");
                printf("\t\t| adivinar la palabra. Debes escribir la   |\n");
                printf("\t\t| letra o palabra que creas estará en la   |\n");
                printf("\t\t| palabra a adivinar. Contarás con seis    |\n");
                printf("\t\t| intentos, si los gastas todos y no       |\n");
                printf("\t\t| adivinas la palabra, habrás perdido.     |\n");
                printf("\t\t| Si adivinas la palabra y todavía cuentas |\n");
                printf("\t\t| con intentos, habrás ganado.             |\n");
                printf("\t\t - - - - - - - - - - - - - - - - - - - - - -\n\n");
                printf("Presiona '1' si quieres regresar al menú principal.\n");
                scanf("%d", &op2);
                switch (op2)
                {
                case 1:
                    system("clear");
                    printf("Elegiste regresar al menú principal\n\n");
                    break;
                default:
                    system("clear");
                    printf("Opción no válida\n\n");
                }
            } while (op2 != 1);
            break;
        case 3:
            system("clear");
            printf("Elegiste Salir\n\n");
            break;
        default:
            system("clear");
            printf("Opción no válida\n\n");
        }
    } while (op == 2);
    return 0;
}

int main()
{
    header();
    instructions();
    return 0;
}
