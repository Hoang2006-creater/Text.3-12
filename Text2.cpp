#include <stdio.h>

int main() {
    int arr[100][100], n, choice, value;

    do {
        printf("\n--- MENU ---\n");
        printf("1. Nhap kich co va gia tri cac phan tu cua ma tran\n");
        printf("2. In ra gia tri cac phan tu cua ma tran theo ma tran\n");
        printf("3. In ra cac phan tu tren duong bien va tinh tich\n");
        printf("4. In ra cac phan tu tren duong cheo chinh\n");
        printf("5. In ra cac phan tu tren duong cheo phu\n");
        printf("6. Sap xep duong cheo chinh theo thu tu tang dan\n");
        printf("7. Tim kiem mot phan tu va in ra vi tri cua phan tu do\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Nhap kich co va gia tri cac phan tu cua ma tran
                printf("Nhap kich co ma tran: ");
                scanf("%d", &n);
                printf("Nhap gia tri cua cac phan tu cua ma tran:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("Nhap gia tri phan tu [%d][%d]: ", i, j);
                        scanf("%d", &arr[i][j]);
                    }
                }
                break;

            case 2: // In ra gia tri cac phan tu cua ma tran
                printf("Ma tran:\n");
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        printf("%d ", arr[i][j]);
                    }
                    printf("\n");
                }
                break;

            case 3: // In ra cac phan tu tren duong bien va tinh tich
                {
                    int product = 1;
                    printf("Cac phan tu tren duong bien: ");
                    for (int i = 0; i < n; i++) {
                        for (int j = 0; j < n; j++) {
                            if (i == 0 || i == n - 1 || j == 0 || j == n - 1) {
                                printf("%d ", arr[i][j]);
                                product *= arr[i][j];
                            }
                        }
                    }
                    printf("\nTich cua cac phan tu tren duong bien: %d\n", product);
                }
                break;

            case 4: // In ra cac phan tu tren duong cheo chinh
                printf("Cac phan tu tren duong cheo chinh: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i][i]);
                }
                printf("\n");
                break;

            case 5: // In ra cac phan tu tren duong cheo phu
                printf("Cac phan tu tren duong cheo phu: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i][n - i - 1]);
                }
                printf("\n");
                break;

            case 6: // Sap xep duong cheo chinh theo thu tu tang dan
                {
                    int temp;
                    // Sap xep duong cheo chinh theo thu tu tang dan
                    for (int i = 0; i < n - 1; i++) {
                        for (int j = i + 1; j < n; j++) {
                            if (arr[i][i] > arr[j][j]) {
                                // Hoan doi gia tri
                                temp = arr[i][i];
                                arr[i][i] = arr[j][j];
                                arr[j][j] = temp;
                            }
                        }
                    }
                    printf("Duong cheo chinh sau khi sap xep: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", arr[i][i]);
                    }
                    printf("\n");
                }
                break;

            case 7: // Tim kiem mot phan tu va in ra vi tri cua phan tu do
                printf("Nhap phan tu can tim: ");
                scanf("%d", &value);
                int found = 0;
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        if (arr[i][j] == value) {
                            printf("Phan tu %d co vi tri: [%d][%d]\n", value, i, j);
                            found = 1;
                        }
                    }
                }
                if (!found) {
                    printf("Khong tim thay phan tu %d trong ma tran!\n", value);
                }
                break;

            case 8: // Thoat
                printf("Thoat chuong trinh!\n");
                break;

            default: // Lua chon khong hop le
                printf("Lua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    } while (choice != 8);

    return 0;
}

