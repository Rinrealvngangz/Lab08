#define MAX 100
#define NGANGDOI '='
#define	NGANGDON '-'

typedef unsigned short int Byte;

struct NgayThangNam
{
	Byte ngaySinh;
	Byte thangSinh;
	unsigned int namSinh;
};

struct Nhanvien
{
	char maNV[8];
	char hoLot[21];
	char ten[8];
	NgayThangNam ntns;
	char diachi[21];
	double luong;
};
	
void Nhap_1NV(Nhanvien&p)
{
	cout << "\nMa Nhan Vien (dung 7 ky so) :";
	_flushall();
	gets_s(p.maNV, 8);

	cout << "\nHo va chu lot:";
	_flushall();
	gets_s(p.diachi, 21);

	cout << "\nTen nhan vien: ";
	_flushall();
	gets_s(p.ten, 7);

		cout << "\nNgay sinh: ";
	_flushall();
	cin >> p.ntns.ngaySinh;
	
	cout << "\nThang sinh: ";
	_flushall();
	cin >> p.ntns.thangSinh;
	cout << "\nNam sinh: ";
	_flushall();
	cin >> p.ntns.namSinh;

	cout << "\n Dia chi: ";
	_flushall();
	gets_s(p.diachi, 20);

	cout << "\nNhap Dia chi: ";
	_flushall();
	cin >> p.luong;
}

void Nhap_DSNV(Nhanvien a[MAX], int &n)
{
	int i;
	cout << "\nNhap n:=";
	cin >> n;
	for (i = 0; i < n; i++)
	{
		system("CLS");
		cout << "\nNhap thong tin nhan vien thu " << i + 1 << ":";
		Nhap_1NV(a[i]);
	}
}

void XuatKengang()
{
	int i;
	cout << "\n";
		cout << setiosflags(ios::left)
		<< '.';
		for (i = 1; i <= 76; i++)
			cout << NGANGDOI;
		cout << '.';
}
void Xuattieude()
{
	XuatKengang();
	cout << endl;
	cout << setiosflags(ios::left)
		<< '.'
		<< setw(8) << "Ma NV"
	    << '.'
		<< setw(16) << "Ho"
		<< setw(8) << "Ten"
		<< ':'
		<< setw(12) << "NTN sinh"
		<< ':'
		<< setw(16) << "Dia Chi"
		<< ':'
		<< setw(12) << "Luong"
		<< ':';
	XuatKengang();
}
void Xuat_1NV(Nhanvien p)
{
	cout << setiosflags(ios::left)
		<< '.'
		<< setw(8) << p.maNV
		<< setw(16) <<p.hoLot
		<< setw(8)<<p.ten
		<< ':'
		<< setw(2) << p.ntns.ngaySinh
		<< '/'
		<< setw(2) << p.ntns.thangSinh
		<< '/'
		<< setw(6) << p.ntns.namSinh
		<< ':'
		<< setw(16) << p.diachi
		<< ':'
		<< setw(12) << setiosflags(ios::fixed) << setprecision(2) << p.luong
		<< ':';
}
void Xuat_DSNV(Nhanvien a[MAX], int n)
{
	int i;
	Xuattieude();
	for (i = 0; i < n; i++)
	{
		cout << endl;
		Xuat_1NV(a[i]);
	}
	XuatKengang();
}

void ThemNhanVien_Cuoi(Nhanvien a[MAX], int &n, Nhanvien p)
{
	a[n++] = p;
}

void XoaNhanVien_MaNV(Nhanvien a[MAX], int &n, char maNV[8])
{
	int i, j;
	for (i = 0; i < n; i++)
	if (strcmp(a[i].maNV, maNV) == 0)
		break;
	if (i == n)
	{
		cout << "\nKhong co nhan vien nao trong danh sach co ma so " << maNV;
		return;
	}
	for (j = i + 1; j < n; j++)
		a[j - 1] = a[j];
	n--;
}

void SuaNhanVien_MaNV(Nhanvien a[MAX], int &n, char maNV[8])
{
	int i;
	char tl;
	for (i = 0; i < n; i++)
	if (strcmp(a[i].maNV, maNV) == 0)
		break;
	if (i == n)
	{
		cout << "\nKhong co nhan vien nao trong danh sach co ma so " << maNV;
		return;
	}
	cout << "\nSua thong tin nhan vien co ma so : " << maNV;
	cout << "\nCo sua ma nhan vien khong ? nhan k neu khong: ";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nMa Nhan Vien : ";
		_flushall();
		gets_s(a[i].maNV, 8);
	}
	cout << "\nCo sua ho va chu lot khong ? nhan k neu khong: ";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nHo va chu lot: ";
		_flushall();
		gets_s(a[i].hoLot, 21);
	}
	cout << "\nCo sua ten khong ? nhan k neu khong: ";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nTen nhan vien: ";
		_flushall();
		gets_s(a[i].ten, 8);
	}
	cout << "\nCo sua ngay sinh khong ? nhan k neu khong: ";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nNgay sinh: ";
		_flushall();
		cin >> a[i].ntns.ngaySinh;
	}
	cout << "\nCo sua thang sinh khong ? nhan k neu khong: ";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nThang sinh: ";
		_flushall();
		cin >> a[i].ntns.thangSinh;
	}
	cout << "\nCo sua nam sinh khong ? nhan k neu khong: ";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nNam sinh: ";
		_flushall();
		cin >> a[i].ntns.namSinh;
	}
	cout << "\nCo sua dia chi khong ? nhan k neu khong: ";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nNhap dia chi: ";
		_flushall();
		gets_s(a[i].diachi, 20);
	}
	cout << "\nCo sua luong khong ? nhan k neu khong: ";
	tl = _getch();
	if (tl != 'k' && tl != 'K')
	{
		cout << "\nNhap luong: ";
		_flushall();
		cin >> a[i].luong;
	}
}

