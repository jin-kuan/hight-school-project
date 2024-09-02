#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"winmm.lib")
#include <conio.h>
#include <time.h>
#include "important.h"
#include "DrawUI.h"
//9/23
//important function
void game_start();
int key_bord_control(COORD* current_xy);
int exceed_border(COORD* current_xy);
void PRINT_star_funtion(struct star_position* first_lineOfStar, int CONTROL_star_amount, int color);
void PRINT_bullet_function(struct bullet_pos* first_bullet);
void PRINT_airplane(COORD* current_xy, int choose_weapon);
void print_all(COORD* current_xy);
void print_bullet();
void printf_all_enemy();
void print_explosion();
void generate_bullet(COORD* current_xy);
void generate_enemy_little_bee();
void Geneate_star_function(struct star_position** first_lineOfStar, struct star_position** last_LineOfStar, int CONTROL_star_amount);
void geneate_star();
void geneate_explosion_anmition(struct position * current_enemy);//�z��
void JUDGE_star_funtion(struct star_position** first_lineOfStar, struct star_position** last_LineOfStar, int CONTROL_star_amount);
void JUDGE_bullet_function(struct bullet_pos** first_bullet, int* bullet_amount);
void judge_bullet();
void judge_collision();
void UPDATE_bullet_list(struct bullet_pos* first_point);
void UPDATE_enemy_list(struct position* first_point, int AI, COORD* current_xy);
void UPDATE_star_xy_funtion(struct star_position* first_lineOfStar, int CONTROL_star_amount);
void update_bullet_xy();
void update_enemy_xy(); 
void show_all_data();
void show_health();
void show_ammo();
void reload_ammo();
// normal function
int free_enemy_function(struct position* current_enemy);
void free_bullet_function(struct bullet_pos** current_bullet);
void Linked_all_bullet();
void deLinked_all_bullet();
//
int bullet_amount=0;  //�p��l�u�h�֭���`��b�@�_�@�@//�����u��
int bullet_amount_2 = 0;//2���u��
int bullet_amount_3 = 0;//3���u��
int little_bee_amount = 0;
int surplus_bullet=20; //�Ѿl�l�u
COORD old_airplane_pos;  //�ΨӼȦs�­�����l
struct bullet_pos* First_Node_of_All_bullet;
struct bullet_pos* last_Node_of_All_bullet;
struct bullet_pos* first_bullet = NULL;  //1���Z�����Y���w
struct bullet_pos* last_bullet = NULL;
struct bullet_pos* first_bullet_2 = NULL;//2���Z�����Y���w
struct bullet_pos* last_bullet_2 = NULL;
struct bullet_pos* first_bullet_3 = NULL;//3���Z�����Y���w
struct bullet_pos* last_bullet_3 = NULL;
struct position* little_bee_first = NULL;
struct position* little_bee_last = NULL;
struct explosion* first_animation = NULL;
struct explosion* last_animation = NULL;
struct star_position* first_lineOfStar = NULL;
struct star_position* last_LineOfStar = NULL;
struct star_position* first_lineOfStar_2 = NULL;
struct star_position* last_LineOfStar_2 = NULL;
struct star_position* current_LineOfStar=NULL;
COORD tmp_old_bullet;
int weapon_choose;
int health;
int agree_reload=0;//�P�N�ˤl�u
int reload_time=0;//�ˤl�u������ɶ�
int count_main_while_time=0;//�`�j��
int CONTROL_little_bee_move_time;//�e���ǨC�X���j���s�@���s�y��
int CONTROL_little_bee_geneate_time;
int CONTROL_UPDATE_star;
int CONTROL_star_amount;
int CONTROL_UPDATE_star_2;
int CONTROL_star_amount_2;
int CONTROL_explo_animation_time;
int AI = 1;
int main()
{
	srand((unsigned int)time(NULL));//�ü�
	//system("mode con cols=100 lines=51");
	system("mode con cols=100 lines=51");
	system("title Defend the Space v0.5   50*60        created by Majitoo");
	print_range();
	game_start();
	system("pause");
}
void game_start()
{
	//��l�Ƽƾ� �p�G���ĤG���C������
	bullet_amount = 0;
	bullet_amount_2 = 0;
	bullet_amount_3 = 0;
	little_bee_amount = 0;
	COORD current_xy;
	current_xy.X = 26;
	current_xy.Y = 43;
	health = 6;
	surplus_bullet = 20;
	weapon_choose = 1;//�w�]�Z�����Ĥ@��
	agree_reload = 0;
	reload_time = 0;
	count_main_while_time = 1;
	CONTROL_little_bee_move_time = 4;//�e���ǨC%d���j���s�@���s�y��
	CONTROL_little_bee_geneate_time = 30;// �w�]:30  
	CONTROL_UPDATE_star = 5;  
	CONTROL_star_amount = 1;
	CONTROL_UPDATE_star_2 = 15;
	CONTROL_star_amount_2 = 1;
	CONTROL_explo_animation_time = 6; //�z���ʵe�ɶ�
	geneate_star();
	while (1)
	{
		Goxy(70, 30);
		printf("%d",count_main_while_time);
		Goxy(70, 25);              //debug mod
		printf("%d", bullet_amount_2);
		if (GetAsyncKeyState(0x31)) //1
		{
			weapon_choose = 1;
		}
		if (GetAsyncKeyState(0x32))//2
		{
			weapon_choose = 2;
		}
		if (GetAsyncKeyState(0x33))//3
		{
			weapon_choose = 3;
		}
		key_bord_control(&current_xy);
		exceed_border(&current_xy);
		if (count_main_while_time % CONTROL_little_bee_geneate_time == 0)
		{
			generate_enemy_little_bee();
		}
		if (count_main_while_time % CONTROL_UPDATE_star == 0)//�P�P��s�ɶ�
		{

			PRINT_star_funtion(first_lineOfStar, CONTROL_star_amount, 15);
			UPDATE_star_xy_funtion(first_lineOfStar, CONTROL_star_amount);
			JUDGE_star_funtion(&first_lineOfStar, &last_LineOfStar, CONTROL_star_amount);
		}
		if (count_main_while_time % CONTROL_UPDATE_star_2 == 0)//�ĤG�t�C�P�P��s�ɶ�
		{
			PRINT_star_funtion(first_lineOfStar_2, CONTROL_star_amount_2, 8);
			UPDATE_star_xy_funtion(first_lineOfStar_2, CONTROL_star_amount_2);
			JUDGE_star_funtion(&first_lineOfStar_2, &last_LineOfStar_2, CONTROL_star_amount_2);
		}
		print_all(&current_xy);
		if ((bullet_amount+bullet_amount_2+bullet_amount_3) >= 1)
		{
			judge_bullet();//�P�_�O�_�n����O����
			update_bullet_xy();
		}
		update_enemy_xy(&current_xy);
		judge_collision();
		show_all_data();
		count_main_while_time++;//�p��j�馸��
		Sleep(25);
		if (count_main_while_time > 999999)
		{
			count_main_while_time = 1;
		}
		if (count_main_while_time % 3500==0)
		{
			mciSendString(("seek music1 to start"), NULL, 0, NULL);
			mciSendString(("play music1"), NULL, 0, NULL); 
		}
	}
}
int free_enemy_function(struct position* current_enemy)// 1�P�N���� 0��������
{
	
	if (little_bee_amount==1)  //�p�G�U�@�ӼĤH���S���ĤH �N������Y���w�]����
	{
		little_bee_first = NULL;
		little_bee_last = NULL;
		return 1;
	}
	if (little_bee_amount == 2)
	{
		if (little_bee_first == current_enemy) //�N��Ĥ@��
		{
			little_bee_first = little_bee_first->pnext;
			little_bee_last = little_bee_first;
			little_bee_last->pnext = NULL;
		}
		else
		{
			little_bee_last = current_enemy->last_pnext;//���W�@��
			little_bee_last->pnext = NULL;
		}
		return 1;
	}
	if (little_bee_amount >= 3)
	{
		if (little_bee_first==current_enemy) //�N��Ĥ@��
		{
			little_bee_first = little_bee_first->pnext;
			little_bee_first->last_pnext = NULL;
		}
		else
		{
			if (current_enemy->pnext != NULL) //�P�_�U�@�ӬO���O�Ū� �Y�O�N���̫�@��  �̫�@��
			{
				current_enemy->last_pnext->pnext = current_enemy->pnext;  //�Ĥ@�Ӹ`�I�o�U�@�ӫ��w ���V�ĤT�Ӹ`�I
				current_enemy->pnext->last_pnext = current_enemy->last_pnext; //�ĤT�Ӹ`�I�o�W�@�ӫ��w ���^���V�Ĥ@�Ӹ`�I
			}
			else              
			{
				little_bee_last = current_enemy->last_pnext;    //�]���U�@�ӬO�Ū��ҥH���W�@��
				little_bee_last->pnext = NULL;
				
			}
		}
		return 1;
	}
	return 0;
}
void free_bullet_function(struct bullet_pos** current_bullet)
{
	COORD xy = (*current_bullet)->pos;
	xy.Y += 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
	printf(" ");
	if ((*current_bullet)->last_pnext == NULL && (*current_bullet)->pnext == NULL)   //���p�T�Ӽu��[�_�ӥu���@��
	{
		First_Node_of_All_bullet = NULL;
		last_Node_of_All_bullet = NULL;
	}
	else if ((*current_bullet)->last_pnext == NULL && (*current_bullet)->pnext != NULL)  //�T�ӥH�W�Ĥ@��
	{
		First_Node_of_All_bullet = (*current_bullet)->pnext;
		First_Node_of_All_bullet->last_pnext = NULL;
	}
	else if ((*current_bullet)->last_pnext != NULL && (*current_bullet)->pnext == NULL) //�T�ӥH�W �̫�@��
	{
		(*current_bullet)->last_pnext->pnext = NULL;
		last_Node_of_All_bullet = (*current_bullet)->last_pnext;
		last_Node_of_All_bullet->pnext = NULL;
	}
	else
	{
		(*current_bullet)->last_pnext->pnext = (*current_bullet)->pnext; //�Ĥ@�ӫ��V�ĤT��
		(*current_bullet)->pnext->last_pnext = (*current_bullet)->last_pnext;//�ĤT�ӫ��V�Ĥ@��
	}
}
void Linked_all_bullet()
{
 	if (first_bullet != NULL) //���M�w�s��b�Ĥ@�ӱo���
	{
		First_Node_of_All_bullet = first_bullet;
		last_Node_of_All_bullet = last_bullet;
		if (first_bullet_2 != NULL) //�M�w�ĤG�����
		{
			last_bullet->pnext = first_bullet_2;
			first_bullet_2->last_pnext = last_bullet;
			last_Node_of_All_bullet = last_bullet_2;
			if (first_bullet_3 != NULL)//�M�w�ĤT�����
			{
				last_bullet_2->pnext = first_bullet_3;
				first_bullet_3->last_pnext = last_bullet_2;
				last_Node_of_All_bullet = first_bullet_3;
			}
		}
		if (first_bullet_3 != NULL)//�M�w�ĤT�����
		{
			last_bullet->pnext = first_bullet_3;
			first_bullet_3->last_pnext = last_bullet;
			last_Node_of_All_bullet = last_bullet_3;
		}
	}
	else if (first_bullet_2!=NULL)//���M�w�s��b�Ĥ@�ӱo���
	{
		First_Node_of_All_bullet = first_bullet_2;
		last_Node_of_All_bullet = last_bullet_2;
		if (first_bullet_3 != NULL)
		{
			last_bullet_2->pnext = first_bullet_3;
			first_bullet_3->last_pnext = last_bullet_2;
			last_Node_of_All_bullet = last_bullet_3;
		}
	}
	else                          //���M�w�s��b�Ĥ@�ӱo���
	{
		First_Node_of_All_bullet = first_bullet_3;
		last_Node_of_All_bullet = last_bullet_3;
	}
}
void deLinked_all_bullet()//��ѽm��
{
	if (First_Node_of_All_bullet != NULL)
	{
		struct bullet_pos* current_bullet = First_Node_of_All_bullet;
		int one_link_count=-1, two_link_count=-1, three_link_count = -1;
		while (1)
		{
			if (current_bullet->bullet_type == 1)
			{
				if (one_link_count == -1)
				{
					first_bullet = current_bullet;
					first_bullet->last_pnext = NULL;
					one_link_count = 0;
				}
				one_link_count++;
			}	
			else if (current_bullet->bullet_type == 2)
			{
				if (two_link_count == -1)
				{
					first_bullet_2 = current_bullet;
					first_bullet_2->last_pnext = NULL;
					two_link_count = 0;
				}
				two_link_count++;
			}
			else	//if (current_bullet->bullet_type == 3)
			{
				if (three_link_count == -1)
				{
					first_bullet_3 = current_bullet;
					first_bullet_3->last_pnext = NULL;
					three_link_count = 0;
				}
				three_link_count++;
			}
			if (one_link_count == bullet_amount || two_link_count==bullet_amount_2 || three_link_count==bullet_amount_3)
			{
				if (one_link_count == bullet_amount)
				{
					last_bullet = current_bullet;
					one_link_count = -2;             //-2�N�����w����T�w
				}
				if (two_link_count == bullet_amount_2)
				{
					last_bullet_2 = current_bullet;
					two_link_count = -2;
				}
				if (three_link_count == bullet_amount_3)
				{
					last_bullet_3 = current_bullet;
					three_link_count = -2;
				}
			}
			if (current_bullet->pnext == NULL)//�T�w�C�Ӽu���l�� �A��s�����_
			{
				if (last_bullet != NULL)
					last_bullet->pnext = NULL;
				if (last_bullet_2 != NULL)
					last_bullet_2->pnext = NULL;
				if (last_bullet_3 != NULL)
					last_bullet_3->pnext = NULL;
				break;
			}
			current_bullet = current_bullet->pnext;
		}
	}
}
void judge_collision()
{
	if ((bullet_amount+bullet_amount_2+bullet_amount_3) != 0 && little_bee_first != NULL)//�p�G�l�u�Ƥ���0�N����
	{
		Linked_all_bullet();
      	struct position* current_enemy = little_bee_first;
		struct position* ready_to_free_enemy = NULL;
		struct bullet_pos* ready_to_free_bullet = NULL;
		while (1)//���@�ܼĤH
		{
			Goxy(70, 30);              //debug mod
			printf("%d", bullet_amount);
			struct bullet_pos* current_bullet = First_Node_of_All_bullet;
			ready_to_free_enemy =current_enemy;
			int check_delete_node = 0;//�p�G���o�͸I���R���`�I ��1 �Ϥ� 0;
			while (1)//���@�ܤl�u
			{
				ready_to_free_bullet = current_bullet;
				if (current_bullet->pos.Y <= current_enemy->pos.Y && current_bullet->pos.Y >= current_enemy->pos.Y - 3
					&& current_bullet->pos.X >= current_enemy->pos.X &&  current_bullet->pos.X <= current_enemy->pos.X + 6)
				{
					check_delete_node=free_enemy_function(current_enemy);
					free_bullet_function(&current_bullet);
					geneate_explosion_anmition(current_enemy);
					little_bee_amount-=1;
					if (current_bullet->bullet_type==1)
						bullet_amount -= 1;
					if (current_bullet->bullet_type == 2)
						bullet_amount_2 -= 1;
					if (current_bullet->bullet_type == 3)
						bullet_amount_3 -= 1;
					if (bullet_amount + bullet_amount_2 + bullet_amount_3 == 0)
					{
						First_Node_of_All_bullet = NULL;
						last_Node_of_All_bullet = NULL;
					}
						
				}
				if (little_bee_amount == 0 || (bullet_amount + bullet_amount_2 + bullet_amount_3) == 0 || current_bullet->pnext == NULL || check_delete_node == 1)
				{
					if (check_delete_node == 1)
					{
						free(ready_to_free_bullet);
					}
					break;
				}
				current_bullet = current_bullet->pnext;
			}
			if (little_bee_amount == 0 || (bullet_amount + bullet_amount_2 + bullet_amount_3) == 0 || current_enemy->pnext == NULL) //�p�G�S���U�@�ӼĤH �N���X�����
			{
				if (check_delete_node == 1)              //�S���U�@�ӼĤH  �S�Q�l�u���� �N����`�I
				{
					free(ready_to_free_enemy);
				}
				deLinked_all_bullet();
				break;
			}
			if (check_delete_node == 1)//�p�G������ĤH
			{
				current_enemy = current_enemy->pnext;
				free(ready_to_free_enemy);   
			}
			else     //�S����ĤH ���U�@�ӼĤH �~�����
			{
				current_enemy = current_enemy->pnext;
			}
		}
	}
}
void geneate_explosion_anmition(struct position * current_enemy)
{
	struct explosion* new_explosion_node = (struct explosion*)malloc(sizeof(struct explosion));//�z���ĪG���
	if (current_enemy->pos.Y>=4)    //�ҩl�ʵe
		new_explosion_node->line_status = 3;
	else if (current_enemy->pos.Y >= 3)
		new_explosion_node->line_status = 2;
	else 
		new_explosion_node->line_status = 1;
	new_explosion_node->delay_time = CONTROL_explo_animation_time;
	new_explosion_node->status = 3;//�`�@���T�ذʵe 3���Ĥ@��
	new_explosion_node->pos = current_enemy->pos;
	if (first_animation == NULL)
	{
		first_animation = new_explosion_node;
		last_animation = new_explosion_node;
		last_animation->pnext = NULL;
	}
	else
	{
		last_animation->pnext = new_explosion_node;
		last_animation = new_explosion_node;
		last_animation->pnext = NULL;
	}
}
int key_bord_control(COORD* current_xy)
{
	static int count_up_key = 0;
	static int count_down_key = 0;
	static int count_rightup_key = 0;
	static int count_leftup_key = 0;
	static int count_rightdown_key = 0;
	static int count_leftdown_key = 0;
	static int count_space_key = 3;
	int w, a, s, d,up,down,left,right;
	w = GetKeyState(0x57);
	d = GetKeyState(0x44);
	a = GetKeyState(0x41);
	s = GetKeyState(0x53);
	up = GetAsyncKeyState(0x26);
	down = GetAsyncKeyState(0x28);
	left = GetAsyncKeyState(0x25);
	right = GetAsyncKeyState(0x27);
	if (GetAsyncKeyState(0x20))//space   �o�g�l�u
	{
		if (count_space_key == 3)
		{
			if (surplus_bullet >= 1)
			{
				generate_bullet(current_xy);   //�w�g�O���w�N���ΦA�ǻ��a�}
			}
			else
			{
				agree_reload = 1;
			}
			count_space_key = 0;
		}
		count_space_key++;
		
	}
	if (w < 0 && d < 0 || right<0 && up<0) //�k�W
	{
		if (count_rightup_key == 1)
		{
			current_xy->Y -= 1;
			current_xy->X += 1;
			count_rightup_key = 0;
		}
		else
			count_rightup_key++;
		return 0;
	}
	if (w < 0 && a < 0  || left<0 && up<0) //���W
	{
		if (count_leftup_key == 1)
		{
			current_xy->Y -= 1;
			current_xy->X -= 1;
			count_leftup_key = 0;
		}
		else
			count_leftup_key++;
		return 0;
	}
	if (d < 0 && s < 0 || right<0 && down<0) //�k�U
	{
		if (count_rightdown_key == 1)
		{
			current_xy->Y += 1;
			current_xy->X += 1;
			count_rightdown_key = 0;
		}
		else
			count_rightdown_key++;
		return 0;
	}
	if (a < 0 && s < 0 || left<0 && down<0) //���U
	{
		if (count_leftdown_key == 1)
		{
			current_xy->Y += 1;
			current_xy->X -= 1;
			count_leftdown_key = 0;
		}
		else
			count_leftdown_key++;
		return 0;
	}
	if (GetAsyncKeyState(0x41) || GetAsyncKeyState(0x25)) //��
	{
		current_xy->X -= 1;
		return 0;
	}
	if (GetAsyncKeyState(0x44) || GetAsyncKeyState(0x27))//�k
	{
		current_xy->X += 1;
		return 0;
	}
	if (GetAsyncKeyState(0x57) || GetAsyncKeyState(0x26))//�W
	{
		if (count_up_key == 2)
		{
			current_xy->Y -= 1;
			count_up_key = 0;
		}
		count_up_key++;
		return 0;
	}
	if (GetAsyncKeyState(0x53) || GetAsyncKeyState(0x28))//�U
	{
		if (count_down_key == 2)
		{
			current_xy->Y += 1;
			count_down_key = 0;
		}
		count_down_key++;
		return 0;
	}
	return 0;
}
int exceed_border(COORD* current_xy) //�P�_�����������
{
	if (current_xy->X>51)  
	{
		current_xy->X = 51;
		return 0;
	}
	if (current_xy->X < 2)
	{
		current_xy->X = 2;
		return 0;
	}
	if (current_xy->Y < 2)
	{
		current_xy->Y = 2;
		return 0;
	}
	if (current_xy->Y >43)
	{
		current_xy->Y = 43;
		return 0;
	}
	return 0;
}
void Geneate_star_function(struct star_position** first_lineOfStar,struct star_position** last_LineOfStar,int CONTROL_star_amount)
{
	int line, i, percent;
	for (line = 48; line >= 1; line--)
	{
		struct star_position* new_line = (struct star_position*)malloc(sizeof(struct star_position));
		for (i = 0; i < CONTROL_star_amount; i++)
		{
			percent = rand() % 2;              //percent ���O1 �N�O0   
			new_line->pos[i].Y = line;
			new_line->old_pos[i].X = new_line->old_pos[i].Y = 0;
			if (percent == 1)                 //�@�b���v�ݷ|���|��x?
			{
				new_line->pos[i].X = rand() % 56 + 2;
			}
			else
				new_line->pos[i].X = 0;
		}
		if (line == 48)
		{
			*first_lineOfStar = new_line;
			*last_LineOfStar = new_line;
			(*first_lineOfStar)->pnext = NULL;
		}
		else
		{
			(*last_LineOfStar)->pnext = new_line;
			*last_LineOfStar = new_line;
			(*last_LineOfStar)->pnext = NULL;
		}
	}
}
void geneate_star() //rand() % 52 + 2;//1~49
{
	Geneate_star_function(&first_lineOfStar, &last_LineOfStar,CONTROL_star_amount);
	Geneate_star_function(&first_lineOfStar_2, &last_LineOfStar_2, CONTROL_star_amount_2);
}
void generate_bullet(COORD* current_xy)
{
	if (weapon_choose == 1)   
	{
		struct bullet_pos *bullet = (struct bullet_pos*)malloc(sizeof(struct bullet_pos));
		bullet_amount++;
		surplus_bullet -= 1;
		bullet->pos.X = current_xy->X + 3;
		bullet->pos.Y = current_xy->Y-1;
		bullet->bullet_type = 1;//�ĴX�ؼu��
		bullet->last_pnext = NULL;
		if (bullet_amount == 1)              //�Ĥ@���l�u
		{
			first_bullet = bullet;
			last_bullet = bullet;	
		}
		else
		{
			bullet->last_pnext = last_bullet;//�ثe���`�I ���V�W�@�ӱo�`�I=�W�@�Ӹ`�I
			last_bullet->pnext = bullet;//�W�@�Ӹ`�I ���V�o�U�@�Ӹ`�I=�ثe���`�I
			last_bullet = bullet;       //���w�ثe���`�I���̫�@��
		}
		bullet->pnext = NULL;
	}
	else if (weapon_choose == 2)
	{
		surplus_bullet -= 2;
		struct bullet_pos *bullet = (struct bullet_pos*)malloc(sizeof(struct bullet_pos));
		struct bullet_pos *bullet2 = (struct bullet_pos*)malloc(sizeof(struct bullet_pos));
		bullet->pos.X = current_xy->X + 7;
		bullet->pos.Y = current_xy->Y + 1;
		bullet2->pos.X = current_xy->X + 1;
		bullet2->pos.Y = current_xy->Y + 1;
		bullet->bullet_type = 2;
		bullet2->bullet_type = 2;
		bullet->last_pnext = NULL;
		bullet->pnext = bullet2;
		bullet2->last_pnext = bullet;
		bullet2->pnext = NULL;
		if (bullet_amount_2 == 0)   //�Y�S���Y�l�u
		{
			first_bullet_2 = bullet;                   //�Y�l�u
			last_bullet_2 = bullet2;					//�̫�@�Ӥl�u
		}
		else
		{
			bullet->last_pnext = last_bullet_2;
			last_bullet_2->pnext = bullet;        //���e���ͤl�u����_�� ���̫᭱
			last_bullet_2 = bullet2;
		}
		bullet_amount_2 += 2;//�l�u+2
	}
	else    //weapon_choose 3
	{
		struct bullet_pos *bullet = (struct bullet_pos*)malloc(sizeof(struct bullet_pos));
		struct bullet_pos *bullet2 = (struct bullet_pos*)malloc(sizeof(struct bullet_pos));
		struct bullet_pos *bullet3 = (struct bullet_pos*)malloc(sizeof(struct bullet_pos));
		struct bullet_pos *bullet4 = (struct bullet_pos*)malloc(sizeof(struct bullet_pos));
		bullet->bullet_type = 3;
		bullet2->bullet_type = 3;
		bullet3->bullet_type = 3;
		bullet4->bullet_type = 3;
		bullet->pos.X = current_xy->X + 2;
		bullet->pos.Y = current_xy->Y - 1;
		bullet2->pos.X = current_xy->X + 3;
		bullet2->pos.Y = current_xy->Y - 1;
		bullet3->pos.X = current_xy->X + 4;
		bullet3->pos.Y = current_xy->Y - 1;
		bullet4->pos.X = current_xy->X + 5;
		bullet4->pos.Y = current_xy->Y - 1;
		bullet->last_pnext = NULL;
		bullet->pnext = bullet2;
		bullet2->last_pnext = bullet;
		bullet2->pnext = bullet3;
		bullet3->last_pnext = bullet2;
		bullet3->pnext = bullet4;
		bullet4->last_pnext = bullet3;
		bullet4->pnext = NULL;
		if (bullet_amount_3 == 0)   //�Y�S���Y�l�u
		{
			first_bullet_3 = bullet;                   //�Y�l�u
			last_bullet_3 = bullet4;					//�̫�@�Ӥl�u
		}
		else
		{
			bullet->last_pnext = last_bullet_3;
			last_bullet_3->pnext = bullet;        //���e���ͤl�u����_�� ���̫᭱
			last_bullet_3 = bullet4;
		}
		bullet_amount_3 += 4;//�l�u+3
	}

}
void generate_enemy_little_bee()  //���ͼĤH
 {
	little_bee_amount++;
	struct position *tmp_little_bee = (struct position *)malloc(sizeof(struct position));//�{���ܼ�
	tmp_little_bee->old_pos.X=tmp_little_bee->pos.X = rand() % 52 + 2;//1~49    //�H��x�b��l
	//tmp_little_bee->old_pos.X = tmp_little_bee->pos.X = 25; //debug
	tmp_little_bee->old_pos.Y=tmp_little_bee->pos.Y = 1;
	tmp_little_bee->line_count = 1;
	tmp_little_bee->old_line_count = 1;
	tmp_little_bee->last_current_enemy = tmp_little_bee->pos;
	tmp_little_bee->last_pnext = NULL;
	tmp_little_bee->pnext = NULL;
	if (little_bee_first == NULL)//�p�G�Y���w���� ��o���w�]���Y���w
	{
		little_bee_first = tmp_little_bee;
		little_bee_last = tmp_little_bee;

	}
	else                        //�p�G�o�����w�g���F�� ���b�̫�@�ӫ��w���᭱
	{
		tmp_little_bee->last_pnext = little_bee_last;
		little_bee_last->pnext = tmp_little_bee;
		little_bee_last = tmp_little_bee;
	}

	
}
void show_all_data()
{
	show_health();
	if (agree_reload == 0)
	{
		show_ammo();
	}
	else //agree reload
	{
		reload_ammo();
	}

}
void reload_ammo()
{
	int i;
	COORD reload_pos;
	reload_pos.X = 70;
	reload_pos.Y = 40;
	if (count_main_while_time % 6 == 0) //�ˤl�u�ɶ�
		reload_time++;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), reload_pos);//�����ª��M��
	printf("                      ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), reload_pos);
	for (i = 0; i < reload_time;i++)
	{
		SetColor(9);
		printf("�p");
	}
	if (reload_time == 10) //�`�l�u��/2
	{
		agree_reload = 0;
		surplus_bullet = 20;
		reload_time = 0;
	}
	SetColor(7);
}
void show_ammo()
{
	int i;
	COORD bullet_pos;
	bullet_pos.X = 70;
	bullet_pos.Y = 40;
	COORD rim;
	COORD word;
	rim.X = bullet_pos.X - 2;
	rim.Y = bullet_pos.Y - 1;
	word.X = bullet_pos.X - 7;
	word.Y = bullet_pos.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bullet_pos);//�����ª��M��
	printf("                      ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rim);
	printf("�z                    �{");
	rim.Y += 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rim);
	printf("�|                    �}");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), word);
	printf("�l�u:");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bullet_pos);
	if (weapon_choose == 3)
	{
		surplus_bullet = 20;
	}
	for (i = 0; i < surplus_bullet; i++)
	{
		SetColor(11);
		printf("|");
	}
	printf("\n");
	SetColor(7);
}
void show_health()
{
	int i;
	COORD health_pos;
	health_pos.X = 70;
	health_pos.Y = 44;
	COORD rim;
	COORD word;
	rim.X = health_pos.X - 2;
	rim.Y = health_pos.Y - 1;
	word.X = health_pos.X - 7;
	word.Y = health_pos.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), health_pos);//�����ª��M��
	printf("                      ");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),rim);
	printf("�z            �{");
	rim.Y +=2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), rim);
	printf("�|            �}");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), word);
	printf("��q:");
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), health_pos);
	for (i = 0; i < health; i++)
	{
		SetColor(4);
		printf("�h");
	}
	printf("\n");
	SetColor(7);
}
void JUDGE_star_funtion(struct star_position** first_lineOfStar,struct star_position** last_LineOfStar,int CONTROL_star_amount )  //�o����w�|����V �ҥH�n�ΤG�ū��w
{
	COORD xy;
	int i, percent;
	struct star_position* ready_to_free = *first_lineOfStar; //���Y���w���s�_�� �H�ɷǳQ����
	*first_lineOfStar = (*first_lineOfStar)->pnext; //�����Y���w
	struct star_position* new_line = (struct star_position*)malloc(sizeof(struct star_position));
	for (i = 0; i < CONTROL_star_amount; i++)
	{
		percent = rand() % 2;              //percent ���O1 �N�O0   
		new_line->pos[i].Y = 1;
		new_line->old_pos[i].X = new_line->old_pos[i].Y = 0;
		if (percent == 1)                 //�@�b���v�ݷ|���|��x?
			new_line->pos[i].X = rand() % 56 + 2;
		else
			new_line->pos[i].X = 0;
		xy = ready_to_free->pos[i];                 //�����Y���w���Ϯץh��
		xy.Y -= 1;
		if (xy.X == 0)
			xy.X = 2;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
		printf(" ");
	}
	(*last_LineOfStar)->pnext = new_line;
	*last_LineOfStar = new_line;
	(*last_LineOfStar)->pnext = NULL;
	free(ready_to_free);
}
void JUDGE_bullet_function(struct bullet_pos** first_bullet, int* bullet_amount)  //�ѩ�|���s���ܫ��w���V �ҥH�ݭn�ΤG�ū��w �P�_�l�u�O�_�W�L���
{
	while (1)
	{
		if ((*first_bullet)->pos.Y <= 1)  //�p�G�W�L���
		{
			struct bullet_pos * ready_to_free = NULL;
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), (*first_bullet)->pos);
			printf(" ");
			ready_to_free = *first_bullet;
			if ((*first_bullet)->pnext == NULL)//�p�G�O�̫�@�o�l�u �N���Y�l�u���VNULL
			{
				*first_bullet = NULL;
				*bullet_amount = 0;             //�S���l�u�F
				break;
			}
			else
			{
				*first_bullet = (*first_bullet)->pnext;   //���ĤG���l�u ���Ĥ@��l�u
				(*first_bullet)->last_pnext = NULL;      //�]���ĤG���l�u �ܦ��Ĥ@���F �ҥH�n����V�W�@�Ӹ`�I���w ���s���VNULL
				free(ready_to_free);                     //��Ĥ@��l�u���񤺦s
				*bullet_amount -= 1;                    //�l�u�֤@��
			}
		}
		else
			break;
	}
}
void judge_bullet()//�P�_�l�u�ϧ_�W�X��� �Y�W�X�h���񱼰O����
{ 
	if (first_bullet != NULL )
	{
		JUDGE_bullet_function(&first_bullet, &bullet_amount);
	}
	if (first_bullet_2 != NULL )
	{
		JUDGE_bullet_function(&first_bullet_2, &bullet_amount_2);
	}
	if (first_bullet_3 != NULL)
	{
		JUDGE_bullet_function(&first_bullet_3, &bullet_amount_3);
	}
}

