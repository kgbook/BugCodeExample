//
// Created by joey on 2024/5/13.
//

#ifndef BUGCODEEXAMPLES_CWE375_H
#define BUGCODEEXAMPLES_CWE375_H

#include <string>

class PatientClass {
private:
    int id;
    std::string name;
    int age;
};

class ClinicalTiral {
private:
    PatientClass patientClass[50];

public:
    PatientClass* getPatients() {
        return patientClass;
    }
};

#endif //BUGCODEEXAMPLES_CWE375_H
