#include <iostream>

using namespace std;

int main()
{
    int p, r;

    cout<<"Enter the number of Processes and Resources: ";
    cin>>p>>r;

    int available[r], Max[p][r], allocation[p][r], RemNeed[p][r];

    cout<<"Enter available resources: ";
    for(int i=0; i<r; i++){
        cin>>available[i];
    }
    cout<<"Enter required Max resources of each process:"<<endl;
    for(int i=0; i<p; i++){
        for(int j=0; j<r; j++){
            cin>>Max[i][j];
        }
    }
    cout<<"Enter Allocation resources of each process:"<<endl;
    for(int i=0; i<p; i++){
        for(int j=0; j<r; j++){
            cin>>allocation[i][j];
            RemNeed[i][j]=Max[i][j]-allocation[i][j];
            available[j]=available[j]-allocation[i][j]; 
        }
    }
    //Prints the remaining resources required for each process.
    cout<<"Remaining Need: ";
    for(int i=0; i<p; i++){
        for(int j=0; j<r; j++){
            cout<<RemNeed[i][j]<<" ";
        }
        cout<<endl;
    }
    bool visited[p]; 
    for(int i=0; i<p; i++){
        visited[i]=false; 
    }
    int count=0; 
  
    while(count!=p){
        for(int i=0; i<p; i++){
            if(!visited[i]){ 
                for(int j=0; j<r; j++){
                    if(RemNeed[i][j]>available[j])
                        break;
                }
                if(i==r){
                    visited[i]=true; 
                    count++;
                    cout<<"Process: "<<i<<" ";
                    for(int j=0; j<r; j++) { 
                        available[j]=available[j]+allocation[i][j];
                }
            }
        }
    }
 
   return 0;
}