void UPDATE_star_xy_funtion(struct star_position* first_lineOfStar,int CONTROL_star_amount)
{
	int i;
	current_LineOfStar = first_lineOfStar;
	while (1)
	{
		for (i = 0; i < CONTROL_star_amount; i++)   //�b��s�y�Ф��e ���ª�?�s�_��
		{
			current_LineOfStar->old_pos[i] = current_LineOfStar->pos[i];
			current_LineOfStar->pos[i].Y++;
		}
		if (current_LineOfStar->pnext == NULL)
			break;
		else
			current_LineOfStar = current_LineOfStar->pnext;
	}
}
void UPDATE_enemy_list(struct position* first_point, int AI,COORD* current_xy)//��s�ĤH�y�� //current_xy =�����y��
{
	struct position* current_point = NULL;
	current_point = first_point;
	while (1)
	{
		current_point->old_pos = current_point->pos;//�b��s�y�Ф��e ���ª�?�s�_��
		current_point->pos.Y += 1;
		if (AI == 1)                //AI:��ۭ�����
		{
			if (current_point->pos.Y < current_xy->Y+6)
			{
				if (current_point->pos.X < current_xy->X)
					current_point->pos.X += 1;
				if (current_point->pos.X > current_xy->X)
					current_point->pos.X -= 1;
			}
		}
		if (current_point->pnext == NULL)
			break;
		else
			current_point = current_point->pnext;
	}
}
void update_enemy_xy(COORD* current_xy)
{
	if (little_bee_first != NULL)
	{
		if (count_main_while_time % CONTROL_little_bee_move_time == 0) //�p�G�D�j�骺�ܼƯ�Ƨڳ]�w��?�㰣 �N��s�y��
		{
			UPDATE_enemy_list(little_bee_first, AI, current_xy);
		}
	}
}
void UPDATE_bullet_list(struct bullet_pos* first_point) //��s�l�u�y��
{
	struct bullet_pos* current_bullet = NULL;//�Ψ������run�@�M�����w
	current_bullet = first_point;
	while (1)
	{
		current_bullet->pos.Y -= 1;
		if (current_bullet->pnext == NULL)
			break;
		else
			current_bullet = current_bullet->pnext;
	}
}
void update_bullet_xy()//�Ψӭp��l�u�C�����ʱo�s��l
{
	if (first_bullet != NULL)
	{
		UPDATE_bullet_list(first_bullet);
	}
	if (first_bullet_2 != NULL)
	{
		UPDATE_bullet_list(first_bullet_2);
	}
	if (first_bullet_3 != NULL)
	{
		UPDATE_bullet_list(first_bullet_3);
	}
}
void PRINT_bullet_function(struct bullet_pos* first_bullet)
{
	struct bullet_pos* current_bullet = NULL;//�Ψ������run�@�M�����w
	current_bullet = first_bullet;
	while (1)
	{
		tmp_old_bullet = current_bullet->pos;
		tmp_old_bullet.Y += 1;//���M���¸��
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmp_old_bullet);
		printf(" ");
		tmp_old_bullet.Y -= 1;//���L�s����l
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), tmp_old_bullet);
		switch (current_bullet->bullet_type)
		{
		case 1:
			SetColor(11);
			printf("*"); 
			break;
		case 2:
			SetColor(11);
			printf("-");
			break;
		case 3:
			SetColor(10);
			printf("|");
			break;
		}
		if (current_bullet->pnext == NULL)
			break;
		current_bullet = current_bullet->pnext;
	}
	SetColor(7);
}
void print_bullet()
{
	if (first_bullet != NULL )
	{
		PRINT_bullet_function(first_bullet);
	}
	if (first_bullet_2 != NULL )
	{
		PRINT_bullet_function(first_bullet_2);
	}
	if (first_bullet_3 != NULL)
	{
		PRINT_bullet_function(first_bullet_3);
	}
}
void printf_all_enemy()
{
	if (little_bee_first != NULL)
	{
		COORD xy;
		int i;
		struct position* current_enemy=little_bee_first;//���Ĥ@�ӫ��w
		while (1)
		{
			xy.X = current_enemy->pos.X;
			xy.Y = current_enemy->pos.Y; 
			if (current_enemy->last_current_enemy.Y != current_enemy->pos.Y)//�p�G�ª��y�ЩM�{�b���y�Ф��@�˥N��n��s�y�� 
			{
				if (current_enemy->pos.Y < 49)//�p�G�p��49�楿�`���L���� �p�G�j��49�}�l�ʵe �@��@�����
				{
					xy.Y = current_enemy->old_pos.Y;              //���W�@���®y��
					for (i = 0; i < current_enemy->old_line_count; i++)
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
						printf("      ");
						xy.Y -= 1;//�W�@��Ϯ�
					}
					xy.Y = current_enemy->pos.Y;//�p�G��Ū�i�o�Ӱ϶� ���s��l��y�y�� ��K�U���϶��ϥ�
					for (i = 0; i < current_enemy->line_count; i++)
					{
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
						if (i == 0)
						{
							printf("  ��");
						}
						if (i == 1)
						{
							printf(" -�i-");
						}
						if (i == 2)
						{
							printf("  �s");
						}
						xy.Y -= 1;//�W�@��Ϯ�
					}
					current_enemy->last_current_enemy = current_enemy->pos; //��ثe��l�s�_�� �d���U���j����
					if (current_enemy->line_count == 2)  ////�P�_�u���u��2��ϧή�
					{
						current_enemy->old_line_count = current_enemy->line_count;
						current_enemy->line_count += 1;
					}
					else
					{
						current_enemy->old_line_count = 3;
					}
				}
				else   //�ʵe�ĪG
				{
					if (current_enemy->pos.Y == 49)
					{
						xy.Y = current_enemy->old_pos.Y; //�p�G��Ū�i�o�Ӱ϶� ���s��l��y�y�� ��K�U���϶��ϥ�
						xy.Y -= 2;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
						printf("       ");
						xy.Y += 2;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
						printf(" -�i-");
						xy.Y -= 1;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
						printf("  �s  ");
					}
					else if (current_enemy->pos.Y == 50)
					{
						xy.Y = current_enemy->old_pos.Y; //�p�G��Ū�i�o�Ӱ϶� ���s��l��y�y�� ��K�U���϶��ϥ�
						xy.Y -= 1;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
						printf("       ");
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
						printf("  �s  ");
						xy.Y -= 1;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
						printf("       ");
					}
					else //�F����� �ǳ����񱼰O���� �ò��X���
					{
						little_bee_amount--;
						xy.Y = current_enemy->old_pos.Y;
						xy.Y -= 2;
						SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
						printf("      ");
						if (little_bee_amount == 0)//�p�G���W�S�����󭸾� �������w�]����
						{
							free(little_bee_first);
							little_bee_first = NULL;
							break;
						}
						else                      
						{
							little_bee_first = current_enemy->pnext;//�Y���w�󴫦��U�@��
							free(current_enemy);
							current_enemy = little_bee_first;
							continue;
						}
					}
				}
			}
			if (current_enemy->line_count == 1)   //�P�_�u���@��ϧή�
			{
				xy.X = current_enemy->pos.X;
				xy.Y = current_enemy->pos.Y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
				printf("  ��");
				current_enemy->old_line_count = current_enemy->line_count;
				current_enemy->line_count += 1;
			}
			if (current_enemy->pnext == NULL)
				break;
			current_enemy = current_enemy->pnext;
		}
	}
}
void PRINT_airplane(COORD* current_xy,int choose_weapon)
{
	int i;
	COORD xy;
	xy.X = current_xy->X;
	xy.Y = current_xy->Y;
	if (count_main_while_time != 1)  //�p�G�O�Ĥ@���j�� �N���L�����ª�����
	{
		for (i = 0; i < 6; i++)
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), old_airplane_pos);
			printf("        ");
			old_airplane_pos.Y += 1;
		}
	}
	old_airplane_pos = xy; //��{�b�o��l�s�_�ӯd���U�@�Ӱj�� �o���í�����
	for (i = 0; i < 6; i++)  //���L����
	{
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
		switch (choose_weapon)
		{
		case 1:
			weapon1(i);
			break;
		case 2:
			weapon2(i);
			break;
		case 3:
			weapon3(i);
			break;
		}
		xy.Y += 1;//�C�L���@�� �ǳƦC�L�U�@��
	}
}
void PRINT_star_funtion(struct star_position* first_lineOfStar, int CONTROL_star_amount, int color )
{
	SetColor(color);
	COORD xy;
	int i;
	current_LineOfStar = first_lineOfStar;
	while (1)
	{
		for (i = 0; i < CONTROL_star_amount; i++)
		{
			if (current_LineOfStar->pos[i].X != 0) //�p�Gx������ �N���L
			{

				if (current_LineOfStar->old_pos[i].Y != 0)
				{
					xy = current_LineOfStar->old_pos[i];
					SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
					printf(" ");
				}
				xy = current_LineOfStar->pos[i];
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
				printf(".");
			}
		}
		if (current_LineOfStar->pnext == NULL)
			break;
		else
			current_LineOfStar = current_LineOfStar->pnext;
	}
	SetColor(7);
}
void print_explosion()
{
	if (first_animation != NULL)
	{
		struct explosion* current_explo=first_animation;
		while (1)
		{
			if (current_explo->delay_time%CONTROL_explo_animation_time == 0)    //��s�z���ʵe�W�v
			{
				PRINT_explosion(current_explo, current_explo->line_status, current_explo->status);
				current_explo->status -= 1;
			}
			if (current_explo->status ==-1)  //�^��2 �N��`�I�ǳ�����
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), current_explo->pos);
				printf("     ");
				current_explo->pos.Y -= 1;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), current_explo->pos);
				printf("     ");
				current_explo->pos.Y -= 1;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), current_explo->pos);
				printf("     ");
				struct explosion* ready_to_free = current_explo;
				if (current_explo->pnext == NULL)   //�p�G�O�̫�@�Ӹ`�I
				{
					free(ready_to_free);
					first_animation = NULL;
					last_animation = NULL;
					break;
				}
				else
				{
					first_animation = current_explo->pnext;
					current_explo = first_animation;
					continue;
				}
			}
			else //�٦��U�@���z���`�I
			{
				current_explo->delay_time += 1;
			}
			if (current_explo->pnext == NULL)
			{
				break;
			}
			current_explo = current_explo->pnext;
		}
	}
}
void print_all(COORD* current_xy)
{
	PRINT_airplane(current_xy, weapon_choose);  //���L����
	if ((bullet_amount+bullet_amount_2+bullet_amount_3) >= 1)   //�p�G���l�u�~���L
		print_bullet();
	printf_all_enemy();
	print_explosion();
}