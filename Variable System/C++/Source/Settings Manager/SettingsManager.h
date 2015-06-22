#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H

#include "Utilities/Utilities.h"
#include "Variable System/VariableCollection.h"

class SettingsManager {
public:
	SettingsManager();
	SettingsManager(const SettingsManager & s);
	SettingsManager & operator = (const SettingsManager & s);
	virtual ~SettingsManager();
	
	void reset();
	
	bool load();
	bool save() const;
	bool loadFrom(const char * fileName);
#if USE_QT
	bool loadFrom(const QString & fileName);
#endif // USE_QT
#if USE_STL
	bool loadFrom(const std::string & fileName);
#endif // USE_STL
	bool saveTo(const char * fileName) const;
#if USE_QT
	bool saveTo(const QString & fileName) const;
#endif // USE_QT
#if USE_STL
	bool saveTo(const std::string & fileName) const;
#endif // USE_STL

public:
	const static char * DEFAULT_SETTINGS_FILENAME;

private:
	VariableCollection * m_variables;
};

#endif // SETTINGS_MANAGER_H
