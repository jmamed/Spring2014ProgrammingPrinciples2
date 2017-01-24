#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct tree_node 
{
  const char *word;
  struct tree_node *left;
  struct tree_node *right;
} tree_node;

char *strip (char **word)
{
  char *start = *word;
  int len = strlen (start);
  char *end = start + len - 1;

  while ((start < end) && (!isalpha (start[0])))
    start++;

  while ((end > start) && (!isalpha (end[0])))
    end--;

  if (start > end)
    return NULL;
         
  end[1] = '\0';
  *word = start;

  return start;
}

void insert (tree_node *root, char *word)
{
int compare_value;
  if (root == NULL)
    return;

  compare_value = strcmp (word, root->word);

  if (compare_value == 0)
    return;

  if (compare_value < 0)
    {
      if (root->left != NULL)
        insert (root->left, word);
      else
        {
          tree_node *new_node = (tree_node *) malloc (sizeof (tree_node));
          new_node->word = strdup (word);
          new_node->left = NULL;
          new_node->right = NULL;
          root->left = new_node;
        }
    }
  else
    {
      if (root->right != NULL)
        insert (root->right, word);
      else
        {
          tree_node *new_node = (tree_node *) malloc (sizeof (tree_node));
          new_node->word = strdup (word);
          new_node->left = NULL;
          new_node->right = NULL;
          root->right = new_node;
        }
    }
}

void populate_dictionary (tree_node **dictionary, char *filename)
{
  FILE *in_file;
  char word[1024];

  in_file = fopen (filename, "r");
  if (in_file)
    {
      while (fgets (word, 1024, in_file) != NULL)
        {
          char *new_word = (strdup (word));
          new_word = strip (&new_word);
          if (*dictionary == NULL)
            {
              tree_node *new_node = (tree_node *) malloc (sizeof (tree_node));
              new_node->word = new_word;
              new_node->left = NULL;
              new_node->right = NULL;
              *dictionary = new_node;
            }
          else
            insert (*dictionary, new_word);
        }
    }
}

int find_word (tree_node *dictionary, char *word)
{
int compare_value;
if (!word || !dictionary)
    return 0;

  compare_value = strcmp (word, dictionary->word);

  if (compare_value == 0)
    return 1;
  else if (compare_value < 0)
    return find_word (dictionary->left, word);
  else
    return find_word (dictionary->right, word);
}

void print_tree (tree_node *dictionary)
{
  if (!dictionary)
    return;

  if (dictionary->left)
    print_tree (dictionary->left);

  printf ("%s\n", dictionary->word);


  if (dictionary->right)
    print_tree (dictionary->right);
}


int main (int argc, char **argv)
{
  tree_node *dictionary = NULL;
  char buffer[1024];
  char *filename = NULL;
  int done = 0;

  if (argc == 2)
    filename = argv[1];

  if (!filename)
    return -1;

  populate_dictionary (&dictionary, filename);
  fprintf (stdout, "Dictionary loaded.\nEnter search word: ");
  while (!done && fgets (buffer, sizeof(buffer), stdin))
    {
      char *word = buffer;
      int len = strlen (word);
      int i;

      for (i = 0; i < len; ++i)
        word[i] = tolower (word[i]);

      if ((len > 0) && (word[len-1] == '\n'))
        {
          word[len-1] = '\0';
          len = len - 1;
        }

      if (find_word (dictionary, word))
        fprintf (stdout, "Yes!\n");
      else
        fprintf (stdout, "No match found!\n");

      fprintf (stdout, "Enter search word: ");
    }
  
  fprintf (stdout, "\n");
  return 0;
}