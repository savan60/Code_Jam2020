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
        string s;
        cin >> s;
        vector<int> v;
        for(j=0;j<s.length();j++){
            v.push_back(int(s[j])-48);
        }
        string ans;
        int last=0;
        int ma=-1;
        vector<int> m;
        for(j=0;j<v.size();j++){
            //cout<<"v[j] is "<<v[j]<<endl;
            if(v[j]==0){
                if(ma!=-1){
                    m.push_back(ma);
                }
                ma=-1;
            }
            else{
                //cout<<"here"<<endl;
                if(ma==-1){
                    ma=v[j];
                }
                else if(ma>v[j]){
                    ma=v[j];
                }
            }
            //cout<<"ma is "<<ma<<endl;
        }
        if(ma!=-1){
            m.push_back(ma);
        }
        //cout<<"size of m vector is "<<m.size()<<endl;
        // for(j=0;j<m.size();j++){
        //     cout<<"value is "<<m[j]<<endl;
        // }
        int ind=-1;
        for(j=0;j<v.size();j++){
            int f=0;
            while(v[j]==0 && j<v.size()){
                ans+='0';
                f=-1;
                j++;
            }
            if(j==v.size()){
                break;
            }
            int start=j;
                ind++;
                //cout<<"m[ind]  is"<<m[ind]<<endl;
                last=m[ind];
            //cout<<"j is "<<j<<endl;
            int count=0;
            while(v[j]!=0 && j<v.size()){
                j++;
            }
            int flag2=0;
            if(j==v.size()){
                count=v.size();
                flag2=-1;
            }
            else{
                count=j;
                j--;
            }
            //cout<<"then j is "<<j<<endl;
            //cout<<"count is "<<count<<endl;
            //cout<<"start is "<<start<<endl;
            for(k=0;k<last;k++){
                ans+='(';
            }
            int open=last;
            //cout<<"opened "<<open<<endl;
            for(k=start;k<count-1;k++){
                int diff=v[k]-open;
                for(int p=0;p<diff;p++){
                    ans+='(';
                }
                ans+=v[k]+48;
                int close;
                if(v[k]>v[k+1]){
                    close=v[k]-v[k+1];
                    for(int p=0;p<close;p++){
                        ans+=')';
                    }
                    open=v[k+1];
                }
                else{
                    open=v[k];
                }
            }
            //cout<<"v[k] is "<<v[k]<<endl;
            //cout<<"v[k] is "<<v[k]<<endl;
            int diff=v[k]-open;
            for(int p=0;p<diff;p++){
                ans+='(';
            }
            ans+=v[k]+48;
            open=v[k];
            for(int p=0;p<open;p++){
                ans+=')';
            }
            if(flag2==-1){
                break;
            }
        }
        cout<<"Case #"<<i+1<<": "<<ans<<endl;
    }
}