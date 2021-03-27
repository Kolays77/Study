int comparator(const char *, const char *);
void binary_insertion_sort(char **, int, int (*)(const char *, const char *));
int binsearch(char **array, int length, char *new_element, int (*cmp)(const char *, const char *));
