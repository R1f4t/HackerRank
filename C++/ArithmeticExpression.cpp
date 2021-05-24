#include <bits/stdc++.h>

using namespace std;


int module(int a, int b){
    if(a < 0)       return  (a % b) + b;
    else        return a % b;
}

int main() {
    vector <int> v;
    vector <char> ch;
    int n, tmp;
    cin >> n;
    for(int i=0; i<n; i++){
            cin >> tmp;
            v.push_back(tmp);
    }

    unsigned int arr[n][101]={0};
    arr[0][v.at(0)]=1;
    int a, b, c;
    int val, res, row;

    int f=0;
    for(int i=0; i<n-1; i++){
        if(f==1)
            break;
        for(int j=0; j<101; j++){
            if(arr[i][j] == 1){
                a = (j + v.at(i+1)) % 101;
                b = module(j - v.at(i+1) ,101);
                c = (j * v.at(i+1)) % 101;
                arr[i+1][a]=1;
                arr[i+1][b]=1;
                arr[i+1][c]=1;
                if (a == 0 || b == 0){
                    val = v.at(i+1);
                    res = 0;
                    row = i;
                    f=1;
                    break;
                }
            }
        }
    }

    for(int i=row; i >= 0; i--){
        for(int j=0; j<101; j++){
            if(arr[i][j] == 1){
                if( module(j - v.at(i+1) ,101) == res){
                    res = j;
                    val = v.at(i);
                    ch.push_back('-');
                    break;
                }
                if( (j+val) % 101 == res){
                    res = j;
                    val = v.at(i);
                    ch.push_back('+');
                    break;
                }
                if( (j*val) % 101 == res){
                    res = j;
                    val = v.at(i);
                    ch.push_back('*');
                    break;
                }
            }
        }
    }

    for(int i=0; i<row+1; i++){
        cout << v.at(i);
        cout << ch.at(row-i);
    }
    cout << v.at(row+1);

    if(row + 2 < n){
        for(int i=0;i<n-row-2; i++){
            cout << "*" << v.at(row+2+i);
        }
    }

    return 0;
}
