#include <format>
#include <iostream>
#include <sstream>
#include <fstream>
#include <ctime>
#include <chrono>
#include <iomanip>
#include <vector>
#include <string>

using std::string;
using std::stringstream;
using std::cin;
using std::cout;

//void GetCurrentDateTime(stringstream& stream)
//{
//    // Get the current time
//    auto now = std::chrono::system_clock::now();
//    time_t currentTime = std::chrono::system_clock::to_time_t(now);
//
//    // Convert to local time structure
//    tm localTime;
//    localtime_s(&localTime, &currentTime);
//
//    // Format the date and time string
//    /*std::strftime(buffer, sizeof(buffer), "%d/%m/%Y Time: %H:%M:%S", localTime);*/
//    stream << std::put_time(&localTime, "%a %b %d %H:%M:%S %Y");
//}

char* GetCurrentDateTime()
{
    // Get the current time
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Convert to local time structure - using the safer localtime_s for Windows
    std::tm localTimeObj = {};
    localtime_s(&localTimeObj, &currentTime);

    // Format the date and time string with CSV commas
    static char buffer[80];  // Static so it persists after function returns
    std::strftime(buffer, sizeof(buffer), "%x,Time:,%X", &localTimeObj);

    return buffer;
}

int main()
{
    //stringstream stream;

    //GetCurrentDateTime(stream);

    //cout << stream.str() << "\n";

    string time = GetCurrentDateTime();

    cout << time << "\n";

}