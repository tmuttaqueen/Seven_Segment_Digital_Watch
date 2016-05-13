/*
            PREPARED BY "TANVEER MUTTAQUEEN"
            BUET CSE'15
            ROLL: 1505002
*/

# include "iGraphics.h"

/*  _ <- 4
5->| | <- 3
    _ <-7
6->| | <- 2
    _ <- 1
*/

const int x_transfer = 135, vertices = 6, circle_radius = 3;;
int sys_time[6];

double x_co_ordinate[7][6] = { 25, 35, 115, 125, 115, 35,
                               125, 128, 128, 125, 122, 122,
                               125, 128, 128, 125, 122, 122,
                               25, 35, 115, 125, 115, 35,
                               25, 28, 28, 25, 22, 22,
                               25, 28, 28, 25, 22, 22,
                               25, 35, 115, 125, 115, 35
                             };

double y_co_ordinate[7][6] = { 23, 20, 20, 23, 26, 26,
                               26, 36, 116, 126, 116, 36,
                               130, 140, 220, 230, 220, 140,
                               230, 227, 227, 230, 233, 233,
                               130, 140, 220, 230, 220, 140,
                               26, 36, 116, 126, 116, 36,
                               128, 125, 125, 128, 131, 131
                             };

int index[10][7] = { {1,1,1,1,1,1,0},
                     {0,1,1,0,0,0,0},
                     {1,0,1,1,0,1,1},
                     {1,1,1,1,0,0,1},
                     {0,1,1,0,1,0,1},
                     {1,1,0,1,1,0,1},
                     {1,1,0,1,1,1,1},
                     {0,1,1,1,0,0,0},
                     {1,1,1,1,1,1,1},
                     {1,1,1,1,1,0,1}
                   };

//get current system time
void gettime()
{
    time_t ctime;
    struct tm * current;
    int h, m, s;
    time ( &ctime );
    current = localtime ( &ctime );
    h = current->tm_hour;
    m = current->tm_min;
    s = current->tm_sec;
    sys_time[1] = h%10;
    h/=10;
    sys_time[0] = h;
    sys_time[3] = m%10;
    m/=10;
    sys_time[2] = m;
    sys_time[5] = s%10;
    s/=10;
    sys_time[4] = s;
}

void iDraw()
{
	iClear();
	iSetColor(255, 2, 50);
	gettime();
	int trans = -135, circlex = 290, circley1 = 76, circley2 = 182;
	double tempx[7][6]; // temporary value for x_co_ordinates of the segments
	for( int i = 0; i < 6; i++ )
    {
       int now = sys_time[i];
       trans += x_transfer;
       if( i == 2 || i == 4 )
       {
            trans += 30;
            iFilledCircle( circlex, circley1, circle_radius );
            iFilledCircle( circlex, circley2, circle_radius );
            circlex += 300;
       }
       //assigning value in x_coordinates of segments
       for( int p = 0; p < 7; p++ )
           for( int q = 0; q < 6; q++ )
               tempx[p][q] = trans + x_co_ordinate[p][q];
       for( int j = 0; j < 7; j++ )
       {
            if( index[now][j] )
                iFilledPolygon( tempx, y_co_ordinate, vertices, j );
       }
    }
    iSetColor(200, 2, 50);
    iText(0, 260, "24 HOUR FORMAT" );
}

void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n",mx,my);
}

void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN);
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN);
}

void iKeyboard(unsigned char key)
{
	if (key == 'q')
		exit(0);
}


void iSpecialKeyboard(unsigned char key)
{
	if (key == GLUT_KEY_END)
		exit(0);
}

int main()
{
	iInitialize(900, 270, "7_Segment_Watch");
	return 0;
}
