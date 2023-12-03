import subprocess
import os
import time
import pygame as pg
import sys

def readfile(a,a1,a2,a3,a4):
    print(len(a))
    if len(a)==1:
        return([[a1,a2]],[[a3,a4]])
    a=a.split()
    way2=[]
    way1 =[]
    for i in range(len(a[0])//2):
        way1.append([0,0])
    for i in range(len(a[1])//2):
        way2.append([0,0])
    for i in range(len(a[0])//2):
        way1[i][0]=(int(a[0][i]))
        way1[i][1]=(int(a[0][i+len(a[0])//2]))
    for i in range(len(a[1])//2):
        way2[i][0]=(int(a[1][i]))
        way2[i][1]=(int(a[1][i+len(a[1])//2]))
    return(way1, way2)
def writefile(stx1,stx2,sty1,sty2,endx,endy,outp,ma,maf):
    wh='9'
    lh='9'
    sx1=str(stx1)
    sx2 = str(stx2)
    sy1 = str(sty1)
    sy2 = str(sty2)
    ex = str(endx)
    ey = str(endy)
    outp.write(sx1)
    outp.write(sx2)
    outp.write(sy1)
    outp.write(sy2)
    outp.write(wh)
    outp.write(lh)
    outp.write(ex)
    outp.write(ey)
    for i in range (9):
        for j in range(9):
            maf.write(str(ma[i][j]))
def up(a1,a2,a3,a4,a5,a6,ma):
    with open('input.txt','w') as out:
        with open ('maze.txt','w') as mazef:
            writefile(a1,a2,a3,a4,a5,a6,out,ma,mazef)
    with open('output.txt','r') as inp:
        a = inp.read()
    wa1,wa2=readfile(a,a1,a2,a3,a4)
    return(wa1,wa2)
def crwindow():
    pg.font.init()
    screen = pg.display.set_mode((500, 360))
    pg.display.set_caption(u'РОБОТЫ')
    return(screen)
def updateall(a1,a2,a3,a4,a5,a6,ma):
    up(a1, a2, a3, a4, a5, a6, ma)
    os.system("start backend.exe")
    time.sleep(0.5)
    w1,w2=up(a1,a2,a3,a4,a5,a6,ma)
    return(w1,w2)

scrn=crwindow()
flwork=True
clock = pg.time.Clock()
maze=[]
stx1=0
sty1=0
stx2=8
sty2=0
endx=8
endy=8
flgrabe1=False
flgrabe2=False
flgrabeh=False
flathome1=False
flathome2=False
flstart=False
floneupdate=False
nowx1=stx1
nowy1=sty1
nowx2=stx2
nowy2=sty2
inow1=0
inow2=0
count1=0
count2=0
for i in range(9):
    maze.append([1,1,1,1,1,1,1,1,1])
w1,w2=updateall(stx1,sty1,stx2,sty2,endx,endy,maze)
print(w1,'\n',w2)
text=pg.font.SysFont('arial', 25)
while flwork:
    posm=pg.mouse.get_pos()
    flmbupl=False
    flonemove=False
    for event in pg.event.get():
        if event.type == pg.QUIT:
            flwork=False
        if event.type == pg.MOUSEBUTTONUP and event.button==1:
            if flgrabe1==False and flgrabe2==False and flgrabeh==False:
                flmbupl=True
            if flgrabe1==True:
                flgrabe1=False
            if flgrabe2==True:
                flgrabe2=False
            if flgrabeh==True:
                flgrabeh=False
            if posm[0] in range(370, 370 + 120) and posm[1] in range(320, 320 + 30) and flstart==False and flonemove==False:
                flstart=True
                flonemove=True
            if posm[0] in range(370, 370 + 120) and posm[1] in range(320, 320 + 30) and flstart==True and flonemove==False:
                flstart=False
                floneupdate=False
                flonemove = True
                inow1=0
                inow2=0
                count1=0
                count2=0
        if event.type==pg.MOUSEBUTTONDOWN:
            if event.button==1 and posm[0] in range(nowx1*40,nowx1*40+40) and posm[1] in range(nowy1*40, nowy1*40+40)and flgrabeh==False and flgrabe2==False:
                flgrabe1=True
            if  event.button==1 and posm[0] in range(nowx2*40,nowx2*40+40) and posm[1] in range(nowy2*40, nowy2*40+40)and flgrabe1==False and flgrabeh==False:
                flgrabe2=True
            if event.button==1 and posm[0] in range(endx*40,endx*40+40) and posm[1] in range(endy*40, endy*40+40) and flgrabe1==False and flgrabe2==False:
                flgrabeh=True
    scrn.fill(pg.Color('#FFFFFF'))
    for i in range(360//40):
        for j in range(360//40):
            if maze[i][j]==1:
                pg.draw.rect(scrn,pg.Color('#101010'),(40*i,40*j,40,40),2)
            if maze[i][j]==0:
                pg.draw.rect(scrn, ('#AFAF50'), (40 * i, 40 * j, 40, 40))
                pg.draw.rect(scrn,pg.Color('#101010'),(40*i,40*j,40,40),2)
            if posm[0] in range(i*40,i*40+40) and posm[1] in range(j*40,j*40+40):
                if maze[i][j] == 0:
                    pg.draw.rect(scrn, ('#909010'), (40 * i, 40 * j, 40, 40))
                    pg.draw.rect(scrn, pg.Color('#101010'), (40 * i, 40 * j, 40, 40), 2)
                else:
                    pg.draw.rect(scrn,('#AFAFAF'),(40*i,40*j,40,40))
                    pg.draw.rect(scrn, ('#101010'), (40 * i, 40 * j, 40, 40),2)
                if flmbupl==True and maze[i][j]==1 and flonemove==False:
                    maze[i][j]=0
                    flonemove=True
                if flmbupl == True and maze[i][j] == 0 and flonemove==False:
                    maze[i][j] = 1
                    flonemove=True
            if i==nowx1 and j==nowy1:
                pg.draw.circle(scrn,('#AF5050'),(40*i+20,40*j+20),15)
            if i == nowx2 and j == nowy2:
                pg.draw.circle(scrn, ('#5050AF'), (40 * i + 20, 40 * j + 20), 15)
            if i==endx and j==endy:
                pg.draw.polygon(scrn, ('#50AF50'),[(40*i+20,40*j+5),(40*i+35,40*j+20),(40*i+30,40*j+20),(40*i+30,40*j+35),(40*i+10,40*j+35),(40*i+10, 40*j+20),(40*i+5,40*j+20),(40*i+20,40*j+5)])
            if flgrabe1==True and 0<posm[0]<360 and 0<posm[1]<360:
                stx1=posm[0]//40
                sty1 = posm[1] // 40
                nowx1=stx1
                nowy1=sty1
            if flgrabe2==True and 0<posm[0]<360 and 0<posm[1]<360:
                stx2=posm[0]//40
                sty2 = posm[1] // 40
                nowx2 = stx2
                nowy2 = sty2
            if flgrabeh==True and 0<posm[0]<360 and 0<posm[1]<360:
                endx=posm[0]//40
                endy = posm[1] // 40
    if posm[0] in range(370,370+120) and posm[1] in range(320,320+30):
        pg.draw.rect(scrn, "#CC3333", (370, 320, 120, 30))
    else:
        pg.draw.rect(scrn,"#FF3333",(370,320,120,30))
    if nowx1==endx and nowy1==endy:
        flathome1=True
    else:
        flathome1=False
    if nowx2==endx and nowy2==endy:
        flathome2=True
    else:
        flathome2=False
    if flstart==True:
        if floneupdate==False:
            floneupdate=True
            w1,w2=updateall(stx1,sty1,stx2,sty2,endx,endy,maze)
            print(w1,'\n',w2)
        if count1==10 and inow1<len(w1):
            if w1[inow1][0]!=nowx2 or w1[inow1][1]!=nowy2 or flathome2==True:
                nowx1=w1[inow1][0]
                nowy1 = w1[inow1][1]
                inow1+=1
            count1=0

        if inow1<len(w1):
            count1+=1
        if count2==10 and inow2<len(w2):
            if w2[inow2][0] != nowx1 or w2[inow2][1] != nowy1 or flathome1==True:
                nowx2=w2[inow2][0]
                nowy2 = w2[inow2][1]
                inow2+=1
            count2 = 0
        if inow2<len(w2):
            count2+=1
    if flstart==False:
        textfont=text.render('Start', False, "#101010")
        scrn.blit(textfont,(398, 322))
    else:
        textfont=text.render('Stop', False, "#101010")
        scrn.blit(textfont, (395, 322))

    if flstart==True:
        textfont = text.render('working..', False, "#101010")
        scrn.blit(textfont, (362, 280))
    coord = text.render('R1= ('+str(nowx1)+' , '+str(nowy1)+')', False, "#101010")
    scrn.blit(coord, (365, 20))
    coord = text.render('R2= (' + str(nowx2) + ' , ' + str(nowy2) + ')', False, "#101010")
    scrn.blit(coord, (365, 80))
    coord = text.render('END=(' + str(endx) + ' , ' + str(endy) + ')', False, "#101010")
    scrn.blit(coord, (365, 140))
    pg.display.update()
    clock.tick(30)