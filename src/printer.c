/**
 * @file printer.c
 * @author Gabriel Hamel (gabriel.hamel@epitech.eu)
 * @brief
 * @version 1.0
 * @date 2020-02-05
 *
 * @copyright Copyright (c) 2020
 *
 */

#include <unistd.h>
#include <string.h>

void print(int fd, const char *str)
{
    write(fd, str, strlen(str));
}
