#ifndef DATABASE_H
#define DATABASE_H

enum type {
  PAYROLL, GIFT, OTHER, // Income types
  FOOD, SHOPPING, SUBSCRIPTION, ENTERTAINMENT, GIFT, OTHER // Expense types
}

typedef struct transaction {
  float value;
  int date; // stored as YYYYMMDD
  enum type;
} transaction_t;

#endif // DATABASE_H
