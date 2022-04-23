#include<bits/stdc++.h>
using namespace std;

int reqNum, head, currentHead, sum=0, minDiff=INT_MAX, x, i, j;
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

void SSTF(){
    x=0, currentHead=head;
    int curr, index;
    vector<bool> traversed(reqNum, false);
    cout<<"\n\tIteration\tCurrent Head\tDisk Movement\tTotal Disk Movement\n";
    for(i=0; i<reqNum; i++){
        minDiff=INT_MAX;
        for(j=0; j<reqNum; j++){
            if(currentHead != requestQueue[j] && !traversed[j]){
                curr = abs(currentHead-requestQueue[j]);
                if(curr<minDiff){
                    minDiff = curr;
                    index = j;
                }
            }
        }
        sum += minDiff;
        traversed[index] = true;
        order.push_back(requestQueue[index]);
        currentHead = requestQueue[index];
        cout<<"\t"<<i+1<<"\t\t"<<currentHead<<"\t\t"<<minDiff<<"\t\t"<<sum<<endl;
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
    SSTF();
    return 0;
}