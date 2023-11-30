#pragma once
#include <iostream>

enum value
{
	False, Unknown, True
};

class Logic
{
	value v;

public:
	Logic()
	{
		v = Unknown;
	}

	Logic(value v)
	{
		this->v = v;
	}

	void SetValue(value v);

	value GetValue() const;

	void Print();

	bool operator==(const Logic& other) const;

	bool operator!=(const Logic& other) const;

	Logic operator!() const;

	Logic operator&&(const Logic& other) const;

	Logic operator||(const Logic& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Logic& logic)
	{
		switch (logic.v)
		{
		case True:
			os << "True";
			break;
		case Unknown:
			os << "Unknown";
			break;
		case False:
			os << "False";
			break;
		}
		return os;
	}
};