#include "Settings Manager/SettingsManager.h"

const char * SettingsManager::DEFAULT_SETTINGS_FILENAME = "settings.ini";

SettingsManager::SettingsManager()
	: m_variables(new VariableCollection()) {
	reset();
}

SettingsManager::SettingsManager(const SettingsManager & s)
	: m_variables(new VariableCollection(*s.m_variables)) {

}

SettingsManager & SettingsManager::operator = (const SettingsManager & s) {
	delete m_variables;

	m_variables = new VariableCollection(*s.m_variables);

	return *this;
}

SettingsManager::~SettingsManager() {
	delete m_variables;
}

void SettingsManager::reset() {
	
}

bool SettingsManager::load() {
	return loadFrom(DEFAULT_SETTINGS_FILENAME);
}

bool SettingsManager::save() const {
	return saveTo(DEFAULT_SETTINGS_FILENAME);
}

bool SettingsManager::loadFrom(const char * fileName) {
	VariableCollection * newVariables = VariableCollection::readFrom(fileName);
	if(newVariables == NULL) { return false; }

	delete m_variables;
	m_variables = newVariables;

	// create local variables instantiated with data parsed from the variable system


	return true;
}

#if USE_QT
bool SettingsManager::loadFrom(const QString & fileName) {
	QByteArray fileNameBytes = fileName.toLocal8Bit();

	return loadFrom(fileNameBytes.data());
}
#endif // USE_QT

#if USE_STL
bool SettingsManager::loadFrom(const std::string & fileName) {
	return loadFrom(fileName.data());
}
#endif // USE_STL

bool SettingsManager::saveTo(const char * fileName) const {
	// update the variable system with the new game settings values


	// group the variables by categories
	m_variables->sortVariables();

	// update the settings file with the changes
	return m_variables->writeTo(fileName);
}

#if USE_QT
bool SettingsManager::saveTo(const QString & fileName) const {
	QByteArray fileNameBytes = fileName.toLocal8Bit();

	return saveTo(fileNameBytes.data());
}
#endif // USE_QT

#if USE_STL
bool SettingsManager::saveTo(const std::string & fileName) const {
	return saveTo(fileName.data());
}
#endif // USE_STL
