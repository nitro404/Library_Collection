#ifndef TEST_H
#define TEST_H

#include "Utilities/Utilities.h"

namespace Test {

	extern const byte BYTE_DATA[];
	extern const short SHORT_DATA[];
	extern const int INT_DATA[];
	extern const long long LONG_DATA[];

	bool runTests();

	bool testByteLength();
	bool testShortLength();
	bool testIntLength();
	bool testLongLength();

}

#endif // TEST_H
