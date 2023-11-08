#include "pch.h"
#include "CppUnitTest.h"
#include"Computer.h"
#include"Desktop.h"
#include"Device.h"
#include"Keyboard.h"
#include"Laptop.h"
#include"Memory.h"
#include"Monitor.h"
#include"OperatingSystem.h"
#include"Processor.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(ComputerTest1)
	{
	public:
		TEST_METHOD(ComputerTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			Assert::IsFalse(A.GetState());
		}
		TEST_METHOD(TurnOnTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			A.TurnOn();
			Assert::IsTrue(A.GetState());
		}
		TEST_METHOD(TurnOffTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			A.TurnOn();
			A.TurnOff();
			Assert::IsFalse(A.GetState());
		}
		TEST_METHOD(InstallOPTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			A.InstallOP(true);
			Assert::IsTrue(A.GetOP());
		}
		TEST_METHOD(RequestTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Request();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'Y');
		}
		TEST_METHOD(InformationTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Information();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'M');
		}
		TEST_METHOD(MemoryRecordingTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			A.MemoryRecording("123");
			Assert::AreEqual(A.GetMemory()->GetFree(), 253);
		}
		TEST_METHOD(GetKeyboardTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			string a = A.GetKeyboard()->GetDevice();
			char b = a[0];
			Assert::AreEqual(b, 'k');
		}
		TEST_METHOD(GetMonitorTest)
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			string a = A.GetMonitor()->GetDevice();
			char b = a[0];
			Assert::AreEqual(b, 'm');
		}
		TEST_METHOD(GetProcessorTest) 
		{
			Computer A("hp", "1234", "iop134", 4, 100, 55, 256, true, true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.GetProcessor()->Information();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'M');
		}

	};

	TEST_CLASS(KeyboardClass) {
		TEST_METHOD(ConnectionTest1)
		{
			Keyboard A("a", false);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Connection();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'Y');
		}
		TEST_METHOD(ConnectionTest2)
		{
			Keyboard A("a", true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Connection();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'Y');
		}
		TEST_METHOD(DisonnectionTest1)
		{
			Keyboard A("a", true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Disconnection();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'Y');
		}
		TEST_METHOD(InputTest)
		{
			Keyboard A("a", true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			stringstream input;
			input << "123" << endl;
			istringstream redirect(input.str());
			streambuf* oldCinBuf = cin.rdbuf(redirect.rdbuf());
			A.Input();
			cin.rdbuf(oldCinBuf);
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'e');
		}
		TEST_METHOD(OutpurTest) {
			Keyboard A("a", true);
			A.Output("123");
		}
	};

	TEST_CLASS(MonitorClass) {
		TEST_METHOD(ConnectionTest1)
		{
			Monitor A("a", false);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Connection();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'Y');

		}
		TEST_METHOD(ConnectionTest2)
		{
			Monitor A("a", true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Connection();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'Y');
		}
		TEST_METHOD(DisconnectionTest1)
		{
			Monitor A("a", true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Disconnection();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'Y');
		}
		TEST_METHOD(InputTest)
		{
			Monitor A("a", true);
			A.Input();
		}
		TEST_METHOD(OutputTest)
		{
			Monitor A("a", true);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.Output("123");
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 't');
		}
	};

	TEST_CLASS(OPClass) {
		TEST_METHOD(InstallTest)
		{
			OP A;
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			stringstream input;
			input << "w" << endl;
			input << "1" << endl;
			istringstream redirect(input.str());
			streambuf* oldCinBuf = cin.rdbuf(redirect.rdbuf());
			A.Install(false);
			cin.rdbuf(oldCinBuf);
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'N');
		}
		TEST_METHOD(ShowInformationTest)
		{
			OP A;
		
			stringstream input;
			input << "w" << endl;
			input << "1" << endl;
			istringstream redirect(input.str());
			streambuf* oldCinBuf = cin.rdbuf(redirect.rdbuf());
			A.Install(false);
			cin.rdbuf(oldCinBuf);
			stringstream buf;
			streambuf* oldbuf = cout.rdbuf(buf.rdbuf());
			A.ShowInformation();
			cout.rdbuf(oldbuf);
			string output = buf.str();
			char a = output[0];
			Assert::AreEqual(a, 'w');
		}
	};

	TEST_CLASS(ProcesorClass) {
		TEST_METHOD(IncreaseSpeedTest)
		{
			Processor A("A", 1, 3, 4);
			A.IncreaseSpeed(5);
			Assert::AreEqual(A.GetSpeed(), 8);
		}
		TEST_METHOD(ReduceSpeedTest)
		{
			Processor A("A", 1, 6, 4);
			A.ReduceSpeed(5);
			Assert::AreEqual(A.GetSpeed(), 1);
		}
	};
}
