#include<bits/stdc++.h>
using namespace std;

int reqNum, head, currentHead, sum=0, x, i;
vector<int> requestQueue;

void processInput(){
    cout<<"Enter the number of requests : ";
    cin>>reqNum;
    cout<<"Enter the request queue : ";
    for(i=0; i<reqNum; i++){
        cin>>x;
        requestQueue.push_back(x);
    }
    cout<<"Enter Head position : ";
    cin>>head;
}

void FCFS(){
    x=0, currentHead=head;
    cout<<"\n\tIteration\tCurrent Head\tDisk Movement\tTotal Disk Movement\n";
    for(auto i : requestQueue){
        sum += abs(currentHead-i);
        cout<<"\t"<<x+1<<"\t\t"<<i<<"\t\t"<<abs(currentHead-i)<<"\t\t"<<sum<<endl;
        currentHead = i;
        ++x;
    }
    cout<<"\nTotal Head Movement = "<<sum<<endl;
    cout<<"Average Seek Time = "<<double(sum)/double(reqNum)<<endl;
    cout<<"Order : ";
    for(auto i : requestQueue){
        if(i == requestQueue[reqNum-1]){cout<<i;break;}
        cout<<i<<" -> ";
    }
}

int main(){
    processInput();
    FCFS();
    return 0;
}