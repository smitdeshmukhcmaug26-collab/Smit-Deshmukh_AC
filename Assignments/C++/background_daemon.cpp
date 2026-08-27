#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 4) {
        cout << "Usage  : " << argv[0] << " <warn_threshold> <critical_threshold> <num_readings>" << endl;
        cout << "Error  : Missing arguments." << endl;
        return 1;
    }

    double warn = atof(argv[1]);
    double critical = atof(argv[2]);
    int num_readings = atoi(argv[3]);

    if (warn >= critical) {
        cout << "Error  : warn_threshold must be strictly less than critical_threshold." << endl;
        return 1;
    }
    if (num_readings < 1 || num_readings > 500) {
        cout << "Error  : num_readings must be between 1 and 500." << endl;
        return 1;
    }

    cout << "Config  : Warn=" << (int)warn << "°C  Critical=" << (int)critical << "°C  Readings=" << num_readings << endl;

    int normal = 0, warning = 0, critical_cnt = 0, shutdown = 0;


    for (int i = 0; i < num_readings; i++) {
        int val = rand() % 70; 

        if (val < warn) {
            normal++;
        } else if (val < critical) {
            warning++;
        } else if (val < 60) {
            critical_cnt++;
        } else {
            shutdown++;
        }
    }

    cout << "Results : Normal:" << normal << "  Warning:" << warning 
         << "  Critical:" << critical_cnt << "  Shutdown:" << shutdown << endl;

    return 0;
}