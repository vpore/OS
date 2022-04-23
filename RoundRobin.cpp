#include<bits/stdc++.h>
using namespace std;

int processes, x, quan, WT=0, TAT=0, i, j;
int itr;
bool updated = true;
vector<vector<int>> burstTime;
vector<vector<int>> ganttchart;
vector<int> remTime;

void processInput(){
    cout<<"Enter no. of processes : ";
    cin>>processes;
    cout<<"Enter time quantum : ";
    cin>>quan;
    cout<<"Enter Burst Time of each process : \n";
    for(i=0; i<processes; i++){
        cin>>x;
        burstTime.push_back({x, i+1});
        remTime.push_back(x);
        //ganttchart.push_back({x, i+1});
    }
}

void ganttChart(){
    cout<<"\tGantt Chart\n\n";
    cout<<"Process\t\tBurst Time\n";
    int t=0;
    while(updated){
        for(auto i : burstTime){
            if(t>processes){t=0;}
            if(remTime[t]<=0){++t; continue;}
            remTime[t] -= quan;
            if(remTime[t] >= 0){
                ganttchart.push_back({quan, t+1});
                ++t;
            }
            else if(remTime[t] < 0 && itr == 0){
                ganttchart.push_back({i[0], t+1});
                ++t;
            }
            else{
                ganttchart.push_back({remTime[t]+quan, t+1});
                ++t;
            }
        }
        updated = false;
        for(j=0; j<processes; j++){
            if(remTime[j]>0){
                ++itr;
                updated = true;
                break;
            }
        }
    }
    for(auto i : ganttchart){
        cout<<"  P"<<i[1]<<"\t\t"<<i[0]<<"s\n";
    }
}

void Calculate(){
    cout<<"\n\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time\n";
    for(auto i : ganttchart){
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
    //Calculate();
    return 0;
}