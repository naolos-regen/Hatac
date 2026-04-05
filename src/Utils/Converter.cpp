#include "Converter.h"

#include <vector>

std::vector<std::string>
Convert::Args(const int argc, char ** argv)
{
	std::vector<std::string> arguments;

	for (int i = 0; i < argc; i++)
	{
		arguments.emplace_back(argv[i]);
	}

	return (arguments);
}
