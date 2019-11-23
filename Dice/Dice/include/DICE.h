#include <vector>

#ifndef _DICE_H
#define _DICE_H

class DICE
{
private:
	// MEMBERS VARIABLES
	const char* m_type;
	int m_sides;
	int m_multi;
	int m_value;

public:

	// CONSTRUCTORS
	DICE(int& sides, int& multi);
	DICE();
	~DICE();

	// SETTERS
	void set_type(const char* type);
	void set_sides(int& sides);
	void set_multi(int& multi);
	void set_value(int value);

	// GETTERS
	const char* get_type();
	int get_sides();
	int get_multi();
	int get_value();

	// PUBLIC FUNCTIONS
	int roll_dice();
};

#endif // !_DICE_H