#include "Settings Manager/SettingsManager.h"
#include <fstream>

#if _DEBUG
#include <vld.h>
#endif // _DEBUG

int main(int argc, const char * argv[]) {
	SettingsManager * settings = new SettingsManager();
	settings->load();
	settings->save();

	delete settings;

	system("pause");
	
	return 0;
}
