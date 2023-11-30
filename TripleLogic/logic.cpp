#include <iostream>	
#include "logic.h"

void Logic::Print()
{
	switch (v)
	{
	case False:
		std::cout << "False";
		break;
	case Unknown:
		std::cout << "Unknown";
		break;
	case True:
		std::cout << "True";
		break;
	}
}

void Logic::SetValue(value val)
{
	v = val;
}


value Logic::GetValue() const
{
	return v;
}

bool Logic::operator==(const Logic& other) const
{
	return v == other.v;
}

bool Logic::operator!=(const Logic& other) const
{
	return v != other.v;
}

Logic Logic::operator!() const
{
	if (v == False)
	{
		return True;
	}
	else if (v == Unknown)
	{
		return Unknown;
	}
	else
	{
		return False;
	}
}

Logic Logic::operator&&(const Logic& other) const
{
    if ((v == False) || (other.v == False))
    {
        return False;
    }
    else if ((v == Unknown) || (other.v == Unknown))
    {
        return Unknown;
    }
    else
    {
        return True;
    }
}

Logic Logic::operator||(const Logic& other) const
{
    if ((v == True) || (other.v == True))
    {
        return True;
    }
    else if ((v == Unknown) || (other.v == Unknown))
    {
        return Unknown;
    }
    else
    {
        return False;
    }
}


