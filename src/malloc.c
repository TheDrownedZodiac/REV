/*
 * E89 Pedagogical & Technical Lab
 * project:     rev
 * created on:  2022-11-26 - 23:20 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: allocation dynamique
 */

#include "fonction.h"
#include <stdlib.h>
#include <unistd.h>

char *allocation(char *src, char *buffer, int size)
{
    int i;
    char *str;

    i = size + 1;
    while (size > 0) {
        size = read(0, buffer, 10);
        buffer[size] = '\0';
        str = malloc(sizeof(char) * i);
        stu_strcpy(str, src);
        i += size;
        free(src);
        src = malloc(sizeof(char) * (i + 1));
        stu_strcpy(src, str);
        free(str);
        stu_strcat(src, buffer);
    }
    src[i] = '\0';
    return src;
}
