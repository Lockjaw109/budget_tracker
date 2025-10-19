#include <gtest/gtest.h>

#include "database.h"

TEST(WriteTransactions, SuccessfulWrite) {
  ASSERT_EQ(SUCCESS, write_transactions("test.txt"));
}

TEST(ReadTransactions, NonExistentFile) {
  ASSERT_EQ(READ_ERR, read_transactions("does_not_exist.txt"));
}

TEST(ReadTransactions, SuccessfulRead) {
  ASSERT_EQ(SUCCESS, read_transactions("test.txt"));
}
