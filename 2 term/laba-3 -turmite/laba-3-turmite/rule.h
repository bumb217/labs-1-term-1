
#ifndef RULE_H
#define RULE_H

#include <fstream>
using namespace std;

enum DIR {North, East, South, West};

class Turmite;

class Rule {
	char cur_state;
	int cur_col;

	char new_state;
	int new_col;

	DIR direction;

	friend class Turmite;

public:

	Rule(pair<char, int>, pair<char, int>, DIR);

	static Rule* read(ifstream &in) {
		int b_color, e_color, direction;
		char b_state, e_state;

		in >> b_state;
		in >> b_color >> e_state;
		in >> e_color >> direction;

		return new Rule(pair<char, int>(b_state, b_color),
						pair<char, int>(e_state, e_color),
						(DIR)direction);
	}
};

#endif
