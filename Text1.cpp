#include <stdio.h>

// Ham kiem tra so nguyen to
int num {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

int main() {
    int arr[100], n = 0, choice, value, index;

    do {
        // Hien thi menu
        printf("       MENU    ");
        printf("1. Nhap so phan tu can nhap va gia tri cac phan tu\n");
        printf("2. In ra gia tri cac phan tu dang quan ly\n");
        printf("3. In ra gia tri lon nhat cua mang\n");
        printf("4. In ra cac phan tu la so nguyen to trong mang\n");
        printf("5. Them mot phan tu vao trong mang\n");
        printf("6. Xoa mot phan tu trong mang\n");
        printf("7. Sap xep mang theo thu tu tang dan\n");
        printf("8. Tim kiem phan tu (nguoi dung nhap) va in ra vi tri index cua phan tu do\n");
        printf("9. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // Nhap so phan tu va gia tri cac phan tu
                printf("Nhap so phan tu: ");
                scanf("%d", &n);
                for (int i = 0; i < n; i++) {
                    printf("Nhap gia tri phan tu %d: ", i + 1);
                    scanf("%d", &arr[i]);
                }
                break;

            case 2: // In ra gia tri cac phan tu dang quan ly
                printf("Cac gia tri trong mang: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 3: // In ra gia tri lon nhat cua mang
                if (n == 0) {
                    printf("Mang trong!\n");
                } else {
                    int max = arr[0];
                    for (int i = 1; i < n; i++) {
                        if (arr[i] > max) max = arr[i];
                    }
                    printf("Gia tri lon nhat trong mang la: %d\n", max);
                }
                break;

            case 4: // In ra cac phan tu la so nguyen to trong mang
                printf("Cac so nguyen to trong mang: ");
                for (int i = 0; i < n; i++) {
                    if (num (arr[i])) {
                        printf("%d ", arr[i]);
                    }
                }
                printf("\n");
                break;

            case 5: // Them mot phan tu vao trong mang
                if (n >= 100) {
                    printf("Mang da day, khong the them phan tu!\n");
                } else {
                    printf("Nhap phan tu can them: ");
                    scanf("%d", &value);
                    arr[n] = value;
                    n++;
                    printf("Phan tu da duoc them!\n");
                }
                break;

            case 6: // Xoa mot phan tu trong mang
                printf("Nhap vi tri phan tu muon xoa (tu 0 den %d): ", n - 1);
                scanf("%d", &index);
                if (index < 0 || index >= n) {
                    printf("Vi tri khong hop le!\n");
                } else {
                    for (int i = index; i < n - 1; i++) {
                        arr[i] = arr[i + 1];
                    }
                    n--;
                    printf("Phan tu da duoc xoa!\n");
                }
                break;

            case 7: // Sap xep mang theo thu tu tang dan
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Mang sau khi sap xep tang dan: ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", arr[i]);
                }
                printf("\n");
                break;

            case 8: // Tim kiem phan tu va in ra vi tri index cua phan tu do
                printf("Nhap gia tri can tim: ");
                scanf("%d", &value);
                int found = 0;
                for (int i = 0; i < n; i++) {
                    if (arr[i] == value) {
                        printf("Phan tu %d co vi tri index %d\n", value, i);
                        found = 1;
                    }
                }
                if (!found) {
                    printf("Khong tim thay phan tu %d trong mang!\n", value);
                }
                break;

            case 9 : 
                printf("Thoat chuong trinh!\n");
                break;
            
            
        }
        
            
    } while (choice != 9);

    return 0;
}

