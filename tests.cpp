#include <iostream>
#include <iomanip> // For std::setw

void centerAlign(const std::string& text, int width) {
    int padding = (width - text.length()) / 2;
    std::cout << std::setw(padding + text.length()) << text << std::endl;
}

int main() {
    int terminalWidth = 40; // Set the width of your terminal/console window
    std::string text = "Center Aligned Text";
    
    centerAlign(text, terminalWidth);
    
    return 0;
}
