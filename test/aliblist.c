#include "aliblist.h"
#include <stdio.h>
#include <stdlib.h>

int insertList(ElementType x, Position p, List *L)
{
    if (L->Last >= MaxLength - 1 || p < 0 || p > L->Last + 1) // kiem tra vi tri chen co hop le khong
    {
        return 0;
    }
    for (int i = L->Last; i >= p; i--)
    {
        L->Element[i + 1] = L->Element[i]; // dich phai cac phan tu tu vi tri p den Last
    }
    L->Element[p] = x;
    L->Last++;
    return 1;
}
void MakeNullList(List *L)
{
    L->Last = 0;
}
int emptyList(List *L)
{
    return L->Last == 0; // tra ve 1 neu danh sach rong, nguoc lai tra ve 0
}
Position nextList(Position p, List *L)
{
    if (p < 0 || p >= L->Last)
    {
        return -1; // vi tri khong hop le
    }
    return p + 1; // tra ve vi tri tiep theo
}
Position previousList(Position p, List *L)
{
    if (p <= 0 || p > L->Last)
    {
        return -1; // vi tri khong hop le do nam ngoai khoang [0, Last]
    }
    return p - 1; // tra ve vi tri truoc do
}
Position firstList(List *L)
{
    if (emptyList(L))
    {
        return -1; // danh sach rong, khong co phan tu dau tien
    }
    return 0; // tra ve vi tri dau tien
}
Position endList(List *L)
{
    if (emptyList(L))
    {
        return -1; // danh sach rong, khong co phan tu cuoi cung
    }
    return L->Last; // tra ve vi tri cuoi cung
}
ElementType retrieveList(Position p, List *L)
{
    if (p < 0 || p > L->Last)
    {
        printf("Vi tri khong hop le.\n");
        exit(1); // ket thuc chuong trinh neu vi tri khong hop le
    }
    return L->Element[p]; // tra ve phan tu tai vi tri p
}
int deleteList(Position p, List *L)
{
    if (p < 0 || p > L->Last || emptyList(L)) // kiem tra vi tri xoa co nam trong khoang hop le
    {
        return 0;
    }
    for (int i = p; i < L->Last; i++)
    {
        L->Element[i] = L->Element[i + 1]; // dich trai cac phan tu tu vi tri p den Last
    }
    L->Last--; // giam so luong phan tu trong danh sach
    return 1;  // tra ve 1 neu xoa thanh cong
}
Position locatelist(ElementType x, List *L)
{
    for (Position i = 0; i <= L->Last; i++)
    {
        if (L->Element[i] == x) // kiem tra tung phan tu trong danh sach
        {
            return i; // tra ve vi tri cua phan tu x neu tim thay
        }
    }
    return -1; // tra ve -1 neu khong tim thay phan tu x
}
void printList(List *L)
{
    if (emptyList(L))
    {
        printf("Danh sach rong.\n");
        return; // neu danh sach rong, in thong bao va ket thuc ham
    }
    printf("Danh sach hien tai: ");
    for (Position i = 0; i < L->Last; i++)
    {
        printf("%d ", L->Element[i]); // in tung phan tu trong danh sach
    }
    printf("\n");
}
void fullList(List *L)
{
    if (L->Last >= MaxLength - 1) // kiem tra xem danh sach da day chua
    {
        printf("Danh sach da day.\n");
    }
    else
    {
        printf("Danh sach chua day, co the them phan tu.\n");
    }
}

