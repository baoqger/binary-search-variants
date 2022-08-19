#include <stdio.h>
#include <stdlib.h>

//  find the element in the array which is equal to the target
int binarySearch(int *arr, int target, int size) {
    int low = 0;
    int high = size - 1;
    int mid;
    
    while(low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if(arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// find the first element in the array which is greater than(>) the target
int binarySearchGreater(int *arr, int target, int size) {
    int low = 0;
    int high = size;
    int ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= target) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

// find the first element in the array which is greater or equal(>=) than the target
int binarySearchGreaterOrEuqal(int *arr, int target, int size) {
    int low = 0;
    int high = size;
    int ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}

// find the last element in the array which is smaller(<) than the target
int binarySearchSmaller(int *arr, int target, int size) {
    int low = 0;
    int high = size - 1;
    int ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] < target) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}



// find the last element in the array which is smaller or equal(<=) than the target
int binarySearchSmallerOrEqual(int *arr, int target, int size) {
    int low = 0;
    int high = size - 1;
    int ans = -1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}



int testGreaterThan() {
    printf("Test strictly greater search.\n");
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 16};
    int target[] = {0, 2, 7, 14, 15,  20};
    
    for (int j = 0; j < sizeof(target)/sizeof(int); j++) {
        
        int t = target[j]; 
        int i = binarySearchGreater(arr, t, sizeof(arr)/sizeof(int));
        printf("find: %d %d\n", t, i >= 0 ?  arr[i] : -1);
    }
    return 0;
}

int testGreaterEqual() {
    printf("Test greater or equal search\n");
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 16};
    int target[] = {0, 2, 7, 14, 15,  20};
    
    for (int j = 0; j < sizeof(target)/sizeof(int); j++) {
        
        int t = target[j]; 
        int i = binarySearchGreaterOrEuqal(arr, t, sizeof(arr)/sizeof(int));
        printf("find: %d %d\n", t, i >= 0 ?  arr[i] : -1);
    }
    return 0;
}

int testSmallerThan() {
    printf("Test smaller search\n");
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 16};
    int target[] = {0, 2, 7, 14, 15,  20};
    
    for (int j = 0; j < sizeof(target)/sizeof(int); j++) {
        
        int t = target[j]; 
        int i = binarySearchSmaller(arr, t, sizeof(arr)/sizeof(int));
        printf("find: %d %d\n", t, i >= 0 ?  arr[i] : -1);
    }
    return 0;
}

int testSmallerOrEqual() {
    printf("Test smaller or equal search\n");
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15, 16};
    int target[] = {0, 2, 7, 14, 15,  20};
    
    for (int j = 0; j < sizeof(target)/sizeof(int); j++) {
        
        int t = target[j]; 
        int i = binarySearchSmallerOrEqual(arr, t, sizeof(arr)/sizeof(int));
        printf("find: %d %d\n", t, i >= 0 ?  arr[i] : -1);
    }
    return 0;
}



int main() {
    testGreaterThan();
    testGreaterEqual();
    testSmallerThan();
    testSmallerOrEqual();
}

