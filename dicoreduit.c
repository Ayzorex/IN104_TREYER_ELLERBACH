#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



unsigned int build_dico(char* fname,char* word_size)
{
    FILE* dico = fopen(fname,"rb");

    char new_name[] = "dico_";
    strcat(new_name,word_size);
    strcat(new_name,".txt");
    FILE* new_dico = fopen(new_name,"wb");
    char buffer[128];

    int N = atoi(word_size);
    unsigned int size_dico = 0;
    
    while (! feof(dico))
    {
        fscanf(dico,"%s",buffer);
        if (strlen(buffer)==N)
        {
            fprintf(new_dico,"%s\n",buffer);
            size_dico++;
        }
    }
    fclose(dico);
    fclose(new_dico);
    return(size_dico);
}

int main(int argc, char *argv[])
{
    char* fname = argv[1];
    printf("quelle taille de mot voulez vous ?\n");
    char buffer[4];
    scanf("%s",buffer);
    unsigned int size = build_dico(fname,buffer);
    printf("le dico construit s'appelle dico_%s_.txt, sa taille est %d\n",buffer,size);
}