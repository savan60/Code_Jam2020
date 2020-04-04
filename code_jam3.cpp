#include <bits/stdc++.h>
using namespace std;
bool sortcol(const vector<int> &v1,
             const vector<int> &v2)
{
    return v1[0] < v2[0];
}
int main()
{
    long long int t, i, j, k;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        long long int n;
        cin >> n;
        vector<vector<int>> v;
        for (j = 0; j < n; j++)
        {
            vector<int> temp;
            for (k = 0; k < 2; k++)
            {
                int temp2;
                cin >> temp2;
                temp.push_back(temp2);
            }
            temp.push_back(j);
            v.push_back(temp);
        }
        sort(v.begin(), v.end(), sortcol);
        int f = 0;
        // for (j = 0; j < n; j++)
        // {
        //     for (k = 0; k < 3; k++)
        //     {
        //         cout << "vector is " << v[j][k] << endl;
        //     }
        //     cout << endl;
        // }
        int flag = 0;
        string s;
        map<int,char> m1;
        map<int, char> m;
        vector<int> va;
        int y;
        char cur='J';
        for (j = 0; j < v.size(); j++)
        {
            // for(k=0;k<va.size();k++){
            //     cout<<"va is "<<va[k]<<endl;
            // }
            
            if (va.size() == 0)
            {
                y=0;
            }
            else
            {
                y = upper_bound(va.begin(), va.end(), v[j][0]) - va.begin();
                if(y<va.size()){
                    y = va.size() - y;
                }
                else{
                    y=0;
                }
            }
            //cout << "y is starting " << y << endl;
            if (y > 1)
            {
                flag=-1;
                break;
            }
            else
            {
                if(y==0){
                    m[v[j][2]]='C';
                    m1[v[j][1]]='C';
                }
                else{
                    if(m1[*(va.end()-1)]=='C'){
                        m[v[j][2]]='J';
                        m1[v[j][1]]='J';
                    }
                    else{
                        m[v[j][2]]='C';
                        m1[v[j][1]]='C';
                    }
                }
                // if(cur=='J'){
                //     m[v[j][2]]='C';
                //     cur='C';
                // }
                // else{
                //     m[v[j][2]]='J';
                //     cur='J';
                // }
            }
            va.push_back(v[j][1]);
            
            sort(va.begin(), va.end());
                // if (j!=v.size()-1 && v[j][1] > v[j + 1][0])
                // {
                //     f++;
                // }
                // else
                // {
                //     if (f > 1)
                //     {
                //         flag = -1;
                //         break;
                //     }
                //     f = 0;
                //}
                //cout << "y is ending " << y << endl;
        }
        if (flag == -1)
        {
            cout << "Case #" << i + 1 << ": "
                 << "IMPOSSIBLE" << endl;
        }
        else
        {
            cout << "Case #" << i + 1 << ": ";
            for (j = 0; j < n; j++)
            {
                cout << m[j];
            }
            cout << endl;
        }
    }
}