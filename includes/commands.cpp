#include <iostream>
#include <string>
#include <ctime>

#include "commands.hpp"

using namespace std;

bool isTextFIle(string fileName)
{
	// Check if file is a .txt	
	if (fileName.find(".txt") != string::npos || fileName != null) // File is a .txt
		return true;
	displayHelp();
	cout << "No text file added or invalid file! Must be a text file!\n"
	return false;
}

void displayHelp()
{
	cout << "DevLog\n";
	cout << "Version 0.1 Alpha\n";
	cout << "Copyright (C) 2014, Sean Francis N. Ballais\n";
	cout << "Usage: devlog <command> <file>\n\n";
	cout << "<file> must be a .txt file. If <file> doesn't exist, log.txt will be created by the program.\n";
	cout << "NOTE: The current date and time will be used in the log.\n\n";
	cout << "DevLog commands:\n";
	cout << "\tadd\t- creates a new log if the <file> doesn't exist; otherwise, append to the contents of <file>\n";
	cout << "\tdelete\t- deletes <file>\n";
	cout << "\tview\t- views the contents of <file>\n";
	cout << "\thelp\t- displays this help\n";
}

// Add a, or append the log file
void addLog(string fileName)
{
	// Check if the user has added a file as an argument
	// Check if log.txt exists; if not, create a new log.txt file
	ifstream logFile("log.txt");
	ifstream checkFile(fileName)

	if (!logFile.is_open() ||
	 	!checkFile.is_open() || 
	 	fileName == null) // log.txt does not exist, no file specified, or file specified not found so create a new log.txt file
	{
		ofstream logFile("log.txt");
		logFile << "DevLog Version 0.1 | Log" << endl;
		fileName = "log.txt"; // Set the text file to be used as log.txt
	}

	// Get the current date and time
	time_t timeNow = time(0);

	// Convert to a string
	string dateTime = ctime(&timeNow);
	cout << "Date and Time: " << dateTime << "\n";

	string logEntry = "";
	cout << "[Type down your log entry now and do not press the Enter key unless your done writing your log entry]\n";
	cout << "Log Entry:\n";
	cin >> logEntry;

	cout << "Writing to log... ";

	// Append to the file the log entry
	ofstream logFile(fileName);

	logFile << "Date and Time: " << dateTime << endl;
	logFile << "Log Entry: " << endl;
	logFile << logEntry << endl;
	logfile << "===================================================================================" << endl;

	cout << "done!\n";
}

// Delete the log
void deleteLog(string fileName)
{
	ifstream checkFile(fileName);
	if (fileName == null || 
		!checkFile.is_open()) // Set to default log.txt if file is not specified, or does not exist
		fileName = "log.txt";

	cout << "Deleting log... ";

	if (remove(fileName) != 0)
		cout << "\nError deleting log. Did you create a new log before?\n";
	else
		cout << "done!\n";
}

// View the log
void viewLog(string fileName)
{
	ifstream checkFile(fileName);
	if (fileName == null ||
		!checkFile.is_open()) // Set to default log.txt if file is not specified, or does not exist
		fileName = "log.txt";

	cout << "Opening log... ";

	if (checkFile.is_open())
	{
		while (getline(checkFile, line))
			cout << line << "\n";
		checkFile.close();
	}
	else
	{
		cout << "\nError viewing log. Did you create a new log before?\n";
	}
}