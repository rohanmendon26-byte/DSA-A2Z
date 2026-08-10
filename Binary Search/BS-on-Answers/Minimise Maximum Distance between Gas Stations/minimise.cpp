
// Time Complexity  : O(k × n)
// Space Complexity : O(n)
//Brute force
class Solution {
public:

    double minMaxDist(vector<int>& stations, int k) {

        int n = stations.size();

        vector<int> howmany(n - 1, 0);

        for (int gasStation = 1; gasStation <= k; gasStation++) {

            long double maxSection = -1;
            int maxInd = -1;

            for (int i = 0; i < n - 1; i++) {

                long double diff =
                    stations[i + 1] - stations[i];

                long double section =
                    diff / (howmany[i] + 1.0);

                if (section > maxSection) {
                    maxSection = section;
                    maxInd = i;
                }
            }

            howmany[maxInd]++;
        }

        long double maxAns = -1;

        for (int i = 0; i < n - 1; i++) {

            long double diff =
                stations[i + 1] - stations[i];

            long double section =
                diff / (howmany[i] + 1.0);

            maxAns = max(maxAns, section);
        }

        return maxAns;
    }
};



//Better
// Time Complexity
// O(n log n + k log n)
// Space Complexity
// The priority queue contains n-1 elements:
// O(n)
class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n=stations.size();
        vector<int>howmany(n-1,0);
        priority_queue<pair<long double,int>>pq;
        for(int i=0;i<n-1;i++){
            pq.push({stations[i+1]-stations[i],i});
        }
        for(int gasstation=1;gasstation<=k;gasstation++){
            auto tp=pq.top();
            pq.pop();
            int secind=tp.second;
            howmany[secind]++;
            long double indiff=stations[secind+1]-stations[secind];
            long double maxsection=indiff/(long double)(howmany[secind]+1);
            pq.push({maxsection,secind});
        }
        return pq.top().first;
    }
};



//optimal
// Time Complexity  = O(n × log(maxGap / 1e-6))
// Space Complexity = O(1)

class Solution {
	public:
	
	int numberofgasstationrequired(vector<int> &stations, long double dist) {
		int n = stations.size();
		int cnt = 0;
		for (int i = 0; i<n - 1; i++) {
			long double gap = stations[i + 1] - stations[i];
			
			int numberinbetween = gap / dist;
			
			if (gap == numberinbetween * dist) {
				numberinbetween--;
			}
			cnt += numberinbetween;
		}
		return cnt;
	}
	
	double minMaxDist(vector<int> &stations, int k) {
		// Code here
		int n = stations.size();
		long double low = 0;
		long double high = 0;
		for (int i = 0; i<n - 1; i++) {
			high = max(high, (long double)(stations[i + 1]-stations[i]));
		}
		long double diff = 1e-6;
		while (high - low>diff) {
			long double mid = low + (high - low)/2.0;
			int cnt = numberofgasstationrequired(stations, mid);
			if (cnt>k)
				low = mid;
			else
				high = mid;
		}
		return high;
	}
};


// Input: stations[] = [1, 2, 3, 4, 5], k = 2
// Output: 1.00
// Explanation: Since all gaps are already equal (1 unit each), adding extra stations in between does not reduce the maximum distance.

// Input: stations[] = [3, 6, 12, 19, 33], k = 3
// Output: 6.00 
// Explanation: The largest gap is 14 (between 19 and 33). Adding 2 stations there splits it into approx 4.67. The next largest gap is 7 (between 12 and 19). Adding 1 station splits it into 3.5. Now the maximum gap left is 6.