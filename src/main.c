/**
 * @file main.c
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-05
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <stdio.h>

#include "header.h"

int main(int ac, char **av)
{
    print(1, "Hello world !\n");
    printf("Nb word: %ld\n", count_word("Hello world !\n", ' '));
    return 0;
}
