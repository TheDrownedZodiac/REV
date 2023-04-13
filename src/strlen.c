/*
 * E89 Pedagogical & Technical Lab
 * project:     rev
 * created on:  2022-10-26 - 16:34 +0200
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: character count
 */

unsigned int stu_strlen(const char *str)
{
    unsigned int count;

    count = 0;
    while (*str != '\0') {
        str += 1;
        count += 1;
    }
    return count;
}
