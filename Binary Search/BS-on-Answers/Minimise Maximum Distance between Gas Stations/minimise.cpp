
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