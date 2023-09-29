#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include <string>

#define KEY_NONE	-1
#define D char(219)
using namespace std;

int whereX()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.X;
	return -1;
}
//========= l?y t?a ?? y c?a con tr? hi?n t?i =======
int whereY()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
		return csbi.dwCursorPosition.Y;
	return -1;
}
//============== d?ch con tr? hi?n t?i ??n ?i?m có t?a ?? (x,y) ==========
// Hàm thay ??i kích c? c?a khung cmd v?i tham s? truy?n vào là chi?u cao, chi?u r?ng.
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}

// Hàm d?ch chuy?n con tr? ??n t?a ?? x, y.
void gotoXY(int x, int y)
{
	HANDLE hConsoleOutput;
	COORD Cursor_an_Pos = { x - 1,y - 1 };
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_an_Pos);
}

// Hàm xóa màn hình.
void XoaManHinh()
{
	HANDLE hOut;
	COORD Position;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}

// Hàm l?y Key t? bàn phím
/* GetAsyncKeyState(VK_ESCAPE) => b?t s? ki?n phím Esc */

// Hàm t? vi?t
void ToMau(int x, int y, char* a, int color) // x, y là t?a ?? con tr? c?n nh?y ??n ?? vi?t, a là chu?i c?n truy?n vào, color là màu truy?n vào.
{
	gotoXY(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}

void hop(int x, int y, int w, int h, int a)
{
	if (h <= 1 || w <= 1) return;
	for (int ix = x; ix <= x + w; ix++)
	{
		gotoXY(ix, y); textcolor(a);
		cout << char(196);
		gotoXY(ix, y + h); textcolor(a);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++)
	{
		gotoXY(x, iy); textcolor(a);
		cout << char(179);
		gotoXY(x + w, iy); textcolor(a);
		cout << char(179);
	}
	gotoXY(x, y); textcolor(a); cout << char(218);
	gotoXY(x + w, y); textcolor(a); cout << char(191);
	gotoXY(x, y + h); textcolor(a); cout << char(192);
	gotoXY(x + w, y + h); textcolor(a); cout << char(217);
}

void hinhnen(int x, int y)
{
	int ix, iy;
	for (iy = 0; iy < y; iy++)
	{
		for (ix = 0; ix < x; ix++)
		{
			textcolor(255);
			printf(" ");
		}
	}
}

void abt()
{
	hinhnen(120, 30);
	hop(36, 13, 52, 14, 246);
	gotoXY(59, 13); printf(" ABOUT ");
	gotoXY(47, 16); printf(" DO AN GAME CO CARO - NHOM IV");
	gotoXY(44, 18); printf("_MSSV_                   _HO VA TEN_");
	gotoXY(43, 19); printf("23122031               NGUYEN HUY HOANG");
	gotoXY(43, 20); printf("23122042              TRAN TA QUANG MINH");
	gotoXY(43, 21); printf("23122043                 NGUYEN BA NAM");
	gotoXY(43, 22); printf("23122056                 LAM HOANG VU");
	gotoXY(43, 24); printf("GV HUONG DAN: THAY TRUONG TOAN THINH");
	gotoXY(60, 26); printf("BACK");
}

void hlp()
{
	hinhnen(120, 30);
	hop(36, 13, 52, 16, 246);
	gotoXY(58, 13); printf("HUONG DAN");
	gotoXY(41, 15); printf("1. BAN CO VOI KINH THUOC 16x16.");
	gotoXY(41, 18); printf("2. SU DUNG: PHIM W A S D DE DI CHUYEN");
	gotoXY(53, 19); printf("PHIM ENTER DE DANH DAU.");
	gotoXY(41, 21); printf("3. KHI CO 5 QUAN CO X HOAC O LIEN TIEP THEO");
	gotoXY(44, 22); printf("CHIEU DOC, NGANG, CHEO SE KET THUC.");
	gotoXY(41, 24); printf("4. AP DUNG LUAT CHAN HAI DAU TRONG CO CARO.");
	gotoXY(47, 26); printf("YOU CAN DO IT. GOOD LUCK!!!");
	gotoXY(60, 28); printf("BACK");
}

void caidat()
{
	hinhnen(120, 30);
	hop(36, 13, 52, 14, 246);
	gotoXY(57, 13); printf("SOUND EFFECT");
	gotoXY(43, 16); printf("        **                        **");
	gotoXY(43, 17); printf("      ** *    *                 ** *");
	gotoXY(43, 18); printf("   ***** *  *  *             ***** *");
	gotoXY(43, 19); printf("   ***** *   *  *            ***** *");
	gotoXY(43, 20); printf("   ***** *  *  *             ***** *");
	gotoXY(43, 21); printf("      ** *    *                 ** *");
	gotoXY(43, 22); printf("       ***                       ***");
	gotoXY(43, 24); printf("    SOUND ON                  SOUND OFF");
	gotoXY(60, 26); printf("  BACK");
}

void choivoiai()
{
	hinhnen(120, 30);
	hop(36, 13, 52, 11, 246);
	gotoXY(48, 13); printf("WHO DO YOU WANT TO PLAY WITH ?");
	gotoXY(43, 16); printf("            1 Play together");
	gotoXY(43, 18); printf("            2 Play with Bot:");
	gotoXY(43, 19); printf("               - Easy -");
	gotoXY(43, 20); printf("              - Medium -");
	gotoXY(43, 21); printf("               - Hard -");
	gotoXY(60, 23); printf("BACK");
}

void set_color(int code) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(color, code);
}
void vebang()
{
	int x, y;
	gotoXY(2, 1);
	// ve khung tren
	cout << char(201);
	for (x = 3; x < 66; x++) {
		gotoXY(x, 1);
		cout << char(205);
	}
	cout << char(187);
	for (x = 6; x < 66; x += 4) {
		gotoXY(x, 1);
		cout << char(203);
	}
	// ve hang
	for (y = 2; y <= 33; y++) {
		gotoXY(2, y);
		for (x = 2; x <= 66; x += 4) {
			gotoXY(x, y);
			cout << char(186);
		}
	}
	// ve khung duoi
	gotoXY(2, 33); cout << char(200);
	for (x = 3; x < 66; x++) {
		gotoXY(x, 33);
		cout << char(205);
	}
	cout << char(188);
	for (x = 6; x < 66; x += 4) {
		gotoXY(x, 33);
		cout << char(202);
	}
	// ve ben trong
	for (y = 3; y <= 32; y += 2) {
		gotoXY(2, y);
		for (x = 2; x < 66; x++) {
			gotoXY(x, y);
			cout << char(205);
		}
	}
	for (y = 3; y <= 32; y += 2) {
		gotoXY(2, y);
		for (x = 6; x < 66; x += 4) {
			gotoXY(x, y);
			cout << char(206);
		}
	}
	for (y = 3; y < 33; y += 2) {
		gotoXY(2, y);
		cout << char(204);
	}
	for (y = 3; y < 33; y += 2) {
		gotoXY(66, y);
		cout << char(185);
	}
}
void vethongso()
{
	int x, y;
	// ve o X
	gotoXY(72, 1); cout << char(218);
	for (x = 73; x <= 96; x++) {
		gotoXY(x, 1); cout << char(196);
	}
	gotoXY(97, 1); cout << char(191);
	for (x = 72; x <= 97; x += 25) {
		for (y = 2; y <= 16; y++) {
			gotoXY(x, y);
			cout << char(179);
		}
	}
	gotoXY(72, 17); cout << char(192);
	for (x = 73; x <= 96; x++) {
		gotoXY(x, 17); cout << char(196);
	}
	gotoXY(97, 17); cout << char(217);
	// ve o Y
	gotoXY(100, 1); cout << char(218);
	for (x = 101; x <= 124; x++) {
		gotoXY(x, 1); cout << char(196);
	}
	gotoXY(125, 1); cout << char(191);
	for (x = 100; x <= 125; x += 25) {
		for (y = 2; y <= 16; y++) {
			gotoXY(x, y);
			cout << char(179);
		}
	}
	gotoXY(100, 17); cout << char(192);
	for (x = 101; x <= 124; x++) {
		gotoXY(x, 17); cout << char(196);
	}
	gotoXY(125, 17); cout << char(217);
	// ve khung ngoai
	gotoXY(70, 0); cout << char(218);
	for (x = 71; x <= 126; x++) {
		gotoXY(x, 0);
		cout << char(196);
	}
	gotoXY(127, 0); cout << char(191);
	for (x = 70; x <= 127; x += 57) {
		for (y = 1; y <= 33; y++) {
			gotoXY(x, y); cout << char(179);
		}
	}
	gotoXY(70, 34); cout << char(192);
	for (x = 71; x <= 126; x++) {
		gotoXY(x, 34);
		cout << char(196);
	}
	gotoXY(127, 34); cout << char(217);
}
void vechuX()
{
	int x, y;
	y = 3;
	for (x = 80; x <= 88; x += 2) {
		gotoXY(x, y); set_color(12); cout << D << D;
		y++;
	}
	y = 3;
	for (x = 88; x >= 80; x -= 2) {
		gotoXY(x, y); set_color(12); cout << D << D;
		y++;
	}
	y = 3;
	for (x = 78; x <= 88; x += 2) {
		gotoXY(x, y); set_color(4); cout << D << D;
		y++;
	}
	y = 3;
	for (x = 90; x >= 80; x -= 2) {
		gotoXY(x, y); set_color(4); cout << D << D;
		y++;
	}
	y = 2;
	for (x = 80; x <= 90; x += 2) {
		gotoXY(x, y); set_color(4); cout << D << D;
		y++;
	}
	y = 2;
	for (x = 88; x >= 78; x -= 2) {
		gotoXY(x, y); set_color(4); cout << D << D;
		y++;
	}
	gotoXY(78, 2); set_color(4); cout << D << D;
	gotoXY(90, 2); set_color(4); cout << D << D;
	gotoXY(78, 8); set_color(4); cout << D << D;
	gotoXY(90, 8); set_color(4); cout << D << D;
}
void vechuO()
{
	int x, y;
	for (y = 2; y <= 8; y += 6) {
		for (x = 110; x <= 114; x += 2) {
			gotoXY(x, y);
			set_color(2);
			cout << D << D;
		}
	}
	for (x = 106; x <= 118; x += 12) {
		for (y = 4; y <= 6; y++) {
			gotoXY(x, y);
			set_color(2);
			cout << D << D;
		}
	}
	gotoXY(108, 3); set_color(2); cout << D << D;
	gotoXY(116, 3); set_color(2); cout << D << D;
	gotoXY(108, 7); set_color(2); cout << D << D;
	gotoXY(116, 7); set_color(2); cout << D << D;
	for (y = 3; y <= 7; y += 4) {
		for (x = 110; x <= 114; x += 2) {
			gotoXY(x, y);
			set_color(10);
			cout << D << D;
		}
	}
	for (x = 108; x <= 116; x += 8) {
		for (y = 4; y <= 6; y++) {
			gotoXY(x, y);
			set_color(10);
			cout << D << D;
		}
	}
}

