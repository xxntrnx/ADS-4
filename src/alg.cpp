// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++){
        for (int j = i + 1; j < len; j++) {
            if (arr[i] + arr[j] == value) {
                count++;
            }
        }
    }
    return count;
}

int countPairs2(int* arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];
        if (sum == value) {
            if (arr[left] == arr[right]) {
                int k = right - left + 1;
                count += k * (k - 1) / 2;
                break;
            }
            int leftVal = arr[left];
            int rightVal = arr[right];
            int leftCount = 0;
            int rightCount = 0;

            while (left < len && arr[left] == leftVal) {
                left++;
                leftCount++;
            }
            while (right >= 0 && arr[right] == rightVal) {
                right--;
                rightCount++;
            }
            count += leftCount * rightCount;
        }
        else if (sum < value) left++;
        else right--; 
    }
    return count;
}

int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int target = value - arr[i];
        for (int j = i + 1; j < len; j++) {
            if (arr[j] == target) count++;
            else if (arr[j] > target) break;
        }
    }
    return count;
}
