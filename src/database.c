#include <assert.h>

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

transaction_t *g_transactions;
int g_size; // size of global array
int g_count; // total transactions stored

/*
 * read_transactions()
 *
 * Purpose: Read in data to transaction_t structs and store in a global
 *          array.
 *
 * INPUT: const char *filename - file where data is stored
 *
 * OUTPUT: int SUCCESS or ERROR
 */

int read_transactions(const char *filename) {
  assert(g_transactions == NULL);
  FILE *fp = NULL;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    return READ_ERR;
  }

  transaction_t *temp = NULL; // array to store transactions
  int count = 0; // amount of transactions to read

  fscanf(fp, "%d\n", &count);

  temp = malloc(count * sizeof(transaction_t));
  if (temp == NULL) {
    fclose(fp);
    fp = NULL;
    return MEM_ERR;
  }

  int status = fread(temp, sizeof(transaction_t), count, fp);
  if (status != count) {
    fclose(fp);
    fp = NULL;
    return READ_ERR;
  }

  return SUCCESS;
} /* read_transactions() */

/*
 * write_transactions()
 *
 * Purpose: Write data from global array to output file
 *
 * INPUT: const char *filename
 *
 * OUTPUT: int SUCCESS or ERROR
 */

int write_transactions(const char *filename) {
  assert(g_transactions != NULL);
  FILE *fp = NULL;

  fp = fopen(filename, "w");
  if (fp = NULL) {
    return WRITE_ERR;
  }

  fprintf(fp, "%d\n", g_count);

  int status = fwrite(g_transactions, sizeof(transaction_t), g_count, fp);
  if (status != g_count) {
    fclose(fp);
    fp = NULL;
    return WRITE_ERR;
  }

  free(g_transactions);
  g_transactions = NULL;

  fclose(fp);
  fp = NULL;
  return SUCCESS;
} /* write_transactions() */

/*
 * insert_transaction()
 *
 * Purpose: Insert transaction into global array
 *
 * INPUT: transaction_t transaction
 *
 * OUTPUT: int SUCCESS or ERROR
 */

int insert_transaction(transaction_t transaction) {
  if (g_transactions == NULL) {
    return IN_ERR;
  }

  int index = (g_count + 1); // TODO: fix insert

  if (index == (g_size / 2)) {
    // resize g_transactions
  }

  g_transactions[index] = transaction;
  g_count++;
  return SUCCESS;
} /* insert_transaction() */

/*
 * delete_transaction()
 *
 * Purpose: Remove the transaction with the given ID
 *
 * INPUT: unsigned long id
 *
 * OUTPUT: int SUCCESS or ERROR
 */

int delete_transaction(unsigned long id) {
  return SUCCESS;
} /* delete_transaction() */

/*
 * view_transactions()
 *
 * Purpose: Print out the array structure of g_transactions
 *
 * INPUT: None
 *
 * OUTPUT: CLI print
 */

int view_transactions(void) {
  assert(g_transactions != NULL);

  unsigned long id = g_transactions[i].id;
  float value = g_transactions[i].value;
  int date = g_transactions[i].date;'

  for (int i = 0; i < g_count; i++) {
    printf("%lu | $%.2f | %d / %d / %d\n", id, value,
          (date / 10000), (date % 1000), (date % 100)); // how to do date??
  }
} /* view_transactions() */
