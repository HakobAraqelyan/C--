#include <iostream>
#include <string>
#include <iomanip>

void analyzeBarcode(const std::string& barcode) {
    std::cout << "\nՎերլուծություն:\n";
    std::cout << "Տեքստային տեսք: " << barcode << "\n";
    std::cout << "Սիմվոլների քանակ: " << barcode.length() << "\n\n";
    
    std::cout << "ASCII  Hex  Dec  Char\n";
    std::cout << "----------------------\n";
    
    for (char c : barcode) {
        // Ցույց տալ յուրաքանչյուր սիմվոլի մասին տեղեկություն
        std::cout << std::setw(5) << std::left << static_cast<int>(c);
        std::cout << std::setw(5) << std::hex << std::uppercase << static_cast<int>(c);
        std::cout << std::setw(5) << std::dec << static_cast<int>(c);
        
        if (isprint(c)) {
            std::cout << "  '" << c << "'";
        } else {
            std::cout << "  (չտեսանելի)";
        }
        std::cout << "\n";
    }
}

int main() {
    std::string barcode;
    
    std::cout << "=============================\n";
    std::cout << "Բարկոդի անալիզատոր\n";
    std::cout << "=============================\n";
    std::cout << "Մուտքագրեք բարկոդը (կամ Ctrl+D/Ctrl+Z ավարտելու համար):\n";
    
    while (std::getline(std::cin, barcode)) {
        if (!barcode.empty()) {
            analyzeBarcode(barcode);
        }
        std::cout << "\nՄուտքագրեք հաջորդ բարկոդը:\n";
    }
    
    std::cout << "\nԾրագիրը ավարտված է։\n";
    return 0;
}