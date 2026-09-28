#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class InputValidator {
public:
    static void validateAge(int age) {
        if (age < 0 || age > 120) {
            throw invalid_argument("Invalid age.");
        }
    }

    static void validateEmail(const string& email) {
        if (email.find('@') == string::npos) {
            throw invalid_argument("Invalid email address.");
        }
    }

    static void validatePassword(const string& password) {
        if (password.length() < 8) {
            throw invalid_argument(
                "Password must contain at least 8 characters."
            );
        }
    }
};

int main() {
    try {
        InputValidator::validateAge(25);
        InputValidator::validateEmail("student@example.com");
        InputValidator::validatePassword("password123");

        cout << "All inputs are valid." << endl;
    }
    catch (const exception& error) {
        cout << "Validation Error: "
             << error.what() << endl;
    }

    return 0;
}
