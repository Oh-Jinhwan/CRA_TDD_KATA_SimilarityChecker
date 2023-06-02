#include "pch.h"
#include "../CRA_TDD_KATA_SimilarityChecker/similarityChecker.cpp"

TEST(TestCaseName, LengthCheck) {
  EXPECT_EQ(60, SimilarityChecker().checkLength("ASD", "DSA"));
  EXPECT_EQ(0, SimilarityChecker().checkLength("A", "BB"));
  EXPECT_EQ(20, SimilarityChecker().checkLength("AAABB", "BAA"));
  EXPECT_EQ(30, SimilarityChecker().checkLength("AA", "AAA"));
}