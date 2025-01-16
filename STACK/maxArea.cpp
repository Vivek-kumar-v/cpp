#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;

#define MAX 1000  // Assuming the maximum grid size is 1000x1000

class Solution {
public:
    vector<int> nextSmallerElement(int* arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for (int i = n - 1; i >= 0; i--) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // ans is top of stack
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    vector<int> prevSmallerElement(int* arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n, -1);

        for (int i = 0; i < n; i++) {
            int curr = arr[i];
            while (s.top() != -1 && arr[s.top()] >= curr) {
                s.pop();
            }
            // ans is top of stack
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }

    int largestRectangleArea(int* heights, int n) {
        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = INT_MIN;
        for (int i = 0; i < n; i++) {
            int l = heights[i];
            if (next[i] == -1) {
                next[i] = n;
            }
            int b = next[i] - prev[i] - 1;
            int newArea = l * b;
            area = max(area, newArea);
        }
        return area;
    }

public:
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Calculate area for the first row
        int area = largestRectangleArea(M[0], m);

        // Process each row after the first
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (M[i][j] != 0) {
                    M[i][j] += M[i - 1][j];
                } else {
                    M[i][j] = 0;
                }
            }
            area = max(area, largestRectangleArea(M[i], m));
        }
        return area;
    }
};

// Main function to test the code
int main() {
    Solution solution;
    int n = 4, m = 4;
    int M[MAX][MAX] = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0}
    };

    int maxArea = solution.maxArea(M, n, m);
    cout << "The maximum rectangular area of 1s is: " << maxArea << endl;

    return 0;
}
