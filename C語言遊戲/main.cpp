#include<stdio.h>
#include<graphics.h>//easyx
#include<time.h>
#include"tools.h"
#include<math.h>

#include<mmsystem.h>
#pragma comment(lib, "winmm.lib")



#define WIＮ_WIDTH 900
#define WIＮ_HEIGHT 600

enum { WAN_DOU, XIANG_RI_KUI, ZHI_WU_COUNT };

IMAGE imgBg;
IMAGE imgBar;
IMAGE imgCards[ZHI_WU_COUNT];
IMAGE* imgZhiWu[ZHI_WU_COUNT][20];


int curX, curY;//植物移動種的位置
int curZhiWu;//0:沒有選中  1:選中第一種植物

struct zhiwu {
	int type;//第幾種植物
	int frameIndex;//序號
};

struct zhiwu map[3][9];

struct sunshineBall {
	int x, y;
	int frameIndex;
	int destY;
	bool used;
	int timer;


	float xoff;
	float yoff;
};
struct sunshineBall balls[10];
IMAGE imgSunshineBall[29];
int sunshine;

struct zm {
	int x, y;
	int frameIndex;
	bool used;
	int speed;
	int row;
	int blood;
	bool dead;
};

struct zm zms[10];
IMAGE imgZM[22];
IMAGE imgZMDead[20];

//子彈
struct bullet {
	int x, y;
	int row;
	bool used;
	int speed;
	bool blast;//爆了沒
	int frameIndex;
};
struct bullet bullets[30];
IMAGE imgBulletNormal;
IMAGE imgBallBlast[4];

bool fileExist(const char* name) {

	FILE* fp = fopen(name, "r");
	if (fp == NULL) {
		return false;
	}
	else {
		fclose(fp);
		return true;
	}
}

void gameInit() {//創造畫面
	//初始化圖片
	loadimage(&imgBg, "res/bg.jpg");
	loadimage(&imgBar, "res/Bar5.png");
	

	memset(imgZhiWu, 0, sizeof(imgZhiWu));
	memset(map, 0, sizeof(map));
	char name[64];
	for (int i = 0; i < ZHI_WU_COUNT; i++) {
		sprintf_s(name, sizeof(name), "res/Cards/card_%d.png", i + 1);
		loadimage(&imgCards[i], name);

		for (int j = 0; j < 20; j++) {
			sprintf_s(name, sizeof(name), "res/zhiwu/%d/%d.png", i, j + 1);
			if (fileExist(name)) {
				imgZhiWu[i][j] = new IMAGE;
				loadimage(imgZhiWu[i][j], name);
			}
			else {
				break;
			}
		}
	}

	curZhiWu = 0;
	sunshine = 50;

	memset(balls, 0, sizeof(balls));
	for (int i = 0; i < 29; i++) {
		sprintf_s(name, sizeof(name), "res/sunshine/%d.png", i + 1);
		loadimage(&imgSunshineBall[i], name);
	}

	srand(time(NULL));

	initgraph(WIＮ_WIDTH, WIＮ_HEIGHT, 1);//視窗大小


	//字體
	LOGFONT f;
	gettextstyle(&f);
	f.lfHeight = 30;
	f.lfWeight = 15;
	strcpy(f.lfFaceName, "Segoe UI black");
	f.lfQuality = ANTIALIASED_QUALITY;
	settextstyle(&f);
	setbkmode(TRANSPARENT);
	setcolor(BLACK);

	//殭屍初始化
	memset(zms, 0, sizeof(zms));
	for (int i = 0; i < 22; i++) {
		sprintf_s(name, sizeof(name), "res/zm/%d.png", i + 1);
		loadimage(&imgZM[i], name);
	}

	//子彈
	loadimage(&imgBulletNormal, "res/bullets/bullet_normal.png");
	memset(bullets, 0, sizeof(bullets));
	
	//子彈爆炸
	loadimage(&imgBallBlast[3], "res/bullets/bullet_blast.png");
	for (int i = 0; i < 3; i++) {
		float k = (i + 1) * 0.2;
		loadimage(&imgBallBlast[i], "res/bullets/bullet_blast.png",  imgBallBlast[3].getwidth() * k, imgBallBlast[3].getheight()*k,true);
	}

	for (int i = 0; i < 20; i++) {
		sprintf_s(name, sizeof(name), "res/zm_dead/%d.png", i + 1);
		loadimage(&imgZMDead[i], name);
	}

}

