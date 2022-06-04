//=============LÝ THUYẾT============
// 
// 1. struct là gì ?
//2. cú pháp khai báo 1 struct ?
//3. Đặt khai báo struct dưới hàm main được không ? vì sao ?
//4. dòng typedef có chức năng gì ? tối ưu việc gì ?
//5. khi nào dùng sao chép bằng toán tử gán khi nào dùng gán lần lượt ? vì sao ?
//6. biến kdl struct có cần tham chiếu khi cập nhật giá trị thay đổi trong hàm không ?
//7. Nếu trong cấu trúc mà có biến con trỏ thì ta nên chú ý việc gì(đáp án gồm 3 ý - cố gắng trả lời đủ 3)
//8. struct dễ không ?
// 
// 
// Giải 
// 1.struct là cấu trúc dữ liệu do người dùng tự định nghĩa và không cso kiểu trả về ở kiểu dữ liệu này ta có thể nồng các kiểu dữ liệu char , int , float với nhau mà không có lỗi
// 
// 2.cú pháp 
// struct ten_bien
// {
//	type 1;
//	tyep 2;
//	...;
// };
// typefef struct ten_bien ten_bien_moi ; // đặt tên lại biến struct cho gọn
// 
// 3. Không đặt được vì struct đặt dưới hàm main sẽ không thể tham trị được vì vậy nó sẽ bắt buộc phải để trên để có thể gọi vào hàm main ;
// 
// 4. Dòng typedef có chức năng định nghĩa lại tên gọi trong biên dịch , nó tối ưu việc gọi hàm gọi biến hơn khi ta đặt tên hàm biến ngắn gọn hơn
// 
// 
// 5. Nếu dùng toán tử gán thì trong struct không được có con trỏ , gán lần lượt khi có con trỏ trong struct
// 
// 6 KHông cần tham chiếu vì ở đây dùng con trỏ sẽ tự động trở tới địa chỉ của giá trị ben trong 
// 
// 7.Nếu trong cấu trúc có biến con trỏ ta cần chú ý gán từng phần;
// 
// 8. struct bình thường
// 
//

#include <iostream>
#include <fstream>
using namespace std;
// struct PHANSO
struct PHANSO
{
	int tu = 0;
	int mau = 0;
};
typedef struct PHANSO ps;
void nhap_ps(ps a[], int n);
void xuat_ps(ps a[], int n);
void ucln(ps a[], int n);
void ps_max(ps a[], int n);
void xoa_ps(ps a[], int& n);
void them_ps(ps a[], int& n);
void tong_ps(ps a[], int n);
ostream& operator << (ostream& os, ps a);
istream& operator >> (istream& is, ps a /*nhập cho ai */);
// struct SINH VIEN 
struct SINHVIEN
{
	char  masv[20] = " ";
	char hoten[30]= " ";
	float ktlt=0, ctdl=0, trr = 0;
};
typedef struct SINHVIEN sv;
void sx_sv(sv a[], int n);
void xuat_sv(sv a[], int n);
void nhap_sv(sv a[], int n);

int i = 0;
// hàm main 
int main()
{
	// ================NHAP PHAN SO ==============
	int n = 0;
	ps a;
	cin >> a;
	cout << a;
	/*do
	{
		cout << "\n nhap gia tri n : "; cin >> n;
		if (n < 0)
		{
			cout << "\n hay nhap gia tri n lon hon 0";
		}
	} while (n < 0);
	
	ps a[50];
	nhap_ps(a, n);
	ucln(a, n);
	xuat_ps(a, n);
	ps_max(a, n);
	them_ps(a, n);
	xuat_ps(a, n);
	xoa_ps(a, n);
	xuat_ps(a, n);*/

	// ================NHAP SINH VIEN ==============
	/*do
	{
		cout << "\n Nhap gia tri n sinh vien : "; cin >> n;
		if (n < 0)
		{
			cout << "\n Hay nhap gia tri n lon hon 0";
		}
	} while (n < 0);
	sv student[50];
	nhap_sv(student, n);
	xuat_sv(student, n);
	sx_sv(student, n);
	xuat_sv(student, n);*/
	
}// KẾT THÚC HÀM MAIN




//NẠP CHỐNG TOÁN TỬ 

istream& operator >> (istream &is, ps a /*nhập cho ai */)
{
	// Nhâp ntn  ?
	//nạp chồng toán tử cho mảng
		cout << "\nNhap tu so thu " << " : ";
			is >> a.tu;
			do
				{
				cout << "\nNhap mau so thu " << " : ";
				is >> a.mau;
				if (a.mau == 0)
				{
					cout << "Hay nhap mau so khac 0 " << endl;
				}
			} while (a.mau == 0);
	return is;
}

ostream& operator << (ostream &os, ps a)
{
	if (a.mau == 1)
	{
		os << "PHANSO thu " << " la : " << a.tu << endl;
	}
	else
	{
		os << "PHANSO thu " << " la : " << a.tu << "/" << a.mau << endl;
	}
	return os;
	
}
// HÀM CHO PHAN SO 

