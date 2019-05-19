#define MAX 100
#define NGANGDOI '='
#define NGANGDON '-'

struct BangDiemSV
{
	
	char MaSV[9];
	char HoTen[25];
	unsigned int NamSinh;
	char Lop[10];
	double DiemTB;
	char XepLoai[5];
};

void nhap1SV(BangDiemSV &p)
{
	
	gets_s(p.MaSV);
	cout << "\nNhap Ma Sinh Vien(dung 8 ky so):";
	_flushall();
	gets_s(p.MaSV);
	cout << "\nNhap Ho ten:";
	_flushall();
	gets_s(p.HoTen, 25);
	cout << "\nNhap Nam Sinh:";
	_flushall();
	cin >> p.NamSinh;
	
	gets_s(p.MaSV);
	cout << "\nNhap Lop:";
	_flushall();
	gets_s(p.Lop, 10);
	cout << "\nNhap Diem TB:";
	_flushall();
	cin >> p.DiemTB;
	cout << "\nNhap Xep Loai:";
	_flushall();
	cin >> p.XepLoai;

}

void NhapDanhsachSV(BangDiemSV a[MAX],int &n)
{
	int i;
	cout << "\nNhap so luong sinh vien:";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		system("CLS");
		cout << "\nSinh vien thu " << i + 1;
		nhap1SV(a[i]);
	}
	
}

void Xuatkenang()
{
	int i;
	cout << "\n";
	cout << setiosflags(ios::left) << ':';
	for (i = 0; i <= 76; i++)

		cout << NGANGDOI;
	cout << ':';
		
}
void xuatkengangdon()
{
	int i;
	cout << "\n";
	cout << setiosflags(ios::left) << ':';
	for (i = 0; i <= 76; i++)

		cout << NGANGDON;
	cout << ':';
}
void Xuattieude()
{
	Xuatkenang();
	cout << endl;
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(10) << "Ma SV"
		<< ':'
		<< setw(28) << "Ho va Ten"
		<< ':'
		<< setw(10) << "Nam Sinh"
		<< ':'
		<< setw(8) << "Lop"
		<< ':'
		<< setw(8) << "Diem TB"
		<< ':'
		<< setw(5) << "Xep Loai"
     	<< ':';
		
}   

void Xuat_1SV(BangDiemSV p)
{
	
	cout << setiosflags(ios::left)
		<< ':'
		<< setw(10) << p.MaSV
		<< ':'
		<< setw(28) << p.HoTen
		<< ':'
		<< setw(10) << p.NamSinh
		<< ':'
		<< setw(8) << p.Lop
		<< ':'
		<< setw(8) << setiosflags(ios::fixed) << setprecision(1) << p.DiemTB
		<< ':'
		<< setw(5) << p.XepLoai
		<< "   :";
		
}
void XuatDSSV(BangDiemSV a[MAX], int n)
{
	int i;
	Xuattieude();
	Xuatkenang();
	for (i = 0; i < n; i++)
	{
		cout << endl;
		Xuat_1SV(a[i]);
		if ((i+1) % 5 == 0)
		
			xuatkengangdon();
		
	}
	Xuatkenang();
}
void them1SV_cuoi(BangDiemSV a[MAX], int &n, BangDiemSV p)
{

	
	a[n++] = p;
}

void xuat_tunglop(BangDiemSV a[MAX], int &n)
{

	int i, j, dau, m = 0, dem = 0;
	BangDiemSV b[MAX];
	int vt[MAX];
	for (i = 0; i<n; i++)
	{
		dau = 1;
		for (j = 0; j<m && dau; j++)
			dau = dau && (_strcmpi(a[i].Lop, b[j].Lop) != 0);
		if (dau)
		{
			strcpy_s(b[m++].Lop, MAX, a[i].Lop);
			vt[m] = i; //Mảng vt dùng để lưu vị trí các phần tử a[i].Lop phân biệt
			dem++; //Xác định có bao nhiêu lớp khác nhau
		}
	}
	m = 1;
	Xuattieude();
	while (m <= dem)
	{
		for (i = 0; i<n; i++)
		{
			if (_strcmpi(a[i].Lop, a[vt[m]].Lop) == 0)
			{
				cout << endl;
				Xuat_1SV(a[i]);
			}
		}
		if (m<dem) xuatkengangdon();//Ngăn cách các lớp bằng dòng kẻ ngang và không kẻ ở dòng cuối cùng
		m++;
	};
	Xuatkenang();
}

void hoanvi(BangDiemSV &p, BangDiemSV &q)
{
	BangDiemSV t;

	t = p;
	p = q;
	q = t;


}

void sapxep_diemTB(BangDiemSV a[MAX], int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	
		for (j = i + 1; j < n; j++)

		
			if ( a[i].DiemTB <a[j].DiemTB)
				hoanvi(a[i], a[j]);

		
	
}
void sapxep_ten_MSV_tang(BangDiemSV a[MAX], int n)
{
	int dk;
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)

			if (_strcmpi(a[i].HoTen, a[j].HoTen) > 0)
				hoanvi(a[i], a[j]);


	for (i = 0; i < n - 1; i++)
		for (j = i + 1; j < n; j++)
			
	if (_strcmpi(a[i].HoTen, a[j].HoTen) == 0)

		if (_strcmpi(a[i].MaSV, a[j].MaSV) > 0)
			hoanvi(a[i], a[j]);
	
}

void timkiemSV(BangDiemSV a[MAX], int n, char HoTen[25])
{
	int i;
	int dem = 0;

	for (i = 0; i < n; i++)
		if (_strcmpi(a[i].HoTen, HoTen) == 0)
			dem++;
	if (!dem)
		cout << "\nTrong danh sach khong co Sinh Vien ten la " << HoTen;
	else
	{
		cout << "\nCo " << dem << " sinh vien ten la " << HoTen
			<< " voi thong tin chi tiet nhu sau:";
		Xuattieude();
		Xuatkenang();
		for (i = 0; i < n; i++)
			if (_strcmpi(a[i].HoTen, HoTen) == 0)
			{
				cout << endl;
				Xuat_1SV(a[i]);
			}
		Xuatkenang();
	}

}
void timkiemSV_diemTB_caonhat(BangDiemSV a[MAX], int n)
{
	int i;
	int dem = 0;
	int max;
	max = a[0].DiemTB;

	for (i = 0; i < n; i++)
	
		if (max <= a[i].DiemTB)

			max = a[i].DiemTB;
		dem++;
	

	if (dem)
	{
		cout <<"\nCo "<<dem+1<< " sinh vien diem cao nhat voi thong tin chi tiet nhu sau:";
		Xuattieude();
		Xuatkenang();
		for (i = 0; i < n; i++)
			if (max <= a[i].DiemTB)
			{
				cout << endl;
				Xuat_1SV(a[i]);
			}
		Xuatkenang();
	}
}


void xephocluc(BangDiemSV a[MAX], int n)
{

	int i;
	for (i = 0; i < n; i++)
	{
		if ( a[i].DiemTB>=8.5 && a[i].DiemTB <=10)
			strcpy_s(a[i].XepLoai, "Gioi");
		else if(a[i].DiemTB>= 7.0&& a[i].DiemTB<=8.5)
			strcpy_s(a[i].XepLoai, "Kha");
		else if(a[i].DiemTB>=5.5&& a[i].DiemTB <=7.0)
			strcpy_s(a[i].XepLoai, "TB");
		else if(a[i].DiemTB>=4.0 && a[i].DiemTB <= 5.5)
			strcpy_s(a[i].XepLoai, "Yeu");
		else
			strcpy_s(a[i].XepLoai, "Kem");
	}
}

