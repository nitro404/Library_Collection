#include "Test.h"

using namespace std;

namespace Test {

	const byte BYTE_DATA[] = {
		-99,
		-9,
		0,
		10,
		100
	};
	
	const short SHORT_DATA[] = {
		-9999,
		-999,
		-99,
		-9,
		0,
		10,
		100,
		1000,
		10000
	};
	
	const int INT_DATA[] = {
		-999999999,
		-99999999,
		-9999999,
		-999999,
		-99999,
		-9999,
		-999,
		-99,
		-9,
		0,
		10,
		100,
		1000,
		10000,
		100000,
		1000000,
		10000000,
		100000000,
		1000000000,
	};
	
	const long long LONG_DATA[] = {
			-999999999999999999L,
			-99999999999999999L,
			-9999999999999999L,
			-999999999999999L,
			-99999999999999L,
			-9999999999999L,
			-999999999999L,
			-99999999999L,
			-9999999999L,
			-999999999L,
			-99999999L,
			-9999999L,
			-999999L,
			-99999L,
			-9999L,
			-999L,
			-99L,
			-9L,
			0L,
			10L,
			100L,
			1000L,
			10000L,
			100000L,
			1000000L,
			10000000L,
			100000000L,
			1000000000L,
			10000000000L,
			100000000000L,
			1000000000000L,
			10000000000000L,
			100000000000000L,
			1000000000000000L,
			10000000000000000L,
			100000000000000000L,
			1000000000000000000L
	};
	
	bool runTests() {
		bool success = true;

		string output;
		
		printf("Testing randomInteger:\n");
		int n;
		bool generatedMin;
		bool generatedMax;
		bool testPassed = true;
		int testIntRanges[][2] = {
			{    4,   16 },
			{    0,    1 },
			{ -100,  100 },
			{   -1,    2 }
		};
		for(int i=0;i<4;i++) {
			generatedMin = false;
			generatedMax = false;
			for(int j=0;j<5000;j++) {
				n = Utilities::randomInteger(testIntRanges[i][0], testIntRanges[i][1]);
				if(n == testIntRanges[i][0]) { generatedMin = true; }
				if(n == testIntRanges[i][1]) { generatedMax = true; }
				if(n < testIntRanges[i][0] || n > testIntRanges[i][1]) {
					output.clear();
					output.append("Integer generated outside of range (");
					output.append(Utilities::toString(testIntRanges[i][0]));
					output.append(", ");
					output.append(Utilities::toString(testIntRanges[i][1]));
					output.append("): ");
					output.append(Utilities::toString(n));
					printf("%s\n", output.data());
					testPassed = false;
				}
			}
			if(!generatedMin) {
				output.clear();
				output.append("Minimum int value never generated for range (");
				output.append(Utilities::toString(testIntRanges[i][0]));
				output.append(", ");
				output.append(Utilities::toString(testIntRanges[i][1]));
				output.append(")!");
				printf("%s\n", output.data());
			}
			if(!generatedMax) {
				output.clear();
				output.append("Maximum int value never generated for range (");
				output.append(Utilities::toString(testIntRanges[i][0]));
				output.append(", ");
				output.append(Utilities::toString(testIntRanges[i][1]));
				output.append(")!");
				printf("%s\n", output.data());
			}
		}
		if(testPassed) {
			printf("Test passed for randomInteger!\n");
		}
		else {
			printf("Test failed for randomInteger!\n");
			success = false;
		}
		
		printf("\nTesting randomFloat:\n");
		output.clear();
		float f;
		testPassed = true;
		float testFloatRanges[][2] = {
			{    4.0f,   16.0f },
			{    0.0f,    1.0f },
			{ -100.0f,  100.0f },
			{   -1.0f,    2.0f }
		};
		for(int i=0;i<4;i++) {
			generatedMin = false;
			generatedMax = false;
			for(int j=0;j<10000;j++) {
				f = Utilities::randomFloat(testFloatRanges[i][0], testFloatRanges[i][1]);
				if(f - testFloatRanges[i][0] < 0.01f) { generatedMin = true; }
				if(testFloatRanges[i][1] - f < 0.01f)  { generatedMax = true; }
				if(f < testFloatRanges[i][0] || f > testFloatRanges[i][1]) {
					output.clear();
					output.append("Float generated outside of range (");
					output.append(Utilities::toString(testIntRanges[i][0]));
					output.append(", ");
					output.append(Utilities::toString(testIntRanges[i][1]));
					output.append("): ");
					output.append(Utilities::toString(n));
					printf("%s\n", output.data());
					testPassed = false;
				}
			}
			if(!generatedMin) {
				output.clear();
				output.append("Minimum float value never generated for range (");
				output.append(Utilities::toString(testIntRanges[i][0]));
				output.append(", ");
				output.append(Utilities::toString(testIntRanges[i][1]));
				output.append(")!");
				printf("%s\n", output.data());
			}
			if(!generatedMax) {
				output.clear();
				output.append("Maximum float value never generated for range (");
				output.append(Utilities::toString(testIntRanges[i][0]));
				output.append(", ");
				output.append(Utilities::toString(testIntRanges[i][1]));
				output.append(")!");
				printf("%s\n", output.data());
			}
		}
		if(testPassed) {
			printf("Test passed for randomFloat!\n");
		}
		else {
			printf("Test failed for randomFloat!\n");
			success = false;
		}
		
		printf("\nTesting byteLength:\n");
		if(testByteLength()) {
			printf("Test passed for byteLength!\n");
		}
		else {
			printf("Test failed for byteLength!\n");
			success = false;
		}
		
		printf("\nTesting shortLength:\n");
		if(testShortLength()) {
			printf("Test passed for shortLength!\n");
		}
		else {
			printf("Test failed for shortLength!\n");
			success = false;
		}
		
		printf("\nTesting intLength:\n");
		if(testIntLength()) {
			printf("Test passed for intLength!\n");
		}
		else {
			printf("Test failed for intLength!\n");
			success = false;
		}
		
		printf("\nTesting longLongLength:\n");
		if(testLongLength()) {
			printf("Test passed for longLongLength!\n");
		}
		else {
			printf("Test failed for longLongLength!\n");
			success = false;
		}
		
		if(success) {
			printf("\nAll tests passed successfully!\n");
		}
		else {
			printf("\nOne or more tests failed, see console for more details!\n");
		}
		
		return success;
	}

