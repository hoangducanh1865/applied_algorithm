#include <bits/stdc++.h>
using namespace std;


// Check phone number
bool checkPhoneNumber(string phoneNumber) {
    if(phoneNumber.length() != 10) return false;

    for(char c : phoneNumber) {
        if(c < '0' || c > '9') return false;
    }

    return true;
}


// Convert from string to number
int stringToNumber(string s) {
    return (s[0] - '0') * 10 + (s[1] - '0');
}


// Count call time of each call
int countTimeEachCall(string startTime, string endTime) {
    int startTimeSecond = stringToNumber(startTime.substr(0, 2)) * 3600 +
                          stringToNumber(startTime.substr(3, 2)) * 60 +
                          stringToNumber(startTime.substr(6, 2));

    int endTimeSecond = stringToNumber(endTime.substr(0, 2)) * 3600 +
                        stringToNumber(endTime.substr(3, 2)) * 60 +
                        stringToNumber(endTime.substr(6, 2));

    return endTimeSecond - startTimeSecond;
}


int main() {
    map <string, int> numberOfCalls, totalCallTime; // Number of calls of phone_number, total call time of phone_number
    int allPhoneNumberAreValid = 1, totalNumberOfCalls = 0;

    string type;
    cin >> type;

    while(type != "#") {
        string fromPhoneNumber,  toPhoneNumber, date, startTime, endTime;
        cin >> fromPhoneNumber >> toPhoneNumber >> date >> startTime >> endTime;

        if(!checkPhoneNumber(fromPhoneNumber) || !checkPhoneNumber(toPhoneNumber)) allPhoneNumberAreValid = 0;
        totalNumberOfCalls++;
        numberOfCalls[fromPhoneNumber]++;
        totalCallTime[fromPhoneNumber] += countTimeEachCall(startTime, endTime);

        cin >> type;
    }

    cin >> type;

    while(type != "#") {
        if(type == "?check_phone_number")
            cout << allPhoneNumberAreValid << endl;
        else if(type == "?number_total_calls")
            cout << totalNumberOfCalls << endl;
        else if(type == "?number_calls_from") {
            string phoneNumber;
            cin >> phoneNumber;
            cout << numberOfCalls[phoneNumber] << endl;
        } else if(type == "?count_time_calls_from") {
            string phoneNumber;
            cin >> phoneNumber;
            cout << totalCallTime[phoneNumber] << endl;
        }

        cin >> type;
    }

    return 0;
}
