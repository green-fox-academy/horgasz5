#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

int main(){
    char first[50];
    char second[50];
    uint8_t boo = 1;

    printf("First word:\n");
    gets(first);
    printf("Second word:\n");
    gets(second);
    uint8_t f_len = strlen(first);
    uint8_t s_len = strlen(second);

    if (f_len != s_len){
        printf("\nOne of the word is longer than the other!\n");
        boo = 0;
        }

    for(uint8_t i = 0; i < f_len; i++){
        for(uint8_t j = 0; j < s_len; j++){
            if(first[i] == second[j]){
                second[j] = '0';
                }
            }
        }

    for(uint8_t i = 0; i < s_len; i++){
        if(second[i] != '0'){
            boo = 0;
        }
    }

    if(boo == 1){
        printf("\nThe two words are anagrams!\n", first, second);
        }else{
        printf("\nNOT anagrams!\n");
        }

    return 0;
}
