#pragma once
#include <iostream>
#include <fstream>

enum class Format
{
    kText,
    kHTML,
    kJSON
};

class Printable
{
public:
    virtual ~Printable() = default;
    virtual std::string print() const = 0;
};

class PrintableAsHTML : public Printable
{
public:
    virtual ~PrintableAsHTML() = default;
    virtual std::string print() const = 0;
};

class PrintableAsText : public Printable
{
public:
    virtual ~PrintableAsText() = default;
    virtual std::string print() const = 0;
};

class PrintableAsJSON : public Printable
{
public:
    virtual ~PrintableAsJSON() = default;
    virtual std::string print() const = 0;
};


class DataAsHTML : public PrintableAsHTML
{
public:
    DataAsHTML(std::string data, Format format)
        : data_(std::move(data)), format_(format) {}

    std::string print() const override;
private:
    std::string data_;
    Format format_;
};

class DataAsText : public PrintableAsText
{
public:
    DataAsText(std::string data, Format format)
        : data_(std::move(data)), format_(format) {}

    std::string print() const override;
private:
    std::string data_;
    Format format_;
};

class DataAsJSON : public PrintableAsJSON
{
public:
    DataAsJSON(std::string data, Format format)
        : data_(std::move(data)), format_(format) {}

    std::string print() const override;
private:
    std::string data_;
    Format format_;
};

class SaveTo
{
public:
    virtual void save(std::ofstream& file, const Printable* printable) const = 0;
};

class SaveToAsHTML : public SaveTo
{
public:
    void save(std::ofstream& file, const Printable* printable) const override;
private:
    void saveToAsHTML(std::ofstream& file, const Printable* printable) const;
};

class SaveToAsJSON : public SaveTo
{
public:
    void save(std::ofstream& file, const Printable* printable) const override;
private:
    void saveToAsJSON(std::ofstream& file, const Printable* printable) const;
};

class SaveToAsText : public SaveTo
{
public:
    void save(std::ofstream& file, const Printable* printable) const override;
private:
    void saveToAsText(std::ofstream& file, const Printable* printable) const;
};