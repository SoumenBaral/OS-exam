#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    int arrivalTime[n], burstTime[n], waitingTime[n], tat[n];
    float totalWT = 0, totalTAT = 0;

    cout << "Enter Arrival Time and Burst Time for each process:\n";
    for (int i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "] Arrival Time: ";
        cin >> arrivalTime[i];
        cout << "P[" << i + 1 << "] Burst Time: ";
        cin >> burstTime[i];
    }

    // Calculating waiting time and turnaround time
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            waitingTime[i] = 0;
        } else {
            waitingTime[i] = (arrivalTime[i - 1] + burstTime[i - 1] + waitingTime[i - 1]) - arrivalTime[i];
            if (waitingTime[i] < 0) waitingTime[i] = 0; // No negative waiting time
        }
        tat[i] = waitingTime[i] + burstTime[i];
        totalWT += waitingTime[i];
        totalTAT += tat[i];
    }

    // Output
    cout << "\nPN\tAT\tBT\tWT\tTAT\n";
    for (int i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "]\t" << arrivalTime[i] << "\t" << burstTime[i]
             << "\t" << waitingTime[i] << "\t" << tat[i] << "\n";
    }

    cout << "\nAverage Waiting Time: " << totalWT / n << "\n";
    cout << "Average Turnaround Time: " << totalTAT / n << "\n";

    return 0;
}
