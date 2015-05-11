package test;

import utilities.*;

public class Test {
	
	static byte BYTE_DATA[] = {
		-99,
		-9,
		0,
		10,
		100
	};
	
	static short SHORT_DATA[] = {
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
	
	static int INT_DATA[] = {
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
	
	static long LONG_DATA[] = {
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
	
	public static boolean runTests() {
		boolean success = true;
		
		System.out.println("Testing randomInteger:");
		int n;
		boolean generatedMin;
		boolean generatedMax;
		boolean testPassed = true;
		int testIntRanges[][] = {
			{    4,   16 },
			{    0,    1 },
			{ -100,  100 },
			{   -1,    2 }
		};
		for(int i=0;i<testIntRanges.length;i++) {
			generatedMin = false;
			generatedMax = false;
			for(int j=0;j<5000;j++) {
				n = Utilities.randomInteger(testIntRanges[i][0], testIntRanges[i][1]);
				if(n == testIntRanges[i][0]) { generatedMin = true; }
				if(n == testIntRanges[i][1]) { generatedMax = true; }
				if(n < testIntRanges[i][0] || n > testIntRanges[i][1]) {
					System.out.println("Number generated outside of range (" + testIntRanges[i][0] + ", " + testIntRanges[i][1] + "): " + n);
					testPassed = false;
				}
			}
			if(!generatedMin) { System.out.println("Minimum int value never generated for range (" + testIntRanges[i][0] + ", " + testIntRanges[i][1] + ")!"); }
			if(!generatedMax) { System.out.println("Maximum int value never generated for range (" + testIntRanges[i][0] + ", " + testIntRanges[i][1] + ")!"); }
		}
		if(testPassed) {
			System.out.println("Test passed for randomInteger!");
		}
		else {
			System.out.println("Test failed for randomInteger!");
			success = false;
		}
		
		System.out.println();
		
		System.out.println("Testing randomFloat:");
		float f;
		testPassed = true;
		float testFloatRanges[][] = {
			{    4.0f,   16.0f },
			{    0.0f,    1.0f },
			{ -100.0f,  100.0f },
			{   -1.0f,    2.0f }
		};
		for(int i=0;i<testFloatRanges.length;i++) {
			generatedMin = false;
			generatedMax = false;
			for(int j=0;j<10000;j++) {
				f = Utilities.randomFloat(testFloatRanges[i][0], testFloatRanges[i][1]);
				if(f - testFloatRanges[i][0] < 0.01f) { generatedMin = true; }
				if(testFloatRanges[i][1] - f < 0.01f)  { generatedMax = true; }
				if(f < testFloatRanges[i][0] || f > testFloatRanges[i][1]) {
					System.out.println("Number generated outside of range (" + testFloatRanges[i][0] + ", " + testFloatRanges[i][1] + "): " + f);
					testPassed = false;
				}
			}
			if(!generatedMin) { System.out.println("Minimum float value never generated for range (" + testFloatRanges[i][0] + ", " + testFloatRanges[i][1] + ")!"); }
			if(!generatedMax) { System.out.println("Maximum float value never generated for range (" + testFloatRanges[i][0] + ", " + testFloatRanges[i][1] + ")!"); }
		}
		if(testPassed) {
			System.out.println("Test passed for randomFloat!");
		}
		else {
			System.out.println("Test failed for randomFloat!");
			success = false;
		}
		
		System.out.println();
		
		System.out.println("Testing byteLength:");
		if(testByteLength()) {
			System.out.println("Test passed for byteLength!");
		}
		else {
			System.out.println("Test failed for byteLength!");
			success = false;
		}
		
		System.out.println();
		
		System.out.println("Testing shortLength:");
		if(testShortLength()) {
			System.out.println("Test passed for shortLength!");
		}
		else {
			System.out.println("Test failed for shortLength!");
			success = false;
		}
		
		System.out.println();
		
		System.out.println("Testing intLength:");
		if(testIntLength()) {
			System.out.println("Test passed for intLength!");
		}
		else {
			System.out.println("Test failed for intLength!");
			success = false;
		}
		
		System.out.println();
		
		System.out.println("Testing longLength:");
		if(testLongLength()) {
			System.out.println("Test passed for longLength!");
		}
		else {
			System.out.println("Test failed for longLength!");
			success = false;
		}
		
		System.out.println();
		
		if(success) {
			System.out.println("All tests passed successfully!");
		}
		else {
			System.out.println("One or more tests failed, see console for more details!");
		}
		
		return success;
	}
	
	public static boolean testByteLength() {
		byte value;
		int length;
		boolean valid = false;
		boolean success = true;
		for(int i=0;i<BYTE_DATA.length;i++) {
			for(byte j=-2;j<3;j++) {
				value = (byte) (BYTE_DATA[i] + j);
				length = Utilities.byteLength(value);
				valid = length == Byte.toString(value).length();
				if(!valid) { success = false; }
				System.out.println("Byte[" + i + "]: " + value + " (" + length + ") " + (valid ? "PASS" : "FAIL"));
			}
		}
		return success;
	}
	
	public static boolean testShortLength() {
		short value;
		int length;
		boolean valid = false;
		boolean success = true;
		for(int i=0;i<SHORT_DATA.length;i++) {
			for(short j=-2;j<3;j++) {
				value = (short) (SHORT_DATA[i] + j);
				length = Utilities.shortLength(value);
				valid = length == Short.toString(value).length();
				if(!valid) { success = false; }
				System.out.println("Short[" + i + "]: " + value + " (" + length + ") " + (valid ? "PASS" : "FAIL"));
			}
		}
		return success;
	}
	
	public static boolean testIntLength() {
		int value;
		int length;
		boolean valid = false;
		boolean success = true;
		for(int i=0;i<INT_DATA.length;i++) {
			for(int j=-2;j<3;j++) {
				value = (int) (INT_DATA[i] + j);
				length = Utilities.intLength(value);
				valid = length == Integer.toString(value).length();
				if(!valid) { success = false; }
				System.out.println("Int[" + i + "]: " + value + " (" + length + ") " + (valid ? "PASS" : "FAIL"));
			}
		}
		return success;
	}
	
	public static boolean testLongLength() {
		long value;
		int length;
		boolean valid = false;
		boolean success = true;
		for(int i=0;i<LONG_DATA.length;i++) {
			for(long j=-2;j<3;j++) {
				value = (long) (LONG_DATA[i] + j);
				length = Utilities.longLength(value);
				valid = length == Long.toString(value).length();
				if(!valid) { success = false; }
				System.out.println("Long[" + i + "]: " + value + " (" + length + ") " + (valid ? "PASS" : "FAIL"));
			}
		}
		return success;
	}
	
}
