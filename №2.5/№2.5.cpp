#include <iostream>
#include <string>
#include <cctype>

// Функція для видалення слів, що починаються на голосну літеру
std::string removeVowelWords(const std::string& str) {
    std::string result;
    std::string word;
    bool isVowelWord = false;

    for (char c : str) {
        if (isspace(c)) {
            if (!isVowelWord) {
                result += word + " ";
            }
            word.clear();
            isVowelWord = false;
        }
        else {
            if (word.empty()) {
                isVowelWord = isalpha(c) && (tolower(c) == 'a' || tolower(c) == 'e' || tolower(c) == 'i' || tolower(c) == 'o' || tolower(c) == 'u');
            }
            word += c;
        }
    }

    if (!isVowelWord) {
        result += word;
    }

    return result;
}

// Функція для перетворення числа з 16-ричної системи числення в десяткову
int hexToDecimal(const std::string& hex) {
    int decimal = 0;
    int base = 1;

    for (int i = hex.length() - 1; i >= 0; i--) {
        if (isdigit(hex[i])) {
            decimal += (hex[i] - '0') * base;
        }
        else {
            decimal += (tolower(hex[i]) - 'a' + 10) * base;
        }
        base *= 16;
    }

    return decimal;
}

// Функція для перетворення числа з двійкової системи числення в десяткову
int binaryToDecimal(const std::string& binary) {
    int decimal = 0;
    int base = 1;

    for (int i = binary.length() - 1; i >= 0; i--) {
        if (binary[i] == '1') {
            decimal += base;
        }
        base *= 2;
    }

    return decimal;
}

// Функція для обчислення значення цілого числа за заданим рядком символів
int convertToDecimal(const std::string& str) {
    if (str.substr(0, 2) == "0x") {
        return hexToDecimal(str.substr(2));
    }
    else if (str.substr(0, 2) == "0b") {
        return binaryToDecimal(str.substr(2));
    }
    else {
        return std::stoi(str);
    }
}

int main() {
    std::string inputString;
    std::cout << "Enter a character string: ";
    std::getline(std::cin, inputString);

    std::string filteredString = removeVowelWords(inputString);
    std::cout << "The line after deleting words that start with a vowel letter: " << filteredString << std::endl;

    std::string numberString;
    std::cout << "Enter a number in decimal, 16-bit, or binary: ";
    std::getline(std::cin, numberString);

    int decimalValue = convertToDecimal(numberString);
    std::cout << "The value of a number in the decimal system: " << decimalValue << std::endl;

    return 0;
}