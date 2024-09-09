import  pygame

def abc(screen1,x,y,a):
# 定义颜色
    BLACK = (0, 0, 0)
    WHITE = (255, 255, 255)
    ORANGE = (255, 165, 0)
    RED = (a%255, 150, 150)
    GRAY = (200, 200, 200)


        # 绘制企鹅身体
    pygame.draw.circle(screen1, BLACK, (x, y), 33)  # 身体
    pygame.draw.circle(screen1, WHITE, (x, y),26 )  # 白色肚子

        # 绘制企鹅眼睛
    pygame.draw.circle(screen1, WHITE, (x-10, y-10), 6)  # 左眼白
    pygame.draw.circle(screen1, WHITE, (x+10, y-10), 6)  # 右眼白
    pygame.draw.circle(screen1, BLACK, (x-10, y-10), 3)  # 左眼黑
    pygame.draw.circle(screen1, BLACK, (x+10, y-10), 3)  # 右眼黑

        # 绘制企鹅嘴巴
    pygame.draw.polygon(screen1, ORANGE, [(x-(400-390)/3, y), (x-(400-410)/3, y), (x, y-(300-320)/3)])  # 嘴巴

        # 绘制企鹅翅膀
    pygame.draw.ellipse(screen1, BLACK, [x-(400-300)/3, y-(300-270)/3, 40/3, 80/3])  # 左翅膀
    pygame.draw.ellipse(screen1, BLACK, [x-(400-460)/3, y-(300-270)/3, 40/3, 80/3])  # 右翅膀

        # 绘制企鹅脚
    pygame.draw.polygon(screen1, ORANGE, [(x-(400-360)/3, y-(300-380)/3), (x-(400-370)/3, y-(300-400)/3), (x-(400-350)/3, y-(300-400)/3)])  # 左脚
    pygame.draw.polygon(screen1, ORANGE, [(x-(400-440)/3, y-(300-380)/3), (x-(400-430)/3, y-(300-400)/3), (x-(400-450)/3, y-(300-400)/3)])  # 右脚

        # 绘制帽子
    pygame.draw.polygon(screen1, RED, [(x-(400-370)/3, y-(300-220)/3), (x-(400-430)/3, y-(300-220)/3), (x, y-(300-170)/3)])  # 帽子
    pygame.draw.circle(screen1, GRAY, (x, y-(300-170)/3), 10/3)  # 帽子顶部的白球
    pygame.draw.rect(screen1, GRAY, [x-(400-370)/3, y-(300-220)/3, 60/3, 10/3])  # 帽子的白色边

def bcd(screen1,x,y,a):
# 定义颜色
    BLACK = (0, 0, 0)
    WHITE = (255, 255, 255)
    ORANGE = (255, 165, 0)
    RED = (155, a%255, 150)
    GRAY = (200, 200, 200)


        # 绘制企鹅身体
    pygame.draw.circle(screen1, GRAY, (x, y), 33)  # 身体
    pygame.draw.circle(screen1, WHITE, (x, y),26 )  # 白色肚子

        # 绘制企鹅眼睛
    pygame.draw.circle(screen1, WHITE, (x-10, y-10), 6)  # 左眼白
    pygame.draw.circle(screen1, WHITE, (x+10, y-10), 6)  # 右眼白
    pygame.draw.circle(screen1, BLACK, (x-10, y-10), 3)  # 左眼黑
    pygame.draw.circle(screen1, BLACK, (x+10, y-10), 3)  # 右眼黑

        # 绘制企鹅嘴巴
    pygame.draw.polygon(screen1, ORANGE, [(x-(400-390)/3, y), (x-(400-410)/3, y), (x, y-(300-320)/3)])  # 嘴巴

        # 绘制企鹅翅膀
    pygame.draw.ellipse(screen1, GRAY, [x-(400-300)/3, y-(300-270)/3, 40/3, 80/3])  # 左翅膀
    pygame.draw.ellipse(screen1, GRAY, [x-(400-460)/3, y-(300-270)/3, 40/3, 80/3])  # 右翅膀

        # 绘制企鹅脚
    pygame.draw.polygon(screen1, ORANGE, [(x-(400-360)/3, y-(300-380)/3), (x-(400-370)/3, y-(300-400)/3), (x-(400-350)/3, y-(300-400)/3)])  # 左脚
    pygame.draw.polygon(screen1, ORANGE, [(x-(400-440)/3, y-(300-380)/3), (x-(400-430)/3, y-(300-400)/3), (x-(400-450)/3, y-(300-400)/3)])  # 右脚

        # 绘制帽子
    pygame.draw.polygon(screen1, RED, [(x-(400-370)/3, y-(300-220)/3), (x-(400-430)/3, y-(300-220)/3), (x, y-(300-170)/3)])  # 帽子
    pygame.draw.circle(screen1, GRAY, (x, y-(300-170)/3), 10/3)  # 帽子顶部的白球
    pygame.draw.rect(screen1, GRAY, [x-(400-370)/3, y-(300-220)/3, 60/3, 10/3])  # 帽子的白色边


