Code-:
class Solution {
public:
    static bool compare(const vector<int>& a, const vector<int>& b) {
    return a[1] == b[1] ? a[0] < b[0] : a[1] < b[1];
}

int scheduleCourse(vector<vector<int>>& courses) {
    sort(courses.begin(), courses.end(), compare);

    priority_queue<int> pq;
    int time = 0;

    for (const auto& course : courses) {
        if (course[0] <= course[1]) {
            if (time + course[0] <= course[1]) {
                pq.push(course[0]);
                time += course[0];
            } else {
                if (!pq.empty() && pq.top() > course[0]) {
                    time -= pq.top();
                    pq.pop();
                    time += course[0];
                    pq.push(course[0]);
                }
            }
        }
    }

    return pq.size();
}
};