int comparator(const char *, const char *);
void heapsorted(char **,
                int,
                int (*) (const char *, const char *));
void sift_up(char **, 
		     int,
		     int (*) (const char *, const char *));
void sift_down(char **,
               int, 
               int,
               int (*) (const char *, const char *));
void swap(char **, char **);