	bool testByteLength() {
		byte value;
		int length;
		bool valid = false;
		bool success = true;
		char temp[64];
		string output;
		for(int i=0;i<5;i++) {
			for(byte j=-2;j<3;j++) {
				value = BYTE_DATA[i] + j;
				length = Utilities::byteLength(value);
				sprintf_s(temp, 64, "%d", value);
				valid = length == Utilities::stringLength(temp);
				if(!valid) { success = false; }
				output.clear();
				output.append("Byte[");
				sprintf_s(temp, 64, "%d", i);
				output.append(temp);
				output.append("]: ");
				sprintf_s(temp, 64, "%d", value);
				output.append(temp);
				output.append(" (");
				sprintf_s(temp, 64, "%d", length);
				output.append(temp);
				output.append(") ");
				output.append(valid ? "PASS" : "FAIL");
				printf("%s\n", output.data());
			}
		}
		return success;
	}
	
	bool testShortLength() {
		short value;
		int length;
		bool valid = false;
		bool success = true;
		char temp[64];
		string output;
		for(int i=0;i<9;i++) {
			for(short j=-2;j<3;j++) {
				value = SHORT_DATA[i] + j;
				length = Utilities::shortLength(value);
				sprintf_s(temp, 64, "%hd", value);
				valid = length == Utilities::stringLength(temp);
				if(!valid) { success = false; }
				output.clear();
				output.append("Short[");
				sprintf_s(temp, 64, "%d", i);
				output.append(temp);
				output.append("]: ");
				sprintf_s(temp, 64, "%hd", value);
				output.append(temp);
				output.append(" (");
				sprintf_s(temp, 64, "%d", length);
				output.append(temp);
				output.append(") ");
				output.append(valid ? "PASS" : "FAIL");
				printf("%s\n", output.data());
			}
		}
		return success;
	}
	
	bool testIntLength() {
		int value;
		int length;
		bool valid = false;
		bool success = true;
		char temp[64];
		string output;
		for(int i=0;i<19;i++) {
			for(int j=-2;j<3;j++) {
				value = INT_DATA[i] + j;
				length = Utilities::intLength(value);
				sprintf_s(temp, 64, "%d", value);
				valid = length == Utilities::stringLength(temp);
				if(!valid) { success = false; }
				output.clear();
				output.append("Int[");
				sprintf_s(temp, 64, "%d", i);
				output.append(temp);
				output.append("]: ");
				sprintf_s(temp, 64, "%d", value);
				output.append(temp);
				output.append(" (");
				sprintf_s(temp, 64, "%d", length);
				output.append(temp);
				output.append(") ");
				output.append(valid ? "PASS" : "FAIL");
				printf("%s\n", output.data());
			}
		}
		return success;
	}
	
	bool testLongLength() {
		long long value;
		int length;
		bool valid = false;
		bool success = true;
		char temp[64];
		string output;
		for(int i=0;i<37;i++) {
			for(long j=-2;j<3;j++) {
				value = LONG_DATA[i] + j;
				length = Utilities::longLongLength(value);
				sprintf_s(temp, 64, "%lld", value);
				valid = length == Utilities::stringLength(temp);
				if(!valid) { success = false; }
				output.clear();
				output.append("Long[");
				sprintf_s(temp, 64, "%d", i);
				output.append(temp);
				output.append("]: ");
				sprintf_s(temp, 64, "%lld", value);
				output.append(temp);
				output.append(" (");
				sprintf_s(temp, 64, "%d", length);
				output.append(temp);
				output.append(") ");
				output.append(valid ? "PASS" : "FAIL");
				printf("%s\n", output.data());
			}
		}
		return success;
	}

}
