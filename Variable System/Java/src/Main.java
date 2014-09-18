public class Main {
	
	public static void main(String[] args) {
		SettingsManager settings = new SettingsManager();
		settings.load();
		settings.save();
	}
	
}
