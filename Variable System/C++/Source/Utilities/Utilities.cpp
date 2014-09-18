#include "Utilities/Utilities.h"

#if _WIN32
const char Utilities::newLine[] = "\r\n";
#elif __APPLE__
const char Utilities::newLine[] = "\r";
#else
const char Utilities::newLine[] = "\n";
#endif

unsigned int Utilities::stringLength(const char * s) {
	return s == NULL ? 0 : strlen(s);
}

const char * Utilities::toString(int value) {
	static char buffer[32];
#if _WIN32
	sprintf_s(buffer, 32, "%d", value);
#else
	sprintf(buffer, "%d", value);
#endif // _WIN32

	return buffer;
}

const char * Utilities::toString(double value) {
	static char buffer[32];
#if _WIN32
	sprintf_s(buffer, 32, "%f", value);
#else
	sprintf(buffer, "%f", value);
#endif // _WIN32

	return buffer;
}

bool Utilities::copyString(char * destination, int size, const char * source) {
	if(source == NULL || destination == NULL || size < 1) { return false; }

#if _WIN32
	return strcpy_s(destination, size, source) == 0;
#else
	return strcpy(destination, source) == 0;
#endif // _WIN32
}

char * Utilities::copyString(const char * data) {
	if(data == NULL) { return NULL; }

	int bufferSize = stringLength(data) + 1;
	char * newData = new char[bufferSize];
	if(copyString(newData, bufferSize, data)) {
		return newData;
	}
	return NULL;
}

// trims whitespace off of the front and end of string passed into it, and returns a copy of the trimmed string
char * Utilities::trimCopyString(const char * data) {
	// verify the string
	if(data == NULL) { return NULL; }
	char * newData = NULL;
	int length = stringLength(data);
	if(length == 0) {
		newData = new char[1];
		*newData = '\0';
		return newData;
	}

	// find the new start and end of the string and verify that they do not overlap (0 length string)
	const char * head = data;
	const char * tail = data + (sizeof(char) * length) - 1;
	int startPos = 0, endPos = length - 1;
	while((*head == ' ' || *head == '\t') && startPos <= endPos) {
		head += sizeof(char);
		startPos++;
	}
	while((*tail == ' ' || *tail == '\t') && startPos <= endPos) {
		tail -= sizeof(char);
		endPos--;
	}
	if(startPos > endPos) {
		newData = new char[1];
		*newData = '\0';
		return newData;
	}

	// copy the contents of the string from the start to the end into a new string (trim) and return the copy
	newData = new char[endPos - startPos + 2];
	char * temp = newData;
	for(int i=startPos;i<=endPos;i++) {
		*temp = data[i];
		temp += sizeof(char);
	}
	*temp = '\0';
	return newData;
}

#if !USE_QT
std::string Utilities::trimString(const std::string & data) {
	if(data.empty()) { return std::string(); }

	int start = 0;
	int end = data.length() - 1;

	for(unsigned int i=0;i<data.length();i++) {
		if(data[i] != ' ' && data[i] != '\t') {
			break;
		}

		start++;
	}

	for(unsigned int i=data.length() - 1;i>=0;i--) {
		if(data[i] != ' ' && data[i] != '\t') {
			break;
		}

		end--;
	}

	if(start > end) { return std::string(); }

	return data.substr(start, end - start);
}
#endif // !USE_QT

char * Utilities::substring(const char * data, int start, int end) {
	if(data == NULL || start > end) { return NULL; }

	int dataLength = stringLength(data);

	if(dataLength == 0) {
		char * newString = new char[1];
		newString[0] = '\0';

		return newString;
	}
	
	int startPos = start < 0 ? 0 : start;
	int endPos = end > dataLength ? dataLength : end;

	char * newString = new char[endPos - startPos + 1];
	int x = 0;
	for(int i=startPos;i<endPos;i++) {
		newString[x++] = data[i];
	}
	newString[x++] = '\0';

	return newString;
}

#if USE_QT
QString Utilities::substring(const QString & data, int start, int end) {
	if(data.isNull() || start > end) { return QString(); }

	if(data.isEmpty()) {
		return QString("");
	}

	int startPos = start < 0 ? 0 : start;
	int endPos = end > data.length() ? data.length() : end;

	return data.mid(startPos, endPos - startPos);
}
#else
std::string Utilities::substring(const std::string & data, int start, int end) {
	if(data.empty() || start > end) { return std::string(); }

	int startPos = start < 0 ? 0 : start;
	int endPos = end > static_cast<int>(data.length()) ? static_cast<int>(data.length()) : end;

	return data.substr(startPos, endPos - startPos);
}
#endif // USE_QT

int Utilities::compareStrings(const char * s1, const char * s2, bool caseSensitive) {
	if(s1 == NULL && s2 == NULL) { return 0; }
	if(s1 == NULL && s2 != NULL) { return -1; }
	if(s1 != NULL && s2 == NULL) { return 1; }

	if(caseSensitive) {
#if _WIN32
		return strcmp(s1, s2);
#else
		return strcmp(s1, s2);
#endif // _WIN32
	}
	else {
#if _WIN32
		return _stricmp(s1, s2);
#else
		return stricmp(s1, s2);
#endif // _WIN32
	}
}

#if USE_QT
int Utilities::compareStrings(const char * s1, const QString & s2, bool caseSensitive) {
	QByteArray bytes = s2.toLocal8Bit();
	return compareStrings(s1, s2.isNull() ? NULL : bytes.data(), caseSensitive);
}
#endif // USE_QT

#if USE_QT
int Utilities::compareStrings(const QString & s1, const char * s2, bool caseSensitive) {
	QByteArray bytes = s1.toLocal8Bit();
	return compareStrings(s1.isNull() ? NULL : bytes.data(), s2, caseSensitive);
}
#endif // USE_QT

int Utilities::compareStringsIgnoreCase(const char * s1, const char * s2) {
	return compareStrings(s1, s2, false);
}

#if USE_QT
int Utilities::compareStringsIgnoreCase(const char * s1, const QString & s2) {
	QByteArray bytes = s2.toLocal8Bit();
	return compareStrings(s1, s2.isNull() ? NULL : bytes.data(), false);
}
#endif // USE_QT

#if USE_QT
int Utilities::compareStringsIgnoreCase(const QString & s1, const char * s2) {
	QByteArray bytes = s1.toLocal8Bit();
	return compareStrings(s1.isNull() ? NULL : bytes.data(), s2, false);
}
#endif // USE_QT
