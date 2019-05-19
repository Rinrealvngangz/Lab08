
void XuatMenu();
int ChonMenu(int soMenu);
void XuLyMenu(int menu, BangDiemSV a[MAX], int &n);

void XuatMenu()
{
	cout << "\n=======================HE THONG CHUC NANG=======================";
	cout << "\n0. Thoat chuong trinh";
	cout << "\n1. Tao bang diem sinh vien";
	cout << "\n2. Xem bang diem sinh vien";
	cout << "\n3. Xem bang diem day du";
	cout << "\n4. Xuat bang diem sinh vien theo tung lop";
	cout << "\n5. Sap bang diem sinh vien giam dan theo diem trung binh";
	cout << "\n6. Sap xep va xuat bang diem tang dan theo ho ten, neu trung, sap tang theo ma sinh vien";
	cout << "\n7. Tim va xuat thong tin cua sinh vien co ten cho truoc";
	cout << "\n8. Tim va xuat thong tin cua cac sinh vien co diem trung binh cao nhat";
	cout << "\n9. Xep loai hoc luc cua sinh vien dua vao diem trung binh";
	cout << "\n================================================================";
	cout << "\n(Du lieu da duoc khoi tao san, nhan 1 de tao lai bo du lieu moi)";
	cout << "\n================================================================";
}

int ChonMenu(int soMenu)
{
	int stt;
	for (;;)
	{
		system("CLS");
		XuatMenu();
		cout << "\nNhap 1 so trong khoang [0,...," << soMenu << "] de chon chuc nang, stt = ";
		cin >> stt;
		if (0 <= stt && stt <= soMenu)
			break;
	}
	return stt;
}

void XuLyMenu(int menu, BangDiemSV a[MAX], int &n)
{
	BangDiemSV p;
	switch (menu)
	{
	case 0:
		system("CLS");
		cout << "\nThoat khoi chuong trinh\n";
		break;
	case 1:
		system("CLS");
		cout << "\n1. Tao bang diem sinh vien\n";
		NhapDanhsachSV(a, n);
		system("CLS");
		XuatDSSV(a, n);
		break;
	case 2:
		system("CLS");
		cout << "\n2. Xem bang diem sinh vien";
		XuatDSSV(a, n);
		cout << "\nSo luong sinh vien: =" << n;
		break;
	case 3:
		system("CLS");
		cout << "\n3. Xem bang diem day du\n";
		/*cout << "\nSinh vien can chen:";
		nhap1SV(p);
		system("CLS");
		them1SV_cuoi(a, n, p);*/
		cout << "\nXem bang diem day du";
		XuatDSSV(a, n);
		break;
	case 4:
		system("CLS");
		cout << "\n4. Xuat bang diem sinh vien theo tung lop\n";
		xuat_tunglop(a, n);
		break;
	case 5:
		system("CLS");
		cout << "\n5. Sap bang diem sinh vien giam dan theo diem trung binh\n";
		sapxep_diemTB(a, n);
		cout << "\nBang diem giam theo TB:";
		XuatDSSV(a, n);
		break;
	case 6:
		system("CLS");
		cout << "\n6. Sap xep va xuat bang diem tang dan theo ho ten, neu trung, sap tang theo ma sinh vien\n";
		cout << "\nBang diem sau khi sap xep :";
		sapxep_ten_MSV_tang(a, n);

		XuatDSSV(a, n);
		break;
	case 7:
		char HoTen[25];
		system("CLS");
		cout << "\n7. Tim va xuat thong tin cua sinh vien co ten cho truoc\n";
		cout << "\nNhap ten Sinh vien tim kiem:";
		gets_s(HoTen, 25);
		_flushall();
		gets_s( HoTen,25);
		timkiemSV(a, n, HoTen);
		
		break;
	case 8:
		system("CLS");
		cout << "\n8. Tim va xuat thong tin cua cac sinh vien co diem trung binh cao nhat\n";
		timkiemSV_diemTB_caonhat(a, n);

		
		break;
	case 9:
		system("CLS");
		cout << "\n9. Xep loai hoc luc cua sinh vien dua vao diem trung binh\n";
		xephocluc(a, n);
		XuatDSSV(a,n);
		break;
	}
	_getch();
}



