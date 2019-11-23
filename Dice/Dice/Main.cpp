/**
 * @package:   Dice
 * @version:   0.2.0 11/23/2019
 * @file:      Main.cpp
 * @brief:     Dice
 * @author:    Justin D. Byrne <justin@byrne-systems.com>
 * @copyright: <LICENSE>
 */

#include <iostream>     /* cin, cout */
#include <stdlib.h>		/* atoi, srand, rand */
#include <regex>		/* regex, regex_match, cmatch */
#include <vector>		/* vector */
#include <time.h>		/* time */
#include "include/DICE.h" 

const char* version_no = "0.2.0";

int validate_argument(const char* arg, std::regex regex, const char* position, bool temp = false);
void stage_dice(int& sides, int& rolls, int multi = 1);
void display_results(std::vector<DICE>& die);
void error(const char* msg);
void help();
void version();
void exit();

/// <summary>
/// Main Programs Entry Point
/// </summary>
/// <param name="argc">Argument Count: Number of command line arguments</param>
/// <param name="argv">Argument Vector: Actual arguments</param>
/// <returns>INT : Exit Code</returns>
int main(int argc, const char* argv[])
{
	int sides{}, multi{}, rolls{};

	std::regex regex_one("(d|D)\\d{1,2}");
	std::regex regex_two("\\d+");

	srand(time(NULL));					// <! Seed srand() with time signature

	switch (argc)
	{
	case 2:
		if (!strcmp(argv[1], "--help"))
		{
			help();
		}
		else if (!strcmp(argv[1], "--version"))
		{
			version();
		}
		else
		{
			error("The arguments supplied don't match the desired pattern.");
		}
		break;
	case 3:
		sides = validate_argument(argv[1], regex_one, "First", true);
		rolls = validate_argument(argv[2], regex_two, "Second");

		stage_dice(sides, rolls);

		break;
	case 4:
		sides = validate_argument(argv[1], regex_one, "First", true);
		rolls = validate_argument(argv[2], regex_two, "Second");
		multi = validate_argument(argv[3], regex_two, "Third");

		stage_dice(sides, rolls, multi);

		break;
	default:
		error("The arguments supplied don't match the desired pattern.");
		break;
	}

	return EXIT_SUCCESS;
}

/// <summary>
/// Validates the vector argument passed via the parameter
/// </summary>
/// <param name="arg">Vector Argument</param>
/// <param name="regex">Regular Expression Pattern</param>
/// <param name="position">Position of the Argument</param>
/// <param name="temp">Whether a Temporary Character Needs to be Employed</param>
/// <returns>Number value extracted from argument</returns>
int validate_argument(const char* arg, std::regex regex, const char* position, bool temp)
{
	int result{};
	const char* temp_char{};
	std::cmatch cm;

	if (std::regex_match(arg, cm, regex))
	{
		if (!temp)
		{
			result = atoi(arg);
		}
		else
		{
			temp_char = arg;
			result = atoi(++temp_char);
		}
	}
	else
	{
		error("First argument does not match specified pattern.");
	}

	return result;
}

/// <summary>
/// Sets the stage and type of dice to be rolled
/// </summary>
/// <param name="sides">Amount of Sides for the Generated Die</param>
/// <param name="rolls">Amount of Rolls</param>
/// <param name="multi">Multiplier Value to be Applied</param>
void stage_dice(int& sides, int& rolls, int multi)
{
	std::vector<DICE> die;

	for (size_t i = 0; i < rolls; i++)
	{
		die.push_back(DICE(sides, multi));				// <! Generate dice

		switch (sides)	// <! Identify dice type
		{
		case 4:		die[i].set_type("Tetrahedron");			    break;
		case 6:		die[i].set_type("Cube");					break;
		case 8:		die[i].set_type("Octahedron");				break;
		case 10:	die[i].set_type("Pentagonal Trapeohedron");	break;
		case 12:	die[i].set_type("Dodecahedron");			break;
		case 20:	die[i].set_type("Icosahedron");				break;
		default:	die[i].set_type("Custom");					break;
		}
	}

	for (size_t i = 0; i < die.size(); i++)				// Roll Dice
		die[i].set_value(die[i].roll_dice());

	display_results(die);
}

/// <summary>
/// Displays the amount (and final totals) of the die being rolled
/// </summary>
/// <param name="die">DICE to be rolled</param>
void display_results(std::vector<DICE>& die)
{
	int total{};

	for (size_t i = 0; i < die.size(); i++)
		total += die[i].get_value();

	std::cout << " > Results:" << std::endl;
	std::cout << "\tAmount of Dice:\t" << die.size() << "\n" << std::endl;

	for (size_t i = 0; i < die.size(); i++)
	{
		std::cout << " > Generated Dice | ";
		std::cout << "[TYPE]: "        << die[i].get_type();
		std::cout << "  [SIDES]: "     << die[i].get_sides();
		std::cout << "  [MULTIPLES]: " << die[i].get_multi();
		std::cout << "  [VALUE]: "     << die[i].get_value();
		std::cout << std::endl;
	}

	std::cout << "\nTotal: " << total * die[0].get_multi() << std::endl;

	exit();
}

/// <summary>
/// Displays error message
/// </summary>
/// <param name="msg">Message to Display</param>
void error(const char* msg)
{
	std::cout << "\n[error] " << msg << std::endl;
	std::cout << " : Please evaluate your previous command and try again!\n" << std::endl;

	exit();
}

/// <summary>
/// Displays help and usage information for this program
/// </summary>
void help()
{
	std::cout << std::endl;
	std::cout << "Usage:\tDice D[no] [rolls] <[multi]>" << std::endl;
	std::cout << std::endl;
	std::cout << "\tOptions:\t" << std::endl;
	std::cout << "\t\t--help\t\tDisplay this help and exit" << std::endl;
	std::cout << "\t\t--version\tOutput version information and exit" << std::endl;
	std::cout << std::endl;
	std::cout << "\tParams:\t" << std::endl;
	std::cout << "\t\t[no]\t\tNumber associated with the type of dice generated" << std::endl;
	std::cout << "\t\t[rolls]\t\tAmount of rolls that each dice should be rolled" << std::endl;
	std::cout << "\t\t[multi]\t\t[Optional]: Multiplier to be applied to the value rolled" << std::endl;
	std::cout << std::endl;
}

/// <summary>
/// Displays version information for this program
/// </summary>
void version()
{
	std::cout << "\nVersion: " << version_no << "\n" << std::endl;
}

/// <summary>
/// Exiting sequence
/// </summary>
void exit()
{
	std::cout << "Press any key to escape!" << std::endl;

	std::cin.get();
}