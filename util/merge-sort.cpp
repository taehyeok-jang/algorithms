// TODO

void merge(int left, int right) {
    if (left < right) {
        int m = (left + right) / 2;

        merge(left, m);
        merge(m + 1, right);

        int l = left, r = m + 1, k = l;

        while (l <= m && r <= right) {
            temp[k++] = info[0][idx[l]] < info[0][idx[r]] ? idx[l++] : idx[r++];
        }
        while (l <= m) temp[k++] = idx[l++];
        while (r <= right) temp[k++] = idx[r++];

        for (int i = left; i <= right; i++) {
            idx[i] = temp[i];
        }
    }
}