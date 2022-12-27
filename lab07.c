/*
 * lab07.c
 *
 * Лабораторная №7
 * Аккузин Илья (ПИН-2022-1)
 *
 * Вариант №1
 * 1. В пpоизвольном тексте найти и отпечатать все слова, начинающиеся с буквы а.
 *
 * $ gcc lab07.c -o lab07
 * */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int read_file(const char* path, char** buffer) {
    FILE* fstream = fopen(path, "rb");

    if (fstream == NULL) {
        printf("[ERROR]: Can't open file on path: '%s'\n", path);
        return 1;
    }

    fseek(fstream, 0, SEEK_END);
    long fsize = ftell(fstream);
    fseek(fstream, 0, SEEK_SET);

    char* fbuffer = malloc(fsize + 1);
    fread(fbuffer, sizeof(char), fsize, fstream);
    fclose(fstream);
    fbuffer[fsize] = '\0';

    *buffer = fbuffer;
    return 0;
}


bool is_ascii_latin(char character) {
    int code = (int)character;
    return (code >= 65 && code <= 90) || (code >= 97 && code <= 122);
}


int main() {
    char* text_buffer;
    if (read_file("./lab07.txt", &text_buffer)) {
        return 1;
    }

    printf("[INFO]: Successfuly readed text:\n");
    printf("%s\n", text_buffer);

    printf("[INFO]: Searching words with first letter 'a'...\n");

    // @NOTE Возможно тут можно как-то ещё оптимизировать алгоритм, но я устал
    bool in_word = false;
    for (int i = 0; i < strlen(text_buffer); i++) {
        const char cur_char = text_buffer[i];

        if (is_ascii_latin(cur_char)) {
            if (!in_word && cur_char == 'a') {
                in_word = true;
            }
        } else if (in_word){
            printf("\n");
            in_word = false;
        }

        if (in_word) {
            printf("%c", cur_char);
        }
    }

    return 0;
}

