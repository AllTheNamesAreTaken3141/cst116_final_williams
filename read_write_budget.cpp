#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

// I know I'm supposed to be overwriting the original file,
// but I really don't want to have to redownload it
// every time something doesn't work.
// It would take me about 10 seconds to make it overwrite the original file.
// I'll explain how that works when you get there.
string OUTPUT_PATH = "./Fixed_File-1.txt";

const string VALID_CHARACTERS = "abcdefghijklmnopqrstuvwxyz0123456789$, \n";

// Turns a file into a vector containing each line as an element.
std::vector<string> readLines(std::ifstream& input)
{
	std::vector<string> lines = {};
	for (string line; getline(input, line);)
	{
		lines.push_back(line);
	}
	return lines;
}

std::vector<string> validateLines(std::vector<string> lines)
{
	std::vector<string> validLines = {};
	int lineCounter = 1;
	for (string line : lines)
	{
		// Break lines up into segments by spaces.
		std::istringstream lineStream(line);
		std::vector<string> lineSegments = {};
		while(!lineStream.eof()) {
			string temp;
			lineStream >> temp;
			lineSegments.push_back(temp);
		}
		bool error = false;

		// Make sure line contains only valid characters.
		for (string s : lineSegments)
		{
			for (char c : s)
			{
				if (VALID_CHARACTERS.find(tolower(c)) == -1)
				{
					error = true;
					break;
				}
			}
			if (error) { break; }
		}

		if (error)
		{
			cout << "Error at line " << lineCounter << ": line contains invalid characters!" << endl;
			lineCounter++;
			continue;
		}

		// Check for errors.
		if (size(lineSegments) < 3)
		{
			cout << "Error at line " << lineCounter << ": not enough items!" << endl;
		}
		else if (size(lineSegments) > 3)
		{
			cout << "Error at line " << lineCounter << ": too many items!" << endl;
		}
		else if (size(lineSegments) > 3)
		{
			cout << "Error at line " << lineCounter << ": too many items!" << endl;
		}
		else if (lineSegments[2][0] != '$')
		{
			cout << "Error at line " << lineCounter << ": budget does not have a '$'!" << endl;
		}
		else if (!std::stoi(lineSegments[1]))
		{
			cout << "Error at line " << lineCounter << ": number of people is not a number!" << endl;
		}
		else
		{
			validLines.push_back(line);
		}

		lineCounter++;
	}
	return validLines;
}

void reverseWrite(std::ofstream& outFile, std::vector<string> lines)
{
	for (int i = size(lines) - 1; i >= 0; i--)
	{
		outFile << lines[i] << endl;
	}
}

/*
int main()
{
	string inputPath;
	cout << "Enter the path to your file: ";
	cin >> inputPath;
	// OUTPUT_PATH = inputPath; // This is the only thing preventing the overwrite.
	std::ifstream inputFile(inputPath);
	std::vector<string> lines = readLines(inputFile);
	inputFile.close();

	std::vector<string> validLines = validateLines(lines);

	std::ofstream outputFile;

	// Clears the output file.
	outputFile.open(OUTPUT_PATH, std::ofstream::trunc);
	outputFile.close();

	outputFile.open(OUTPUT_PATH);
	reverseWrite(outputFile, validLines);
	outputFile.close();

	return 0;
}
*/