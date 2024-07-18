
#ifndef NUMBER_TO_WORDS_H
#define NUMBER_TO_WORDS_H

#define MAX_LINE_LENGTH 100
#define MAX_WORD_LENGTH 50
#define MAX_NUMBER_LENGTH 50
#define MAX_ENTRIES 40

typedef struct {
    char number[MAX_NUMBER_LENGTH];
    char word[MAX_WORD_LENGTH];
} DictionaryEntry;

int is_valid_number(const char *number);
int readDictionary(const char *filename, DictionaryEntry *dictionary);
const char* findWord(const char *number, DictionaryEntry *dictionary, int dictSize);
int convert_number_to_words(const char *number_str, char *result, DictionaryEntry *dictionary, int dictSize);
void convert_chunk(int chunk, char *result, DictionaryEntry *dictionary, int dictSize);
const char* find_power_of_ten(int power, DictionaryEntry *dictionary, int dictSize);

#endif
