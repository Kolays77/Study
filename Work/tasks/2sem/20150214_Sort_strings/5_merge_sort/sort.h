int comparator(const char *, const char *);
int merge_sort(char **,
               char **,
               int,
               int (*)(const char *, const char *));
void merge(char **,
           char **,
           int,
           int,
           char **,
           int (*)(const char *, const char *));
