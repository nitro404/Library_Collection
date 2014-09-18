using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Variable_System {

	public class VariableCollection {

		private List<Variable> m_variables = null;
		private List<string> m_categories = null;

		// create an empty variable system
		public VariableCollection() {
			m_variables = new List<Variable>();
			m_categories = new List<string>();
		}

		public int numberOfCategories() {
			return m_categories.Count();
		}

		public bool hasCategory(string category) {
			if(category == null || m_categories.Count() == 0) { return false; }

			string formattedCategory = category.Trim();

			if(formattedCategory.Length == 0) { return false; }

			for(int i=0;i<m_categories.Count();i++) {
				if(formattedCategory.Equals(m_categories[i], StringComparison.OrdinalIgnoreCase)) {
					return true;
				}
			}

			return false;
		}

		// get the index of a category string within the collection of categories
		public int indexOfCategory(string category) {
			if(category == null || m_categories.Count() == 0) { return -1; }

			string formattedCategory = category.Trim();

			if(formattedCategory.Length == 0) { return -1; }

			for(int i=0;i<m_categories.Count();i++) {
				if(formattedCategory.Equals(m_categories[i], StringComparison.OrdinalIgnoreCase)) {
					return i;
				}
			}

			return -1;
		}

		// get a category from a specific index
		public string getCategory(int index) {
			if(index < 0 || index >= m_categories.Count()) { return null; }

			return m_categories[index];
		}

		// add a category string to the list of categories
		public int addCategory(string category) {
			if(category == null || category.Length == 0) { return Variable.NO_CATEGORY; }

			string formattedCategory = category.Trim();

			if(formattedCategory.Length == 0) { return Variable.NO_CATEGORY; }

			if(!m_categories.Contains(formattedCategory)) {
				m_categories.Add(formattedCategory);
				return m_categories.Count() - 1;
			}
			else {
				return m_categories.IndexOf(formattedCategory);
			}
		}

		// remove all variables in the specified category
		public void removeCategory(string data) {
			if(data == null) { return; }
			string category = data.Trim();

			int categoryIndex = indexOfCategory(category);

			for(int i=0;i<m_variables.Count();i++) {
				if(m_variables[i].category == categoryIndex) {
					m_variables.RemoveAt(i);
					i--;
				}
			}
		}

		// get the number of variables
		public int numberOfVariables() {
			return m_variables.Count();
		}

		// check if a variable is contained in the collection based on its id
		public bool hasVariable(string id) {
			if(id == null || id.Length == 0) { return false; }

			string formattedID = id.Trim();

			if(formattedID.Length == 0) { return false; }

			for(int i=0;i<m_variables.Count();i++) {
				if(formattedID.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					return true;
				}
			}
			return false;
		}

		// check if a variable is contained in the collection based on its id and category
		public bool hasVariable(string id, string category) {
			if(id == null || id.Length == 0) { return false; }

			string formattedID = id.Trim();

			if(formattedID.Length == 0) { return false; }

			int categoryIndex = indexOfCategory(category);

			for(int i=0;i<m_variables.Count();i++) {
				if(m_variables[i].category == categoryIndex &&
				   formattedID.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					return true;
				}
			}
			return false;
		}

		// check if an already existing variable is contained in the collection
		public bool hasVariable(Variable v) {
			if(v == null || v.id.Length == 0) { return false; }

			for(int i=0;i<m_variables.Count();i++) {
				if(v.category == m_variables[i].category &&
				   v.id.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					return true;
				}
			}
			return false;
		}

		// get the index of a variable from the collection based on its id if it exists
		public int indexOfVariable(string id) {
			if(id == null || id.Length == 0) { return -1; }

			string formattedID = id.Trim();

			if(formattedID.Length == 0) { return -1; }

			for(int i=0;i<m_variables.Count();i++) {
				if(formattedID.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					return i;
				}
			}
			return -1;
		}

		// get the index of a variable from the collection based on its id and category if it exists
		public int indexOfVariable(string id, string category) {
			if(id == null || id.Length == 0) { return -1; }

			string formattedID = id.Trim();

			if(formattedID.Length == 0) { return -1; }

			int categoryIndex = indexOfCategory(category);

			for(int i=0;i<m_variables.Count();i++) {
				if(m_variables[i].category == categoryIndex &&
				   formattedID.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					return i;
				}
			}
			return -1;
		}

		// get the index of an already existing variable from the collection
		public int indexOfVariable(Variable v) {
			if(v == null || v.id.Length == 0) { return -1; }

			for(int i=0;i<m_variables.Count();i++) {
				if(v.category == m_variables[i].category &&
				   v.id.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					return i;
				}
			}
			return -1;
		}

		// get a variable based on a specific index
		public Variable getVariable(int index) {
			if(index < 0 || index >= m_variables.Count()) { return null; }

			return m_variables[index];
		}

		// get a variable based on a specific id
		public Variable getVariable(string id) {
			if(id == null || id.Length == 0) { return null; }

			string formattedID = id.Trim();

			if(formattedID.Length == 0) { return null; }

			for(int i=0;i<m_variables.Count();i++) {
				if(formattedID.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					return m_variables[i];
				}
			}
			return null;
		}

		// get a variable based on a specific id and category
		public Variable getVariable(string id, string category) {
			if(id == null || id.Length == 0) { return null; }

			string formattedID = id.Trim();

			if(formattedID.Length == 0) { return null; }

			int categoryIndex = indexOfCategory(category);

			for(int i=0;i<m_variables.Count();i++) {
				if(m_variables[i].category == categoryIndex &&
				   formattedID.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					return m_variables[i];
				}
			}
			return null;
		}

		// get a variable value on a specific id
		public string getValue(string id) {
			if(id == null || id.Length == 0) { return null; }

			string formattedID = id.Trim();

			if(formattedID.Length == 0) { return null; }

			for(int i=0;i<m_variables.Count();i++) {
				if(formattedID.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					return m_variables[i].value;
				}
			}
			return null;
		}

		// get a variable value on a specific id and category
		public string getValue(string id, string category) {
			if(id == null || id.Length == 0) { return null; }

			string formattedID = id.Trim();

			if(formattedID.Length == 0) { return null; }

			int categoryIndex = indexOfCategory(category);

			for(int i=0;i<m_variables.Count();i++) {
				if(m_variables[i].category == categoryIndex &&
				   formattedID.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					return m_variables[i].value;
				}
			}
			return null;
		}

		// get a collection of variables in the specified category
		public List<Variable> getVariablesInCategory(string category) {
			int categoryIndex = indexOfCategory(category);

			List<Variable> variableCollection = new List<Variable>();

			for(int i=0;i<m_variables.Count();i++) {
				if(m_variables[i].category == categoryIndex) {
					variableCollection.Add(m_variables[i]);
				}
			}
			return variableCollection;
		}

		// update the string value of a variable based on its id
		public void setValue(string id, string value) {
			if(id == null || id.Length == 0) { return; }

			string formattedID = id.Trim();

			if(formattedID.Length == 0) { return; }

			bool valueUpdated = false;

			for(int i=0;i<m_variables.Count();i++) {
				if(formattedID.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					m_variables[i].value = value;
					valueUpdated = true;
				}
			}

			// if the variable doesn't exist, add it
			if(!valueUpdated) {
				addVariable(formattedID, value);
			}
		}

		// update the boolean value of a variable based on its id
		public void setValue(string id, bool value) {
			setValue(id, value.ToString().ToLower());
		}

		// update the integer value of a variable based on its id
		public void setValue(string id, int value) {
			setValue(id, value.ToString());
		}

		// update the floating point value of a variable based on its id
		public void setValue(string id, double value) {
			setValue(id, value.ToString());
		}

		// update the string value of a variable based on its id and category
		public void setValue(string id, string value, string category) {
			if(id == null || value == null || category == null) { return; }

			int categoryIndex = indexOfCategory(category);

			for(int i=0;i<m_variables.Count();i++) {
				if(m_variables[i].category == categoryIndex &&
				   id.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					m_variables[i].value = value;
					return;
				}
			}

			// if the variable doesn't exist, add it
			addVariable(id, value, category);
		}

		// update the integer value of a variable based on its id and category
		public void setValue(string id, int value, string category) {
			setValue(id, value.ToString(), category);
		}

		// update the floating point value of a variable based on its id and category
		public void setValue(string id, double value, string category) {
			setValue(id, value.ToString(), category);
		}

		// update the boolean value of a variable based on its id and category
		public void setValue(string id, bool value, string category) {
			setValue(id, value.ToString().ToLower(), category);
		}

		// add a new variable from a specified id and value (create the variable)
		public bool addVariable(string id, string value) {
			if(id == null || id.Length == 0) { return false; }

			string formattedID = id.Trim();

			if(formattedID.Length == 0) { return false; }

			if(!hasVariable(formattedID)) {
				m_variables.Add(new Variable(formattedID, value, Variable.NO_CATEGORY));
				return true;
			}
			return false;
		}

		// add a new variable from a specified id, value and category (create the variable)
		public bool addVariable(string id, string value, string category) {
			if(id == null || id.Length == 0) { return false; }

			string formattedID = id.Trim();

			if(formattedID.Length == 0) { return false; }

			if(!hasVariable(formattedID, category)) {
				int categoryIndex = addCategory(category);
				m_variables.Add(new Variable(formattedID, value, categoryIndex));
				return true;
			}
			return false;
		}

		// add an already existing variable
		public bool addVariable(Variable v) {
			if(v == null || v.id.Length == 0) { return false; }

			if(!hasVariable(v) && v.category < m_categories.Count()) {
				m_variables.Add(v);
				return true;
			}
			return false;
		}

		// remove a specific variable based on its index
		public bool removeVariable(int index) {
			if(index < 0 || index >= m_variables.Count()) { return false; }
			m_variables.RemoveAt(index);
			return true;
		}

		// remove a specific variable based on its id
		public bool removeVariable(string id) {
			if(id == null) { return false; }

			for(int i=0;i<m_variables.Count();i++) {
				if(id.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					m_variables.RemoveAt(i);
					return true;
				}
			}
			return false;
		}

		// remove a specific variable based on its id and category
		public bool removeVariable(string id, string category) {
			if(id == null || category == null) { return false; }

			int categoryIndex = indexOfCategory(category);

			for(int i=0;i<m_variables.Count();i++) {
				if(m_variables[i].category == categoryIndex &&
				   id.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase)) {
					m_variables.RemoveAt(i);
					return true;
				}
			}
			return false;
		}

		// remove an already existing variable
		public bool removeVariable(Variable v) {
			if(v == null) { return false; }

			for(int i=0;i<m_variables.Count();i++) {
				if(v.id.Equals(m_variables[i].id, StringComparison.OrdinalIgnoreCase) &&
				   v.category == m_variables[i].category) {
					m_variables.RemoveAt(i);
					return true;
				}
			}
			return false;
		}

		// clear all variables
		public void clearVariables() {
			m_variables.Clear();
		}

		// group all variables together based on their categories
		public void sortVariables() {
			m_variables = mergeSortVariables(m_variables);
		}

		private List<Variable> mergeSortVariables(List<Variable> variables) {
			if(variables.Count() <= 1) {
				List<Variable> newVariables = new List<Variable>();
				if(variables.Count() > 0) {
					newVariables.Add(variables[0]);
				}

				return newVariables;
			}

			List<Variable> left = new List<Variable>();
			List<Variable> right = new List<Variable>();

			int mid = variables.Count() / 2;

			for(int i=0;i<mid;i++) {
				left.Add(variables[i]);
			}

			for(int i=mid;i<variables.Count();i++) {
				right.Add(variables[i]);
			}

			left = mergeSortVariables(left);
			right = mergeSortVariables(right);

			return mergeVariables(left, right);
		}

		private List<Variable> mergeVariables(List<Variable> left, List<Variable> right) {
			List<Variable> result = new List<Variable>();

			while(left.Count() > 0 && right.Count() > 0) {
				if(left[0].category <= right[0].category) {
					result.Add(left[0]);
					left.RemoveAt(0);
				}
				else {
					result.Add(right[0]);
					right.RemoveAt(0);
				}
			}

			for(int i=0;i<left.Count();i++) {
				result.Add(left[i]);
			}

			for(int i=0;i<right.Count();i++) {
				result.Add(right[i]);
			}

			return result;
		}

		// parse a collection of variables from a file
		public static VariableCollection readFrom(string fileName) {
			if(fileName == null || fileName.Length == 0) { return null; }

			string data;

			// open the file
			StreamReader input = null;
			try {
				input = File.OpenText(fileName);
			}
			catch(Exception) {
				return null;
			}

			VariableCollection variables = new VariableCollection();
			string category = null;
			int categoryIndex = -1;

			// read to the end of the file
			while((data = input.ReadLine()) != null) {
				data = data.Trim();
				if(data.Length == 0) {
					category = null;
					categoryIndex = -1;
					continue;
				}

				// parse a category
				if(data.Length >= 2 && data[0] == '[' && data[data.Length-1] == ']') {
					category = data.Substring(1, data.Length - 2);
					categoryIndex = variables.addCategory(category);
				}
				// parse a variable
				else {
					Variable v = Variable.parseFrom(data);
					if(v != null) {
						v.category = categoryIndex;
						variables.addVariable(v);
					}
				}
			}

			if(input != null) { input.Close(); }

			return variables;
		}

		public bool writeTo(string fileName) {
			int lastCategory = -1;

			bool firstLine = true;

			// open the file
			StreamWriter output = null;
			try {
				output = File.CreateText(fileName);
			}
			catch(Exception) {
				return false;
			}

			// output all of the variables to the file, grouped under corresponding categories
			for(int i=0;i<m_variables.Count();i++) {
				if(lastCategory == -1 || lastCategory != m_variables[i].category) {
					if(m_variables[i].category != -1) {
						if(!firstLine) { output.WriteLine(); }
						output.WriteLine("[" + m_categories[m_variables[i].category] + "]");
						firstLine = false;
					}
					lastCategory = m_variables[i].category;
				}
				m_variables[i].writeTo(output);
				output.WriteLine();
				firstLine = false;
			}

			if(output != null) { output.Close(); }

			return true;
		}

		public override int GetHashCode() {
			return base.GetHashCode();
		}

		public override bool Equals(object o) {
			VariableCollection v = o as VariableCollection;
			if(v == null) { return false; }
			return m_variables.Equals(v.m_variables);
		}

		public override string ToString() {
			string s = "";
			for(int i=0;i<m_variables.Count();i++) {
				s += m_variables[i];
				if(i<m_variables.Count()-1) {
					s += '\n';
				}
			}
			return s;
		}

	}

}