void nhap_ps(ps a[], int n)
{
	cout << "\n\t\t==============NHAP===============" << endl;
	for (i = 0; i < n; i++)
	{
			cout << "\nNhap tu so thu " << i << " : ";
			cin >> a[i].tu;
		do
		{
			cout << "\nNhap mau so thu " << i << " : ";
			cin >> a[i].mau;
			if (a[i].mau < 0)
			{
				cout << "Hay nhap mau so khac 0 " << endl;
			}
		} while (a[i].mau == 0);
	}
}
void xuat_ps(ps a[], int n)
{
	cout << "\n\t\t==============XUAT===============" << endl;
	for (i = 0; i < n; i++)
	{
		if (a[i].mau == 1)
		{
			cout << "PHANSO thu "  << i << " la : " << a[i].tu << endl;
			continue;
		}
		cout << "PHANSO thu " << i << " la : " << a[i].tu << "/" << a[i].mau << endl;
	}
}
void ucln(ps a[], int n)
{
	for (i = 0; i < n; i++)
	{
		int max = 0, min = 0;
		if (a[i].mau > a[i].tu)	{
			max = a[i].mau;
			min = a[i].tu;
		}
		else{
			max = a[i].tu;
			min = a[i].mau;
		}
		for (int j = min; j >1; j--)
		{
			if ((max % j == 0) && (min % j == 0))
			{
				a[i].mau /= j;
				a[i].tu /= j;
				break;
			}
		}
	}
}
void ps_max(ps a[], int n)
{
	float psmax = 0,temp = 0; 
	int kt = 0;
	for (i = 0; i < n; i++)
	{
		temp = float(a[i].tu / a[i].mau);
		if (psmax <  temp)
		{
			psmax = temp;
			kt = i;
		}
	}
	cout << "\nPHAN SO MAX LA  : " << a[kt].tu << "/" << a[kt].mau;
}
void tong_ps(ps a[], int n)
{
	float temp =0 , tong= 0;
	for (i = 0; i < n; i++)
	{
		temp = float(a[i].tu / a[i].mau);
		tong = temp + tong; 
	}
	cout << "\nTong phan so la : " << tong;
}
void them_ps(ps a[], int &n)
{
	int tu; cout << "\nNhap tu can them : "; cin >> tu;
	int mau; cout << "\nNhap mau can them : "; cin >> mau;
	int vitri; cout << "\nNhap vi tri can them : "; cin >> vitri;
	for (int i = n; i > vitri; i--)
	{
		a[i].tu = a[i - 1].tu;
		a[i].mau = a[i - 1].mau;
	}
	a[vitri].tu = tu;
	a[vitri].mau = mau;
	n++;
}
void xoa_ps(ps a[], int &n)
{
	int vitri; cout << "\nNhap vi tri can xoa : "; cin >> vitri;
	for (int i = vitri; i < n; i++)
	{
		a[i].tu = a[i + 1].tu;
		a[i].mau = a[i + 1].mau;
	}
	n--;
}
///////==========SINH VIEN===================

void nhap_sv(sv a[],int n)
{
	cout << "\n\t\t==============NHAP SINH VIEN===============" << endl;
	for (i = 0; i < n; i++)
	{
		while (getchar() != '\n');
		// Enter the name for student ;
			cout << "\nNhap ten sinh vien thu " << i << " : ";
			fgets(a[i].hoten, sizeof(a[i].hoten), stdin);
		// Enter the student code for student ;
			cout << "\nNhap ma so sinh vien thu " << i << " : ";
			fgets(a[i].masv, sizeof(a[i].masv), stdin);
		// Enter the point ctdl code for student ;
			do {
				cout << "\nNhap diem ctdl sinh vien thu " << i << " : ";
				cin >> a[i].ctdl;
			} while (a[i].ctdl < 0 && a[i].ctdl > 10);
		
		// Enter the point math code for student ;
			do {
				cout << "\nNhap diem toan roi rac sinh vien thu " << i << " : ";
				cin >> a[i].trr;
			} while (a[i].trr < 0 && a[i].trr > 10);
		// Enter the point ktll code for student ;
			do {
				cout << "\nNhap diem kien truc lap trinh sinh vien thu " << i << " : ";
				cin >> a[i].ktlt;
			} while (a[i].ktlt < 0 && a[i].ktlt > 10);
	}
}
void xuat_sv(sv a[], int n)
{
	cout << "\n\t\t==============XUAT SINH VIEN===============" << endl;
	for (i = 0; i < n; i++)
	{
		cout << "\nTen sinh vien : " << a[i].hoten;
		cout << "\nMa sinh vien : " << a[i].masv;
		cout << "\nDiem toan : " << a[i].trr;
		cout << "\nDiem kien truc lap trinh : " << a[i].ktlt;
		cout << "\nDiem ctdl : " << a[i].ctdl;
	}
}
void sx_sv(sv a[], int n)
{
	float tong,ss;
	for (i = 0; i < n - 1; i++)
	{
		tong = a[i].trr + a[i].ktlt + a[i].ctdl;
		for (int j = i + 1; j < n; j++)
		{
			ss = a[j].trr + a[j].ktlt + a[j].ctdl;
			if (tong < ss)
			{
				sv temp;
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		tong = (a[i].trr + a[i].ktlt + a[i].ctdl) / 3;
		if (tong > 9.8)
		{
			cout << "\nSinh vien " << a[i].hoten << " dat xuat sac ";
		}
		else if (tong >= 8)
		{
			cout << "\nSinh vien " << a[i].hoten << " dat loai gioi ";
		}
		else if(tong >= 6.5)
		{
			cout << "\nSinh vien " << a[i].hoten << " dat loai kha ";
		}
		else if (tong >= 4)
		{
			cout << "\nSinh vien " << a[i].hoten << " dat loai trung binh ";
		}
		else
		{
			cout << "\nSinh vien " << a[i].hoten << " dat loai yeu ";
		}
	}
}
void sv_acsii(sv a[], int n)
{

}