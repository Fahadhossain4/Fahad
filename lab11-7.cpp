#include <iostream>

using namespace std;

class Device {
protected:
	string name;

public:
	Device() { }
	virtual ~Device() { }

	void turnOn() {
		cout << "\e[0;33mDevice " << name << "\e[0m turned on!" << endl;
	}
	void turnOff() {
		cout << "\e[0;33mDevice " << name << "\e[0m turned off!" << endl;
	}

	virtual void operate() = 0;
};

class SmartPhone : public Device {
public:
	SmartPhone(string name) {
		this->name = name;
		cout << "\e[0;33mSmartphone " << name << "\e[0m created!" << endl;	
	}
	~SmartPhone() {
		cout << "\e[0;33mSmartphone " << name << "\e[0m destroyed!" << endl;
	}

	void operate() override {
		cout << "\e[0;33mSmartphone " << name << "\e[0m: Loading linux initramfs...." << endl;
	}
};

class SmartTV : public Device {
public:
	SmartTV(string name) {
		this->name = name;
		cout << "\e[0;33mSmartTV " << name << "\e[0m created!" << endl;
	}
	~SmartTV() {
		cout << "\e[0;33mSmartTV " << name << "\e[0m destroyed!" << endl;
	}

	void operate() override {
		cout << "\e[0;33mSmartTV " << name << "\e[0m: Starting...." << endl;
	}
};

class SmartFridge : public Device {
public:
	SmartFridge(string name) {
		this->name = name;
		cout << "\e[0;33mSmart Fridge " << name << "\e[0m created!" << endl;
	}
	~SmartFridge() {
		cout << "\e[0;33mSmart Fridge " << name << "\e[0m destroyed!" << endl;
	}

	void operate() override {
		cout << "\e[0;33mSmart Fridge " << name << "\e[0m: Beep Beep" << endl;
	}
};

int main() {
	cout << "\e[0;32mCreating devices: \e[0m" << endl;
	Device* devices[] = {
		new SmartTV("Walton"),
		new SmartPhone("Nokia"),
		new SmartPhone("CMF"),
		new SmartFridge("Samsung"),
		new SmartTV("Panasonic")
	};

	cout << endl;
	for (int i=0; i<5; i++) {
		devices[i]->turnOn();
		devices[i]->operate();
		devices[i]->turnOff();

		cout << endl;
	}

	cout << "\e[0;31mDestroying devices: \e[0m" << endl;
	for (int i=0; i<5; i++)
		delete devices[i];

	return 0;
}