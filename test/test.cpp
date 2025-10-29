#include <gtest/gtest.h>

#include "database.h"

TEST(InsertTransactions, SuccessfulInsert) {
  transaction_t transaction;
  transaction.id = 0L;
  transaction.value = 99.99;
  transaction.date = 20051215; // 12/15/2005
  transaction.type = FOOD;
  ASSERT_EQ(SUCCESS, insert_transaction(transaction));
}

TEST(ViewTransactions, SuccessfulView) {
  view_transactions();
  SUCCEED();
}

TEST(WriteTransactions, SuccessfulWrite) {
  ASSERT_EQ(SUCCESS, write_transactions("test.txt"));
}

TEST(ReadTransactions, NonExistentFile) {
  ASSERT_EQ(READ_ERR, read_transactions("does_not_exist.txt"));
}

TEST(ReadTransactions, SuccessfulRead) {
  ASSERT_EQ(SUCCESS, read_transactions("test.txt"));
}
