#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hof.h"
#include <stdbool.h>
#include <ctype.h>
int load(struct player list[])  //https://www.w3resource.com/c-programming-exercises/file-handling/c-file-handling-exercise-5.php
{
     FILE * input1 = fopen("score", "r");
     if(input1 == NULL) return -1;
     int count = 0;
     char c;
        for (c = (char)getc(input1); c != EOF; c = (char)getc(input1))
        if (c == '\n')
            count = count + 1;
    fclose(input1);
     FILE * input2 = fopen("score", "r");
    for(int i = 0; i < count; i++)
        {
            fscanf(input2,"%s %d", list[i].name, &list[i].score); 
        }
    fclose(input2);
    struct player temp;
    for(int j = 0; j < count ; j++)//sort
    {
        for(int k = 0; k < (count - j); k++)
        {
            if (list[k].score < list[k+1].score)
            {
                temp = list[k];
                list[k] = list[k + 1];
                list[k + 1] = temp;
            } 
        }
    }
    return count;
}
bool save(const struct player list[], const int size) //done
{  
    FILE *input1 = fopen("score", "r");
    if(input1 == NULL) return false;
    int i = 0;
    struct player temp[10];
    for(i = 0; i<size; i++)
    {
        fscanf(input1,"%s %d", temp[i].name, &temp[i].score); 
        if(fgetc(input1) == EOF) break;
    }
    struct player change;
    for(int j = 0; j<i-1; j++)
    {
        for (int k = 0; k < (i - 1-j); k++)
        {
            if (temp[k].score < temp[k+1].score)
            {
                change = temp[k];
                temp[k] = temp[k + 1];
                temp[k + 1] = change;
            } 
        }
    }
    fclose(input1);
     FILE * pFile;
     pFile = fopen("score","w");
     for(int k = 0; k < i; k++)
     {
         fprintf (pFile, "%s %d\n",temp[k].name, temp[k].score);
     }
    fclose(pFile);
    return true;
}
bool add_player(struct player list[], int* size, const struct player player)
{
      if(*size == 0)
      {
           list[0] = player;
      }
      if(*size >= 10 && list[*size-1].score > player.score) return false;
      if(*size>=10 && list[*size-1].score <= player.score)
      {
         list[*size-1] = player;
      }
      if(*size < 10)
      {
            list[*size] = player;
            *size+=1;
      }
      struct player change;
      for(int j = 0; j<*size-1; j++)
      { 
        for (int k = 0; k < (*size - 1 - j); k++)
        {
            if (list[k].score < list[k+1].score)
            {
                change = list[k];
                list[k] = list[k + 1];
                list[k + 1] = change;
            } 
        }
     }
     bool exit = false;
     for(int j = 0; j<*size-1; j++)
      { 
        for (int k = 0; k < (*size - 1 - j); k++)
        {
            if (list[k].score == list[k+1].score && list[k+1].score == player.score)
            {
                change = list[k];
                list[k] = list[k + 1];
                list[k + 1] = change;
                exit = true;
                break;
            } 
        }
        if(exit == true) break;
      }
     return true;    
}
