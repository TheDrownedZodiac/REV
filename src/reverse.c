/*
 * E89 Pedagogical & Technical Lab
 * project:     rev
 * created on:  2022-11-22 - 09:43 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: reverse
 */

#include "fonction.h"
#include <unistd.h>
#include <stdlib.h>

static int conteur(int j, char *src)
{
    while (src[j] != '\n' && src[j] != '\0') {
        j += 1;
    }
    j -= 1;
    return j;
}

char *reverse(char *src)
{
    int j;
    char *k;
    int l;

    j = 0;
    k = malloc(stu_strlen(src) * sizeof(char));
    l = 0;
    while (src[l] != '\0') {
        j = conteur(j, src);
        while (src[l] != '\n' && src[l] != '\0') {
            k[j] = src[l];
            j -= 1;
            l += 1;
        }
        if (src[l] != '\0') {
            k[l] = '\n';
        }
        l += 1;
        j = l;
    }
    write(1, k, j);
    free(k);
    return 0;
}
