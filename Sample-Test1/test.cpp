#include "pch.h"
#include "../CRA_TDD_KATA_SimilarityChecker/similarityChecker.cpp"

TEST(TestCaseName, LengthCheck) {
  EXPECT_EQ(60, SimilarityChecker().checkLength("ASD", "DSA"));
  EXPECT_EQ(0, SimilarityChecker().checkLength("A", "BB"));
  EXPECT_EQ(20, SimilarityChecker().checkLength("AAABB", "BAA"));
  EXPECT_EQ(30, SimilarityChecker().checkLength("AA", "AAA"));
}

TEST(TestCaseName, AlphabetCheck) {
	EXPECT_EQ(40, SimilarityChecker().checkAlphabet("ASD", "DSA"));
	EXPECT_EQ(0, SimilarityChecker().checkAlphabet("A", "BB"));
	EXPECT_EQ(40, SimilarityChecker().checkAlphabet("AAABB", "BA"));
	EXPECT_EQ(20, SimilarityChecker().checkAlphabet("AA", "AAE"));
}

TEST(TestCaseName, SimilarityCheck) {
	EXPECT_EQ(100, SimilarityChecker().checkSimilarity("ASD", "DSA"));
	EXPECT_EQ(0, SimilarityChecker().checkSimilarity("A", "BB"));
	EXPECT_EQ(60, SimilarityChecker().checkSimilarity("AAABB", "BAA"));
	EXPECT_EQ(40, SimilarityChecker().checkSimilarity("AAABB", "BA"));
	EXPECT_EQ(70, SimilarityChecker().checkSimilarity("AA", "AAA"));
	EXPECT_EQ(50, SimilarityChecker().checkSimilarity("AA", "AAE"));
}