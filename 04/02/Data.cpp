#include "Data.h"

std::string DataAsHTML::print() const
{
    if (format_ != Format::kHTML) {
        throw std::runtime_error("Invalid format!");
    }
    std::string resultString = "<html>" + data_ + "<html/>";
    return resultString;
}

std::string DataAsText::print() const
{
    if (format_ != Format::kText) {
        throw std::runtime_error("Invalid format!");
    }
    std::string resultString = data_;

    return resultString;
}

std::string DataAsJSON::print() const
{
    if (format_ != Format::kJSON) {
        throw std::runtime_error("Invalid format!");
    }
    std::string resultString = "{ \"data\": \"" + data_ + "\"}";

    return resultString;
}

void SaveToAsHTML::save(std::ofstream& file, const Printable* printable) const
{
    saveToAsHTML(file, printable);
}

void SaveToAsHTML::saveToAsHTML(std::ofstream& file, const Printable* printable) const
{
    file << printable->print();
}

void SaveToAsJSON::save(std::ofstream& file, const Printable* printable) const
{
    saveToAsJSON(file, printable);
}
void SaveToAsJSON::saveToAsJSON(std::ofstream& file, const Printable* printable) const
{
    file << printable->print();
}

void SaveToAsText::save(std::ofstream& file, const Printable* printable) const
{
    saveToAsText(file, printable);
}
void SaveToAsText::saveToAsText(std::ofstream& file, const Printable* printable) const
{
    file << printable->print();
}