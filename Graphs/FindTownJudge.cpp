/* FIND THE TOWN JUDGE

In a town, there are n people labelled from 1 to n.  There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:
- The town judge trusts nobody.
- Everybody (except for the town judge) trusts the town judge.
- There is exactly one person that satisfies properties 1 and 2.
You are given trust, an array of pairs trust[i] = [a, b] representing that the person labelled a trusts the person labelled b.
If the town judge exists and can be identified, return the label of the town judge.  Otherwise, return -1.

Link: https://leetcode.com/problems/find-the-town-judge/
Note: Driver code is not given, it'll be handled in the weblink.
*/

class Solution {
public:

    int findJudge(int n, vector<vector<int>>& trust) {

        if(trust.size()<n-1)
            return -1;

        vector<int> trust_score(n);

        for(vector<int> itr: trust)
        {
            trust_score[itr[0]-1]-=1;
            trust_score[itr[1]-1]+=1;
        }

        for(int i=0; i<n; i++)
        {
            if(trust_score[i]== (n-1))
                return i+1;
        }

        return -1;
    }
};

/*
Test Cases:
    Input: n = 2, trust = [[1,2]]
    Output: 2

    Input: n = 3, trust = [[1,3],[2,3]]
    Output: 3

    Input: n = 3, trust = [[1,3],[2,3],[3,1]]
    Output: -1

    Input: n = 3, trust = [[1,2],[2,3]]
    Output: -1

    Input: n = 4, trust = [[1,3],[1,4],[2,3],[2,4],[4,3]]
    Output: 3

Time Complexity: O(E) //as E>>N and it's O(E+N)
Space Complexity: O(N)
*/
