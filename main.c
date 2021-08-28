#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hof.h"
#include "k.h"
#include "ui.h"
#include <ui.c>
#include <hof.c>
#include <k.c>
#include <stdbool.h>
#include <ctype.h>
int main()
{
    struct game game = {
        .board = {
            {'A', 'B', 'C', 'D'},
            {'A', 'B', 'C', 'D'},
            {'A', 'B', 'C', 'D'},
            {'A', 'B', 'C', 'D'}
        },
        .score = 1234
    };
    struct player list[10];
    int size = load(list); // done
    struct player player = 
    {
    .name = "John",
    .score = 100
    };
    bool result = add_player(list, &size, player);
    bool dark = save(player, size);
    bool wait = update(&game, 1, 1);
    bool mda = is_move_possible(game);
    bool kek = is_game_won(game);
    add_random_tile(&game);
    render(game);
    
    
}
