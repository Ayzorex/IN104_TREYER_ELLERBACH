#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "tools.h"
#include "load_file.h"
#include "resolve.h"
#include "jeu_auto.h"
#include "jeu_auto_naif.h"
#include "jeu.h"

void get_data(char* fname, unsigned int N, int number_test, char type)
{  
    double time_spent;
    //int list_turn[number_test];
    int turn;
    FILE* fd=fopen("data_turn.txt","wb");
    FILE* ft = fopen("data_time.txt","wb");
    for(int i = 0;i<number_test;i++)
    {
        time_spent = 0.0;
        clock_t begin = clock();
        if(type == '1')
        {
            turn = play_alone_naif(fname,N);
        }
        if(type == '2')
        {
            turn = play_alone(fname,N);
        }
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        //printf("%f\n",time_spent);
        if(turn!=100)
        {
            fprintf(fd,"%d\n",turn);
            fprintf(ft,"%f\n",time_spent);
        }
    }
    fclose(fd);
    fclose(ft);
}

int main(int argc, char *argv[])
{
    char* fname = argv[1];
    srand(time(NULL));
    printf("que voulez vous faire ?\n");
    printf("1 - jouer au wordle\n");
    printf("2 - utiliser l'aide à la résolution\n");
    printf("3 - simuler des parties de wordle\n");
    printf("4 - trouver le meilleur premier mot\n");
    printf("entrée le numéro corespondant\n");
    char buffer;
    char buffer_N[2];
    scanf(" %c",&buffer);
    if (buffer == '1')
    {
        printf("avec quelle taille de mot voules vous jouer ?\n");
        scanf("%s",buffer_N);
        unsigned int N = atoi(buffer_N);
        play_wordle(N,fname);
    }
    if (buffer == '2')
    {
        printf("avec quelle taille de mot voules vous jouer ?\n");
        scanf("%s",buffer_N);
        unsigned int N = atoi(buffer_N);
        resolve(fname,N);
    }
    if (buffer == '3')
    {
        printf("avec quelle taille de mot voules vous simuler ?\n");
        scanf("%s",buffer_N);
        unsigned int N = atoi(buffer_N);
        printf("avec quel modèle de résolution ?\n 1 - aléatoire\n 2 - théorie de l'information\n");
        char buffer_type;
        scanf(" %c",&buffer_type);
        printf("combien de partie voulez vous simuler ?\n");
        char buffer_test[8];
        scanf(" %s",buffer_test);
        int number_test = atoi(buffer_test);
        get_data(fname,N,number_test,buffer_type);
        printf("retrouvez les data de vos partie dans les fichier data_time.txt et data_turn.txt");
    }
    if (buffer == '4')
    {
        printf("ATTENTION, cet algorithme est très long pour une taille de mot supérieur à 5 (plus d'une demie heure)\n");
        printf("pour quelle taille de mot voulez vous chercher ?\n");
        scanf("%s",buffer_N);
        unsigned int N = atoi(buffer_N);
        double time_spent = 0.0;
        struct Array_and_size* array_and_size = get_word_array(fname,N);
        char** word_array = array_and_size->array;
        unsigned int size_dico = array_and_size->size;
        char** config_array = get_config_array(N);
        clock_t begin = clock();
        char* best_word =get_best_word(word_array,config_array,N,size_dico);
        clock_t end = clock();
        time_spent += (double) (end - begin)/ CLOCKS_PER_SEC;
        printf("le meilleur mot est : %s\n",best_word);
        printf("temps d'excution : %f\n",time_spent);
    }
    return(0);

}