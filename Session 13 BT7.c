#include <stdio.h>


void tao_ma_tran(int arr[100][100], int hang, int cot){
    printf("Nhap cac gia tri cho ma tran: \n");
    for(int i = 0; i < hang; i++){
        for(int j = 0; j < cot; j++){
            printf("arr[%d][%d]: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void in_ma_tran(int arr[100][100], int hang, int cot){
    printf("Ma tan vua nhap la: \n");
    for(int i = 0; i < hang; i++){
        for(int j = 0; j < cot; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}
int main(){
    
    int hang, cot, arr[100][100];
    printf("Nhap so hang: ");
    scanf("%d", &hang);
    printf("Nhap so cot: ");
    scanf("%d", &cot);
    if(hang <= 0 || cot <= 0 || hang > 100 || cot > 100){
        printf("Kich thuoc nhap khong hop le!!!");
    }
    
    tao_ma_tran(arr, hang, cot);
    in_ma_tran(arr, hang, cot);

    return 0;
}
