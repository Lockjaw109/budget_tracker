#include "database.h"

/*
 * Database
 *
 * Author: Henri Goosen
 *
 * Date: 10-15-2025
 *
 * Purpose: Store and modify transaction_t for main.c
 */

int g_transactions[INIT_SIZE];

/*
 * read_transactions()
 *
 * Purpose: Read in data to transaction_t structs and store in a global
 *          array.
 *
 * INPUT: char *filename - file where data is stored
 *
 * OUTPUT: int SUCCESS or ERROR
 */

int read_transactions(char *filename) {
  FILE *fp = NULL;

  fp = fopen(filename, "r");
  if (fp != NULL) {
    return READ_ERR;
  }

  return SUCCESS;
} /* read_transactions() */