int TimNhanVien_MaNV(Nhanvien a[MAX], int n, char maNV[8])
{
	int i, kq = -1;
	for (i = 0; i < n; i++)
	if (strcmp(a[i].maNV, maNV) == 0)
	{
		kq = i;
		break;
	}
	return kq;
}

void TimNhanVien_Ten(Nhanvien a[MAX], int n, char ten[7])
{
	int i, dem = 0;
	for (i = 0; i < n; i++)
	if (_strcmpi(a[i].ten, ten) == 0)
		dem++;
	if (!dem)
		cout << "\nTrong danh sach khong co nhan vien nao co ten la " << ten;
	else
	{
		cout << "\nCo " << dem << " nhan vien ten " << ten
			<< ", voi thong tin chi tiet nhu sau :\n";
		Xuattieude();
		for (i = 0; i < n; i++)
		if (_strcmpi(a[i].ten, ten) == 0)
		{
			cout << endl;
			Xuat_1NV(a[i]);
		}
		XuatKengang();
	}
}
void HoanVi(Nhanvien &p, Nhanvien &q)
{
	Nhanvien t;
	t = p;
	p = q;
	q = t;
}
void SapTang_MaNV(Nhanvien a[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	for (j = i + 1; j < n; j++)
	if (_strcmpi(a[i].maNV, a[j].maNV)> 0)
		HoanVi(a[i], a[j]);
}



void SapTang_Ten_Ho_Luong(Nhanvien a[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	for (j = i + 1; j < n; j++)
	if (_strcmpi(a[i].ten, a[j].ten)> 0)
		HoanVi(a[i], a[j]);
	for (i = 0; i < n - 1; i++)
	for (j = i + 1; j < n; j++)
	if (_strcmpi(a[i].ten, a[j].ten) == 0)
	if (_strcmpi(a[i].hoLot, a[j].hoLot) > 0)
		HoanVi(a[i], a[j]);
	for (i = 0; i < n - 1; i++)
	for (j = i + 1; j < n; j++)
	if (_strcmpi(a[i].ten, a[j].ten) == 0 && _strcmpi(a[i].hoLot, a[j].hoLot) == 0)
	if (a[i].luong > a[j].luong)
		HoanVi(a[i], a[j]);
}

double TinhTongLuong(Nhanvien a[MAX], int n)
{
	int i;
	double tong = 0;
	for (i = 0; i < n; i++)
		tong += a[i].luong;
	return tong;
}

void Xuat_DSNV_Luong_KhongNhoHon_x(Nhanvien a[MAX], int n, double x)
{
	int i, kq = 0;
	for (i = 0; i < n; i++)
	if (a[i].luong >= x)
		kq++;
	if (!kq)
		cout << "\nKhong co nhan vien nao co luong >= " << x;
	else
	{
		cout << "\n\nCo " << kq << " nhan vien co luong >= " << x
			<< ", voi thong tin chi tiet nhu sau:";
		Xuattieude();
		for (i = 0; i < n; i++)
		{
			if (a[i].luong >= x)
			{
				cout << endl;
				Xuat_1NV(a[i]);
			}
		}
		XuatKengang();
	}
}

void Xuat_DSNV_NamSinh_u_v(Nhanvien a[MAX], int n, unsigned int u, unsigned int v)
{
	int i, kq = 0;
	for (i = 0; i < n; i++)
	if (u <= a[i].ntns.namSinh && a[i].ntns.namSinh <= v)
		kq++;
	if (!kq)
		cout << "\nKhong co nhan vien nao co nam sinh trong khoang [" << u << ", " << v << "]";
	else
	{
		cout << "\n\nCo " << kq << " nhan vien co nam sinh trong khoang [" << u
			<< ",..," << v << "] : ";
		Xuattieude();
		for (i = 0; i < n; i++)
		{
			if (u <= a[i].ntns.namSinh && a[i].ntns.namSinh <= v)
			{
				cout << endl;
				Xuat_1NV(a[i]);
			}
		}
		XuatKengang();
	}
}