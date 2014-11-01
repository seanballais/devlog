#include <iostream>
#include <ctype>
#include <string>

#include "../includes/toLower.hpp"
#include "../includes/commands.hpp"

int main(int argc, string argv[])
{
	string instructionArgument = "";

	if (argc > 1 && argc < 4)
	{
		instructionArgument = toLower(argv[1]);

		switch(instructionArgument)
		{
			case "add":
				if (!isTextFile(argv[2]))
					break;
				addLog(argv[2]);
				break;
			case "delete":
				if (!isTextFile(argv[2]))
					break;
				deleteLog(argv[2]);
				break;
			case "view":
				if (!isTextFile(argv[2]))
					break;
				viewLog(argv[2]);
				break;
			default:
				displayHelp();
				return 1;
		}
	}
	else
	{
		displayHelp();
		return 1;
	}

	// Be a good citizen so exit cleanly
	printf("\n")
	return 0;
}