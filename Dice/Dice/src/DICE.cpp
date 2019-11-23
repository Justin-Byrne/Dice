#include "../include/DICE.h"
#include <stdlib.h>		/* rand */

/// <summary>
/// DICE Constructor
/// </summary>
/// <param name="sides">Amount of Sides</param>
/// <param name="multi">Multiplies of base number</param>
DICE::DICE(int& sides, int& multi) :
	m_sides(sides), m_multi(multi) { };

/// /// <summary>
/// Default Constructor
/// </summary>
DICE::DICE() { }

/// <summary>
/// Default De-Constructor
/// </summary>
DICE::~DICE() { }

/// <summary>
/// Sets the Type of Dice
/// </summary>
/// <param name="type">Type of Dice</param>
void DICE::set_type(const char* type)
{
	this->m_type = type;
}

/// <summary>
/// Set Amount of Sides for Dice
/// </summary>
/// <param name="sides">Amount of Sides</param>
void DICE::set_sides(int& sides)
{
	this->m_sides = sides;
}

/// <summary>
/// Set Numeric Multiplier Value
/// </summary>
/// <param name="base">Multiplier Value</param>
void DICE::set_multi(int& multi)
{
	this->m_multi = multi;
}

/// <summary>
/// Set Final Value of Dice
/// </summary>
/// <param name="value">Value of Dice</param>
void DICE::set_value(int value)
{
	this->m_value = value;
}

/// <summary>
/// Gets the Type of Dice
/// </summary>
/// <returns>Type of Dice</returns>
const char* DICE::get_type()
{
	return this->m_type;
}

/// <summary>
/// Get Amount of Sides
/// </summary>
/// <returns>Amount of Sides</returns>
int DICE::get_sides()
{
	return this->m_sides;
}

/// <summary>
/// Get Numeric Multiplier Value
/// </summary>
/// <returns>Multiplier Value</returns>
int DICE::get_multi()
{
	return this->m_multi;
}

/// <summary>
/// Get Final Value of Dice
/// </summary>
/// <returns>Value of Dice</returns>
int DICE::get_value()
{
	return this->m_value;
}

/// <summary>
/// Roll Dice and Have Side Rolled Returned
/// </summary>
/// <returns>Side Rolled</returns>
int DICE::roll_dice()
{
	return (rand() % this->m_sides + 1);
}