void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

}

void box(int x, int y, int w, int h, int t_color, int b_color, string nd) {
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++) {
		for (int ix = x + 1; ix <= x + w - 1; ix++) {
			gotoXY(ix, iy); cout << " ";
		}
	}
	textcolor(117);
	gotoXY(x + 4, y + 1);
	cout << nd;
	textcolor(t_color);
	if (h <= 1 || w <= 1) return;
	for (int ix = x; ix <= x + w; ix++) {
		gotoXY(ix, y);
		cout << char(196);
		gotoXY(ix, y + h);
		cout << char(196);
	}
	for (int iy = y; iy <= y + h; iy++) {
		gotoXY(x, iy);
		cout << char(179);
		gotoXY(x + w, iy);
		cout << char(179);
	}
	gotoXY(x, y); cout << char(218);
	gotoXY(x + w, y); cout << char(191);
	gotoXY(x, y + h); cout << char(192);
	gotoXY(x + w, y + h); cout << char(217);
}
//lam sang lua chon khi con tro tro toi

void mua(int m, int n, int check) {
	while (true) {
		int mcu, ncu;
		mcu = m;
		ncu = n - 1;
		textcolor(116);
		gotoXY(m, n);
		cout << "X";
		if (n == 30) {
			check = 1;
		}
		else if (n == 0 || n == 1 || n == 2 || n == 3 || n == 4) {
			check = 0;
		}
		if (check == 0) {
			n++;
		}
		else if (check == 1) {
			n = 0;
		}
		gotoXY(mcu, ncu);
		cout << " ";



		Sleep(120);




	}
}
// ve hinh nen
void vehinhnen() {
	textcolor(117);
	gotoXY(38, 5); cout << "    cccccc      aaa      rrrrr        ooooo                              ";
	gotoXY(38, 6); cout << "   ccc         aa aa     rr   rr     oo   oo                     ";
	gotoXY(38, 7); cout << "  ccc         aa   aa    rr   rr    oo     oo                     ";
	gotoXY(38, 8); cout << "  ccc        aa aaa aa   rrrrrr     oo     oo                     ";
	gotoXY(38, 9); cout << "   ccc      aa       aa  rr   rr     oo   oo                  ";
	gotoXY(38, 10); cout << "    cccccc aaa       aaa rr     rr    ooooo                          ";
	Sleep(1000);
	textcolor(116);
	gotoXY(65, 13); cout << "bb     bb    bb   iiiii  tttttt pppp                        ";
	gotoXY(65, 14); cout << "bbbbb    bbbb      iii     tt   pp  pp                   ";
	gotoXY(65, 15); cout << "bb  bb    bb       iii     tt   pp pp                 ";
	gotoXY(65, 16); cout << "bbbbb     bb      iiiii    tt   pp                    ";
	Sleep(1000);
}
void venen() {
	for (int X = 0; X <= 150; X++) {
		for (int Y = 0; Y <= 30; Y++) {
			textcolor(120);

			gotoXY(X, Y);
			cout << " ";

		}
	}

}
void fixkhung() {
	//fixkhung
	textcolor(117);
	for (int p = 0; p < 4; p++) {
		gotoXY(55, 20 + (p * 2) + 2);
		cout << char(195);
		gotoXY(55 + 12, 20 + (p * 2) + 2);
		cout << char(180);
	}

}
void thanhsang(int x, int y, int w, int h, int b_color) {
	textcolor(b_color);
	for (int iy = y + 1; iy <= y + h - 1; iy++) {
		for (int ix = x + 1; ix <= x + 1; ix++) {
			gotoXY(ix, iy); cout << " ";
			gotoXY(ix + 10, iy); cout << " ";

		}
	}


}
void menu() {
	int y = 20;
	int x = 55;
	//ShowCur(0);//lam an con tro chuot
	int b_color_sang = 13;
	box(x, y - 2, 12, 2, 117, 116, "Start");
	box(x, y, 12, 2, 117, 116, "Load");
	box(x, y + 2, 12, 2, 117, 116, "Help");
	box(x, y + 4, 12, 2, 117, 116, "About");
	box(x, y + 6, 12, 2, 117, 116, "Setting");
	box(x, y + 8, 12, 2, 117, 116, "Exit");



	int xp = x; int yp = y;//giu toa do thanh sang
	int xcu = xp; int ycu = yp;
	bool kt = true;
	while (true) {

		//backspace xoa du lieu cu
		//in
		if (kt == true) {
			gotoXY(xcu, ycu);
			thanhsang(xcu, ycu, 12, 2, 117);
			xcu = xp; ycu = yp;
			thanhsang(xp, yp, 12, 2, 80);
			kt = false;
		}
		//dieu khien//di chuyen
		if (_kbhit()) {
			char c = _getch();
			if (c == -32) {
				kt = true;//da bam
				c = _getch();
				if (c == 72) {
					if (yp != y)yp -= 2;
					else {
						yp = y + 8;
					}

				}
				else if (c == 80) {
					if (yp != y + 8)yp += 2;
					else {
						yp = y;
					}

				}
			}
		}
		//speed
	}
}
void click() {

}

void manhinhbatdau()
{
	FixConsoleWindow();
	venen();
	vehinhnen();
	menu();
	fixkhung();
	gotoXY(64, 21);
}
void playboard()
{
	hinhnen(120, 30);
	vebang();
	vethongso();
	vechuX();
	vechuO();
}