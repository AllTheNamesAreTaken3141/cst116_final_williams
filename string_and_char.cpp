#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// Excuse my dumb humor, I got 4 hours of sleep last night.
string testString1 = "Thou shalt not add an unholy fifthglyph to a string.";
string testString2 = "By fifthglyph, I am obviously talking about the character 'e'.";
string testString3 = "\"To destroy your enemy on the battlefield, you must first destroy his mother in the bedroom.\" - Sun Tzu, 'The Art of War'";

char testChar1[256] = "Thou shalt not add an unholy fifthglyph to a string.";
char testChar2[256] = "By fifthglyph, I am obviously talking about the character 'e'.";
char testChar3[256] = "\"To destroy your enemy on the battlefield, you must first destroy his mother in the bedroom.\" - Sun Tzu, 'The Art of War'";

string slash(string inStr, char ch)
{
	for (int i = 0; i < inStr.size(); i++)
	{
		if (inStr[i] == ch)
		{
			inStr[i] = '\\';
		}
	}
	return inStr;
}

string deslash(string inStr, char ch)
{
	for (int i = 0; i < inStr.size(); i++)
	{
		if (inStr[i] == '\\')
		{
			inStr[i] = 'e';
		}
	}
	return inStr;
}

char* slash(char* inChar, char ch)
{
	for (int i = 0; i < strlen(inChar); i++)
	{
		if (inChar[i] == ch)
		{
			inChar[i] = '\\';
		}
	}
	return inChar;
}

char* deslash(char* inChar, char ch)
{
	for (int i = 0; i < strlen(inChar); i++)
	{
		if (inChar[i] == '\\')
		{
			inChar[i] = 'e';
		}
	}
	return inChar;
}

/*
int main() {

	cout << "String in: " << testString1 << endl;
	string outStr1 = slash(testString1, 'e');
	cout << "Slashed string: " << outStr1 << endl;
	cout << "Deslashed string: " << deslash(outStr1, 'e') << endl << endl;
 
	cout << "String in: " << testString2 << endl;
	string outStr2 = slash(testString2, 'e');
	cout << "Slashed string: " << outStr2 << endl;
	cout << "Deslashed string: " << deslash(outStr2, 'e') << endl << endl;

	cout << "String in: " << testString3 << endl;
	string outStr3 = slash(testString3, 'e');
	cout << "Slashed string: " << outStr3 << endl;
	cout << "Deslashed string: " << deslash(outStr3, 'e') << endl << endl;


	cout << "Char in: " << testChar1 << endl;
	char* outChar1 = slash(testChar1, 'e');
	cout << "Slashed char: " << outChar1 << endl;
	cout << "Deslashed char: " << deslash(outChar1, 'e') << endl << endl;

	cout << "Char in: " << testChar2 << endl;
	char* outChar2 = slash(testChar2, 'e');
	cout << "Slashed char: " << outChar2 << endl;
	cout << "Deslashed char: " << deslash(outChar2, 'e') << endl << endl;

	cout << "Char in: " << testChar3 << endl;
	char* outChar3 = slash(testChar3, 'e');
	cout << "Slashed string: " << outChar3 << endl;
	cout << "Deslashed string: " << deslash(outChar3, 'e') << endl << endl;

	return 0;
}
*/