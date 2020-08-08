int strspn_(const char *, const char *);
int comparator(char, char);
void heapsorted(char *, int, int (*)(char, char));
void sift_down(char *, int, int, int (*)(char, char));
void sift_up(char *, int, int (*)(char, char));
void swap(char *, char *);
int binsearch(const char *, int, char);
