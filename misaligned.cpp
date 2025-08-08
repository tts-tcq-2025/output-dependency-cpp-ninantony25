#include <iostream>
#include <vector>
#include <string>
#include <cassert>
 
std::vector<std::string> getColorMap() {
    const std::vector<std::string> major = {"White", "Red", "Black", "Yellow", "Violet"};
    const std::vector<std::string> minor = {"Blue", "Orange", "Green", "Brown", "Slate"};
    std::vector<std::string> colorMap;
    colorMap.reserve(25);
 
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            colorMap.push_back(
                std::to_string(i * 5 + j) + " | " + major[i] + " | " + minor[i]  // BUG: minor[i] should be minor[j]
            );
        }
    }
    return colorMap;
}
 
int printColorMap() {
    const auto& colorMap = getColorMap();
    for (const auto& entry : colorMap) {
        std::cout << entry << "\n";
    }
    return static_cast<int>(colorMap.size());
}
 
void testPrintColorMap() {
    std::cout << "\nPrint color map test\n";
    auto colorMap = getColorMap();
 
    assert(colorMap.size() == 25);
    assert(colorMap[0] == "0 | White | Blue");      // Will fail
    assert(colorMap[6] == "6 | Red | Green");       // Will fail
    assert(colorMap[24] == "24 | Violet | Slate");  // Will fail
 
    std::cout << "All is well (maybe!)\n";
}
 
int main() {
    testPrintColorMap();
    return 0;
}
