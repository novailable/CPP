#include "Bureaucrat.hpp"
#include <iostream>

// Terminal color codes
#define RESET       "\033[0m"
#define RED         "\033[31m"
#define GREEN       "\033[32m"
#define YELLOW      "\033[33m"
#define CYAN        "\033[36m"
#define BOLD        "\033[1m"

void printHeader(const std::string &title) {
    std::cout << BOLD << CYAN << "\n=== " << title << " ===\n" << RESET;
}

void testDefaultConstructor()
{
    printHeader("Default Constructor Test");
    Bureaucrat b;
    std::cout << GREEN << b << RESET << "\n";
}

void testValidConstruction()
{
    printHeader("Valid Construction Test");
    Bureaucrat b1("Alice", 1);
    Bureaucrat b2("Bob", 150);
    std::cout << GREEN << b1 << RESET << "\n" << GREEN << b2 << RESET << "\n";
}

void testInvalidConstruction()
{
    printHeader("Invalid Construction Test");
    try
    {
        Bureaucrat b("Charlie", 0);
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Caught exception: " << e.what() << RESET << "\n";
    }
    try
    {
        Bureaucrat b("Dave", 151);
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Caught exception: " << e.what() << RESET << "\n";
    }
}

void testCopyAndAssignment()
{
    printHeader("Copy Constructor and Assignment Test");
    Bureaucrat original("Eve", 75);
    Bureaucrat copy(original);
    Bureaucrat assigned;
    assigned = original;

    std::cout << YELLOW << "Original: " << RESET << original << "\n";
    std::cout << YELLOW << "Copy: " << RESET << copy << "\n";
    std::cout << YELLOW << "Assigned: " << RESET << assigned << "\n";
}
void testGradeIncrementDecrement()
{
    printHeader("Grade Increment and Decrement Test");
    Bureaucrat b("Frank", 2);
    std::cout << GREEN << b << RESET << "\n";

    std::cout << CYAN << "Pre-increment:" << RESET << "\n";
    try
    {
        ++b;
        std::cout << GREEN << b << RESET << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Exception on pre-increment: " << e.what() << RESET << "\n";
    }

    std::cout << CYAN << "Post-increment:" << RESET << "\n";
    try
    {
        b++;
        std::cout << GREEN << b << RESET << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Exception on post-increment: " << e.what() << RESET << "\n";
    }

    std::cout << CYAN << "Pre-decrement:" << RESET << "\n";
    try
    {
        --b;
        std::cout << GREEN << b << RESET << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Exception on pre-decrement: " << e.what() << RESET << "\n";
    }

    std::cout << CYAN << "Post-decrement:" << RESET << "\n";
    try
    {
        b--;
        std::cout << GREEN << b << RESET << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Exception on post-decrement: " << e.what() << RESET << "\n";
    }

    std::cout << CYAN << "Increase grade by 2:" << RESET << "\n";
    try
    {
        b.increaseGrade(2);
        std::cout << GREEN << b << RESET << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << "\n";
    }

    std::cout << CYAN << "Decrease grade by 3:" << RESET << "\n";
    try
    {
        b.decreaseGrade(3);
        std::cout << GREEN << b << RESET << "\n";
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Exception: " << e.what() << RESET << "\n";
    }
}

void testExceptionOnIncrementDecrement()
{
    printHeader("Exception on Increment/Decrement Boundaries Test");
    Bureaucrat top("Top", 1);
    Bureaucrat bottom("Bottom", 150);

    try
    {
        ++top;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Top increment exception: " << e.what() << RESET << "\n";
    }

    try
    {
        bottom.decreaseGrade(1);
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Bottom decrease exception: " << e.what() << RESET << "\n";
    }

    try
    {
        bottom++;
    }
    catch (const std::exception &e)
    {
        std::cerr << RED << "Bottom post-increment exception: " << e.what() << RESET << "\n";
    }
}

int main()
{
    testDefaultConstructor();
    testValidConstruction();
    testInvalidConstruction();
    testCopyAndAssignment();
    testGradeIncrementDecrement();
    testExceptionOnIncrementDecrement();

    return 0;
}