void drawZM() {
	int zmCount = sizeof(zms) / sizeof(zms[0]);
	for (int i = 0; i < zmCount; i++) {
		if (zms[i].used) {
			//IMAGE* img = &imgZM[zms[i].frameIndex];
			IMAGE* img = (zms[i].dead) ? imgZMDead : imgZM;
			img += zms[i].frameIndex;
			putimagePNG(zms[i].x, zms[i].y - img->getheight(), img);
		}
	}
}
void shoot() {
	static int l = 0;

	int lines[3] = { 0 };
	int zmCount = sizeof(zms) / sizeof(zms[0]);

	//int bulletMax = sizeof(bullets) / sizeof(bullets[0]);
	int dangerX = WIＮ_WIDTH - imgZM[0].getwidth()+40;

	for (int i = 0; i < zmCount; i++) {
		if (zms[i].used && zms[i].x < dangerX) {
			lines[zms[i].row] = 1;


			//direction[zms[i].row] = 1;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {

			if (map[i][j].type == WAN_DOU + 1 && lines[i]) {
				static int count = 0;
				count++;

				if (count > 40) {//發射速度
					count = 0;

					int k;
					int bulletMax = sizeof(bullets) / sizeof(bullets[0]);

					/*for (int k = 0; k < bulletMax; k++) {//&& bullets[k].used
						l++;
						printf("%d", l);
						if (k < bulletMax) {
							bullets[k].used = true;
							bullets[k].row = i;
							bullets[k].speed = 6;

							int zwX = 256 + j * 81;
							int zwY = 179 + i * 102;
							bullets[k].x = zwX + imgZhiWu[map[i][j].type - 1][0]->getwidth() - 10;
							bullets[k].y = zwY + 5;


						}
					}*/
					for (int k = 0; k < bulletMax; k++) {
						if (!bullets[k].used) {
							bullets[k].used = true;
							bullets[k].row = i;
							bullets[k].speed = 5;

							bullets[k].blast = false;
							bullets[k].frameIndex = 0;

							int zwX = 260 + j * 81;
							int zwY = 180 + i * 102;
							bullets[k].x = zwX + imgZhiWu[map[i][j].type - 1][0]->getwidth() - 10;
							bullets[k].y = zwY + 5;
							break;  // 找到未使用的子彈後，立即退出循環
						}
					}

				}
			}
		}
	}
}
void updateWindow() {
	BeginBatchDraw();//開始緩衝

	putimage(0, 0, &imgBg);//從哪裡開始顯示
	//putimage(250, 0, &imgBar);
	putimagePNG(250, 0, &imgBar);

	for (int i = 0; i < ZHI_WU_COUNT; i++) {
		int x = 335 + i * 65;
		int y = 6;
		putimage(x, y, &imgCards[i]);

	}


	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j].type > 0) {
				int x = 256 + j * 81;
				int y = 179 + i * 102;
				int zhiWuType = map[i][j].type - 1;
				int index = map[i][j].frameIndex;
				putimagePNG(x, y, imgZhiWu[zhiWuType][index]);
			}
		}
	}

	//植物拖動的過程
	if (curZhiWu > 0) {
		IMAGE* img = imgZhiWu[curZhiWu - 1][0];

		putimagePNG(curX - img->getwidth() / 2, curY - img->getheight() / 2, img);
	}
	//陽光
	int ballMax = sizeof(balls) / sizeof(balls[0]);
	for (int i = 0; i < ballMax; i++) {
		if (balls[i].used || balls[i].xoff) {
			IMAGE* img = &imgSunshineBall[balls[i].frameIndex];
			putimagePNG(balls[i].x, balls[i].y, img);
		}
	}

	char scoreText[8];
	sprintf_s(scoreText, sizeof(scoreText), "%d", sunshine);
	outtextxy(276, 67, scoreText);//陽光數

	drawZM();

	int bulletMax = sizeof(bullets) / sizeof(bullets[0]);
	for (int i = 0; i < bulletMax; i++) {
		if (bullets[i].used) {
			if (bullets[i].blast) {
				IMAGE* img = &imgBallBlast[bullets[i].frameIndex];
				putimagePNG(bullets[i].x, bullets[i].y, img);
			}


			else {
				putimagePNG(bullets[i].x, bullets[i].y, &imgBulletNormal);
			}
		}
		
	}




	EndBatchDraw();//結束緩衝 
}

