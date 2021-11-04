#include <iostream>
#include <string>
#include <sstream>
#include <random>
#include <vector>

using namespace std;

int main() {
  /**** Create array ****/
  const int MAX_NUMBERS_AMOUNT = 20;
  vector<int> numbers;

  /*** Decide how to populate array - via typing numbers in or randomly ***/
  int decisionNumber;

  cout << "Choose how to populate the array - via typing numbers in or randomly. Type in 0 or 1 respectively to choose the method." << endl;
  cin >> decisionNumber;
  if (!cin.good() || (decisionNumber != 0 && decisionNumber != 1)) {
    cout << "Error: got incorrect decision number value. The value must be '0' or '1'. Exiting the program...";
    return 1;
  }
  cin.ignore(); // Allow 'getline()' to work. See https://stackoverflow.com/a/33316611

  /** Create array via typing numbers in **/
  if (decisionNumber == 0) {
    cout << "Enter numbers in format 'number number number', e.g. '321 -142 6 -3': ";

    string numbersString;
    getline(cin, numbersString);

    stringstream StringStream(numbersString);
    string number;

    for (int i = 0; StringStream >> number; i++) {
      if (i == MAX_NUMBERS_AMOUNT) {
        cout << "Error: exceeded maximum numbers amount. Exiting the program...";
        return 1;
      }

      numbers.push_back(stoi(number));
    }
  }
  /** Create array with random numbers **/
  if (decisionNumber == 1) {
    random_device randomDevice;
    mt19937 rng(randomDevice());
    uniform_real_distribution<> generateRandomInteger(-100, 100);

    for (int i = 0; i < MAX_NUMBERS_AMOUNT; i++) {
      numbers.push_back(generateRandomInteger(rng));
    }
  }
  
  cout << "Before deleting positive numbers: ";
  for (auto number : numbers) {
    cout << number << " ";
  }
  cout << endl;

  /**** Delete positive numbers ****/
  int numbersLength = numbers.size();
  for (int i = 0; i < numbers.size(); i++) {
    int number = numbers[i];
    
    if (number > 0) {
      numbers.erase(numbers.begin() + i);
      i--;
    }
  }

  cout << "After deleting positive numbers: ";
  for (auto number : numbers) {
    cout << number << " ";
  }

  return 0;
}
