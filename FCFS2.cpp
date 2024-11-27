#include<bits/stdc++.h>

using namespace std;

int main(){

int i,n;
vector<pair<int,int>>ATBT;

cin>>n;
for(i=0;i<n;i++){

    int At,bt;
    cin>>At>>bt;

    ATBT.push_back(make_pair(At,bt));
}

sort(ATBT.begin(),ATBT.end());

int CT[n],TAT[n],WT[n];

CT[0]=ATBT[0].second;
for (i=1;i<n;i++){
    CT[i]=CT[i-1]+ATBT[i].second;
}

for (i=0;i<n;i++){
    TAT[i]=CT[i]-ATBT[i].first;
    WT[i]=TAT[i]-ATBT[i].second;
}


for (i=0;i<n;i++){
    cout<<ATBT[i].first<<" "<<ATBT[i].second<<endl;
}
}