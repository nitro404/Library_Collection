#ifndef UTILITIES_H
#define UTILITIES_H

#if !USE_QT && !USE_STL
#define USE_STL 1
#endif // !USE_QT && !USE_STL

#if USE_QT
#include <QString.h>
#endif // USE_QT
#if USE_STL
#include <iostream>
#endif // USE_STL

namespace Utilities {
	extern const char newLine[];

	unsigned int stringLength(const char * s);
	const char * toString(int value);
	const char * toString(double value);
	bool copyString(char * destination, int size, const char * source);
	char * copyString(const char * data);
	char * trimCopyString(const char * data);
#if USE_STL
	std::string trimString(const std::string & data);
#endif // USE_STL
	char * substring(const char * data, int start, int end);
#if USE_QT
	QString substring(const QString & data, int start, int end);
#endif // USE_QT
#if USE_STL
	std::string substring(const std::string & data, int start, int end);
#endif // USE_STL
	int compareStrings(const char * s1, const char * s2, bool caseSensitive = true);
#if USE_QT
	int compareStrings(const char * s1, const QString & s2, bool caseSensitive = true);
	int compareStrings(const QString & s1, const char * s2, bool caseSensitive = true);
#endif // USE_QT
	int compareStringsIgnoreCase(const char * s1, const char * s2);
#if USE_QT
	int compareStringsIgnoreCase(const char * s1, const QString & s2);
	int compareStringsIgnoreCase(const QString & s1, const char * s2);
#endif // USE_QT
}

#endif // UTILITIES_H
