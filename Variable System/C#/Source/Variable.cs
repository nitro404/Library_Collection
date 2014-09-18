using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace Variable_System {

	public class Variable {

		public const int NO_CATEGORY = -1;
		private static char[] SEPARATORS = { ':', '=' };
		
		private string m_id = "";
		private string m_value = "";
		private int m_category = NO_CATEGORY; // refers to the index in the list of string categories in its parent variable system

		// default constructor
		public Variable()
			: this(null, null, NO_CATEGORY) {
			
		}

		// create a variable with no category
		public Variable(string id, string value)
			: this(id, value, NO_CATEGORY) {
			
		}

		// create a variable with a specific category
		public Variable(string id, string value, int category) {
			m_category = (category < 0) ? NO_CATEGORY : category;
			this.id = id;
			this.value = value;
		}

		public string id {
			get { return m_id; }
			set { m_id = (value == null) ? "" : value.Trim(); }
		}

		public string value {
			get { return m_value; }
			set { m_value = (value == null) ? "" : value.Trim(); }
		}

		public int category {
			get { return m_category; }
			set { m_category = (value < 0) ? NO_CATEGORY : value; }
		}

		public void setValue(String value) {
			m_value = (value == null) ? "" : value.Trim();
		}

		public void setValue(bool value) {
			m_value = value.ToString().ToLower();
		}

		public void setValue(int value) {
			m_value = value.ToString();
		}

		public void setValue(double value) {
			m_value = value.ToString();
		}

		public void removeCategory() {
			m_category = NO_CATEGORY;
		}

		// parse a variable from a string
		public static Variable parseFrom(string data) {
			if(data == null || data.Length == 0) { return null; }

			string formattedData = data.Trim();

			if(formattedData.Length == 0) { return null; }

			int separatorIndex = -1;
			for(int i=0;i<formattedData.Length;i++) {
				for(int j=0;j<SEPARATORS.Length;j++) {
					if(formattedData[i] == SEPARATORS[j]) {
						separatorIndex = i;
						break;
					}
				}
				if(separatorIndex != -1) {
					break;
				}
			}

			if(separatorIndex == -1) { return null; }

			string id = formattedData.Substring(0, separatorIndex);
			string value = formattedData.Substring(separatorIndex + 1, formattedData.Length - separatorIndex - 1);

			return new Variable(id, value, NO_CATEGORY);
		}

		// print a variable to an output stream
		public bool writeTo(StreamWriter output) {
			return writeTo(output, SEPARATORS[0]);
		}

		// print a variable to an output stream
		public bool writeTo(StreamWriter output, char separator) {
			if(output == null || separator == '\0') { return false; }

			output.Write(m_id);
			output.Write(separator);
			if(separator == ':') { output.Write(' '); }
			output.Write(m_value);

			return true;
		}

		public override int GetHashCode() {
			return base.GetHashCode();
		}

		public override bool Equals(object o) {
			Variable v = o as Variable;
			if(v == null) { return false; }
			return m_category == v.m_category &&
				   m_id.Equals(v.m_id, StringComparison.OrdinalIgnoreCase);
		}

		public override string ToString() {
			return m_id + SEPARATORS[0] + " " + m_value;
		}

	}

}
