using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Variable_System {

	public class Program {

		static void Main(string[] args) {
			SettingsManager settings = new SettingsManager();
			settings.load();
			settings.save();
		}

	}

}
