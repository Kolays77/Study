#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>

void return_error (int result, const char *name);

#define LENGTH 1024
#define MAX_NUM 1000
#define NUM_CHAR 256

int replace_substrings_by_others (const char *input_file,
                                  const char *output_file,
                                  const char *substr,
                                  const char *new_substr); //task1

int make_string (char *string);
void fill_was_char (const char *string, int *was_char);
void delete_spaces (char *string, int *is_space);

int find_not_equals_without_spaces (const char *file_input,
                                    const char *output_file,
                                    char *compare_string,
                                    const char *spaces); //task2

int find_consists_of_allowable_chars (const char *input_file,
                                      const char *output_file,
                                      char *allowable_chars,
                                      const char *spaces); //task3

int find_includes_substring (const char *input_file,
                             const char *output_file,
                             char *substring,
                             const char *spaces); //task4

int parse (char *string, int length, const char *space, char **words);

#define NUM_OF_WORDS 2048

int find_includes_words (const char *input_file,
                         const char *output_file,
                         char *string_words,
                         const char *space); //task5

int find_equals_strings1 (const char *input_file,
                         const char *output_file,
                         char *examplar); //task6


int find_equals_strings2 (const char *input_file,
                          const char *output_file,
                          char *examplar); //task7

int find_equals_strings3 (const char *input_file,
                           const char *output_file,
                           char *examplar); //task8
