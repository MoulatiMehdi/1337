
#include "number_to_words.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>

int is_valid_number(const char *number) {
    for (int i = 0; number[i] != '\0'; i++) {
        if (!isdigit(number[i])) {
            return 0;
        }
    }
    return 1;
}

int readDictionary(const char *filename, DictionaryEntry *dictionary) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return 0;
    }

    int count = 0;
    char line[MAX_LINE_LENGTH];

    while (fgets(line, sizeof(line), file) != NULL) {
        if (strlen(line) <= 1) {
            continue; // Skip empty lines
        }

        char *number = strtok(line, ":");
        char *word = strtok(NULL, "\n");

        if (number == NULL || word == NULL) {
            fclose(file);
            return 0;
        }

        // Trim spaces
        while (isspace(*number)) number++;
        while (isspace(*word)) word++;
        char *end;

        end = number + strlen(number) - 1;
        while (end > number && isspace(*end)) end--;
        *(end + 1) = '\0';

        end = word + strlen(word) - 1;
        while (end > word && isspace(*end)) end--;
        *(end + 1) = '\0';

        strcpy(dictionary[count].number, number);
        strcpy(dictionary[count].word, word);
        count++;

        if (count >= MAX_ENTRIES) {
            break;
        }
    }

    fclose(file);
    return count;
}

const char* findWord(const char *number, DictionaryEntry *dictionary, int dictSize) {
    for (int i = 0; i < dictSize; i++) {
        if (strcmp(dictionary[i].number, number) == 0) {
            return dictionary[i].word;
        }
    }
    return NULL;
}

int convert_number_to_words(const char *number_str, char *result, DictionaryEntry *dictionary, int dictSize) {
    long long number = atoll(number_str);
    if (number == 0) {
        strcpy(result, findWord("0", dictionary, dictSize));
        return 1;
    }

    result[0] = '\0';
    int chunk_count = 0;
    char chunk_word[100];

    while (number > 0) {
        int chunk = number % 1000;
        if (chunk > 0) {
            chunk_word[0] = '\0';
            convert_chunk(chunk, chunk_word, dictionary, dictSize);
            if (chunk_count > 0) {
                strcat(chunk_word, " ");
                strcat(chunk_word, find_power_of_ten(chunk_count, dictionary, dictSize));
                if (result[0] != '\0') {
                    strcat(chunk_word, ", ");
                }
            }
            strcat(chunk_word, result);
            strcpy(result, chunk_word);
        }
        number /= 1000;
        chunk_count++;
    }

    return 1;
}

void convert_chunk(int chunk, char *result, DictionaryEntry *dictionary, int dictSize) {
    if (chunk >= 100) {
        strcat(result, findWord((char[]){chunk / 100 + '0', '\0'}, dictionary, dictSize));
        strcat(result, " ");
        strcat(result, findWord("100", dictionary, dictSize));
        chunk %= 100;
        if (chunk > 0) {
            strcat(result, " and ");
        }
    }
    if (chunk > 0) {
        if (chunk < 20) {
            strcat(result, findWord((char[]){chunk + '0', '\0'}, dictionary, dictSize));
        } else {
            strcat(result, findWord((char[]){chunk / 10 * 10 + '0', '\0'}, dictionary, dictSize));
            if (chunk % 10 != 0) {
                strcat(result, "-");
                strcat(result, findWord((char[]){chunk % 10 + '0', '\0'}, dictionary, dictSize));
            }
        }
    }
}

const char* find_power_of_ten(int power, DictionaryEntry *dictionary, int dictSize) {
    long long number = 1;
    for (int i = 0; i < power; i++) {
        number *= 1000;
    }
    char number_str[MAX_NUMBER_LENGTH];
    sprintf(number_str, "%lld", number);
    return findWord(number_str, dictionary, dictSize);
}
