class NumArray {
public:
    vector<int> seg;
    int n;

    void build(int idx, int low, int high, vector<int>& nums) {
        if (low == high) {
            seg[idx] = nums[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * idx + 1, low, mid, nums);
        build(2 * idx + 2, mid + 1, high, nums);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    int query(int idx, int low, int high, int l, int r) {
        // Complete overlap
        if (low >= l && high <= r) {
            return seg[idx];
        }

        // No overlap
        if (high < l || low > r) {
            return 0;
        }

        int mid = (low + high) / 2;

        int left = query(2 * idx + 1, low, mid, l, r);
        int right = query(2 * idx + 2, mid + 1, high, l, r);

        return left + right;
    }

    void updateTree(int idx, int low, int high, int pos, int val) {
        if (low == high) {
            seg[idx] = val;
            return;
        }

        int mid = (low + high) / 2;

        if (pos <= mid)
            updateTree(2 * idx + 1, low, mid, pos, val);
        else
            updateTree(2 * idx + 2, mid + 1, high, pos, val);

        seg[idx] = seg[2 * idx + 1] + seg[2 * idx + 2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        seg.resize(4 * n);

        if (n > 0)
            build(0, 0, n - 1, nums);
    }

    void update(int index, int val) {
        updateTree(0, 0, n - 1, index, val);
    }

    int sumRange(int left, int right) {
        return query(0, 0, n - 1, left, right);
    }
};