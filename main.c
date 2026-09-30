#include <stdio.h>
#include <string.h>

#define MAX_PHIEU 50

int main() {
    char maPhieu[MAX_PHIEU][20] = {"PM101", "PM102", "PM103"};
    int ngayQuaHan[MAX_PHIEU] = {0, 3, 5};
    int soLuong = 3;

    int luachon;

    do {
        printf("\n--- HE THONG QUAN LY MUON TRA SACH (LIBRARY_WMS) ---\n");
        printf("1. Xem danh sach phieu muon\n");
        printf("2. Them moi phieu muon\n");
        printf("3. Cap nhat so ngay qua han\n");
        printf("0. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &luachon);

        while (getchar() != '\n');

        switch (luachon) {
            case 1: {
                printf("\n--- DANH SACH PHIEU MUON SACH ---\n");
                printf("STT | Ma Phieu | So Ngay Qua Han | Tien Phat (VND)\n");
                printf("--------------------------------------------------\n");

                for (int i = 0; i < soLuong; i++) {
                    long tienPhat = (long)ngayQuaHan[i] * 5000;
                    printf("%-3d | %-8s | %d ngay         | %ld VND\n", 
                           i + 1, maPhieu[i], ngayQuaHan[i], tienPhat);
                }

                printf("--------------------------------------------------\n");
                printf("Tong so phieu: %d\n", soLuong);
                break;
            }

            case 2: {
                if (soLuong >= MAX_PHIEU) {
                    printf("Loi: Danh sach phieu muon da day, khong the them!\n");
                } else {
                    printf("Nhap ma phieu muon moi: ");
                    scanf("%19s", maPhieu[soLuong]);
                    while (getchar() != '\n'); 

                    ngayQuaHan[soLuong] = 0; 
                    soLuong++;
                    printf("Them phieu muon thanh cong!\n");
                }
                break;
            }

            case 3: {
                char maTimKiem[20];
                printf("Nhap ma phieu muon can cap nhat: ");
                scanf("%19s", maTimKiem);
                while (getchar() != '\n');

                int viTri = -1;
                for (int i = 0; i < soLuong; i++) {
                    if (strcmp(maPhieu[i], maTimKiem) == 0) {
                        viTri = i;
                        break;
                    }
                }

                if (viTri != -1) {
                    printf("Tim thay phieu muon '%s' tai vi tri index %d.\n", maTimKiem, viTri);
                    int ngayMoi;
                    do {
                        printf("Nhap so ngay qua han moi: ");
                        scanf("%d", &ngayMoi);
                        while (getchar() != '\n');

                        if (ngayMoi < 0) {
                            printf("Loi: So ngay qua han phai la so nguyen khong am (>= 0). Vui long nhap lai!\n");
                        }
                    } while (ngayMoi < 0);

                    ngayQuaHan[viTri] = ngayMoi;
                    printf("Cap nhat thanh cong! So ngay qua han moi cua %s la %d ngay.\n", maTimKiem, ngayMoi);
                } else {
                    printf("Khong tim thay ma phieu muon '%s' trong he thong!\n", maTimKiem);
                }
                break;
            }

            case 0:
                printf("Cam on ban da su dung he thong. Tam biet!\n");
                break;

            default:
                printf("Lua chon khong hop le. Vui long chon lai tu 0 den 3!\n");
                break;
        }

    } while (luachon != 0);

    return 0;
}