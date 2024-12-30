#include <stdio.h>
#include <math.h>

int arr[100][100];
int hang, cot;
void nhap_phan_tu() {
    printf("Nhap so hang: ");
    scanf("%d", &hang);
    printf("Nhap so cot: ");
    scanf("%d", &cot);
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void in_ma_tran() {
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

void in_goc_ma_tran(){
    printf("Cac phan tu o cac goc cua ma tran la:\n");
    printf("%d ", arr[0][0]);
    printf("%d \n", arr[0][cot - 1]);
    printf("%d ", arr[hang - 1][0]);
    printf("%d ", arr[hang - 1][cot - 1]);
    printf("\n");
}

void in_duong_bien_ma_tran() {
    printf("Cac phan tu nam tren duong bien cua ma tran la:\n");
    for (int j = 0; j < cot; j++) {
        printf("%d ", arr[0][j]);
    }
    for (int i = 1; i < hang - 1; i++) {
        printf("%d ", arr[i][cot - 1]);
    }
    if (hang > 1) {
        for (int j = cot - 1; j >= 0; j--) {
            printf("%d ", arr[hang - 1][j]);
        }
    }
    if (cot > 1) {
        for (int i = hang - 2; i > 0; i--) {
            printf("%d ", arr[i][0]);
        }
    }
    printf("\n");
}

void in_duong_cheo_ma_tran() {
    printf("Cac phan tu nam tren duong cheo chinh va duong cheo phu cua ma tran la:\n");
    for (int i = 0; i < hang; i++) {
        printf("%d ", arr[i][i]);
    }
    printf("\n");
    for (int i = 0; i < hang; i++) {
        printf("%d ", arr[i][cot - i - 1]);
    }
    printf("\n");
}

int la_so_nguyen_to(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

void in_so_nguyen_to_ma_tran() {
    printf("Cac phan tu la so nguyen to cua ma tran la:\n");
    for (int i = 0; i < hang; i++) {
        for (int j = 0; j < cot; j++) {
            if (la_so_nguyen_to(arr[i][j])) {
                printf("%d ", arr[i][j]);
            }
        }
    }
    printf("\n");
}

int main() {
    int choice;
    do {
        printf("\n==================================MENU===================================\n");
        printf("1. Nhap gia tri cac phan tu cua mang.\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran.\n");
        printf("3. In ra cac phan tu o goc theo ma tran.\n");
        printf("4. In ra cac phan tu nam tren duong bien theo ma tran.\n");
        printf("5. In ra cac phan tu nam tren duong cheo chinh va duong cheo phu theo ma tran.\n");
        printf("6. In ra cac phan tu la so nguyen to theo ma tran.\n");
        printf("7. Thoat MENU.\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: 
                nhap_phan_tu();
                break;

            case 2:
                in_ma_tran();
                break;

            case 3:
                in_goc_ma_tran();
                break;

            case 4:
                in_duong_bien_ma_tran();
                break;

            case 5:
                in_duong_cheo_ma_tran();
                break;

            case 6:
                in_so_nguyen_to_ma_tran();
                break;

            case 7:
                printf("Thoat MENU.\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long nhap lai!\n");
        }
    } while (choice != 7);

    return 0;
}
