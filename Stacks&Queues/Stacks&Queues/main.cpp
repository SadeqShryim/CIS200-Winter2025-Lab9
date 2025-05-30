#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Func.1 --> Brackets balanced
bool is_balanced(string some_string);

//Func.2 --> Turn to binary
string convert_to_binary(int some_int);

//Func.3 --> Time simulator 
	// Helper function for time delay
int getTimeToStart(int cars);
int timeDelay();


int main() {
	string usrInput;
	int num, cars, trafficTime;
	//Func. 1
	cout << "----- Bracket Checker ------" << endl;
	cout << "What bracket string do you want to check: ";
	cin >> usrInput;

	cout << (is_balanced(usrInput) ? "Balanced!!!" : "Not Balanced...") << endl;
	//Func. 2
	cout << "What number would you like to convert to binary: ";
	cin >> num;

	string binary = convert_to_binary(num);
	cout << binary << endl;
	//Func. 3
	cout << "---- Traffic Simulation ----" << endl;
	cout << "You are in traffic, how many cars are ahead: ";
	cin >> cars;

	trafficTime = getTimeToStart(cars);
	cout << "You will start moving in " << trafficTime << " seconds." << endl;
	return 0;
}

bool is_balanced(string some_string) {
	stack<char> balanced;

	for (char check : some_string) {
		if (check == '(' or check == '[' or check == '{') {
			balanced.push(check);
		}
		else if (check == ')' or check == ']' or check == '}')
		{
			//base case
			if (balanced.empty()) {
				return false;
			}
			char top = balanced.top();

			if ((check == ')' and top != '(') or (check == ']' and top != '[') or (check == '}' and top != '{')) {
				return false; 
			}
			balanced.pop();
		}

		return balanced.empty();
	}
}

string convert_to_binary(int some_int) {
	//base case
	if (some_int == 0) return "0";
	stack <int> into;

	while (some_int > 0) {
		into.push(some_int % 2);
		some_int /= 2;
	}

	string outOf;
	while (!into.empty()) {
		outOf += to_string(into.top());
		into.pop();
	}

	return outOf;
}

int getTimeToStart(int cars) {
	//seed
	srand(time(0));
	queue<int> trafficLine;

	for (int i = 0; i < cars; ++i) {
		trafficLine.push(timeDelay());
	}

	int totalTime = 0;
	while (!trafficLine.empty()) {
		totalTime += trafficLine.front();
		trafficLine.pop();
	}

	return totalTime; 
}

int timeDelay() {
	return rand() % 3 + 1; 
}