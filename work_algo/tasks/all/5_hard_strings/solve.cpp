#include "head.h"

int make_string (char *string)
{
  int idx;
  for (idx = 0; string[idx]; idx++)
    {
      if (string[idx] == '\n')
        {
          string[idx] = 0;
          break;
        }
    }
  return idx;
}

void fill_was_char (const char *string, int *was_char)
{
  for (int idx = 0; idx < NUM_CHAR; idx++)
    {
      was_char[idx] = 0;
    }
  for (int idx = 0; string[idx]; idx++)
    {
      was_char[(unsigned int) string[idx]] = 1;
    }
  return;
}

void delete_spaces (char *string, int *is_space)
{
  int length = strlen (string), was_delete = 0;
  for (int idx = 0; string[idx]; idx++)
    {
      if (is_space[(unsigned int) string[idx]])
        {
          was_delete++;
        }
      else
        {
          string[idx - was_delete] = string[idx];
        }
    }
  string[length - was_delete] = 0;
  return;
}


int replace_substrings_by_others (const char *input_file,
                                  const char *output_file,
                                  const char *substr,
                                  const char *new_substr)
{
  FILE *fp_in, *fp_out;
  int result = 0;
  char buffer[LENGTH];

  int was_changed;
  int len_substr = strlen (substr);
  char *pointer_buffer, *pointer_substr;

  if (!(fp_in = fopen (input_file, "r")))
    {
      return -11;
    }
  if (!(fp_out = fopen (output_file, "w")))
    {
      fclose (fp_in);
      return -21;
    }

  while (fgets (buffer, LENGTH, fp_in))
    {
      make_string (buffer);
      was_changed = 0;
      pointer_buffer = buffer;
      while (pointer_buffer)
        {
          if ((pointer_substr = strstr (pointer_buffer, substr)) != NULL)
            {
              was_changed = 1;;
              pointer_buffer[strlen (pointer_buffer) - strlen (pointer_substr)] = 0;
              fprintf (fp_out, "%s", pointer_buffer);
              fprintf (fp_out, "%s", new_substr);
              pointer_buffer = pointer_substr + len_substr;
            }
          else
            {
              break;
            }
        }
      fprintf (fp_out, "%s\n", pointer_buffer);
      if (was_changed)
        {
          result++;
        }
    }
  if (!feof (fp_in))
    {
      fclose (fp_in);
      fclose (fp_out);
      return -12;
    }
  fclose (fp_in);
  fclose (fp_out);
  return result;
}



int find_not_equals_without_spaces (const char *input_file,
                                    const char *output_file,
                                    char *compare_string,
                                    const char *spaces)
{
  FILE *fp_in, *fp_out;
  int is_space[NUM_CHAR];
  int result = 0;
  char buffer[LENGTH], buffer_without_spases[LENGTH];


  if (!(fp_in = fopen (input_file, "r")))
    {
      return -11;
    }
  if (!(fp_out = fopen (output_file, "w")))
    {
      fclose (fp_in);
      return -21;
    }

  fill_was_char (spaces, is_space);
  delete_spaces (compare_string, is_space);

  while (fgets (buffer, LENGTH, fp_in))
    {
      make_string (buffer);
      strcpy (buffer_without_spases, buffer);
      delete_spaces (buffer_without_spases, is_space);
      if (strcmp (buffer_without_spases, compare_string))
        {
          fprintf (fp_out, "%s\n", buffer);
          result++;
        }
    }
  if (!feof (fp_in))
    {
      fclose (fp_in);
      fclose (fp_out);
      return -12;
    }
  fclose (fp_in);
  fclose (fp_out);
  return result;
}


int find_consists_of_allowable_chars (const char *input_file,
                                      const char *output_file,
                                      char *allowable_chars,
                                      const char *spaces)
{
  FILE *fp_in, *fp_out;
  int is_allowable[NUM_CHAR];
  int result = 0;
  char buffer[LENGTH], buffer_without_allowable_chars[LENGTH];

  if (!(fp_in = fopen (input_file, "r")))
    {
      return -11;
    }
  if (!(fp_out = fopen (output_file, "w")))
    {
      fclose (fp_in);
      return -21;
    }

  strcat (allowable_chars, spaces);
  fill_was_char (allowable_chars, is_allowable);

  while (fgets (buffer, LENGTH, fp_in))
    {
      make_string (buffer);
      strcpy (buffer_without_allowable_chars, buffer);
      delete_spaces (buffer_without_allowable_chars, is_allowable);
      if (buffer_without_allowable_chars[0] == 0)
        {
          fprintf (fp_out, "%s\n", buffer);
          result++;
        }
    }
  if (!feof (fp_in))
    {
      fclose (fp_in);
      fclose (fp_out);
      return -12;
    }
  fclose (fp_in);
  fclose (fp_out);
  return result;
}

