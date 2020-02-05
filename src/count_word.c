/**
 * @file str_to_word_array.c
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-05
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <stddef.h>
#include <stdbool.h>

size_t count_word(const char *str, char delim)
{
    size_t nb_word = *str ? 1 : 0;
    bool on_word = false;

    for (size_t i = 0; str[i] != '\0'; i++) {
        if (str[i] != delim)
            on_word = true;
        else {
            if (on_word == true)
                nb_word++;
            on_word = false;
        }
    }
    if (on_word == false && *str)
       nb_word--;
    return nb_word;
}
