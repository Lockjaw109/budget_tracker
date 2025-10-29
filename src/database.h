#ifndef DATABASE_H
#define DATABASE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS (0)
#define READ_ERR (-1)
#define WRITE_ERR (-2)
#define MEM_ERR (-3)
#define IN_ERR (-4) // insert error

#define INIT_SIZE (8) // Initial size of array for transactions

typedef enum type {
  PAYROLL, GIFT_I, OTHER_I, // Income types
  FOOD, SHOPPING, SUBSCRIPTION, ENTERTAINMENT, GIFT_E, OTHER_E // Expense types
} type_e;

typedef struct transaction {
  unsigned long id; // unique ID
  float value;
  int date; // stored as YYYYMMDD
  type_e type;
} transaction_t;

extern int read_transactions(const char *);
extern int write_transactions(const char *);
extern int delete_transaction(unsigned long id);
extern int insert_transaction(transaction_t);
extern int view_transactions(void);
extern transaction_t *search_transactions(void);
extern int sort_transactions(void);
extern int init_db(void);

#ifdef __cplusplus
}
#endif

#endif // DATABASE_H
