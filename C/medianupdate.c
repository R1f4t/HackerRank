#include<bits/stdc++.h>

using namespace std;


void median(vector<char> V, vector<long int> X){
    multiset<long int> rightMedian; //min heap
    multiset <long int, greater <long int> > leftMedian; //max heap
    double median;
    int flag;
    int i=0;
    for(;i<V.size();i++){
        if(V[i]=='a'){
            rightMedian.insert(X[i]);
            median=X[i];
            if(leftMedian.size()+rightMedian.size()==0){
                cout<<"Wrong!"<<endl;
            }
            else{
                if(ceil(median)!=median){
                    cout<<fixed<<setprecision(1)<<median<<endl;
                }
                else{
                    cout<<fixed<<setprecision(0)<<median<<endl;
                }
            }
            i++;
            break;
        }
        else{
            cout<<"Wrong!"<<endl;
        }
    }
    for(;i<V.size();i++){
        flag = 1;
        if(V[i]=='a'){
            if(signed(rightMedian.size()-leftMedian.size())==1){
                if(X[i]<median){
                    leftMedian.insert(X[i]);
                }
                else if(X[i]>=median){
                    int temp = *(rightMedian.begin());
                    rightMedian.erase(rightMedian.begin());
                    rightMedian.insert(X[i]);
                    leftMedian.insert(temp);
                }
            }

            else if(signed(rightMedian.size()-leftMedian.size())==0){
                if(X[i]>=median){
                    rightMedian.insert(X[i]);
                }
                else if(X[i]<median){
                    leftMedian.insert(X[i]);
                    int temp = *(leftMedian.begin());
                    rightMedian.insert(temp);
                    leftMedian.erase(leftMedian.begin());
                }

            }

            else{
                rightMedian.insert(X[i]);
            }
        }


        else if(V[i]=='r'){
            if(leftMedian.count(X[i]) || rightMedian.count(X[i])){
                if(leftMedian.count(X[i])){
                    leftMedian.erase(leftMedian.find(X[i]));
                }
                else if(rightMedian.count(X[i])){
                    rightMedian.erase(rightMedian.find(X[i]));
                }
            }
            else{
                flag = -1;
            }

        }

        // auto balancing after removal is done
        if(signed(rightMedian.size()-leftMedian.size())>1 || signed(rightMedian.size()-leftMedian.size())<0){
            if(signed(rightMedian.size()-leftMedian.size())>1){
                int temp = *(rightMedian.begin());
                rightMedian.erase(rightMedian.begin());
                leftMedian.insert(temp);
            }
            else{
                int temp = *(leftMedian.begin());
                leftMedian.erase(leftMedian.begin());
                rightMedian.insert(temp);

            }
        }

        if(flag == -1){
            cout<<"Wrong!"<<endl;
            flag = 1;
        }
        else if((leftMedian.size()+rightMedian.size())%2==0 && leftMedian.size()+rightMedian.size()!=0){
            median = (*(leftMedian.begin()) + *(rightMedian.begin()))/2.0;
            if(ceil(median)!=median){
                cout<<fixed<<setprecision(1)<<median<<endl;
            }
            else{
                cout<<fixed<<setprecision(0)<<median<<endl;
            }
        }
        else if(leftMedian.size()+rightMedian.size()==0){
            cout<<"Wrong!"<<endl;
        }
        else{
            median = *(rightMedian.begin());
            if(ceil(median)!=median){
                cout<<fixed<<setprecision(1)<<median<<endl;
            }
            else{
                cout<<fixed<<setprecision(0)<<median<<endl;
            }
        }
    }
}

int main(){
    long int N;
    cin>>N;
    vector<char> s;
    vector<long int> X;
	char temp;
    int tempint;
	for(int i = 0; i < N; i++){
		cin >> temp >> tempint;
        s.push_back(temp);
        X.push_back(tempint);
	}
	median(s,X);
	return 0;
}