int find_includes_substring (const char *input_file,
                             const char *output_file,
                             char *substring,
                             const char *spaces)
{
  FILE *fp_in, *fp_out;
  int is_space[NUM_CHAR];
  int result = 0;
  char buffer[LENGTH], buffer_without_spaces[LENGTH];

  if (!(fp_in = fopen (input_file, "r")))
    {
      return -11;
    }
  if (!(fp_out = fopen (output_file, "w")))
    {
      fclose (fp_in);
      return -21;
    }

  fill_was_char (spaces, is_space);
  delete_spaces (substring, is_space);

  while (fgets (buffer, LENGTH, fp_in))
    {
      make_string (buffer);
      strcpy (buffer_without_spaces, buffer);
      delete_spaces (buffer_without_spaces, is_space);
      if (strstr (buffer_without_spaces, substring))
        {
          fprintf (fp_out, "%s\n", buffer);
          result++;
        }
    }
  if (!feof (fp_in))
    {
      fclose (fp_in);
      fclose (fp_out);
      return -12;
    }
  fclose (fp_in);
  fclose (fp_out);
  return result;
}

int parse (char *string, int length, const char *space, char **words)
{
  int cnt_words = 0;
  int shift = strspn (string, space);

  while (string[shift] && shift < length)
    {
      words[cnt_words++] = string + shift;
      shift += strcspn (string + shift, space);
      string[shift++] = 0;
      shift += strspn (string + shift, space);
    }
  return cnt_words;
}

int find_includes_words (const char *input_file,
                         const char *output_file,
                         char *string_words,
                         const char *space)
{
  FILE *fp_in, *fp_out;
  int result = 0;
  int num_of_words_in_dictionary = 0;
  int length_string = strlen (string_words), curr_length;
  char buffer[LENGTH], curr_word[LENGTH], *pointer;
  int shift;
  char *dictionary[NUM_OF_WORDS];
  int was_found;

  if (!(fp_in = fopen (input_file, "r")))
    {
      return -11;
    }
  if (!(fp_out = fopen (output_file, "w")))
    {
      fclose (fp_in);
      return -21;
    }

  num_of_words_in_dictionary = parse (string_words, length_string, space, dictionary);

  while (fgets (buffer, LENGTH, fp_in))
    {
      shift = 0;
      was_found = 0;
      curr_length = make_string (buffer);
      strcpy (curr_word, buffer);
      while (curr_word[shift] && shift < curr_length && !was_found)
        {
          pointer = curr_word + shift;
          shift += strcspn (pointer, space);
          curr_word[shift++] = 0;
          for (int idx = 0; idx < num_of_words_in_dictionary; idx++)
            {
              if (!strcmp (pointer, dictionary[idx]))
                {
                  was_found = 1;
                  fprintf (fp_out, "%s\n", buffer);
                  result++;
                  break;
                }
            }
          shift += strspn (curr_word + shift, space);
        }
    }
  if (!feof (fp_in))
    {
      fclose (fp_in);
      fclose (fp_out);
      return -12;
    }
  fclose (fp_in);
  fclose (fp_out);
  return result;
}

int find_equals_strings1 (const char *input_file,
                          const char *output_file,
                          char *examplar)
{
  int result = 0;
  int length_examplar = strlen (examplar);
  char buffer[LENGTH];
  FILE *fp_in, *fp_out;

  if (!(fp_in = fopen (input_file, "r")))
    {
      return -11;
    }
  if (!(fp_out = fopen (output_file, "w")))
    {
      fclose (fp_in);
      return -21;
    }

  while (fgets (buffer, LENGTH, fp_in))
    {
      int idx_examplar = 0, idx_buffer = 0, is_equal = 1;
      make_string (buffer);
      while (buffer[idx_buffer])
        {
          if (examplar[idx_examplar] == '.')
            {
              idx_buffer++;
              idx_examplar++;
              continue;
            }
          else if (examplar[idx_examplar] == '\\')
            {
              if ((buffer[idx_buffer] == '\\' && examplar[idx_examplar + 1] == '\\')
                  || (buffer[idx_buffer] == '.' && examplar[idx_examplar + 1] == '.'))
                {
                  idx_buffer++;
                  idx_examplar += 2;
                  continue;
                }
              else
                {
                  is_equal = 0;
                  break;
                }
            }
          else if (buffer[idx_buffer] != examplar[idx_examplar])
            {
              is_equal = 0;
              break;
            }
          idx_buffer++;
          idx_examplar++;
        }
      if (is_equal && idx_examplar == length_examplar)
        {
          fprintf (fp_out, "%s\n", buffer);
          result++;
        }
    }
  if (!feof (fp_in))
    {
      fclose (fp_in);
      fclose (fp_out);
      return -12;
    }
  fclose (fp_in);
  fclose (fp_out);
  return result;
}

