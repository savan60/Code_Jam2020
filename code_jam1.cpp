 #include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int t, i, j, k;
    cin >> t;
    for (i = 0; i < t; i++)
    {
        long long int n;
        cin >> n;
        long long int a[n][n];
        set<long long int> s;
        long long int trace=0,row=0,col=0;
        for(j=0;j<n;j++){
            s.clear();
            for(k=0;k<n;k++){
                cin>>a[j][k];
                s.insert(a[j][k]);
                if(k==j){
                    trace+=a[j][k];
                }
            }
            if(s.size()!=n){
                row++;
            }
        }
        for(j=0;j<n;j++){
            s.clear();
            for(k=0;k<n;k++){
                s.insert(a[k][j]);
            }
            if(s.size()!=n){
                col++;
            }
        }
        cout<<"Case #"<<i+1<<": "<<trace<<" "<<row<<" "<<col<<endl;
    }
}