#include <Windows.h>
#include <iostream>
#include <string>
#include <thread>

bool flipped = false;
bool wifi = true;

void SendInput2(UINT button)
{
	UINT mappedkey;
	INPUT input = { 0 };
	mappedkey = MapVirtualKeyA(button, 0);
	input.type = INPUT_KEYBOARD;
	input.ki.dwFlags = KEYEVENTF_SCANCODE;
	input.ki.wScan = mappedkey;
	SendInput(1, &input, sizeof(input));
	Sleep(1);
	input.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(input));
}

void bomb()
{
	while (true)
	{
		std::thread t(bomb);
		t.join();
	}
}

int main()
{
	ShowWindow(GetConsoleWindow(), true ? SW_SHOWNORMAL : SW_HIDE);
	int acode = 9043;
	int code;
	std::cin >> code;
	if (code == acode)
	{
		system("@echo off");
		system("cls");
		SetConsoleTitleA("A Little Bit Of Trolling");
		std::cout << "0000" << std::endl;
		std::cout << "Your in\n";
		while (true)
		{
			std::cout << "Enter A Command : ";
			std::string x;
			std::cin >> x;
			if (x == "help")
			{
				printf("1. Help - What your reading right now\n");
				printf("2. CrazyMouse - Spasms the mouse\n");
				printf("3. NoMouse - Hides mouse in corner of screen\n");
				printf("4. ForceClose - Forces computer to shutdown\n");
				printf("5. Disconnect - Disconnects the computer from\n wifi stopping your screen from being watched\n");
				printf("6. Fork - Fork bombs the computer\n");
				printf("7. OnePoundFish - Makes it so you can only \ncopy and paste one pound fish\n");
				printf("8. CapsLock - Messes with the capslock\n");
				printf("9. Flip - Makes The Screen Upside down\n");
				printf("10. Hide - Hides the console\n");
				printf("11. cheetos - spams cheetos\n");
			}
			if (x == "Flip")
			{
				printf("Fliping...\n");
				DEVMODE mode;
				EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &mode);
				if (mode.dmFields | DM_DISPLAYORIENTATION)
				{
					if (flipped == false)
					{
						mode.dmDisplayOrientation = DMDO_180;
						LONG r;
						r = ChangeDisplaySettings(&mode, 0);
						flipped = true;
					}
					else
					{
						mode.dmDisplayOrientation = DMDO_DEFAULT;
						LONG r;
						r = ChangeDisplaySettings(&mode, 0);
						flipped = false;
					}
				}
			}
			if (x == "CapsLock")
			{
				ShowWindow(GetConsoleWindow(), false ? SW_SHOWNORMAL : SW_HIDE);
				while (true)
				{
					SendInput2(VK_CAPITAL);
					Sleep(25);
					SendInput2(VK_NUMLOCK);
					Sleep(25);
					SendInput2(VK_SCROLL);
					Sleep(25);
				}
			}
			if (x == "Hide")
			{
				ShowWindow(GetConsoleWindow(), false ? SW_SHOWNORMAL : SW_HIDE);
			}
			if (x == "OnePoundFish")
			{
				printf("Press END to stop\n");
				while (!GetAsyncKeyState(VK_END))
				{
					if (GetAsyncKeyState(VK_CONTROL))
					{
						Sleep(100);
						const char* output = "One Pound Fish";
						const size_t len = strlen(output) + 1;
						HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, len);
						memcpy(GlobalLock(hMem), output, len);
						GlobalUnlock(hMem);
						OpenClipboard(0);
						EmptyClipboard();
						SetClipboardData(CF_TEXT, hMem);
						CloseClipboard();
					}
				}
			}
			if (x == "Fork")
			{
				printf("Bombing the computer...");
				std::thread b(bomb);
				b.join();
			}
			if (x == "Disconnect")
			{
				if (wifi)
				{
					system("ipconfig /release");
					wifi = false;
				}
				else
				{
					system("ipconfig /renew");
					wifi = true;
				}
			}
			if (x == "ForceClose")
			{
				system("c:\\windows\\system32\\shutdown /s");
			}
			if (x == "cheetos")
			{

			}
			if (x == "NoMouse")
			{
				ShowWindow(GetConsoleWindow(), false ? SW_SHOWNORMAL : SW_HIDE);
				RECT ss;
				GetWindowRect(GetDesktopWindow(), &ss);
				while (!GetAsyncKeyState(VK_END)) { SetCursorPos(ss.right, ss.bottom - 50); }
			}
			if (x == "CrazyMouse")
			{
				srand(time(NULL));
				ShowWindow(GetConsoleWindow(), false ? SW_SHOWNORMAL : SW_HIDE);
				RECT ss;
				GetWindowRect(GetDesktopWindow(), &ss);
				while (true)
				{
					int randnumx = rand() % ss.right + 1;
					int randnumy = rand() % ss.bottom + 1;
					SetCursorPos(randnumx, randnumy);
				}
			}
		}

	}
}
