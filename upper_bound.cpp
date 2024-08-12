// Time Complexity log(n)
int upper_bound(std::vector<long>& a, long val) {
    int start = 0;
    int end = a.size() - 1;
    while (start <= end) {
        int mid = (start + end) / 2;
        if (a[mid] >= val) {
            if (mid == 0 || a[mid - 1] < val)
                return mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}
