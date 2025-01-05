#include <stdio.h>

void sort_tang(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sort_giam(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int size, int value) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == value) {
            return 1;
        } else if (arr[mid] < value) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return 0;
}

int main() {
    int arr[100], size = 0, choice;
    while (1) {
        printf("1. Nhap gia tri cac phan tu vao mang\n");
        printf("2. Hien thi gia tri cac phan tu trong mang\n");
        printf("3. Them mot phan tu vao vi tri chi dinh\n");
        printf("4. Sua mot phan tu o vi tri chi dinh\n");
        printf("5. Xoa mot phan tu o vi tri chi dinh\n");
        printf("6. Sap xep cac phan tu\n");
        printf("7. Tim kiem phan tu nhap vao\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Nhap so luong phan tu: ");
            scanf("%d", &size);
            for (int i = 0; i < size; i++) {
                printf("Nhap gia tri phan tu thu %d: ", i + 1);
                scanf("%d", &arr[i]);
            }
            break;
        case 2:
            if (size == 0) {
                printf("Mang rong\n");
            } else {
                printf("Cac phan tu trong mang: ");
                for (int i = 0; i < size; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
            }
            break;
        case 3:
            if (size == 0) {
                printf("Ban chua nhap gia tri cac phan tu cua mang\n");
            } else {
                int position, value;
                printf("Nhap vi tri can them: ");
                scanf("%d", &position);
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                if (position < 1 || position > size + 1) {
                    printf("Vi tri khong hop le\n");
                } else {
                    for (int i = size; i > position - 1; i--) {
                        arr[i] = arr[i - 1];
                    }
                    arr[position - 1] = value;
                    size++;
                    printf("Them thanh cong\n");
                }
            }
            break;
        case 4:
            if (size == 0) {
                printf("Ban chua nhap gia tri cac phan tu cua mang\n");
            } else {
                int position, value;
                printf("Nhap vi tri can sua: ");
                scanf("%d", &position);
                printf("Nhap gia tri can sua: ");
                scanf("%d", &value);
                if (position < 1 || position > size) {
                    printf("Vi tri khong hop le\n");
                } else {
                    arr[position - 1] = value;
                    printf("Sua thanh cong\n");
                }
            }
            break;
        case 5:
            if (size == 0) {
                printf("Ban chua nhap gia tri cac phan tu cua mang\n");
            } else {
                int position;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &position);
                if (position < 1 || position > size) {
                    printf("Vi tri khong hop le\n");
                } else {
                    for (int i = position - 1; i < size - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    size--;
                    printf("Xoa thanh cong\n");
                }
            }
            break;
        case 6:
            if (size == 0) {
                printf("Ban chua nhap gia tri cac phan tu cua mang\n");
            } else {
                char another_choice;
                printf("a. Giam dan\n");
                printf("b. Tang dan\n");
                printf("Nhap lua chon cua ban: ");
                scanf(" %c", &another_choice);
                if (another_choice == 'a') {
                    sort_giam(arr, size);
                    printf("Sap xep giam dan thanh cong\n");
                } else if (another_choice == 'b') {
                    sort_tang(arr, size);
                    printf("Sap xep tang dan thanh cong\n");
                } else {
                    printf("Lua chon khong hop le\n");
                }
            }
            break;
        case 7:
            if (size == 0) {
                printf("Ban chua nhap gia tri cac phan tu cua mang\n");
            } else {
                char another_choice;
                int value;
                printf("a. Tim kiem tuyen tinh\n");
                printf("b. Tim kiem nhi phan\n");
                printf("Nhap lua chon cua ban: ");
                scanf(" %c", &another_choice);
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                if (another_choice == 'a') {
                    int found = 0;
                    for (int i = 0; i < size; i++) {
                        if (arr[i] == value) {
                            printf("Tim thay gia tri %d tai vi tri %d\n", value, i + 1);
                            found = 1;
                            break;
                        }
                    }
                    if (!found) {
                        printf("Khong tim thay gia tri %d\n", value);
                    }
                } else if (another_choice == 'b') {
                    sort_tang(arr, size);
                    if (binarySearch(arr, size, value)) {
                        printf("Tim thay gia tri %d\n", value);
                    } else {
                        printf("Khong tim thay gia tri %d\n", value);
                    }
                } else {
                    printf("Lua chon khong hop le\n");
                }
            }
            break;
        case 8:
            printf("Thoat chuong trinh\n");
            return 0;
        default:
            printf("Lua chon khong hop le\n");
            break;
        }
    }
    return 0;
}