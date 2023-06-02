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
		int sameCnt = 0;
		int totalCnt = 0;

		getSameAndTotalCount(str1, str2, sameCnt, totalCnt);

		if (totalCnt == 0) return 0;
		return sameCnt * MAX_ALPHABET_POINT / totalCnt;
	}

private :
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

	void getSameAndTotalCount(string str1, string str2, int& sameCnt, int& totalCnt)
	{
		for (char alphabet = 'A'; alphabet <= 'Z'; alphabet++) {
			int found = 0;
			for (char ch1 : str1) {
				if (alphabet == ch1) {
					found++;
					break;
				}
			}
			for (char ch2 : str2) {
				if (alphabet == ch2) {
					found++;
					break;
				}
			}
			if (found >= 1) totalCnt++;
			if (found == 2) sameCnt++;
		}
	}
};