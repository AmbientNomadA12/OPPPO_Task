#include "test.h"
#include "logic.h"

std::string testProgram(const std::string& fileName)
{
    std::string testResult = "Тест пройден";

    std::vector<Equipment*> Table;

    try
    {
        readFromFile(Table, fileName);
    }
    catch (const std::logic_error& e)
    {
        testResult = e.what();
    }

    return testResult;
}