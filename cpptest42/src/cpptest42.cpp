//============================================================================
// Name        : cpptest42.cpp
// Author      : Zimin Wei
// Version     :
// Copyright   : Your copyright notice
// Description : C++ TEST2 in C++
//============================================================================
/*
 * a switch statement can be followed by any valid statement including a compound (block) statement.
 * The only difference from a general compound statement is that case and default labels can appear
 * inside it. Jumping into the nested do-while block is legal, and its execution is not altered by
 * the case labels
 */

#include <iostream>

int main() {
    int n = 3;
    int i = 0;

    switch (n % 2) {
    case 0:
		do {
			++i;
			case 1: ++i;
		} while (--n > 0);
    }

    std::cout << i;
}
