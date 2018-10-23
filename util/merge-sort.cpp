// TODO

/**
 * merge sort with comparator (ex. array refered.)
 */
void merge_sort(int left, int right) {
    if (left < right) {
        int m = (left + right) / 2;

        merge_sort(left, m);
        merge_sort(m + 1, right);

        int l = left, r = m + 1, k = l;

        while (l <= m && r <= right) {
            temp[k++] = info[0][idx[l]] < info[0][idx[r]] ? idx[l++] : idx[r++];
            // TODO temp[k++] = comparator(l, r)? idx[l++] : idx[r++];
        }
        while (l <= m) temp[k++] = idx[l++];
        while (r <= right) temp[k++] = idx[r++];

        for (int i = left; i <= right; i++) {
            idx[i] = temp[i];
        }
    }
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int m = (left + right) / 2;

        merge_sort(arr, left, m);
        merge_sort(arr, m+1, right);

        int l = left, r = m + 1, k = l;

        while (l <= m && r <= right) {
            aux[k++] = arr[l]<arr[r]? arr[l++]:arr[r++];
        }
        while(l<=m) aux[k++] = arr[l++];
        while(r<=right) aux[k++] = arr[r++];

        for (int i = left; i <= right; i++)
            arr[i] = aux[i];
    }
}

