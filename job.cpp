#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;

    Job(char id, int deadline, int profit) : id(id), deadline(deadline), profit(profit) {}
};

bool compare(Job& j1, Job& j2) {
    return j1.profit > j2.profit;
}

void scheduleJobs(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare);

    int n = jobs.size();
    vector<bool> slot(n, false);
    vector<char> result(n);

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = jobs[i].id;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "Scheduled Jobs: ";
    for (char jobId : result) {
        if (jobId != '\0') {
            cout << jobId << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<Job> jobs = {
        Job('a', 2, 100),
        Job('b', 1, 19),
        Job('c', 2, 27),
        Job('d', 1, 25),
        Job('e', 3, 15)
    };

    scheduleJobs(jobs);

    return 0;
}
