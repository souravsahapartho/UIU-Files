#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Maximum {
    int length;
    int start_month;
    int end_month;
};

Maximum findCrs(const vector<int>& profits, int low, int mid, int high) {
    int left_length = 0;
    int left_index = -1;
    for (int i = mid; i >= low; --i) {
        if (profits[i] > 0) {
            left_length++;
            left_index = i;
        } else {
            break;
        }
    }

    int right_length = 0;
    int right_index = -1;
    for (int i = mid + 1; i <= high; ++i) {
        if (profits[i] > 0) {
            right_length++;
            right_index = i;
        } else {
            break;
        }
    }

    if (left_index != -1 && right_index != -1) {
        return {left_length+ right_length, left_index + 1, right_index + 1};
    } else if (left_index != -1) {
        return {left_length, left_index + 1, left_index + left_length};
    } else if (right_index != -1) {
        return {right_length, right_index - right_length + 1, right_index + 1};
    } else {
        return {0, -1, -1};
    }
}

Maximum find_period(const vector<int>& profits, int low, int high) {
    if (low == high) {
        if (profits[low] > 0) {
            return {1, low + 1, low + 1};
        } else {
            return {0, -1, -1};
        }
    }

    int mid = low + (high - low) / 2;

    Maximum left_result = find_period(profits, low, mid);
    Maximum right_result = find_period(profits, mid + 1, high);
    Maximum crs_result = findCrs(profits, low, mid, high);

    if (left_result.length >= right_result.length && left_result.length >= crs_result.length) {
        return left_result;
    } else if (right_result.length >= left_result.length && right_result.length >= crs_result.length) {
        return right_result;
    } else {
        return crs_result;
    }
}

int main() {
    vector<int> profits = {3, -1, 9, -2, 4, 3, 1, -5, 3, 2};
    Maximum final_result = find_period(profits, 0, profits.size() - 1);

    if (final_result.length > 0) {
        cout << "Longest Profit Period = " << final_result.length << " months" << endl;
        cout << "Month Range = {M" << final_result.start_month << ", M" << final_result.end_month << "}" << endl;
    } else {
        cout << "No continuous profit period found!" << endl;
    }

    return 0;
}
