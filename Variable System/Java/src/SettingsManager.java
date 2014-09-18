public class SettingsManager {
	
	private VariableSystem m_settings;
	
	final public static String defaultSettingsFileName = "settings.ini";
	
	public SettingsManager() {
		m_settings = new VariableSystem();
		reset();
	}
	
	public void reset() {
		
	}
	
	public boolean load() { return loadFrom(defaultSettingsFileName); }
	
	public boolean save() { return saveTo(defaultSettingsFileName); }
	
	public boolean loadFrom(String fileName) {
		VariableSystem variables = VariableSystem.readFrom(fileName);
		if(variables == null) {
			System.out.println("ERROR: Unable to load settings file: \"" + fileName + "\".");
			return false;
		}
		
		m_settings = variables;
		
		// create local variables instantiated with data parsed from the variable system
		// TODO
		
		return true;
	}
	
	public boolean saveTo(String fileName) {
		// update the variable system with the new settings values
		// TODO
		
		// group the settings by categories
		m_settings.sort();
		
		return m_settings.writeTo(fileName);
	}
	
}
