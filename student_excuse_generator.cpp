#include <iostream>
#include <cstdlib>  // for rand() and srand()
#include <ctime>    // for time()
using namespace std;

int main() {
    string name;

    // Take input from user
    cout << "Enter your name: ";
    getline(cin, name);

    // Handle empty input
    if (name.length() == 0) {
        cout << "Please enter a valid name!" << endl;
        return 0;
    }

    // Array of excuse templates (10 excuses)
    string excuses[] = {
        "{name} couldn't complete the assignment because the laptop battery died unexpectedly.",
        "{name} was about to finish the homework when the Wi-Fi suddenly stopped working.",
        "{name} tried completing the assignment, but the keyboard stopped responding.",
        "{name} had finished the work, but the file mysteriously disappeared.",
        "{name}'s computer decided to update for hours right before submission.",
        "{name} was almost done when the power went out.",
        "{name} got stuck because the software refused to open the file.",
        "{name} accidentally saved the file in the wrong format and couldnt recover it.",
        "{name} was working hard, but the system suddenly crashed.",
        "{name} tried finishing the homework, but the internet kept disconnecting."
    };

    int total = 10;

    // Initialize random seed (important for different output every run)
    srand(time(0));

    // Generate random index
    int index = rand() % total;

    string selected = excuses[index];
    string result = "";

    // Replace {name} with actual name
    for (int i = 0; i < selected.length(); i++) {
        if (selected.substr(i, 6) == "{name}") {
            result += name;
            i += 5; // skip "{name}"
        } else {
            result += selected[i];
        }
    }

    // Output
    cout << "\n Your Excuse:\n";
    cout << result << endl;

    return 0;
}