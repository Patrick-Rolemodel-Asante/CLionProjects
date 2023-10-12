//
// Created by rol on 10/10/23.
//
#include "main.h"

char  *change_to_baseN(unsigned long int num, int new_base){
    char all_nums[] = "0123456789ABCDEF";
    char *res;

    if (num < new_base) {
        res = malloc(2);
        res[0] = all_nums[num];
        res[1] = '\0';
    } else {
        char *rem = change_to_baseN(num / new_base, new_base);
        unsigned int len = strlen(rem);
        res = malloc(len + 2);
        strcpy(res, rem);
        res[len] = all_nums[num % new_base];
        res[len + 1] = '\0';
        free(rem);
    }
    return (res);
}



int my_hex(const char *fmt, unsigned long *num) {
    char *new_num = change_to_baseN(*num, 16);
    char prefix_low[300] = "0x";
    char prefix_upp[300] = "0X";
    strncat(prefix_low, new_num, strlen(new_num) + 2);
    strncat(prefix_upp, new_num, strlen(new_num) + 2);
    if (*fmt == 'x') {
        write(1, prefix_low, strlen(prefix_low));
        return (int ) (strlen(prefix_low));
    }

    write(1, prefix_upp, strlen(prefix_upp));
    return (int ) (strlen(prefix_upp));
}



int my_oct(const char *fmt, unsigned long *num) {
    char *new_num = change_to_baseN(*num, 8);
    char prefix_upp[300] = "0o";
    strncat(prefix_upp, new_num, strlen(new_num) + 2);
    write(1, prefix_upp, strlen(prefix_upp));
    return (int ) (strlen(prefix_upp));
}

