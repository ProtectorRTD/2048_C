#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "k.h"
#include <stdbool.h>
#include <ctype.h>
void add_random_tile(struct game *game){
    int row, col;
    // find random, but empty tile
    do{
        row = rand() % SIZE;
        col = rand() % SIZE;
    }while(game->board[row][col] != ' ');

    // place to the random position 'A' or 'B' tile
    if(rand() % 2 == 0){
        game->board[row][col] = 'A';
    }else{
        game->board[row][col] = 'B';
    }
}
bool update(struct game *game, int dy, int dx)
{
    char check_array[4][4];
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            check_array[i][j] = game->board[i][j];
        }
    }
    if(dy != 0 && dx != 0) return false;
    if(is_game_won(*game) == 1) return false; 
    if(dx == 0 && dy == 0) return false;
    if(dx < -1 || dx > 1 || dy < -1 || dy > 1) return false;
    int  k = 0;
    char number[] = "ABCDEFGHIJK";
    int ball[] = {4,8,16,32,64,128,256,512,1024,2048};
    if (dx == 0 && dy == -1) 
	{
            for (int x = 0; x < 4; x++)
            {
                for (int i = 0; i < 4; i++)
                {
                    k = 0;
                    for (int m = 0; m < 4; m++)
                    {
                        for (int z = 0; z < 4; z++)
                        {
                            if (game->board[z][x] == ' ' && z != 3)
                            {
                                game->board[z][x] = game->board[z + 1][x];
                                game->board[z + 1][x] = ' ';
                            }
                        }
                    }
                    if (game->board[i][x] == game->board[i + 1][x] && i != 3 && game->board[i][x] != ' ')
                    {
                        for (k = 0; k < strlen(number); k++)
                        {
                            if (game->board[i][x] == number[k]) 
                            {
                                    game->score += ball[k]; 
                                    break;
                            }
                        }
                        game->board[i][x] = number[k + 1];                      
                        if (i + 1 < 4) 
                        {
                            game->board[i + 1][x] = ' ';                      
                        }
                        else 
                        {
                            game->board[i][x] = ' ';
                        }
                    }
                }
            }
	}
        if (dx == 0 && dy == 1) //
    {
        for (int x = 0; x < 4; x++)
        {
            for (int i = 4; i > 0; --i)
            {
                k = 0;
                for (int m = 0; m < 4; m++)
                {
                    for (int z = 4; z > 0; --z)
                    {
                        if (game->board[z][x] == ' ')
                        {
                            game->board[z][x] = game->board[z - 1][x];
                            game->board[z - 1][x] = ' ';
                        }
                    }
                    if (i != 0 && game->board[i][x] != ' ' && game->board[i][x] == game->board[i - 1][x])
                    {
                        for (k = 0; k < strlen(number); k++)
                        {
                            if (game->board[i][x] == number[k]) 
                            {
                                    game->score += ball[k]; 
                                    break;
                            }
                        }
                        game->board[i][x] = number[k + 1];
                        game->board[i - 1][x] = ' ';
                    }
                }
            }
        }
    }
        if (dx == -1 && dy == 0)  //done
    {
        for (int y = 0; y < 4; y++)
        {
            for (int j = 0; j < 4; j++)
            {
                k = 0;
                for (int l = 0; l < 4; l++)
                {
                    for (int z = 0; z < 4; z++)
                    {
                        if (z != 3 && game->board[y][z] == ' ')
                        {
                            game->board[y][z] = game->board[y][z + 1];
                            game->board[y][z + 1] = ' ';
                        }
                    }
                }
            }
            for (int j = 0; j < 4; j++) 
            {
                    if (j != 3 && game->board[y][j] != ' ' && game->board[y][j] == game->board[y][j + 1])
                    {
                        for (k = 0; k < strlen(number); k++)
                        {
                            if (game->board[y][j] == number[k])
                            {
                                     game->score += ball[k]; 
                                    break;
                            }
                        }
                       game->board[y][j] = number[k + 1];
                        game->board[y][j + 1] = ' ';
                    }
            }
            for (int j = 0; j < 4; j++)
            {
                k = 0;
                for (int l = 0; l < 4; l++)
                {
                    for (int z = 0; z < 4; z++)
                    {
                        if (game->board[y][z] == ' ' && z != 3)
                        {
                            game->board[y][z] = game->board[y][z + 1];
                            game->board[y][z + 1] = ' ';
                        }
                    }
                }
            }    
        }
    }
                if (dx == 1 && dy == 0) //for right
                {
                    for (int y = 0; y < 4; y++)
                    {
                        for (int j = 3; j > 0; j--)
                        {
                            k = 0;
                                for (int i = 0; i < 4; i++)
                                {
                                    for (int j = 3; j > 0; j--)
                                    {
                                        if (game->board[i][j] == ' ' && j != 0)
                                        {
                                            game->board[i][j] = game->board[i][j - 1];
                                            game->board[i][j - 1] = ' ';
                                        }
                                    }
                                }
                        }
                        for (int j = 3; j > 0; j--) 
                        {
                                if (j != 0 &&  game->board[y][j] != ' ' && game->board[y][j] == game->board[y][j - 1])
                                {
                                    for (k = 0; k < strlen(number); k++)
                                    {
                                        if (game->board[y][j - 1] == number[k]) 
                                            {
                                                 game->score += ball[k]; 
                                                 break;
                                            }
                                    }
                                    game->board[y][j] = number[k + 1];
                                    game->board[y][j - 1] = ' ';
                                }              
                        }
                        for (int i = 0; i < 4; i++)
                        {
                            for (int j = 3; j > 0; j--)
                            {
                                if (game->board[i][j] == ' ' && j != 0)
                                {
                                    game->board[i][j] = game->board[i][j - 1];
                                    game->board[i][j - 1] = ' ';
                                }
                            }
                        }
                    }
               }
            
 for (int i = 0; i < 4; i++) 
    {
        for (int j = 0; j < 4; j++) 
        {
            if (game->board[i][j] == '\0') 
            {
                game->board[i][j] = ' ';
            }
        }
    }
    int count = 0;
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(check_array[i][j] == game->board[i][j])
            {
                count++;
            }
        }
    }
    if(count == 16) return false;
   return true;
}
bool is_move_possible(const struct game game) // done
{
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(game.board[i][j] == ' ') return true;
            if((game.board[i][j] == game.board[i][j-1]  && j - 1 > 0)|| (game.board[i][j] == game.board[i][j+1] && j+1 < 3)) return true;
            if((game.board[i][j] == game.board[i+1][j] && i+1 < 3) || (game.board[i][j] == game.board[i-1][j] && i - 1 > 0)) return true;
        }
    }
    return false;
}
bool is_game_won(const struct game game) // done
{
    for(int i = 0; i<4; i++)
    {
        for(int j = 0; j<4; j++)
        {
            if(game.board[i][j] == 'K') return true;
        }
    }
    return false;
}
