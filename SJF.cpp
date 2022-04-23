#include<bits/stdc++.h>
using namespace std;

int processes, x, WT=0, TAT=0, i;
vector<vector<int>> burstTime;

void processInput(){
    cout<<"Enter no. of processes : ";
    cin>>processes;
    cout<<"Enter Burst Time of each process : \n";
    for(i=0; i<processes; i++){
        cin>>x;
        burstTime.push_back({x, i+1});
    }
    sort(burstTime.begin(), burstTime.end());
}

void ganttChart(){
    cout<<"\t\tGantt Chart\n\n";
    cout<<"Process : \t";
    for(auto i : burstTime){
        cout<<"P"<<i[1]<<"\t";
    }
    cout<<"\nBurst Time : \t";
    for(auto i : burstTime){
        cout<<i[0]<<"s\t";
    }
}

void Calculate(){
    cout<<"\n\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(auto i : burstTime){
        TAT+=i[0];
        cout<<"  P"<<i[1]<<"\t\t"<<i[0]<<"s\t\t"<<WT<<"s\t\t"<<TAT<<"s\n";
        WT+=i[0];
    }
    WT-=burstTime[processes-1][0];
    cout<<"\n\nAverage Waiting Time = "<<fixed<<setprecision(2)<<double(WT)/double(processes);
    cout<<"\nAverage Turnaround Time = "<<fixed<<setprecision(2)<<double(TAT)/double(processes);
}

int main(){
    processInput();
    ganttChart();
    Calculate();
    return 0;
}