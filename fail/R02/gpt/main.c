#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "number_to_words.h"

void print_error(const char *msg) {
    write(1, msg, strlen(msg));
}

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        print_error("Error\n");
        return 1;
    }

    char *dictionary_file = "dictionary.txt";
    char *number_str;

    if (argc == 2) {
        number_str = argv[1];
    } else {
        dictionary_file = argv[1];
        number_str = argv[2];
    }

    if (!is_valid_number(number_str)) {
        print_error("Error\n");
        return 1;
    }

    DictionaryEntry dictionary[MAX_ENTRIES];
    int dictSize = readDictionary(dictionary_file, dictionary);

    if (dictSize == 0) {
        print_error("Dict Error\n");
        return 1;
    }

    char result[1000];
    if (!convert_number_to_words(number_str, result, dictionary, dictSize)) {
        print_error("Dict Error\n");
        return 1;
    }

    printf("%s\n", result);
    return 0;
}
