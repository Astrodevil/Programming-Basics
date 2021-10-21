import pygame
import time
import random

pygame.init()

screen = pygame.display.set_mode((854, 700))
pygame.display.set_caption("Snakes and Ladders")

black = (0, 0, 0 )

# buttons
roll_img = pygame.image.load("DATA/roll.png")
roll_img = pygame.transform.scale(roll_img, (100, 40))
roll_rect = roll_img.get_rect()
roll_rect.topleft = (28, 430)



# load assest
        # Load board
board = pygame.image.load("DATA/board.png")
        # Load dice
dice1 = pygame.transform.scale(pygame.image.load("DATA/1.png"), (50, 50))
dice2 = pygame.transform.scale(pygame.image.load("DATA/2.png"), (50, 50))
dice3 = pygame.transform.scale(pygame.image.load("DATA/3.png"), (50, 50))
dice4 = pygame.transform.scale(pygame.image.load("DATA/4.png"), (50, 50))
dice5 = pygame.transform.scale(pygame.image.load("DATA/5.png"), (50, 50))
dice6 = pygame.transform.scale(pygame.image.load("DATA/6.png"), (50, 50))
        # Pins
pin_r = pygame.transform.scale(pygame.image.load("DATA/pin_r.png"), (30, 30))
pin_y = pygame.transform.scale(pygame.image.load("DATA/pin_y.png"), (30, 30))
pin_p = pygame.transform.scale(pygame.image.load("DATA/pin_p.png"), (30, 30))
pin_b = pygame.transform.scale(pygame.image.load("DATA/pin_b.png"), (30, 30))

        # fonts
player1_font = pygame.font.SysFont('comicsansms', 22)

# ##### LIST of coordinates

red_coord = [(185, 650), (245, 650), (320, 650), (395, 650), (455, 650), (530, 650), (590, 650), (660, 650), (735, 650), (810, 650), 
            (810, 575), (735, 575), (660, 575), (590, 575), (530, 575), (455, 575), (395, 575), (320, 575), (245, 575), (185, 575),
            (185, 505), (245, 505), (320, 505), (395, 505), (455, 505), (530, 505), (590, 505), (660, 505), (735, 505), (810, 505),
            (810, 435), (735, 435), (660, 435), (590, 435), (530, 435), (455, 435), (395, 435), (320, 435), (245, 435), (185, 435),
            (185, 365), (245, 365), (320, 365), (395, 365), (455, 365), (530, 365), (590, 365), (660, 365), (735, 365), (810, 365),
            (810, 295), (735, 295), (660, 295), (590, 295), (530, 295), (455, 295), (395, 295), (320, 295), (245, 295), (185, 295),
            (185, 225), (245, 225), (320, 225), (395, 225), (455, 225), (530, 225), (590, 225), (660, 225), (735, 225), (810, 225),
            (810, 155), (735, 155), (660, 155), (590, 155), (530, 155), (455, 155), (395, 155), (320, 155), (245, 155), (185, 155),
            (185, 85), (245, 85), (320, 85), (395, 85), (455, 85), (530, 85), (590, 85), (660, 85), (735, 85), (810, 85),
            (810, 15), (735, 15), (660, 15), (590, 15), (530, 15), (455, 15), (395, 15), (320, 15), (245, 15), (185, 15)]

yellow_coord = [(185, 650), (245, 650), (320, 650), (395, 650), (455, 650), (530, 650), (590, 650), (660, 650), (735, 650), (810, 650), 
            (810, 575), (735, 575), (660, 575), (590, 575), (530, 575), (455, 575), (395, 575), (320, 575), (245, 575), (185, 575),
            (185, 505), (245, 505), (320, 505), (395, 505), (455, 505), (530, 505), (590, 505), (660, 505), (735, 505), (810, 505),
            (810, 435), (735, 435), (660, 435), (590, 435), (530, 435), (455, 435), (395, 435), (320, 435), (245, 435), (185, 435),
            (185, 365), (245, 365), (320, 365), (395, 365), (455, 365), (530, 365), (590, 365), (660, 365), (735, 365), (810, 365),
            (810, 295), (735, 295), (660, 295), (590, 295), (530, 295), (455, 295), (395, 295), (320, 295), (245, 295), (185, 295),
            (185, 225), (245, 225), (320, 225), (395, 225), (455, 225), (530, 225), (590, 225), (660, 225), (735, 225), (810, 225),
            (810, 155), (735, 155), (660, 155), (590, 155), (530, 155), (455, 155), (395, 155), (320, 155), (245, 155), (185, 155),
            (185, 85), (245, 85), (320, 85), (395, 85), (455, 85), (530, 85), (590, 85), (660, 85), (735, 85), (810, 85),
            (810, 15), (735, 15), (660, 15), (590, 15), (530, 15), (455, 15), (395, 15), (320, 15), (245, 15), (185, 15)]

