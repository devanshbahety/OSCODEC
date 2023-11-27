//Round robin 

#include<iostream>
using namespace std;

struct process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat; 
    int wt;
};

void calctimes_nonpreemptive(process proc[], int n, int tq) {
    int remainingTime[n];
    for (int i = 0; i < n; i++) {
        remainingTime[i] = proc[i].bt;
    }
int currentTime = 0;
    while (true) {
        bool allDone = true;
for (int i = 0; i < n; i++) {
            if (remainingTime[i] > 0) {
                allDone = false;

                if (remainingTime[i] > tq) {
                    currentTime += tq;
                    remainingTime[i] -= tq;
                } else {
                    currentTime += remainingTime[i];
                    proc[i].ct = currentTime;
                    remainingTime[i] = 0;
                }

            }
        }

        if (allDone) {
            break;
        }
    }
}

//next page round robin

void findtat_nonpreemptive(process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].tat = proc[i].ct - proc[i].at;
    }
}

void findwt_nonpreemptive(process proc[], int n) {
    for (int i = 0; i < n; i++) {
        proc[i].wt = proc[i].tat - proc[i].bt;
    }
}

void printrr_nonpreemptive(process proc[], int n) {
    cout << "Non-preemptive RR SCHEDULING : " << endl;
    cout << "PID\t AT\t BT\t CT\t TAT\t WT" << endl;
    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t" << proc[i].at << "\t" << proc[i].bt << "\t" << proc[i].ct << "\t" << proc[i].tat << "\t" << proc[i].wt << endl;
    }
}

int main() {
    int n, tq; //no of process , time quantum
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> tq;

    process proc[n];

    cout << "Enter process details (ID, AT, BT)" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter process " << i + 1 << endl;
        cin >> proc[i].pid >> proc[i].at >> proc[i].bt;
    }

    calctimes_nonpreemptive(proc, n, tq);
    findtat_nonpreemptive(proc, n);
    findwt_nonpreemptive(proc, n);
    printrr_nonpreemptive(proc, n);

    return 0;
}
