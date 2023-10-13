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

    if (!new_num) {
        // Handle memory allocation error.
        stop("Memory allocation error");
    }

    if (*fmt == 'x') {
        char prefix_low[300] = "0x";
        lower_case(new_num);
        write(1, prefix_low, strlen(prefix_low));
        write(1, new_num, strlen(new_num));
        int total_length = (int) (strlen(prefix_low) + strlen(new_num));
        free(new_num);  // Remember to free the memory allocated in change_to_baseN.
        return total_length;
    }

    char prefix_upp[300] = "0X";
    strncat(prefix_upp, new_num, strlen(new_num));
    write(1, prefix_upp, strlen(prefix_upp));
    int total_length = (int) strlen(prefix_upp);
    free(new_num);  // Remember to free the memory allocated in change_to_baseN.
    return total_length - 1;
}


int my_oct(const unsigned long *num) {
    char *new_num = change_to_baseN(*num, 8);
    char prefix_upp[300] = "0";
    strncat(prefix_upp, new_num, strlen(new_num) + 2);
    write(1, prefix_upp, strlen(prefix_upp));

    free(new_num);
    return (int ) (strlen(prefix_upp) - 1);
}


int write_me(const unsigned long *num, int base, char letter) {
    char *new_num = change_to_baseN(*num, base);
    if (letter == 'x') lower_case(new_num);
    int new_num_len = (int) (strlen(new_num));
    write(1, new_num, new_num_len);

    free(new_num);
    return (new_num_len);
}

void lower_case(char * new_num) {
    for (register_t i = 0; i < strlen(new_num); i++) {
        if (new_num[i] >= 'A' && new_num[i] <= 'Z') {
            new_num[i] += 32;  // Convert uppercase to lowercase
        }
    }
}