void collectSunshine(ExMessage* msg) {
	int count = sizeof(balls) / sizeof(balls[0]);
	int w = imgSunshineBall[0].getwidth();
	int h = imgSunshineBall[0].getheight();
	for (int i = 0; i < count; i++) {
		if (balls[i].used) {
			int x = balls[i].x;
			int y = balls[i].y;
			if (msg->x > x && msg->x < x + w && msg->y >y && msg->y < y + h) {
				balls[i].used = false;
				//sunshine+= 25;
				mciSendString("play res/sunshine.mp3", 0, 0, 0);
				//陽光回家
				float destY = 0;
				float destX = 262;
				float angle = atan((y - destY) / (x - destX));
				balls[i].xoff = 4 * cos(angle);
				balls[i].yoff = 4 * sin(angle);

			}

		}
	}

}
void userClick() {
	ExMessage msg;
	static int status = 0;
	if (peekmessage(&msg)) {
		if (msg.message == WM_LBUTTONDOWN) {//按下左鍵
			if (msg.x > 332 && msg.x < 335 + 65 * ZHI_WU_COUNT && msg.y < 96) {
				int index = (msg.x - 335) / 65;
				status = 1;
				curZhiWu = index + 1;

			}
			else {
				collectSunshine(&msg);
			}
		}
		else if (msg.message == WM_MOUSEMOVE && status == 1) {//移動
			curX = msg.x;
			curY = msg.y;

		}
		else if (msg.message == WM_LBUTTONUP) {//放開左鍵
			if (msg.x > 256 && msg.y > 179 && msg.y < 489) {


				int row = (msg.y - 179) / 102;
				int col = (msg.x - 256) / 81;



				if (map[row][col].type == 0) {
					map[row][col].type = curZhiWu;
					map[row][col].frameIndex = 0;
				}


			}
			curZhiWu = 0;
			status = 0;
		}
	}
}

void createSunshine() {
	static int count = 0;
	static int fre = 100;
	count++;

	if (count >= fre) {
		fre = 50 + rand() % 100;
		count = 0;
		int ballMax = sizeof(balls) / sizeof(balls[0]);
		int i;
		for (i = 0; i < ballMax && balls[i].used; i++);
		if (i >= ballMax)return;

		balls[i].used = true;
		balls[i].frameIndex = 0;
		balls[i].x = 260 + rand() % (900 - 260);
		balls[i].y = 60;
		balls[i].destY = 200 + (rand() % 3) * 90;
		balls[i].timer = 0;
		balls[i].xoff = 0;
		balls[i].yoff = 0;



	}

}
void updateSunshine() {
	int ballMax = sizeof(balls) / sizeof(balls[0]);
	for (int i = 0; i < ballMax; i++) {
		if (balls[i].used) {
			balls[i].frameIndex = (balls[i].frameIndex + 1) % 29;
			if (balls[i].timer == 0) {
				balls[i].y += 2;
			}

			if (balls[i].y >= balls[i].destY) {
				//balls[i].used = false;
				balls[i].timer++;
				if (balls[i].timer > 100) {
					balls[i].used = false;
				}
			}
		}
		else if (balls[i].xoff) {
			float destY = 0;
			float destX = 262;
			float angle = atan((balls[i].y - destY) / (balls[i].x - destX));
			balls[i].xoff = 4 * cos(angle);
			balls[i].yoff = 4 * sin(angle);

			balls[i].x -= balls[i].xoff;
			balls[i].y -= balls[i].yoff;
			if (balls[i].y < 0 || balls[i].x < 262) {
				balls[i].xoff = 0;
				balls[i].yoff = 0;

				sunshine += 25;
			}
		}
	}
}

void createZM() {
	static int zmFrc = 150;
	static int count = 0;

	count++;
	if (count > zmFrc) {
		count = 0;
		zmFrc = rand() % 200 + 300;

		int i;
		int zmMax = sizeof(zms) / sizeof(zms[0]);
		for (i = 0; i < zmMax && zms[i].used; i++);
		if (i < zmMax) {
			zms[i].used = true;
			zms[i].x = WIＮ_WIDTH;
			zms[i].row = rand() % 3;
			zms[i].y = 172 + (1 + zms[i].row) * 100;
			zms[i].speed = 1;
			zms[i].blood = 100;
			zms[i].dead = false;
		}
	}
}

