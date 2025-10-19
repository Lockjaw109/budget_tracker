#ifndef DATABASE_H
#define DATABASE_H

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS (0)
#define READ_ERR (-1)
#define WRITE_ERR (-2)
#define MEM_ERR (-3)

#define INIT_SIZE (20) // Initial size of array for transactions

enum type {
  PAYROLL, GIFT, OTHER, // Income types
  FOOD, SHOPPING, SUBSCRIPTION, ENTERTAINMENT, GIFT, OTHER // Expense types
}

typedef struct transaction {
  float value;
  int date; // stored as YYYYMMDD
  enum type;
} transaction_t;

int read_transactions(char *);
int write_transactions(char *);
int delete_transaction(transaction_t *);
int insert_transaction(transaction_t *);
int view_transactions(void);
transaction_t *search_transactions(void);
int sort_transactions(void);

#endif // DATABASE_H
