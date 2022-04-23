#include<bits/stdc++.h>
using namespace std;

int processes, x, prio, WT=0, TAT=0, i;
vector<vector<int>> burstTime;

void processInput(){
    cout<<"Enter no. of processes : ";
    cin>>processes;
    cout<<"Enter Priority & Burst Time  of each process (respectively) : \n";
    for(i=0; i<processes; i++){
        cin>>prio>>x;
        burstTime.push_back({prio, x, i+1});
    }
    sort(burstTime.begin(), burstTime.end());
}

void ganttChart(){
    cout<<"\t\tGantt Chart\n\n";
    cout<<"Process : \t";
    for(auto i : burstTime){
        cout<<"P"<<i[2]<<"\t";
    }
    cout<<"\nPriority : \t";
    for(auto i : burstTime){
        cout<<i[0]<<"\t";
    }
    cout<<"\nBurst Time : \t";
    for(auto i : burstTime){
        cout<<i[1]<<"s\t";
    }
}

void Calculate(){
    cout<<"\n\nProcess\t\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(auto i : burstTime){
        TAT+=i[1];
        cout<<"  P"<<i[2]<<"\t\t"<<i[0]<<"\t\t"<<i[1]<<"s\t\t"<<WT<<"s\t\t"<<TAT<<"s\n";
        WT+=i[1];
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