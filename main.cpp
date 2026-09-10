#include "versionA.h"
#include "versionB.h"

#include <iostream>
using namespace std;

void run_versionA(){
    cout << "running version A" << endl;
    VersionA v1(3);
    VersionA v2(5);
    cout << "calling v1 + v2" << endl;
    VersionA result = v1+v2;
    cout << "copy count is " << VersionA::copyCount << endl;
    cout << "assign count is " << VersionA::assignCount << endl;
    cout << "calling v1+= v2" << endl;
    v1+= v2; 
    cout << "copy count is " << VersionA::copyCount << endl;
    cout << "assign count is " << VersionA::assignCount << endl;

}

void run_versionB(){
    cout << "running version B" << endl;
    VersionB v1(3);
    VersionB v2(5);
    cout << "calling v1 + v2" << endl;
    VersionB result = v1+v2;
    cout << "copy count is " << VersionB::copyCount << endl;
    cout << "assign count is " << VersionB::assignCount << endl;
    cout << "calling v1+= v2" << endl;
    v1+= v2; 
    cout << "copy count is " << VersionB::copyCount << endl;
    cout << "assign count is " << VersionB::assignCount << endl;

}

int main() {
    run_versionA();
    cout << "****************" << endl;
    run_versionB();
    return 0;
}
