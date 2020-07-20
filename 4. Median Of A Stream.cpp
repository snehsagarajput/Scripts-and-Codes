#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)

#define min_heap priority_queue<double, vector<double>, greater<double>>
#define max_heap priority_queue<double>


int main()
{
    double a[]={5,10,6,2,7,3,11,6};
    int n=sizeof(a)/sizeof(a[0]); 
    max_heap p;
    min_heap q;
    double median=0;
    loop(i,0,n)
    {
        if(p.size()>q.size())
        {
            if(a[i]<median)
            {
                q.push(p.top());
                p.pop();
                p.push(a[i]);
            }
            else
            {
                q.push(a[i]);
            }
            median=(p.top()+q.top())/2;
        }
        else if(p.size()<q.size())
        {
            if(a[i]>median)
            {
                p.push(q.top());
                q.pop();
                q.push(a[i]);
            }
            else
            {
                p.push(a[i]);
            } 
            median=(p.top()+q.top())/2;
        }
        else
        {
            if(a[i]<median)
            {
                p.push(a[i]);
                median=p.top();
            }
            else
            {
                q.push(a[i]);
                median=q.top();
            }
        }
        cout<<median<<"   ";
    }
    
    
    return 0;
}