def ladder_detect(value):
    if value == 3:
        value = 55
        print(value)
        return value 
    elif value == 40:
        value = 78
        return value 
    elif value == 11:
        value = 49
        return value 
    elif value == 53:
        value = 87
        return value 
    else:
        return value
      

           
# pins pos x and y
red_pos = (25,650)
yellow_pos = (75,650)

# pin pos count according to board
rp_pos = 0
yp_pos = 0

# pins insde a board or not
r_start = False
y_start = False

# turn defined
turn = 'red'
dice = dice6
p_turn = player1_font.render(turn + ' turn', True, (0,0,0))
run = True
while run:

        # coordinates of mouse 
    mx, my = pygame.mouse.get_pos()
    
        # white color of background
    screen.fill((255, 255, 255))

        # render board
    screen.blit(board, (150, 0))

        # render pin
    screen.blit(pin_r, red_pos)
    screen.blit(pin_y, yellow_pos)
    

    # Render roll button
    screen.blit(roll_img, (28,430))

    # render dice
    screen.blit(dice, (45, 350))

    # player turn display
    screen.blit(p_turn, (20, 520))
    

    for event in pygame.event.get():
        # quit
        if event.type == pygame.QUIT:
            run = False
        
        if event.type == pygame.MOUSEBUTTONDOWN:

            # get mouse pos
            pos = pygame.mouse.get_pos()

            # get random number
            dice_val = random.randint(1,6)

            if roll_rect.collidepoint(pos):
                time.sleep(0.3)
                # dice roll
                if dice_val == 1:
                    dice = dice1
                    num = 1
                elif dice_val == 2:
                    dice = dice2
                    num = 2
                elif dice_val == 3:
                    dice = dice3
                    num = 3
                elif dice_val == 4:
                    dice = dice4
                    num = 4
                elif dice_val == 5:
                    dice = dice5
                    num = 5
                else:
                    dice = dice6
                    num = 6
                

                # red player turn
                if turn=='red':
                    p_turn = player1_font.render(turn + ' turn', True, (0,0,0))
                    turn = 'yellow'
                    
                    if num == 6 and r_start == False:
                        red_pos = red_coord[0]
                        r_start = True
                        turn = 'red'
                        
                    
                    else:
                        if num != 6 and r_start == True:
                            rp_pos = rp_pos + num
                            if rp_pos >= 99:
                                rp_pos = 99
                                red_pos = red_coord[rp_pos]
                                print("red won")
                                time.sleep(1)
                                run = False

                            if num == 1:
                                red_pos = red_coord[rp_pos]
                                turn = 'yellow'
                                
                            elif num == 2:                            
                                red_pos = red_coord[rp_pos]
                                turn = 'yellow'

                            elif num == 3:
                                red_pos = red_coord[rp_pos]
                                turn = 'yellow'

                            elif num == 4:
                                red_pos = red_coord[rp_pos]
                                turn = 'yellow'

                            elif num == 5:
                                red_pos = red_coord[rp_pos]
                                turn = 'yellow'
                        else:
                            if num == 6 and r_start == True:
                                rp_pos = rp_pos + num
                                if rp_pos >= 99 and r_start == True:
                                    rp_pos = 99
                                    red_pos = red_coord[rp_pos]
                                    print("red won")
                                    time.sleep(1)
                                    run = False
                                red_pos = red_coord[rp_pos]
                                turn = 'red'
                         
 
                # yellow player turn 
                else:
                    p_turn = player1_font.render(turn + ' turn', True, (0,0,0))
                    turn = 'red'
                    
                    if num == 6 and y_start == False:
                        yellow_pos = yellow_coord[0]
                        y_start = True
                        turn = 'yellow'
                        
                    
                    else:
                        if num != 6 and y_start == True:
                            yp_pos = yp_pos + num
                            if yp_pos >=99 and y_start == True:
                                print('yellow won')
                                yp_pos = 99
                                yellow_pos = yellow_coord[yp_pos]
                                time.sleep(1)
                                run = False
                            if num == 1:
                                yellow_pos = yellow_coord[yp_pos]
                                turn = 'red'
                            elif num == 2:                            
                                yellow_pos = yellow_coord[yp_pos]
                                turn = 'red'
                            elif num == 3:
                                yellow_pos = yellow_coord[yp_pos]
                                turn = 'red'
                            elif num == 4:
                                yellow_pos = yellow_coord[yp_pos]
                                turn = 'red'
                            elif num == 5:
                                yellow_pos = yellow_coord[yp_pos]
                                turn = 'red'

                        else:
                            if num == 6 and y_start == True:
                                yp_pos = yp_pos + num
                                if yp_pos >=99 and y_start == True:
                                    print('yellow won')
                                    yp_pos = 99
                                    yellow_pos = yellow_coord[yp_pos]
                                    time.sleep(1)
                                    run = False
                                yellow_pos = yellow_coord[yp_pos]
                                turn = 'yellow'
                if r_start == True:
                    # ladder
                    if rp_pos == 3:
                        rp_pos = 55
                        red_pos = red_coord[rp_pos]
                    elif rp_pos == 11:
                        rp_pos = 49
                        red_pos = red_coord[rp_pos]
                    elif rp_pos == 13:
                        rp_pos = 54
                        red_pos = red_coord[rp_pos]
                    elif rp_pos == 21:
                        rp_pos = 57
                        red_pos = red_coord[rp_pos]
                    elif rp_pos == 40:
                        rp_pos = 78
                        red_pos = red_coord[rp_pos]
                    elif rp_pos == 53:
                        rp_pos = 87
                        red_pos = red_coord[rp_pos]
                    
                    # snake
                    elif rp_pos == 27:
                        rp_pos = 9
                        red_pos = red_coord[rp_pos]
                    elif rp_pos == 36:
                        rp_pos = 2
                        red_pos = red_coord[rp_pos]
                    elif rp_pos == 46:
                        rp_pos = 15
                        red_pos = red_coord[rp_pos]
                    elif rp_pos == 74:
                        rp_pos = 31
                        red_pos = red_coord[rp_pos]
                    elif rp_pos == 93:
                        rp_pos = 70
                        red_pos = red_coord[rp_pos]
                    elif rp_pos == 95:
                        rp_pos = 41
                        red_pos = red_coord[rp_pos]
                
                if y_start == True:
                    if yp_pos == 3:
                        yp_pos = 55
                        yellow_pos = yellow_coord[yp_pos]
                    elif yp_pos == 11:
                        yp_pos = 49
                        yellow_pos = yellow_coord[yp_pos]
                    elif yp_pos == 13:
                        yp_pos = 54
                        yellow_pos = yellow_coord[yp_pos]
                    elif yp_pos == 21:
                        yp_pos = 57
                        yellow_pos = yellow_coord[yp_pos]
                    
                    elif yp_pos == 40:
                        yp_pos = 78
                        yellow_pos = yellow_coord[yp_pos]
                    elif yp_pos == 53:
                        yp_pos = 87
                        yellow_pos = yellow_coord[yp_pos]
                    
                    # snake
                    elif yp_pos == 27:
                        yp_pos = 9
                        yellow_pos = yellow_coord[yp_pos]
                    elif yp_pos == 36:
                        yp_pos = 2
                        yellow_pos = yellow_coord[yp_pos]
                    elif yp_pos == 46:
                        yp_pos = 15
                        yellow_pos = yellow_coord[yp_pos]
                    elif yp_pos == 74:
                        yp_pos = 31
                        yellow_pos = yellow_coord[yp_pos]
                    elif yp_pos == 93:
                        yp_pos = 70
                        yellow_pos = yellow_coord[yp_pos]
                    elif yp_pos == 95:
                        yp_pos = 41
                        yellow_pos = yellow_coord[yp_pos]

                        
    pygame.display.update()
pygame.quit()