int find_equals_strings2 (const char *input_file,
                          const char *output_file,
                          char *examplar)
{
  int result = 0;
  int length_examplar = strlen (examplar);
  char buffer[LENGTH];
  FILE *fp_in, *fp_out;

  if (!(fp_in = fopen (input_file, "r")))
    {
      return -11;
    }
  if (!(fp_out = fopen (output_file, "w")))
    {
      fclose (fp_in);
      return -21;
    }

  while (fgets (buffer, LENGTH, fp_in))
    {
      int idx_examplar = 0, idx_buffer = 0, is_equal = 1;
      make_string (buffer);
      while (buffer[idx_buffer])
        {
          if (examplar[idx_examplar] == '\\')
            {
              if ((buffer[idx_buffer] == '\\' && examplar[idx_examplar + 1] == '\\')
                  || (buffer[idx_buffer] == '*' && examplar[idx_examplar + 1] == '*'))
                {
                  idx_buffer++;
                  idx_examplar += 2;
                  continue;
                }
              else
                {
                  is_equal = 0;
                  break;
                }
            }
          else if (examplar[idx_examplar + 1] == '*')
              {
                while (buffer[idx_buffer] == examplar[idx_examplar])
                  {
                    idx_buffer++;
                  }
                idx_examplar += 2;
                continue;
              }
          else if (buffer[idx_buffer] != examplar[idx_examplar])
            {
              is_equal = 0;
              break;
            }
          idx_buffer++;
          idx_examplar++;
        }
      if (is_equal && idx_examplar == length_examplar)
        {
          fprintf (fp_out, "%s\n", buffer);
          result++;
        }
    }
  if (!feof (fp_in))
    {
      fclose (fp_in);
      fclose (fp_out);
      return -12;
    }
  fclose (fp_in);
  fclose (fp_out);
  return result;
}

int find_equals_strings3 (const char *input_file,
                           const char *output_file,
                           char *examplar)
 {
   int result = 0;
   int length_examplar = strlen (examplar);
   char buffer[LENGTH];
   FILE *fp_in, *fp_out;

   if (!(fp_in = fopen (input_file, "r")))
     {
       return -11;
     }
   if (!(fp_out = fopen (output_file, "w")))
     {
       fclose (fp_in);
       return -21;
     }

   while (fgets (buffer, LENGTH, fp_in))
     {
       int idx_examplar = 0, idx_buffer = 0, is_equal = 1;
       make_string (buffer);
       while (buffer[idx_buffer])
         {
           if (examplar[idx_examplar] == '\\')
             {
               if ((buffer[idx_buffer] == '\\' && examplar[idx_examplar + 1] == '\\')
                   || (buffer[idx_buffer] == '[' && examplar[idx_examplar + 1] == '[')
                   || (buffer[idx_buffer] == ']' && examplar[idx_examplar + 1] == ']'))
                 {
                   idx_buffer++;
                   idx_examplar += 2;
                   continue;
                 }
               else
                 {
                   is_equal = 0;
                   break;
                 }
             }
           else if (examplar[idx_examplar] == '[' && examplar[idx_examplar + 2] == '-' && examplar[idx_examplar + 4] == ']')
             {
               if (buffer[idx_buffer] >= examplar[idx_examplar + 1] && buffer[idx_buffer] <= examplar[idx_examplar + 3])
                 {
                   idx_buffer++;
                   idx_examplar += 5;
                 }
               else
                 {
                   is_equal = 0;
                   break;
                 }
               continue;
             }
           else if (buffer[idx_buffer] != examplar[idx_examplar])
             {
               is_equal = 0;
               break;
             }
           idx_buffer++;
           idx_examplar++;
         }
       if (is_equal && idx_examplar == length_examplar)
         {
           fprintf (fp_out, "%s\n", buffer);
           result++;
         }
     }
   if (!feof (fp_in))
     {
       fclose (fp_in);
       fclose (fp_out);
       return -12;
     }
   fclose (fp_in);
   fclose (fp_out);
   return result;
 }
