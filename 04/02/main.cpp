#include "Data.h"

int main(int argc, char* argv[]) {
    std::ofstream file("file.txt");
    Printable* dataAsJSON = new DataAsJSON("data", Format::kJSON);
    SaveToAsHTML saveToHTML;
    saveToHTML.save(file, dataAsJSON);
}