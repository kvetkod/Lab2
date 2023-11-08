#include<iostream>
#include"Computer.h"
#include"Device.h"
#include"Keyboard.h"
#include"Laptop.h"
#include"Desktop.h"
#include"OperatingSystem.h"
#include"Processor.h"
#include"Memory.h"
using namespace std;


int main() {
	setlocale(LC_ALL, "rus");
	Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
	//A.turn_on();
	//A.getKeyboard()->connection();
	//A.Information();
	//A.installop(false);
	//A.MemoryRecording("2134");
	//A.Information();
	////A.request();
	//A.getProcessor()->IncreaseSpeed(10);
	//A.Information();

	Desktop B("hp", "1234", "iop134", 4, 100, 55, 256, false, false);
	B.Information();
	B.GetKeyboard()->Input();

	//Laptop C("hp", "1234", "iop134", 4, 100, 55, 256, true, true);

	//Keyboard a("keyboard");//куда их подключать, к чему
	//a.connection();
	//a.click();
	//a.disconnection();
	//a.click();
	//Laptop z("hp", "123");
	//z.turn_on();
	//z.statement();
	//z.turn_off();
	//z.statement();
}