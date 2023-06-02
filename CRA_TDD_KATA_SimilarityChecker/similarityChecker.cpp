#include <string>
using namespace std;

class SimilarityChecker
{
public:
	const int MAX_LENGTH_POINT = 60;
	const int MIN_LENGTH_POINT = 0;
	const int MAX_ALPHABET_POINT = 40;

	int checkSimilarity(string str1, string str2)
	{
		return checkLength(str1, str2) + checkAlphabet(str1, str2);
	}

	int checkLength(string str1, string str2)
	{
		if (isSameLength(str1.size(), str2.size())) return MAX_LENGTH_POINT;
		if (isInvalidLengthDiff(str1.size(), str2.size())) return MIN_LENGTH_POINT;
		return getLengthPoint(str1.size(), str2.size());
	}

	int checkAlphabet(string str1, string str2)
	{
		AlphabetCheckResult result = getSameAndTotalCount(str1, str2);

		if (result.totalCnt == 0) return 0;
		return result.sameCnt * MAX_ALPHABET_POINT / result.totalCnt;
	}

private :
	struct AlphabetCheckResult { int sameCnt, totalCnt; };

	bool isSameLength(int str1Size, int str2Size)
	{
		return (str1Size == str2Size);
	}

	bool isInvalidLengthDiff(int str1Size, int str2Size)
	{
		if (str1Size > str2Size) return (str1Size >= str2Size * 2);
		return (str2Size >= str1Size * 2);
	}

	int getLengthPoint(int str1Size, int str2Size)
	{
		if (str1Size > str2Size) return (MAX_LENGTH_POINT * 2) - (str1Size * MAX_LENGTH_POINT / str2Size);
		return MAX_LENGTH_POINT * 2 - (str2Size * MAX_LENGTH_POINT / str1Size);
	}

	int beFound(string str1, char alphabet)
	{
		for (char ch1 : str1) {
			if (alphabet == ch1) return 1;
		}
		return 0;
	}

	AlphabetCheckResult getSameAndTotalCount(string str1, string str2)
	{
		AlphabetCheckResult result = { 0,0 };
		for (char alphabet = 'A'; alphabet <= 'Z'; alphabet++) {
			int found = beFound(str1, alphabet) + beFound(str2, alphabet);
			if (found >= 1) result.totalCnt++;
			if (found == 2) result.sameCnt++;
		}
		return result;
	}
};