void updateZM() {
	int zmMax = sizeof(zms) / sizeof(zms[0]);

	static int count = 0;
	count++;
	if (count > 2) {
		count = 0;

		//位置
		for (int i = 0; i < zmMax; i++) {
			if (zms[i].used) {
				
				zms[i].x -= zms[i].speed;
				if (zms[i].x < 170) {
					printf("GAME OVER\n");
					MessageBox(NULL, "OVER", "OVER", 0);//記得升級
					exit(0);
				}
			}
		}
	}
	static int count2 = 0;
	count2++;
	if (count2 > 4) {
		count2 = 0;
		for (int i = 0; i < zmMax; i++) {
			if (zms[i].used) {
				if (zms[i].dead) {
					zms[i].frameIndex++;
					if (zms[i].frameIndex >= 20) {
						zms[i].used = false;
					}
				}
				else {
					zms[i].frameIndex = (zms[i].frameIndex + 1) % 22;
				}
				
			}
		}
	}


}

void updateBullets() {
	int countMax = sizeof(bullets) / sizeof(bullets[0]);
	for (int i = 0; i < countMax; i++) {
		if (bullets[i].used) {
			bullets[i].x += bullets[i].speed;
			if (bullets[i].x > WIＮ_WIDTH) {
				bullets[i].used = false;
			}//還沒好
			if (bullets[i].blast) {
				bullets[i].frameIndex++;
				if (bullets[i].frameIndex >= 4) {
					bullets[i].used = false;
				}
			}
		}
	}

}
void collisioncheck() {
	int bCount = sizeof(bullets) / sizeof(bullets[0]);
	int zCount = sizeof(zms) / sizeof(zms[0]);
	for (int i = 0; i<bCount; i++) {
		if (bullets[i].used == false || bullets[i].blast) {
			continue;
		}
		for (int k = 0; k < zCount; k++) {
			if (zms[k].used == false)continue;
			int x1 = zms[k].x + 80;
			int x2 = zms[k].x + 110;
			int x = bullets[i].x;
			if (zms[k].dead == false &&bullets[i].row == zms[k].row && x > x1 && x < x2) {
				zms[k].blood -= 20;
				bullets[i].blast = true;
				bullets[i].speed = 0;

				if (zms[k].blood <= 0) {
					zms[k].dead = true;
					zms[k].speed = 0;
					zms[k].frameIndex = 0;
				}

				break;
			}
		}
	}
}


void updateGame() {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 9; j++) {
			if (map[i][j].type > 0) {
				map[i][j].frameIndex++;
				int zhiWuType = map[i][j].type - 1;
				int index = map[i][j].frameIndex;
				if (imgZhiWu[zhiWuType][index] == NULL) {
					map[i][j].frameIndex = 0;
				}
			}
		}
	}

	createSunshine();//創造陽光
	updateSunshine();//更新陽光

	createZM();//創造殭屍
	updateZM();//更新殭屍

	shoot();//子彈
	updateBullets();

	collisioncheck();//碰撞
}

void startUI() {
	IMAGE imgBg, imgMenu1, imgMenu2;
	loadimage(&imgBg, "res/menu.png");
	loadimage(&imgMenu1, "res/menu1.png");
	loadimage(&imgMenu2, "res/menu2.png");
	int flag = 0;

	while (1) {
		putimage(0, 0, &imgBg);
		putimagePNG(470, 75, flag ? &imgMenu2 : &imgMenu1);


		ExMessage msg;
		if (peekmessage(&msg)) {
			if (msg.message == WM_LBUTTONDOWN && msg.x > 470 && msg.x < 470 + 300 && msg.y>75 && msg.y < 75 + 140) {
				flag = 1;
			}
			else if (msg.message == WM_LBUTTONUP && flag) {
				return;
			}
		}

		EndBatchDraw();

	}
}

int main() {

	gameInit();
	startUI();

	int timer = 0;
	bool flag = true;
	while (1) {
		userClick();

		timer += getDelay();
		if (timer > 20) {
			flag = true;
			timer = 0;

		}
		if (flag) {
			flag = false;
			updateWindow();

			updateGame();

		}





	}



	system("pause");
	return 0;
}