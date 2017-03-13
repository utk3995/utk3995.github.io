// A C++ program to find maximal Bipartite matching.
#include <iostream>
#include <string.h>
using namespace std;

// M is number of applicants and N is number of jobs
int M,N;
bool bpGraph[1000][1000];
// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(int u, bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in job v and v is
        // not visited
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true; // Mark v as visited

            // If job 'v' is not assigned to an applicant OR
            // previously assigned applicant for job v (which is matchR[v])
            // has an alternate job available.
            // Since v is marked as visited in the above line, matchR[v]
            // in the following recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

// Returns maximum number of matching from M to N
int maxBPM()
{
    // An array to keep track of the applicants assigned to
    // jobs. The value of matchR[i] is the applicant number
    // assigned to job i, the value -1 indicates nobody is
    // assigned.
    int matchR[N];

    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));

    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        // Find if the applicant 'u' can get a job
        if (bpm( u, seen, matchR))
            result++;
    }
    return result;
}

// Driver program to test above functions
int main()
{
    //freopen("in.txt","r",stdin);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    int cas=1;
    while (t--){
        cin>>M;
        int a[M];
        for (int i=0;i<M;i++) {
            cin>>a[i];
        }
        cin>>N;
        int b[N];
        for (int i=0;i<N;i++){
            cin>>b[i];
        }
        memset(bpGraph,0,sizeof(bpGraph));
        for (int i=0;i<M;i++){
            for (int j=0;j<N;j++){
                if (b[j]%a[i]==0)
                    bpGraph[i][j]=1;
            }
        }
        /*for (int i=0;i<n;i++){
            cout<<a[i]<<" : ";
            for (int j=0;j<graph[i+1].size();j++){
                cout<<graph[i+1][j]<<"  ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;*/
        cout<<"Case "<<cas++<<": "<<maxBPM()<<endl;
    }
    return 0;
}




