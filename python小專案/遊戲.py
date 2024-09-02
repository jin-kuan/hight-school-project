import pygame 
import random
import pyautogui
from pygame.locals import *
# 初始化參數
size = 1000
screen = pygame.display.set_mode([size,size],0 , 32)
pygame.display.set_caption("貪吃蛇")
cell_size = 20
cell_num = int(size/20)
x , y = [60,0]
# 初始方向向右
dir_snake = 'R'
body_snake = [[0,0],[20,0],[40,0],[60,0]]
# 初始蛇長為3
len_snake = 40
# 初始食物坐標
food_coor = [random.randint(0, cell_num - 1) * 20, random.randint(0, cell_num - 1) * 20, 20, 20]
# 蛇移動速度
clock = pygame.time.Clock()
# bg
def bg():
    for i in range(0, size , int(cell_size)):
        pygame.draw.line(screen,[72,72,72],[i,0],[i,size])
    for i in range(0, size, int(cell_size)):
        pygame.draw.line(screen, [72, 72, 72], [0, i], [size,i])
# 蛇
def snake(K):
    for x,y in K[:-len_snake - 1:-1]:
        pygame.draw.rect(screen,[255,255,255],[x,y,20,20],0)
# 食物
def food():
    pygame.draw.rect(screen,[255,0,0],food_coor,0)
# 主循環
def running():
    global x ,y , dir_snake ,food_coor , len_snake
    while True:
        for event in pygame.event.get():
            if event.type == QUIT:
                exit()
        screen.fill((40, 43, 46))
        # 方向規則
        if dir_snake == 'U':
            y -= 20
        elif dir_snake == 'R':
            x += 20
        elif dir_snake == 'D':
            y += 20
        elif dir_snake == 'L':
            x -= 20
        # 鍵盤方向控制
        if event.type == KEYDOWN:
            if event.key == K_LEFT and dir_snake != 'R':
                dir_snake = 'L'
            elif event.key == K_DOWN and dir_snake != 'U':
                dir_snake = 'D'
            elif event.key == K_RIGHT and dir_snake != 'L':
                dir_snake = 'R'
            elif event.key == K_UP and dir_snake != 'D':
                dir_snake = 'U'
        # 撞墻之後
        if x < 0:
            x += size
        elif x >= size:
            x -= size
        elif y < 0:
            y += size
        elif y >= size:
            y -= size
        # draw蛇體
        body_snake.append([x,y])
        snake(body_snake)
        food()
        # 吃到食物後food換位置
        if [x,y] == food_coor[:2]:
            food_coor = [random.randint(0, cell_num - 1) * 20, random.randint(0, cell_num - 1) * 20, 20, 20]
            if food_coor[:2] in body_snake[-2:-len_snake -1 :-1]:
                food_coor = [random.randint(0, cell_num - 1) * 20, random.randint(0, cell_num - 1) * 20, 20, 20]
            len_snake +=1
        # 遊戲結束
        if body_snake[-1] in body_snake[-2:-len_snake -1 :-1]:
            pyautogui.alert(text='遊戲結束,最終蛇長為{}'.format(len_snake))
            exit()
        # 格線
        bg()
        # 右下角顯示蛇長
        font = pygame.font.SysFont("simsunnsimsun", 40)
        text_surface = font.render("{}".format(len_snake), True, (255,255, 255))
        screen.blit(text_surface , (size-40,size-40))
        pygame.display.update()
        # 蛇的移動速度隨著蛇的長度而越來越快
        clock.tick(len_snake *2)

if __name__ == '__main__':
    pygame.init()
    running()