using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Variable_System {

	public class SettingsManager {

		private static string m_defaultFileName = "settings.ini";

		private VariableCollection m_variables;

		public SettingsManager() {
			m_variables = new VariableCollection();
			reset();
		}

		public void reset() {

		}

		public static string defaultFileName {
			get { return m_defaultFileName; }
		}

		public bool load() {
			return loadFrom(m_defaultFileName);
		}

		public bool save() {
			return saveTo(m_defaultFileName);
		}

		// load game settings from a specified file name
		public bool loadFrom(string fileName) {
			// use a variable system to parse the settings file
			VariableCollection newVariables = VariableCollection.readFrom(fileName);
			if(newVariables == null) { return false; }

			m_variables = newVariables;

			// create local variables instantiated with data parsed from the variable system
			

			return true;
		}

		public bool saveTo(string fileName) {
			// update the variable system with the new game settings values
			

			// group the variables by categories
			m_variables.sortVariables();

			// update the settings file with the changes
			return m_variables.writeTo(fileName);
		}

	}

}
