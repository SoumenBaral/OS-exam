#include<bits/stdc++.h>
using namespace std;
#define max 20 // maximum size for array
main()
{
    int i,burstTime[max],remainTime[max],waitingTime[max],tat[max],arrivalTime[max],totalExecutionTime=0,timeQuantum,n;

    printf("Enter the Number of Process(max 20) : ");
    scanf("%d",&n); // n is the number of Process

    printf("Enter Arrival Time\n");
    for(i=0;i<n;i++){
        printf("For P[%d]: ",i+1);
        scanf("%d",&arrivalTime[i]);
    }

    printf("\nEnter Burst Time\n");
    for(i=0;i<n;i++){
        printf("For P[%d]: ",i+1);
        scanf("%d",&burstTime[i]);
        remainTime[i]=burstTime[i]; // initially assume remain time for any process is equal to it's burst time !
    }

    printf("\nEnter Time Quantum :");
    scanf("%d",&timeQuantum);

    printf("\n");

    while(1)
    {
        bool done = true;
        for(int i =0; i< n; i++)
        {
            if(arrivalTime[i]<=totalExecutionTime){
            if(remainTime[i]>0)
                {
                    done = false;
                    if(remainTime[i]>timeQuantum)
                    {
                        totalExecutionTime +=timeQuantum;
                        remainTime[i] -= timeQuantum;
                    }
                    else
                   {
                        totalExecutionTime += remainTime[i];
                        tat[i] = totalExecutionTime - arrivalTime[i];
                        waitingTime[i] = tat[i] - burstTime[i];
                        remainTime[i] = 0;
                }
            }
            }
        }
        // If all processes are done
        if (done == true)
        break;
    }



    float total_wt=0, total_tat;
    cout << "PN\t "<< " \tAT "<< " \t\tBT "
        << " \t WT " << " \t\tTAT\n";
    for (int i=0; i<n; i++)
    {
        total_wt = total_wt + waitingTime[i];
        total_tat = total_tat + tat[i];
        cout << " " << i+1 << "\t\t"<<arrivalTime[i]<<"\t\t" << burstTime[i] <<"\t "
             << waitingTime[i] <<"\t\t " << tat[i] <<endl;
    }



    cout << "Average waiting time = "
        << (float)total_wt / (float)n;
    cout << "\nAverage turn around time = "
        << (float)total_tat / (float)n;
}
