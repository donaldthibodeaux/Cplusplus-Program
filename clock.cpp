/*
 * clock.cpp
 *
 *  Created on: Jan 22, 2021
 *      Author: 1676039_snhu
 *      Donald Thibodeaux
 */

#include <ctime>
#include <iostream>
#include <stdlib.h>

using namespace std;
class Time_24;
class Time {
public:
	int hour;
	int minute;
	int second;

	void addHour();
	void addMinute();
	void addSecond();
};

class Time_12: public Time {
public:
	Time_12(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
	void addHour() {
		hour == 11 ? hour = 0 : hour += 1;
	}
	void addMinute() {
		if (minute == 59) {

			minute = 0;

			addHour();
		} else {

			minute += 1;
		}
	}
	void addSecond() {
		if (second == 59) {

			second = 0;

			addMinute();
		} else {

			second += 1;
		}
	}
};

class Time_24: public Time {
public:
	Time_24(int h, int m, int s) {
		hour = h;
		minute = m;
		second = s;
	}
	void addHour() {
		hour == 23 ? hour = 0 : hour += 1;
	}
	void addMinute() {
		if (minute == 59) {

			minute = 0;

			addHour();
		} else {

			minute += 1;
		}
	}
	void addSecond() {
		if (second == 59) {

			second = 0;

			addMinute();
		} else {

			second += 1;
		}
	}
};

void displayTime(const Time_12 &t12, const Time_24 &t24)

{

	cout << "******************* **********************\n";

	cout << "* \t12-Hour Clock \t*\t * \t24-Hour Clock\t *\n";
	cout << "*\t ";
	cout << (t12.hour < 10 ? "0" : "") << t12.hour << ":"
			<< (t12.minute < 10 ? "0" : "") << t12.minute << ":"
			<< (t12.second < 10 ? "0" : "") << t12.second
			<< (t24.hour < 12 ? " AM" : " PM");

	cout << "\t*\t *\t ";

	cout << (t24.hour < 10 ? "0" : "") << t24.hour << ":"
			<< (t24.minute < 10 ? "0" : "") << t24.minute << ":"
			<< (t24.second < 10 ? "0" : "") << t24.second
			<< (t24.hour < 12 ? " AM" : " PM");

	cout << " \t\t*\n";

	cout << "******************* **********************\n";
}

int main()

{

	Time_12 _12_Clock(11, 59, 59);

	Time_24 _24_Clock(23, 59, 59);

	displayTime(_12_Clock, _24_Clock);

	char c;
	cout << "Press any button[y/n]";
	cin >> c;
	if (c == 'n') {
		system("cls");
		_12_Clock.addMinute();

		_24_Clock.addMinute();

		displayTime(_12_Clock, _24_Clock);
	} else {

		while (true)

		{

			cout << "***************************\n";

			cout << "* 1 - Add One Hour \t\t*\n";

			cout << "* 2 - Add One Minute  \t*\n";

			cout << "* 3 - Add One Second  \t*\n";

			cout << "* 4 - End Program \t\t*\n";

			cout << "***************************\n";

			int choice;
			cout << "user Input";
			cin >> choice;
			system("cls");
			switch (choice)

			{

			case 1:

				_12_Clock.addHour();

				_24_Clock.addHour();

				displayTime(_12_Clock, _24_Clock);

				break;

			case 2:

				_12_Clock.addMinute();

				_24_Clock.addMinute();

				displayTime(_12_Clock, _24_Clock);

				break;

			case 3:

				_12_Clock.addSecond();

				_24_Clock.addSecond();

				displayTime(_12_Clock, _24_Clock);

				break;

			case 4:

				cout << "Program End";

				exit(1);

				break;

			default:
				cout << "Invalid choice !\n ";

				break;
			}
		}
	}
}

