#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Patient{

    private:

    int patientId;
    string name;
    int age;
    string ward;
    const string bloodGroup;

    public:

    Patient() : patientId(0), name("Unknown"), age(0), ward("General"), bloodGroup("O+") {
        cout << "[Constructor] Default patient registered." << endl;
    }

    Patient(int id, const string& name): patientId(id), name(name), age(0), ward("General"), bloodGroup("O+"){
        cout << "Emergency! " << endl;
        cout << "Enter patient name : " << name << endl;
        cout << "Enter patient id : " << id << endl;
    }

    Patient(int id, const string& name, int age, const string& ward, const string& bg): patientId(id), name(name), age(0), ward("General"), bloodGroup("O+"){
        cout << "Full admission: " << name << endl;
    }

    ~Patient(){
        cout << "Patient " << name << " discharged." << endl;
    }

    void displayRecord(){
        cout << "\nPatient Record:\n";
        cout << "  ID        : " << patientId << "\n";
        cout << "  Name      : " << name << "\n";
        cout << "  Age       : " << age << "\n";
        cout << "  Ward      : " << ward << "\n";
        cout << "  Blood Grp : " << bloodGroup << endl;
    }

    void transferWard(const string& newWard){
        cout << "Ward Transfer: " << name << " -> " << newWard << endl;
        ward = newWard;
    }

};

int main(){

    Patient p1(1001, "Meera Joshi", 34, "Cardiology", "B+");
    Patient p2(1002, "Raj Patel");
    Patient p3;

    Patient* wardArray = new Patient[4];

    for(int i = 0; i < 4; i++){
        wardArray[i].displayRecord();
    }

    p1.displayRecord();

    p2.transferWard("ICU");

    delete[] wardArray;

    return 0;
}