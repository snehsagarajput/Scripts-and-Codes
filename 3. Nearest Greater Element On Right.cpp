#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define fast_input ios_base::sync_with_stdio(0)
#define tie_off cin.tie(NULL)
#define loop(i,a,b) for(int i=a;i<b;++i)

void nearestGreaterElementOnRight(int *a,int n, int *ans)
{
  stack<int> s;
  s.push(-1);
  for(int i=n-1;i>-1;--i)
  {
    while(!s.empty() && a[i]>=s.top())
    {
        s.pop();
    }
    ans[i] = s.empty() ? -1 : s.top();
    s.push(a[i]);
  }
}

int main()
{
    fast_input;
    tie_off;
    
    int a[]={5,10,7,8,3,2,12};
    int n=sizeof(a)/sizeof(a[0]);
    int ans[n];
    nearestGreaterElementOnRight(a,n,ans);
    loop(i,0,n)
      cout<<ans[i]<<" ";
    cout<<nl;
    
    cout<<endl<<endl;
    return 0;
}
