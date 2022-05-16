#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include "dicoreduit.h"
#include "load_file.h"
#include "chain.h" 
#include <time.h>
#include "resolve.h"
#include "jeu.h"
#include "tools.h"

int play_alone(char* fname,unsigned int N)
{
    char* best_first_array[20];
    best_first_array[2] = "AU";
    best_first_array[3] = "AIE";
    best_first_array[4] = "SAIE";
    best_first_array[5] = "RAIES";
    best_first_array[6] = "TARIES";
    struct Array_and_size* array_and_size = get_word_array(fname,N);
    char** word_array = array_and_size->array;
    unsigned int size_dico = array_and_size->size;
    char** config_array = get_config_array(N);
    int turn = 1;
    char* secret_word = word_select(word_array,size_dico,N);
    char* best_word;
    if(N<7)
    {
        best_word = best_first_array[N];
    }
    else
    {
        best_word = get_best_word(word_array,config_array,N,size_dico);
    }
    printf("mot joué : %s\n",best_word);
    char* config_answer = analyse(best_word,secret_word,N);
    printf("config obtenue: %s\n\n",config_answer);
    struct Array_and_size *new_word_array_and_size = create_new_word_array(best_word,config_answer,word_array,size_dico,N);
    char ** new_word_array = new_word_array_and_size->array;
    unsigned int new_size = new_word_array_and_size->size;
    //printf_array(word_array,new_size);
    while (new_size!=1 && turn<100)
    {
        //printf("%d\n",new_size);
        if(new_size!=0) best_word=get_best_word(new_word_array,config_array, N, new_size);
        config_answer = analyse(best_word,secret_word,N);
        printf("mot joué : %s\n",best_word);
        printf("config obtenue : %s\n\n",config_answer);
        //printf_array(word_array,new_size);
        new_word_array_and_size = create_new_word_array(best_word,config_answer,word_array,new_size,N);
        new_size=new_word_array_and_size->size;
        turn++;
        free(new_word_array_and_size);
        free(config_answer);
    }
    if(turn<100)
    {
        printf("le mot obtenu est : %s (mot secret était : %s)\n",word_array[0],secret_word);
        printf("mot trouvé en %d coups\n",turn);
    }
    else
    {
        printf("echec pour trouver le mot\n");
    }
    return(turn);
}