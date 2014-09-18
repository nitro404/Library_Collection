#ifndef VARIABLE_COLLECTION_H
#define VARIABLE_COLLECTION_H

#include "Utilities/Utilities.h"
#if USE_QT
#include <QString.h>
#include <QVector.h>
#include <QFile.h>
#include <QTextStream.h>
#else
#include <string.h>
#include <vector>
#include <fstream>
#endif // USE_QT
#include "Variable System/Variable.h"

class VariableCollection {
public:
	VariableCollection();
	VariableCollection(const VariableCollection & v);
	VariableCollection & operator = (const VariableCollection & v);
	~VariableCollection();
	
	int addCategory(const char * category);
#if USE_QT
	int addCategory(const QString & category);
#else
	int addCategory(const std::string & category);
#endif // USE_QT
	int indexOfCategory(const char * category) const;
#if USE_QT
	int indexOfCategory(const QString & category) const;
#else
	int indexOfCategory(const std::string & category) const;
#endif // USE_QT
	char * categoryAt(int index) const;
	int size() const;
	bool contains(const char * id) const;
#if USE_QT
	bool contains(const QString & id) const;
#else
	bool contains(const std::string & id) const;
#endif // USE_QT
	bool contains(const char * id, const char * category) const;
#if USE_QT
	bool contains(const QString & id, const QString & category) const;
#else
	bool contains(const std::string & id, const std::string & category) const;
#endif // USE_QT
	bool contains(const Variable * v) const;
	int indexOf(const char * id) const;
#if USE_QT
	int indexOf(const QString & id) const;
#else
	int indexOf(const std::string & id) const;
#endif // USE_QT
	int indexOf(const char * id, const char * category) const;
#if USE_QT
	int indexOf(const QString & id, const QString & category) const;
#else
	int indexOf(const std::string & id, const std::string & category) const;
#endif // USE_QT
	int indexOf(const Variable * v) const;
	const Variable * variableAt(int index) const;
	const Variable * getVariable(const char * id) const;
#if USE_QT
	const Variable * getVariable(const QString & id) const;
#else
	const Variable * getVariable(const std::string & id) const;
#endif // USE_QT
	const Variable * getVariable(const char * id, const char * category) const;
#if USE_QT
	const Variable * getVariable(const QString & id, const QString & category) const;
#else
	const Variable * getVariable(const std::string & id, const std::string & category) const;
#endif // USE_QT
	const char * getValue(const char * id) const;
#if USE_QT
	const char * getValue(const QString & id) const;
#else
	const char * getValue(const std::string & id) const;
#endif // USE_QT
	const char * getValue(const char * id, const char * category) const;
#if USE_QT
	const char * getValue(const QString & id, const QString & category) const;
#else
	const char * getValue(const std::string & id, const std::string & category) const;
#endif // USE_QT
#if USE_QT
	QVector<Variable *> * getVariablesInCategory(const char * category) const;
	QVector<Variable *> * getVariablesInCategory(const QString & category) const;
#else
	std::vector<Variable *> * getVariablesInCategory(const char * category) const;
	std::vector<Variable *> * getVariablesInCategory(const std::string & category) const;
#endif // USE_QT
	bool add(const char * id, const char * value = NULL, const char * category = NULL);
#if USE_QT
	bool add(const QString & id, const QString & value = QString(), const QString & category = QString());
#else
	bool add(const std::string & id, const std::string & value = std::string(), const std::string & category = std::string());
#endif // USE_QT
	bool add(Variable * v);
	bool addCopy(const Variable * v);
	void setValue(const char * id, const char * value);
	void setValue(const char * id, int value);
	void setValue(const char * id, double value);
	void setValue(const char * id, bool value);
#if USE_QT
	void setValue(const QString & id, const char * value);
	void setValue(const QString & id, const QString & value);
	void setValue(const QString & id, int value);
	void setValue(const QString & id, double value);
	void setValue(const QString & id, bool value);
#else
	void setValue(const std::string & id, const char * value);
	void setValue(const std::string & id, const std::string & value);
	void setValue(const std::string & id, int value);
	void setValue(const std::string & id, double value);
	void setValue(const std::string & id, bool value);
#endif // USE_QT
	void setValue(const char * id, const char * value, const char * category);
	void setValue(const char * id, int value, const char * category);
	void setValue(const char * id, double value, const char * category);
	void setValue(const char * id, bool value, const char * category);
#if USE_QT
	void setValue(const QString & id, const char * value, const QString & category);
	void setValue(const QString & id, const QString & value, const QString & category);
	void setValue(const QString & id, int value, const QString & category);
	void setValue(const QString & id, double value, const QString & category);
	void setValue(const QString & id, bool value, const QString & category);
#else
	void setValue(const std::string & id, const char * value, const std::string & category);
	void setValue(const std::string & id, const std::string & value, const std::string & category);
	void setValue(const std::string & id, int value, const std::string & category);
	void setValue(const std::string & id, double value, const std::string & category);
	void setValue(const std::string & id, bool value, const std::string & category);
#endif // USE_QT
	bool remove(int index);
	bool remove(const char * id);
#if USE_QT
	bool remove(const QString & id);
#else
	bool remove(const std::string & id);
#endif // USE_QT
	bool remove(const char * id, const char * category);
#if USE_QT
	bool remove(const QString & id, const QString & category);
#else
	bool remove(const std::string & id, const std::string & category);
#endif // USE_QT
	bool remove(const Variable * v);
	bool removeCategory(const char * data);
#if USE_QT
	bool removeCategory(const QString & data);
#else
	bool removeCategory(const std::string & data);
#endif // USE_QT
	void clear();
	void sort();

	static VariableCollection * readFrom(const char * fileName);
#if USE_QT
	static VariableCollection * readFrom(const QString & fileName);
#else
	static VariableCollection * readFrom(const std::string & fileName);
#endif // USE_QT
	bool writeTo(const char * fileName) const;
#if USE_QT
	bool writeTo(const QString & fileName) const;
#else
	bool writeTo(const std::string & fileName) const;
#endif // USE_QT

	bool operator == (const VariableCollection & v) const;
	bool operator != (const VariableCollection & v) const;

private:
#if USE_QT
	QVector<Variable *> m_variables;
	QVector<char *> m_categories;
#else
	std::vector<Variable *> m_variables;
	std::vector<char *> m_categories;
#endif // USE_QT
};

#endif // VARIABLE_COLLECTION_H
