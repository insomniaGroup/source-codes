// 0 - based indexing segmentTree seg

class SegmentTree
{
   private:
    vector<ll> seg;

   public:
    SegmentTree(int n)
    {
        seg.resize(4 * n);
    }

    void build(const vector<int>& a, int v, int low, int high)
    {
        if (low == high) {
            seg[v] = a[low];
            return;
        }
        int mid = low + (high - low) / 2;
        build(a, v * 2 + 1, low, mid);
        build(a, v * 2 + 2, mid + 1, high);
        seg[v] = seg[v * 2 + 1] + seg[v * 2 + 2];
    }

    ll find(int v, int low, int high, int l, int r)
    {
        if (l > r) {
            return 0;
        }
        if (l == low && r == high) {
            return seg[v];
        }
        int mid = low + (high - low) / 2;
        return find(v * 2 + 1, low, mid, l, min(r, mid)) + find(v * 2 + 2, mid + 1, high, max(l, mid + 1), r);
    }

    void update(int v, int low, int high, int pos, int newValue)
    {
        if (low == high) {
            seg[v] = newValue;
            return;
        }
        int mid = low + (high - low) / 2;
        if (pos <= mid) {
            update(v * 2 + 1, low, mid, pos, newValue);
        } else {
            update(v * 2 + 2, mid + 1, high, pos, newValue);
        }
        seg[v] = seg[v * 2 + 1] + seg[v * 2 + 2];
    }
};
