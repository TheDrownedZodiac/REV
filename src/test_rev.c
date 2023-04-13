/*
 * E89 Pedagogical & Technical Lab
 * project:     rev
 * created on:  2022-11-22 - 09:20 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: main
 */

#include "fonction.h"
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char *buffer;
    char *str;
    int size_read;

    buffer = malloc(sizeof(char) * 11);
    if (!buffer) {
        return -1;
    }
    size_read = read(0, buffer, 10);
    if (!size_read) {
        return -1;
    }
    buffer[size_read] = '\0';
    str = malloc(sizeof(char) * (size_read + 1));
    stu_strcpy(str, buffer);
    str = allocation(str, buffer, size_read);
    reverse(str);
    free(buffer);
    free(str);
}
