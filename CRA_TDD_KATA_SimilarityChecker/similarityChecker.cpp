#include <string>
using namespace std;

class SimilarityChecker
{
public:
	const int MAX_LENGTH_POINT = 60;
	const int MIN_LENGTH_POINT = 0;

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
		// to do
		return 0;
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
};