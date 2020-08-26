//
//  main.c
//  Question1c
//
//  Created by Behnaz Nasiri on 2020-08-26.
//  Copyright © 2020 Behnaz Nasiri. All rights reserved.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isMatch(char* str, char* pattern) {
    bool table [strlen(str) + 1][strlen(pattern) + 1];
    table[0][0] = true;
    for (int j = 1; j <= strlen(pattern); j++) {
        if (pattern[j - 1] == '*')
            table[0][j] = table[0][j - 2];
        else
            table[0][j] = false;
    }
    
    for (int i = 1; i <= strlen(str); i++)
        table[i][0] = false;

    for (int i = 1; i <= strlen(str); i++) {
        for (int j = 1; j <= strlen(pattern); j++) {
            if (str[i-1] == pattern[j-1] || pattern[j-1] == '.') {
                table[i][j] = table[i-1][j-1];
            }
            
            else if (pattern[j-1] == '*') {
                if (table[i][j - 2] == true)
                    table[i][j] = true;
                else if (pattern[j-2] == str[i-1] || pattern[j-2] == '.')
                    table[i][j] = table[i-1][j];
                else
                    table[i][j] = false;
            }
            else
                table[i][j] = false;

            }
    }
    return table[strlen(str)][strlen(pattern)];
}





int main(int argc, const char * argv[]) {
    char str[] = "aab";
    char pattern[] = "a*b";
    printf("%d \n", isMatch(str, pattern));
    return 0;
}
