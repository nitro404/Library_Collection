#ifndef SETTINGS_MANAGER_H
#define SETTINGS_MANAGER_H

#include "Utilities/Utilities.h"
#include "Variable System/VariableCollection.h"

class SettingsManager {
public:
	SettingsManager();
	SettingsManager(const SettingsManager & s);
	SettingsManager & operator = (const SettingsManager & s);
	~SettingsManager();
	
	void reset();
	
	bool load();
	bool save() const;
	bool loadFrom(const char * fileName);
#if USE_QT
	bool loadFrom(const QString & fileName);
#else
	bool loadFrom(const std::string & fileName);
#endif
	bool saveTo(const char * fileName) const;
#if USE_QT
	bool saveTo(const QString & fileName) const;
#else
	bool saveTo(const std::string & fileName) const;
#endif

public:
	const static char * DEFAULT_SETTINGS_FILENAME;

private:
	VariableCollection * m_variables;
};

#endif // SETTINGS_MANAGER_H
