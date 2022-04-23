#include<bits/stdc++.h>
using namespace std;

int reqNum, head, currentHead, sum=0, dir, x, i, j;
vector<int> requestQueue, order;

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

void LOOK(){
    cout<<"Enter the direction - Right[1] or Left[0] : ";
    cin>>dir;
    x=0, currentHead=head;
    if(dir){
        sort(requestQueue.begin(), requestQueue.end());
        for(i=0; i<reqNum; i++){
            if(requestQueue[i] < currentHead){continue;}
            break;
        }
        for(j=i; j<reqNum; j++){
            order.push_back(requestQueue[j]);
        }
        for(j=i-1; j>=0; j--){
            order.push_back(requestQueue[j]);
        }
    }
    else{
        sort(requestQueue.begin(), requestQueue.end());
        for(i=0; i<reqNum; i++){
            if(requestQueue[i]>currentHead){--i; break;}
        }
        for(j=i; j>=0; j--){
            order.push_back(requestQueue[j]);
        }
        for(j=i+1; j<reqNum; j++){
            order.push_back(requestQueue[j]);
        }
    }
    cout<<"\n\tIteration\tCurrent Head\tDisk Movement\tTotal Disk Movement\n";
    for(auto i : order){
        sum += abs(currentHead-i);
        cout<<"\t"<<x+1<<"\t\t"<<i<<"\t\t"<<abs(currentHead-i)<<"\t\t"<<sum<<endl;
        currentHead = i;
        ++x;
    }
    cout<<"\nTotal Head Movement = "<<sum<<endl;
    cout<<"Average Seek Time = "<<double(sum)/double(reqNum)<<endl;
    cout<<"Order : ";
    for(auto i : order){
        if(i == order[reqNum-1]){cout<<i;break;}
        cout<<i<<" -> ";
    }
}

int main(){
    processInput();
    LOOK();
    return 0;
}