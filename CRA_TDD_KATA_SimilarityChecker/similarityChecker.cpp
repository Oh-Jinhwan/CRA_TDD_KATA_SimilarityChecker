#include <string>
using namespace std;

class SimilarityChecker
{
public:
	int checkSimilarity(string str1, string str2)
	{
		return checkLength(str1, str2) + checkAlphabet(str1, str2);
	}

	int checkLength(string str1, string str2)
	{
		if (isSameLength(str1.size(), str2.size())) return 60;
		if (isInvalidLengthDiff(str1.size(), str2.size())) return 0;
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
		if (str1Size > str2Size) return 120 - (str1Size * 60 / str2Size);
		return 120 - (str2Size * 60 / str1Size);
	}
};